#include <App.hpp>

bool App::OnInit()
{
    Mainframe* mainFrame = new Mainframe("Graphing Tool");
    mainFrame->SetSize(wxSize(800, 600));
    mainFrame->Show(true);
    return true;
}

wxIMPLEMENT_APP(App);