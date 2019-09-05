//#include <variant>
//#include <iostream>
//#include <utility>
//#include <cassert>
//#include <filesystem>

#include "RMG.h"
#include "ManagedConvert.h"

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace std;

//const char* capTagWr[] = {
//	"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kCO2\"}"
//	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kN2\"}"
//	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"kd\"}"
//	,"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"W1\",\"ParamName\":\"Dat\"}"
//};

const char* cpInitDrv = "{\"Devices\":[{\"Name\":\"EC605_test\",\"Type\":\"\",\"Password\":\"22222\",\"WritePassword\":\"33333\",\"UserId\":\"01\",\"UrlSingleParam\":\"192.168.1.23\",\"Address\":1,\"BaudRate\":9600,\"Port\":\"520\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"FlowCtrl\":0,\"SetRTS\":0,\"TD\":\"23112017\",\"TH\":\"23112017\",\"TI\":\"01112017\",\"TA\":\"14042017\",\"Transport\":\"Ethernet\"}]}";

//const char* capTags[] = {
//	//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"H2\",\"ArchiveName\":\"H2\"}",
//		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"Service\"}",
//		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kCO2\"}",
//		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kN2\"}",
//		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R4\",\"ParamName\":\"kd\"}",
//		"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Dat\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Tpr\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R6\",\"ArchiveName\":\"as\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"verze\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"CZ\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Pvc\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Dsm\"}",
//		//"{\"DeviceName\":\"EC605_test\",\"RequestName\":\"R2\",\"ParamName\":\"Adr\"}" 
//};

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CRMG::CRMG (DOutMess^ OutMess) : CDevice (OutMess)
	{
	}
	//_____________________________________________________________________________

	int CRMG::Write (std::string cpAddr, BYTE* baVal, int iLenPar)
	{
		return WriteValue ((char*)cpAddr.c_str (), (char*)baVal, iLenPar);
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
		return iLenVal;
	}
	//_____________________________________________________________________________

	int CRMG::InitDev (System::String^ asDevType, System::String^ asPort)
	{
		// Добавить вставку типа прибора
		InitConfig ((char*)cpInitDrv);
		return 0;
	}
	//_____________________________________________________________________________

}