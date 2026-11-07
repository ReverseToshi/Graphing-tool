#include <UI/MainFrame.hpp>
#include <UI/Functions.hpp>
#include <UI/Graph.hpp>
#include <UI/Controls.hpp>
#include <wx/aui/aui.h>

UI::MainFrame::MainFrame(
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size
)
    : wxFrame(nullptr, wxID_ANY, title, pos, size) {

    SetBackgroundColour(wxColour(255, 255, 255));

    auiManager.SetManagedWindow(this);

    functionPanel = new UI::Functions(this);
    graphPanel = new UI::Graph(this);
    controlPanel = new UI::Controls(this);

    auiManager.AddPane(
        functionPanel,
        wxAuiPaneInfo()
            .Left()
            .Caption("Function Panel")
            .BestSize(250, 500)
            .MinSize(200, 200)
    );

    auiManager.AddPane(
        graphPanel,
        wxAuiPaneInfo()
            .Center()
            .Caption("Graph Panel")
    );

    auiManager.AddPane(
        controlPanel,
        wxAuiPaneInfo()
            .Top()
            .Caption("Control Panel")
            .BestSize(-1, 100)
            .MinSize(-1, 80)
    );

    auiManager.Update();
}

UI::MainFrame::~MainFrame() {
    delete this->mainPanel;
}