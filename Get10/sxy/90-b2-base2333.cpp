/* ��11 ɳЦ�� 2153396 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;
#define N 10
#define M 12

void jilu(char sz[N][M], char zb[], int x0, int y0, char n, int a, int b,int X,int Y)
{
	int i, j, x = 0, y = 0, q;
	char jl[N][M], ch;

	for (i = 0; i < N; i++) {//��ʼ��
		for (j = 0; j < M; j++)
			jl[i][j] = '0';
	}
	if (zb[0] > 64 && zb[1] > 47) {//��������
		x = (int)zb[0] - 64;//xΪѡ��ĺ�����+1
		y = (int)zb[1] - 47;//yΪѡ���������+1
	}
	//cout << endl << zb[0]<<zb[1] << endl;
	ch = sz[x][y];
	/*sdf*/
	/*cout << endl;
	for (int u = 0; u < N + 1; u++)
	{
		for (int f = 0; f < M + 1; f++)
		{
			cout << sz[u][f] << " ";
		}
		cout << endl;
	}cout << endl;*/

	jl[x][y] = '*';
	for (q = 0; q < 10; q++) {
		for (i = 1; i < N - 1; i++) {//����ch����Χ���Ǻŵ���
			for (j = 1; j < M - 1; j++) {
				if (sz[i][j] == ch && (jl[i][j + 1] == '*' || jl[i][j - 1] == '*' || jl[i + 1][j] == '*' || jl[i - 1][j] == '*'))
					jl[i][j] = '*';
				else
					jl[i][j] = '0';
			}
		}
	}
	kuaidown(zb, sz, jl, x0, y0, n, a, b, X, Y);
}

void hebing(char zb[],char sz[N][M],char jl[N][M],int x0,int y0,char n)
{
	int i, j, x = 0, y = 0;
	char ch;

	if (zb[0] > 64 && zb[1] > 47) {//��������
		x = (int)zb[0] - 64;//xΪѡ��ĺ�����+1
		y = (int)zb[1] - 47;//yΪѡ���������+1
	}
	ch = sz[x][y];
	jl[x][y] = '1';
	sz[x][y] = (char)(ch + 1);

	for (i = 0; i < x0; i++) {
		for (j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				sz[i + 1][j + 1] = '0';
		}
	}
}