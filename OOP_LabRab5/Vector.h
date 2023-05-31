#pragma once
#include "Object.h"

class Vector {
public:
	Vector(void);//����������� ��� ���������� 
	Vector(int);//����������� �����������
	~Vector(void);//����������
	void add(Object*);//���������� �������� � ������
	friend ostream& operator<<(ostream& out, const Vector&);//�������� ������ 
private:
	Object** begin;//��������� �� ������ ������� ������� 
	int size;//������
	int cur;//������� �������
};
