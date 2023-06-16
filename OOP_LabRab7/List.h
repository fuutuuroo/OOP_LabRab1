#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node* pNext;
	Node(T data = T(), Node* pNext = nullptr) {
		this->data = data;
		this->pNext = pNext;
	}
};

template <typename T>
class List
{
private:
	int size;
	Node<T>* first;
	Node<T>* last;
public:
	List();
	List(int, T);
	List(const List<T>&);
	~List();
	void push_back(T&);
	void pop_front();
	//перегрузки операторов
	List<T>& operator = (const List<T>&);
	T& operator [] (int);
	int operator () ();
	void operator + (const int);
	//перегрузки операций ввода и вывода
	friend istream& operator >> (istream& in, List<T>& list) {
		int count;
		cout << "Введите размер списка: ";
		in >> count;
		cout << "Введите элементы списка через Enter: " << endl;
		for (int i = 0; i < count; i++) {
			T data;
			in >> data;
			list.push_back(data);
		}
		return in;
	}
	friend ostream& operator << (ostream& out, const List<T>& list) {
		if (list.first == nullptr) {
			cout << "Список пуст!" << endl;
			return out;
		}
		Node<T>* current = list.first;
		while (current != nullptr) {
			cout << '(' << current->data << ')' << " ";
			current = current->pNext;
		}
		cout << endl;
		return out;
	}
};