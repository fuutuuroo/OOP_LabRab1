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

void Person::Show() {
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
}

void Person::Input() {
	cout << "\nВведите имя: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
}

Person& Person::operator = (const Person& p) {
	if (&p == this)
		return *this;
	name = p.name;
	age = p.age;
	return *this;
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

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage) //Событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Имя: " << get_name() << endl;
			break;
		}
	}
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!