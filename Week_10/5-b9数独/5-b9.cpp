/* 2151298 信11 杨滕超 */
#include <iostream>
#include <cmath>
using namespace std;
#define N 9
int main()
{
	int r[N][N], k1[9] = { 0 }, k2[9] = { 0 }, k3[9] = { 0 }, k4[9] = { 0 }, k5[9] = { 0 }, k6[9] = { 0 }, k7[9] = { 0 }, k8[9 ] = { 0 }, k9[9] = { 0 };
	int i, j, m, p=0;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	/*输入，应改为两个for语句的循环输入二维数组的行列下标*/
	for (i = 0; i < N; i++)
	{
		while (1)
		{
			cin >> r[0][i];
			if (cin.fail() || r[0][i] < 1 || r[0][i]>9)
			{
				cout << "请重新输入第1行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第2行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第3行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第4行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第5行" << i+1<< "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第6行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第7行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第8行" << i+1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "请重新输入第9行" << i+1 << "列(行列均从1开始计数)的值" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (r[8][i] >= 1 && r[8][i] <= 9)
				break;
		}
	}
	/*行比较*/
	for (i = 0; i < N; i++)//循环每行
	{
		for (j = 0; j < N; j++)//每行的每个元素
		{
			for (m =j+1; m < N; m++)//每个元素要与后面所有元素比较
			{
				if (r[i][j] == r[i][m])
					p++;
			}
		}
	}
	/*列比较*/
	for (i = 0; i < N; i++)//循环每列
	{
		for (j = 0; j < N - 1; j++)//每列的每个元素
		{
			for (m = j + 1; m < N; m++)//每个元素要与后面所有元素比较
			{
				if (r[j][i] == r[m][i])
					p++;
			}
		}
	}
	/*两重循环方法——列*/
	int line[10],col;
	for (col = 0; col < N; col++)
	{
		for (i = 0; i <= N; i++)/*将line[i]-line[9]全部赋值为零*/
			line[i] = 0;
		for (i = 0; i < N; i++)
			line[r[i][col]] = 1;//下标[1]-[9]赋值
		for (i = 1; i <= N; i++)//检查line[1]-line[9]是否全是1
			if (line[i] == 0)//若出现有line[i]为零，没有赋值为1，则表示上述列没有那个数字
				p++;
	}
	/*大数组赋值到小块里面*/
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
	/*小块里面比较*/
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
		cout << "不是数独的解" << endl;
	else
		cout << "是数独的解" << endl;
	return 0;
}