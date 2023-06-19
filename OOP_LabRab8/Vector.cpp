#include "Vector.h"
#include "Employee.h"
#include "Event.h"
#include <iostream>
using namespace std;

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}

void Vector::Add()
{
	Object* p;	
	cout << "1. Человек" << endl;
	cout << "2. Сотрудник" << endl;
	int y;
	cin >> y;
	if (y == 1) {
		Person* a = new Person;
		a->Input(); 
		p = a;
		if (cur < size) {
			beg[cur] = p; 
			cur++;
		}
	}
	else {
		if (y == 2) { 
			Employee* b = new Employee;
			b->Input();
			p = b;
			if (cur < size) {
				beg[cur] = p;
				cur++;
			}
		}
		else
			return;
	}
}

void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}
void Vector::Show()
{
	if (cur == 0)
		cout << "Вектор пустой" << endl;
	Object** p = beg; 
	for (int i = 0; i < cur; i++) {
		(*p)->Show(); 
		p++; 
	}
}

int Vector::operator () ()
{
	return size;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e); 
			p++; 
		}
		switch (e.command)
		{
		case cmGetName:
			int k;
			cin >> k;
			beg[k - 1]->Show();
			break;
		}
	}
	
}
