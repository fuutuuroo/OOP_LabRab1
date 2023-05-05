#include "Point.h"

Point make_Point(double x, double y) {
    Point temp;
    temp.Init(x, y);
    return temp;
}

int main() {
    setlocale(LC_ALL, "RU");

    Point point = make_Point(0, 3);
    point.Show();
    point.Read();
    point.Show();
    cout << "\nРасстояние от точки до начала координат равно: " << point.distance() << endl;

    cout << "\n\n";
    system("pause");
    return 0;
}