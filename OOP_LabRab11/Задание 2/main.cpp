/* Вариант 12. Задача 2.
1.	Контейнер - список
2.	Тип элементов Pair (см. лабораторную работу №3).
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
3адание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include "Pair.h"
#include <list>
#include <ctime>

typedef list<Pair> List;

List makeList(int size) {
	List temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push_back(p);
	}
	return temp;
}

void printList(List& list) {
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

Pair listFindMean(List& list) {
	Pair sum;
	for (auto i = list.begin(); i != list.end(); ++i) {
		sum = sum + *i;
	}
	return sum / list.size();
}

void addMeanToPosition(List& list, int pos) {
	Pair mean = listFindMean(list);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
}

void deleteRange(List& list) {
	Pair left, right;
	cout << "Введите левую границу диапазона: " << endl;
	cin >> left;
	cout << "Введите правую границу диапазона: " << endl;
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			++i;
	}
}

void eachMinusMean(List& list) {
	Pair mean = listFindMean(list);
	for (auto i = list.begin(); i != list.end(); ++i) {
		*i = *i - mean;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	List list;
	int size;
	cout << "Введите размер списка: ";
	cin >> size;
	list = makeList(size);
	cout << "Cписок: ";
	printList(list);
	cout << "Среднее арифметическое = " << listFindMean(list) << endl;
	int pos;
	cout << endl << "Введите позицию для добавления среднего арифметического: ";
	cin >> pos;
	addMeanToPosition(list, pos);
	cout << "Cписок после добавления: ";
	printList(list);
	cout << endl << "Удаление элементов из указанного диапазона:" << endl;
	deleteRange(list);
	cout << "Список после удаления элементов: ";
	printList(list);
	cout << "Среднее арифметическое = " << listFindMean(list) << endl;
	eachMinusMean(list);
	cout << endl << "Список после удаления среднего арифметического из каждого элемента: " << endl;
	printList(list);

	return 0;
}
