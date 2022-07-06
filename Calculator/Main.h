#pragma once
#include "wx\wx.h"

class Main : public wxFrame {
public:
	Main();
	~Main();

	wxButton **buttons;
	wxTextCtrl *display;
	unsigned char mode = 0;

	void OnButtonClicked(wxCommandEvent &e);

	wxDECLARE_EVENT_TABLE();
};