/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
bool bigyear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	else
		return 0;
}
int days(int y, int m, int d)
{
	int days,a[13];
	a[0] = 0;
	a[1] = 31;//a[i]��ʾ1��i+1���¹��ж�����
	a[2] = 31 + 28+ bigyear(y);
	a[3] = 31 + 28 + bigyear(y) + 31;
	a[4] = 31 + 28 + bigyear(y) + 31 + 30;
	a[5] = 31 + 28 + bigyear(y) + 31 + 30 + 31;
	a[6] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30;
	a[7] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31;
	a[8] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31 + 31;
	a[9] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31 + 31 + 30;
	a[10] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 30;
	a[11] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
	a[12] = 31 + 28 + bigyear(y) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31;

	days = a[m - 1] + d;
	return days;
}
int main()
{
	int y, m, d;
	cout << "�������꣬�£���" << endl;
	cin >> y >> m >> d;
	
	if (m >= 1 && m <= 12)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d>31)
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			else
				cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << days(y, m, d) << "��" << endl;
		}
		else if (m == 2)
		{
			if (d < 1 || d>28 + bigyear(y))
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			else
				cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << days(y, m, d) << "��" << endl;
		}
		else
		{
			if (d < 1 || d>30)
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			else
				cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << days(y, m, d) << "��" << endl;
		}
	}
	else
		cout << "�������-�·ݲ���ȷ" << endl;
	return 0;
}