/* Вариант 12. Задача 1
1.	Контейнер - map
2.	Тип элементов - int
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
Задание 3: Из каждого элемента вычесть среднее арифметическое контейнера
 */

#include <iostream>
#include <map>
#include <ctime>
using namespace std;

typedef map<int, int> Map;
typedef Map::iterator iter;
//создание словаря
Map makeMap(int size) {
	Map m;
	int data;
	for (int i = 0; i < size; i++) {
		data = rand() % 20;
		m.insert(make_pair(i, data));
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
int findMean(Map m) {
	int sum = 0;
	int count = 0;
	for (iter it = m.begin(); it != m.end(); it++) {
		sum = sum + it->second;
		count++;
	}
	return sum / count;
}
//удаление элементов из указанного диапазона
void deleteRange(Map& m) {
	int left, right;
	cout << "Введите левую границу: ";
	cin >> left;
	cout << "Введите правую границу: ";
	cin >> right;
	for (iter it = m.begin(); it != m.end();) {
		if (left <= it->second && it->second <= right) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}
//вычитание среднего арифметического из каждого элемента
void eachMinusMean(Map& m) {
	int mean = findMean(m);
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
	int mean = findMean(map);
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