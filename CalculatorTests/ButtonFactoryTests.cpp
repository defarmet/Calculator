#include <assert.h>

#include "ButtonFactoryTests.h"
#include "../../Calculator/Calculator/ButtonFactory.h"
#include "../../Calculator/Calculator/ButtonFactory.cpp"

ButtonFactoryTests::ButtonFactoryTests() : wxFrame(nullptr, wxID_ANY, "ButtonFactoryTests", wxPoint(30, 30), wxSize(625, 250))
{
	wxFlexGridSizer *box = new wxFlexGridSizer(2, 1, 0, 0);
	wxFlexGridSizer *rows = new wxFlexGridSizer(4, 7, 0, 0);

	display = new wxTextCtrl(this, 9999, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY | wxTE_RICH);
	wxFont display_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	display->SetFont(display_font);
	box->Add(display, 0, wxEXPAND);

	buttons = new wxButton *[27];
	ButtonFactory::create_buttons(this, buttons);
	for (int i = 0; i < 27; i++)
		rows->Add(buttons[i], 1, wxEXPAND);

	box->Add(rows, 1, wxEXPAND);
	box->AddGrowableRow(1);
	box->AddGrowableCol(0);

	this->SetSizer(box);

	assert(buttons[0]->GetLabel().ToStdString() == "0" && buttons[0]->GetId() == 10000);
	assert(buttons[9]->GetLabel().ToStdString() == "9" && buttons[9]->GetId() == 10009);
	assert(buttons[10]->GetLabel().ToStdString() == "A" && buttons[10]->GetId() == 10010);
	assert(buttons[15]->GetLabel().ToStdString() == "F" && buttons[15]->GetId() == 10015);
	assert(buttons[16]->GetLabel().ToStdString() == "+" && buttons[16]->GetId() == 10016);
	assert(buttons[19]->GetLabel().ToStdString() == "/" && buttons[19]->GetId() == 10019);
	assert(buttons[20]->GetLabel().ToStdString() == "MOD" && buttons[20]->GetId() == 10020);
	assert(buttons[22]->GetLabel().ToStdString() == "=" && buttons[22]->GetId() == 10022);
	assert(buttons[23]->GetLabel().ToStdString() == "BIN" && buttons[23]->GetId() == 10023);
	assert(buttons[26]->GetLabel().ToStdString() == "HEX" && buttons[26]->GetId() == 10026);

	*display << "ALL TESTS PASSED";
}

ButtonFactoryTests::~ButtonFactoryTests()
{
	delete[] buttons;
	delete display;
}