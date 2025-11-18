#pragma once
#include <wx/wx.h>
#include <wx/frame.h>

class Mainframe : public wxFrame
{
public:
    Mainframe(const wxString& title);
    ~Mainframe();
};