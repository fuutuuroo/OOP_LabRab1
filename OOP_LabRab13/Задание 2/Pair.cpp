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
//��������������� �������
void Pair::set_randomPair() {
	left = rand() % 10;
	right = (rand() % 100 - 1) / 10.0;
}
//���������� �������� �����
istream& operator >> (istream& in, Pair& p) {
	cout << "����� �����: ";
	in >> p.left;
	cout << "������ �����: ";
	in >> p.right;
	return in;
}
//���������� �������� ������
ostream& operator << (ostream& out, const Pair& p) {
	return (out << "[" << p.left << " : " << p.right << "]" << " ");
}
//���������� �������������� ��������
Pair Pair::operator - (Pair p) {
	left -= p.left;
	right -= p.right;
	return *this;
}
Pair& Pair::operator + (int first) {
	this->left += left;
	return *this;
}
Pair& Pair::operator + (double second) {
	this->right += right;
	return *this;
}
Pair& Pair::operator + (const Pair& p)
{
	this->left += p.left;
	this->right += p.right;
	return *this;
}
//���������� �������� ������������
Pair& Pair::operator = (const Pair& p) {
	if (&p == this) return *this;
	left = p.left;
	right = p.right;
	return *this;
}
//���������� �������� ���������
bool Pair::operator < (const Pair& p)const {
	if (left != p.left) {
		return left < p.left;
	}
	else {
		return right < p.right;
	}
}
bool Pair::operator > (const Pair& p)const {
	if (left != p.left) {
		return left > p.left;
	}
	else {
		return right > p.right;
	}
}
bool Pair::operator <=(const Pair& p) const
{
	double sthis = this->left + this->right;
	double sother = p.left + p.right;
	if (sthis <= sother) return true;
	return false;
}
bool Pair::operator >=(const Pair& p) const
{
	double sthis = this->left + this->right;
	double sother = p.left + p.right;
	if (sthis >= sother) return true;
	return false;
}