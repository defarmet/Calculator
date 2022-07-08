#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(600, 200))
{
	wxFlexGridSizer *box = new wxFlexGridSizer(2, 1, 0, 0);
	wxFlexGridSizer *rows = new wxFlexGridSizer(3, 0, 0);
	wxGridSizer *s1 = new wxGridSizer(4, 2, 0, 0);
	wxGridSizer *s2 = new wxGridSizer(2, 1, 0, 0);
	wxGridSizer *s2_1 = new wxGridSizer(2, 1, 0, 0);
	wxGridSizer *s3 = new wxGridSizer(4, 4, 0, 0);

	display = new wxTextCtrl(this, 9999, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY);
	box->Add(display, 0, wxEXPAND);

	buttons = new wxButton *[27];

	wxFont button_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < 27; i++) {
		buttons[i] = new wxButton(this, 10000 + i);
		buttons[i]->SetFont(button_font);
		//buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
		if (i < 10)
			buttons[i]->SetLabel(std::to_string(i));
	}

	buttons[10]->SetLabel("A");
	buttons[11]->SetLabel("B");
	buttons[12]->SetLabel("C");
	buttons[13]->SetLabel("D");
	buttons[14]->SetLabel("E");
	buttons[15]->SetLabel("F");
	buttons[16]->SetLabel("+");
	buttons[17]->SetLabel("-");
	buttons[18]->SetLabel("*");
	buttons[19]->SetLabel("/");
	buttons[20]->SetLabel("MOD");
	buttons[21]->SetLabel("CR");
	buttons[22]->SetLabel("=");
	buttons[23]->SetLabel("BIN");
	buttons[24]->SetLabel("OCT");
	buttons[25]->SetLabel("DEC");
	buttons[26]->SetLabel("HEX");

	s1->Add(buttons[10], 1, wxEXPAND);
	s1->Add(buttons[11], 1, wxEXPAND);
	s1->Add(buttons[13], 1, wxEXPAND);
	s1->Add(buttons[14], 1, wxEXPAND);
	s1->Add(buttons[23], 1, wxEXPAND);
	s1->Add(buttons[24], 1, wxEXPAND);
	s1->Add(buttons[25], 1, wxEXPAND);
	s1->Add(buttons[26], 1, wxEXPAND);
	rows->Add(s1, 1, wxEXPAND);

	s2_1->Add(buttons[12], 1, wxEXPAND);
	s2_1->Add(buttons[15], 1, wxEXPAND);
	s2->Add(s2_1, 1, wxEXPAND);
	s2->Add(buttons[22], 1, wxEXPAND);
	rows->Add(s2, 1, wxEXPAND);

	s3->Add(buttons[7], 1, wxEXPAND);
	s3->Add(buttons[8], 1, wxEXPAND);
	s3->Add(buttons[9], 1, wxEXPAND);
	s3->Add(buttons[19], 1, wxEXPAND);
	s3->Add(buttons[4], 1, wxEXPAND);
	s3->Add(buttons[5], 1, wxEXPAND);
	s3->Add(buttons[6], 1, wxEXPAND);
	s3->Add(buttons[18], 1, wxEXPAND);
	s3->Add(buttons[1], 1, wxEXPAND);
	s3->Add(buttons[2], 1, wxEXPAND);
	s3->Add(buttons[3], 1, wxEXPAND);
	s3->Add(buttons[17], 1, wxEXPAND);
	s3->Add(buttons[0], 1, wxEXPAND);
	s3->Add(buttons[21], 1, wxEXPAND);
	s3->Add(buttons[20], 1, wxEXPAND);
	s3->Add(buttons[16], 1, wxEXPAND);
	rows->Add(s3, 1, wxEXPAND);
	rows->AddGrowableRow(0);
	for (int i = 0; i < 3; i++)
		rows->AddGrowableCol(i);

	box->Add(rows, 1, wxEXPAND);
	box->AddGrowableRow(1);
	box->AddGrowableCol(0);

	this->SetSizer(box);
}

Main::~Main()
{
	delete[] buttons;
	delete display;
}

void Main::OnButtonClicked(wxCommandEvent &e)
{
}
