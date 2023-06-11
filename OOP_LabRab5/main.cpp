#include "Vector.h" 
#include "Object.h"
#include "Student.h"
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	Vector v(5);								//создание вектора
	Person p1;									//создание и заполнение объекта класса Person
	cin >> p1;
	Student s1("Melissa", 22, 2008);			//создание и заполнение объекта класса Student
	Object* ptr = &p1;							//установка указателя на объект класса Person 
	v.Add(ptr);									//добавление объекта в вектор	
	ptr = &s1;									//установка указателя на объект класса Student 
	v.Add(ptr);									//добавление объекта в вектор		
	cout << endl << "----------" << endl << v;	//вывод вектора на экран

	return 0;
}