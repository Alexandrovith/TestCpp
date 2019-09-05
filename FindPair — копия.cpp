//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	������:			������� ���������� ������ �������� (driver) 
//~~~~~~~~~	������:			���            
//~~~~~~~~~	������:			����������� �������� ��� ���������� �� ������ �����	(as json)
//~~~~~~~~~	����������:	���������� �.�.
//~~~~~~~~~	����:				27.03.2019     

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include "FindPair.h"

CFindPair::CFindPair (std::string Tag)
{
	asTag = Tag;
}

CFindPair::~CFindPair ()
{}

//_________________________________________________________________________"parname":12"parname2":"321"

// �������� �� ���������� (��� ���) �����
// <param name="sStr">������ ��� ������ ��������</param>
// <param name="iStartFind">������� ������ ������ � ������</param>
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
		while (c != '"' && c != '_' && !IsLetterOrDigit (c)); // ����� ������� ��� �������� 
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

// �������� ��������� ��  �����
// <param name="sKey">����������, ��� ���� (������������ ���������)</param>
std::string CFindPair::Value (std::string sKey)
{
	std::string sRet = "";
	sKey = "\"" + sKey + "\"";
	iCurrPos = FindWord (sKey);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey.length ();
		sRet = Value (asTag, iCurrPos);     // ����� �������� �� ���������� (��� ���) �����
	}
	return sRet;
}
//_________________________________________________________________________

// �������� ��������� �� �����, ������� �� ������� ������� � ������
// <param name="sKey">����������, ��� ���� (������������ ���������)</param>
std::string CFindPair::ValueNext (std::string sKey)
{
	std::string sRet = "";
	iCurrPos = FindWord (sKey, iCurrPos);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey.length ();
		sRet = Value (asTag, iCurrPos);     // �������� �� ���������� (��� ���) �����
	}
	return sRet;
}
//_________________________________________________________________________

// ����� ������ ����� � ������ � ������ ������
int CFindPair::FindWord (std::string sKey)
{
	return iCurrPos = asTag.find (sKey);// .IndexOf (sKey);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// ����� ������ ����� � ������ � �������� �������
int CFindPair::FindWord (std::string sKey, int iPosNameParam)
{
	return iCurrPos = asTag.find (sKey, iPosNameParam + sKey.length ());
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// ����� ������� ������ ����� � ������
int CFindPair::Find (std::string sKey, int iPosNameParam)
{
	if (iPosNameParam > -1 && asTag.length () > iPosNameParam + sKey.length ())
	{
		// ����, ���� ��������� ��������, ������ sKey, �� ������ �������� ������ ������� �����
		int iLenKey = sKey.length ();
		auto NextSym = asTag[iPosNameParam + iLenKey];
		while ((iPosNameParam == 0 && IsLetterOrDigit (NextSym)) ||
			(iPosNameParam != 0) &&
			(IsLetterOrDigit (asTag[iPosNameParam - 1]) || IsLetterOrDigit (NextSym)))    // ���� ��� ����� �����
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
