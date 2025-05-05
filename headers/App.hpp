#pragma once
#include <wx/wx.h>
#include <wx/app.h>
#include <MainFrame.hpp>

class App:public wxApp{
public:
    virtual bool OnInit() override;
};