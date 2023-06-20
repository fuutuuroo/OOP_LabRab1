#include "Pair.h"
#include <string>
//функция для записи в файл
int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc); 
	if (!stream)
		return -1; 
	int n;
	Pair p;
	cout << "Введите количество экземпляров: "; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p; 
		stream << p << "\n"; 
	}
	stream.close();
	return n; 
}
//функция для печати файла
int print_file(const char* f_name) {
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Pair temp;
	int i = 0;
	while (stream >> temp)
	{
		cout << temp << "\n";
		i++;
	}
	stream.close();
	return i;
}
//удалить все записи большие заданного значения
int deletePairs(const char* f_name, int value) {
	fstream fromStream(f_name, ios::in);
	fstream inStream("temp", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p) {
		if (p.get_left() <= value && !fromStream.eof()) {
			inStream << p;
			i++;
		}
	}
	fromStream.close();
	inStream.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
//увеличить все записи с заданным значением на число L
int increasePairs(const char* f_name, int currentValue, int addValue) {
	fstream fromStream(f_name, ios::in);
	fstream inStream("temp", ios::out | ios::trunc);
	int i = 0;
	Pair p;
	while (fromStream >> p) {
		if (p.get_left() == currentValue && !fromStream.eof()) {
			p = p + addValue;
			i++;
		}
		inStream << p;
	}
	fromStream.close();
	inStream.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
//добавить K записей после записи с номером N
int add_file(const char* f_name, int k, Pair newPair) {
	fstream temp("temp", ios::out); 
	fstream stream(f_name, ios::in); 
	if (!stream)
		return -1; 
	Pair p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		temp << p;
		if (i == k)
		{
			temp << newPair; 
			l++;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l; 
}