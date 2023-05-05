#pragma once
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
    double first, second;
    void Init(double, double);
    void Read();
    void Show();
    double distance();
};
