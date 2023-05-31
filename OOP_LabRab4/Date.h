#pragma once
#include "Triad.h"

class Date : public Triad {
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date& d);
	~Date();

	int get_year();
	int get_month();
	int get_day();
	void set_year(int);
	void set_month(int);
	void set_day(int);

	friend istream& operator >> (istream& in, Date& d);
	friend ostream& operator << (ostream& out, const Date& d);

	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	bool operator > (const Date& d);
	bool operator >= (const Date& d);
	bool operator == (const Date& d);

};

