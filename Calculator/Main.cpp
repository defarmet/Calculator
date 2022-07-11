#include "Main.h"
#include "ButtonFactory.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(625, 250))
{
	wxFlexGridSizer *box = new wxFlexGridSizer(2, 1, 0, 0);
	wxFlexGridSizer *rows = new wxFlexGridSizer(3, 0, 0);
	wxGridSizer *s1 = new wxGridSizer(4, 2, 0, 0);
	wxGridSizer *s2 = new wxGridSizer(2, 1, 0, 0);
	wxGridSizer *s2_1 = new wxGridSizer(2, 1, 0, 0);
	wxGridSizer *s3 = new wxGridSizer(4, 4, 0, 0);

	display = new wxTextCtrl(this, 9999, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY | wxTE_RICH);
	wxFont display_font(16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	display->SetFont(display_font);
	box->Add(display, 0, wxEXPAND);

	buttons = new wxButton *[27];
	ButtonFactory::create_buttons(this, buttons);
	for (int i = 0; i < 27; i++)
		buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::on_click, this);

	const int order[] = {10, 11, 13, 14, 23, 24, 25, 26, 12, 15, 22,
			7, 8, 9, 19, 4, 5, 6, 18, 1, 2, 3, 17, 0, 21, 20, 16};

	int i;
	for (i = 0; i < 8; i++)
		s1->Add(buttons[order[i]], 1, wxEXPAND);

	rows->Add(s1, 1, wxEXPAND);

	for (; i < 10; i++)
		s2_1->Add(buttons[order[i]], 1, wxEXPAND);

	s2->Add(s2_1, 1, wxEXPAND);
	s2->Add(buttons[order[i++]], 1, wxEXPAND);
	rows->Add(s2, 1, wxEXPAND);

	for (; i < 27; i++)
		s3->Add(buttons[order[i]], 1, wxEXPAND);
	
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

void Main::on_click(wxCommandEvent &e)
{
	int index = e.GetId() - 10000;
	*display << buttons[index]->GetLabel();
	/*switch (index) {
	case 8:
	case 9:
		if (mode < 2)
			break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		if (mode < 1)
			break;
	case 0:
	case 1:
		*display << index;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		if (mode == 3)
			*display << (char)('A' + (index - 10));
		break;

	case 16:
		*display << '+';
		break;

	case 17:
		*display << '-';
		break;

	case 18:
		*display << '*';
		break;

	case 19:
		*display << '/';
		break;

	case 20:
		*display << '%';
		break;

	case 21:
		display->Clear();
		break;

	case 22:
		*display << '=';
		break;

	case 23:
		mode = 0;
		display->Clear();
		break;

	case 24:
		mode = 1;
		display->Clear();
		break;

	case 25:
		mode = 2;
		display->Clear();
		break;

	case 26:
		mode = 3;
		display->Clear();
		break;
	}*/
}