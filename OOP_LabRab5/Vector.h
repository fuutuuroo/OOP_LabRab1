#pragma once
#include "Object.h"

class Vector {
public:
	Vector(void);//конструктор без параметров 
	Vector(int);//конструктор копирования
	~Vector(void);//деструктор
	void add(Object*);//добавление элемента в вектор
	friend ostream& operator<<(ostream& out, const Vector&);//операция вывода 
private:
	Object** begin;//указатель на первый элемент вектора 
	int size;//размер
	int cur;//текущая позиция
};
