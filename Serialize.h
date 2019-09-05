#pragma once

#include "FindPair.h"
#include "Typesdef.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

namespace TestCpp
{
	ref class CSerialize
	{
		static System::Collections::ArrayList^ RequestNamesWr = gcnew System::Collections::ArrayList ();// = { "R35" };
	public: static CSerialize ()
	{
		RequestNamesWr->Add ("R35");
		RequestNamesWr->Add ("R37");
		RequestNamesWr->Add ("R43");
	}
	private: static int iCountPar;

	public:	static bool ReadFl (const System::String^ asNameFl, System::Windows::Forms::Control^ PanelOutRd, Control^ PanelOutWr, DOutMess^ OutMess);
	private: static void CSerialize::PanelClear (System::Windows::Forms::Control^ PanelOut);
	private: static void AddParamRow (System::Windows::Forms::Control^ PanelOut, CFindPair^ FindPair, int iNumPar, int iId);
	};
}

