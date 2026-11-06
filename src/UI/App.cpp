#include <UI/App.hpp>
#include <UI/MainFrame.hpp>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    // Create an instance of MainFrame
    UI::MainFrame* mainFrame = new UI::MainFrame("Graphing Tool", wxPoint(50, 50), wxSize(800, 600));
    
    // Show the main frame
    mainFrame->Show(true);
    
    return true;
}

