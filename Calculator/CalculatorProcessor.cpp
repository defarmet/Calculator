#include "CalculatorProcessor.h"

CalculatorProcessor *CalculatorProcessor::calc = nullptr;

CalculatorProcessor *CalculatorProcessor::get_instance()
{
	if (CalculatorProcessor::calc == nullptr) {
		CalculatorProcessor::calc = new CalculatorProcessor;
	}

	return CalculatorProcessor::calc;
}

void CalculatorProcessor::calculate(wxTextCtrl *display, unsigned char in_mode, unsigned char out_mode)
{
	std::string input = display->GetLineText(0).ToStdString();
	display->Clear();
	unsigned long long result = 0;
	unsigned long long store = 0;
	char op = ' ';
	bool flip = false;
	for (size_t i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case '-':
			if (i == 0)
				flip = true;
		case '+':
		case '*':
		case '/':
		case '%':
			result = store;
			store = 0;
			op = input[i];
			break;

		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
			store *= in_mode;
			store += input[i] - 'A' + 10;
			break;

		default:
			store *= in_mode;
			store += input[i] - '0';
		}
	}

	switch (op) {
	case ' ':
		result = store;
		break;

	case '+':
		if (flip) {
			if (store >= result) {
				flip = false;
				result = store - result;
			} else {
				result -= store;
			}
		} else {
			result += store;
		}
		break;

	case '-':
		if (flip) {
			result += store;
		} else if (store > result) {
			result = store - result;
			flip = true;
		} else {
			result -= store;
		}
			
		break;

	case '*':
		result *= store;
		break;

	case '/':
		result /= store;
		break;

	case '%':
		result %= store;
	}

	std::string output = "";
	if (result == 0) {
		flip = false;
		output = "0";
	}

	for (; result > 0; result /= out_mode) {
		switch (result % out_mode) {
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			output.insert(0, std::string(1, (result % out_mode - 10) + 'A'));
			break;

		default:
			output.insert(0, std::to_string(result % out_mode));
		}
	}
	if (flip)
		output.insert(0, "-");

	*display << output;
}