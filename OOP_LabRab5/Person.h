#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	~Person();

	string get_name() { return name; }
	void set_name(string n) { name = n; }
	int get_age() { return age; }
	void set_age(int a) { age = a; }
	void Show();
	Person& operator = (const Person&);
	friend istream& operator >> (istream& in, Person& p);
	friend ostream& operator << (ostream& out, const Person& p);
};


