/* 2151298 信11 杨滕超 */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
const int N = 80, NUM_KONGGE = 4, RB = 5, CB = 5, TB = 5, TE = 20;
/*end输入*/
void to_be_continued()//缓冲区问题
{
	cout << "本小题结束，请输入End继续...";
	char str[N];
	int i,x,y;
	cct_getxy(x, y);//取坐标以后面恢复光标位置
	while (1)
	{
		cin.ignore(65536, '\n');
		for (i = 0; i < N; i++)//循环开始都变成\0
			str[i] = '\0';
		cct_showch(x, y, ' ',COLOR_BLACK,COLOR_WHITE, NUM_KONGGE);
		cct_gotoxy(x, y);//恢复光标位置
		cin.getline(str, N, '\n');
		for (i = 0; i < 4; i++)
	    {
			if (str[i] >= 'a' && str[i] <= 'z')//转成大写
				str[i] -= 32;
		}
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == '\0')
			break;
		else
		{
			
			cout << "输入错误，请重新输入！！！！" << endl;
		}
	}

}
/*输入函数*/
void input(int* rp, int* cp, int* tgtp ,int choice)
{
	while (1)
	{
		cout << "请输入行数(5-8)：" << endl;
		cin >> *rp;
		if (*rp >= RB && *rp <= RE)
			break;
		
		cin.clear();//不管怎样都清缓冲区
	    cin.ignore(65536, '\n');
		
	}
	while (1)
	{
		cout << "请输入列数(5-10)：" << endl;
		cin >> *cp;
		if (*cp >= CB && *cp <= CE)
			break;
		cin.clear();//不管怎样都清缓冲区
		cin.ignore(65536, '\n');
		
	}
	if (choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 'A' - '0' && choice != 'B' - '0')
	{
		while (1)
		{
			cout << "请输入合成目标(5-20)：" << endl;
			cin >> *tgtp;
			if (*tgtp >= TB && *tgtp <= TE)
				break;
			cin.clear();//不管怎样都清缓冲区
			cin.ignore(65536, '\n');

		}
	}
}
/*输入函数3，确认合并*/
char input3(char*hang,int*lie)
{
	int x, y;
	char ch;
	cct_getxy(x, y);//取坐标以后面恢复光标位置
	while (1)
	{
		cout << "请确认是否把相邻的相同值合并到"<<*hang<<*lie<<"中(Y / N / Q)：";
		ch = _getche();
		if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N' || ch == 'q' || ch == 'Q')
			break;
		else
		{
			cin.ignore(65536, '\n');
			cct_gotoxy(x, y);//输入不对，就回到原来位置重新来一边
		}
	}
	if (ch >= 'a' && ch <= 'z')//小写转成大写
		ch -= 32;
	cout << endl;
	return ch;
}
/*输入函数2，选择行列*/
void input2(int* rp, int* cp,char* hang, int* lie)//rp指向行数，cp指向列数
{
	cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
	int x, y;
	cct_getxy(x, y);//取坐标以后面恢复光标位置
	while (1)
	{
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, NUM_KONGGE);
		cct_gotoxy(x, y);//恢复光标位置
		cin >> *hang;
		cin >> *lie;
		if (*hang >= 'a' && *lie <= 'z')//小写转成大写
			*hang -= 32;

		if ((*hang>= 'A' && *hang<='A' + *rp - 1) && (*lie>=0 && *lie<=*cp - 1))
			break;
		else if(!((*hang >= 'A' && *hang <= 'A' + *rp - 1) && (*lie >= 0 && *lie <= *cp - 1)))
		    cout << "输入错误，请重新输入.";
		cin.ignore(65536, '\n');
	}
}
/*输入函数4，按回车下落除零;输入函数5，按回车新值填充;输入函数6，回车继续新一次合成;输入函数7，回车更高目标*/
void input456(int num)
{
	char ch;
	int x, y;
	cct_getxy(x,y);
	while (1)
	{
		cct_gotoxy(x, y);
		if (num == 4)
			cout << "按回车键进行数组下落除0操作...";
		else if (num == 5)
			cout << "按回车键进行新值填充...";
		else if (num == 6)
			cout << "本次合成结束，按回车键继续新一次的合成...";
		else if (num == 7)
			cout << "按回车键继续向更高目标进发...";
		ch = _getch();
		if (ch == 13)
			break;
	}
}
/*记录得分并输出*/
void fen(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie,int*tgtp,int *zongfen)
{
	int fen, geshu = 0, i, j;
	for (i = 1; i < RE + 1; i++)//记录*的个数
		for (j = 1; j < CE + 1; j++)
			if (map2[i][j] == '*')
				geshu++;
	fen = geshu * map[*hang - 'A' + 1][*lie + 1] * 3;
	*zongfen += fen;
	cout << "本次得分：" << fen << " 总得分：" << *zongfen << " 合成目标：" << *tgtp <<"     " << endl;
	cout << endl;
}
/*随机数填充*/
void myrandom(int map[][CE + 2], char map2[][CE + 2],int max)
{
	srand((unsigned)time(NULL));
	int i, j, k;
	for (i = 1; i < RE+1; i++)
	{
		for (j = 1; j < CE+1; j++)
		{
			if (map2[i][j] == '*')
			{
				if (max > 0 && max < 4)
				{
					k = rand() % 3 + 1;
					map[i][j] = k;

				}
				else if (max == 4)
				{
					k = rand() % 10 + 1;
					if (k >= 1 && k <= 3)
						map[i][j] = 1;
					else if (k >= 4 && k <= 6)
						map[i][j] = 2;
					else if (k >= 7 && k <= 9)
						map[i][j] = 3;
					else if (k == 10)
						map[i][j] = 4;
				}
				else if (max == 5)
				{
					k = rand() % 20 + 1;
					if (k >= 1 && k <= 5)
						map[i][j] = 1;
					else if (k >= 6 && k <= 10)
						map[i][j] = 2;
					else if (k >= 11 && k <= 15)
						map[i][j] = 3;
					else if (k >= 16 && k <= 18)
						map[i][j] = 4;
					else if (k >= 19 && k <= 20)
						map[i][j] = 5;
				}
				else if (max == 6)
				{
					k = rand() % 20 + 1;
					if (k >= 1 && k <= 4)
						map[i][j] = 1;
					else if (k >= 5 && k <= 8)
						map[i][j] = 2;
					else if (k >= 9 && k <= 12)
						map[i][j] = 3;
					else if (k >= 13 && k <= 16)
						map[i][j] = 4;
					else if (k >= 17 && k <= 19)
						map[i][j] = 5;
					else if (k == 20)
						map[i][j] = 6;
				}
				else if (max > 6)
				{
					k = rand() % 20 + 1;
					if (k == 1)
						map[i][j] = max;
					else if (k == 2)
						map[i][j] = max - 1;
					else if (k == 3 || k == 4)
						map[i][j] = max - 2;
					else
						map[i][j] = rand() % (max - 3) + 1;
				}
			}
		}
	}
}
/*找到最大值*/
int find_max(int map[][CE + 2])
{
	int i, j, max=map[0][0];
	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map[i][j] > max)
				max = map[i][j];
	return max;
}
/*回车或者左键确认,还有图形*/
int MouseKeyboardAffirm(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie)//传入选中块的对应鼠标的坐标
{
	int  k = 0, m = 0, loop = 1;
	const int X0 = 4, Y0 = 3;
	//cct_getxy(x0, y0);
	/*注意此时x1，y1的值应为上一次确定下来的块*/
	int X = *lie * 8 + X0, Y = (*hang - 'A') * 4 + Y0, x1 = *lie*8+X0, y1 = (*hang-'A')*4 + Y0, x2=0, y2=0, ret, maction, keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	
	while (loop)
	{
		k = 0;//记录回车或左键的计数器每次循环恢复
		m = 0;//记录方向键的计数器每次循环恢复
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*恢复黑色*/
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
		{
			TurnLightorDark(map, map2, (x1 - X0) / (3 + 5), (y1 - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始

		}
		if (ret == CCT_MOUSE_EVENT)//鼠标操作
		{
			if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
			{
				cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//覆盖掉之前的提示
				cct_gotoxy(0, r * 4 + 3);
			}

			if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)//在框以内
			{
				if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
					cout << "[当前鼠标] " << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
				x1 = X;//记录当前鼠标位置，以便判断下一次移动是否还在原来的块
				y1 = Y;
				TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
			}
			else
			{
				if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
				{
					cct_gotoxy(0, r * 4 + 3);
					cout << "[当前鼠标] 位置非法";
				}
			}
			
			switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK://左键
					k++;//判断有左键和回车，以便后面判断结束
					break;


			}//end of switch
		}//end of if
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
			{
				cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//覆盖掉之前的提示
cct_gotoxy(0, r * 4 + 3);
cout << "[当前按键] : ";
cct_getxy(x2, y2);
			}

			switch (keycode1) {
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((Y - Y0) / (2 + 2) > 0)
								Y -= 4;
							else//到边上了就穿过去
								Y += 4 * (r - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							}
							m++;
							break;
						case KB_ARROW_DOWN:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((Y - Y0) / (2 + 2) < r - 1)
								Y += 4;
							else//到边上了就穿过去
								Y -= 4 * (r - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							}
							m++;
							break;
						case KB_ARROW_LEFT:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((X - X0) / (3 + 5) > 0)
								X -= 8;
							else//到边上了就穿过去
								X += 8 * (c - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							m++;
							break;
						case KB_ARROW_RIGHT:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((X - X0) / (3 + 5) < c - 1)
								X += 8;
							else//到边上了就穿过去
								X -= 8 * (c - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							}
							m++;
							break;
					}
					break;
				case 13://回车
					k++;//判断有左键和回车，以便后面判断结束
					break;


			}//end of switch
		}//end of else if
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2) || k > 0 || m > 0
			|| !((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2))//鼠标不在原来的块或有回车或左键
			loop = 0;

	}


	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	*hang = char((Y - Y0) / (2 + 2) + 'A');
	*lie = (X - X0) / (3 + 5);
	return k;//返回是否有回车或者左键
}
/*回车或左键确认*/
int confirm()
{
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	int x = 0, y = 0, k1 = 0, k2 = 0, ma = 0, ret = 0, k = 0;
	while (k==0)
	{
		k = 0;
		ret = cct_read_keyboard_and_mouse(x, y, ma, k1, k2);
		if (ret == CCT_MOUSE_EVENT)
		{
			if (ma == MOUSE_LEFT_BUTTON_CLICK)//左键
				k++;
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if (k1 == 13 && k2 == 0)//回车
				k++;
		}
	}
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return k;
}
/*按C或左键确认*/
int confirmC()
{
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	int x = 0, y = 0, k1 = 0, k2 = 0, ma = 0, ret = 0, k = 0;
	while (k == 0)
	{
		k = 0;
		ret = cct_read_keyboard_and_mouse(x, y, ma, k1, k2);
		if (ret == CCT_MOUSE_EVENT)
		{
			if (ma == MOUSE_LEFT_BUTTON_CLICK)//左键
				k++;
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if ((k1 == (int)('C')||k1==(int)('c')) && k2 == 0)//按c
				k++;
		}
	}
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return k;
}