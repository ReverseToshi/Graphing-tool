#include <Mainframe.hpp>

Mainframe::Mainframe(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    // You can add more initialization code here if needed
}

Mainframe::~Mainframe()
{
    // You can add cleanup code here if needed
}