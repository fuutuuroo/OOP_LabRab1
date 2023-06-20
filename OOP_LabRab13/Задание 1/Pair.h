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
	void set_randomPair();
	//перегрузки операций ввода-вывода
	friend istream& operator >> (istream&, Pair&);
	friend ostream& operator << (ostream&, const Pair&);

	Pair operator - (Pair);
	Pair& operator +(const Pair& p);
	Pair operator ++ (int);
	Pair operator ++ ();
	Pair& operator+(int);
	Pair& operator+(double);

	Pair& operator=(const Pair&);
	bool operator<(const Pair&)const;
	bool operator>(const Pair&)const;
	bool operator <=(const Pair&)const;
	bool operator >=(const Pair&)const;

	/*
	//перегрузки операторов сравнения
	bool operator < (const Pair&)const;
	bool operator > (const Pair&)const;
	bool operator <= (const Pair&)const;
	bool operator >= (const Pair&)const;
	//перегрузки арифметических действий с парами
	Pair operator + (const Pair&);
	Pair operator - (const Pair&);
	Pair operator / (int);
	*/
};