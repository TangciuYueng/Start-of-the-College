/* 2151298 ��11 ������ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/


void move_by_ijkl(int i)
{
	
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��׼����豸��Ӧ�ľ��
	init_border(hout);
	int X=33, Y=7;
	while (1) 
	{
		char ch;
		ch=_getch();
		if (i == 1)//choose 1
		{
			if (ch == 73 || ch == 105)//up
			{
				if (Y > 1)
				{
					Y--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 74 || ch == 106)//left
			{
				if (X > 1)
				{
					X--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 75 || ch == 107)//down
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

			if (ch == 81 || ch == 113)
			{
				cout << "��Ϸ���������س������ز˵�.";
				ch = _getch();
				if (ch == 10)
				{
					break;
				}
		}
		if (i == 2)//choose 2
		{
			if (ch == 73 || ch == 105)//up
			{
				if (Y > 1)
				{
					Y--;
					gotoxy(hout, X, Y);
				}
				if (Y == 1)
				{
					Y = 16;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 74 || ch == 106)//left
			{
				if (X > 1)
				{
					X--;
					gotoxy(hout, X, Y);
				}
				if (X == 1)
				{
					X = 68;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 75 || ch == 107)//down
			{
				if (Y < 17)
				{
					Y++;
					gotoxy(hout, X, Y);
				}
				if (Y == 17)
				{
					Y = 2;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 76 || ch == 108)//tight
			{
				if (X < 69)
				{
					X++;
					gotoxy(hout, X, Y);
				}
				if (X == 69)
				{
					X = 2;
					gotoxy(hout, X, Y);
				}

			}

			if (ch == 81 || ch == 113) {
				cout << "��Ϸ���������س������ز˵�.";
				ch=_getch();
				if (ch == 10)
				{
                    break;
				}
					
			}
				


		}
		
	}//ѭ�������ƶ����
	
}

void move_by_arrow(int i);
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��׼����豸��Ӧ�ľ��
	init_border(hout);
	int X = 33, Y = 7;
	while (1) {
		char ch;
		ch = _getch();
		if (i == 3)//choose 3
		{
			if (ch == 38)//up
			{
				if (Y > 1)
				{
					Y--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 37)//left
			{
				if (X > 1)
				{
					X--;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 40)//down
			{
				if (Y < 17)
				{
					Y++;
					gotoxy(hout, X, Y);
				}

			}
			if (ch == 39)//right
			{
				if (X < 69)
				{
					X++;
					gotoxy(hout, X, Y);
				}

			}

			if (ch == 81 || ch == 113)
			{
				cout << "��Ϸ���������س������ز˵�.";
				ch = _getch();
				if (ch == 10)
				{
					break;
				}
			}
			if (i == 4)//choose 4
			{
				if (ch == 38)//up
				{
					if (Y > 1)
					{
						Y--;
						gotoxy(hout, X, Y);
					}
					if (Y == 1)
					{
						Y = 16;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 37)//left
				{
					if (X > 1)
					{
						X--;
						gotoxy(hout, X, Y);
					}
					if (X == 1)
					{
						X = 68;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 40)//down
				{
					if (Y < 17)
					{
						Y++;
						gotoxy(hout, X, Y);
					}
					if (Y == 17)
					{
						Y = 2;
						gotoxy(hout, X, Y);
					}

				}
				if (ch == 39)//right
				{
					if (X < 69)
					{
						X++;
						gotoxy(hout, X, Y);
					}
					if (X == 69)
					{
						X = 2;
		
						gotoxy(hout, X, Y);
					}

				}

				if (ch == 81 || ch == 113)
				{
					cout << "��Ϸ���������س������ز˵�.";
					ch = _getch();
					if (ch == 10)
					{
						break;
					}

				}



			}

		}//ѭ�������ƶ����
	}
}
void menu()
{
	while (1)
	{
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		int i;
		i = _getch();
		if (i == 1)
			move_by_ijkl(i);
		else if (i == 2)
			move_by_ijkl(i);
		else if (i == 3)
			move_by_arrow(i);
		else if (i == 4)
			move_by_arrow(i);
		else if (i == 0)
			break;
	}

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��׼����豸��Ӧ�ľ��
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	int ch=1,i;
	
	i = ch;
	menu(i);

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	

	
	return 0;
}