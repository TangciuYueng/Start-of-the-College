/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	const int N = 1001;
	int a[N] = { 0 }, i = 0, j = 0, k, t, sum;
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	while (i <= 1000)
	{
		cin >> a[i];
		if (a[i] == -1)
			break;
		i++;
	}
	cout << "输入的数组为:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		cout << a[j] << " ";
		if ((j + 1) % 10 == 0|| j == i - 1)
			cout << endl;
	
	}
	for (k = 0; k <= i - 1; k++)//从大到小排序
	{
		for (j = 0; j < i - k - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}

		}
	}
	cout << "分数与人数的对应关系为:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		sum = 1;
		if (a[i] == -2)
			continue;//避免重复
		for (k = j + 1; k > j && k <= i - 1; k++)
		{
			if (a[j] == a[k])
			{
				sum++;//记录同分的有多少人
				a[k] = -2;//把后面相同的元素都变成-2，避免重复
			}
		}
		if (sum >= 1 && a[j] >= 0)
			cout << a[j] << " " << sum << endl;
	}

	return 0;
}