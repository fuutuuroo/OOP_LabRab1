/* ������� 12. ������ 2.
1.	��������� - ������
2.	��� ��������� Pair (��. ������������ ������ �3).
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
3������ 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include "Pair.h"
#include <list>
#include <ctime>

typedef list<Pair> List;

List makeList(int size) {
	List temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push_back(p);
	}
	return temp;
}

void printList(List& list) {
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

Pair listFindMean(List& list) {
	Pair sum;
	for (auto i = list.begin(); i != list.end(); ++i) {
		sum = sum + *i;
	}
	return sum / list.size();
}

void addMeanToPosition(List& list, int pos) {
	Pair mean = listFindMean(list);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
}

void deleteRange(List& list) {
	Pair left, right;
	cout << "������� ����� ������� ���������: " << endl;
	cin >> left;
	cout << "������� ������ ������� ���������: " << endl;
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			++i;
	}
}

void eachMinusMean(List& list) {
	Pair mean = listFindMean(list);
	for (auto i = list.begin(); i != list.end(); ++i) {
		*i = *i - mean;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	List list;
	int size;
	cout << "������� ������ ������: ";
	cin >> size;
	list = makeList(size);
	cout << "C�����: ";
	printList(list);
	cout << "������� �������������� = " << listFindMean(list) << endl;
	int pos;
	cout << endl << "������� ������� ��� ���������� �������� ���������������: ";
	cin >> pos;
	addMeanToPosition(list, pos);
	cout << "C����� ����� ����������: ";
	printList(list);
	cout << endl << "�������� ��������� �� ���������� ���������:" << endl;
	deleteRange(list);
	cout << "������ ����� �������� ���������: ";
	printList(list);
	cout << "������� �������������� = " << listFindMean(list) << endl;
	eachMinusMean(list);
	cout << endl << "������ ����� �������� �������� ��������������� �� ������� ��������: " << endl;
	printList(list);

	return 0;
}
