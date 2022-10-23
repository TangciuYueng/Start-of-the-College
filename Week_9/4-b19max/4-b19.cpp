/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int max(int x, int y, int z)
{
	return max(x, y) > z ? max(x, y) : z;
}
int max(int x, int y, int z, int w)
{
	return max(x, y, z) > w ? max(x, y, z) : w;
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
				cout << "max=" << max(x, y)<<endl;
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
				cout << "max=" << max(x, y, w)<<endl;
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
				cout << "max=" << max(x, y, w, z) << endl;
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