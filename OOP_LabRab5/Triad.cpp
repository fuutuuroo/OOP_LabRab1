#include "Triad.h"

Triad::Triad() {
	first = 0;
	second = 0;
	third = 0;
}
Triad::Triad(int f, int s, int t) {
	first = f;
	second = s;
	third = t;
}
Triad::Triad(const Triad& t) {
	first = t.first;
	second = t.second;
	third = t.third;
}
Triad::~Triad() {};

int Triad::get_first() {
	return first;
}
int Triad::get_second() {
	return second;
}
int Triad::get_third() {
	return third;
}
void Triad::set_first(int f) {
	first = f;
}
void Triad::set_second(int s) {
	second = s;
}
void Triad::set_third(int t) {
	third = t;
}

void Triad::show() {
	cout << first << " " << second << " " << third << endl;
}

istream& operator>>(istream& in, Triad& t) {
	cout << "\n¬ведите первое число: ";
	in >> t.first;
	cout << "\n¬ведите второе число: ";
	in >> t.second;
	cout << "\n¬ведите третье число: ";
	in >> t.third;
	return in;
}
ostream& operator <<(ostream& out, const Triad& t) {
	out << t.first << " " << t.second << " " << t.third << endl;
	return out;
}

bool Triad::operator < (const Triad& t) {
	return ((first < t.first) || (first == t.first && second < t.second) ||
		(first == t.first && second == t.second && third < t.third));
}
bool Triad::operator <= (const Triad& t) {
	return ((first <= t.first) || (first == t.first && second <= t.second) ||
		(first == t.first && second == t.second && third <= t.third));
}
bool Triad::operator > (const Triad& t) {
	return ((first > t.first) || (first == t.first && second > t.second) ||
		(first == t.first && second == t.second && third > t.third));
}
bool Triad::operator >= (const Triad& t) {
	return ((first >= t.first) || (first == t.first && second >= t.second) ||
		(first == t.first && second == t.second && third >= t.third));
}
bool Triad::operator == (const Triad& t) {
	return (first == t.first && second == t.second && third == t.third);
}
