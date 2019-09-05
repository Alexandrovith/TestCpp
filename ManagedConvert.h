///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///~~~~~~~~~	Проект:			Тест драйверов, написанных на cpp
///~~~~~~~~~	Модуль:			Конвертация Управляемый <-> Неуправляемый код
///~~~~~~~~~	Разработка:	Демешкевич С.А.
///~~~~~~~~~	Дата:				27.06.2017

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once

#include <string>

//using namespace System;
//using namespace System::Runtime::InteropServices;

ref class CConvMarsh
{
public:
	CConvMarsh();
	static void Close();
private:
	static System::IntPtr Ptr;
public:
	static std::string Convert(System::String^ StrFrom);
	static System::String^ Convert(std::string StrUnmngdFrom);
	static System::String^ Convert (const char* cpText);

	template <class T>
	static char* TypeToCharArr (T Val);
	static char* ByteArToCharArr (cli::array<System::Byte, 1> ^ Val);
	static System::IntPtr CharArrToByteArr (char*);
};

