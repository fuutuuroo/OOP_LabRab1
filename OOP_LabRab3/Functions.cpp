#include "Header.h"

istream& operator >> (istream& in, Money& m) {
	cout << "¬ведите кол-во рублей: ";
	in >> m.rub;
	cout << "¬ведите кол-во копеек: ";
	in >> m.kop;
	return in;
}

ostream& operator << (ostream& out, const Money& m) {
	return (out << m.rub << "," << m.kop);
}

Money operator + (Money& m, float x) {
	long sum = (m.get_rub() * 100) + m.get_kop() + (x * 100);
	long r = sum / 100;
	int k = sum % 100;
	Money Sum(r, k);
	return Sum;
}

bool Money::operator < (const Money& m) {
	return ((this->rub < m.rub) || (this->rub == m.rub && this->kop < m.kop)); 
}

bool Money::operator > (const Money& m) {
	return ((this->rub > m.rub) || (this->rub == m.rub && this->kop > m.kop)); 
}

bool Money::operator == (const Money& m) {
	return (this->rub == m.rub && this->kop == m.kop);
}
