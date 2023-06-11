#include "Student.h"

Student::Student() : Person()
{
	year = 0;
}

Student::Student(string n, int a, int y) : Person(n, a)
{
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
	//cout << "������ ���������� ��� ������ Student: " << this << endl;
}

void Student::Show() {
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "��� �����������: " << year << endl;
}

Student& Student::operator = (const Student& s) {
	if (&s == this)
		return *this;
	name = s.name;
	age = s.age;
	year = s.year;
	return *this;
}

istream& operator >> (istream& in, Student& s)
{
	cout << "\n������� ���: ";
	in >> s.name;
	cout << "������� �������: ";
	in >> s.age;
	cout << "������� ��� �����������: ";
	in >> s.year;
	return in;
}

ostream& operator << (ostream& out, const Student& s)
{
	out << s.name << " | " << s.age << " | " << s.year << endl;
	return out;
}
