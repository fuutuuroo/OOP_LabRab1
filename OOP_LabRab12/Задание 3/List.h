#pragma once
#include <iostream>
#include <set>
#include <map>
using namespace std;

template <typename T>
class List
{
private:
	map<int, T> m;
	int size;
public:
	List();
	List(int);
	~List();
	void print();
	T findMean();
	void addMean();
	void deleteRange();
	void eachMinusMean();
};
//констуктор по умолчанию
template <typename T>
List<T>::List() {
	size = 0;
}
//конструктор с параметрами
template <typename T>
List<T>::List(int s) {
	T data;
	size = s;
	for (int i = 0; i < size; ++i) {
		cout << "¬ведите значение: ";
		cin >> data;
		m.insert(make_pair(i, data));
	}
}
//деструктор
template <typename T>
List<T>::~List() {}
//вывод списка в консоль
template <typename T>
void List<T>::print() {
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
}
//поиск среднего арифметического
template <typename T>
T List<T>::findMean() {
	T sum = 0;
	int count = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		sum = sum + it->second;
		count++;
	}
	T mean = sum / count;
	return mean;
}
//добавление среднего арифметического в консоль
template <typename T>
void List<T>::addMean() {
	T mean = findMean();
	m.insert(make_pair(size, mean));
}
//удаление элементов из указанного диапазона
template <typename T>
void List<T>::deleteRange() {
	T left, right;
	cout << "¬ведите левую границу диапазона: "; 
	cin >> left;
	cout << "¬ведите правую границу диапазона: "; 
	cin >> right;
	for (auto it = m.begin(); it != m.end();) {
		if (left <= it->second && it->second <= right) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}
//вычитание среднего арифметического из каждого элемента
template <typename T>
void List<T>::eachMinusMean() {
	T mean = findMean();
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second = it->second - mean;
	}
}