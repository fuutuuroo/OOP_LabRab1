#include "Vector.h"
//����������� ��� ���������� 
Vector::Vector(void) {
	begin = 0;
	size = 0;
	cur = 0;
}
//���������� 
Vector::~Vector(void) {
	if (begin != 0) {
		delete[] begin;
	}
	begin = 0;
}
//����������� � ����������� 
Vector::Vector(int n) {
	begin = new Object* [n];
	cur = 0;
	size = n;
}
//���������� �������, �� ������� ��������� ��������� p � ������ 
void Vector::add(Object* p) {
	if (cur < size) {
		begin[cur] = p;
		cur++;
	}
}

//�������� ������
ostream& operator<<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "������ ����!" << endl;
	}
	Object** p = v.begin;//��������� �� ��������� ���� Object 
	for (int i = 0; i < v.cur; i++) {
		(*p)->show();//����� ������ show() (������� ����������) 
		p++;//����������� ��������� �� ��������� ������
	}
	return out;
}
