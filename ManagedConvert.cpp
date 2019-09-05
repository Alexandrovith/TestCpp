///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///~~~~~~~~~	Проект:			Тест драйверов, написанных на cpp
///~~~~~~~~~	Модуль:			Конвертация Управляемый <-> Неуправляемый код
///~~~~~~~~~	Разработка:	Демешкевич С.А.
///~~~~~~~~~	Дата:				27.06.2017

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <Windows.h>
#include <string>
//#include <msclr/marshal.h>

#include "ManagedConvert.h"

//namespace msclr {
//	namespace interop {
//		template<>
//		inline TO marshal_as<class TO, class FROM> (const FROM& from) 
//		{
//			// Insert conversion logic here, and return a TO parameter.
//			
//		}
//	}
//}

CConvMarsh::CConvMarsh()
{
}
///____________________________________________________________________________

void CConvMarsh::Close()
{
	System::Runtime::InteropServices::Marshal::FreeHGlobal(Ptr);
}
///____________________________________________________________________________

std::string CConvMarsh::Convert(System::String^ StrFrom)
{
	Ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(StrFrom);
	return std::string((char*)(void*)Ptr);
}
///____________________________________________________________________________

System::String^ CConvMarsh::Convert(std::string StrUnmngdFrom)
{
	const char* cVal = StrUnmngdFrom.c_str();
	return System::Runtime::InteropServices::Marshal::PtrToStringAnsi((System::IntPtr)(char*)cVal);
}
///____________________________________________________________________________

System::String^ CConvMarsh::Convert(const char* cpText)
{
	return System::Runtime::InteropServices::Marshal::PtrToStringAnsi((System::IntPtr)(char*)cpText);
}
/////____________________________________________________________________________
//
//System::String^ CConvMarsh::Convert(LPCWSTR cpText)
//{
//	return Marshal::PtrToStringAnsi((IntPtr)(LPCWSTR)cpText);
//}
///____________________________________________________________________________

template <class T>
static char* CConvMarsh::TypeToCharArr (T Val)
{
	auto btVal = BitConverter::GetBytes (Val);

	pin_ptr<System::Byte> p = &btVal[0];
	UCHAR* pcVal = p;
	return reinterpret_cast<char*>(pcVal);
}
///____________________________________________________________________________

char* CConvMarsh::ByteArToCharArr (cli::array<System::Byte, 1> ^ Val)
{
	pin_ptr<System::Byte> p = &Val[0];
	UCHAR* pcVal = p;
	return reinterpret_cast<char*>(pcVal);
}
///____________________________________________________________________________

System::IntPtr CConvMarsh::CharArrToByteArr (char* cpVal)
{
	//Marshal::StructureToPtr (cpVal, Ptr, false);
	return Ptr;
}
