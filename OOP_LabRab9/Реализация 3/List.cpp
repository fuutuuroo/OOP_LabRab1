#include "List.h"
#include "Error.h"

//конструктор по умолчанию
List::List() {
	size = 0;
	first = nullptr;
	last = nullptr;
}
//конструктор с параметрами
List::List(int s) {
	if (s > MAX_SIZE) {
		throw MaxSizeError();		//обработка превышения максимального размера
	}
	size = s;
	first = nullptr;
	last = nullptr;
	for (int i = 0; i < size; i++) {
		int rnd = rand() % 10;
		Node* addNode = new Node(rnd);
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
}
//деструктор
List::~List() {
	while (size > 0) {
		pop_front();
	}
}
//функция для добавления элемента в конец списка
void List::push_back(int data) {
	if (size >= MAX_SIZE) {
		throw MaxSizeError();		//обработка превышения максимального размера
	}
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
	if (first == nullptr) {
		throw EmptySizeError();		//обработка случая с пустым списком
	}
	Node* temp = first;
	first = first->pNext;
	delete temp;
	size--;
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
	if (index < 0)
		throw IndexErrorMin();		//обработка индекса меньше нуля
	if (index >= size)
		throw IndexErrorMax();		//обработка индекса больше размера
	if (index >= 0 && index < size) {
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
}
//перегрузка круглых скобок - получение размера списка
int List::operator () () {
	return size;
}
//перегрузка оператора сложения
void List::operator + (const int add) {
	Node* current = this->first;
	while (current != nullptr) {
		current->data = current->data + add;
		current = current->pNext;
	}
}
//перегрузка инкремента
void List::operator ++ () {
	if (size >= MAX_SIZE) {
		throw MaxSizeError();			//обработка превышения максимального размера
	}
	if (first == nullptr) {
		first = new Node();
	}
	else {
		Node* current = this->first;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node();
	}
	size++;
}
//перегрузка операции ввода
istream& operator >> (istream& in, List& list) {
	int count;
	cout << "Введите размер списка: ";
	in >> count;
	cout << "Введите элементы списка через Enter: ";
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