#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Vector {
private:
	Object** begin;		//��������� �� ������ ������� ������� 
	int size;			//������
	int cur;			//������� �������
public:
	Vector();													//����������� ��� ���������� 
	Vector(int);												//����������� c �����������
	~Vector();													//����������
	void Add(Object*);											//���������� �������� � ������
	friend ostream& operator << (ostream& out, const Vector&);	//�������� ������ 
};
