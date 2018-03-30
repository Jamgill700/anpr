#include "MainForm.h"
#include "alpr.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OpenAlprFormsDemo::MainForm form;
	Application::Run(%form);
	return 0;
}