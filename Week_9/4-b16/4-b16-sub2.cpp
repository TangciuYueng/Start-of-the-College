/* 2151298 ��11 ������ */
#include <iostream>
#include <math.h>
using namespace std;
void f2(double a, double b, double c)
{
	if (fabs(a) >= 1e-6 && b * b - 4 * a * c >= 1e-6)
	{
		cout << "����������ʵ����" << endl;
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