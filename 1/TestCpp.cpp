#include "TestCpp.h"
#include "Tags.h"
#include "Typesdef.h"
#include "ManagedConvert.h"

using namespace System;
using namespace System::Windows::Forms;


namespace TestCpp
{
	DInitDll InitDll;
	TRunSubscribe RunSubscribe;
	TRunInitConfig RunInitConfig;
	TRun Run;

	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	FTestCpp::FTestCpp (void)
	{
		InitializeComponent ();

		PDOutMess = gcnew DOutMess (this, &FTestCpp::OutMess);

		CreateTagsFrame (PTagsSuper);

	}
	///___________________________________________________________________________

	System::Void FTestCpp::CreateTagsFrame (System::Windows::Forms::Control^ Parent)
	{
		Tags = gcnew CTags ();
		Tags->Parent = Parent;
		Tags->Dock = System::Windows::Forms::DockStyle::Fill;
		Tags->Show ();
	}
	///___________________________________________________________________________

	System::Void FTestCpp::BLoadDllSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (Superflo == nullptr)
		{
			try
			{
				Superflo = gcnew CSuperflo (PDOutMess);
				Superflo->DllLoad (L"UsefullF.dll");
			}
			catch (const std::exception& exc)
			{
				TBOut->AppendText ("Superflo: " + CConvMarsh::Convert (exc.what ()));
				return;
			}
			TBOut->AppendText ("Superflo: dll загружена");
		}

	}
	///___________________________________________________________________________

	System::Void FTestCpp::BLoadDll_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (RMG == nullptr)
		{
			try
			{
				RMG = gcnew CRMG (PDOutMess);			//RMG = gcnew CRMG (this);
				RMG->DllLoad (L"GeneralR.dll");
			}
			catch (const std::exception& exc)
			{
				TBOut->AppendText ("RMG: " + CConvMarsh::Convert (exc.what ()));
				return;
			}
			TBOut->AppendText ("RMG: dll загружена");
		}
	}
	///___________________________________________________________________________

	System::Void FTestCpp::OutMess (System::String^ asMess)
	{
		TBOut->AppendText (asMess);
	}
	///___________________________________________________________________________

	System::Void FTestCpp::BStartStopSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		Superflo->InitDev ();
		Superflo->RunSubscribe (GetTagsSuper());
	}
	///___________________________________________________________________________
	
	System::Collections::ArrayList^ FTestCpp::GetTagsSuper ()
	{
		//System::Collections::ArrayList^ TagList = gcnew System::Collections::ArrayList (4);
		CTags^ TagsContainer = (CTags^)PTagsSuper->Controls[0];
		return TagsContainer->GetTagData (Superflo->DevName);
	}

}