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
	//cout << "Вызван деструктор для класса Employee: " << this << endl;
}

void Employee::Show() {
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Заработная плата: " << salary << endl;
	cout << "Должность: " << position << endl;
}

void Employee::Input() {
	cout << "\nВведите имя: ";
	cin >> name;
	cout << "Введите возраст: ";
	cin >> age;
	cout << "Введите зарплату: ";
	cin >> salary;
	cout << "Введите должность";
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
	cout << "\nВведите имя: ";
	in >> e.name;
	cout << "Введите возраст: ";
	in >> e.age;
	cout << "Введите зарплату: ";
	in >> e.salary;
	cout << "Введите должность";
	in >> e.position;
	return in;
}

ostream& operator << (ostream& out, const Employee& e)
{
	out << e.name << " | " << e.age << " | " << e.salary << " | " << e.position << endl;
	return out;
}
