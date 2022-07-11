#include "ButtonFactory.h"

void ButtonFactory::create_buttons(wxFrame *win, wxButton **buttons)
{
	int i;
	for (i = 0; i < 10; i++)
		buttons[i] = create_button(win, i, std::to_string(i));

	const std::string labels[] = {"A", "B", "C", "D", "E", "F",
			"+", "-", "*", "/", "MOD", "CR", "=",
			"BIN", "OCT", "DEC", "HEX"};

	for (; i < 27; i++)
		buttons[i] = create_button(win, i, labels[i - 10]);
}

wxButton *ButtonFactory::create_button(wxFrame *win, int index, std::string label)
{
	wxButton *btn = new wxButton(win, 10000 + index);

	wxFont button_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	btn->SetFont(button_font);
	btn->SetLabel(label);

	return btn;
}