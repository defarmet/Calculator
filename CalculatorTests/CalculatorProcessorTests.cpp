#include <cstdlib>

#include "CalculatorProcessorTests.h"
#include "../../Calculator/Calculator/CalculatorProcessor.h"
#include "../../Calculator/Calculator/CalculatorProcessor.cpp"

CalculatorProcessorTests::CalculatorProcessorTests() : wxFrame(nullptr, wxID_ANY, "CalculatorProcessorTests", wxPoint(30, 280), wxSize(625, 250))
{
	time_t t;
	srand(time(&t));

	wxFlexGridSizer *box = new wxFlexGridSizer(1, 0, 0);

	display = new wxTextCtrl(this, 9999, "0", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY | wxTE_RICH);
	wxFont display_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	display->SetFont(display_font);
	box->Add(display, 0, wxEXPAND);

	box->AddGrowableCol(0);

	this->SetSizer(box);

	int x = rand();
	int y = rand();

	*display << x << "+" << y;
	calculator.calculate(display, 10, 10);
	std::string output = display->GetLineText(0).ToStdString();
	assert(output == std::to_string(x + y));
	display->Clear();

	*display << x << "-" << y;
	calculator.calculate(display, 10, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == std::to_string(x - y));
	display->Clear();

	*display << x << "*" << y;
	calculator.calculate(display, 10, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == std::to_string(x * y));
	display->Clear();

	*display << x << "/" << y;
	calculator.calculate(display, 10, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == std::to_string(x / y));
	display->Clear();

	*display << x << "%" << y;
	calculator.calculate(display, 10, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == std::to_string(x % y));
	display->Clear();

	*display << 10 << "+" << 5;
	calculator.calculate(display, 10, 2);
	output = display->GetLineText(0).ToStdString();
	assert(output == "1111");
	display->Clear();

	*display << 1010 << "+" << 101;
	calculator.calculate(display, 2, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == "15");
	display->Clear();

	*display << 1010 << "+" << 101;
	calculator.calculate(display, 2, 16);
	output = display->GetLineText(0).ToStdString();
	assert(output == "F");
	display->Clear();

	*display << 'A' << "+" << 5;
	calculator.calculate(display, 16, 2);
	output = display->GetLineText(0).ToStdString();
	assert(output == "1111");
	display->Clear();

	*display << 'A' << "+" << 5;
	calculator.calculate(display, 16, 10);
	output = display->GetLineText(0).ToStdString();
	assert(output == "15");
	display->Clear();

	*display << "ALL TESTS PASSED";
}

CalculatorProcessorTests::~CalculatorProcessorTests()
{
	delete display;
}