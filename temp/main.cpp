/* ������� 12. ������ 4.
��������� - ������
��� ��������� Pair (��. ������������ ������ �3).
������� ���������� � ������� � ������������.
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
3������ 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include "Pair.h"
#include <list>
#include <queue>
#include <ctime>

typedef priority_queue<Pair> Pq;
typedef list<Pair> List;

Pq make_pq(int size) {
	Pq temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		cin >> p;
		temp.push(p);
	}
	return temp;
}

List copy_pq_to_list(Pq pq) {
	List list;
	while (!pq.empty()) {
		list.push_back(pq.top());
		pq.pop();
	}
	return list;
}

Pq copy_list_to_pq(List list) {
	Pq pq;
	for (auto it = list.begin(); it != list.end(); ++it) {
		pq.push(*it);
	}
	return pq;
}

void print_pq(Pq pq) {
	List list = copy_pq_to_list(pq);
	for (auto it = list.cbegin(); it != list.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

Pair findMean(Pq& pq) {
	List list = copy_pq_to_list(pq);
	int count = 1;
	Pair sum = pq.top();
	pq.pop();
	while (!pq.empty()) {
		sum = sum + pq.top();
		pq.pop();
		count++;
	}
	pq = copy_list_to_pq(list);
	return sum / count;
}

void addMeanToPosition(Pq& pq, int pos) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_list(pq);
	auto i = list.begin();
	for (int j = 0; j < pos - 1; j++) {
		i++;
	}
	list.insert(i, mean);
	pq = copy_list_to_pq(list);
}

void deleteRange(Pq& pq) {
	Pair left, right;
	List list = copy_pq_to_list(pq);
	cout << "������� ����� ������� ���������: " << endl; 
	cin >> left;
	cout << "������� ������ ������� ���������: " << endl; 
	cin >> right;
	for (auto i = list.begin(); i != list.end();) {
		if (*i >= left && *i <= right)
			i = list.erase(i);
		else
			i++;
	}
	pq = copy_list_to_pq(list);
}

void eachMinusMean(Pq& pq) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_list(pq);
	for (auto i = list.begin(); i != list.end(); ++i) {
		*i = *i - mean;
	}
	pq = copy_list_to_pq(list);
}


int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Pq pq;
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	pq = make_pq(size);
	cout << "�������: ";
	print_pq(pq);
	cout << "������� �������������� = " << findMean(pq) << endl;
	int pos;
	cout << endl << "������� ������� ��� ���������� �������� ���������������: ";
	cin >> pos;
	addMeanToPosition(pq, pos);
	cout << "������� ����� ����������: ";
	print_pq(pq);
	cout << endl << "�������� ��������� �� ���������� ���������:" << endl;
	deleteRange(pq);
	cout << "������� ����� �������� ���������: ";
	print_pq(pq);
	cout << "������� �������������� = " << findMean(pq) << endl;
	eachMinusMean(pq);
	cout << endl << "������� ����� �������� �������� ��������������� �� ������� ��������: " << endl;
	print_pq(pq);

	return 0;
}
