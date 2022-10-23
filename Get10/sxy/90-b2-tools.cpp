/* 信11 沙笑因 2153396 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;
#define N 10
#define M 12

void zhaoshu1(char zb[], char sz[N][M], char ch, int x0, int y0, char n, int mb)//找旁边有没有一样的
{
	int i, j, x = 0, y = 0, q = 0, w = 0;
	char jl[N][M];
	for (i = 0; i < N; i++) {//初始化
		for (j = 0; j < M; j++)
			jl[i][j] = '0';
	}
	if (zb[0] > 64 && zb[1] > 47) {//消除警告
		x = (int)zb[0] - 64;//x为选择的横坐标+1
		y = (int)zb[1] - 47;//y为选择的纵坐标+1
	}

	jl[x][y] = '*';
	for (q = 0; q < 10; q++) {
		for (i = 1; i < N - 1; i++) {//找是ch且周围有星号的数
			for (j = 1; j < M - 1; j++) {
				if (sz[i][j] == ch && (jl[i][j + 1] == '*' || jl[i][j - 1] == '*' || jl[i + 1][j] == '*' || jl[i - 1][j] == '*'))
					jl[i][j] = '*';
				else
					jl[i][j] = '0';
			}
		}
	}
	shuchuxh(zb, sz, jl, ch, x0, y0, n, mb);
}

char shuchuxh(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb) {//输出带星号的数组
	int i, j;
	cout << "查找结果数组：" << endl;
	cout << "  |";
	for (i = 0; i < y0; i++) //输出第一行
		cout << "  " << i;
	cout << endl << "--+-";//输出分割线
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//输出数组
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++)
			cout << setw(3) << jl[j + 1][i + 1];
		cout << endl;
	}
	cout << endl << endl;

	char ret=shangsai(zb, sz, jl, ch, x0, y0, n, mb);
	return ret;
}

void zhaoshu2(char zb[], char sz[N][M], char ch, int x0, int y0, int x, int y, char jl[N][M])//递归
{
	jl[x][y] = '*';

	if (x - 1 > 0 && sz[x - 1][y] == ch && jl[x - 1][y] != '*') {
		jl[x - 1][y] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x - 1, y, jl);
	}
	if (y - 1 > 0 && sz[x][y - 1] == ch && jl[x][y - 1] != '*') {
		jl[x][y - 1] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x, y - 1, jl);
	}
	if (y + 1 < y0 + 1 && sz[x][y + 1] == ch && jl[x][y + 1] != '*') {
		jl[x][y + 1] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x, y + 1, jl);
	}
	if (x + 1 < x0 + 1 && sz[x + 1][y] == ch && jl[x + 1][y] != '*') {
		jl[x + 1][y] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x + 1, y, jl);
	}
}

char shangsai(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb, bool bo)//上色
{
	int i, j, a, b;
	char qr;
	if (bo)
		cout << "当前数组(不同色标识)：" << endl;
	cout << "  |";
	for (i = 0; i < y0; i++) //输出第一行
		cout << "  " << i;
	cout << endl << "--+-";//输出分割线
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//输出数组
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			cout << "  ";
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(14, 0);
			cout << sz[j + 1][i + 1];
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(0, 7);
		}
		cct_setcolor(0, 7);
		cout << endl;
	}
	cout << endl;

	if (n >= '3') {
		while (1) {
			cout << "请确认是否把相邻的相同值合并到" << (char)zb[0] << zb[1] << "中(Y/N/Q)：";
			while (1) {//输入
				qr = _getche();
				cct_getxy(a, b);
				if (qr == 'Y' || qr == 'y' || qr == 'n' || qr == 'N' || qr == 'q' || qr == 'Q')
					break;
				else if (n == 13)
					cct_gotoxy(10, b);
				else {
					cct_showch(a - 1, b, ' ');
					cct_gotoxy(a - 1, b);
				}
			}
			cout << endl << endl;
			if (qr == 'Y' || qr == 'y') {
				heyi(zb, sz, jl, ch, x0, y0, n, mb);
				break;
			}
			else if (qr == 'n' || qr == 'N')
				return qr;
			else
				return qr;
		}
	}
}

void shuzu(int x0, int y0, char n, int mb,bool bo)
{
	srand((unsigned)time(0));
	int  i, j, s = 0;
	char zb[80], sz[N][M];
	for (i = 0; i < N; i++) {//初始化
		for (j = 0; j < M; j++)
			sz[i][j] = '\0';
	}
	for (i = 0; i < 80; i++)
		zb[i] = '0';

	cout << endl << "当前数组：" << endl;//打印数组
	cout << "  |";
	for (i = 0; i < y0; i++) //输出第一行
		cout << "  " << i;
	cout << endl << "--+-";//输出分割线
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//输出数组
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			s = (rand() % 3) + 1;
			cout << "  " << s;
			sz[j + 1][i + 1] = s + '0';//+1为了把8，10整成10，12
		}
		cout << endl;
	}
	cout << endl;
	while (1) {
		shuru2(zb, sz, x0, y0, n, mb);
		if (n != '4')
			break;
	}
}

void shuru2(char zb[], char sz[N][M], int x0, int y0, char n, int mb, bool boo)
{
	int x2, y2, x1, y1, x = 0, y = 0, i, j, loop = 1;
	bool bo = 1;
	char jl[N][M], ch;
	while (loop) {
		loop = 0;
		if (boo)
			cin.ignore(65535, '\n');
		else {
			cout << endl << "当前数组：" << endl;//打印数组
			cout << "  |";
			for (i = 0; i < y0; i++) //输出第一行
				cout << "  " << i;
			cout << endl << "--+-";//输出分割线
			for (i = 0; i < y0; i++)
				cout << "---";
			cout << endl;

			for (j = 0; j < x0; j++) {//输出数组
				cout << (char)(j + 65) << " |";
				for (i = 0; i < y0; i++)
					cout << "  " << sz[j + 1][i + 1];
				cout << endl;
			}
			cout << endl;
		}

		cct_getxy(x2, y2);//提示语输出的位置
		while (1) {
			if (bo)
				cct_gotoxy(0, y2);
			cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
			cin.getline(zb, 50, '\n');

			if ((int)zb[0] <= 123 && (int)zb[0] >= 97)//把小写转为大写
				zb[0] = zb[0] - 32;

			if (((int)zb[0] < 65 + x0 && (int)zb[0] >= 65) && ((int)zb[1] < y0 + 48 && (int)zb[1] >= 48))
				cout << "输入为" << (char)zb[0] << "行" << zb[1] << "列";
			else {
				bo = 1;
				cout << "输入错误，请重新输入.";
				cct_getxy(x1, y1);//输入错误之后光标位置
				cct_showch(39, y1 - 1, ' ', 0, 7, 50);
				cct_gotoxy(39, y1 - 1);
				continue;
			}

			if (zb[0] > 64 && zb[1] > 47) {//消除警告
				x = (int)zb[0] - 64;//x为选择的横坐标+1
				y = (int)zb[1] - 47;//y为选择的纵坐标+1
			}
			ch = sz[x][y];//ch为指定坐标处的数字

			if (y >= 1 && x >= 1) {
				if (sz[x][y + 1] != ch && sz[x][y - 1] != ch && sz[x + 1][y] != ch && sz[x - 1][y] != ch) {//检验是否存在星号
					cout << endl << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
					bo = 0;
					cct_getxy(x2, y2);//提示语输出的位置
					continue;
				}
				else
					break;
			}
		}
		cout << endl << endl;

		if (n == '1')
			zhaoshu1(zb, sz, ch, x0, y0, n, mb);
		else /*if (n == '2' || n == '3')*/ {
			for (i = 0; i < N; i++) {//初始化
				for (j = 0; j < M; j++)
					jl[i][j] = '0';
			}
			zhaoshu2(zb, sz, ch, x0, y0, x, y, jl);
			char ret = shuchuxh(zb, sz, jl, ch, x0, y0, n, mb);
			if (ret == 'N' || ret == 'n') {
				boo = 0;
				loop = 1;
			}
		}
	}
}

void shuru(char n)
{
	int x = 0, y = 0, mb = 5;
	char zb[3] = { '\0' };
	cct_cls();

	while (1) {
		cout << "请输入行数(5-8)：" << endl;
		cin >> x;
		if (x <= 8 && x >= 5)
			break;
	}
	while (1) {
		cout << "请输入列数(5-10)：" << endl;
		cin >> y;
		if (y <= 10 && y >= 5)
			break;
	}

	if (n == '3' || n == '4' || n == '9') {
		while (1) {
			cout << "请输入合成目标(5-20)：" << endl;
			cin >> mb;
			if (mb <= 20 && mb >= 5)
				break;
		}
	}
	if (n <= '4')
		shuzu(x, y, n, mb);
	if (n == '5')
		huakuai(x, y);
	if (n == '6' || n >= '7') {
		huakuai2(x, y, n);
		cct_gotoxy(0, 4 * x + 3);
	}
}

void heyi(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb)//3
{
	int i, j, x = 0, y = 0, a, b;
	char hc;
	cout << "相同值归并后的数组(不同色标识)：" << endl;
	if (zb[0] > 64 && zb[1] > 47) {//消除警告
		x = (int)zb[0] - 64;//x为选择的横坐标+1
		y = (int)zb[1] - 47;//y为选择的纵坐标+1
	}
	jl[x][y] = '1';
	sz[x][y] = (char)(ch + 1);

	for (i = 0; i < x0; i++) {
		for (j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				sz[i + 1][j + 1] = '0';
		}
	}

	shangsai2(zb, sz, jl, ch, x0, y0, n, mb);
	defen(jl, ch, n, mb, x0, y0);
	cout << "按回车键进行数组下落除0操作..." << endl;
	while (1) {
		hc = _getche();
		cct_getxy(a, b);
		if (hc == 13)
			break;
		else if (hc == '\b')
			cct_gotoxy(30, b);
		else {
			cct_showch(a - 1, b, ' ');
			cct_gotoxy(a - 1, b);
		}
	}
	xialuo(sz, jl, x0, y0);
	cout << "除0后的数组(不同色标识)：" << endl;
	shangsai2(zb, sz, jl, ch, x0, y0, n, mb, 1);
	cout << "按回车键进行新值填充..." << endl;
	while (1) {
		hc = _getche();
		cct_getxy(a, b);
		if (hc == 13)
			break;
		else if (hc == '\b')
			cct_gotoxy(30, b);
		else {
			cct_showch(a - 1, b, ' ');
			cct_gotoxy(a - 1, b);
		}
	}
	cout << "新值填充后的数组(不同色标识)：" << endl;
	tianchong(sz, jl, mb, x0, y0, n, ch);
	shangsai2(zb, sz, jl, ch, x0, y0, n, mb, 1);

	if (n == '4') {
		cout << "本次合成结束，按回车键继续新一次的合成..." << endl << endl;
		while (1) {
			cct_getxy(a, b);
			hc = _getche();
			if (hc == 13)
				break;
			else if (hc == '\b')
				cct_gotoxy(30, b);
			else {
				cct_showch(a - 1, b, ' ');
				cct_gotoxy(a - 1, b);
			}
		}
		
		shuzu2(zb,sz, x0, y0, n, mb);
	}
}

void shuzu2(char zb[],char sz[N][M], int x0, int y0, char n, int mb) 
{
	int i, j;
	cout << endl << "当前数组：" << endl;//打印数组
	cout << "  |";
	for (i = 0; i < y0; i++) //输出第一行
		cout << "  " << i;
	cout << endl << "--+-";//输出分割线
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//输出数组
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) 
			cout << "  " << sz[j + 1][i + 1];//+1为了把8，10整成10，12
		cout << endl;
	}
	cout << endl;

	shuru2(zb, sz, x0, y0, n, mb);
}

void xialuo(char sz[N][M], char jl[N][M], int x0, int y0)
{
	int i, j;
	for (j = 1; j <= y0; j++) {
		for (i = x0; i > 1; i--) {
			if (jl[i][j] == '*' && jl[i - 1][j] != '*') {
				if (jl[i - 1][j] != '\0' && jl[i][j] != '\0') {
					sz[i][j] = sz[i - 1][j];
					sz[i - 1][j] = '0';
					jl[i][j] = '0';
					jl[i - 1][j] = '*';

				}
			}
		}
	}

	for (j = 1; j <= y0; j++) {
		for (i = x0; i > 1; i--) {
			if (sz[i - 1][j] != '0' && sz[i][j] == '0')
				break;
		}
		if (i != 1)
			break;
	}
	if (j != y0 + 1)
		xialuo(sz, jl, x0, y0);
}

void defen(char jl[N][M], char ch, char n, int mb, int x0, int y0)
{
	int i, j, q = 0, f = 0;
	for (i = 0; i < x0; i++) {
		for (j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				q++;
		}
	}
	f = (q + 1) * (ch - '0') * 3;
	cout << "本次得分：" << f << " 总得分：" << f << " 合成目标：" << mb << endl << endl;
}

void shangsai2(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb, bool bo)//上色2
{
	int i, j;

	cout << "  |";
	for (i = 0; i < y0; i++) //输出第一行
		cout << "  " << i;
	cout << endl << "--+-";//输出分割线
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	if (bo) {
		for (i = 0; i < x0; i++)
			for (j = 0; j < y0; j++)
				if (jl[i + 1][j + 1] == '1')
					jl[i + 1][j + 1] = '0';
	}

	for (j = 0; j < x0; j++) {//输出数组
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			cout << "  ";
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(14, 0);
			cout << sz[j + 1][i + 1];
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(0, 7);
		}
		cct_setcolor(0, 7);
		cout << endl;
	}
	cout << endl;
}

void tianchong(char sz[N][M], char jl[N][M], int mb, int x0, int y0, char n, char ch)
{
	srand((unsigned)time(0));
	int s, i, j;
	if (n == '3') {
		if (ch != '3')
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 3) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
		else
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 10)
						s = 4;
					else
						s = (rand() % 3) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
	}
	else {//选项89
		if (ch == '4')
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 10)
						s = 5;
					else if (s > 10 && s <= 25)
						s = 4;
					else
						s = (rand() % 3) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
		else if (ch == '5')
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 5)
						s = 6;
					else if (s > 5 && s <= 20)
						s = 5;
					else
						s = (rand() % 4) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
		else
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 5)
						s = ch - '0' + 1;
					else if (s > 5 && s <= 10)
						s = ch - '0';
					else if (s > 10 && s <= 20)
						s = ch - '1';
					else
						s = (rand() % (ch - '2')) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
	}
}

void huakuai(int x0, int y0)
{
	cct_setconsoleborder(6 * y0 + 7, 3 * x0 + 8, 6 * y0 + 7, 3 * x0 + 8);
	int i, j, k, s = 0;
	char sz[N][M];

	for (j = 0; j < x0; j++) {//数组
		for (i = 0; i < y0; i++) {
			s = (rand() % 3) + 1;
			sz[j + 1][i + 1] = s + '0';//+1为了把8，10整成10，12
		}
	}

	cout << "屏幕当前设置为：" << 6 * y0 + 7 << "行" << 3 * x0 + 8 << "列" << endl;
	cout << " ";
	for (i = 1; i <= y0; i++)//第一行
		cout << setw(6) << i;
	cout << endl;

	//第一排的框
	cout << "  ";
	cct_setcolor(15, 0);
	for (i = 0; i < y0 * 3 + 2; i++) {
		if (i == 0)
			cout << "┏";
		else if (i == y0 * 3 + 2 - 1)
			cout << "┓";
		else
			cout << "━";
	}
	cout << endl;

	//中间带色的
	for (i = 0; i < x0; i++) {
		for (k = 0; k < 3; k++) {//行
			cct_setcolor(0, 7);
			if (k == 1)
				cout << (char)(i + 65) << " ";
			else
				cout << "  ";
			cct_setcolor(15, 0);
			cout << "┃";
			//每行最前面那块

			for (j = 0; j < y0; j++) {
				if (k == 0) {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┏" << "━" << "┓";
				}
				else if (k == 1) {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┃" << sz[i + 1][j + 1] << " " << "┃";
				}
				else {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┗" << "━" << "┛";
				}
			}

			cct_setcolor(15, 0);
			cout << "┃";
			//每行最后面那块
			cout << endl;
		}
	}

	//最后一排的框
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	for (i = 0; i < y0 * 3 + 2; i++) {
		//Sleep(10);
		if (i == 0)
			cout << "┗";
		else if (i == y0 * 3 + 2 - 1)
			cout << "┛";
		else
			cout << "━";
	}
	cct_setcolor(0, 7);
	cout << endl;
}

void huakuai2(int x0, int y0, char n)
{
	cct_setconsoleborder(8 * y0 + 5, 4 * x0 + 7, 8 * y0 + 5, 4 * x0 + 7);
	cout << "屏幕当前设置为：" << 8 * y0 + 5 << "行" << 4 * x0 + 7 << "列" << endl;
	char sz[N][M];
	int i, j, s = 0, k, a, b;

	for (j = 0; j < x0; j++) {//数组
		for (i = 0; i < y0; i++) {
			s = (rand() % 3) + 1;
			sz[j + 1][i + 1] = s + '0';//+1为了把8，10整成10，12
		}
	}

	cout << "      0";
	for (i = 1; i < y0; i++)//第一行
		cout << setw(8) << i;
	cout << endl;

	//第一排的框
	cout << "  ";
	cct_setcolor(15, 0);
	for (i = 0; i < y0; i++) {
		//Sleep(10);
		if (i == 0)
			cout << "┏━━━┳";
		else if (i == y0 - 1)
			cout << "━━━┓";
		else
			cout << "━━━┳";
	}
	cout << endl;

	//中间带色的
	for (i = 0; i < x0; i++) {
		for (k = 0; k < 3; k++) {//行
			cct_setcolor(0, 7);
			if (k == 1)
				cout << (char)(i + 65) << " ";
			else
				cout << "  ";
			cct_setcolor(15, 0);
			cout << "┃";
			//每行最前面那块

			for (j = 0; j < y0; j++) {
				if (k == 0) {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┏" << "━" << "┓";
				}
				else if (k == 1) {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┃" << sz[i + 1][j + 1] << " " << "┃";
				}
				else {
					cct_setcolor(sz[i + 1][j + 1] - '0', 0);
					cout << "┗" << "━" << "┛";
				}
				cct_setcolor(15, 0);
				cout << "┃";
			}

			//每行最后面那块
			cout << endl;
		}

		if (i != x0 - 1) {
			cct_setcolor(0, 7);
			cout << "  ";
			cct_setcolor(15, 0);
			cout << "┣━━━";
			for (j = 0; j < y0; j++) {
				//Sleep(6);
				if (j == y0 - 1)
					cout << "┫";
				else
					cout << "╋━━━";
			}
			cct_setcolor();
			cout << endl;
		}
	}

	//最后一排的框
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	for (i = 0; i < y0; i++) {
		//Sleep(10);
		if (i == 0)
			cout << "┗━━━┻";
		else if (i == y0 - 1)
			cout << "━━━┛";
		else
			cout << "━━━┻";
	}
	cct_setcolor(0, 7);
	cout << endl;

	if (n >= '7') {
		while (1) {
			cct_getxy(a, b);
			cct_setcolor(0, 7);
			cct_gotoxy(0,4 * x0 + 3);
			cout << "箭头键/鼠标移动，回车键/单击左键选择并结束";
			xuan(sz, x0, y0, n, a, b);
			if (n != '9')
				break;
		}
		
	}
}