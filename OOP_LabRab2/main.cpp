/* ������� 12
���������������� ����� ��������� ����� �  int
���� � string ����� � double
*/

#include "Receipt.h"
//������� ��� �������� ������� ��� ����������
Receipt makeReceipt() {
	int num;
	string date;
	double sum;
	cout << "������� ����� ���������: " << endl;
	cin >> num;
	cout << "������� ����: " << endl;
	cin >> date;
	cout << "������� �����: " << endl;
	cin >> sum;
	Receipt temp(num, date, sum);
	return temp;	
}
//������� ��� �������� �������, ��� ���������
void printReceipt(Receipt r) {
	r.show();
}

int main() {
	setlocale(LC_ALL, "RU");
	//����������� ��� ����������
	Receipt r1;
	cout << "��������� � 1: " << endl;
	r1.show();
	//����������� � �����������
	Receipt r2(2000222, "02/02/2022", 378.55);
	cout << "\n��������� � 2: " << endl;
	r2.show();
	//����������� �����������
	Receipt r3 = r2;
	//��������� ����� ���������
	r3.set_number(1000055);
	r3.set_date("05/05/2005");
	r3.set_sum(2777.44);
	cout << "\n��������� � 3: " << endl;
	r3.show();
	//������� ��� ��������
	r1 = makeReceipt();
	cout << "\n��������� � 4" << endl;
	printReceipt(r1);
	cout << endl;

	return 0;
}