# Minimum CMake version required for FetchContent and other modern features
cmake_minimum_required(VERSION 3.18)

# Define the project name and specify we're using C++
project(Graphing_Tool LANGUAGES CXX)

# Set C++ standard to C++17 and make it required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================================
# User Options
# ============================================================================
# Allow user to force building wxWidgets from source even if system version exists
option(WX_FORCE_BUILD "Force downloading and building wxWidgets even if a system package is found" OFF)
# Allow user to prefer fetching wxWidgets instead of using system package
option(WX_PREFER_FETCH "Prefer fetching wxWidgets instead of using system package" OFF)

# ============================================================================
# wxWidgets Configuration
# ============================================================================
# Set the version of wxWidgets to download if needed
set(WX_VERSION 3.2.5)

# Choose the appropriate download URL based on the operating system
# Windows uses .zip, Unix-like systems use .tar.bz2
if(WIN32)
  set(WX_DOWNLOAD_URL https://github.com/wxWidgets/wxWidgets/releases/download/v${WX_VERSION}/wxWidgets-${WX_VERSION}.zip)
else()
  set(WX_DOWNLOAD_URL https://github.com/wxWidgets/wxWidgets/releases/download/v${WX_VERSION}/wxWidgets-${WX_VERSION}.tar.bz2)
endif()

# ============================================================================
# wxWidgets Discovery/Fetch Logic
# ============================================================================
# Decide whether to try finding a system-installed wxWidgets first
set(_use_system ON)
if(WX_FORCE_BUILD OR WX_PREFER_FETCH)
  set(_use_system OFF)
endif()

# Try to find wxWidgets on the system if we're using system packages
if(_use_system)
  find_package(wxWidgets COMPONENTS core base QUIET)
endif()

# If wxWidgets wasn't found (or we're forcing a build), fetch and build it
if(NOT wxWidgets_FOUND)
  message(STATUS "Using embedded wxWidgets ${WX_VERSION} from ${WX_DOWNLOAD_URL}")
  include(FetchContent)

  # Configure wxWidgets build options before adding it as a subdirectory
  set(wxBUILD_SHARED ON  CACHE BOOL "" FORCE)     # Build shared libraries
  set(wxBUILD_SAMPLES OFF CACHE BOOL "" FORCE)    # Don't build wxWidgets samples
  set(wxBUILD_TESTS   OFF CACHE BOOL "" FORCE)    # Don't build wxWidgets tests
  
  # On Linux, use GTK3 toolkit
  if(UNIX AND NOT APPLE)
    set(wxBUILD_TOOLKIT gtk3 CACHE STRING "" FORCE)
  endif()

  # Declare where to fetch wxWidgets from
  FetchContent_Declare(
    wxwidgets_src
    URL ${WX_DOWNLOAD_URL}
  )

  # Populate (download and extract) wxWidgets if not already done
  FetchContent_GetProperties(wxwidgets_src)
  if(NOT wxwidgets_src_POPULATED)
    FetchContent_Populate(wxwidgets_src)
    
    # Add wxWidgets as a subdirectory to build it
    # EXCLUDE_FROM_ALL prevents it from being built by default "make all"
    if(EXISTS "${wxwidgets_src_SOURCE_DIR}/CMakeLists.txt")
      add_subdirectory(${wxwidgets_src_SOURCE_DIR} ${wxwidgets_src_BINARY_DIR} EXCLUDE_FROM_ALL)
    elseif(EXISTS "${wxwidgets_src_SOURCE_DIR}/build/cmake")
      add_subdirectory(${wxwidgets_src_SOURCE_DIR}/build/cmake ${wxwidgets_src_BINARY_DIR} EXCLUDE_FROM_ALL)
    else()
      message(FATAL_ERROR "Fetched wxWidgets does not contain a CMake buildsystem.")
    endif()
  endif()
endif()

# ============================================================================
# Create Interface Library for wxWidgets
# ============================================================================
# Create an interface library to simplify linking wxWidgets to our targets
add_library(graph_wx INTERFACE)

# Link the appropriate wxWidgets targets based on what's available
if(TARGET wx::core AND TARGET wx::base)
  # Modern CMake targets (preferred)
  target_link_libraries(graph_wx INTERFACE wx::core wx::base)
elseif(wxWidgets_FOUND)
  # Legacy FindwxWidgets.cmake variables
  include(${wxWidgets_USE_FILE})
  target_include_directories(graph_wx INTERFACE ${wxWidgets_INCLUDE_DIRS})
  target_link_libraries(graph_wx INTERFACE ${wxWidgets_LIBRARIES})
else()
  # wxWidgets not available at all
  message(FATAL_ERROR "wxWidgets not available. Install it or set WX_FORCE_BUILD=ON (or -DWX_PREFER_FETCH=ON).")
endif()

# ============================================================================
# Application Target
# ============================================================================
# Define the list of source files for the application
set(_main_sources
  ${CMAKE_SOURCE_DIR}/src/App.cpp
  ${CMAKE_SOURCE_DIR}/src/Mainframe.cpp
)

# Check if at least one source file exists before creating the target
set(_have_any_source OFF)
foreach(_s IN LISTS _main_sources)
  if(EXISTS "${_s}")
    set(_have_any_source ON)
  endif()
endforeach()

# Only create the executable target if we have source files
if(_have_any_source)
  add_executable(Graphing_Tool ${_main_sources})
  
  # Add include directory for header files
  target_include_directories(Graphing_Tool PRIVATE ${CMAKE_SOURCE_DIR}/headers)
  
  # Link the wxWidgets interface library to the application
  target_link_libraries(Graphing_Tool PRIVATE graph_wx)
endif()