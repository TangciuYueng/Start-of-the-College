/* 2151298 信11 杨滕超 */
#include <iostream>
#include <math.h>
#include "4-b16.h"
using namespace std;
int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	f1(a, b, c);
	f2(a, b, c);
	f3(a, b, c);
	f4(a, b, c);
	return 0;
}