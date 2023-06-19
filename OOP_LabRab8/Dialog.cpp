#include "Dialog.h"
#include "Event.h"
#include "Vector.h"
#include <iostream>
using namespace std;

Dialog::Dialog() : Vector()
{
	EndState = 0;
}

Dialog::~Dialog() {}
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq "; 
	string s;
	string param;
	char code;
	cout << "Введите команду > ";
	cin >> s;
	code = s[0]; 
	if (OpInt.find(code) >= 0) { 
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break; 
		case '+': event.command = cmAdd; break; 
		case '-': event.command = cmDel; break; 
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGetName; break;
		case 'q': event.command = cmQuit; break; 
		}
		//Выделяем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str()); //Преобразуем параметр в число
			event.a = A; //Записываем в сообщение
		}
	}
	else event.what = evNothing; //Пустое событие
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //получить событие 
		HandleEvent(event); //обработать событие
	} while (!Valid());
	return EndState;
}
bool Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else
		return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing; //пустое событие
}
void Dialog::EndExec()
{
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake: //создание группы 
			size = event.a; //размер группы
			beg = new Object * [size]; //выделяем память под массив указателей 
			cur = 0; //текущая позиция
			ClearEvent(event); //очищаем событие 
			break;
		case cmAdd: //добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del(); //удаление 
			ClearEvent(event);
			break;
		case cmShow:
			Show(); //просмотр 
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec(); //выход 
			ClearEvent(event);
			break;
		default: Vector::HandleEvent(event);
		}
	}
}