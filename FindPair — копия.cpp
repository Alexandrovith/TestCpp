//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	Проект:			Базовая библиотека опроса приборов (driver) 
//~~~~~~~~~	Прибор:			Все            
//~~~~~~~~~	Модуль:			Вычитывание настроек для параметров из строки тегов	(as json)
//~~~~~~~~~	Разработка:	Демешкевич С.А.
//~~~~~~~~~	Дата:				27.03.2019     

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include "FindPair.h"

CFindPair::CFindPair (std::string Tag)
{
	asTag = Tag;
}

CFindPair::~CFindPair ()
{}

//_________________________________________________________________________"parname":12"parname2":"321"

// Значение по найденному (или нет) ключу
// <param name="sStr">Строка для поиска значения</param>
// <param name="iStartFind">Позиция начала поиска в строке</param>
std::string CFindPair::Value (std::string sStr, int iStartFind)
{
	std::string sRet = "";
	int iEnd = sStr.length ();
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
		while (c != '"' && c != ',')// && (IsLetterOrDigit (c) || c == ' ' || c == '-' || c == '+' || c == '.' || c == '_'))
		{
			if (c != 0)
				sRet += c;
			if (++iStartFind >= iEnd)
				return sRet;
			c = sStr[iStartFind];
		}
		break;
	}
	return sRet;
}
//_________________________________________________________________________

// Значение параметра по  ключу
// <param name="sKey">Собственно, сам ключ (наименование параметра)</param>
std::string CFindPair::Value (std::string sKey)
{
	std::string sRet = "";
	sKey = "\"" + sKey + "\"";
	iCurrPos = FindWord (sKey);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey.length ();
		sRet = Value (asTag, iCurrPos);     // Поиск значения по найденному (или нет) ключу
	}
	return sRet;
}
//_________________________________________________________________________

// Значение параметра по ключу, начиная от текущей позиции в строке
// <param name="sKey">Собственно, сам ключ (наименование параметра)</param>
std::string CFindPair::ValueNext (std::string sKey)
{
	std::string sRet = "";
	iCurrPos = FindWord (sKey, iCurrPos);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey.length ();
		sRet = Value (asTag, iCurrPos);     // Значение по найденному (или нет) ключу
	}
	return sRet;
}
//_________________________________________________________________________

// Поиск целого слова в строке с начала строки
int CFindPair::FindWord (std::string sKey)
{
	return iCurrPos = asTag.find (sKey);// .IndexOf (sKey);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// Поиск целого слова в строке с заданной позиции
int CFindPair::FindWord (std::string sKey, int iPosNameParam)
{
	return iCurrPos = asTag.find (sKey, iPosNameParam + sKey.length ());
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// Поиск позиции целого слова в строке
int CFindPair::Find (std::string sKey, int iPosNameParam)
{
	if (iPosNameParam > -1 && asTag.length () > iPosNameParam + sKey.length ())
	{
		// Ищем, пока найденное значение, равное sKey, не станет являться частью другого слова
		int iLenKey = sKey.length ();
		auto NextSym = asTag[iPosNameParam + iLenKey];
		while ((iPosNameParam == 0 && IsLetterOrDigit (NextSym)) ||
			(iPosNameParam != 0) &&
			(IsLetterOrDigit (asTag[iPosNameParam - 1]) || IsLetterOrDigit (NextSym)))    // Если это часть слова
		{
			iPosNameParam = asTag.find (sKey, iPosNameParam + iLenKey);
			if (iPosNameParam == -1)
				return iPosNameParam;
		}
		iCurrPos = iPosNameParam;
		return iPosNameParam;
	}
	return -1;
}
//_________________________________________________________________________
