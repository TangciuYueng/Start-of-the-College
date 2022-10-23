/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
void calendar(int y, int m, int w);
int zeller(int y, int m, int d=1)
{
	int w = 0, c = 0;
	if (m >= 3) {
		c = y / 100;
		y = y - c * 100;
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	}
	if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 12 + 1) / 5 + d - 1;
	}

	if (w >= 0)
		w = w % 7;
	else {
		while (w < 0) {
			w = w + 7;
		}
		w = w % 7;
	}


	return w;
}/*1是否写死？*/
void calendar(int y,int m,int w)
{
	int i=0, j, sum;
	
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			i = 31;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		if (m == 4 || m == 6 || m == 9 || m == 11)
			i = 30;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		if (m == 2)
			i = 29;//闰年的
	
	
	if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			i = 31;
	if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
		if (m == 4 || m == 6 || m == 9 || m == 11)
			i = 30;
	if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
		if (m == 2)
			i = 28;//平年的
	j = 2;

	cout << endl;
	cout << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	if (w == 0) {
		cout << setw(4) << "1";
		sum = 1;
	}

	else if (w == 1) {
		cout << setw(12) << "1";
		sum = 2;
	}

	else if (w == 2) {
		cout << setw(20) << "1";
		sum = 3;
	}
	else if (w == 3) {
		cout << setw(28) << "1";
		sum = 4;
	}
	else if (w == 4) {
		cout << setw(36) << "1";
		sum = 5;
	}
	else if (w == 5) {
		cout << setw(44) << "1";
		sum = 6;
	}
	else {
		cout << setw(52) << "1";
		sum = 7;
	}

	while (j <= i) {
		if (sum % 7 == 0) {
			cout << "    " << endl;
			cout << setw(4) << j;
		}
		else
			cout << setw(8) << j;

		sum = sum + 1;
		j++;
	}
	cout <<"    " << endl;
	
}
int main()
{
	int y, m,d,w;
	cout << "请输入年[1900-2100]、月" << endl;
	cin >> y >> m;
	while (1) 
	{
		while (cin.fail()  )
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月" << endl;
			cin >> y >> m;
		}
		if (y < 1900 || y>2100) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "年份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月" << endl;
			cin >> y >> m;
		}
		if (y >= 1900 && y <= 2100) {
			while (cin.fail() || m < 1 || m>12)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
				cout << "月份不正确，请重新输入" << endl;
				cout << "请输入年[1900-2100]、月" << endl;
				cin >> y >> m;
			}
			if (m >= 1 && m <= 12)
				break;
		}

	}

	w = zeller(y, m);
	calendar(y, m, w);
	cout << endl;
	return 0;
}
