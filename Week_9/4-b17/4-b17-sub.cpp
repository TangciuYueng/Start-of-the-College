/* 2151298 信11 杨滕超 */
#include <iostream>
#include <math.h>
using namespace std;
extern double a, b, c;
void f1()
{
	if (fabs(a) < 1e-6)
		cout << "不是一元二次方程" << endl;
}
void f2()
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
void f3()
{
	if (fabs(a) >= 1e-6 && fabs(b * b - 4 * a * c) < 1e-6)
	{
		cout << "有两个相等实根：" << endl;
		cout << "x1=x2=" << fabs(-b / 2 / a) << endl;
	}
}
void f4()
{
	if (fabs(a) >= 1e-6 && b * b - 4 * a * c < -1e-6)
	{
		cout << "有两个虚根：" << endl;
		if (fabs(-b / 2 / a) < 1e-6)
		{
			if (fabs(sqrt(4 * a * c - b * b) / 2 / a) == 1)
			{
				cout << "x1="  << "i" << endl;
				cout << "x2="  << "-i" << endl;
			}
			else
			{
				cout << "x1=" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
				cout << "x2=" << -fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
			}
			
		}
		else
		{
			if (fabs(sqrt(4 * a * c - b * b) / 2 / a) == 1)
			{
				cout << "x1=" << -b / 2 / a << "+" << "i" << endl;
				cout << "x2=" << -b / 2 / a << "-" << "i" << endl;
			}
			else 
			{
				cout << "x1=" << -b / 2 / a << "+" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
				cout << "x2=" << -b / 2 / a << "-" << fabs(sqrt(4 * a * c - b * b) / 2 / a) << "i" << endl;
			}
			
		}
	}
}