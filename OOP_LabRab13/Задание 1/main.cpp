/* ������� 12. ������ 1.
1. ��������� - ������
2. ��� ��������� Pair (��. ������������ ������ �3).
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include "Pair.h"
#include <list>
#include <ctime>
#include <algorithm>

typedef list<Pair> List;
//�������� ������
List makeList(int size) {
	List temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push_back(p);
	}
	return temp;
}
//����� ������ � �������
void printList(List list) {
	for (auto i : list) {
		cout << i << endl;
	}
}
//����� �������� ��������������� 
Pair findMean(List list) {
	Pair sum;
	int count = 0;
	for_each(list.begin(), list.end(), [&sum] (Pair& p)
		{
			sum = sum + p;
		}
	);
	sum.set_left(sum.get_left() / list.size());
	sum.set_right(sum.get_right() / list.size());
	return sum;
}
//���������� �������� ��������������� � �������
void addMean(List& list, int ind) {
	Pair mean = findMean(list);
	auto li = list.begin();
	advance(li, ind);
	list.insert(li, mean);
}
//�������� ��������� �� ���������� ���������
void deleteRange(List& list) {
	Pair first, second;
	cout << "\n������� ������ �������:\n";
	cin >> first;
	cout << "������� ������ �������:\n";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	auto s = remove_if(list.begin(), list.end(), [first, second] (Pair& p) {
			return p >= first && p <= second;
		}
	);
	list.erase(s, list.end());
}
//��������� �������� ��������������� �� ������� ��������
void eachMinusMean(List& list) {
	Pair mean = findMean(list);
	for_each(list.begin(), list.end(), [&mean] (Pair& p) {p = p - mean; });
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	List list;
	int size;
	cout << "������� ���������� ���������: ";
	cin >> size;
	list = makeList(size);
	cout << "C�����: " << endl;
	printList(list);
	
	cout << "C������ ��������������: " << findMean(list) << endl;
	int ind;
	cout << "\n������� ������ ��� ������� �������� ���������������: ";
	cin >> ind;

	addMean(list, ind);
	cout << "C����� ����� ������� �������� ���������������: " << endl;
	printList(list);

	cout << "\n�������� ���������: ";
	deleteRange(list);
	cout << "\nC����� ����� ��������: " << endl;
	printList(list);
	cout << "C������ ��������������: " << findMean(list) << endl;

	eachMinusMean(list);
	cout << "\nC����� ����� ��������� �������� ��������������� �� ���� ���������: " << endl;
	printList(list);

	return 0;
}