#include "Program.h"

wxIMPLEMENT_APP(Program);

bool Program::OnInit()
{
	frame1 = new ButtonFactoryTests();
	frame1->Show();

	frame2 = new CalculatorProcessorTests();
	frame2->Show();

	return true;
}