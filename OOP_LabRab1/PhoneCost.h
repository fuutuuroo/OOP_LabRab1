#pragma once
#include <iostream>
using namespace std;

struct PhoneCost {
	int first;		//����������������� ����������� ��������� � �������
	double second;	//��������� ����� ������ ��������� � ������
	void Init(int f, double s);
	void Read();
	void Show();
	double cost();
};
