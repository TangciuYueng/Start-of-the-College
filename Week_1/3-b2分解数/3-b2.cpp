/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	cout << "��λ : " << a / 10000 << endl;
	b = a / 10000 * 10000;
	cout << "ǧλ : " << (a - b) / 1000 << endl;
	c = (a - b) / 1000 * 1000;
	cout << "��λ : " << (a - b - c) / 100 << endl;
	d = (a - b - c) / 100 * 100;
	cout << "ʮλ : " << (a - b - c - d) / 10 << endl;
	e = (a - b - c - d) / 10 * 10;
	cout << "��λ : " << a - b - c - d - e << endl;
	return 0;
}