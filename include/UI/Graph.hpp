#pragma once
#include <wx/wx.h>
#include <wx/aui/aui.h>

namespace UI{
    class Graph: public wxPanel {
        public:
            Graph(wxWindow* parent);
            ~Graph();

        private:
            wxAuiManager auiManager;
    };
}