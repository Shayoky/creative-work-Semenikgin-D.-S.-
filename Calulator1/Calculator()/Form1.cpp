#include "Form1.h"
#include <cstdlib>

using namespace Calculator;

[STAThreadAttribute]
int main()
{
	setlocale(LC_ALL, "rus");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form1());
	return 0;
}
