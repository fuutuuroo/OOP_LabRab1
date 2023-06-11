#pragma once
#include "Person.h"

class Student : public Person {
protected:
	int year;
public:
	Student();
	Student(string, int, int);
	Student(const Student&);
	~Student();
	//методы класса
	int get_year() { return year; }
	void set_year(int y) { year = y; }
	void add_year(int y) { year += y; }
	void Show();
	Student& operator = (const Student&);
	//перегрузка операций ввода и вывода
	friend istream& operator >> (istream& in, Student& s);
	friend ostream& operator << (ostream& out, const Student& s);
};