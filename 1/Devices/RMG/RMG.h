#pragma once

#include "Device.h"
#include "Typesdef.h"

namespace TestCpp
{
	ref class CRMG : public CDevice
	{
		//.............................................................................

	public:
		CRMG (DOutMess^ OutMess);	//CRMG (FTestCppDrv^ Class);

		virtual int Write (String^ cpAddr, cli::array<System::Byte, 1> ^ baVal) override;
		virtual int GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal) override;
		virtual int InitDev () override;
		//virtual int RunSubscribe (cli::array<System::String^, 2> ^ CTags) override;

	};
}
