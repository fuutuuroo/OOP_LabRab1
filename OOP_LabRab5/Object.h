#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object {
public:
	Object(void); 
	~Object(void);
	virtual void show() = 0;//чисто виртуальная функция
};

