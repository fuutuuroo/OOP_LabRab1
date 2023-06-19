#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 5;

class Node
{
public:
	int data = 0;
	Node* pNext = nullptr;
	Node(int data = 0, Node* pNext = nullptr) {
		this->data = data;
		this->pNext = pNext;
	}
};

class List
{
private:
	int size;
	Node* first;
	Node* last;

public:
	List();
	List(int);
	List(const List&);
	~List();
	void push_back(int);
	void pop_front();
	List& operator = (const List&);
	int& operator [] (int);
	int operator () ();
	void operator + (const int);
	void operator ++ ();
	friend istream& operator >> (istream&, List&);
	friend ostream& operator << (ostream&, const List&);
};
