#include "Point.h"

void Point::Init(double x, double y) {
    if (x == 0 && y == 0) {
        cout << "Координаты этой точки не могут быть (0, 0)!" << endl;
    }
    else {
        first = x;
        second = y;
    }
}

void Point::Read() {
    cout << "\nВведите значение x: ";
    cin >> first;
    cout << "Введите значение y: ";
    cin >> second;
    while (first == 0 && second == 0) {
        cout << "Введите новые значения x и y, оба не могут быть равны нулю: ";
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