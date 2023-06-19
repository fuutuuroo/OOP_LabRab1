#pragma once
#include "Object.h"
#include "Event.h"

class Vector
{
protected:
	Object** beg; 
	int size; 
	int cur; 
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(); 
	void Del(); 
	void Show();
	void HandleEvent(const TEvent& e);
	int operator () ();
};
