/* ������� 12. ������ 2.
��������� - ������
��� ��������� Pair (��. ������������ ������ �3).
������� ���������� � ������� � ������������.
������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: �� ������� �������� ������� ������� �������������� ����������.
*/

#include "Pair.h"
#include <list>
#include <ctime>
#include <queue>
#include <algorithm>

typedef list<Pair> List;
typedef priority_queue<Pair> Pq;
//�������� �������
Pq makePq(int size) {
	Pq temp;
	Pair p;
	for (int i = 0; i < size; i++) {
		p.set_randomPair();
		temp.push(p);
	}
	return temp;
}
//����������� ������ � ������
List copy_pq_to_lst(Pq pq) {
	List list;
	while (!pq.empty()) {
		list.push_back(pq.top());
		pq.pop();
	}
	return list;
}
//����������� ������ � �������
Pq copy_lst_to_pq(List list) {
	Pq pq;
	while (!list.empty()) {
		pq.push(list.back());
		list.pop_back();
	}
	return pq;
}
//����� ������� � �������
void print_pq(Pq pq) {
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
}
//����� �������� ��������������� 
Pair findMean(Pq pq) {
	List list = copy_pq_to_lst(pq);
	Pair sum;
	int count = 0;
	for_each(list.begin(), list.end(), [&sum](Pair& p) {
			sum = sum + p;
	});
	sum.set_left(sum.get_left() / list.size());
	sum.set_right(sum.get_right() / list.size());
	return sum;
}
//���������� �������� ��������������� � �������
void addMean(Pq& pq, int ind) {
	Pair mean = findMean(pq);
	List list = copy_pq_to_lst(pq);
	auto li = list.begin();
	advance(li, ind);
	list.insert(li, mean);
	pq = copy_lst_to_pq(list);
}
//�������� ��������� �� ���������� ���������
void deleteRange(Pq& pq) {
	List list = copy_pq_to_lst(pq);
	Pair first, second;
	cout << "\n������� ������ �������:\n";
	cin >> first;
	cout << "������� ������ �������:\n";
	cin >> second;
	if (first > second) {
		swap(first, second);
	}
	auto s = remove_if(list.begin(), list.end(), [first, second](Pair& p) {
		return p >= first && p <= second;
	});
	list.erase(s, list.end());
	pq = copy_lst_to_pq(list);
}
//��������� �������� ��������������� �� ������� ��������
void eachMinusMean(Pq& pq) {
	List list = copy_pq_to_lst(pq);
	Pair mean = findMean(pq);
	for_each(list.begin(), list.end(), [&mean](Pair& p) {p = p - mean; });
	pq = copy_lst_to_pq(list);
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	Pq pq;
	int size;
	cout << "������� ���������� ���������: ";
	cin >> size;
	pq = makePq(size);
	cout << "�������: " << endl;
	print_pq(pq);
	cout << "C������ ��������������: " << findMean(pq) << endl;
	
	addMean(pq, 0);	//������� � ����������� ������������� ����������� ��������, ������� ������� 0
	cout << "\n������� ����� ������� �������� ���������������: " << endl;
	print_pq(pq);

	cout << "�������� ���������: ";
	deleteRange(pq);
	cout << "\n������� ����� ��������: " << endl;
	print_pq(pq);
	cout << "C������ ��������������: " << findMean(pq) << endl;

	eachMinusMean(pq);
	cout << "\n������� ����� ��������� �������� ��������������� �� ���� ���������: " << endl;
	print_pq(pq);

	return 0;
}