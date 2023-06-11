#pragma once
#include <iostream>
using namespace std;

struct PhoneCost {
	int first;		//продолжительность телефонного разговора в минутах
	double second;	//стоимость одной минуты разговора в рублях
	void Init(int f, double s);
	void Read();
	void Show();
	double cost();
};
