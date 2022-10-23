/* 2151298 信11 杨滕超 */

#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>


const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");
	

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
void move_by_ijkl(int i)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//取标准输出设备对应的句柄
	init_border(hout);
	int X = 35, Y = 9;
	gotoxy(hout, X, Y);
	while (1)
	{

		char ch;
		ch = _getch();
		if (i == 1)
		{
			if (ch == 73 || ch == 105)
			{
				if (Y > 1)
				{
					Y--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 74 || ch == 106)
			{
				if (X > 1)
				{
					X--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 75 || ch == 107)
			{
				if (Y < 17)
				{
					Y++;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 76 || ch == 108)
			{
				if (X < 69)
				{
					X++;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 32)
			{

				showch(hout, X, Y, ch);

				gotoxy(hout, X, Y);
			}
			if (ch == 81 || ch == 113)
			{
				X = 0;
				Y = 23;
				gotoxy(hout, X, Y);
				printf("游戏结束，按回车键返回菜单.");
				ch = _getch();
				if (ch == 13)
				{
					cls(hout);
					break;
				}
			}
		}
		if (i == 2)
		{
			if (ch == 73 || ch == 105)
			{
				if (Y > 1)
				{
					Y--;
					gotoxy(hout, X, Y);
				}
				else
				{
					Y = 17;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 74 || ch == 106)
			{
				if (X > 1)
				{
					X--;
					gotoxy(hout, X, Y);
				}
				else
				{
					X = 69;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 75 || ch == 107)
			{
				if (Y < 17)
				{
					Y++;
					gotoxy(hout, X, Y);
				}
				else
				{
					Y = 1;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 76 || ch == 108)
			{
				if (X < 69)
				{
					X++;
					gotoxy(hout, X, Y);
				}
				else
				{
					X = 1;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 32)
			{

				showch(hout, X, Y, ch);

				gotoxy(hout, X, Y);
			}
			if (ch == 81 || ch == 113)
			{
				X = 0;
				Y = 23;
				gotoxy(hout, X, Y);
				printf("游戏结束，按回车键返回菜单.");
				ch = _getch();
				if (ch == 13)
				{
					cls(hout);
					break;

				}

			}
		}
	}
}

void move_by_arrow(int i)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//取标准输出设备对应的句柄
	init_border(hout);
	int X = 35, Y = 9;
	gotoxy(hout, X, Y);
	while (1)
	{
		int ch;
		ch = _getch();
		if (i == 3)
		{
			if (ch == 224)
			{
				ch = _getch();
				if (ch == 72)
				{
					if (Y > 1)
					{
						Y--;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 75)
				{
					if (X > 1)
					{
						X--;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 80)
				{
					if (Y < 17)
					{
						Y++;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 77)
				{
					if (X < 69)
					{
						X++;
						gotoxy(hout, X, Y);
					}

				}
			}
			if (ch == 32)
			{

				showch(hout, X, Y, ch);

				gotoxy(hout, X, Y);
			}
			if (ch == 81 || ch == 113)
			{
				X = 0;
				Y = 23;
				gotoxy(hout, X, Y);
				printf("游戏结束，按回车键返回菜单.");
				ch = _getch();
				if (ch == 13)
				{
					cls(hout);
					break;
				}
			}
		}

		if (i == 4)
		{
			if (ch == 224)
			{
				ch = _getch();
				if (ch == 72)
				{
					if (Y > 1)
					{
						Y--;
						gotoxy(hout, X, Y);
					}
					else
					{
						Y = 17;
						gotoxy(hout, X, Y);
					}
				}
				if (ch == 75)
				{
					if (X > 1)
					{
						X--;
						gotoxy(hout, X, Y);
					}
					else
					{
						X = 69;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 80)
				{
					if (Y < 17)
					{
						Y++;
						gotoxy(hout, X, Y);
					}
					else
					{
						Y = 1;
						gotoxy(hout, X, Y);
					}
				}
				if (ch == 77)
				{
					if (X < 69)
					{
						X++;
						gotoxy(hout, X, Y);
					}
					else
					{
						X = 1;
						gotoxy(hout, X, Y);
					}

				}
			}
			if (ch == 32)
			{

				showch(hout, X, Y, ch);

				gotoxy(hout, X, Y);
			}
			if (ch == 81 || ch == 113)
			{
				X = 0;
				Y = 23;
				gotoxy(hout, X, Y);
				printf("游戏结束，按回车键返回菜单.");
				ch = _getch();
				if (ch == 13)
				{
					cls(hout);
					break;

				}
			}
		}
	}
}

void menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//取标准输出设备对应的句柄
	while (1)
	{
		printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
		printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
		printf("3.用箭头键控制上下左右，边界停止\n");
		printf("4.用箭头键控制上下左右，边界回绕\n");
		printf("0.退出\n");
		printf("[请选择0-4]");
		printf(" ");

		char i;
		i = _getche();
		cls(hout);
		if (i == '1')
			move_by_ijkl(1);
		else if (i == '2')
			move_by_ijkl(2);
		else if (i == '3')
			move_by_arrow(3);
		else if (i == '4')
			move_by_arrow(4);
		else if (i == '0')
			break;
		else
			printf("\b");
	}
}

int main()
{
	menu();
	return 0;
}
/*方向键左键的ASCII码和大写的K相同
输出的字符有重叠*/