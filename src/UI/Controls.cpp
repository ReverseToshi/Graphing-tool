#include <UI/Controls.hpp>

UI::Controls::Controls(wxWindow* parent)
    : wxPanel(parent, wxID_ANY) {
    // Set the background color of the panel
    SetBackgroundColour(wxColour(255, 255, 255)); // Light gray background

    auiManager.SetManagedWindow(this);

    auiManager.Update();
}

UI::Controls::~Controls() {
    auiManager.UnInit();
}