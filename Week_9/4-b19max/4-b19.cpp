/* 2151298 ��11 ������ */
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
		cout << "���������num��num����������" << endl;
		cin >> num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(65535, '\n');
			cout << "���������num��num����������" << endl;
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
			cout << "�����������" << endl;
			break;
		}
	}

	return 0;
}