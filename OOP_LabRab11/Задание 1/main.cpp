/* Вариант 12. Задача 1. 
1.	Контейнер - список
2.	Тип элементов - int
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
3адание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include <iostream>
#include <list>
#include <ctime>
using namespace std;

typedef list<int> List;

List makeList(int size) {
	List temp;
	for (int i = 0; i < size; i++) {
		int e = (rand() % 20);
		temp.push_back(e);
	}
	return temp;
}

void printList(List& list) {
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

int listFindMean(List& list) {
	int sum = 0;
	for (auto i = list.begin(); i != list.end(); ++i) {
		sum += *i;
	}
	return sum / list.size();
}

void addMeanToPosition(List& list, int pos) {
	int mean = listFindMean(list);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
}

void deleteRange(List& list) {
	int left, right;
	cout << "Введите левую границу диапазона: "; 
	cin >> left;
	cout << "Введите правую границу диапазона: "; 
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			++i;
	}
}

void eachMinusMean(List& list) {
	int mean = listFindMean(list);
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
	cout << endl << "Список после удаления среднего арифметического из каждого элемента: ";
	printList(list);

	return 0;
}