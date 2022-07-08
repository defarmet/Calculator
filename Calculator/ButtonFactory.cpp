#include "ButtonFactory.h"
#include "Main.h"

wxButton *ButtonFactory::CreateButton(wxFrame *win, int index, std::string label)
{
	wxButton *btn = new wxButton(win, 10000 + index);

	wxFont button_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	btn->SetFont(button_font);
	btn->SetLabel(label);

	return btn;
}