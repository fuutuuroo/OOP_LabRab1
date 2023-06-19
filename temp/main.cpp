/* Вариант 12. Задача 4.
Контейнер - список
Тип элементов Pair (см. лабораторную работу №3).
Адаптер контейнера – очередь с приоритетами.
Задание 1: Найти среднее арифметическое и добавить его на заданную позицию контейнера
Задание 2: Найти элементы ключами из заданного диапазона и удалить их из контейнера
3адание 3: Из каждого элемента вычесть среднее арифметическое контейнера.
*/

#include "Pair.h"
#include <list>
#include <queue>
#include <ctime>

typedef priority_queue<Pair> Pq;
typedef list<Pair> List;

Pq make_pq(int size) {
	Pq temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		cin >> p;
		temp.push(p);
	}
	return temp;
}

List copy_pq_to_list(Pq pq) {
	List list;
	while (!pq.empty()) {
		list.push_back(pq.top());
		pq.pop();
	}
	return list;
}

Pq copy_list_to_pq(List list) {
	Pq pq;
	for (auto it = list.begin(); it != list.end(); ++it) {
		pq.push(*it);
	}
	return pq;
}

void print_pq(Pq pq) {
	List list = copy_pq_to_list(pq);
	for (auto it = list.cbegin(); it != list.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

Pair findMean(Pq& pq) {
	List list = copy_pq_to_list(pq);
	int count = 1;
	Pair sum = pq.top();
	pq.pop();
	while (!pq.empty()) {
		sum = sum + pq.top();
		pq.pop();
		count++;
	}
	pq = copy_list_to_pq(list);
	return sum / count;
}

void addMeanToPosition(Pq& pq, int pos) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_list(pq);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
	pq = copy_list_to_pq(list);
}

void deleteRange(Pq& pq) {
	Pair left, right;
	List list = copy_pq_to_list(pq);
	cout << "Введите левую границу диапазона: " << endl; 
	cin >> left;
	cout << "Введите правую границу диапазона: " << endl; 
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			i++;
	}
	pq = copy_list_to_pq(list);
}

void eachMinusMean(Pq& pq) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_list(pq);
	for (auto i = list.begin(); i != list.end(); ++i) {
		*i = *i - mean;
	}
	pq = copy_list_to_pq(list);
}


int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Pq pq;
	int size;
	cout << "Введите размер очереди: ";
	cin >> size;
	pq = make_pq(size);
	cout << "Очередь: ";
	print_pq(pq);
	cout << "Среднее арифметическое = " << findMean(pq) << endl;
	int pos;
	cout << endl << "Введите позицию для добавления среднего арифметического: ";
	cin >> pos;
	addMeanToPosition(pq, pos);
	cout << "Очередь после добавления: ";
	print_pq(pq);
	cout << endl << "Удаление элементов из указанного диапазона:" << endl;
	deleteRange(pq);
	cout << "Очередь после удаления элементов: ";
	print_pq(pq);
	cout << "Среднее арифметическое = " << findMean(pq) << endl;
	eachMinusMean(pq);
	cout << endl << "Очередь после удаления среднего арифметического из каждого элемента: " << endl;
	print_pq(pq);

	return 0;
}
