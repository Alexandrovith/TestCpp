//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//~~~~~~~~~	������:			������� ���������� ������ �������� (driver)      
//~~~~~~~~~	������:			���                                     
//~~~~~~~~~	������:			����������� �������� ��� ���������� �� ������ �����	(as json)
//~~~~~~~~~	����������:	���������� �.�.                                    		  
//~~~~~~~~~	����:				27.03.2019                                         		  

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once

#include <Windows.h>
#include <string>

//=============================================================================

class CFindPair
{
public:
	CFindPair (std::string Tag);
	CFindPair () {}
	~CFindPair ();

	std::string operator [](std::string asKey)
	{
		return Value (asKey);
	}
	int CurrPos () { return iCurrPos; }
	std::string Tag () { return asTag; }
	void InitTag (std::string Tag)
	{
		asTag = Tag;
		iCurrPos = 0;
	}

	std::string Value (std::string sKey);
		
private:
	std::string asTag;
	int iCurrPos = 0;

	int Find (std::string sKey, int iPosNameParam);
	int FindWord (std::string sKey, int iPosNameParam);
	int FindWord (std::string sKey);
	std::string ValueNext (std::string sKey);
	virtual std::string Value (std::string sStr, int iStartFind);

	bool IsLetterOrDigit (char cSym)
	{
		return (isascii (cSym));
	}

};

