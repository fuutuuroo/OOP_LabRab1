/* Вариант 12
Пользовательский класс КВИТАНЦИЯ Номер –  int
Дата – string Сумма – double
*/

#include "Receipt.h"
//функция для возврата объекта как результата
Receipt makeReceipt() {
	int num;
	string date;
	double sum;
	cout << "Введите номер квитанции: " << endl;
	cin >> num;
	cout << "Введите дату: " << endl;
	cin >> date;
	cout << "Введите сумму: " << endl;
	cin >> sum;
	Receipt temp(num, date, sum);
	return temp;	
}
//функция для передачи объекта, как параметра
void printReceipt(Receipt r) {
	r.show();
}

int main() {
	setlocale(LC_ALL, "RU");
	//конструктор без параметров
	Receipt r1;
	cout << "Квитанция № 1: " << endl;
	r1.show();
	//конструктор с параметрами
	Receipt r2(2000222, "02/02/2022", 378.55);
	cout << "\nКвитанция № 2: " << endl;
	r2.show();
	//конструктор копирования
	Receipt r3 = r2;
	//изменение полей сеттерами
	r3.set_number(1000055);
	r3.set_date("05/05/2005");
	r3.set_sum(2777.44);
	cout << "\nКвитанция № 3: " << endl;
	r3.show();
	//функция для создания
	r1 = makeReceipt();
	cout << "\nКвитанция № 4" << endl;
	printReceipt(r1);
	cout << endl;

	return 0;
}