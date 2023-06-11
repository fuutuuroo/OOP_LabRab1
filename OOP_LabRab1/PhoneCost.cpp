#include "PhoneCost.h"
//функция для заполнения данных
void PhoneCost::Init(int f, double s) {
	if (f > 0 && s > 0) {
		first = f;
		second = s;
	}
	else {
		cout << "Количество минут и стоимость должны быть больше нуля!" << endl;
	}
}
//функция для считывания данных с клавиатуры
void PhoneCost::Read(){
	int f = 0;
	double s = 0.0;
	cout << "\nВведите количество миинут: ";
	cin >> f;
	while (f <= 0) {
		cout << "Укажите корректное количество минут, оно должно быть больше нуля: " ;
		cin >> f;
	}
	first = f;

	cout << "Введите стоимость одной минуты в рублях: ";
	cin >> s;
	while (s <= 0.0) {
		cout << "Укажите корректную стоимость, она должна быть больше нуля: ";
		cin >> s;
	}
	second = s;
}
//функция для отображения данных
void PhoneCost::Show(){
	cout << "\nКоличество минут (first) = " << first << endl;
	cout << "Стоимость минуты в рублях (second) = " << second << endl;
}
//функция для вычисления стоимости разговора
double PhoneCost::cost() {
	return first * second;
}

