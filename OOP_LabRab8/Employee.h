#pragma once
#include "Person.h"

class Employee : public Person {
protected:
	float salary;
	string position;
public:
	Employee();
	Employee(string, int, float, string);
	Employee(const Employee&);
	~Employee();
	//методы класса
	float get_salary() { return salary; }
	void set_salary(float s) { salary = s; }
	string get_position() { return position; }
	void set_position(string p) { position = p; }
	void Show();
	void Input();
	Employee& operator = (const Employee&);
	//перегрузка операций ввода и вывода
	friend istream& operator >> (istream& in, Employee& s);
	friend ostream& operator << (ostream& out, const Employee& s);
};