/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;
int yanghui(int m, int n)
{
	if (n == 0 || n == m-1)
		return 1;
	else
		return (yanghui(m - 1, n - 1) + yanghui(m - 1, n));
}
void kongge(int r, int i)
{
	/*最后一行没有空格，每上一行多三个空格*/
	int geshu = 3 * (r - i);
	if (r == i)
		putchar(' ');
	else
	{
		putchar(' ');

		kongge(r, i + 1);

	}
	//cout << setfill('&') << setw(geshu);
}
int main()
{
	int r, tri[13][13] = { 0 }, i, j;
	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> r;
	for (i = 0; i <= r; i++)
	{
		for (j = 0; j < i; j++)
		{
			tri[i][j] = yanghui(i, j);
		}
	}

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "0         1         2         3         4         5         6         7" << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "--------------------------------------------------------------------------------" ;
	for (i = 0; i <= r; i++)
	{
		for (j = 0; j < i; j++)
		{
			cout << setw(6) << tri[i][j];
		}
		cout << endl;
	}

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4         5         6         7" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	cout << endl << endl;
	return 0;
}