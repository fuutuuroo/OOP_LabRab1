#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
	int left;
	double right;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	//геттеры
	int get_left();
	double get_right();
	//сеттеры
	void set_left(int);
	void set_right(double);
	//вспомогательные функции
	void set_randomPair();
	//перегрузки операций ввода-вывода
	friend istream& operator >> (istream&, Pair&);
	friend ostream& operator << (ostream&, const Pair&);
	//перегрузки арифметических операций
	Pair operator - (Pair);
	Pair& operator + (const Pair&);
	Pair& operator + (int);
	Pair& operator + (double);
	//перегрузка операции присваивания
	Pair& operator = (const Pair&);
	//перегрузки операций сравнения
	bool operator < (const Pair&)const;
	bool operator > (const Pair&)const;
	bool operator <= (const Pair&)const;
	bool operator >= (const Pair&)const;
};