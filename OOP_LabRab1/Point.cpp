#include "Point.h"

void Point::Init(double x, double y) {
    if (x == 0 && y == 0) {
        cout << "���������� ���� ����� �� ����� ���� (0, 0)!" << endl;
    }
    else {
        first = x;
        second = y;
    }
}

void Point::Read() {
    cout << "\n������� �������� x: ";
    cin >> first;
    cout << "������� �������� y: ";
    cin >> second;
    while (first == 0 && second == 0) {
        cout << "������� ����� �������� x � y, ��� �� ����� ���� ����� ����: ";
        cin >> first;
        cin >> second;
    }
}

void Point::Show() {
    cout << "first = " << first << endl;
    cout << "second = " << second << endl;
}

double Point::distance() {
    return sqrt(first * first + second * second);
}