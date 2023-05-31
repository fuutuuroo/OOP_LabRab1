#pragma once
#include <iostream>
using namespace std;

class Triad {
	int first, second, third;
public:
	Triad();
	Triad(int f, int s, int t);
	Triad(const Triad& t);
	~Triad();

	int get_first();
	int get_second();
	int get_third();
	void set_first(int);
	void set_second(int);
	void set_third(int);

	friend istream& operator >> (istream& in, Triad& t);
	friend ostream& operator << (ostream& out, const Triad& t);

	bool operator < (const Triad& t);
	bool operator <= (const Triad& t);
	bool operator > (const Triad& t);
	bool operator >= (const Triad& t);
	bool operator == (const Triad& t);

};

