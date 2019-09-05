//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	������:			������� ���������� ������ �������� (driver) 
//~~~~~~~~~	������:			���            
//~~~~~~~~~	������:			����������� �������� ��� ���������� �� ������ �����	(as json)
//~~~~~~~~~	����������:	���������� �.�.
//~~~~~~~~~	����:				27.03.2019     

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

// �������� �� ���������� (��� ���) �����
// <param name="sStr">������ ��� ������ ��������</param>
// <param name="iStartFind">������� ������ ������ � ������</param>
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

// �������� ��������� ��  �����
// <param name="sKey">����������, ��� ���� (������������ ���������)</param>
System::String^ CFindPair::Value (System::String^ sKey)
{
	System::String^ sRet = "";
	sKey = "\"" + sKey + "\"";
	iCurrPos = FindWord (sKey);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey->Length;
		sRet = Value (asTag, iCurrPos);     // ����� �������� �� ���������� (��� ���) �����
	}
	return sRet;
}
//_________________________________________________________________________

// �������� ��������� �� �����, ������� �� ������� ������� � ������
// <param name="sKey">����������, ��� ���� (������������ ���������)</param>
System::String^ CFindPair::ValueNext (System::String^ sKey)
{
	System::String^ sRet = "";
	iCurrPos = FindWord (sKey, iCurrPos);
	if (iCurrPos > -1)
	{
		iCurrPos += sKey->Length;
		sRet = Value (asTag, iCurrPos);     // �������� �� ���������� (��� ���) �����
	}
	return sRet;
}
//_________________________________________________________________________

// ����� ������ ����� � ������ � ������ ������
int CFindPair::FindWord (System::String^ sKey)
{
	return iCurrPos = asTag->IndexOf (sKey);// .IndexOf (sKey);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// ����� ������ ����� � ������ � �������� �������
int CFindPair::FindWord (System::String^ sKey, int iPosNameParam)
{
	return iCurrPos = asTag->IndexOf (sKey, iPosNameParam + sKey->Length);
	//return Find (sKey, iCurrPos);
}
//_________________________________________________________________________

// ����� ������� ������ ����� � ������
int CFindPair::Find (System::String^ sKey, int iPosNameParam)
{
	if (iPosNameParam > -1 && asTag->Length > iPosNameParam + sKey->Length)
	{
		// ����, ���� ��������� ��������, ������ sKey, �� ������ �������� ������ ������� �����
		int iLenKey = sKey->Length;
		auto NextSym = asTag[iPosNameParam + iLenKey];
		while ((iPosNameParam == 0 && IsLetterOrDigit (NextSym)) ||
			(iPosNameParam != 0) &&
			(IsLetterOrDigit (asTag[iPosNameParam - 1]) || IsLetterOrDigit (NextSym)))    // ���� ��� ����� �����
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
