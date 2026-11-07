#pragma once
#include <wx/wx.h>
#include <wx/aui/aui.h>

namespace UI{
    class Controls: public wxPanel {
        public:
            Controls(wxWindow* parent);
            ~Controls();

        private:
            wxAuiManager auiManager;
    };
}