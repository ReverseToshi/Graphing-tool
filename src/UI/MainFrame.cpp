#include <UI/MainFrame.hpp>
#include <UI/Functions.hpp>
#include <UI/Graph.hpp>
#include <wx/aui/aui.h>

UI::MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    // Set the background color of the frame
    SetBackgroundColour(wxColour(255, 255, 255)); // White background

    auiManager.SetManagedWindow(this);

    this->functionPanel = new UI::Functions(this);
    this->graphPanel = new UI::Graph(this);

    auiManager.AddPane(this->functionPanel, wxAuiPaneInfo().Left().Caption("Function Panel"));
    auiManager.AddPane(this->graphPanel, wxAuiPaneInfo().Center().Caption("Graph Panel"));

    auiManager.Update();
    
}

UI::MainFrame::~MainFrame() {
    delete this->mainPanel;
}