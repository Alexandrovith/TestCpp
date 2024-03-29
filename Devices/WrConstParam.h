#pragma once

#include <memory>
#include <string>

#include "FindPair.h"
#include "LoadDLL.h"

class CWrConstParam
{
	class EParam 
	{
	public:
		enum Epar { Static_Pressure_Value, Temperature_Value, Differential_Pressure_Value, Tap_Location,  
								Static_Pressure_Flag, Temperature_Flag,	Differential_Pressure_Flag,			
					SIZE
					} Val;

		EParam ():
			Val(Differential_Pressure_Value)
		{
		}

		friend const Epar operator ++(Epar & i)
		{
			if (i < Epar::SIZE)
			{
				i = (Epar)(i + 1);
			}
			//else i = (Epar)0;
			return i;
		}

		void operator =(Epar val)
		{
			Val = val;
		}

		int ToInt ()
		{
			return (int)Val;
		}

		std::string ToString ()
		{
			return ToString (Val);
		}

		static std::string ToString (Epar val)
		{
			switch (val)
			{
			case CWrConstParam::EParam::Differential_Pressure_Value: return "Differential_Pressure_Value";
			case CWrConstParam::EParam::Static_Pressure_Value: return "Static_Pressure_Value";
			case CWrConstParam::EParam::Temperature_Value: return "Temperature_Value";
			case CWrConstParam::EParam::Differential_Pressure_Flag: return "Differential_Pressure_Flag";
			case CWrConstParam::EParam::Static_Pressure_Flag: return "Static_Pressure_Flag";
			case CWrConstParam::EParam::Temperature_Flag: return "Temperature_Flag";
			case CWrConstParam::EParam::Tap_Location: return "Tap_Location";
			case CWrConstParam::EParam::SIZE: return "SIZE";
			default: return "";
			}
		}
	};

	std::shared_ptr<CFindPair> FindPair = std::make_shared<CFindPair> ();
	int iaTagsRdOfConstPar[(int)EParam::SIZE];
	int iaTagsWrOfConstPar[(int)EParam::SIZE];
	CLoadDLL::DWriteValue WriteValue;
	CLoadDLL::DGetValue GetValue;
	char** capTagWr;

public:
	CWrConstParam (CLoadDLL::DWriteValue WriteValue, CLoadDLL::DGetValue GetValue, char** caTagWr);
	~CWrConstParam ();
	void GetIdOfConstParam (char* cpTag, int NumValByWr);
	void WrValue (EParam ParName, int iSizeVal);

	void OutBuf (char* caVal, int iSize);

	char* MessHelp ()
	{
		return " 0 - ������ ������� ���������, 1 - �������, ... �� 6 ";
	}
	int Process ();
	int ReadParams (bool& retflag);
	void OutRecieveVal (std::string ParName, int iSizeVal, unsigned char* cpVal);
};

