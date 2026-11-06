#pragma once
#include <wx/wx.h>
#include <wx/aui/aui.h>

namespace UI{
    class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
            ~MainFrame();

        private:
            wxPanel* mainPanel = nullptr;
            wxPanel* graphPanel = nullptr;
            wxPanel* controlPanel = nullptr;
            wxPanel* functionPanel = nullptr;
            wxAuiManager auiManager;
    };
}