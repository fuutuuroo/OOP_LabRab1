#include "Flat.h"

Flat make_Flat() {
    string a;
    double s;
    int r;
    cout << "Введите адрес: ";
    cin >> a;
    cout << "Введите площадь квартиры: ";
    cin >> s;
    cout << "Введите количество комнат: ";
    cin >> r;
    Flat f(a, s, r);
    return f;
}

void print_Flat(Flat f) {
    f.show();
}

int main() {
    setlocale(LC_ALL, "RU");
    Flat f1;
    f1.show();

    Flat f2("Ленина, 38, 39", 56.5, 3);
    f2.show();

    Flat f3 = f2;
    f3.set_address("Сталина, 37, 51");
    f3.set_square(44.4);
    f3.set_rooms(2);
    f3.show();

    print_Flat(f3);

    f1 = make_Flat();
    f1.show();

    cout << "\n\n";
    system("pause");
    return 0;
}