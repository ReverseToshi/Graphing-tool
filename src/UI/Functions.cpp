#include <UI/Functions.hpp>
#include <wx/aui/aui.h>
#include <wx/wx.h>

UI::Functions::Functions(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {
    // Set the background color of the panel
    SetBackgroundColour(wxColour(255, 255, 255)); // Light gray background

    auiManager.SetManagedWindow(this);

    auiManager.Update();
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