//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	Проект:			Базовая библиотека опроса приборов (driver)      
//~~~~~~~~~	Прибор:			Все                                     
//~~~~~~~~~	Модуль:			Вычитывание настроек для параметров из строки тегов	(as json)
//~~~~~~~~~	Разработка:	Демешкевич С.А.                                    		  
//~~~~~~~~~	Дата:				27.03.2019                                         		  

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once

#include <Windows.h>
//#include <string>

//=============================================================================

ref class CFindPair
{
public:
	CFindPair (System::String^ Tag);
	CFindPair () {}
	~CFindPair ();

	System::String^ operator [](System::String^ asKey)
	{
		return Value (asKey);
	}
	int CurrPos () { return iCurrPos; }
	System::String^ Tag () { return asTag; }
	void InitTag (System::String^ Tag)
	{
		asTag = Tag;
		iCurrPos = 0;
	}

	System::String^ Value (System::String^ sKey);
	System::String^ ValueNext (System::String^ sKey);
		
private:
	System::String^ asTag;
	int iCurrPos = 0;

	int Find (System::String^ sKey, int iPosNameParam);
	int FindWord (System::String^ sKey, int iPosNameParam);
	int FindWord (System::String^ sKey);
	virtual System::String^ Value (System::String^ sStr, int iStartFind);

	bool IsLetterOrDigit (char cSym)
	{
		return (isascii (cSym));
	}

};

