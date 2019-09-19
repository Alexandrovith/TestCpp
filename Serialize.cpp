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

	bool CSerialize::ReadFlSetups (const String^ asNameFl, Control^ PanelOutRd, Control^ PanelOutWr/*, DOutMess^ OutMess,*/ 
													 /*System::Collections::ArrayList^ iaRowsCheck, CSavePropert^ SavePropert*/)
	{
		if (File::Exists ((String^)asNameFl))
		{
			System::Collections::ArrayList^ CheckedTagsWr = GetCheckedTagsWr (asNameFl);
			System::Collections::ArrayList^ CheckedTagsRd = GetCheckedTagsRd (asNameFl);
			CFindPair^ FindPair = gcnew CFindPair();
			PanelClear (PanelOutRd);
			PanelClear (PanelOutWr);

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
						FindPair->InitTag (asLine);
						if (RequestNamesWr->Contains (FindPair->operator[]("RequestName")))
						{																											// Добавление тега для записи параметра 
							AddParamRow (PanelOutWr, FindPair, iNumParWr - START_TAG_ID_WR, iNumParWr, CheckedTagsWr);
							iNumParWr++;
						}
						else
						{
							AddParamRow (PanelOutRd, FindPair, iNumParRd, iNumParRd + 1, CheckedTagsRd); // Добавление тега для чтения параметра 
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
	///___________________________________________________________________________

	System::Collections::ArrayList^ CSerialize::GetCheckedTagsRd (const String^ asFilePrmd)
	{
		//String^ asTagName;
		//if (asFilePrmd == FlSuperPrmd)
		//{
		//	asTagName = "CheckTagsSuperRd";
		//}
		//else
		//{
		//	asTagName = "CheckTagsRMGRd";
		//}
		return GetCheckedTags ((asFilePrmd == FlSuperPrmd)? "CheckTagsSuperRd":"CheckTagsRMGRd");
	}
	///___________________________________________________________________________

	System::Collections::ArrayList^ CSerialize::GetCheckedTagsWr (const String^ asFilePrmd)
	{
		//String^ asTagName;
		//if (asFilePrmd == FlSuperPrmd)
		//{
		//	asTagName = "CheckTagsSuperWr";
		//}
		//else
		//{
		//	asTagName = "CheckTagsRMGWr";
		//}
		return GetCheckedTags ((asFilePrmd == FlSuperPrmd)?"CheckTagsSuperWr":"CheckTagsRMGWr");
	}
	//___________________________________________________________________________

	System::Collections::ArrayList^ CSerialize::GetCheckedTags (System::String^ asTagName)
	{
		ArrayList^ Ret = gcnew ArrayList ();
		auto TagsRd = SavePropert->Get (asTagName);
		String^ asTags;
		if (TagsRd != nullptr)
		{
			asTags = static_cast<String^>(TagsRd);
			auto asaTagsRd = asTags->Split (';');

			for each (auto item in asaTagsRd)
			{
				int iTag;
				if (int::TryParse (item, iTag))
				{
					Ret->Add (iTag);
				}
			}
		}
		return Ret;
	}
	//___________________________________________________________________________

	void CSerialize::PanelClear (Control^ PanelOut)
	{
		PanelOut->Controls->Clear ();
	}
	//___________________________________________________________________________

	void CSerialize::AddParamRow (Control^ PanelOut, CFindPair^ FindPair, int iNumPar, int iId, System::Collections::ArrayList^ iaRowsCheck)
	{
		const int iTOP = 0;
		const int iLEFT = 0;
		const int iDeltaV = 17;

		CRowOutPar^ Row = gcnew CRowOutPar (iNumPar, SavePropert);
		Row->Left = iLEFT;
		Row->Top = iTOP + iNumPar * iDeltaV;
		Row->Parent = PanelOut;
		Row->Tag = iId;												// Id тега параметра 
		Row->FillControlByName ("TBRequestName", FindPair->operator[]("RequestName"));
		Row->FillControlByName ("TBParamName", FindPair->operator[]("ParamName"));
		Row->FillControlByName ("TBType", FindPair->operator[]("Type"));
		Row->FillCheckBox (IsRowChecked (iNumPar, iaRowsCheck));

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
	}
	//___________________________________________________________________________

	bool CSerialize::IsRowChecked (int iNumPar, System::Collections::ArrayList^ RowsCheck)
	{
		return RowsCheck->Contains (iNumPar);
	}
	//___________________________________________________________________________

}