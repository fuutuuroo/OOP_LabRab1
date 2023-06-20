/* ������� 12. ������ 2
1.	��������� - map
2.	��� ��������� Pair (��. ������������ ������ �3).
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: �� ������� �������� ������� ������� �������������� ����������
 */

#include "Pair.h"
#include <ctime>
#include <map>

typedef map<int, Pair> Map;
typedef Map::iterator iter;
//�������� �������
Map makeMap(int size) {
	Map m;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		m.insert(make_pair(i, p));
	}
	return m;
}
//����� ������� � �������
void printMap(Map m) {
	for (iter it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
}
//����� �������� ���������������
Pair findMean(Map m) {
	Pair temp;
	int intSum = 0;
	double doubleSum = 0.0;
	int count = 0;
	for (iter it = m.begin(); it != m.end(); it++) {
		intSum = intSum + it->second.get_left();
		doubleSum = doubleSum + it->second.get_right();
		count++;
	}
	temp.set_left(intSum / count);
	temp.set_right(doubleSum / count);
	return temp;
}
//�������� ��������� �� ���������� ���������
void deleteRange(Map& m) {
	int left, right;
	cout << "������� ����� ������� ����� ����� ����: ";
	cin >> left;
	cout << "������� ������ ������� ����� ����� ����: ";
	cin >> right;
	for (iter it = m.begin(); it != m.end();) {
		if (left <= it->second.get_left() && it->second.get_left() <= right) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}
//��������� �������� ��������������� �� ������� ��������
void eachMinusMean(Map& m) {
	Pair mean = findMean(m);
	for (iter it = m.begin(); it != m.end(); it++) {
		it->second = it->second - mean;
	}
}


int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Map map;
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	map = makeMap(size);
	cout << "�������: " << endl;
	printMap(map);
	Pair mean = findMean(map);
	cout << "������� ��������������: " << mean << endl;

	map.insert(make_pair(size, mean));
	cout << "\n������� ����� ���������� �������� ���������������: " << endl;
	printMap(map);

	cout << endl << "������� �������� ��� �������� ���������: " << endl;
	deleteRange(map);
	cout << "������� ����� ��������: " << endl;
	printMap(map);
	cout << "������� ��������������: " << findMean(map) << endl;

	eachMinusMean(map);
	cout << "\n������� ����� ��������� �������� ��������������� �� ���������: " << endl;
	printMap(map);

	return 0;
}