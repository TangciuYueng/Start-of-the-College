/* 2151298 信11 杨滕超 */
#include <iostream>
#include <math.h>
using namespace std;
void f1(double a, double b, double c);
void f2(double a, double b, double c);
void f3(double a, double b, double c);
void f4(double a, double b, double c);
void f1(double a,double b,double c)
{
	if (fabs(a) < 1e-6)
		cout << "不是一元二次方程" << endl;
}
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
void f3(double a, double b, double c)
{
	if (fabs(a) >=1e-6 && fabs(b * b - 4 * a * c) < 1e-6)
	{
		cout << "有两个相等实根：" << endl;
		cout << "x1=x2=" <<fabs( -b / 2 / a )<< endl;
	}
}
void f4(double a, double b, double c)
{
	if (fabs(a) >= 1e-6 && b * b - 4 * a * c < -1e-6)
	{
		cout << "有两个虚根：" << endl;
		if (fabs(-b / 2 / a) < 1e-6)
		{
			if (fabs(sqrt(4 * a * c - b * b) / 2 / a) == 1)
			{
				cout << "x1=" << "i" << endl;
				cout << "x2=" << "-i" << endl;
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