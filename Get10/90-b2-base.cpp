/* 2151298 信11 杨滕超 */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*初始随机数组*/
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
/*输出数组*/
void output(int map[][CE + 2], char map2[][CE + 2], int r, int c, int select )
{
	cout << endl;
	if (select == 0)
		cout << "当前数组:" << endl;
	else if (select == 1)
		cout << "查找结果数组：" << endl;
	else if (select == 2)
		cout << "当前数组(不同色标识)：" << endl;
	else if (select == 3)
		cout << "相同值归并后的数组(不同色标识)：" << endl;
	else if (select == 4)
		cout << "除0后的数组(不同色标识)：" << endl;
	else if (select == 5)
		cout << "新值填充后的数组(不同色标识)：" << endl;
	int i = 0, j = 0;
		

	cout << "  |";//左上角
	for (i = 0; i < c; i++)//第一行数字
	{
		cout << "  " << i;
	}
	cout << endl;
	cout << "--+";//横线
	for (i = 0; i < c; i++)
	{
		cout << "---";
	}
	cout << "-" << endl;

	for (i = 1; i < r + 1; i++)//数组输出
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
					cout << "  ";//防止前面的也变成黄色了
				else
					cout << " ";
				if (map2[i][j] == '*')
					cct_setcolor(14, 0);//背景色亮黄，字体黑
				cout << map[i][j];
				if (map2[i][j] == '*')
					cct_setcolor();
			}
			else if (select == 3||select==4||select==5)
			{
				if (map[i][j] < 10)
					cout << "  ";//防止前面的也变成黄色了
				else
					cout << " ";
				if(map2[i][j]=='*')
					cct_setcolor(14, 0);//背景色亮黄，字体黑
				cout << map[i][j];
				if (map2[i][j] == '*')
					cct_setcolor();
			}
			
		}
		cout << endl;
	}
	cout << endl;

}
/*检索相邻相同_非递归*/
int search1(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie)//应该返回一个值判断*的个数，等于1需要重新输入坐标
{
	int i, j, m, n, sum = 0, k;

	for (i = 0; i < RE + 2; i++)//防止查找出来只有一个*，重新输入时候
		for (j = 0; j < CE + 2; j++)
			map2[i][j] = '0';

	map2[*hang - 'A' + 1][*lie + 1] = '*';//输入的坐标置’*‘

	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map2[i][j] == '*')
				for (m = i - 1; m <= i + 1; m++)//周围四个格子
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
		/*正向来一遍*/
		for (i = 1; i < RE + 1; i++)
			for (j = 1; j < CE + 1; j++)
				if (map2[i][j] == '*')
					for (m = i - 1; m <= i + 1; m++)//周围四个格子
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


		/*负向来一遍*/
		for (i = RE; i > 0; i--)
			for (j = CE; j > 0; j--)
				if (map2[i][j] == '*')
					for (m = i - 1; m <= i + 1; m++)//周围四个格子
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
	


	/*记录*个数*/
	for (i = 0; i < RE + 2; i++)//每次循环map和map2的恢复
		for (j = 0; j < CE + 2; j++)
			if (map2[i][j] == '*')
				sum++;
	return sum;
}
/*检索相邻相同——递归*/
void search2(int map[][CE + 2], char map2[][CE + 2], int i, int j,int same)
{
	/*首先保证数组不越界，之后判断是否相邻相同并且不是之前找过的地方，直到找完结束*/
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
/*数组变换——相同值归并*/
void merge(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie)
{
	int i, j;
	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map2[i][j] == '*')//是*
			{
				if (i == *hang - 'A' + 1 && j == *lie + 1)//但不是输入的坐标
				{
					map[i][j]++;
					continue;
				}
				else
					map[i][j] = 0;
			}
}
/*数组变换——下落*/
void drop(int map[][CE + 2], char map2[][CE + 2],int hang)
{
	int i, j, k = 0;
	for (j = 1; j < CE+1; j++)//从每一列开始
		for (i = RE; i >1; i--)//不管第一行
		{
			if (map2[i][j] == '*' && map2[i - 1][j] != '*')//发现是*
			{
				map[i][j] = map[i-1][j];//上面赋值给下面
				map[i-1][j] = 0;
				map2[i-1][j ] = '*';
				map2[i][j] = '0';
			}
		}
	/*检查还没有没0在*上面，在输出范围内*/
	for (i = 1; i < hang; i++)//不用检查最后一行
	{
		for (j = 1; j < CE; j++)
		{
			if (map[i][j]>0&&map[i+1][j]==0)//0在*上面就不对了
			{
				k++;
				break;
			}
		}
	}
	if (k)
		drop(map, map2,hang);
}
/*记录*的个数*/
int count(char map2[][CE + 2])
{
	int i, j, sum=0;
	for (i = 0; i < RE + 2; i++)//每次循环map和map2的恢复
		for (j = 0; j < CE + 2; j++)
			if (map2[i][j] == '*')
				sum++;
	return sum;
}
/*两个数组输出*/
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
/*map2恢复*/
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
/*判断游戏是否结束*/
int gameend(int map[][CE + 2], char map2[][CE + 2],int r,int c)
{
	int i, j, k;
	k = 0;
	huifu(map2);//全部置0
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)//每个位置都看一遍，发现都不能合并则k为零
		{
			map2[i][j] = '*';
			search2(map, map2, i, j, map[i][j]);
			if (count(map2) > 1)
				k++;
			
			huifu(map2);//全部置0

			if (k)
				break;
		}
		if (k)
			break;
	}
	return k;
}
/*找到最优解*/
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
				if (map[i][j] * count(map2) * 3 > fenmax)//有比fenmax还大的，就更新
				{
					fenmax = map[i][j] * count(map2) * 3;
					*hang = (char)(i + 'A' - 1);
					*lie = j - 1;
				}
			}
			   
			huifu(map2);//map2使用完后的恢复，全部置‘0’
		}
	}
}