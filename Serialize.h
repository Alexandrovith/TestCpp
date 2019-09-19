#pragma once

#include "FindPair.h"
#include "Typesdef.h"
#include "SavePropert.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

namespace TestCpp
{
	ref class CSerialize
	{
#pragma region //xxxxxxxxxxxxxxxxxxxxxx    Ï Î Ñ Ò Î ß Í Í Û Å    xxxxxxxxxxxxxxxxxxxxxxxxx

		const String^ FlSuperPrmd = "Superflo.prmd";
		const String^ FlRMGPrmd = "RMG.prmd";

		static System::Collections::ArrayList^ RequestNamesWr = gcnew System::Collections::ArrayList ();

#pragma endregion
#pragma region //xxxxxxxxxxxxxxxxxxxxxx    Ï Å Ð Å Ì Å Í Í Û Å    xxxxxxxxxxxxxxxxxxxxxxxxx

	private: int iCountPar;
					 DOutMess^ OutMess;
					 CSavePropert^ SavePropert;

#pragma endregion

	public: CSerialize (DOutMess^ OutMess, CSavePropert^ SavePropert)
	{
		this->OutMess = OutMess;
		this->SavePropert = SavePropert;

		RequestNamesWr->Add ("R35");
		RequestNamesWr->Add ("R37");
		RequestNamesWr->Add ("R43");
	}

	public:	bool ReadFlSetups (const String^ asNameFl, Control^ PanelOutRd, Control^ PanelOutWr/*, DOutMess^ OutMess,*/
											/*System::Collections::ArrayList^ iaRowsCheck, CSavePropert^ SavePropert*/);
	private: void CSerialize::PanelClear (System::Windows::Forms::Control^ PanelOut);
	private: void AddParamRow (System::Windows::Forms::Control^ PanelOut, CFindPair^ FindPair, int iNumPar, int iId, System::Collections::ArrayList^ RowsCheck);
	private: bool IsRowChecked (int iNumPar, System::Collections::ArrayList^ RowsCheck);
	private: System::Collections::ArrayList^ GetCheckedTagsRd (const String^ asFilePrmd);
					 System::Collections::ArrayList^ GetCheckedTagsWr (const String^ asFilePrmd);
					 System::Collections::ArrayList^ GetCheckedTags (System::String^ asTagName);
	};
}

