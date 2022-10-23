/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
#define N 22
int main()
{
	int a[N] = { 0 }, i = 0, k, j, t;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	while (i <= 21)
	{
		while (i <= 20)
		{
			cin >> a[i];
			if (a[i] == -1)
				break;
			else if (a[i] <= 0)
				break;
			i++;
		}
		if (i+1 == 1||a[0]<=0)
		{
			cout << "无有效输入" << endl;
			break;
		}
		if (i+1 > 1 && i+1 <= 21)
		{
			cout << "原数组为：" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)
					cout << a[j] << " ";
			}
			cout << endl;
			/*插入一个数字到最后，冒泡法排序*/
			cout << "请输入要插入的正整数" << endl;
			cin >>a[N-1];
			for (j = 0; j < N - 1; j++)
			{
				for (k = 0; k < N - (j + 1); k++)
				{
					if (a[k] > a[k + 1])
					{
						t = a[k];
						a[k] = a[k + 1];
						a[k + 1] = t;
					}
				}
			}
			cout << "插入后的数组为：" << endl;
			for (j = 0; j <N; j++)
			{
				if (a[j] != -1 && a[j] != 0)//只输出正数！
					cout << a[j] << " ";
			}
			cout << endl;
			break;
		}
		if (i+1 > 21)
		{
			/*数组满了都是正数*/
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "原数组为：" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)
					cout << a[j] << " ";
			}
			cout << endl;
			/*插入一个数字到最后，冒泡法排序*/
			cout << "请输入要插入的正整数" << endl;
			cin >> a[N - 1];
			for (j = 0; j < N - 1; j++)
			{
				for (k = 0; k < N - (j + 1); k++)
				{
					if (a[k] > a[k + 1])
					{
						t = a[k];
						a[k] = a[k + 1];
						a[k + 1] = t;
					}
				}
			}
			cout << "插入后的数组为：" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)//只输出正数！
					cout << a[j] << " ";
			}
			cout << endl;
			break;
		}
		if (i + 1 > 21)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "原数组为：" << endl;

			cout << endl;
			break;

		}
	}
	return 0;
}
