#pragma once

#include <Windows.h>

#include "Device.h"
#include "Typesdef.h"

namespace TestCpp
{
	ref class CRMG : public CDevice
	{
	public: static const LPCWSTR cpwDllname = L"GeneralR.dll";

		//.............................................................................

	public:
		CRMG (DOutMess^ OutMess);

		virtual int Write (std::string cpAddr, BYTE* baVal, int iLenPar) override;
		virtual int GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal) override;
		virtual int InitDev (System::String^ asDevType, System::String^ asPort) override;

	};
}
