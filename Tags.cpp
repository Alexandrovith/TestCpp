#include "RowOutPar.h"
#include "Tags.h"

namespace TestCpp
{
	CTags::CTags ()
	{
		InitializeComponent ();

		FDOpenFl->Filter = "Файлы параметров|*.prmd|Все файлы|*.*";
		FDOpenFl->Title = "Открытие файла параметров";
		/*CSerialize::ReadFl ("Superflo.prmd", PShowParams);*/
	}
	//___________________________________________________________________________

	System::Collections::Hashtable^ CTags::GetRdData (System::String^ asDevName)
	{
		System::Collections::Hashtable^ TagsList = gcnew System::Collections::Hashtable ();
		for each (auto item in PShowParams->Controls)
		{
			CRowOutPar^ Row = dynamic_cast<CRowOutPar^>(item);
			if (Row != nullptr)
			{
				int iTagId;
				String^ asTag = Row->GetTagDataRowChecked (asDevName, iTagId);
				if (asTag != nullptr)
					TagsList[iTagId] = asTag;
			}
		}
		return TagsList;
	}
	//___________________________________________________________________________

	System::Collections::ArrayList^ CTags::GetWrData (System::String^ asDevName)
	{
		System::Collections::ArrayList^ TagsList = gcnew System::Collections::ArrayList (3);
		for each (auto item in PShowParams->Controls)
		{
			CRowOutPar^ Row = dynamic_cast<CRowOutPar^>(item);
			if (Row != nullptr)
			{
				CDataForWr^ TagWr = Row->GetTagWrRowChecked (asDevName);
				if (TagWr != nullptr)
				{
					TagsList->Add (TagWr);
				}
			}
		}
		return TagsList;
	}
	//___________________________________________________________________________

	System::String^ CTags::GetType (int iId)
	{
		for each (auto item in PShowParams->Controls)
		{
			CRowOutPar^ Row = dynamic_cast<CRowOutPar^>(item);
			if (Row != nullptr)
			{
				int iTagId = (int)Row->Tag;
				if (iTagId == iId)
				{
					return Row->TBType->Text;
				}
			}
		}
		 System::String^ asRet;
		 return asRet;
	}
	//___________________________________________________________________________

	void CTags::OutVal (int iId, System::String^ asVal)
	{
		for each (auto item in PShowParams->Controls)
		{
			CRowOutPar^ Row = dynamic_cast<CRowOutPar^>(item);
			if (Row != nullptr)
			{
				int iTagId = (int)Row->Tag;
				if (iTagId == iId)
				{
					Row->TBVal->Text = asVal;
					return;
				}
			}
		}
	}
}