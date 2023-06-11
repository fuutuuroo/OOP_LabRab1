#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int data;		//данные
	Node* pNext;	//указатель на следующий узел	
};

class Stack
{
private:
	int size;		//размер стека
	Node* top;		//указатель на вершину стека
public:
	Stack();
	Stack(int, int);
	Stack(const Stack&);
	~Stack();
	void push(int);	//функция для добавления элемента в стек
	void pop();		//функция для удаления элемента из стека
	//перегрузки операторов
	Stack& operator = (const Stack&);
	int& operator [] (int);
	int operator () ();
	void operator + (int); 
	friend istream& operator >> (istream&, Stack&);
	friend ostream& operator << (ostream&, const Stack&);
};
