#pragma once

#include <vector>

#include "Device.h"
#include "Typesdef.h"

using namespace System;

namespace TestCpp
{
	public ref class CSuperflo : public CDevice
	{
	private: String^ asDevName;
	public: property String^ DevName
	{
		String^ get () { return asDevName; }
	}
					//.............................................................................

	public:
		CSuperflo (DOutMess^ OutMess/*, cli::array<System::String^, 2> ^ Tags, const LPCWSTR cpDll*/);

		virtual int Write (String^ cpAddr, cli::array<System::Byte, 1> ^ cpVal) override;
		virtual int GetVal (int iTagId, cli::array<System::Byte, 1> ^ baVal) override;
		virtual int InitDev () override;
	protected: 	void RdDevName ();
	};

}