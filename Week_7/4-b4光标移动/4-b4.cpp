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
	//cout << "***********************************************************************" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "*                                                                     *" << endl;
	//cout << "***********************************************************************" << endl;
/*���ɰ����ӡ������*/
	int X, Y;//�������ù���λ�ã���Ϊһ��ʼ���ڣ�0��0��
	for (Y = 0; Y <= MAX_Y + 1; Y++)//��������ʱ 0 ��MAX_Y+1
	{
		cout << "*";                                     //������*��
		for (X = 1; X <= MAX_X; X++)
			cout << ((Y > 0 && Y < MAX_Y + 1) ? ' ' : '*'); //�м�Ŀո�
		cout << "*" << endl;                                //���Ҳ��*
    }

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� 
	   ��ĸ���������ظ���λ��*/
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
	
	//int X = 35, Y = 9; ����ϰ�ߣ���TAT ��Ȼ���궨���ʲô���� 
	int X=MAX_X / 2 + 1 ;
	int Y=MAX_Y / 2 + 1 ;
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
				cout << "��Ϸ���������س������ز˵�.";
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
				cout << "��Ϸ���������س������ز˵�.";
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

void move_by_arrow(int i)//ע���ȡ�ַ��ж�ʱ��ֱ���жϡ�k��������k��ascii�룡�� 
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��׼����豸��Ӧ�ľ��
	init_border(hout);
	//int X = 35, Y = 9; ����ϰ�ߣ���TAT ��Ȼ���궨���ʲô���� 
	int X=MAX_X / 2 + 1 ;
	int Y=MAX_Y / 2 + 1 ;
	gotoxy(hout, X, Y);
	while (1)
	{
		int ch;
		ch = _getch();//�����������ASCII���أ�����Ҫ���ж�������
		if (i == 3)
		{
			if (ch == 224)
			{
				ch = _getch();//�����ĵڶ���
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
				cout << "��Ϸ���������س������ز˵�.";
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
			
			if ((int)ch == 224)
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
				cout << "��Ϸ���������س������ز˵�.";
				ch = _getch();
				if (ch == 13)
				{
					cls(hout);
					break;

				}
			}
		}
	}
}//��ע�͵�һ��������

void menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��׼����豸��Ӧ�ľ��
	while (1)
	{
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		cout << "0.�˳�" << endl;
		cout << "[��ѡ��0-4]" << " ";
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
			cout << "\b";
	}
}

int main()
{
	menu();
	return 0;
}
/*����������ASCII��ʹ�д��K��ͬ
������ַ����ص�*/
