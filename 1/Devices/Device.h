#pragma once

#include "Typesdef.h"
#include "LoadDll.h"
#include <memory>

using namespace System;

namespace TestCpp
{
	public ref class CDevice
	{
	private: CLoadDLL* LoadDLL;
	public:
		CDevice (DOutMess^ OutMess/*, cli::array<System::String^, 2> ^ Tags, System::String^ asMessError*/);
		~CDevice ()
		{
			delete LoadDLL;
		}
		virtual int Write (String^ cpAddr, cli::array<Byte, 1> ^ cpVal) = 0;
		virtual int GetVal (int iTagId, cli::array<Byte, 1> ^ baVal) = 0;
		virtual int InitDev () = 0;
		virtual int RunSubscribe (System::Collections::ArrayList^ TagList);
		
	private: int LoadFuncFromExtDll (CLoadDLL* LoadDLL);

	//public: property LPCWSTR DllName
	//	{
	//		LPCWSTR get () { return cpDll; }
	//	}
	protected: DOutMess^ OutMess;
	public: void DllLoad (const LPCWSTR cpDll/*cli::array<System::String^, 2> ^ CTags, System::String^ asMessError*/);
	};

}