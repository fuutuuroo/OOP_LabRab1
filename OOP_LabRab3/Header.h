#pragma once
#include <iostream>
using namespace std;

class Money {
	long rub;
	int kop;
public:
	Money() {
		rub = 0;
		kop = 0;
	};
	Money(long r, int k) {
		rub = r;
		kop = k;
	}
	Money(const Money& m) {
		rub = m.rub;
		kop = m.kop;
	}
	~Money() {};

	long get_rub() {
		return rub;
	}
	int get_kop() {
		return kop;
	}
	void set_rub(long r) {
		rub = r;
	}
	void set_kop(int k) {
		kop = k;
	}
	
	friend istream& operator >> (istream& in, Money& m);
	friend ostream& operator << (ostream& out, const Money& m);
	friend Money operator + (Money& m, float x);
	bool operator < (const Money& m);
	bool operator > (const Money& m);
	bool operator == (const Money& m);

};
