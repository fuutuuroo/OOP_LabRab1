#include "List.h"
#include <iostream>
using namespace std;
//конструктор по умолчанию
template <typename T>
List<T>::List() {
	size = 0;
	first = nullptr;
	last = nullptr;
}
//конструктор с параметрами
template <typename T>
List<T>::List(int s, T d) {
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++) {
		Node<T>* addNode = new Node<T>;
		addNode->data = d;
		if (last == nullptr) {
			first = addNode;
			last = addNode;
		}
		else {
			last->pNext = addNode;
			last = addNode;
		}
	}
}
//конструктор копирования
template <typename T>
List<T>::List(const List<T>& L) {
	size = 0;
	first = nullptr;
	last = nullptr;
	Node<T>* current = L.first;
	while (current != nullptr) {
		Node<T>* addNode = new Node<T>();
		addNode->data = current->data;
		addNode->pNext = nullptr;
		if (last == nullptr) {
			first = addNode;
			last = addNode;
		}
		else {
			last->next = addNode;
			last = addNode;
		}
		current = current->next;
		size++;
	}
}
//деструктор
template <typename T>
List<T>::~List()
{
	while (size > 0) {
		pop_front();
	}
}
//функция для добавления элемента в конец списка
template <typename T>
void List<T>::push_back(T& d) {
	if (first == nullptr) {
		first = new Node<T>(d);
	}
	else {
		Node<T>* current = this->first;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(d);
	}
	size++;
}
//функция для удаления элемента из начала списка
template <typename T>
void List<T>::pop_front() {
	if (first == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}
	Node<T>* temp = first;
	first = first->pNext;
	delete temp;
	size--;
}
//перегрузка оператора присваивания
template <typename T>
List<T>& List<T>::operator = (const List<T>& other)
{
	if (this == &other) {
		return *this; 
	}

	while (first != nullptr) {
		Node<T>* temp = first;
		first = first->pNext;
		delete temp;
	}

	Node<T>* currentOther = other.first;
	while (currentOther != nullptr) {
		push_back(currentOther->data);
		currentOther = currentOther->pNext;
	}
	return *this;
}
//перегрузка квадратных скобок
template <typename T>
T& List<T>::operator [] (int index) {
	if (index >= 0 && index < size) {
		int count = 0;
		Node<T>* current = this->first;
		while (current != nullptr) {
			if (count == index) {
				return current->data;
			}
			current = current->pNext;
			count++;
		}
	}
	else {
		cout << "Некорректный индекс!" << endl;
	}
}
//перегрузка круглых скобок - получение размера списка
template <typename T>
int List<T>::operator() () {
	return size;
}
//перегрузка оператора сложения
template <typename T>
void List<T>::operator + (const int add) {
	Node<T>* current = this->first;
	while (current != nullptr) {
		current->data = current->data + add;
		current = current->pNext;
	}
}