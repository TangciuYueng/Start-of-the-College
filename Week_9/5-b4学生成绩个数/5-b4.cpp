/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
int main()
{
	const int N = 1001;
	int a[N] = { 0 }, i = 0, j = 0, k, t, sum;
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
		if ((j + 1) % 10 == 0|| j == i - 1)
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
	cout << "�����������Ķ�Ӧ��ϵΪ:" << endl;
	for (j = 0; j <= i - 1; j++)
	{
		sum = 1;
		if (a[i] == -2)
			continue;//�����ظ�
		for (k = j + 1; k > j && k <= i - 1; k++)
		{
			if (a[j] == a[k])
			{
				sum++;//��¼ͬ�ֵ��ж�����
				a[k] = -2;//�Ѻ�����ͬ��Ԫ�ض����-2�������ظ�
			}
		}
		if (sum >= 1 && a[j] >= 0)
			cout << a[j] << " " << sum << endl;
	}

	return 0;
}