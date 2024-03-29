#pragma once

#include "Device.h"
#include "Typesdef.h"
#include "Tags.h"

namespace TestCpp
{
	ref class CWorkOfDevs
	{
	public: enum class EDrv	{	Work, Stopped	};


	protected: CDevice^ Device;
	protected: DOutMess^ OutMess;
						 CTags^ TagsContainer;
	protected: System::Windows::Forms::Timer^ TrReadDrv = gcnew System::Windows::Forms::Timer ();
	protected: System::Collections::Hashtable^ Tags;
	protected: DRButBlink^ RButBlink;

	///___________________________________________________________________________
	// Загрузка dll Superflo
	public: CWorkOfDevs (DOutMess^ OutMess, CTags^ TagsContainer);
					bool Init (DNewDev^ NewDev, const LPCWSTR cpDllName, DRButBlink^ RButBlink);
					EDrv StartStop (System::Object^ sender, System::String^ asDevType, System::String^ asPort);
					void CloseDrv (System::String^ asDevMess);
	public: void SetIntervalTimer (int iInterval);
	public: void Exit ();
	public: void Write (CTags^ TagsForWr);

	private: System::Collections::Hashtable^ CWorkOfDevs::GetTags ();
					 void TrRdVals_OnTick (System::Object^ sender, System::EventArgs^ e);
	};
}
