/* 2151298 ��11 ������ */
#include <iostream>
#include <time.h>
#include <cstdio>
#include <conio.h>
#define M 10 
#define N 26
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//���ӣ��ڳ�����ֻ��һ�ξ͹���
	char map[M][N] ;
	int num = 50,i,j,x,y,count=0,m,n,sum=0;
	/*���ɵ���*/
	for (i = 0; i < 50; i++)
	{
	     x = rand() % M ;
		 y = rand() % N ;
		 if (map[x][y] == '*')//���λ���ظ���
			 i--;
		 else
		     map[x][y] = '*';
	}
	/*Ҳ���Բ�дi++,��������
	for (i = 0; i < 50;)
	{
		x = rand() % M;
		y = rand() % N;
		if (map[x][y] != '*')//�жϷ��������˲�i++
		{
			map[x][y] = '*';
			i++;
		}//�����ײŸ�ֵ++
	}
	*/
	/*�����Աߵ����֣��ҷ���λ�ã���һȦ�����׾�++*/
	/*ͳһ�߽��м䷽��������һȦ����ע�ⲻҪ���Ǻ����������*/
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			count = 0;
			if (map[i][j] == '*')
				continue;
			else if (i == 0 && j == 0)
			{
				for (m = i; m < i + 2; m++)
				{
					for (n = j; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i == 9 && j == 0)
			{
				for (m = i - 1; m < i + 1; m++)
				{
					for (n = j; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i == 9 && j == 25)
			{
				for (m = i - 1; m < i + 1; m++)
				{
					for (n = j - 1; n < j + 1; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i == 0 && j == 25)
			{
				for (m = i; m < i + 2; m++)
				{
					for (n = j - 1; n < j + 1; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i == 0 && j > 0 && j < 25)
			{
				for (m = i; m < i + 2; m++)
				{
					for (n = j - 1; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i > 0 && i < 9 && j == 0)
			{
				for (m = i - 1; m < i + 2; m++)
				{
					for (n = j; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i == 9 && j > 0 && j < 25)
			{
				for (m = i - 1; m < i + 1; m++)
				{
					for (n = j - 1; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else if (i > 0 && i < 9 && j == 25)
			{
				for (m = i - 1; m < i + 2; m++)
				{
					for (n = j - 1; n < j + 1; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			else
			{
				for (m = i - 1; m < i + 2; m++)
				{
					for (n = j - 1; n < j + 2; n++)
					{
						if (map[m][n] == '*')
							count++;
					}
				}
			}
			map[i][j] = char(count+'0');
		}
	}
	/*��ӡ��ͼ*/
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
	
	return 0;
}