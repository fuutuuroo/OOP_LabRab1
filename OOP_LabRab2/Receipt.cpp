#include "Receipt.h"

Receipt::Receipt()
{
	number = 0;
	date = "";
	sum = 0.0;
}

Receipt::Receipt(int n, string d, double s)
{
	number = n;
	date = d;
	sum = s;
}

Receipt::Receipt(const Receipt& r)
{
	number = r.number;
	date = r.date;
	sum = r.sum;
}

Receipt::~Receipt()
{
	cout << "Вызов деструктора для " << this << endl;
}

int Receipt::get_number()
{
	return number;
}

void Receipt::set_number(int n)
{
	number = n;
}

string Receipt::get_date()
{
	return date;
}

void Receipt::set_date(string d)
{
	date = d;
}

double Receipt::get_sum()
{
	return sum;
}

void Receipt::set_sum(double s)
{
	sum = s;
}

void Receipt::show()
{
	cout << "Номер квитанции: " << number << endl;
	cout << "Дата: " << date << endl;
	cout << "Сумма: " << sum << endl;
}
