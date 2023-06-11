#include "Student.h"

int main() {
	setlocale(LC_ALL, "RU");
	//�������� ������ ������ Person
	Person p1;					
	cout << "Person 1:" << endl << p1 << endl;
	Person p2;
	cin >> p2;
	cout << "\nPerson 2:" << endl << p2 << endl;
	//�������� ������ ������ Student
	Student s1;										//����������� �� ���������
	cin >> s1;										//���������� �������� �����
	cout << "\nStudent 1:" << endl << s1 << endl;
	Student s2("Andrew", 20, 2005);					//����������� � �����������
	cout << "Student 2:" << endl << s2 << endl;
	Student s3(s2);									//����������� ����������� � ��������� �����
	s3.set_name("Monica");
	s3.set_age(22);
	s3.set_year(2010);								//����� ��������� ���� ��������
	cout << "Student 3:" << endl << s3 << endl;
	s3.add_year(10);								//����� ���������� ���� ��������
	cout << "Student 3 with new year:" << endl << s3 << endl;

	return 0;
}