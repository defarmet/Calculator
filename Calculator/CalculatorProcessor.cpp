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
	long long result = 0;
	long long store = 0;
	char op = ' ';
	for (size_t i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			if (op == ' ') {
				result = store;
			} else {
				switch (op) {
				case '+':
					result += store;
					break;

				case '-':
					result -= store;
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
			}

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
		result += store;
		break;

	case '-':
		result -= store;
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
	store = 0;

	std::string output = "";
	bool flip = result < 0;
	if (flip)
		result = -result;

	switch (out_mode) {
	case 2:
		for (; result > 0; result /= 2)
			output.insert(0, std::to_string(result % 2));

		if (flip)
			output.insert(0, "-");

		*display << output;
		break;

	case 8:
		for (; result > 0; result /= 8)
			output.insert(0, std::to_string(result % 8));

		if (flip)
			output.insert(0, "-");

		*display << output;
		break;

	case 10:
		if (flip)
			result = -result;

		*display << std::to_string(result);
		break;

	case 16:
		for (; result > 0; result /= 16) {
			switch (result % 16) {
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				output.insert(0, std::string(1, (result % 16 - 10) + 'A'));
				break;

			default:
				output.insert(0, std::to_string(result % 16));
			}
		}
		if (flip)
			output.insert(0, std::string(1, '-'));

		*display << output;
		break;
	}
}