#include "Device.h"
#include "LoadDLL.h"

#include <variant>
#include <iostream>
#include <utility>
#include <cassert>
#include <filesystem>
#include <ManagedConvert.h>
#include <msclr/marshal.h>

using namespace System;

namespace TestCpp
{
	//wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

	CDevice::CDevice (DOutMess^ OutMess)
	{
		this->OutMess = OutMess;
	}
	//_____________________________________________________________________________

	void CDevice::DllLoad (const LPCWSTR cpDll)
	{
		LoadDLL = new CLoadDLL (cpDll);		// std::shared_ptr<CLoadDLL> LoadDLL (new CLoadDLL (cpDll));

		DInitDll InitDll = (DInitDll)LoadDLL->Load ("InitDll");
		if (InitDll == nullptr)
			throw gcnew Exception ("Error DllLoad");
		InitDll ();

		if (LoadFuncFromExtDll (LoadDLL) == 1)
			throw gcnew Exception ("Error load func dll");
	}
	//_____________________________________________________________________________
	//char*caI = "{\"Devices\":[{\"Name\":\"DevSF\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM13\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ-3À ÒÝÖ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":2,\"BaudRate\":1200,\"Port\":\"COM11\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ-1À\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM12\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ñò.Ñåëî\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM13\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"28112018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ðå÷èöà\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM14\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Êàëèíêîâè÷è\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM17\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Õîéíèêè\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM15\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Äîáðóø\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM18\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"03122018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ñò.Ðóäíÿ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM19\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"25102018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Òóðñê\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM20\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ìèêàøåâè÷è\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM21\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"05102018\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Òåðåõîâêà\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM22\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Êðóïåö\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM23\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Çÿáðîâêà\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM24\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Æèòêîâè÷è\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM25\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"18112018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Åëüñê\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM33\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"31102018\",\"TA\":\"19112018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ïåòðèêîâ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM26\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"06122018\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Êîðìà\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM27\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"06122018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ ×å÷åðñê\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM28\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"26112018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ëåëü÷èöû\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM29\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ñâåòèëîâè÷è\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM30\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Íàðîâëÿ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM31\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Óâàðîâè÷è\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM34\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ìîçûðü\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM37\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"17082018\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Á.Êîøåëåâî\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM35\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Áóäèùå\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM38\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Ëîåâ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM36\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"02032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ Áðàãèí\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM16\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"02032019\",\"FlowCtrl\":0},{\"Name\":\"SF ÃÐÑ-2À\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM39\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"17032019\",\"TA\":\"02032019\",\"FlowCtrl\":0}]}";

	int CDevice::LoadFuncFromExtDll (CLoadDLL* LoadDLL)
	{
		InitConfig = (CLoadDLL::DInitConfig)LoadDLL->Load ("InitConfig");
		if (InitConfig == nullptr)
			return 1;
		//InitConfig (caI);
		Subscribe = (CLoadDLL::DSubscribe)LoadDLL->Load ("Subscribe");
		if (Subscribe == nullptr)
			return 1;
		WriteValue = (CLoadDLL::DWriteValue)LoadDLL->Load ("WriteValue");
		if (WriteValue == nullptr)
			return 1;
		Close = (CLoadDLL::DClose)LoadDLL->Load ("Close");
		if (Close == nullptr)
			return 1;
		StopStartDev = (CLoadDLL::DStopStartDev)LoadDLL->Load ("StopStartDev");
		if (StopStartDev == nullptr)
			return 1;
		GetValue = (CLoadDLL::DGetValue)LoadDLL->Load ("GetValue");
		if (GetValue == nullptr)
			return 1;

		return 0;
	}
	//_____________________________________________________________________________

	int CDevice::RunSubscribe (System::Collections::ArrayList^ TagList)
	{
		int iTagId = 0;
		try
		{
			for each (String ^ tag in TagList)
			{
				Subscribe (iTagId++, (char*)CConvMarsh::Convert (tag).c_str ());
			}
		}
		catch (const std::exception& exc)
		{			
			//OutMess (msclr::interop::marshal_as<System::String^> (exc.what ()));
			OutMess (CConvMarsh::Convert (exc.what ()));
		}
		return 0;
	}
	//_____________________________________________________________________________
}