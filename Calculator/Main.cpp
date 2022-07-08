#include "Main.h"
#include "ButtonFactory.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(620, 210))
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

	int i;
	for (i = 0; i < 10; i++)
		buttons[i] = ButtonFactory::CreateButton(this, i, std::to_string(i));

	buttons[i] = ButtonFactory::CreateButton(this, i, "A");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "B");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "C");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "D");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "E");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "F");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "+");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "-");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "*");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "/");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "MOD");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "CR");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "=");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "BIN");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "OCT");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "DEC");
	buttons[++i] = ButtonFactory::CreateButton(this, i, "HEX");

	for (i = 0; i < 27; i++)
		buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);

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