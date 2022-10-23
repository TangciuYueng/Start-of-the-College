/* 2151298 ��11 ������ */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*��ʼ�������*/
void rand_num(int map[][CE + 2], int r, int c)
{
	int i, j, k = 0, num;
	srand((unsigned)time(NULL));
	while (k < r * c)
	{
		i = 1 + rand() % r;
		j = 1 + rand() % c;
		if (map[i][j] == 0)
		{
			num = 1 + rand() % 3;
			map[i][j] = num;
			k++;
		}
	}
}
/*�������*/
void output(int map[][CE + 2], char map2[][CE + 2], int r, int c, int select )
{
	cout << endl;
	if (select == 0)
		cout << "��ǰ����:" << endl;
	else if (select == 1)
		cout << "���ҽ�����飺" << endl;
	else if (select == 2)
		cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	else if (select == 3)
		cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
	else if (select == 4)
		cout << "��0�������(��ͬɫ��ʶ)��" << endl;
	else if (select == 5)
		cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	int i = 0, j = 0;
		

	cout << "  |";//���Ͻ�
	for (i = 0; i < c; i++)//��һ������
	{
		cout << "  " << i;
	}
	cout << endl;
	cout << "--+";//����
	for (i = 0; i < c; i++)
	{
		cout << "---";
	}
	cout << "-" << endl;

	for (i = 1; i < r + 1; i++)//�������
	{
		cout << char(i + 'A' - 1) << " |";
		for (j = 1; j < c + 1; j++)
		{
			if (select == 0)
				cout << setw(3) << setiosflags(ios::right) << map[i][j];
			else if (select == 1)
				cout << setw(3) << setiosflags(ios::right) << map2[i][j];
			else if (select == 2)
			{
				if (map[i][j] < 10)
					cout << "  ";//��ֹǰ���Ҳ��ɻ�ɫ��
				else
					cout << " ";
				if (map2[i][j] == '*')
					cct_setcolor(14, 0);//����ɫ���ƣ������
				cout << map[i][j];
				if (map2[i][j] == '*')
					cct_setcolor();
			}
			else if (select == 3||select==4||select==5)
			{
				if (map[i][j] < 10)
					cout << "  ";//��ֹǰ���Ҳ��ɻ�ɫ��
				else
					cout << " ";
				if(map2[i][j]=='*')
					cct_setcolor(14, 0);//����ɫ���ƣ������
				cout << map[i][j];
				if (map2[i][j] == '*')
					cct_setcolor();
			}
			
		}
		cout << endl;
	}
	cout << endl;

}
/*����������ͬ_�ǵݹ�*/
int search1(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie)//Ӧ�÷���һ��ֵ�ж�*�ĸ���������1��Ҫ������������
{
	int i, j, m, n, sum = 0, k;

	for (i = 0; i < RE + 2; i++)//��ֹ���ҳ���ֻ��һ��*����������ʱ��
		for (j = 0; j < CE + 2; j++)
			map2[i][j] = '0';

	map2[*hang - 'A' + 1][*lie + 1] = '*';//����������á�*��

	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map2[i][j] == '*')
				for (m = i - 1; m <= i + 1; m++)//��Χ�ĸ�����
					for (n = j - 1; n <= j + 1; n++)
					{
						if (m == i - 1 && (n == j - 1 || n == j + 1))
							continue;
						if (m == i + 1 && (n == j - 1 || n == j + 1))
							continue;

						if (map[m][n] == map[i][j])
						{
							map2[m][n] = '*';
						}
					}
	for (k = 0; k < 2; k++)
	{
		/*������һ��*/
		for (i = 1; i < RE + 1; i++)
			for (j = 1; j < CE + 1; j++)
				if (map2[i][j] == '*')
					for (m = i - 1; m <= i + 1; m++)//��Χ�ĸ�����
						for (n = j - 1; n <= j + 1; n++)
						{
							if (m == i - 1 && (n == j - 1 || n == j + 1))
								continue;
							if (m == i + 1 && (n == j - 1 || n == j + 1))
								continue;

							if (map[m][n] == map[i][j])
							{
								map2[m][n] = '*';
							}
						}


		/*������һ��*/
		for (i = RE; i > 0; i--)
			for (j = CE; j > 0; j--)
				if (map2[i][j] == '*')
					for (m = i - 1; m <= i + 1; m++)//��Χ�ĸ�����
						for (n = j - 1; n <= j + 1; n++)
						{
							if (m == i - 1 && (n == j - 1 || n == j + 1))
								continue;
							if (m == i + 1 && (n == j - 1 || n == j + 1))
								continue;

							if (map[m][n] == map[i][j])
							{
								map2[m][n] = '*';
							}
						}
	}
	


	/*��¼*����*/
	for (i = 0; i < RE + 2; i++)//ÿ��ѭ��map��map2�Ļָ�
		for (j = 0; j < CE + 2; j++)
			if (map2[i][j] == '*')
				sum++;
	return sum;
}
/*����������ͬ�����ݹ�*/
void search2(int map[][CE + 2], char map2[][CE + 2], int i, int j,int same)
{
	/*���ȱ�֤���鲻Խ�磬֮���ж��Ƿ�������ͬ���Ҳ���֮ǰ�ҹ��ĵط���ֱ���������*/
	if (i + 1 <= RE)
		if (same == map[i + 1][j] && map2[i + 1][j] != '*')
		{
			map2[i + 1][j] = '*';
			search2(map, map2, i + 1, j, same);
		}
	if (i - 1 >= 1)
		if (same == map[i - 1][j]&&map2[i-1][j]!='*')
		{
			map2[i - 1][j] = '*';
			search2(map, map2,  i - 1, j, same);
		}
	if (j + 1 <= CE)
		if (same == map[i][j + 1]&&map2[i][j+1] != '*')
		{
			map2[i][j + 1] = '*';
			search2(map, map2,  i, j + 1, same);
		}
	if (j - 1 >= 1)
		if (same == map[i][j - 1]&&map2[i][j-1] != '*')
		{
			map2[i][j - 1] = '*';
			search2(map, map2,  i, j - 1, same);
		}
}
/*����任������ֵͬ�鲢*/
void merge(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie)
{
	int i, j;
	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map2[i][j] == '*')//��*
			{
				if (i == *hang - 'A' + 1 && j == *lie + 1)//���������������
				{
					map[i][j]++;
					continue;
				}
				else
					map[i][j] = 0;
			}
}
/*����任��������*/
void drop(int map[][CE + 2], char map2[][CE + 2],int hang)
{
	int i, j, k = 0;
	for (j = 1; j < CE+1; j++)//��ÿһ�п�ʼ
		for (i = RE; i >1; i--)//���ܵ�һ��
		{
			if (map2[i][j] == '*' && map2[i - 1][j] != '*')//������*
			{
				map[i][j] = map[i-1][j];//���渳ֵ������
				map[i-1][j] = 0;
				map2[i-1][j ] = '*';
				map2[i][j] = '0';
			}
		}
	/*��黹û��û0��*���棬�������Χ��*/
	for (i = 1; i < hang; i++)//���ü�����һ��
	{
		for (j = 1; j < CE; j++)
		{
			if (map[i][j]>0&&map[i+1][j]==0)//0��*����Ͳ�����
			{
				k++;
				break;
			}
		}
	}
	if (k)
		drop(map, map2,hang);
}
/*��¼*�ĸ���*/
int count(char map2[][CE + 2])
{
	int i, j, sum=0;
	for (i = 0; i < RE + 2; i++)//ÿ��ѭ��map��map2�Ļָ�
		for (j = 0; j < CE + 2; j++)
			if (map2[i][j] == '*')
				sum++;
	return sum;
}
/*�����������*/
void outputtt(int map[][CE + 2], char map2[][CE + 2])
{
	int i, j;
	cout << endl;
	/*for (i = 0; i < RE + 2; i++)
	{
		for (j = 0; j < CE+2; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	for (i = 0; i < RE+2; i++)
	{
		for (j = 0; j < CE+2; j++)
		{
			cout << map2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/*map2�ָ�*/
void huifu(char map2[][CE + 2])
{
	int m, n;
	for (m = 1; m < RE + 1; m++)
	{
		for (n = 1; n < CE + 1; n++)
		{
			map2[m][n] = '0';
		}
	}
	
}
/*�ж���Ϸ�Ƿ����*/
int gameend(int map[][CE + 2], char map2[][CE + 2],int r,int c)
{
	int i, j, k;
	k = 0;
	huifu(map2);//ȫ����0
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)//ÿ��λ�ö���һ�飬���ֶ����ܺϲ���kΪ��
		{
			map2[i][j] = '*';
			search2(map, map2, i, j, map[i][j]);
			if (count(map2) > 1)
				k++;
			
			huifu(map2);//ȫ����0

			if (k)
				break;
		}
		if (k)
			break;
	}
	return k;
}
/*�ҵ����Ž�*/
void find_best(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie,int r,int c)
{
	int i, j, fenmax = 0;
	*hang = 'A';
	*lie = 0;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			map2[i][j] = '*';
			search2(map, map2, i, j, map[i][j]);
			if (count(map2) > 1)
			{
				if (map[i][j] * count(map2) * 3 > fenmax)//�б�fenmax����ģ��͸���
				{
					fenmax = map[i][j] * count(map2) * 3;
					*hang = (char)(i + 'A' - 1);
					*lie = j - 1;
				}
			}
			   
			huifu(map2);//map2ʹ�����Ļָ���ȫ���á�0��
		}
	}
}