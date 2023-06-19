#include "List.h"

template <typename T>
List<T>::List() {
	size = 0;
}

template <typename T>
List<T>::List(int s) {
	T elem;
	size = s;
	for (int i = 0; i < size; i++) {
		cin >> elem;
		list.push_back(elem);
	}
}

template <typename T>
List<T>::~List() {}

template <typename T>
void List<T>::printList() {
	for (auto i = list.begin(); i != list.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
}

template <typename T>
T List<T>::listFindMean() {
	T sum;
	for (auto i = list.begin(); i != list.end(); i++) {
		sum = sum + *i;
	}
	return sum / size;
}

template<typename T>
void List<T>::addMeanToPosition(int pos) {
	T mean = listFindMean();
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
}

template <typename T>
void List<T>::deleteRange() {
	T left, right;
	cout << "¬ведите левую границу диапазона: " << endl;
	cin >> left;
	cout << "¬ведите правую границу диапазона: " << endl;
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			i++;
	}
}

template <typename T>
void List<T>::eachMinusMean() {
	T mean = listFindMean();
	for (auto i = list.begin(); i != list.end(); ++i) {
		*i = *i - mean;
	}
}