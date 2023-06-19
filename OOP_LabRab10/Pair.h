#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair {
private:
	int left;
	double right;
public:
	//конструкторы
	Pair() {
		left = 0;
		right = 0.0;
	}
	Pair(int l, double r) {
		left = l;
		right = r;
	}
	Pair(const Pair& p) {
		left = p.left;
		right = p.right;
	}
	~Pair() {}
	//геттеры
	int get_left() {
		return left;
	}
	void set_left(int l) {
		left = l;
	}
	//сеттеры
	double get_right() {
		return right;
	}
	void set_right(double r) {
		right = r;
	}
	//перегрузки операторов сравнения
	void operator < (const Pair& p);
	void operator > (const Pair& p);
	//перегрузка префиксного инкремента
	void operator ++ () { ++left; }
	//перегрузка постфиксного инкремента
	void operator ++ (int) { right += 1.0; }
	//перегрузка оператора сложения
	Pair operator + (int); 
	//перегрузки операций ввода-вывода
	friend istream& operator >> (istream&, Pair&);
	friend ostream& operator << (ostream&, const Pair&);
	//перегрузки для работы с файловым потоком
	friend fstream& operator >> (fstream&, Pair&);
	friend fstream& operator << (fstream&, const Pair&);
};