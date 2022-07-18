#pragma once

#include "wx/wx.h"

class CalculatorProcessor {
private:
	static CalculatorProcessor *calc;
	CalculatorProcessor() = default;
public:
	static CalculatorProcessor *get_instance();
	void calculate(wxTextCtrl *display, unsigned char in_mode, unsigned char out_mode);

	CalculatorProcessor(CalculatorProcessor &other) = delete;
	void operator=(CalculatorProcessor &other) = delete;
};

