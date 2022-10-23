/* 2151298 信11 杨滕超 */
#include <iostream>
#include <math.h>
using namespace std;
void f2(double a, double b, double c)
{
	if (fabs(a) >= 1e-6 && b * b - 4 * a * c >= 1e-6)
	{
		cout << "有两个不等实根：" << endl;
		if (a > 0)
		{
			cout << "x1=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
			cout << "x2=" << (-b - sqrt(b * b - 4 * a * c)) / 2 / a << endl;
		}
		else
		{
			cout << "x1=" << (-b - sqrt(b * b - 4 * a * c)) / 2 / a << endl;
			cout << "x2=" << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << endl;
		}

	}
}