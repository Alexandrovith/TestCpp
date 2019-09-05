#include "TestCpp.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TestCpp;

[STAThreadAttribute]
void main (array<String^>^ args)
{
	Application::EnableVisualStyles ();
	Application::SetCompatibleTextRenderingDefault (false);

	Application::Run (gcnew FTestCpp ());
}