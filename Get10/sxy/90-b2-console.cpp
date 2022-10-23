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

void xuan(char sz[N][M], int x0, int y0, char n, int a, int b,bool bo)
{
	int sbx, sby, sbxingwei, jp1, jp2, fs, X = 1, Y = 1, loop = 1;
	char zb[80], ch;
	while (loop) {
		loop = 0;
		cct_enable_mouse();//可以用鼠标
		cct_setcursor(CURSOR_INVISIBLE);//光标不显示
		if (bo) {
			cct_gotoxy(4, 3);
			biansai(1, 1, sz, 7);
		}
		while (1) {
			fs = cct_read_keyboard_and_mouse(sbx, sby, sbxingwei, jp1, jp2);//鼠标为0，键盘为1
			if (fs == 1) {//键盘
				if (jp1 == 224) {
					biansai(X, Y, sz, 0);//变回去
					if (jp2 == KB_ARROW_UP) {
						if (X >= 2 && X <= x0)
							X--;
						else if (X == 1)
							X = x0;
					}
					else if (jp2 == KB_ARROW_DOWN) {
						if (X >= 1 && X < x0)
							X++;
						else if (X == x0)
							X = 1;
					}
					else if (jp2 == KB_ARROW_LEFT) {
						if (Y >= 2 && Y <= y0)
							Y--;
						else if (Y == 1)
							Y = y0;
					}
					else if (jp2 == KB_ARROW_RIGHT) {
						if (Y >= 1 && Y < y0)
							Y++;
						else if (Y == y0)
							Y = 1;
					}
					cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
					cct_setcolor(0, 7);
					cout << "[当前键盘] " << (char)(X + 64) << "行" << Y - 1 << "列";
					biansai(X, Y, sz, 7);//变色
				}
				else if (jp1 == 13) {
					if (Y >= 1 && X >= 1) {
						int x2, y2;
						ch = sz[X][Y];
						if (sz[X][Y + 1] != ch && sz[X][Y - 1] != ch && sz[X + 1][Y] != ch && sz[X - 1][Y] != ch) {//检验是否存在星号
							cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
							cct_gotoxy(0, 4 * x0 + 3);
							cout << endl << "周围无相同值";
							bo = 0;
							cct_getxy(x2, y2);//提示语输出的位置
							continue;
						}
						else {
							cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
							cct_gotoxy(0, 4 * x0 + 3);
							cout << "选中了" << (char)(X + 64) << "行" << Y - 1 << "列";
							break;
						}
					}
				}
				else if (jp1 == 'q' || jp1 == 'Q') {
					if (n == '7') {
						cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
						cct_gotoxy(0, 4 * x0 + 3);
						cout << "选中了" << (char)(X + 64) << "行" << Y - 1 << "列";
						break;
					}
					else
						break;
				}
			}
			else if (fs == 0) {//鼠标			
				biansai(X, Y, sz, 0);//变回去
				if (sbx >= 4 && sbx <= 4 * (2 * y0 - 1) + 5 && sby >= 3 && sby <= x0 * 4 - 1 + 2) {
					if ((sbx + 4) % 8 <= 5 && (sbx + 4) % 8 >= 0) {
						Y = (sbx + 4) / 8;
					}
					else {
						cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
						cct_gotoxy(0, 4 * x0 + 3);
						cct_setcolor(0, 7);
						cout << "[当前鼠标] 位置非法";
					}
					if ((sby + 1) % 4 <= 2 && (sby + 1) % 4 >= 0) {
						X = (sby + 1) / 4;
						biansai(X, Y, sz, 7);
						cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
						cct_gotoxy(0, 4 * x0 + 3);
						cct_setcolor(0, 7);
						cout << "[当前键盘] " << (char)(X + 64) << "行" << Y - 1 << "列";
					}
					else {
						cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
						cct_gotoxy(0, 4 * x0 + 3);
						cct_setcolor(0, 7);
						cout << "[当前鼠标] 位置非法";
					}
				}
				else {
					cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
					cct_gotoxy(0, 4 * x0 + 3);
					cct_setcolor(0, 7);
					cout << "[当前鼠标] 位置非法";
				}
				if (sbxingwei == MOUSE_LEFT_BUTTON_CLICK) {
					cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
					cct_gotoxy(0, 4 * x0 + 3);
					cct_setcolor(0, 7);
					cout << "选中了" << (char)(X + 64) << "行" << Y - 1 << "列";
					break;
				}
				else if (sbxingwei == MOUSE_RIGHT_BUTTON_CLICK) {
					if (n == '7') {
						cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
						cct_gotoxy(0, 4 * x0 + 3);
						cct_setcolor(0, 7);
						cout << "选中了" << (char)(X + 64) << "行" << Y - 1 << "列";
						break;
					}
					else
						break;
				}
			}
		}
		cct_disable_mouse();
		cct_setcursor(CURSOR_VISIBLE_NORMAL);

		if (n != '7') {
			zb[0] = (char)(X + 64);
			zb[1] = (char)(Y - 1 + '0');
			int ret = jilu(sz, zb, x0, y0, n, a, b, X, Y);
			if (ret)//周围没有相同值
			{
				cct_gotoxy(0, 4 * x0 + 3);
				cct_setcolor(0, 14);
				cout << "周围没有相同值" << endl;
				cct_setcolor(0, 7);
				Sleep(500);
				loop = 1;
			}
		}
	}
	
}

void biansai(int X, int Y, char sz[N][M],int se,bool bo)
{
	int i, j;
	char s;
	i = 4 * (2 * Y - 1);
	j = X * 4 - 1;
	if (bo)
		s = sz[X][Y] + 1;
	else
		s = sz[X][Y];
	cct_gotoxy(i, j);
	cct_setcolor(s - '0', se);
	cout << "┏" << "━" << "┓";
	cct_gotoxy(i, j + 1);
	cct_setcolor(s - '0', se);
	cout << "┃" << s << " " << "┃";
	cct_gotoxy(i, j + 2);
	cct_setcolor(s - '0', se);
	cout << "┗" << "━" << "┛";
}

void kuaidown(char zb[], char sz[N][M], char jl[N][M], int x0, int y0, char n, int a, int b, int X0, int Y0)
{
	int i, j, fs, sbx, sby, sbxingwei, jp1, jp2, t = 300, X, Y;
	cct_enable_mouse();//可以用鼠标
	cct_setcursor(CURSOR_INVISIBLE);//光标不显示

	for (i = 0; i < x0; i++) {
		for (j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				biansai(i + 1, j + 1, sz, 7);
		}
	}
	cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
	cct_gotoxy(0, 4 * x0 + 3);
	cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
	while (1) {
		fs = cct_read_keyboard_and_mouse(sbx, sby, sbxingwei, jp1, jp2);//鼠标为0，键盘为1
		Y = (sbx + 4) / 8;
		X = (sby + 1) / 4;
		if ((fs == 0 && sbxingwei == MOUSE_LEFT_BUTTON_CLICK) || (fs == 1 && jp1 == 13) || !(X == X0 && Y == Y0))
			break;
	}

	if (fs == 1 && jp1 == 13 || fs == 0 && sbxingwei == MOUSE_LEFT_BUTTON_CLICK) {
		hebing(zb, sz, jl, x0, y0, n);
		
		for (i = 0; i < x0; i++) {
			for (j = 0; j < y0; j++) {
				if (jl[i + 1][j + 1] == '*')
					xiaochu(i + 1, j + 1);
				else if (jl[i + 1][j + 1] == '1') {//闪动
					biansai(i + 1, j + 1, sz, 7, 0);
				}
			}
		}
		if (n == '8') {
			cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
			cct_gotoxy(0, 4 * x0 + 3);
			cout << "按回车/单击左键，进行下落操作";

			while (1) {
				fs = cct_read_keyboard_and_mouse(sbx, sby, sbxingwei, jp1, jp2);//鼠标为0，键盘为1
				if ((fs == 0 && sbxingwei == MOUSE_LEFT_BUTTON_CLICK) || (fs == 1 && jp1 == 13) || !(X == X0 && Y == Y0))
					break;
			}
		}
		xialuotuxing(sz, jl, x0, y0);
		if (n == '8') {
			cct_showch(0, 4 * x0 + 3, ' ', 0, 7, 60);//清除一开始那句话
			cct_gotoxy(0, 4 * x0 + 3);
			cout << "按回车/单击左键，进行填充操作";

			while (1) {
				fs = cct_read_keyboard_and_mouse(sbx, sby, sbxingwei, jp1, jp2);//鼠标为0，键盘为1
				if ((fs == 0 && sbxingwei == MOUSE_LEFT_BUTTON_CLICK) || (fs == 1 && jp1 == 13) || !(X == X0 && Y == Y0))
					break;
			}
		}
		int m = 1, n = 1;
		char zuida = sz[1][1];
		for (m=1; m <= x0; m++)
			for (n=1; n <= y0; n++)
				if (sz[m][n] > zuida)
					zuida = sz[m][n];

		tianchong(sz, jl, 5, x0, y0, '8',zuida);
		
		kuaitianchong(sz, jl, x0, y0);
	}
	else
		xuan(sz, x0, y0, n, a, b, 0);
}

void xiaochu(int X, int Y)
{
	int i, j;
	i = 4 * (2 * Y - 1);
	j = X * 4 - 1;
	cct_gotoxy(i, j);
	cct_setcolor(15, 15);
	cout << "      ";
	cct_gotoxy(i, j + 1);
	cout << "      ";
	cct_gotoxy(i, j + 2);
	cout << "      ";
	cct_setcolor(0, 7);
}

void xialuoyici(int X, int Y, int x0, int y0, char sz[][M], char jl[][M])
{
	//此时传入的XY是数组对应的行列下标，x0,y0是最开始输入的行列数
	int m = Y * 8 - 4, n = X * 4 - 1;//转化为cmd窗口的坐标
	for (int k = 0; k < 4; k++) {
		cct_setcolor(15, 15);//亮白色
		cct_gotoxy(m, n + k);//开始时x，y为每个方块左上角坐标
		cout << "  " << "  " << "  ";
		cct_gotoxy(m, n + k + 1);
		cout << "  " << "  " << "  ";
		cct_gotoxy(m, n + k + 2);
		cout << "  " << "  " << "  ";
		cct_setcolor();

		cct_setcolor(sz[X + 1][Y], 0);//黑色,注意xy在数组表示反过来
		cct_gotoxy(m, n + k + 1);//开始时x，y为每个方块左上角坐标
		cout << "┏" << "━" << "┓";
		cct_gotoxy(m, n + k + 2);
		cout << "┃" << setw(2)<<setiosflags(ios::left)<<sz[X + 1][Y]<< "┃";
		cct_gotoxy(m, n + k + 3);
		cout << "┗" << "━" << "┛";
		cct_setcolor();

		Sleep(10);
	}
	/*回到边界，重新打印*/
	n += 3;
	cct_gotoxy(m, n);
	cct_setcolor(15, 0);//白底黑色
	cout << "━━━";
	cct_setcolor();
}

void xialuotuxing(char sz[N][M], char jl[N][M], int x0, int y0)
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
					xialuoyici(i - 1, j, x0, y0, sz, jl);
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
		xialuotuxing(sz, jl, x0, y0);
}

void kuaitianchong(char sz[N][M], char jl[N][M], int x0, int y0)
{
	for (int i = 0; i < x0; i++) {
		for (int j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				biansai(i + 1, j + 1, sz, 0, 0);
		}
	}
}

