#include "Vector.h" 
#include "Object.h"
#include "Student.h"
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	Vector v(5);								//�������� �������
	Person p1;									//�������� � ���������� ������� ������ Person
	cin >> p1;
	Student s1("Melissa", 22, 2008);			//�������� � ���������� ������� ������ Student
	Object* ptr = &p1;							//��������� ��������� �� ������ ������ Person 
	v.Add(ptr);									//���������� ������� � ������	
	ptr = &s1;									//��������� ��������� �� ������ ������ Student 
	v.Add(ptr);									//���������� ������� � ������		
	cout << endl << "----------" << endl << v;	//����� ������� �� �����

	return 0;
}