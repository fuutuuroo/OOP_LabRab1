/* ������� 12
���� first � ����� ������������� �����, ����������������� ����������� ��������� � �������, 
���� second � ������� ������������� �����, ��������� ����� ������ ��������� � ������. 
����������� ����� cost() � ���������� ����� ��������� ���������
*/
#include "PhoneCost.h"

PhoneCost makePhoneCost(int x, double y) {
	PhoneCost temp;
	temp.Init(x, y);
	return temp;
}

int main() {
	setlocale(LC_ALL, "RU");
	PhoneCost example = makePhoneCost(12, 2.5);
	example.Show();
	example.Read();
	example.Show();
	cout << "\n��������� ��������� �����: " << example.cost() << endl;

	return 0;
}