/* ������� 12. ������ 1
1.	��������� - map
2.	��� ��������� - int
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: �� ������� �������� ������� ������� �������������� ����������
 */

#include <iostream>
#include <map>
#include <ctime>
using namespace std;

typedef map<int, int> Map;
typedef Map::iterator iter;
//�������� �������
Map makeMap(int size) {
	Map m;
	int data;
	for (int i = 0; i < size; i++) {
		data = rand() % 20;
		m.insert(make_pair(i, data));
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
int findMean(Map m) {
	int sum = 0;
	int count = 0;
	for (iter it = m.begin(); it != m.end(); it++) {
		sum = sum + it->second;
		count++;
	}
	return sum / count;
}
//�������� ��������� �� ���������� ���������
void deleteRange(Map& m) {
	int left, right;
	cout << "������� ����� �������: ";
	cin >> left;
	cout << "������� ������ �������: ";
	cin >> right;
	for (iter it = m.begin(); it != m.end();) {
		if (left <= it->second && it->second <= right) {
			m.erase(it++);
		}
		else {
			++it;
		}
	}
}
//��������� �������� ��������������� �� ������� ��������
void eachMinusMean(Map& m) {
	int mean = findMean(m);
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
	int mean = findMean(map);
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