#include "Pair.h"
//���������� �������� �����
istream& operator >> (istream& in, Pair& p) {
	cout << "������� ����� �����: ";
	in >> p.left;
	cout << "������� ������ �����: ";
	in >> p.right;
	return in;
}
//���������� �������� ������
ostream& operator << (ostream& out, const Pair& p) {
	return (out << p.left << ":" << p.right) << endl;
}
//���������� �������� ���������
void Pair::operator < (const Pair& p) {
	if ((this->left < p.left) || (this->left == p.left && this->right < p.right)) {
		cout << "������ ���� ����� ������, ��� ������ ����" << endl;
	}
	else {
		cout << "������ ���� ����� �� ������, ��� ������ ����" << endl;
	}

}
void Pair::operator > (const Pair& p) {
	if ((this->left > p.left) || (this->left == p.left && this->right > p.right)) {
		cout << "������ ���� ����� ������, ��� ������ ����" << endl;
	}
	else {
		cout << "������ ���� ����� �� ������, ��� ������ ����" << endl;
	}
}
