/* Вариант 12. Задача 3.
Тип элементов Pair (см. лабораторную работу №3).
Параметризированный класс – Список (см. лабораторную работу №7)

Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
3адание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/


#include <iostream>
#include "Pair.h"
#include "List.h"
#include "List.cpp"

int main() {
	setlocale(LC_ALL, "rus");

	int size;
	cout << "Введите размер списка: ";
	cin >> size;
	cout << "Введите элементы списка через Enter:" << endl;
	List<Pair> list(size);
	cout << "Cписок: ";
	list.printList();
	cout << "Среднее арифметическое = " << list.listFindMean() << endl;
	int pos;
	cout << endl << "Введите позицию для добавления среднего арифметического: ";
	cin >> pos;
	list.addMeanToPosition(pos);
	cout << "Cписок после добавления: ";
	list.printList();
	cout << endl << "Укажите диапазон для удаления элементов:" << endl;
	list.deleteRange();
	cout << "Список после удаления элементов: ";
	list.printList();
	cout << "Среднее арифметическое = " << list.listFindMean() << endl;
	list.eachMinusMean();
	cout << endl << "Список после удаления среднего арифметического из каждого элемента: " << endl;
	list.printList();

	return 0;
}