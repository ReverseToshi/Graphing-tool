#include <UI/Graph.hpp>
#include <wx/wx.h>
#include <wx/aui/aui.h>

UI::Graph::Graph(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {
    // Set the background color of the panel
    SetBackgroundColour(wxColour(255,255,255)); // Light gray background

    auiManager.SetManagedWindow(this);

    auiManager.AddPane(this, wxAuiPaneInfo().Center().Caption("Graph Panel"));
}

UI::Graph::~Graph() {
    auiManager.UnInit();
}