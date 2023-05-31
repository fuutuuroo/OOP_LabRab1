#include "Flat.h"

Flat::Flat() {
    address = "";
    square = 0;
    rooms = 0;
}

Flat::Flat(string adr, double sq, int num) {
    address = adr;
    square = sq;
    rooms = num;
}

Flat::Flat(const Flat& f) {
    address = f.address;
    square = f.square;
    rooms = f.rooms;
}

Flat::~Flat() {
    cout << "Вызов дестуктора для " << this << endl;
}

string Flat::get_address() {
    return address;
}

void Flat::set_address(string adr) {
    address = adr;
}

double Flat::get_square() {
    return square;
}

void Flat::set_square(double sq) {
    square = sq;
}

int Flat::get_rooms() {
    return rooms;
}

void Flat::set_rooms(int r) {
    rooms = r;
}

void Flat::show() {
    cout << "Адрес: " << address << endl;
    cout << "Площадь квартиры: " << square << endl;
    cout << "Количество комнат: " << rooms << endl;
}