/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
#define N 22
int main()
{
	int a[N] = { 0 }, i = 0, k, j, t;
	cout << "��������������������������20��������-1����" << endl;
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
			cout << "����Ч����" << endl;
			break;
		}
		if (i+1 > 1 && i+1 <= 21)
		{
			cout << "ԭ����Ϊ��" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)
					cout << a[j] << " ";
			}
			cout << endl;
			/*����һ�����ֵ����ð�ݷ�����*/
			cout << "������Ҫ�����������" << endl;
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
			cout << "����������Ϊ��" << endl;
			for (j = 0; j <N; j++)
			{
				if (a[j] != -1 && a[j] != 0)//ֻ���������
					cout << a[j] << " ";
			}
			cout << endl;
			break;
		}
		if (i+1 > 21)
		{
			/*�������˶�������*/
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "ԭ����Ϊ��" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)
					cout << a[j] << " ";
			}
			cout << endl;
			/*����һ�����ֵ����ð�ݷ�����*/
			cout << "������Ҫ�����������" << endl;
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
			cout << "����������Ϊ��" << endl;
			for (j = 0; j < N; j++)
			{
				if (a[j] != -1 && a[j] != 0)//ֻ���������
					cout << a[j] << " ";
			}
			cout << endl;
			break;
		}
		if (i + 1 > 21)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "ԭ����Ϊ��" << endl;

			cout << endl;
			break;

		}
	}
	return 0;
}
