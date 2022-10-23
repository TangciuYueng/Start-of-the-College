/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "十亿位 : " << (long long)a / 1000000000 << endl;
	cout << "亿位   : " << (long long)a % 1000000000 / 100000000 << endl;
	cout << "千万位 : " << (long long)a % 100000000 / 10000000 << endl;
	cout << "百万位 : " << (long long)a % 10000000 / 1000000<< endl;
	cout << "十万位 : " << (long long)a % 1000000 / 100000 << endl;
	cout << "万位   : " << (long long)a % 100000 / 10000 << endl;
	cout << "千位   : " << (long long)a % 10000 / 1000 << endl;
	cout << "百位   : " << (long long)a % 1000 / 100 << endl;
	cout << "十位   : " << (long long)a % 100 / 10 << endl;
	cout << "元     : " << (long long)a % 10 << endl;
	cout << "角     : " << int ((a - (long long)a) * 100.001) % 100 / 10 << endl;
	cout << "分     : " << int ((a - (long long)a) * 100.001) % 10 << endl;
	return 0; 
}
