#include "Student.h"

Student::Student()
{
	name = "";
	age = 0;
	year = 0;
}

Student::Student(string n, int a, int y)
{
	name = n;
	age = a;
	year = y;
}

Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	year = s.year;
}

Student::~Student()
{
	//cout << "Вызван деструктор для класса Student: " << this << endl;
}

istream& operator >> (istream& in, Student& s)
{
	cout << "\nВведите имя: ";
	in >> s.name;
	cout << "Введите возраст: ";
	in >> s.age;
	cout << "Введите год поступления: ";
	in >> s.year;
	return in;
}

ostream& operator << (ostream& out, const Student& s)
{
	out << s.name << " | " << s.age << " | " << s.year << endl;
	return out;
}
