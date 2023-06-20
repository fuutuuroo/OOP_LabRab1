/* Вариант 12. Задача 3.
Тип элементов Pair (см. лабораторную работу №3).
Ассоциативный контейнер словарь с дубликатами
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
Задание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include "Pair.h"
#include <ctime>
#include <map>
#include <algorithm>

typedef multimap<int, Pair> Map;
//создание словаря
Map makeMap(int size) {
	Map temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.insert(make_pair(i, p));
	}
	return temp;
}
//вывод словаря в консоль
void printMap(Map map) {
	for (auto it : map) {
		cout << it.first << " : " << it.second << endl;
	}
}
//поиск среднего арифметического
Pair findMean(Map map) {
	Pair sum;
	int count = 0;
	for (auto it : map) {
		sum = sum + it.second;
		count++;
	}
	Pair mean;
	mean.set_left(sum.get_left() / count);
	mean.set_right(sum.get_right() / count);
	return mean;
}
//добавление среднего арифметического на заданную позицию
void addMean(Map& map, int pos) {
	Pair mean = findMean(map);
	map.insert(make_pair(pos, mean));
}
//удаление элементов из указанного диапазона
void deleteRange(Map& map) {
	int first, second;
	cout << "\nВведите первую границу целого числа пары: ";
	cin >> first;
	cout << "Введите вторую границу целого числа пары: ";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	while (find_if(map.begin(), map.end(), [&first, &second](decltype(*map.begin())& it) -> bool {
		return it.second.get_left() >= first && it.second.get_left() <= second;
		}
	) != map.end())	{
		const auto it = find_if(map.begin(), map.end(), [&first, &second](decltype(*map.begin())& it) -> bool {
				return it.second.get_left() >= first && it.second.get_left() <= second;
			}
		);
		map.erase(it->first);
	}
}
//вычитание среднего арифметического из каждого элемента
void eachMinusMean(Map& map) {
	Pair mean = findMean(map);
	for_each(map.begin(), map.end(), [mean] (pair<const int, Pair>& p) { p.second = p.second - mean; });	
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Map map;
	int size;
	cout << "Введите количество элементов: ";
	cin >> size;
	map = makeMap(size);
	cout << "Словарь: " << endl;
	printMap(map);
	cout << "Cреднее арифметическое: " << findMean(map) << endl;
	
	int ind;
	cout << "\nВведите индекс для вставки среднего арифметического: ";
	cin >> ind;
	addMean(map, ind);				
	cout << "Словарь после вставки среднего арифметического: " << endl;
	printMap(map);

	cout << "\nУдаление диапазона: ";
	deleteRange(map);
	cout << "Словарь после удаления: " << endl;
	printMap(map);
	cout << "Cреднее арифметическое: " << findMean(map) << endl;

	eachMinusMean(map);
	cout << "\nСловарь после вычитания среднего арифметического из всех элементов: " << endl;
	printMap(map);

	return 0;
}