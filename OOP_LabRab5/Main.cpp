#include "Triad.h"
#include "Date.h"
#include "Vector.h"

int main() {
	setlocale(LC_ALL, "RU");
	Vector vec(5);

	Triad t1;
	cout << t1;
	Object* p1 = &t1;
	vec.add(p1);
	Triad t2(22, 2, 222);
	cout << t2 << endl;
	Object* p2 = &t2;
	vec.add(p2);

	Date d1(1999, 12, 8);
	cout << d1 << endl;
	Object* p3 = &d1;
	vec.add(p3);
	Date d2;
	cin >> d2;
	
	bool comp1 = d1 < d2;
	if (comp1) {
		cout << d1 << " меньше, чем " << d2 << endl;
	}
	else {
		cout << d1 << " не меньше, чем " << d2 << endl;
	}
	Date d3(d2);
	bool comp2 = d2 == d3;
	if (comp2) {
		cout << d2 << " равна дате " << d3 << endl;
	}
	else {
		cout << d2 << " не равна дате " << d3 << endl;
	}
	Object* p4 = &d2;
	vec.add(p4);
	Object* p5 = &d3;
	vec.add(p5);

	cout << endl << "Вектор:" << endl << vec;

	return 0;
}






