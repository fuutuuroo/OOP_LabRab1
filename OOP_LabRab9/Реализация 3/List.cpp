#include "List.h"
#include "Error.h"

//����������� �� ���������
List::List() {
	size = 0;
	first = nullptr;
	last = nullptr;
}
//����������� � �����������
List::List(int s) {
	if (s > MAX_SIZE) {
		throw MaxSizeError();		//��������� ���������� ������������� �������
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
//����������� �����������
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
//����������
List::~List() {
	while (size > 0) {
		pop_front();
	}
}
//������� ��� ���������� �������� � ����� ������
void List::push_back(int data) {
	if (size >= MAX_SIZE) {
		throw MaxSizeError();		//��������� ���������� ������������� �������
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
//������� ��� �������� �������� �� ������ ������
void List::pop_front() {
	if (first == nullptr) {
		throw EmptySizeError();		//��������� ������ � ������ �������
	}
	Node* temp = first;
	first = first->pNext;
	delete temp;
	size--;
}
//���������� ��������� ������������
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
//���������� ���������� ������
int& List::operator [] (int index) {
	if (index < 0)
		throw IndexErrorMin();		//��������� ������� ������ ����
	if (index >= size)
		throw IndexErrorMax();		//��������� ������� ������ �������
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
//���������� ������� ������ - ��������� ������� ������
int List::operator () () {
	return size;
}
//���������� ��������� ��������
void List::operator + (const int add) {
	Node* current = this->first;
	while (current != nullptr) {
		current->data = current->data + add;
		current = current->pNext;
	}
}
//���������� ����������
void List::operator ++ () {
	if (size >= MAX_SIZE) {
		throw MaxSizeError();			//��������� ���������� ������������� �������
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
//���������� �������� �����
istream& operator >> (istream& in, List& list) {
	int count;
	cout << "������� ������ ������: ";
	in >> count;
	cout << "������� �������� ������ ����� Enter: ";
	for (int i = 0; i < count; i++) {
		int data;
		in >> data;
		list.push_back(data);
	}
	return in;
}
//���������� �������� ������
ostream& operator << (ostream& out, const List& list) {
	if (list.first == nullptr) {
		cout << "������ ����!" << endl;
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