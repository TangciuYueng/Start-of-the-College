/* 2151298 ��11 ������ */
#include <iostream>
#include <cmath>
using namespace std;
#define N 9
int main()
{
	int r[N][N], k1[9] = { 0 }, k2[9] = { 0 }, k3[9] = { 0 }, k4[9] = { 0 }, k5[9] = { 0 }, k6[9] = { 0 }, k7[9] = { 0 }, k8[9 ] = { 0 }, k9[9] = { 0 };
	int i, j, m, p=0;
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	/*���룬Ӧ��Ϊ����for����ѭ�������ά����������±�*/
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[0][i];
			if (cin.fail() || r[0][i] < 1 || r[0][i]>9)
			{
				cout << "�����������1��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[0][i] >= 1 && r[0][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[1][i];
			if (cin.fail() || r[1][i] < 1 || r[1][i]>9)
			{
				cout << "�����������2��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[1][i] >= 1 && r[1][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[2][i];
			if (cin.fail() || r[2][i] < 1 || r[2][i]>9)
			{
				cout << "�����������3��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[2][i] >= 1 && r[2][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[3][i];
			if (cin.fail() || r[3][i] < 1 || r[3][i]>9)
			{
				cout << "�����������4��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[3][i] >= 1 && r[3][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[4][i];
			if (cin.fail() || r[4][i] < 1 || r[4][i]>9)
			{
				cout << "�����������5��" << i+1<< "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[4][i] >= 1 && r[4][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[5][i];
			if (cin.fail() || r[5][i] < 1 || r[5][i]>9)
			{
				cout << "�����������6��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[5][i] >= 1 && r[5][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[6][i];
			if (cin.fail() || r[6][i] < 1 || r[6][i]>9)
			{
				cout << "�����������7��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[6][i] >= 1 && r[6][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[7][i];
			if (cin.fail() || r[7][i] < 1 || r[7][i]>9)
			{
				cout << "�����������8��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[7][i] >= 1 && r[7][i] <= 9)
				break;
		}
	}
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[8][i];
			if (cin.fail() || r[8][i] < 1 || r[8][i]>9)
			{
				cout << "�����������9��" << i+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[8][i] >= 1 && r[8][i] <= 9)
				break;
		}
	}
	/*�бȽ�*/
	for (i = 0; i < N; i++)//ѭ��ÿ��
	{
		for (j = 0; j < N; j++)//ÿ�е�ÿ��Ԫ��
		{
			for (m =j+1; m < N; m++)//ÿ��Ԫ��Ҫ���������Ԫ�رȽ�
			{
				if (r[i][j] == r[i][m])
					p++;
			}
		}
	}
	/*�бȽ�*/
	for (i = 0; i < N; i++)//ѭ��ÿ��
	{
		for (j = 0; j < N - 1; j++)//ÿ�е�ÿ��Ԫ��
		{
			for (m = j + 1; m < N; m++)//ÿ��Ԫ��Ҫ���������Ԫ�رȽ�
			{
				if (r[j][i] == r[m][i])
					p++;
			}
		}
	}
	/*����ѭ������������*/
	int line[10],col;
	for (col = 0; col < N; col++)
	{
		for (i = 0; i <= N; i++)/*��line[i]-line[9]ȫ����ֵΪ��*/
			line[i] = 0;
		for (i = 0; i < N; i++)
			line[r[i][col]] = 1;//�±�[1]-[9]��ֵ
		for (i = 1; i <= N; i++)//���line[1]-line[9]�Ƿ�ȫ��1
			if (line[i] == 0)//��������line[i]Ϊ�㣬û�и�ֵΪ1�����ʾ������û���Ǹ�����
				p++;
	}
	/*�����鸳ֵ��С������*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i / 3 == 0)
			{
				if (j / 3 == 0)
				{

					k1[i % 3 * 3 + j % 3] = r[i][j];
				}
				else if (j / 3 == 1)
				{
					
					k2[i % 3 * 3 + j % 3 ] = r[i][j];
				}
				else
				{
					k3[i % 3 * 3 + j % 3 ] = r[i][j];
				}
			}

			else if (i / 3 == 1)
			{
				if (j / 3 == 0)
				{
					k4[i % 3 * 3 + j % 3 ] = r[i][j];
				}
				else if (j / 3 == 1)
				{
					k5[i % 3 * 3 + j % 3 ] = r[i][j];
				}
				else
				{
					k6[i % 3 * 3 + j % 3 ] = r[i][j];
				}
			}
			else
			{
				if (j / 3 == 0)
				{
					k7[i % 3 * 3 + j % 3 ] = r[i][j];
				}
				else if (j / 3 == 1)
				{
					k8[i % 3 * 3 + j % 3 ] = r[i][j];
				}
				else
				{
					k9[i % 3 * 3 + j % 3 ] = r[i][j];
				}
			}
		}
	}
	/*С������Ƚ�*/
	for (i = 0; i < N; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (k1[i] == k1[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k2[i] == k2[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k3[i] == k3[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k4[i] == k4[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k5[i] == k5[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k6[i] == k6[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k7[i] == k7[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k8[i] == k8[j])
				p++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (k9[i] == k9[j])
				p++;
		}
	}
	
	if (p)
		cout << "���������Ľ�" << endl;
	else
		cout << "�������Ľ�" << endl;
	return 0;
}