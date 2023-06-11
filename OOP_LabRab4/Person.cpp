#include "Person.h"

Person::Person()
{
	name = "";
	age = 0;
}

Person::Person(string n, int a)
{
	name = n;
	age = a;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

Person::~Person()
{
	//cout << "Вызван деструктор для класса Person: " << this << endl;
}

istream& operator >> (istream& in, Person& p)
{
	cout << "\nВведите имя: ";
	in >> p.name;
	cout << "Введите возраст: ";
	in >> p.age;
	return in;
}

ostream& operator << (ostream& out, const Person& p)
{
	out << p.name << " | " << p.age << endl;
	return out;
}
