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
	//cout << "������ ���������� ��� ������ Person: " << this << endl;
}

void Person::Show() {
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
}

void Person::Input() {
	cout << "\n������� ���: ";
	cin >> name;
	cout << "������� �������: ";
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
	cout << "\n������� ���: ";
	in >> p.name;
	cout << "������� �������: ";
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
	if (e.what == evMessage) //�������-���������
	{
		switch (e.command)
		{
		case cmGet:
			cout << "���: " << get_name() << endl;
			break;
		}
	}
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!