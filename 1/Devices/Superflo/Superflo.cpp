#include "Superflo.h"
#include "LoadDLL.h"
#include "TestCpp.h"
#include "ManagedConvert.h"
#include "Init_Superflo.cpp"

#include <variant>
#include <iostream>
#include <utility>
#include <cassert>
#include <filesystem>
#include <FindPair.h>
#include <msclr\marshal.h>
#include <memory>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CSuperflo::CSuperflo (DOutMess^ OutMess/*, const LPCWSTR cpDll*/) : CDevice (OutMess)
	{
	}
	//_____________________________________________________________________________

	int CSuperflo::Write (String^ cpAddr, cli::array<System::Byte, 1> ^ baVal)
	{
		return WriteValue ((char*)CConvMarsh::Convert (cpAddr).c_str (), (char*)CConvMarsh::ByteArToCharArr (baVal), baVal->Length);
	}
	//_____________________________________________________________________________

	int CSuperflo::GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal)
	{
		UCHAR caVal[64];
		int iLenVal = GetValue (iTagId, (UCHAR*)caVal);
		baVal = gcnew cli::array<Byte, 1> (iLenVal);
		for (int i = 0; i < iLenVal; i++)
		{
			baVal[i] = caVal[i];
		}
		//Marshal::Copy((char*)caVal, baVal, 0, iLenVal);//CConvMarsh::CharArrToByteArr ((char*)caVal)
		return iLenVal;
	}
	//_____________________________________________________________________________

	int CSuperflo::InitDev ()
	{
		RdDevName ();
		InitConfig ((char*)caInit ());
		return 0;
	}
	//_____________________________________________________________________________

	void CSuperflo::RdDevName ()
	{
		CFindPair FindPair;
		FindPair.InitTag ((char*)caInit ());
		//asDevName = msclr::interop::marshal_as<System::String^> (FindPair["Name"]);
		asDevName = CConvMarsh::Convert (FindPair["Name"]);
	}
}