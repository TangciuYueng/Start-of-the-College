/* 2151298 ��11 ������ */
#include <iostream>
#include <math.h>
using namespace std;
void f4(double a, double b, double c)
{
	if (fabs(a) >= 1e-6 && b * b - 4 * a * c < -1e-6)
	{
		cout << "�����������" << endl;
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