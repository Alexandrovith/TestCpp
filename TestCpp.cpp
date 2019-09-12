#include "TestCpp.h"
#include "Tags.h"
#include "Typesdef.h"
#include "ManagedConvert.h"
#include "Serialize.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::IO::Ports;

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	FTestCpp::FTestCpp (void)
	{
		InitializeComponent ();

		CBDevType->SelectedIndex = 0;
		ScanComPorts ();
		asPathExe = Path::GetDirectoryName (System::Reflection::Assembly::GetExecutingAssembly ()->Location);// System::IO::Directory::GetCurrentDirectory ();
		PDOutMess = gcnew DOutMess (this, &FTestCpp::OutMess);

		CreateTagsFrame ("Superflo.prmd", PTagsRdSuper, GBWrParam);
		//CreateTagsFrame ("RMG.prmd", PTagsRdRMG, GBWrParamRMG);
		TrWaitInitDrv->Tick += gcnew System::EventHandler (this, &TestCpp::FTestCpp::TrWaitInitDrvOnTick);
	}
	///___________________________________________________________________________

	void FTestCpp::ScanComPorts ()
	{
		SerialPort^ Port = gcnew SerialPort ();
		CBComPort->Items->Clear ();
		CBComPort->Items->AddRange (Port->GetPortNames ());
		CBComPort->SelectedIndex = CBComPort->FindString ("COM13");
		if (CBComPort->SelectedIndex == -1)
			CBComPort->SelectedIndex = 0;
	}
	///___________________________________________________________________________
	// Размещение панели вывода/настройки параметров в заданном контроле
	System::Void FTestCpp::CreateTagsFrame (const System::String^ asFilePrmd, System::Windows::Forms::Control^ ParentRd, Control^ ParentWr)
	{
		CTags^ TgsRd = TagFrameNew (ParentRd);
		CTags^ TgsRw = TagFrameNew (ParentWr);
		CSerialize::ReadFl (asPathExe + "\\" + (String^)asFilePrmd, TgsRd->PShowParams, TgsRw->PShowParams, PDOutMess);
	}
	///___________________________________________________________________________

	CTags^ FTestCpp::TagFrameNew (System::Windows::Forms::Control^ Parent)
	{
		CTags^ Tags = gcnew CTags ();
		Tags->Parent = Parent;
		Tags->Dock = System::Windows::Forms::DockStyle::Fill;
		Tags->Show ();
		return Tags;
	}
	///___________________________________________________________________________
	// Загрузка dll Superflo
	System::Void FTestCpp::BLoadDllSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (SuperfloWork == nullptr)
		{
			DNewDev^ NewSuper = gcnew DNewDev (this, &FTestCpp::DllLoadSuper);
			SuperfloWork = gcnew CWorkOfDevs (PDOutMess, (CTags^)PTagsRdSuper->Controls[0]);
			DRButBlink^ Blink = gcnew DRButBlink (this, &FTestCpp::RButBlink);
			if (SuperfloWork->Init (NewSuper, (const LPCWSTR)CSuperflo::cpwDllname, Blink) == false)
			{
				SuperfloWork = nullptr;
				return;
			}
			SetIntervalTimerSuper += gcnew DSetIntervalTimer (SuperfloWork, &CWorkOfDevs::SetIntervalTimer);
			NumericUpDown1_ValueChanged (nullptr, nullptr);
			BStartStopSuper->Enabled = true;
		}
	}
	///___________________________________________________________________________

	void FTestCpp::RButBlink ()
	{
		RBRrequest->Checked = !RBRrequest->Checked;
	}
	///___________________________________________________________________________

	void FTestCpp::RButBlinkRMG ()
	{
		RBRrequestRMG->Checked = !RBRrequestRMG->Checked;
	}
	///___________________________________________________________________________

	CDevice^ FTestCpp::DllLoadSuper ()
	{
		return gcnew CSuperflo (PDOutMess);
	}
	///___________________________________________________________________________

	CDevice^ FTestCpp::DllLoadRMG ()
	{
		return gcnew CRMG (PDOutMess);
	}
	///___________________________________________________________________________

	System::Void FTestCpp::BLoadDll_Click (System::Object^ sender, System::EventArgs^ e)
	{
		RMGwork->StartStop (sender, nullptr, nullptr);
	}
	///___________________________________________________________________________

	System::Void FTestCpp::OutMess (System::String^ asMess)
	{
		DateTime DT = DateTime::Now;
		TBOut->AppendText (String::Format ("{1:00}.{2:00}.{3:00}.{4:000} {5}{0}",
			Environment::NewLine, DT.Hour, DT.Minute, DT.Second, DT.Millisecond, asMess));
	}
	///___________________________________________________________________________

	System::Void FTestCpp::BStartStopSuper_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (SuperfloWork->StartStop (sender, CBDevType->Text, CBComPort->Text) == CWorkOfDevs::EDrv::Work)
		{
			rWaitSuper_RMG = LWaitSuper;
			TrWaitInitDrv->Start ();
			iCountWait = 0;
			CBDevType->Enabled = false;
		}
		else CBDevType->Enabled = true;
	}
	///___________________________________________________________________________

	System::Void FTestCpp::NumericUpDown1_ValueChanged (System::Object^ sender, System::EventArgs^ e)
	{
		SetIntervalTimerSuper (static_cast<int> (NUDIntervalReqSuper->Value));
	}
	///___________________________________________________________________________

	System::Void FTestCpp::NUDIntervalReqRMG_ValueChanged (System::Object^ sender, System::EventArgs^ e)
	{
		SetIntervalTimerRMG (static_cast<int> (NUDIntervalReqRMG->Value));
	}
	///___________________________________________________________________________

	System::Void FTestCpp::BLoadDllRMG_Click (System::Object^ sender, System::EventArgs^ e)
	{
		if (RMGwork == nullptr)
		{
			DNewDev^ NewRMG = gcnew DNewDev (this, &FTestCpp::DllLoadRMG);
			RMGwork = gcnew CWorkOfDevs (PDOutMess, (CTags^)PTagsRdSuper->Controls[0]);
			DRButBlink^ BlinkRMG = gcnew DRButBlink (this, &FTestCpp::RButBlinkRMG);
			if (RMGwork->Init (NewRMG, CRMG::cpwDllname, BlinkRMG) == false)
			{
				RMGwork = nullptr;
				return;
			}
			SetIntervalTimerRMG += gcnew DSetIntervalTimer (SuperfloWork, &CWorkOfDevs::SetIntervalTimer);
			NUDIntervalReqRMG_ValueChanged (nullptr, nullptr);
			BStartStopRMG->Enabled = true;
		}
	}
	///___________________________________________________________________________

	const int DELAY_RD_PARAMS = 30;

	void TestCpp::FTestCpp::TrWaitInitDrvOnTick (System::Object^ sender, System::EventArgs^ e)
	{
		if (iCountWait < DELAY_RD_PARAMS)
			rWaitSuper_RMG->Text = Convert::ToString (iCountWait++);
		else
		{
			TrWaitInitDrv->Stop ();
		}
	}
}

