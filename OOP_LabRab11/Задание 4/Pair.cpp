#include "Pair.h"


//������������
Pair::Pair() {
	left = 0;
	right = 0.0;
}

Pair::Pair(int l, double d) {
	left = l;
	right = d;
}

Pair::Pair(const Pair& p) {
	left = p.left;
	right = p.right;
}
//����������
Pair::~Pair() {}
//�������
int Pair::get_left() {
	return left;
}
double Pair::get_right() {
	return right;
}
//�������
void Pair::set_left(int l) {
	left = l;
}
void Pair::set_right(double r) {
	right = r;
}

void Pair::set_randomPair() {
	left = rand() % 10;
	right = (rand() % 100 - 1) / 10.0;
}

//���������� �������� �����
istream& operator >> (istream& in, Pair& p) {
	cout << "������� ����� �����: ";
	in >> p.left;
	cout << "������� ������ �����: ";
	in >> p.right;
	return in;
}
//���������� �������� ������
ostream& operator << (ostream& out, const Pair& p) {
	return (out << "[" << p.left << " : " << p.right << "]" << " ");
}
//���������� �������� ��������� 

bool Pair::operator < (const Pair& p)const {
	return ((left < p.left) || (left == p.left && right < p.right));
}
bool Pair::operator > (const Pair& p)const {
	return ((left > p.left) || (left == p.left && right > p.right));
}

bool Pair::operator <= (const Pair& p)const {
	return (left <= p.left && right <= p.right);
}
bool Pair::operator >= (const Pair& p)const {
	return (left >= p.left && right >= p.right);
}
//���������� �������� �������� ��� ���� ���
Pair Pair::operator + (const Pair& p) {
	Pair temp;
	temp.left = left + p.left;
	temp.right = right + p.right;
	return temp;
}
//���������� �������� ��������� ��� ���� ���
Pair Pair::operator - (const Pair& p) {
	Pair temp;
	temp.left = left - p.left;
	temp.right = right - p.right;
	return temp;
}
//���������� �������� ������� ��� ����
Pair Pair::operator / (int n) {
	Pair temp;
	temp.left = left / n;
	temp.right = right / n;
	return temp;
}
