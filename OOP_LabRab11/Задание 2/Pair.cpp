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

void Pair::set_randomPair() {
	left = rand() % 10;
	right = (rand() % 100 - 1) / 10.0;
}

//перегрузка операции ввода
istream& operator >> (istream& in, Pair& p) {
	cout << "Введите левое число: ";
	in >> p.left;
	cout << "Введите правое число: ";
	in >> p.right;
	return in;
}
//перегрузка операции вывода
ostream& operator << (ostream& out, const Pair& p) {
	return out << "[" << p.left << " : " << p.right << "]" << " ";
}
//перегрузка операций сравнения
void Pair::operator < (const Pair& p) {
	if ((this->left < p.left) || (this->left == p.left && this->right < p.right)) {
		cout << "Первая пара чисел меньше, чем вторая пара" << endl;
	}
	else {
		cout << "Первая пара чисел НЕ меньше, чем вторая пара" << endl;
	}

}
void Pair::operator > (const Pair& p) {
	if ((this->left > p.left) || (this->left == p.left && this->right > p.right)) {
		cout << "Первая пара чисел больше, чем вторая пара" << endl;
	}
	else {
		cout << "Первая пара чисел НЕ больше, чем вторая пара" << endl;
	}
}

void Pair::operator ++ () {
	++left; }
void Pair::operator ++ (int) {
	right += 1.0; }
//перегрузка операции сложения для двух пар
Pair Pair::operator + (const Pair& p) {
	Pair temp;
	temp.left = left + p.left;
	temp.right = right + p.right;
	return temp;
}
//перегрузка операции вычитания для двух пар
Pair Pair::operator - (const Pair& p) {
	Pair temp;
	temp.left = left - p.left;
	temp.right = right - p.right;
	return temp;
}
//перегрузка операции деления для пары
Pair Pair::operator / (int n) {
	Pair temp;
	temp.left = left / n;
	temp.right = right / n;
	return temp;
}
//перегрузки операций сравнения
bool Pair::operator >= (const Pair& p) {
	if (left >= p.left && right >= p.right)
		return 1;
	else
		return 0;
}
bool Pair::operator <= (const Pair& p) {
	if (left <= p.left && right <= p.right)
		return 1;
	else
		return 0;
}
