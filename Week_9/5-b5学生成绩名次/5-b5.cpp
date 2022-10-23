/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	const int N = 1001;
	int a[N] = { 0 }, i = 0, j = 0, k, t, sum[N],mc[N];
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
		if ((j + 1) % 10 == 0 || j == i - 1)//十个换一行或者最后一个了也换一行
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
	cout << "分数与名次的对应关系为:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		mc[j] = j+1;
		if (a[j] == a[j - 1]&&j>=1)//若这个数等于前一个数，名次等于前一个的名次
			mc[j ] = mc[j-1];
		cout << a[j] << " " <<mc[j] << endl;
	}
	return 0;
}