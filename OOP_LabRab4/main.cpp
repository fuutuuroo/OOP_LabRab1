#include "Student.h"

int main() {
	setlocale(LC_ALL, "RU");
	//проверка работы класса Person
	Person p1;					
	cout << "Person 1:" << endl << p1 << endl;
	Person p2;
	cin >> p2;
	cout << "\nPerson 2:" << endl << p2 << endl;
	//проверка работы класса Student
	Student s1;										//констурктор по умолчанию
	cin >> s1;										//перегрузка операции ввода
	cout << "\nStudent 1:" << endl << s1 << endl;
	Student s2("Andrew", 20, 2005);					//конструктор с параметрами
	cout << "Student 2:" << endl << s2 << endl;
	Student s3(s2);									//конструктор копирования и изменение полей
	s3.set_name("Monica");
	s3.set_age(22);
	s3.set_year(2010);								//метод изменения года обучения
	cout << "Student 3:" << endl << s3 << endl;
	s3.add_year(10);								//метод увеличения года обучения
	cout << "Student 3 with new year:" << endl << s3 << endl;

	return 0;
}