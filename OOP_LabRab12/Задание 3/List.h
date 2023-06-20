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
//���������� �� ���������
template <typename T>
List<T>::List() {
	size = 0;
}
//����������� � �����������
template <typename T>
List<T>::List(int s) {
	T data;
	size = s;
	for (int i = 0; i < size; ++i) {
		cout << "������� ��������: ";
		cin >> data;
		m.insert(make_pair(i, data));
	}
}
//����������
template <typename T>
List<T>::~List() {}
//����� ������ � �������
template <typename T>
void List<T>::print() {
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
}
//����� �������� ���������������
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
//���������� �������� ��������������� � �������
template <typename T>
void List<T>::addMean() {
	T mean = findMean();
	m.insert(make_pair(size, mean));
}
//�������� ��������� �� ���������� ���������
template <typename T>
void List<T>::deleteRange() {
	T left, right;
	cout << "������� ����� ������� ���������: "; 
	cin >> left;
	cout << "������� ������ ������� ���������: "; 
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
//��������� �������� ��������������� �� ������� ��������
template <typename T>
void List<T>::eachMinusMean() {
	T mean = findMean();
	for (auto it = m.begin(); it != m.end(); it++) {
		it->second = it->second - mean;
	}
}