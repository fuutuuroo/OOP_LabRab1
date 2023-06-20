#include "Pair.h"
using namespace std;

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
//перегрузка оператора сложения
Pair Pair::operator + (int add) {
	return Pair(left + add, right + add);
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
	return (out << p.left << ":" << p.right) << endl;
}
//операции файлового потока
fstream& operator >> (fstream& fin, Pair& p) {
	fin >> p.left;
	fin >> p.right;
	return fin;
}
fstream& operator << (std::fstream& fout, const Pair& p) {
	fout << p.left << '\n';
	fout << p.right << '\n';
	return fout;
}