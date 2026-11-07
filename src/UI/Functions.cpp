#include <UI/Functions.hpp>
#include <wx/aui/aui.h>
#include <wx/wx.h>

UI::Functions::Functions(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {

    SetBackgroundColour(wxColour(255, 255, 255));

    // Initialise AUI manager
    auiManager.SetManagedWindow(this);

    // Information panel
    wxPanel* infoPanel = new wxPanel(this, wxID_ANY);
    infoPanel->SetBackgroundColour(wxColour(200, 200, 200));

    // Header
    wxStaticText* infoText = new wxStaticText(
        infoPanel,
        wxID_ANY,
        "{} Expression Reference"
    );

    infoText->SetFont(wxFont(
        10,
        wxFONTFAMILY_DEFAULT,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_BOLD
    ));

    // Expression reference
    wxStaticText* infoContent = new wxStaticText(
        infoPanel,
        wxID_ANY,
        "+ - * / ^ () x e π"
    );

    infoContent->SetFont(wxFont(
        10,
        wxFONTFAMILY_DEFAULT,
        wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL
    ));

    // Information panel layout
    wxBoxSizer* infoSizer = new wxBoxSizer(wxVERTICAL);

    infoSizer->Add(infoText, 0, wxALL, 10);
    infoSizer->Add(infoContent, 0, wxLEFT | wxRIGHT | wxBOTTOM, 10);

    infoPanel->SetSizer(infoSizer);
    infoPanel->SetMinSize(wxSize(-1, 100));

    // Add information panel to AUI
    auiManager.AddPane(
        infoPanel,
        wxAuiPaneInfo()
            .Name("InformationPane")
            .Bottom()
            .Caption("Information Panel")
            .BestSize(-1, 120)
            .MinSize(-1, 100)
    );

    // Apply AUI layout
    auiManager.Update();

    // Debugging
    wxLogDebug("Info content best size: %d x %d",
        infoContent->GetBestSize().GetWidth(),
        infoContent->GetBestSize().GetHeight());

    wxLogDebug("Info panel size: %d x %d",
        infoPanel->GetSize().GetWidth(),
        infoPanel->GetSize().GetHeight());

    wxLogDebug("Info content actual size: %d x %d",
        infoContent->GetSize().GetWidth(),
        infoContent->GetSize().GetHeight());
}

UI::Functions::~Functions() {
    auiManager.UnInit();
}

UI::Function::Function(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {
    // Set the background color of the panel
    SetBackgroundColour(wxColour(240, 240, 240)); // Light gray background
    

    auiManager.SetManagedWindow(this);

    auiManager.Update();
}

UI::Function::~Function() {
    auiManager.UnInit();
}

void UI::Functions::AddFunction(wxPanel* function) {
    auiManager.AddPane(function, wxAuiPaneInfo().Center().Caption("Function Panel"));
    auiManager.Update();
}