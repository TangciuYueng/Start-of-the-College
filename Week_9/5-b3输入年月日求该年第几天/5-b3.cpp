/* 2151298 信11 杨滕超 */
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
	a[1] = 31;//a[i]表示1到i+1个月共有多少天
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
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	
	if (m >= 1 && m <= 12)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 1 || d>31)
				cout << "输入错误-日与月的关系非法" << endl;
			else
				cout << y << "-" << m << "-" << d << "是" << y << "年的第" << days(y, m, d) << "天" << endl;
		}
		else if (m == 2)
		{
			if (d < 1 || d>28 + bigyear(y))
				cout << "输入错误-日与月的关系非法" << endl;
			else
				cout << y << "-" << m << "-" << d << "是" << y << "年的第" << days(y, m, d) << "天" << endl;
		}
		else
		{
			if (d < 1 || d>30)
				cout << "输入错误-日与月的关系非法" << endl;
			else
				cout << y << "-" << m << "-" << d << "是" << y << "年的第" << days(y, m, d) << "天" << endl;
		}
	}
	else
		cout << "输入错误-月份不正确" << endl;
	return 0;
}