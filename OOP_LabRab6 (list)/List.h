#pragma once
#include <iostream>
using namespace std;

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

class Iterator
{
private:
	friend class List;
	Node* elem;
public:
	Iterator() { elem = nullptr; } 
	Iterator(const Iterator& it) { elem = it.elem; } 
	int& operator * () const { return elem->data; }
	void operator ++ () { elem = elem->pNext; };
	void operator ++ (int) { elem = elem->pNext; };
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }

};

class List
{
private:
	int size;
	Node* first;
	Node* last;
	Iterator begin;
	Iterator end;
public:
	List();
	List(int);
	List(const List&);
	~List();
	void push_back(int); 
	void pop_front();
	void clear();
	List& operator = (const List&);
	int& operator [] (int);
	int operator () (); 
	void operator + (int); 
	friend istream& operator >> (istream&, List&);
	friend ostream& operator << (ostream&, const List&);
	Iterator iFirst() { return begin; }
	Iterator iLast() { return end; }

};
