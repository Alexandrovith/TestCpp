///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///~~~~~~~~~	Проект:			Тест драйверов на С++
///~~~~~~~~~	Прибор:			Все приборы
///~~~~~~~~~	Модуль:			Подключение dll
///~~~~~~~~~	Разработка:	Демешкевич С.А.
///~~~~~~~~~	Дата:				xx.xx.2019

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include "LoadDLL.h"

volatile CLoadDLL::DInitConfig InitConfig;
volatile CLoadDLL::DSubscribe Subscribe;
volatile CLoadDLL::DWriteValue WriteValue;
volatile CLoadDLL::DClose Close;
volatile CLoadDLL::DStopStartDev StopStartDev;
volatile CLoadDLL::DGetValue GetValue;

CLoadDLL::CLoadDLL (LPCWSTR lpLibFileName)
{
	hDLL = LoadLibrary (lpLibFileName);
}
//_____________________________________________________________________________

CLoadDLL::~CLoadDLL ()
{
	Free ();
}
//_____________________________________________________________________________

void* CLoadDLL::Load (LPCSTR FuncName)
{              // Handle to DLL  
	void* lpfnDllFunc = nullptr;    // Function pointer  
	if (hDLL != nullptr)
	{
		lpfnDllFunc = GetProcAddress (hDLL, FuncName);
		if (!lpfnDllFunc)
		{
			Close ();
			return nullptr;
		}
	}
	return lpfnDllFunc;
}
//_____________________________________________________________________________
//char*caI = "{\"Devices\":[{\"Name\":\"DevSF\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM13\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС-3А ТЭЦ\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":2,\"BaudRate\":1200,\"Port\":\"COM11\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС-1А\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM12\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Ст.Село\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM13\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"28112018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Речица\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM14\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Калинковичи\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM17\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Хойники\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM15\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Добруш\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM18\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"03122018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Ст.Рудня\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM19\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"25102018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Турск\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM20\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Микашевичи\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM21\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"05102018\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Тереховка\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM22\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Крупец\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM23\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Зябровка\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM24\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Житковичи\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM25\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"18112018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Ельск\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM33\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"31102018\",\"TA\":\"19112018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Петриков\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM26\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"06122018\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Корма\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM27\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"06122018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Чечерск\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM28\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"26112018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Лельчицы\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM29\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Светиловичи\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM30\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Наровля\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM31\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Уваровичи\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM34\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Мозырь\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM37\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"17082018\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Б.Кошелево\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM35\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"01032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Будище\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM38\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"01012000\",\"TH\":\"18032019\",\"TI\":\"01012000\",\"TA\":\"01012000\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Лоев\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM36\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"02032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС Брагин\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM16\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"15032019\",\"TA\":\"02032019\",\"FlowCtrl\":0},{\"Name\":\"SF ГРС-2А\",\"Type\":\"SF21RU6D\",\"Password\":\"123\",\"Address\":1,\"BaudRate\":1200,\"Port\":\"COM39\",\"DataBits\":8,\"Parity\":0,\"StopBit\":1,\"TD\":\"17032019\",\"TH\":\"18032019\",\"TI\":\"17032019\",\"TA\":\"02032019\",\"FlowCtrl\":0}]}";

int CLoadDLL::LoadFuncFromExtDll (/*CLoadDLL* LoadDLL*/)
{
	InitConfig = (DInitConfig)Load ("InitConfig");
	if (InitConfig == nullptr)
		return 1;
	//InitConfig (caI);
	Subscribe = (DSubscribe)Load ("Subscribe");
	if (Subscribe == nullptr)
		return 1;
	WriteValue = (DWriteValue)Load ("WriteValue");
	if (WriteValue == nullptr)
		return 1;
	Close = (DClose)Load ("Close");
	if (Close == nullptr)
		return 1;
	StopStartDev = (DStopStartDev)Load ("StopStartDev");
	if (StopStartDev == nullptr)
		return 1;
	GetValue = (DGetValue)Load ("GetValue");
	if (GetValue == nullptr)
		return 1;

	return 0;
}
//_____________________________________________________________________________

void CLoadDLL::Free ()
{
	if (hDLL != nullptr)
	{
		FreeLibrary (hDLL);
		hDLL = nullptr;
	}
}
