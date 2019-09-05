///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///~~~~~~~~~	Проект:			Тест драйверов, написанных на cpp
///~~~~~~~~~	Модуль:			Конвертация Управляемый <-> Неуправляемый код
///~~~~~~~~~	Разработка:	Демешкевич С.А.
///~~~~~~~~~	Дата:				27.06.2017

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once
#include <string>

using namespace System;
using namespace System::Runtime::InteropServices;

ref class CConvMarsh
{
public:
	CConvMarsh();
	static void Close();
private:
	static IntPtr Ptr;
public:
	static std::string Convert(String^ StrFrom);
	static System::String^ Convert(std::string StrUnmngdFrom);
	static System::String^ Convert (const char* cpText);

	template <class T>
	static char* TypeToCharArr (T Val);
	static char* ByteArToCharArr (cli::array<Byte, 1> ^ Val);
	static IntPtr CharArrToByteArr (char*);
};

