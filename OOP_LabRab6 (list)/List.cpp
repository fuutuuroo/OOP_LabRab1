#include <iostream>
#include "List.h"
using namespace std;
//конструктор по умолчанию
List::List() {
	size = 0;
	first = nullptr;
	last = nullptr;
}
//конструктор с параметрами
List::List(int s) {
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++) {
		int newData = rand() % 10;
		Node* addNode = new Node(newData);
		if (last == nullptr) {
			first = addNode;
			last = addNode;
		}
		else {
			last->pNext = addNode;
			last = addNode;
		}
	}
	begin.elem = first;
	end.elem = nullptr;
}
//конструктор копирования
List::List(const List& list) {
	size = 0;
	first = nullptr;
	last = nullptr;
	Node* current = list.first;
	while (current != nullptr) {
		Node* addNode = new Node();
		addNode->data = current->data;
		addNode->pNext = nullptr;
		if (last == nullptr) {
			first = addNode;
			last = addNode;
		}
		else {
			last->pNext = addNode;
			last = addNode;
		}
		current = current->pNext;
		size++;
	}
	begin = list.begin;
	end = list.end;
}
//деструктор
List::~List() {
	clear();
}
//функция для добавления элемента в конец списка
void List::push_back(int data) {
	if (first == nullptr) {
		first = new Node(data);
	}
	else {
		Node* current = this->first;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	size++;
}
//функция для удаления элемента из начала списка
void List::pop_front() {
	Node* temp = first;
	first = first->pNext;
	delete temp;
	size--;
}
//функция для удаления всех элементов списка
void List::clear() {
	while (size > 0) {
		pop_front();
	}
}
//перегрузка оператора присваивания
List& List::operator = (const List& other) {
	if (this == &other) {
		return *this; 
	}
	while (first != nullptr) {
		Node* temp = first;
		first = first->pNext;
		delete temp;
	}
	Node* currentOther = other.first;
	while (currentOther != nullptr) {
		push_back(currentOther->data);
		currentOther = currentOther->pNext;
	}
	return *this;
}
//перегрузка квадратных скобок
int& List::operator [] (int index) {
	int count = 0;
	Node* current = this->first;
	while (current != nullptr) {
		if (count == index) {
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}
//перегрузка круглых скобок
int List::operator () () {
	return size;
}
//перегрузка оператора сложения
void List::operator + (int add) {
	Node* current = this->first;
	while (current != nullptr) {
		current->data = current->data + add;
		current = current->pNext;
	}
}
//перегрузка операции ввода
istream& operator >> (istream& in, List& list) {
	int count;
	cout << "Введите количество элементов: ";
	in >> count;
	cout << "Введите значения: ";
	for (int i = 0; i < count; i++) {
		int data;
		in >> data;
		list.push_back(data);
	}
	return in;
}
//перегрузка операции вывода
ostream& operator << (ostream& out, const List& list) {
	if (list.first == nullptr) {
		cout << "Список пуст!" << endl;
		return out;
	}
	Node* current = list.first;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->pNext;
	}
	cout << endl;
	return out;
}