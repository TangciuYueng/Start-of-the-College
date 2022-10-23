/* 信11 沙笑因 2153396 */
#include <iostream>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

char menu()
{
	char n;
	int a, b;
	cout << "---------------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版(支持鼠标)" << endl;
	cout << "---------------------------------------" << endl;

	cout << "0.退出" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[请选择:] ";

	while (1) {
		n = _getche();
		cct_getxy(a, b);
		if (n <= '9' && n >= '0')
			break;
		else if (n == 13 || n == '\b')
			cct_gotoxy(10, b);
		else {
			cct_showch(a - 1, b, ' ');
			cct_gotoxy(a - 1, b);
		}
	}
	return n;
}

int main()
{
	char n, end[99];
	int x1, y1, i;
	for (i = 0; i < 99; i++)
		end[i] = '\0';
	while (1) {
		cct_cls();
		n = menu();
		if (n >= '1' && n <= '9') {
			shuru(n);
			
			cout << "本小题结束，请输入End继续...";
			cct_getxy(x1, y1);
			while (1) {
				if (n == '5')
					cin.ignore(65535, '\n');
				cin.getline(end, 99, '\n');
				if ((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D'))
					break;
				else {
					cct_gotoxy(0, y1 + 1);
					cout << "输入错误，请重新输入";
					cct_showch(x1, y1, ' ', 0, 7, 50);
					cct_gotoxy(x1, y1);
				}
			}
		}
		else if (n == '0')
			return 0;




	}


	return 0;
}