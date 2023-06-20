/* Вариант 12. Задача 2
1.	Контейнер - map
2.	Тип элементов Pair (см. лабораторную работу №3).
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
Задание 3: Из каждого элемента вычесть среднее арифметическое контейнера
 */

#include "Pair.h"
#include <ctime>
#include <map>

typedef map<int, Pair> Map;
typedef Map::iterator iter;
//создание словаря
Map makeMap(int size) {
	Map m;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		m.insert(make_pair(i, p));
	}
	return m;
}
//вывод словаря в консоль
void printMap(Map m) {
	for (iter it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
}
//поиск среднего арифметического
Pair findMean(Map m) {
	Pair temp;
	int intSum = 0;
	double doubleSum = 0.0;
	int count = 0;
	for (iter it = m.begin(); it != m.end(); it++) {
		intSum = intSum + it->second.get_left();
		doubleSum = doubleSum + it->second.get_right();
		count++;
	}
	temp.set_left(intSum / count);
	temp.set_right(doubleSum / count);
	return temp;
}
//удаление элементов из указанного диапазона
void deleteRange(Map& m) {
	int left, right;
	cout << "Введите левую границу целых чисел пары: ";
	cin >> left;
	cout << "Введите правую границу целых чисел пары: ";
	cin >> right;
	for (iter it = m.begin(); it != m.end();) {
		if (left <= it->second.get_left() && it->second.get_left() <= right) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}
//вычитание среднего арифметического из каждого элемента
void eachMinusMean(Map& m) {
	Pair mean = findMean(m);
	for (iter it = m.begin(); it != m.end(); it++) {
		it->second = it->second - mean;
	}
}


int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Map map;
	int size;
	cout << "Введите размер словаря: ";
	cin >> size;
	map = makeMap(size);
	cout << "Словарь: " << endl;
	printMap(map);
	Pair mean = findMean(map);
	cout << "Среднее арифметическое: " << mean << endl;

	map.insert(make_pair(size, mean));
	cout << "\nСловарь после добавления среднего арифметического: " << endl;
	printMap(map);

	cout << endl << "Укажите диапазон для удаления элементов: " << endl;
	deleteRange(map);
	cout << "Словарь после удаления: " << endl;
	printMap(map);
	cout << "Среднее арифметическое: " << findMean(map) << endl;

	eachMinusMean(map);
	cout << "\nСловарь после вычитания среднего арифметического из элементов: " << endl;
	printMap(map);

	return 0;
}