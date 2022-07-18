#pragma once

#include "../../Calculator/Calculator/CalculatorProcessor.h"
#include "wx\wx.h"

class CalculatorProcessorTests : public wxFrame {
public:
	CalculatorProcessorTests();
	~CalculatorProcessorTests();
private:
	wxTextCtrl *display;
	unsigned char mode = 10;
	CalculatorProcessor *calculator;
};