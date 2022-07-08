#pragma once

#include "wx/wx.h"

class ButtonFactory {
public:
	static wxButton *CreateButton(wxWindow *win, int index, std::string label);
};

