/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	cout << "万位 : " << a / 10000 << endl;
	b = a / 10000 * 10000;
	cout << "千位 : " << (a - b) / 1000 << endl;
	c = (a - b) / 1000 * 1000;
	cout << "百位 : " << (a - b - c) / 100 << endl;
	d = (a - b - c) / 100 * 100;
	cout << "十位 : " << (a - b - c - d) / 10 << endl;
	e = (a - b - c - d) / 10 * 10;
	cout << "个位 : " << a - b - c - d - e << endl;
	return 0;
}