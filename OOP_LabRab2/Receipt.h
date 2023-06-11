#pragma once
#include <iostream>
#include <string>
using namespace std;
class Receipt {
private:
	int number;		//номер квитанции
	string date;	//дата
	double sum;		//сумма
public:
	//конструкторы
	Receipt();
	Receipt(int, string, double);
	Receipt(const Receipt&);
	~Receipt();	//деструктор
	//геттеры и сеттеры
	int get_number();
	void set_number(int);
	string get_date();
	void set_date(string);
	double get_sum();
	void set_sum(double);
	//функция для вывода объекта на экран
	void show();
};

