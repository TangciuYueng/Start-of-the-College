/* 2151298 ��11 ������ */
/* 2152813 ½���� 2151299 �ռ��� 2153396 ɳЦ�� 2152497 �Բ�ά 2151119 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define M 10 
#define N 26
int main()
{
	char map[M][N];
	int i, j, sum1=0,sum2=0,count=0,m=0,n=0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	/*�������*/
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (map[i][j] == '*')
				sum1++;
		}
	}
	/*��������*/
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
			if (map[i][j] != (char)(count + '0'))
				sum2++;
		}
	}
	if (sum1 != 50)
	{
		printf("����1\n");
	}
	else
	{
		if (sum2)
		{
			printf("����2\n");
		}
		else
			printf("��ȷ\n");
	}
	return 0;
}