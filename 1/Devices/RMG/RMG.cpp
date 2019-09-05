#include "RMG.h"
#include "LoadDLL.h"
#include "TestCpp.h"
#include "ManagedConvert.h"

#include <variant>
#include <iostream>
#include <utility>
#include <cassert>
#include <filesystem>

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace std;

//LPCWSTR cpDll = L"GeneralR.dll";
////DInitDll InitDll;
//TRunSubscribe RunSubscribe;
//TRunInitConfig RunInitConfig;
//TRun Run;

const char* capTagWr[] = {
	"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kCO2\"}"
	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kN2\"}"
	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kd\"}"
	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"Dat\"}"
};

const char* cpInitDrv = "{\"Devices\":[{\"Name\":\"EC605_test\",\"Type\":\"\",\"Password\":\"22222\",\"WritePassword\":\"33333\",\"UserId\":\"01\",\"UrlSingleParam\":\"192.168.1.23\",\"Address\":1,\"BaudRate\":9600,\"Port\":\"520\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"FlowCtrl\":0,\"SetRTS\":0,\"TD\":\"23112017\",\"TH\":\"23112017\",\"TI\":\"01112017\",\"TA\":\"14042017\",\"Transport\":\"Ethernet\"}]}";

const char* capTags[] = {
	//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"H2\",\"ArchiveName\":\"H2\"}",
		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"Service\"}",
		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kCO2\"}",
		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kN2\"}",
		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kd\"}",
		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Dat\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Tpr\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R6\",\"ArchiveName\":\"as\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"verze\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"CZ\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Pvc\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Dsm\"}",
		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Adr\"}" 
};

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CRMG::CRMG (DOutMess^ OutMess) : CDevice (OutMess)
	{
	}
	//_____________________________________________________________________________

	//void CRMG::DllLoad (cli::array<System::String^, 2> ^ Tags)
	//{
	//	std::shared_ptr<CLoadDLL> LoadDLL (new CLoadDLL (cpDll));
	//
	//	InitDll = (DInitDll)LoadDLL->Load ("InitDll");
	//	if (InitDll == nullptr)
	//		throw "Error: load RMG.InitDll";
	//	InitDll ();
	//	InitDev ();
	//	RunSubscribe (Tags);
	//}
	//_____________________________________________________________________________

	int CRMG::Write (String^ cpAddr, cli::array<System::Byte, 1> ^ baVal)
	{
		return WriteValue ((char*)CConvMarsh::Convert (cpAddr).c_str (), (char*)CConvMarsh::ByteArToCharArr (baVal), baVal->Length);
	}
	//_____________________________________________________________________________

	int CRMG::GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal)
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

	int CRMG::InitDev ()
	{
		InitConfig ((char*)cpInitDrv);
		return 0;
	}
	//_____________________________________________________________________________

	//int CRMG::RunSubscribe (cli::array<System::String^, 2> ^ Tags)
	//{
	//	int iTagId = 0;
	//	for each (String^ tag in Tags)
	//	{
	//		Subscribe (iTagId++, (char*)CConvMarsh::Convert (tag).c_str());
	//	}
	//	return 0;
	//}
}