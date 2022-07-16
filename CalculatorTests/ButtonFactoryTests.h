#pragma once

#include "wx\wx.h"

class ButtonFactoryTests : public wxFrame {
public:
	ButtonFactoryTests();
	~ButtonFactoryTests();
private:
	wxButton **buttons;
	wxTextCtrl *display;
};