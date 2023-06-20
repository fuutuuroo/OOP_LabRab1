/* Вариант 12. Задача 1.
1. Контейнер - список
2. Тип элементов Pair (см. лабораторную работу №3).
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
Задание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include "Pair.h"
#include <list>
#include <ctime>
#include <algorithm>

typedef list<Pair> List;
//создание списка
List makeList(int size) {
	List temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push_back(p);
	}
	return temp;
}
//вывод списка в консоль
void printList(List list) {
	for (auto i : list) {
		cout << i << endl;
	}
}
//поиск среднего арифметического 
Pair findMean(List list) {
	Pair sum;
	int count = 0;
	for_each(list.begin(), list.end(), [&sum] (Pair& p)
		{
			sum = sum + p;
		}
	);
	sum.set_left(sum.get_left() / list.size());
	sum.set_right(sum.get_right() / list.size());
	return sum;
}
//добавление среднего арифметического в очередь
void addMean(List& list, int ind) {
	Pair mean = findMean(list);
	auto li = list.begin();
	advance(li, ind);
	list.insert(li, mean);
}
//удаление элементов из указанного диапазона
void deleteRange(List& list) {
	Pair first, second;
	cout << "\nВведите первую границу:\n";
	cin >> first;
	cout << "Введите вторую границу:\n";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	auto s = remove_if(list.begin(), list.end(), [first, second] (Pair& p) {
			return p >= first && p <= second;
		}
	);
	list.erase(s, list.end());
}
//вычитание среднего арифметического из каждого элемента
void eachMinusMean(List& list) {
	Pair mean = findMean(list);
	for_each(list.begin(), list.end(), [&mean] (Pair& p) {p = p - mean; });
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	List list;
	int size;
	cout << "Введите количество элементов: ";
	cin >> size;
	list = makeList(size);
	cout << "Cписок: " << endl;
	printList(list);
	
	cout << "Cреднее арифметическое: " << findMean(list) << endl;
	int ind;
	cout << "\nУкажите индекс для вставки среднего арифметического: ";
	cin >> ind;

	addMean(list, ind);
	cout << "Cписок после вставки среднего арифметического: " << endl;
	printList(list);

	cout << "\nУдаление диапазона: ";
	deleteRange(list);
	cout << "\nCписок после удаления: " << endl;
	printList(list);
	cout << "Cреднее арифметическое: " << findMean(list) << endl;

	eachMinusMean(list);
	cout << "\nCписок после вычитания среднего арифметического из всех элементов: " << endl;
	printList(list);

	return 0;
}