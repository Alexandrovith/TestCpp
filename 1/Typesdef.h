#pragma once

#include <Windows.h>
#include <string>

using namespace System;

typedef void (CALLBACK* DInitDll)();
typedef void (*TRunSubscribe) ();
typedef void (*TRunInitConfig) ();
typedef void (*TRun) ();
delegate void DOutMess (System::String^ asMess);
//namespace TestCpp
//{
//	public ref class FTestCppDrv
//	{
//	public: delegate void DOutMess (System::String^ asMess);
//	};
//}
//typedef void (*DOutMess) (std::string asMess);
