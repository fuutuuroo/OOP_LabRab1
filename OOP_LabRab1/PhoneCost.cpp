#include "PhoneCost.h"
//������� ��� ���������� ������
void PhoneCost::Init(int f, double s) {
	if (f > 0 && s > 0) {
		first = f;
		second = s;
	}
	else {
		cout << "���������� ����� � ��������� ������ ���� ������ ����!" << endl;
	}
}
//������� ��� ���������� ������ � ����������
void PhoneCost::Read(){
	int f = 0;
	double s = 0.0;
	cout << "\n������� ���������� ������: ";
	cin >> f;
	while (f <= 0) {
		cout << "������� ���������� ���������� �����, ��� ������ ���� ������ ����: " ;
		cin >> f;
	}
	first = f;

	cout << "������� ��������� ����� ������ � ������: ";
	cin >> s;
	while (s <= 0.0) {
		cout << "������� ���������� ���������, ��� ������ ���� ������ ����: ";
		cin >> s;
	}
	second = s;
}
//������� ��� ����������� ������
void PhoneCost::Show(){
	cout << "\n���������� ����� (first) = " << first << endl;
	cout << "��������� ������ � ������ (second) = " << second << endl;
}
//������� ��� ���������� ��������� ���������
double PhoneCost::cost() {
	return first * second;
}

