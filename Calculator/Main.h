#pragma once

#include "CalculatorProcessor.h"
#include "wx\wx.h"

class Main : public wxFrame {
public:
	Main();
	~Main();
private:
	wxButton **buttons;
	wxTextCtrl *display;
	unsigned char mode = 10;
	CalculatorProcessor calculator;

	void on_click(wxCommandEvent &e);
};