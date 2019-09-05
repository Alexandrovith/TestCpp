//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	Проект:			Базовая библиотека опроса приборов (driver) 
//~~~~~~~~~	Прибор:			Все            
//~~~~~~~~~	Модуль:			Вычитывание настроек для параметров из строки тегов	(as json)
//~~~~~~~~~	Разработка:	Демешкевич С.А.
//~~~~~~~~~	Дата:				27.03.2019     

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <string>

#include "FindPair.h"
#include "ManagedConvert.h"

CFindPair::CFindPair (System::String^ Tag)
{
	asTag = Tag;
}

CFindPair::~CFindPair ()
{}

//_________________________________________________________________________"parname":12"parname2":"321"

// Значение по найденному (или нет) ключу
// <param name="sStr">Строка для поиска значения</param>
// <param name="iStartFind">Позиция начала поиска в строке</param>
System::String^ CFindPair::Value (System::String^ sStr, int iStartFind)
{
	System::String^ sRet = "";
	int iEnd = sStr->Length;
	for (; iStartFind < iEnd; iStartFind++)
	{
		char c = sStr[iStartFind];
		if (c != ':')
			continue;
		do
			c = sStr[++iStartFind];
		while (c != '"' && c != '_' && !IsLetterOrDigit (c)); // Нашли кавычки или значение 
		if (c == '"')
		{
			if (sStr[iStartFind + 1] == '"')
				return "";
			c = 0;// ' ';
		}
		else c = sStr[--iStartFind];
		//while (c != '"' && IsLetterOrDigit (c) == false)   //c != '"' || 
		while (c != /*'_' && */IsLetterOrDigit (c) == false && c != '"')
		{
			if (++iStartFind >= iEnd)
				return sRet;
			c = sStr[iStartFind];
		}
		
		std::string str;
		while (c != '"' && c != ',')// && (IsLetterOrDigit (c) || c == ' ' || c == '-' || c == '+' || c == '.' || c == '_'))
		{
			if (c != 0)
			{
				str += c;				//sRet += c;
			}
			if (++iStartFind >= iEnd)
			{			
				return CConvMarsh::Convert(str);
			}
			c = sStr[iStartFind];
		}
		sRet = CConvMarsh::Convert(str);
		break;
	}
	return sRet;
}
//_________________________________________________________________________

// Значение параметра по  ключу
// <param name="sKey">Собственно, сам ключ (наименование параметра)</param>
System::String^ CFindPair::Value (System::String^ sKey)
{
	System::String^ sRet = "";
	sKey = "\"" + sKey + "\"";
	iCurrPos = FindWord (sKey);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey->Length;
		sRet = Value (asTag, iCurrPos);     // Поиск значения по найденному (или нет) ключу
	}
	return sRet;
}
//_________________________________________________________________________

// Значение параметра по ключу, начиная от текущей позиции в строке
// <param name="sKey">Собственно, сам ключ (наименование параметра)</param>
System::String^ CFindPair::ValueNext (System::String^ sKey)
{
	System::String^ sRet = "";
	iCurrPos = FindWord (sKey, iCurrPos);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey->Length;
		sRet = Value (asTag, iCurrPos);     // Значение по найденному (или нет) ключу
	}
	return sRet;
}
//_________________________________________________________________________

// Поиск целого слова в строке с начала строки
int CFindPair::FindWord (System::String^ sKey)
{
	return iCurrPos = asTag->IndexOf (sKey);// .IndexOf (sKey);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// Поиск целого слова в строке с заданной позиции
int CFindPair::FindWord (System::String^ sKey, int iPosNameParam)
{
	return iCurrPos = asTag->IndexOf (sKey, iPosNameParam + sKey->Length);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// Поиск позиции целого слова в строке
int CFindPair::Find (System::String^ sKey, int iPosNameParam)
{
	if (iPosNameParam > -1 && asTag->Length > iPosNameParam + sKey->Length)
	{
		// Ищем, пока найденное значение, равное sKey, не станет являться частью другого слова
		int iLenKey = sKey->Length;
		auto NextSym = asTag[iPosNameParam + iLenKey];
		while ((iPosNameParam == 0 && IsLetterOrDigit (NextSym)) ||
			(iPosNameParam != 0) &&
			(IsLetterOrDigit (asTag[iPosNameParam - 1]) || IsLetterOrDigit (NextSym)))    // Если это часть слова
		{
			iPosNameParam = asTag->IndexOf (sKey, iPosNameParam + iLenKey);
			if (iPosNameParam == -1)
				return iPosNameParam;
		}
		iCurrPos = iPosNameParam;
		return iPosNameParam;
	}
	return -1;
}
//_________________________________________________________________________
