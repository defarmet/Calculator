#pragma once

#include "ButtonFactoryTests.h"
#include "CalculatorProcessorTests.h"
#include "wx\wx.h"

class Program : public wxApp {
private:
	ButtonFactoryTests *frame1 = nullptr;
	CalculatorProcessorTests *frame2 = nullptr;

public:
	virtual bool OnInit();
};