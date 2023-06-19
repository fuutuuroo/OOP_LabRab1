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
	//�������
	int get_left();
	double get_right();
	//�������
	void set_left(int);
	void set_right(double);
	void set_randomPair();
	//���������� �������� �����-������
	friend istream& operator >> (istream&, Pair&);
	friend ostream& operator << (ostream&, const Pair&);
	//���������� ���������� ���������
	bool operator < (const Pair&);
	bool operator > (const Pair&);
	bool operator <= (const Pair&);
	bool operator >= (const Pair&);
	//���������� �������������� �������� � ������
	Pair operator + (const Pair&);
	Pair operator - (const Pair&);
	Pair operator / (int);

};