#pragma once
#include <list>
#include <queue>
#include <iostream>
using namespace std;


template <typename T>
class List {
	priority_queue<T> pq;
	int size = pq.size();
public:
	List(int n);
	~List() {};
	void add(T);
	void print();	
	T findMean();
	void addMean();
	void deleteRange(int, int);
	void eachMinusMean();
};

template <typename T>
priority_queue<T> copy_list_to_pq(list<T> list) {
	priority_queue<T> pq;
	for (auto it = list.begin(); it != list.end(); ++it) {
		pq.push(*it);
	}
	return pq;
}

template <typename T>
list<T> copy_pq_to_list(priority_queue<T> pq) {
	list<T> list;
	while (!pq.empty()) {
		list.push_back(pq.top());
		pq.pop();
	}
	return list;
}

template <typename T>
void List<T>::add(T data) {
	pq.push(data);
}

template <typename T>
List<T>::List(int s) {
	T elem;
	size = s;
	cout << "Введите значения через Enter: \n";
	for (int i = 0; i < size; ++i) {
		cin >> elem;
		this->add(elem);
	}
}

template <typename T>
void List<T>::print() {
	list<T> list = copy_pq_to_list(pq);
	for (auto it = list.begin(); it != list.end(); ++it) {
		cout << *it << " ";
	}
}

template <typename T>
T List<T>::findMean() {
	T sum{};
	list<T> list = copy_pq_to_list(pq);
	for (auto it = list.begin(); it != list.end(); ++it) {
		sum = sum + *it;
	}
	T mean = sum / list.size();
	pq = copy_list_to_pq(list); 
	cout << "\nСреднее арифметическое списка: " << mean << endl;
	return mean;
}

template<typename T>
void List<T>::addMean() {
	T mean = findMean();
	this->add(mean);
}

template <typename T>
void List<T>::deleteRange(int left, int right) {
	list<T> list = copy_pq_to_list(pq);
	for (auto it = list.begin(); it != list.end();) {
		if (*it >= left && *it <= right)
			it = list.erase(it);
		else
			it++;
	}
	pq = copy_list_to_pq(list);
}


template <typename T>
void List<T>::eachMinusMean() {
	T mean = findMean();
	list<T> list = copy_pq_to_list(pq);
	for (auto it = list.begin(); it != list.end(); ++it) {
		*it = *it - mean;
	}
	pq = copy_list_to_pq(list);
}
