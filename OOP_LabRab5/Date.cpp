#include "Date.h"

Date::Date() {
	year = 0;
	month = 0;
	day = 0;
}
Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
Date::Date(const Date& d) {
	year = d.year;
	month = d.month;
	day = d.day;
}
Date::~Date() {};

int Date::get_year() {
	return year;
}
int Date::get_month() {
	return month;
}
int Date::get_day() {
	return day;
}
void Date::set_year(int y) {
	year = y;
}
void Date::set_month(int m) {
	month = m;
}
void Date::set_day(int d) {
	day = d;
}
void Date::show() {
	cout << year << "/" << month << "/" << day << endl;
}

istream& operator>>(istream& in, Date& d) {
	cout << "¬ведите год: ";
	in >> d.year;
	while (d.year < 1) {
		cout << "¬ведите корректный год (от 1): ";
		in >> d.year;
	}
	cout << "¬ведите мес€ц: ";
	in >> d.month;
	while (d.month < 1 || d.month > 12) {
		cout << "¬ведите корректный мес€ц (1-12): ";
		in >> d.month;
	}
	cout << "¬ведите день: ";
	in >> d.day;
	while (d.day < 1 || d.day > 31) {
		cout << "¬ведите корректный день (1-31): ";
		in >> d.day;
	}
	return in;
}
ostream& operator <<(ostream& out, const Date& d) {
	out << d.year << "/" << d.month << "/" << d.day;
	return out;
}

bool Date::operator < (const Date& d) {
	return ((year < d.year) || (year == d.year && month < d.month) ||
		(year == d.year && month == d.month && day < d.day));
}
bool Date::operator <= (const Date& d) {
	return ((year <= d.year) || (year == d.year && month <= d.month) ||
		(year == d.year && month == d.month && day <= d.day));
}
bool Date::operator > (const Date& d) {
	return ((year > d.year) || (year == d.year && month > d.month) ||
		(year == d.year && month == d.month && day > d.day));
}
bool Date::operator >= (const Date& d) {
	return ((year >= d.year) || (year == d.year && month >= d.month) ||
		(year == d.year && month == d.month && day >= d.day));
}
bool Date::operator == (const Date& d) {
	return (year == d.year && month == d.month && day == d.day);
}
