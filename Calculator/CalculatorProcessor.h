#pragma once

#include "wx/wx.h"

class CalculatorProcessor {
public:
	static CalculatorProcessor &get_instance();
	void calculate(wxTextCtrl *display, unsigned char in_mode, unsigned char out_mode);
};

