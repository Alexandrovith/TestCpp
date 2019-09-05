#include "Serialize.h"
#include "RowOutPar.h"
#include "ManagedConvert.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

namespace TestCpp
{
	//___________________________________________________________________________

	const int START_TAG_ID_WR = 1024;

	bool CSerialize::ReadFl (const String^ asNameFl, Control^ PanelOutRd, Control^ PanelOutWr, DOutMess^ OutMess)
	{
		if (File::Exists ((String^)asNameFl))
		{
			CFindPair^ FindPair = gcnew CFindPair();
			PanelClear (PanelOutRd);
			StreamReader^ SR = File::OpenText ((String^)asNameFl);
			{
				int iNumParRd = 0;
				int iNumParWr = START_TAG_ID_WR;
				String^ asLine = nullptr;
				while (true)
				{
					asLine = SR->ReadLine ();
					if (asLine != nullptr)
					{
						//cli::array<System::String^, 1>^ asaTag = asLine->Split (';');
						FindPair->InitTag (asLine);
						//String^ asms = FindPair->operator[]("RequestName");
						if (RequestNamesWr->Contains (FindPair->operator[]("RequestName")))
						{																											// Добавление тега для записи параметра 
							AddParamRow (PanelOutWr, FindPair, iNumParWr - START_TAG_ID_WR, iNumParWr);
							iNumParWr++;
						}
						else
						{
							AddParamRow (PanelOutRd, FindPair, iNumParRd, iNumParRd + 1); // Добавление тега для чтения параметра 
							iNumParRd++;
						}
					}
					else break;
				}
			}
			return true;
		}
		OutMess ("Файл [" + (String^)asNameFl + "] не найден");
		return false;
	}
	//___________________________________________________________________________

	void CSerialize::PanelClear (Control^ PanelOut)
	{
		PanelOut->Controls->Clear ();
	}
	//___________________________________________________________________________

	void CSerialize::AddParamRow (Control^ PanelOut, CFindPair^ FindPair, int iNumPar, int iId)
	{
		const int iTOP = 0;
		const int iLEFT = 0;
		const int iDeltaV = 17;

		CRowOutPar^ Row = gcnew CRowOutPar ();
		Row->Left = iLEFT;
		Row->Top = iTOP + iNumPar * iDeltaV;
		Row->Parent = PanelOut;
		Row->Tag = iId;												// Id тега параметра 
		Row->FillControlByName ("TBRequestName", FindPair->operator[]("RequestName"));
		Row->FillControlByName ("TBParamName", FindPair->operator[]("ParamName"));
		Row->FillControlByName ("TBType", FindPair->operator[]("Type"));

		System::String^ asName = FindPair->operator[]("Name");

		if (asName->Length == 0)
			Row->asRunNumber = "";
		else if (asName == "RunNumber")
			Row->asRunNumber = "\"Name\":\"RunNumber\",";
		else
		{
			if (asName == "SuperFlo_Write_Password" && FindPair->ValueNext ("Name")->Length > 0) // Если нашли RunNumber в ком.записи 
				Row->asRunNumber = "\"Name\":\"RunNumber\",";
			else Row->asRunNumber = "";
		}
		//Row->asRunNumber = FindPair->operator[]("Name")->Length == 0 ? "" : "\"Name\":\"\",";
	}
	//___________________________________________________________________________

}