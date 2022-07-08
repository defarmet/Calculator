#pragma once
#include "wx\wx.h"

class Main : public wxFrame {
public:
	Main();
	~Main();

	wxButton **buttons;
	wxTextCtrl *display;
	unsigned char mode = 2;

	void OnButtonClicked(wxCommandEvent &e);
};