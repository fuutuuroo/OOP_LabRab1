/* ������� 12. ������ 1. 
1.	��������� - ������
2.	��� ��������� - int
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
3������ 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include <iostream>
#include <list>
#include <ctime>
using namespace std;

typedef list<int> List;

List makeList(int size) {
	List temp;
	for (int i = 0; i < size; i++) {
		int e = (rand() % 20);
		temp.push_back(e);
	}
	return temp;
}

void printList(List& list) {
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

int listFindMean(List& list) {
	int sum = 0;
	for (auto i = list.begin(); i != list.end(); ++i) {
		sum += *i;
	}
	return sum / list.size();
}

void addMeanToPosition(List& list, int pos) {
	int mean = listFindMean(list);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
}

void deleteRange(List& list) {
	int left, right;
	cout << "������� ����� ������� ���������: "; 
	cin >> left;
	cout << "������� ������ ������� ���������: "; 
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			++i;
	}
}

void eachMinusMean(List& list) {
	int mean = listFindMean(list);
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
	cout << endl << "������ ����� �������� �������� ��������������� �� ������� ��������: ";
	printList(list);

	return 0;
}