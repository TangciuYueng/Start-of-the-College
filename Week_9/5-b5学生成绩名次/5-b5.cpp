/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
int main()
{
	const int N = 1001;
	int a[N] = { 0 }, i = 0, j = 0, k, t, sum[N],mc[N];
	cout << "������ɼ������1000��������-1����" << endl;
	while (i <= 1000)
	{
		cin >> a[i];
		if (a[i] == -1)
			break;
		i++;
	}
	cout << "���������Ϊ:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		cout << a[j] << " ";
		if ((j + 1) % 10 == 0 || j == i - 1)//ʮ����һ�л������һ����Ҳ��һ��
			cout << endl;

	}

	for (k = 0; k <= i - 1; k++)//�Ӵ�С����
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
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		mc[j] = j+1;
		if (a[j] == a[j - 1]&&j>=1)//�����������ǰһ���������ε���ǰһ��������
			mc[j ] = mc[j-1];
		cout << a[j] << " " <<mc[j] << endl;
	}
	return 0;
}