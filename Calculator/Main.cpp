#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(800, 600))
{
	wxGridSizer grid = wxGridSizer(7, 5, 0, 0);
	display = wxTextCtrl(this, 9999, style = wxTE_RIGHT | wxTE_READONLY);

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < 27; i++) {
		buttons[i] = wxButton(this, 10000 + i);
		buttons[i]->SetFont(font);
		grid.Add(&buttons[i], 1, wxEXPAND | wxALL);

		buttons[i].Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
	}

	this->SetSizer(&grid);
	grid.Layout();
}

Main::~Main()
{
}

void Main::OnButtonClicked(wxCommandEvent &e)
{
	unsigned char index = e.GetId() - 10000;
	char value = index < 16 ? index : -1;

	if (first_click) {
		for (int mines = 30; mines;) {
			int rx = rand() % W;
			int ry = rand() % H;

			if (field[ry * W + rx] == 0 && rx != x && ry != y) {
				field[ry * W + rx] = -1;
				mines--;
			}
		}

		first_click = false;
	}

	btn[y * W + x]->Enable(false);

	if (field[y * W + x] == -1) {
		wxMessageBox("Game Over");

		first_click = true;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				field[y * W + x] = 0;
				btn[y * W + x]->SetLabel("");
				btn[y * W + x]->Enable(true);
			}
		}
	} else {
		int count = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (y + i >= 0 && y + i < H && x + j >= 0 && x + j < W) {
					if (field[(y + i) * W + (x + j)] == -1)
						count++;
				}
			}
		}

		if (count > 0)
			btn[y * W + x]->SetLabel(std::to_string(count));
	}

	e.Skip();
}