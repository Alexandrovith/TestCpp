#include <Windows.h>
#include <memory>

#include "ManagedConvert.h"
#include "WorkOfDevs.h"

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CWorkOfDevs::CWorkOfDevs (DNewDev^ NewDev, LPCWSTR cpDllName, DOutMess^ OutMess, CTags^ TagsContainer)
	{
		this->OutMess = OutMess;
		this->TagsContainer = TagsContainer;
		TrReadDrv->Tick += gcnew System::EventHandler (this, &TestCpp::CWorkOfDevs::TrRdVals_OnTick);

		if (Device == nullptr)
		{
			try
			{
				Device = NewDev ();
				Device->DllLoad (cpDllName);
			}
			catch (const std::exception& exc)
			{
				OutMess (Device->DevName + ": " + CConvMarsh::Convert (exc.what ()));
				return;
			}
			OutMess (Device->DevName + ": dll загружена");
		}
	}
	//___________________________________________________________________________

	CWorkOfDevs::EDrv CWorkOfDevs::StartStop (System::Object^ sender, System::String^ asDevType, System::String^ asPort)
	{
		System::Windows::Forms::Button^ B = dynamic_cast<System::Windows::Forms::Button^>(sender);
		if (B == nullptr)
			return EDrv::Stopped;

		if (B->Text == "Старт")
		{
			Device->InitDev (asDevType, asPort);
			System::String^ asDevMess = "[" + Device->DevName + "] ";
			OutMess (asDevMess + "InitDev");
			System::Collections::Hashtable^ Tags = GetTags ();
			if (Tags->Count > 0)
			{
				Device->RunSubscribe (Tags);
				OutMess (asDevMess + "Subscribe");
				TrReadDrv->Start ();
				B->Text = "Стоп";
				return EDrv::Work;
			}
			else
			{
				CloseDrv (asDevMess);
			}
		}
		else
		{
			TrReadDrv->Stop ();
			B->Text = "Старт";
			CloseDrv ("[" + Device->DevName + "] ");
		}
		return EDrv::Stopped;
	}
	///___________________________________________________________________________

	void CWorkOfDevs::CloseDrv (System::String^ asDevMess)
	{
		OutMess ("Не заданы теги для чтения. Остановка драйвера ...");
		Device->CloseDev ();
		OutMess (asDevMess + "Драйвер остановлен");
	}
	///___________________________________________________________________________

	System::Collections::Hashtable^ CWorkOfDevs::GetTags ()
	{
		Tags = TagsContainer->GetRdData (Device->DevName);
		return Tags;
	}
	///___________________________________________________________________________

	void CWorkOfDevs::SetIntervalTimer (int iInterval)
	{
		TrReadDrv->Interval = iInterval;
	}
	///___________________________________________________________________________

	union UToFl
	{
		int32_t iVal;
		float fVal;
		char ucaVal[64];
	};
	void TestCpp::CWorkOfDevs::TrRdVals_OnTick (System::Object^ sender, System::EventArgs^ e)
	{
		//UCHAR ucaVal[64];
		UToFl ToFl;
		for each (System::Collections::DictionaryEntry item in Tags)
		{
			int iId = (int)item.Key;
			int iLen = GetValue (iId, (UCHAR*)ToFl.ucaVal);
			if (iLen == 0)
				return;
			System::String^ asType = TagsContainer->GetType (iId);
			System::String^ asRet;
			//strncpy_s (ToFl.ucaVal, iLen, (char*)ucaVal, iLen);
			if (asType == "byte")
			{
				asRet = Convert::ToString (ToFl.ucaVal[0]);
			}
			else if (asType == "int")
			{
				asRet = Convert::ToString (ToFl.iVal);
			}
			else if (asType == "float")
			{
				asRet = Convert::ToString (ToFl.fVal);
			}
			else if (asType == "string")
			{
				asRet = Convert::ToString (ToFl.ucaVal);
			}
			TagsContainer->OutVal (iId, asRet);
		}
	}
	///___________________________________________________________________________
	
	void CWorkOfDevs::Write (CTags^ TagsForWr)
	{
		// Get ох params 
		ArrayList^ DataForWr = TagsForWr->GetWrData (Device->DevName);

		for each (CDataForWr^ item in DataForWr)
		{
			size_t uiSizeData = 256;
			BYTE* btpVal;
			try
			{
				std::string csVal = CConvMarsh::Convert(item->asData);
				float fVal; int iVal; BYTE btVal;

				cli::array<BYTE>^ Val;
				if (item->asType == "float")
				{
					uiSizeData = sizeof (float);
					fVal = std::stof (csVal);					//Val = BitConverter::GetBytes (Convert::ToSingle (item->asData));
					btpVal = (BYTE*)&fVal;
				}
				else if (item->asType == "byte")
				{
					uiSizeData = 1;
					//std::static_pointer_cast<BYTE>(	//Val = BitConverter::GetBytes (Convert::ToByte (item->asData));
					btVal = std::stoi (csVal);
					btpVal = (BYTE*)&btVal;
				}
				else if (item->asType == "int")
				{
					uiSizeData = 4;
					btVal = std::stoi (csVal);
					btpVal = (BYTE*)&iVal; //Val = BitConverter::GetBytes (Convert::ToInt32 (item->asData));
				}
				//else if (asTypeData == "string")
				//{
				//	uiSizeData = 256;
				//}
				else
				{
					OutMess (String::Format ("[{0}]) неизвестный тип параметра [{1}]", Device->DevName, item->asType));
					continue;
				}

				//std::unique_ptr<BYTE[]> btVal (new BYTE[uiSizeData]);
				//for (size_t i = 0; i < uiSizeData; i++)
				//{
				//	btVal[i++] = (int)Val[i];
				//}
				int iRet = Device->Write (CConvMarsh::Convert (item->asTag), btpVal, uiSizeData);//btVal.get ()
				OutMess (String::Format ("[{0}] Запись {1} в [{2}]", Device->DevName, item->asData, item->asTag));
			}
			catch (System::Exception ^exc)
			{
				OutMess (String::Format ("[{0}] ERR: {1}", Device->DevName, exc->Message));
			}
			catch (const std::exception& exc)
			{
				OutMess (String::Format ("[{0}] ERR: {1}", Device->DevName, CConvMarsh::Convert((char*)exc.what ())));
			}
		}
	}
	///___________________________________________________________________________

	void CWorkOfDevs::Exit ()
	{
		if (Device == nullptr)
		{
			Device->CloseDev ();
		}
	}
}
