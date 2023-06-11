#pragma once
#include <iostream>
using namespace std;

class Pair {
private:
	int left;
	double right;
public:
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
	~Pair() {
		cout << "����� ����������� ���: " << this << endl;
	}
	//�������
	int get_left() {
		return left;
	}
	void set_left(int l) {
		left = l;
	}
	//�������
	double get_right() {
		return right;
	}
	void set_right(double r) {
		right = r;
	}
	//���������� �������� �����-������
	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, const Pair& p);
	//���������� ���������� ���������
	void operator < (const Pair& p);
	void operator > (const Pair& p);
	//���������� ����������� ����������
	void operator ++ () {
		++left;
	}
	//���������� ������������ ����������
	void operator ++ (int) {
		right++;
	}
};

