#include "Serialize.h"
#include "RowOutPar.h"
#include "ManagedConvert.h"

#include <memory>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

namespace TestCpp
{
	//___________________________________________________________________________

	bool CSerialize::ReadFl (String^ asNameFl, Panel^ PanelOut)
	{
		if (File::Exists (asNameFl))
		{
			std::shared_ptr<CFindPair> FindPair = std::make_shared<CFindPair> ();
			PanelClear (PanelOut);
			StreamReader^ SR = File::OpenText (asNameFl);
			{
				int iNumPar = 0;
				String^ asLine = nullptr;
				while (true)
				{
					asLine = SR->ReadLine ();
					if (asLine != nullptr)
					{
						//cli::array<System::String^, 1>^ asaTag = asLine->Split (';');
						FindPair->InitTag (CConvMarsh::Convert (asLine));
						if (RequestNamesWr->Contains (CConvMarsh::Convert (FindPair->operator[]("RequestName"))) == false)
							AddParamRow (PanelOut, FindPair, iNumPar++);
					}
					else break;
				}
			}
			return true;
		}
		return false;
	}
	//___________________________________________________________________________

	void CSerialize::PanelClear (Panel^ PanelOut)
	{
		PanelOut->Controls->Clear ();

	}
	//___________________________________________________________________________

	void CSerialize::AddParamRow (Panel^ PanelOut, std::shared_ptr<CFindPair> FindPair, int iNumPar)
	{
		const int iTOP = 0;
		const int iLEFT = 0;
		const int iDeltaV = 15;

		CRowOutPar^ Row = gcnew CRowOutPar ();
		Row->Left = iLEFT;
		Row->Top = iTOP + iNumPar * iDeltaV;
		Row->Parent = PanelOut;
		Row->Tag = iNumPar + 1;
		Row->FillControlByName ("TBRequestName", CConvMarsh::Convert (FindPair->operator[]("RequestName")));
		Row->FillControlByName ("TBParamName", CConvMarsh::Convert (FindPair->operator[]("ParamName")));
	}
	//___________________________________________________________________________

}