/*2151298 ��11 ������ */
#include <iostream>
using namespace std;
int main()
{
	int a[100] = { 0 }, i, j;
	for (i = 0; i < 100; i++)//�ӵ�һ���Ƶ���һ�ٸ���
	{
		for (j = 1; j <= 100; j++)//ÿһյ�Ƶ�1-100����
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