#pragma once
#include <iostream>
#include <string>
using namespace std;

class Flat {
    string address;
    double square;
    int rooms;
public:
    Flat();
    Flat(string, double, int);
    Flat(const Flat&);
    ~Flat();

    string get_address();
    void set_address(string);

    double get_square();
    void set_square(double);
    int get_rooms();
    void set_rooms(int);

    void show();
};
