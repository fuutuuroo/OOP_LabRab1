#include "Pair.h"
//конструкторы
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
//деструктор
Pair::~Pair() {}
//геттеры
int Pair::get_left() {
	return left;
}
double Pair::get_right() {
	return right;
}
//сеттеры
void Pair::set_left(int l) {
	left = l;
}
void Pair::set_right(double r) {
	right = r;
}
//вспомогательные функции
void Pair::set_randomPair() {
	left = rand() % 10;
	right = (rand() % 100 - 1) / 10.0;
}
//перегрузка операции ввода
istream& operator >> (istream& in, Pair& p) {
	cout << "Левое число: ";
	in >> p.left;
	cout << "Правое число: ";
	in >> p.right;
	return in;
}
//перегрузка операции вывода
ostream& operator << (ostream& out, const Pair& p) {
	return (out << "[" << p.left << " : " << p.right << "]" << " ");
}
//перегрузки арифметических операций
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
//перегрузка операции присваивания
Pair& Pair::operator = (const Pair& p) {
	if (&p == this) return *this;
	left = p.left;
	right = p.right;
	return *this;
}
//перегрузки операций сравнения
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