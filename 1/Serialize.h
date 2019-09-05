#pragma once

#include "FindPair.h"
#include <memory>

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
		RequestNamesWr->Add ("R43");
	}
	private: static int iCountPar;

	public:	static bool ReadFl (System::String^ asNameFl, System::Windows::Forms::Panel^ PanelOut);
	private: static void CSerialize::PanelClear (System::Windows::Forms::Panel^ PanelOut);
	private: static void AddParamRow (System::Windows::Forms::Panel^ PanelOut, std::shared_ptr<CFindPair> FindPair, int iNumPar);
	};
}

