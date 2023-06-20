/* ������� 12. ������ 3.
��� ��������� Pair (��. ������������ ������ �3).
������������� ��������� ������� � �����������
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include "Pair.h"
#include <ctime>
#include <map>
#include <algorithm>

typedef multimap<int, Pair> Map;
//�������� �������
Map makeMap(int size) {
	Map temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.insert(make_pair(i, p));
	}
	return temp;
}
//����� ������� � �������
void printMap(Map map) {
	for (auto it : map) {
		cout << it.first << " : " << it.second << endl;
	}
}
//����� �������� ���������������
Pair findMean(Map map) {
	Pair sum;
	int count = 0;
	for (auto it : map) {
		sum = sum + it.second;
		count++;
	}
	Pair mean;
	mean.set_left(sum.get_left() / count);
	mean.set_right(sum.get_right() / count);
	return mean;
}
//���������� �������� ��������������� �� �������� �������
void addMean(Map& map, int pos) {
	Pair mean = findMean(map);
	map.insert(make_pair(pos, mean));
}
//�������� ��������� �� ���������� ���������
void deleteRange(Map& map) {
	int first, second;
	cout << "\n������� ������ ������� ������ ����� ����: ";
	cin >> first;
	cout << "������� ������ ������� ������ ����� ����: ";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	while (find_if(map.begin(), map.end(), [&first, &second](decltype(*map.begin())& it) -> bool {
		return it.second.get_left() >= first && it.second.get_left() <= second;
		}
	) != map.end())	{
		const auto it = find_if(map.begin(), map.end(), [&first, &second](decltype(*map.begin())& it) -> bool {
				return it.second.get_left() >= first && it.second.get_left() <= second;
			}
		);
		map.erase(it->first);
	}
}
//��������� �������� ��������������� �� ������� ��������
void eachMinusMean(Map& map) {
	Pair mean = findMean(map);
	for_each(map.begin(), map.end(), [mean] (pair<const int, Pair>& p) { p.second = p.second - mean; });	
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Map map;
	int size;
	cout << "������� ���������� ���������: ";
	cin >> size;
	map = makeMap(size);
	cout << "�������: " << endl;
	printMap(map);
	cout << "C������ ��������������: " << findMean(map) << endl;
	
	int ind;
	cout << "\n������� ������ ��� ������� �������� ���������������: ";
	cin >> ind;
	addMean(map, ind);				
	cout << "������� ����� ������� �������� ���������������: " << endl;
	printMap(map);

	cout << "\n�������� ���������: ";
	deleteRange(map);
	cout << "������� ����� ��������: " << endl;
	printMap(map);
	cout << "C������ ��������������: " << findMean(map) << endl;

	eachMinusMean(map);
	cout << "\n������� ����� ��������� �������� ��������������� �� ���� ���������: " << endl;
	printMap(map);

	return 0;
}