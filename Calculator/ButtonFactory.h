#pragma once

#include "wx/wx.h"

class ButtonFactory {
public:
	static wxButton *CreateButton(wxFrame *win, int index, std::string label);
};

