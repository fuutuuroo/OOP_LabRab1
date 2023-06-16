#include "Employee.h"

Employee::Employee() : Person()
{
	salary = 0;
	position = "";
}

Employee::Employee(string n, int a, float s, string p) : Person(n, a)
{
	salary = s;
	position = p;
}

Employee::Employee(const Employee& e)
{
	name = e.name;
	age = e.age;
	salary = e.salary;
	position = e.position;
}

Employee::~Employee()
{
	//cout << "������ ���������� ��� ������ Employee: " << this << endl;
}

void Employee::Show() {
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "���������� �����: " << salary << endl;
	cout << "���������: " << position << endl;
}

void Employee::Input() {
	cout << "\n������� ���: ";
	cin >> name;
	cout << "������� �������: ";
	cin >> age;
	cout << "������� ��������: ";
	cin >> salary;
	cout << "������� ���������";
	cin >> position;
}

Employee& Employee::operator = (const Employee& e) {
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	salary = e.salary;
	position = e.position;
	return *this;
}

istream& operator >> (istream& in, Employee& e)
{
	cout << "\n������� ���: ";
	in >> e.name;
	cout << "������� �������: ";
	in >> e.age;
	cout << "������� ��������: ";
	in >> e.salary;
	cout << "������� ���������";
	in >> e.position;
	return in;
}

ostream& operator << (ostream& out, const Employee& e)
{
	out << e.name << " | " << e.age << " | " << e.salary << " | " << e.position << endl;
	return out;
}
