/*2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	int a[100] = { 0 }, i, j;
	for (i = 0; i < 100; i++)//从第一个灯到第一百个灯
	{
		for (j = 1; j <= 100; j++)//每一盏灯的1-100个人
		{
			if ((i+1) % j == 0)
			{
				if (a[i] == 0)
					a[i] = 1;
				else
					a[i] = 0;
			
			}
		}
	}
	cout << "1";
	for (i = 0; i < 100; i++)
	{
		if (a[i] == 1 && i != 0)
			cout << " " << i+1;
	}
	cout << endl;
	return 0;
}