#include "FindPair.h"
#include "Superflo.h"
#include "ManagedConvert.h"
#include "Init_Superflo.cpp"

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CSuperflo::CSuperflo (DOutMess^ OutMess) : CDevice (OutMess)
	{
	}
	//_____________________________________________________________________________

	int CSuperflo::Write (std::string cpAddr, BYTE* baVal, int iLenPar)
	{
		return WriteValue ((char*)cpAddr.c_str (), (char*)baVal, iLenPar);
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

	int CSuperflo::InitDev (System::String^ asDevType, System::String^ asPort)
	{
		RdDevName ();
		System::String^ asInit = CConvMarsh::Convert ((char*)caInit ());
		CFindPair FindPair (asInit);
		asInit = asInit->Replace (FindPair["Type"], asDevType);
		InitConfig ((char*)CConvMarsh::Convert (asInit->Replace (FindPair["Port"], asPort)).c_str());// Только для первого прибора в списке 
		return 0;
	}
	//_____________________________________________________________________________

	void CSuperflo::RdDevName ()
	{
		CFindPair FindPair;
		FindPair.InitTag (CConvMarsh::Convert ((char*)caInit ()));
		//asDevName = msclr::interop::marshal_as<System::String^> (FindPair["Name"]);
		asDevName = FindPair["Name"];
	}
}