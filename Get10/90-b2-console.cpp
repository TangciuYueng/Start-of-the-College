/* 2151298 信11 杨滕超 */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*选项5，6*/
void choice56(int map[][CE + 2], char map2[][CE + 2],int*r,int*c,int choice)
{
	const int R0 = 37, C0 = 23, R1 = 45, C1 = 27;
	/*横着的：左边4格子，中间（5+1）*列数 在右边3个格子 
	竖着的 上边3个，中间5×行数，下边5个*/
	/* 5hang*5lie 37hang23lie  6  5 37hang26lie  +3
	5  6 43hang23lie  +6
	5  6 49hang23lie
	
	选项六
	5 5 45宽度27列  6 5  45宽度31 +4
	5 6 53宽度27   +8*/
	if (choice == 5)
	{
		cct_setconsoleborder((*c - 5) * 6 + R0, (*r - 5) * 3 + C0, (*c - 5) * 6 + R0, (*r - 5) * 3 + C0);
		cout << "屏幕当前设置为：" << (*c - 5) * 6 + R0 << "行" << (*r - 5) * 3 + C0 << "列" << endl;
		
		output56(map, map2, *r, *c,choice);
	}
	else 
	{
		cct_setconsoleborder((*c - 5) * 8 + R1, (*r - 5) * 4 + C1, (*c - 5) * 8 + R1, (*r - 5) * 4 + C1);
		cout << "屏幕当前设置为：" << (*c - 5) * 8 + R1 << "行" << (*r - 5) * 4 + C1 << "列" << endl;
		output56(map, map2, *r, *c,choice);
	}
	cout << endl;
	
}
/*输出界面*/
void output56(int map[][CE + 2], char map2[][CE + 2], int r, int c,int choice)
{
	int i, j, k, x, y, x1, y1;
	const int TIME = 10, X = 4, Y = 3;
	/*列标*/
	if (choice == 5)
	{
		cout << " ";//一个空格
		for (i = 0; i < c; i++)//第一行的列标志
		{
			cout << setw(6) << i;
		}
	}
	else//6789选项
	{
		for (i = 0; i < c; i++)//第一行的列标志
		{
			if (i == 0)
				cout << setw(7) << i;
			else
				cout << setw(8) << i;
		}
	}
	cout << endl;
	
	/*白色背景*/
	/*第一行边框*/
	cout << "  ";//两个空格
	cct_setcolor(15,0);
	if (choice == 5)
	{
		for (k = 0; k < c * 3 + 2; k++)//上面的边
		{
			Sleep(TIME);
			if (k == 0)
				cout << "┏";
			else if (k == c * 3 + 2 - 1)
				cout << "┓";
			else
				cout << "━";
		}
	}
	else//6789选项
	{
		for (k = 0; k < c * 4 + 1; k++)
		{
			if(choice==6)
			    Sleep(TIME);
			if (k == 0)
				cout << "┏";
			else if (k == c * 4)
				cout << "┓";
			else if (k % 4 == 0)
				cout << "┳";
			else
				cout << "━";
		}
	}
	cct_setcolor();
	cout << endl;
	/*中间部分背景*/
	for (i = 0; i < r; i++)//行
	{
		for (j = 0; j < 3; j++)//列
		{
			if (j != 1)
				cout << "  ";//两个空格
			else
				cout << char('A' + i) << ' ';
			cct_setcolor(15, 0);
			if (choice == 5)
				for (k = 0; k < c * 3 + 2; k++)
				{
					Sleep(TIME);
					if (k == 0)
						cout << "┃";
					else if (k == c * 3 + 2 - 1)
						cout << "┃" ;
					else
						cout <<"  ";
				}
			else//6789选项
				for (k = 0; k < c * 4+1; k++)
				{
					if(choice==6)
					    Sleep(TIME);
					if(k==c*4)
						cout << "┃" ;
					else if (k %4==0)
						cout << "┃";
					else
						cout <<  "  ";
				}
			
			cct_setcolor();
			cout << endl;
		}
		if ((choice == 6 || choice == 7 || choice == 8 || choice == 9) && i != r - 1)
		{
			cout << "  ";
			cct_setcolor(15, 0);
			for (k = 0; k < c * 4 + 1; k++)
			{
				if(choice==6)
			    	Sleep(TIME);
				if (k == 0)
					cout << "┣";
				else if (k == c * 4)
					cout << "┫";
				else if (k % 4 == 0)
					cout << "╋";
				else
					cout << "━";
			}
			cct_setcolor();
			cout << endl;
		}
	}
	/*最后一行边框*/
	cout << "  ";//1个空格
	cct_setcolor(15, 0);
	if (choice == 5)
	{
		for (k = 0; k < c * 3 + 2; k++)//下面的边
		{
			Sleep(TIME);
			if (k == 0)
				cout << "┗";
			else if (k == c * 3 + 2 - 1)
				cout << "┛";
			else
				cout << "━";
		}
	}
	else//6789选项
	{
		for (k = 0; k < c * 4 + 1; k++)
		{
			if (choice == 6)
		    	Sleep(TIME);
			if (k == 0)
				cout << "┗";
			else if (k == c * 4)
				cout << "┛";
			else if (k % 4 == 0)
				cout << "┻";
			else
				cout << "━";
		}
	}
	cct_setcolor();
	/*输出数组*/
	x = X;
	y = Y;
	cout << setiosflags(ios::left);
	for (i = 1; i < r+1; i++)
	{
		cct_gotoxy(x, y);
		for (j = 1; j < c+1; j++)
		{
			cct_setcolor( map[i][j],0);
			cout << "┏"  << "━"  << "┓";
			cct_setcolor();
			if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			{
				cct_getxy(x1, y1);
				cct_gotoxy(x1 + 2, y1);
			}
		}
		cct_gotoxy(x, y + 1);
		
		for (j = 1; j < c + 1; j++)
		{
			cct_setcolor(map[i][j], 0);
			cout << "┃"  <<setw(2)<< map[i][j] << "┃";
			cct_setcolor();
			if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			{
				cct_getxy(x1, y1);
				cct_gotoxy(x1 + 2, y1);
			}
		}
		cct_gotoxy(x, y + 2);
		for (j = 1; j < c + 1; j++)
		{
			cct_setcolor(map[i][j], 0);
			cout << "┗"  << "━"  << "┛";
			cct_setcolor();
			if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			{
				cct_getxy(x1, y1);
				cct_gotoxy(x1 + 2, y1);
			}
		}
		if (choice == 5)
			y += 3;//到下一行的方块开始
		else if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			y += 4;

	}//end of for
	cout << endl << endl;
}
/*色块变色*/
void TurnLightorDark(int map[][CE + 2], char map2[][CE + 2],int x,int y,int loop,int r,int c)
{
	const int X0 = 4, Y0 = 3;
	int x1, y1;
	if (x >= 0 && y >= 0 && y < r && x < c)//保证在表内
	{
		cct_gotoxy(x * 8 + X0, y * 4 + Y0);//此时大写X，Y为每个方块左上角坐标
		if (loop == 1)
			cct_setcolor(map[y + 1][x + 1], 7);//暗白色,注意xy在数组表示反过来
		else if (loop == 2)
			cct_setcolor(map[y + 1][x + 1], 0);//黑色,注意xy在数组表示反过来
		else if (loop == 3)
			cct_setcolor(map[y + 1][x + 1], 15);//亮白色,注意xy在数组表示反过来
		else if (loop == 4)
			cct_setcolor(15, 15);
		cout << setiosflags(ios::left);
		if (loop != 4)
		{
			cct_getxy(x1, y1);
			cout << "┏" << "━" << "┓";
			cct_gotoxy(x1, y1 + 1);
			cout << "┃" <<setw(2)<< map[y + 1][x + 1] << "┃";
			cct_gotoxy(x1, y1 + 2);
			cout << "┗" << "━" << "┛";
			cct_setcolor();
		}
		else
		{
			cct_getxy(x1, y1);
			cout << "  " << "  " << "  ";
			cct_gotoxy(x1, y1 + 1);
			cout << "  " << "  " << "  ";
			cct_gotoxy(x1, y1 + 2);
			cout << "  " << "  " << "  ";
			cct_setcolor();
		}
		
	}
}
/*鼠标键盘选择*/
int MouseKeyboard(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie,int choice)
{
	int x0, y0, k=0;
	const int X0 = 4, Y0 = 3;
	cct_getxy(x0, y0);
	int X = X0, Y = Y0, x1 = *lie * 8 + X0, y1 = (*hang - 'A') * 4 + Y0,x2,y2, ret, maction, keycode1, keycode2, loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	
	while (loop)
	{
		
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*恢复黑色*/
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//鼠标不在原来的块
			TurnLightorDark(map, map2, (x1 - X0) / (3 + 5), (y1 - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始

		if (ret == CCT_MOUSE_EVENT)//鼠标操作
		{
			cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//覆盖掉之前的提示
			cct_gotoxy(0, r * 4 + 3);
			/*保证在小块以内，且不出边框*/
			//cout << "X=" << X << " Y=" << Y << endl;
			if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)
			{
				cout << "[当前鼠标] " << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
				x1 = X;//记录当前鼠标位置，以便判断下一次移动是否还在原来的块
				y1 = Y;
				TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
			}
			else
				cout << "[当前鼠标] 位置非法";
			switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK://左键
					if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)//在框以内
					{
						cct_gotoxy(0, r * 4 + 3);
						cout << "选中了 ";
						cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
						cout << endl;
						loop = 0;//停止循环
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK://右键
					k = 1;
					break;
			}//end of switch
		}//end of if
		else if (ret == CCT_KEYBOARD_EVENT)//键盘
		{
			cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//覆盖掉之前的提示
			cct_gotoxy(0, r * 4 + 3);
			cout << "[当前按键] : ";
			cct_getxy(x2, y2);
			switch (keycode1) {
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((Y - Y0) / (2 + 2) > 0)
								Y -= 4;
							else//到边上了就穿过去
								Y += 4*(r-1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout<< char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							break;
						case KB_ARROW_DOWN:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((Y - Y0) / (2 + 2) < r-1)
								Y += 4;
							else//到边上了就穿过去
								Y -= 4 * (r - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
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
							break;
						case KB_ARROW_RIGHT:
							/*恢复黑色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//传入数组坐标，从零开始
							if ((X - X0) / (3 + 5) < c-1)
								X += 8;
							else//到边上了就穿过去
								X -= 8 * (c - 1);
							/*变色*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//传入数组坐标，从零开始
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
							break;
					}
					break;
				case 13://回车
					cct_gotoxy(0, r * 4 + 3);
					cout << "选中了 ";
					cout << char((Y - Y0) / (2 + 2) + 'A') << "行" << (X - X0) / (3 + 5) << "列   ";
					cout << endl;
					loop = 0;
					break;

				case (int)'Q':
				case (int)'q':
					k = 1;
					break;
			}//end of switch
		}//end of else if

		if (k)//右键或按q/Q结束
			break;
	}
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	*hang = char((Y - Y0) / (2 + 2) + 'A');
	*lie = (X - X0) / (3 + 5);
	return k;//告诉外面按了右键或者q/Q
	
}
/*选中的相同相邻的色块一起变色*/
void MulLightorDark(int map[][CE + 2], char map2[][CE + 2], int r, int c,char hang,int lie, int loop)
{
	int i, j;
	for (i = 1; i < RE + 1; i++)
	{
		for (j = 1; j < CE + 1; j++)
		{
			if (map2[i][j] == '*' && !(hang - 'A' == i - 1 && lie == j - 1))//是*但不是选中的坐标
			{
				TurnLightorDark(map, map2, j - 1, i - 1,loop, r, c);
			}
		}
	}
}
/*消去变白*/
void MulBlank(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie)
{
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (map2[i][j] == '*' && !(hang - 'A' == i - 1 && lie == j - 1))//是*但不是选中的坐标85
			{
				TurnLightorDark(map, map2, j - 1, i - 1, 4, r, c);//变成白色
			}
		}
	}
}
/*闪动*/
void shining(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie)
{
	int i;
	const int time = 25;
	for (i = 0; i < 15; i++)
	{
		TurnLightorDark(map, map2, lie, hang - 'A', i%2+1, r, c);
		Sleep(time);
		TurnLightorDark(map, map2, lie, hang - 'A', i % 2 + 2, r, c);
		Sleep(time);
	}
}
/*下落一格*/
void Drop_Once(int map[][CE + 2], char map2[][CE + 2], int r, int c, int i, int j)
{
	const int X0 = 4, Y0 = 3, time = 10;
	//i,j为数组的下标
	int x= (j - 1) * 8 + X0, y= (i - 1) * 4 + Y0;//x,y现在是块的左上角坐标
	int k;
	cout << setiosflags(ios::left);

	for (k = 0; k < 4; k++)
	{
		cct_setcolor(15, 15);//亮白色
		cct_gotoxy(x, y+k);//开始时x，y为每个方块左上角坐标
		cout << "  " << "  " << "  ";
		cct_gotoxy(x, y+k + 1);
		cout << "  " << "  " << "  ";
		cct_gotoxy(x, y+k + 2);
		cout << "  " << "  " << "  ";
		cct_setcolor();

		cct_setcolor(map[i+1][j],0);//黑色,注意xy在数组表示反过来
		cct_gotoxy(x, y+k + 1);//开始时x，y为每个方块左上角坐标
		cout << "┏" << "━" << "┓";
		cct_gotoxy(x, y+k + 2);
		cout << "┃" << setw(2) << map[i+1][j] << "┃";
		cct_gotoxy(x, y+k + 3);
		cout << "┗" << "━" << "┛";
		cct_setcolor();

		Sleep(time);
	}
	/*回到边界，重新打印*/
	y+=3;
	cct_gotoxy(x, y);
	cct_setcolor(15, 0);//白底黑色
	cout << "━━━";
	cct_setcolor();

}
/*色块下落*/
void Drop(int map[][CE + 2], char map2[][CE + 2], int r, int c)
{
	int i, j, k = 0;
	for (j = 1; j < CE + 1; j++)//从每一列开始
		for (i = RE; i > 1; i--)//不管第一行
		{
			if (map2[i][j] == '*' && map2[i - 1][j] != '*')//发现是*
			{
				map[i][j] = map[i - 1][j];//上面赋值给下面
				map[i - 1][j] = 0;
				map2[i - 1][j] = '*';
				map2[i][j] = '0';
				Drop_Once(map, map2, r, c, i-1, j);//上面的向下移动一格
			}
		}
	/*检查还没有没0在*上面，在输出范围内*/
	for (i = 1; i < r; i++)//不用检查最后一行
	{
		for (j = 1; j < CE; j++)
		{
			if (map[i][j] > 0 && map[i + 1][j] == 0)//0在*上面就不对了
			{
				k++;
				break;
			}
		}
	}
	if (k)
		Drop(map, map2, r, c);
}
/*空白位置填充色块*/
void fill(int map[][CE + 2], char map2[][CE + 2], int r, int c)
{
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (map2[i][j] == '*' )//是*,需要填充
			{
				TurnLightorDark(map, map2, j - 1, i - 1, 2, r, c);
			}
		}
	}
}