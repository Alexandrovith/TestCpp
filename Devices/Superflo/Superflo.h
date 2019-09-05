#pragma once

#include <Windows.h>
#include "Device.h"
#include "Typesdef.h"

namespace TestCpp
{
	ref class CSuperflo : public CDevice
	{
	public: static const LPCWSTR cpwDllname = L"UsefullF.dll";
	public: static const System::String^ asDllname = "UsefullF.dll";

	public:
		CSuperflo (DOutMess^ OutMess);

		virtual int Write (std::string cpAddr, BYTE* baVal, int iLenPar) override;
		virtual int GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal) override;
		virtual int InitDev (System::String^ asDevType, System::String^ asPort) override;

	protected: 	void RdDevName ();
	};

}