#include "Triad.h"
#include "Date.h"

int main() {
	setlocale(LC_ALL, "RU");

	Triad t;
	cout << t;
	cin >> t;
	cout << t;

	Date d1(1999, 12, 8);
	Date d2;
	cin >> d2;
	bool comp1 = d1 < d2;
	if (comp1) {
		cout << d1 << " ������, ��� " << d2 << endl;
	}
	else {
		cout << d1 << " �� ������, ��� " << d2 << endl;
	}
	Date d3(d2);
	bool comp2 = d2 == d3;
	if (comp2) {
		cout << d2 << " ����� ����  " << d2 << endl;
	}
	else {
		cout << d2 << " �� ����� ���� " << d2 << endl;
	}
	

	return 0;
}