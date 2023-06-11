/* ¬ариант 12
ѕоле first Ц целое положительное число, продолжительность телефонного разговора в минутах, 
поле second Ц дробное положительное число, стоимость одной минуты разговора в рубл€х. 
–еализовать метод cost() Ц вычисление общей стоимости разговора
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
	cout << "\n—тоимость разговора равна: " << example.cost() << endl;

	return 0;
}