#pragma once
#include <wx/wx.h>
#include <wx/app.h>
#include <Mainframe.hpp>

class App:public wxApp{
public:
    virtual bool OnInit() override;
};