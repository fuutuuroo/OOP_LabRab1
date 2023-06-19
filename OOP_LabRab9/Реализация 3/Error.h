#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error 
{
public:
	virtual void what() {};
};

class SizeError : public Error 
{
protected:
	string msg;
public:
	SizeError() { 
		msg = "Ошибка размера списка! "; 
	}
	virtual void what() { 
		cout << msg; 
	}
};

class MaxSizeError : public SizeError 
{
protected:
	string msg_;
public:
	MaxSizeError() { 
		SizeError(); 
		msg_ = "Размер списка больше максимального!\n"; 
	}
	virtual void what() { 
		cout << msg << msg_; 
	}
};

class EmptySizeError : public SizeError 
{
protected:
	string msg_;
public:
	EmptySizeError() { 
		SizeError(); 
		msg_ = "Список пустой!\n"; 
	}
	virtual void what() { 
		cout << msg << msg_; 
	}
};

class IndexError : public Error 
{
protected:
	string msg;
public:
	IndexError() { 
		msg = "Ошибка идекса! "; 
	}
	virtual void what() { 
		cout << msg; 
	}
};

class IndexErrorMin : public IndexError 
{
protected:
	string msg_;
public:
	IndexErrorMin() { 
		IndexError(); 
		msg_ = "Индекс меньше нуля!\n"; 
	}
	virtual void what() { 
		cout << msg << msg_; 
	}
};

class IndexErrorMax : public IndexError 
{
protected:
	string msg_;
public:
	IndexErrorMax() { 
		IndexError(); 
		msg_ = "Индекс за пределами списка!\n"; 
	}
	virtual void what() { 
		cout << msg << msg_; 
	}
};