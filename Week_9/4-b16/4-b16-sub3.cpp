/* 2151298 ��11 ������ */
#include <iostream>
#include <math.h>
using namespace std;
void f3(double a, double b, double c)
{
	if (fabs(a) >= 1e-6 && fabs(b * b - 4 * a * c) < 1e-6)
	{
		cout << "���������ʵ����" << endl;
		cout << "x1=x2=" <<fabs( -b / 2 / a) << endl;
	}
}