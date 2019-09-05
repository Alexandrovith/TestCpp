///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///~~~~~~~~~	Проект:			Тест драйверов на С++
///~~~~~~~~~	Прибор:			Все приборы
///~~~~~~~~~	Модуль:			Подключение dll
///~~~~~~~~~	Разработка:	Демешкевич С.А.
///~~~~~~~~~	Дата:				xx.xx.2019

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#pragma once
#include <Windows.h>

class CLoadDLL
{
	HINSTANCE hDLL;

public:
	typedef void (CALLBACK* DInitConfig)(char*);
	typedef int (CALLBACK* DSubscribe)(int, char*);
	typedef int (CALLBACK* DWriteValue)(char* address, char* value, int size);
	typedef void (CALLBACK* DClose)();
	typedef void (CALLBACK* DStopStartDev)(char*, bool);
	typedef void (CALLBACK* DZipByCppLog)();
	typedef int (CALLBACK* DGetValue)(int tagId, UCHAR*);

	CLoadDLL (LPCWSTR lpLibFileName);
	~CLoadDLL ();
	void* Load (LPCSTR FuncName);
	void Close ();
};

extern volatile CLoadDLL::DInitConfig InitConfig;
extern volatile CLoadDLL::DSubscribe Subscribe;
extern volatile CLoadDLL::DWriteValue WriteValue;
extern volatile CLoadDLL::DClose Close;
extern volatile CLoadDLL::DStopStartDev StopStartDev;
extern volatile CLoadDLL::DGetValue GetValue;

