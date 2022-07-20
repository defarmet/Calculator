#include "CppUnitTest.h"
#include "../Calculator/ButtonFactory.h"
#include "../Calculator/CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	private:
		wxButton **buttons = new wxButton *[27];
		wxFrame *win = new wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(625, 250));

	public:
		TEST_METHOD(Button0Is0)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[0]->GetLabel().ToStdString() == "0");
			Assert::IsTrue(buttons[0]->GetId() == 10000);
		}
		TEST_METHOD(Button9Is9)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[9]->GetLabel().ToStdString() == "9");
			Assert::IsTrue(buttons[9]->GetId() == 10009);
		}
		TEST_METHOD(Button10IsA)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[10]->GetLabel().ToStdString() == "A");
			Assert::IsTrue(buttons[10]->GetId() == 10010);
		}
		TEST_METHOD(Button15IsF)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[15]->GetLabel().ToStdString() == "F");
			Assert::IsTrue(buttons[15]->GetId() == 10015);
		}
		TEST_METHOD(Button16IsPlus)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[16]->GetLabel().ToStdString() == "+");
			Assert::IsTrue(buttons[16]->GetId() == 10016);
		}
		TEST_METHOD(Button19IsSlash)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[19]->GetLabel().ToStdString() == "/");
			Assert::IsTrue(buttons[19]->GetId() == 10019);
		}
		TEST_METHOD(Button20IsMOD)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[20]->GetLabel().ToStdString() == "MOD");
			Assert::IsTrue(buttons[20]->GetId() == 10020);
		}
		TEST_METHOD(Button22IsEquals)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[22]->GetLabel().ToStdString() == "=");
			Assert::IsTrue(buttons[22]->GetId() == 10022);
		}
		TEST_METHOD(Button23IsBIN)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[23]->GetLabel().ToStdString() == "BIN");
			Assert::IsTrue(buttons[23]->GetId() == 10023);
		}
		TEST_METHOD(Button26IsHEX)
		{
			ButtonFactory::create_buttons(win, buttons);
			Assert::IsTrue(buttons[26]->GetLabel().ToStdString() == "HEX");
			Assert::IsTrue(buttons[26]->GetId() == 10026);
		}
	};

	TEST_CLASS(CalculatorProcessorTests) {
	private:
		wxFrame *win = new wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(625, 250));
		CalculatorProcessor *calc = CalculatorProcessor::get_instance();
		wxTextCtrl *display = new wxTextCtrl(win, 9999, "0", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxTE_READONLY | wxTE_RICH);

	public:
		TEST_METHOD(Addition)
		{
			*display << 10 << "+" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "15");
			display->Clear();
		}
		TEST_METHOD(Subtraction)
		{
			*display << 10 << "-" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "5");
			display->Clear();
		}
		TEST_METHOD(Multiplication)
		{
			*display << 10 << "*" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "50");
			display->Clear();
		}
		TEST_METHOD(Division)
		{
			*display << 10 << "/" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "2");
			display->Clear();
		}
		TEST_METHOD(Modulo)
		{
			*display << 10 << "%" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "0");
			display->Clear();
		}
		TEST_METHOD(AddToNegative)
		{
			*display << -2 << "+" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "3");
			display->Clear();
		}
		TEST_METHOD(SubtractFrom0)
		{
			*display << 0 << "-" << 5;
			calc->calculate(display, 10, 10);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "-5");
			display->Clear();
		}
		TEST_METHOD(Binary)
		{
			*display << 10 << "+" << 5;
			calc->calculate(display, 10, 2);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "1111");
			display->Clear();
		}
		TEST_METHOD(Octal)
		{
			*display << 10 << "+" << 5;
			calc->calculate(display, 10, 8);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "17");
			display->Clear();
		}
		TEST_METHOD(Hexadecimal)
		{
			*display << 10 << "+" << 5;
			calc->calculate(display, 10, 16);
			std::string output = display->GetLineText(0).ToStdString();
			Assert::IsTrue(output == "F");
			display->Clear();
		}
	};
}
