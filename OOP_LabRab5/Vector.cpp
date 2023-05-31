#include "Vector.h"
//конструктор без параметров 
Vector::Vector(void) {
	begin = 0;
	size = 0;
	cur = 0;
}
//деструктор 
Vector::~Vector(void) {
	if (begin != 0) {
		delete[] begin;
	}
	begin = 0;
}
//конструктор с параметрами 
Vector::Vector(int n) {
	begin = new Object* [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор 
void Vector::add(Object* p) {
	if (cur < size) {
		begin[cur] = p;
		cur++;
	}
}

//операци€ вывода
ostream& operator<<(ostream& out, const Vector& v) {
	if (v.size == 0) {
		out << "¬ектор пуст!" << endl;
	}
	Object** p = v.begin;//указатель на указатель типа Object 
	for (int i = 0; i < v.cur; i++) {
		(*p)->show();//вызов метода show() (позднее св€зывание) 
		p++;//передвигаем указатель на следующий объект
	}
	return out;
}
