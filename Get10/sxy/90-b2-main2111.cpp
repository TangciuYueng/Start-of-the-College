/* ��11 ɳЦ�� 2153396 */
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
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������(֧�����)" << endl;
	cout << "---------------------------------------" << endl;

	cout << "0.�˳�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[��ѡ��:] ";

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
			
			cout << "��С�������������End����...";
			cct_getxy(x1, y1);
			while (1) {
				if (n == '5')
					cin.ignore(65535, '\n');
				cin.getline(end, 99, '\n');
				if ((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D'))
					break;
				else {
					cct_gotoxy(0, y1 + 1);
					cout << "�����������������";
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