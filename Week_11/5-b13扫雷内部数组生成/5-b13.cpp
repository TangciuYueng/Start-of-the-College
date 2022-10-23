/* 2151298 信11 杨滕超 */
#include <iostream>
#include <time.h>
#include <cstdio>
#include <conio.h>
#define M 10 
#define N 26
using namespace std;

int main()
{
	srand((unsigned)time(NULL));//种子，在程序中只用一次就够了
	char map[M][N] ;
	int num = 50,i,j,x,y,count=0,m,n,sum=0;
	/*生成地雷*/
	for (i = 0; i < 50; i++)
	{
	     x = rand() % M ;
		 y = rand() % N ;
		 if (map[x][y] == '*')//如果位置重复就
			 i--;
		 else
		     map[x][y] = '*';
	}
	/*也可以不写i++,空条件！
	for (i = 0; i < 50;)
	{
		x = rand() % M;
		y = rand() % N;
		if (map[x][y] != '*')//判断符合条件了才i++
		{
			map[x][y] = '*';
			i++;
		}//不是雷才赋值++
	}
	*/
	/*地雷旁边的数字，找非雷位置，走一圈，有雷就++*/
	/*统一边角中间方法：扩充一圈！！注意不要让星号落在最外层*/
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
	/*打印地图*/
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