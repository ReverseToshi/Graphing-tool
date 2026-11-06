#pragma once
#include <wx/wx.h>
#include <wx/aui/aui.h>

namespace UI{
    class Functions: public wxPanel {
        public:
            Functions(wxWindow* parent);
            ~Functions();

            void AddFunction(wxPanel* function);

        private:
            wxAuiManager auiManager;
    };

    class Function: wxPanel {
        public:
            Function(wxWindow* parent);
            ~Function();

        private:
            wxAuiManager auiManager;
    };
}