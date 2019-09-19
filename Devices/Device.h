#pragma once

#include <string>

#include "LoadDll.h"
#include "Typesdef.h"

namespace TestCpp
{
	typedef void (CALLBACK* DInitDll)();

	ref class CDevice
	{
	protected: System::String^ asDevName;
	public: property System::String^ DevName
	{
		System::String^ get () { return asDevName; }
	}
	private: CLoadDLL* LoadDLL;
					 System::String^ asDevType;
					// devType не инициализируется - нет реализации 
	public: property System::String^ devType { System::String^ get () { return asDevType; }}

	public:
		CDevice (DOutMess^ OutMess);
		~CDevice ()
		{
			delete LoadDLL;
		}
		virtual int Write (std::string cpAddr, BYTE* baVal, int iLenPar) = 0;
		virtual int GetVal (int iTagId, cli::array<Byte, 1> ^ baVal) = 0;
		virtual int InitDev (System::String^ asDevType, System::String^ asPort) = 0;
		virtual int RunSubscribe (System::Collections::Hashtable^ TagList);
		virtual void CloseDev ();
		virtual void StopStartDevice (char* cpDevConfig, bool bStop);
		
	protected: DOutMess^ OutMess;
	public: void DllLoad (const LPCWSTR cpDll);
	};

	public delegate CDevice^ DNewDev ();
	public delegate void DRButBlink ();

}