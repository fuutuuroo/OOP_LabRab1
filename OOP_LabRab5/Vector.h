#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Vector {
private:
	Object** begin;		//указатель на первый элемент вектора 
	int size;			//размер
	int cur;			//текущая позиция
public:
	Vector();													//конструктор без параметров 
	Vector(int);												//конструктор c параметрами
	~Vector();													//деструктор
	void Add(Object*);											//добавление элемента в вектор
	friend ostream& operator << (ostream& out, const Vector&);	//операция вывода 
};
