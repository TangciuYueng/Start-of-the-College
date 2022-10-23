/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int min(int x, int y, int z = 2147483647, int w = 2147483647);//这样子int的最大值，不用判断是否存在，好；也可以0x7FFFFFFF？？；也可以<limits.h>INT_MAX
int min(int x,int y,int z,int w)
{
	int t;
	if (x > y)
		t = y;
	else
		t = x;
	if (t < z)
		t = t;
	else
		t = z;
	if (t < w)
		t = t;
	else
		t = w;
	return t;
}
int main()
{
	int num;

	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "请输入个数num及num个正整数：" << endl;
			cin >> num;
		}
		if (num == 2)
		{
			int x, y;
			cin >> x >> y;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65535, '\n');
				continue;
			}
			else
			{
				cout << "min=" << min(x, y) << endl;
				break;
			}
		}
		else if (num == 3)
		{
			int x, y, w;
			cin >> x >> y >> w;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65535, '\n');
				continue;
			}
			else
			{
				cout << "min=" << min(x, y, w) << endl;
				break;
			}
		}
		else if (num == 4)
		{
			int x, y, w, z;
			cin >> x >> y >> w >> z;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65535, '\n');
				continue;
			}
			else
			{
				cout << "min=" << min(x, y, w, z) << endl;
				break;
			}
		}
		else
		{
			cout << "个数输入错误" << endl;
			break;
		}


	}

	return 0;
}