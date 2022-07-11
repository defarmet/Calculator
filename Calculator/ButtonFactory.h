#pragma once

#include "wx/wx.h"

class ButtonFactory {
public:
	static void create_buttons(wxFrame *win, wxButton **buttons);

private:
	static wxButton *create_button(wxFrame *win, int index, std::string label);
};

