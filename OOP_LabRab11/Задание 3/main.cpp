/* ������� 12. ������ 3.
��� ��������� Pair (��. ������������ ������ �3).
������������������� ����� � ������ (��. ������������ ������ �7)

������� 1: ����� ������� �������������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� ������� �� ��������� ��������� � ������� �� �� ����������
3������ 3: �� ������� �������� ������� ������� �������������� ����������.
*/


#include <iostream>
#include "Pair.h"
#include "List.h"
#include "List.cpp"

int main() {
	setlocale(LC_ALL, "rus");

	int size;
	cout << "������� ������ ������: ";
	cin >> size;
	cout << "������� �������� ������ ����� Enter:" << endl;
	List<Pair> list(size);
	cout << "C�����: ";
	list.printList();
	cout << "������� �������������� = " << list.listFindMean() << endl;
	int pos;
	cout << endl << "������� ������� ��� ���������� �������� ���������������: ";
	cin >> pos;
	list.addMeanToPosition(pos);
	cout << "C����� ����� ����������: ";
	list.printList();
	cout << endl << "������� �������� ��� �������� ���������:" << endl;
	list.deleteRange();
	cout << "������ ����� �������� ���������: ";
	list.printList();
	cout << "������� �������������� = " << list.listFindMean() << endl;
	list.eachMinusMean();
	cout << endl << "������ ����� �������� �������� ��������������� �� ������� ��������: " << endl;
	list.printList();

	return 0;
}