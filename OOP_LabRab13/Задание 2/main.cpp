/* Вариант 12. Задача 2.
Контейнер - список
Тип элементов Pair (см. лабораторную работу №3).
Адаптер контейнера – очередь с приоритетами.
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
Задание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include "Pair.h"
#include <list>
#include <ctime>
#include <queue>
#include <algorithm>

typedef list<Pair> List;
typedef priority_queue<Pair> Pq;
//создание очереди
Pq makePq(int size) {
	Pq temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push(p);
	}
	return temp;
}
//копирование оереди в список
List copy_pq_to_lst(Pq pq) {
	List list;
	while (!pq.empty()) {
		list.push_back(pq.top());
		pq.pop();
	}
	return list;
}
//копирование списка в очередь
Pq copy_lst_to_pq(List list) {
	Pq pq;
	while (!list.empty()) {
		pq.push(list.back());
		list.pop_back();
	}
	return pq;
}
//вывод очереди в консоль
void print_pq(Pq pq) {
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
}
//поиск среднего арифметического 
Pair findMean(Pq pq) {
	List list = copy_pq_to_lst(pq);
	Pair sum;
	int count = 0;
	for_each(list.begin(), list.end(), [&sum](Pair& p) {
			sum = sum + p;
	});
	sum.set_left(sum.get_left() / list.size());
	sum.set_right(sum.get_right() / list.size());
	return sum;
}
//добавление среднего арифметического в очередь
void addMean(Pq& pq, int ind) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_lst(pq);
	auto li = list.begin();
	advance(li, ind);
	list.insert(li, mean);
	pq = copy_lst_to_pq(list);
}
//удаление элементов из указанного диапазона
void deleteRange(Pq& pq) {
	List list = copy_pq_to_lst(pq);
	Pair first, second;
	cout << "\nВведите первую границу:\n";
	cin >> first;
	cout << "Введите вторую границу:\n";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	auto s = remove_if(list.begin(), list.end(), [first, second](Pair& p) {
		return p >= first && p <= second;
	});
	list.erase(s, list.end());
	pq = copy_lst_to_pq(list);
}
//вычитание среднего арифметического из каждого элемента
void eachMinusMean(Pq& pq) {
	List list = copy_pq_to_lst(pq);
	Pair mean = findMean(pq);
	for_each(list.begin(), list.end(), [&mean](Pair& p) {p = p - mean; });
	pq = copy_lst_to_pq(list);
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Pq pq;
	int size;
	cout << "Введите количество элементов: ";
	cin >> size;
	pq = makePq(size);
	cout << "Очередь: " << endl;
	print_pq(pq);
	cout << "Cреднее арифметическое: " << findMean(pq) << endl;
	
	addMean(pq, 0);	//очередь с приоритетом автоматически расставляет элементы, поэтому позиция 0
	cout << "\nОчередь после вставки среднего арифметического: " << endl;
	print_pq(pq);

	cout << "Удаление диапазона: ";
	deleteRange(pq);
	cout << "\nОчередь после удаления: " << endl;
	print_pq(pq);
	cout << "Cреднее арифметическое: " << findMean(pq) << endl;

	eachMinusMean(pq);
	cout << "\nОчередь после вычитания среднего арифметического из всех элементов: " << endl;
	print_pq(pq);

	return 0;
}