#include "Tags.h"
#include "Serialize.h"
#include "RowOutPar.h"

using namespace System;

namespace TestCpp
{
	CTags::CTags (void)
	{
		InitializeComponent ();

		FDOpenFl->Filter = "Файлы параметров|*.prmd|Все файлы|*.*";
		FDOpenFl->Title = "Открытие файла параметров";
		CSerialize::ReadFl (L"Superflo.prmd", PShowParams);
	}
	//___________________________________________________________________________

	System::Collections::ArrayList^ CTags::GetTagData (String^ asDevName)
	{
		System::Collections::ArrayList^ TagsList = gcnew System::Collections::ArrayList(4);
		for each (auto item in PShowParams->Controls)
		{
			CRowOutPar^ Row = dynamic_cast<CRowOutPar^>(item);
			if (Row != nullptr)
			{
				TagsList->Add (Row->GetTagDataRow (asDevName));
			}
		}
		return TagsList;
	}
}