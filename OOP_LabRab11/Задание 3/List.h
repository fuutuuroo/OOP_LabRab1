#pragma once
#include <iostream>
#include <list>
using namespace std;

template <typename T>
class List
{
private:
	list<T> list;
	int size = list.size();
public:
	List();
	List(int);
	~List();
	void printList();
	T listFindMean();
	void addMeanToPosition(int);
	void deleteRange();
	void eachMinusMean();
};