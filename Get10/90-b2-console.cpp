/* 2151298 ��11 ������ */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
/*ѡ��5��6*/
void choice56(int map[][CE + 2], char map2[][CE + 2],int*r,int*c,int choice)
{
	const int R0 = 37, C0 = 23, R1 = 45, C1 = 27;
	/*���ŵģ����4���ӣ��м䣨5+1��*���� ���ұ�3������ 
	���ŵ� �ϱ�3�����м�5���������±�5��*/
	/* 5hang*5lie 37hang23lie  6  5 37hang26lie  +3
	5  6 43hang23lie  +6
	5  6 49hang23lie
	
	ѡ����
	5 5 45���27��  6 5  45���31 +4
	5 6 53���27   +8*/
	if (choice == 5)
	{
		cct_setconsoleborder((*c - 5) * 6 + R0, (*r - 5) * 3 + C0, (*c - 5) * 6 + R0, (*r - 5) * 3 + C0);
		cout << "��Ļ��ǰ����Ϊ��" << (*c - 5) * 6 + R0 << "��" << (*r - 5) * 3 + C0 << "��" << endl;
		
		output56(map, map2, *r, *c,choice);
	}
	else 
	{
		cct_setconsoleborder((*c - 5) * 8 + R1, (*r - 5) * 4 + C1, (*c - 5) * 8 + R1, (*r - 5) * 4 + C1);
		cout << "��Ļ��ǰ����Ϊ��" << (*c - 5) * 8 + R1 << "��" << (*r - 5) * 4 + C1 << "��" << endl;
		output56(map, map2, *r, *c,choice);
	}
	cout << endl;
	
}
/*�������*/
void output56(int map[][CE + 2], char map2[][CE + 2], int r, int c,int choice)
{
	int i, j, k, x, y, x1, y1;
	const int TIME = 10, X = 4, Y = 3;
	/*�б�*/
	if (choice == 5)
	{
		cout << " ";//һ���ո�
		for (i = 0; i < c; i++)//��һ�е��б�־
		{
			cout << setw(6) << i;
		}
	}
	else//6789ѡ��
	{
		for (i = 0; i < c; i++)//��һ�е��б�־
		{
			if (i == 0)
				cout << setw(7) << i;
			else
				cout << setw(8) << i;
		}
	}
	cout << endl;
	
	/*��ɫ����*/
	/*��һ�б߿�*/
	cout << "  ";//�����ո�
	cct_setcolor(15,0);
	if (choice == 5)
	{
		for (k = 0; k < c * 3 + 2; k++)//����ı�
		{
			Sleep(TIME);
			if (k == 0)
				cout << "��";
			else if (k == c * 3 + 2 - 1)
				cout << "��";
			else
				cout << "��";
		}
	}
	else//6789ѡ��
	{
		for (k = 0; k < c * 4 + 1; k++)
		{
			if(choice==6)
			    Sleep(TIME);
			if (k == 0)
				cout << "��";
			else if (k == c * 4)
				cout << "��";
			else if (k % 4 == 0)
				cout << "��";
			else
				cout << "��";
		}
	}
	cct_setcolor();
	cout << endl;
	/*�м䲿�ֱ���*/
	for (i = 0; i < r; i++)//��
	{
		for (j = 0; j < 3; j++)//��
		{
			if (j != 1)
				cout << "  ";//�����ո�
			else
				cout << char('A' + i) << ' ';
			cct_setcolor(15, 0);
			if (choice == 5)
				for (k = 0; k < c * 3 + 2; k++)
				{
					Sleep(TIME);
					if (k == 0)
						cout << "��";
					else if (k == c * 3 + 2 - 1)
						cout << "��" ;
					else
						cout <<"  ";
				}
			else//6789ѡ��
				for (k = 0; k < c * 4+1; k++)
				{
					if(choice==6)
					    Sleep(TIME);
					if(k==c*4)
						cout << "��" ;
					else if (k %4==0)
						cout << "��";
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
					cout << "��";
				else if (k == c * 4)
					cout << "��";
				else if (k % 4 == 0)
					cout << "��";
				else
					cout << "��";
			}
			cct_setcolor();
			cout << endl;
		}
	}
	/*���һ�б߿�*/
	cout << "  ";//1���ո�
	cct_setcolor(15, 0);
	if (choice == 5)
	{
		for (k = 0; k < c * 3 + 2; k++)//����ı�
		{
			Sleep(TIME);
			if (k == 0)
				cout << "��";
			else if (k == c * 3 + 2 - 1)
				cout << "��";
			else
				cout << "��";
		}
	}
	else//6789ѡ��
	{
		for (k = 0; k < c * 4 + 1; k++)
		{
			if (choice == 6)
		    	Sleep(TIME);
			if (k == 0)
				cout << "��";
			else if (k == c * 4)
				cout << "��";
			else if (k % 4 == 0)
				cout << "��";
			else
				cout << "��";
		}
	}
	cct_setcolor();
	/*�������*/
	x = X;
	y = Y;
	cout << setiosflags(ios::left);
	for (i = 1; i < r+1; i++)
	{
		cct_gotoxy(x, y);
		for (j = 1; j < c+1; j++)
		{
			cct_setcolor( map[i][j],0);
			cout << "��"  << "��"  << "��";
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
			cout << "��"  <<setw(2)<< map[i][j] << "��";
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
			cout << "��"  << "��"  << "��";
			cct_setcolor();
			if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			{
				cct_getxy(x1, y1);
				cct_gotoxy(x1 + 2, y1);
			}
		}
		if (choice == 5)
			y += 3;//����һ�еķ��鿪ʼ
		else if (choice == 6 || choice == 7 || choice == 8 || choice == 9)
			y += 4;

	}//end of for
	cout << endl << endl;
}
/*ɫ���ɫ*/
void TurnLightorDark(int map[][CE + 2], char map2[][CE + 2],int x,int y,int loop,int r,int c)
{
	const int X0 = 4, Y0 = 3;
	int x1, y1;
	if (x >= 0 && y >= 0 && y < r && x < c)//��֤�ڱ���
	{
		cct_gotoxy(x * 8 + X0, y * 4 + Y0);//��ʱ��дX��YΪÿ���������Ͻ�����
		if (loop == 1)
			cct_setcolor(map[y + 1][x + 1], 7);//����ɫ,ע��xy�������ʾ������
		else if (loop == 2)
			cct_setcolor(map[y + 1][x + 1], 0);//��ɫ,ע��xy�������ʾ������
		else if (loop == 3)
			cct_setcolor(map[y + 1][x + 1], 15);//����ɫ,ע��xy�������ʾ������
		else if (loop == 4)
			cct_setcolor(15, 15);
		cout << setiosflags(ios::left);
		if (loop != 4)
		{
			cct_getxy(x1, y1);
			cout << "��" << "��" << "��";
			cct_gotoxy(x1, y1 + 1);
			cout << "��" <<setw(2)<< map[y + 1][x + 1] << "��";
			cct_gotoxy(x1, y1 + 2);
			cout << "��" << "��" << "��";
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
/*������ѡ��*/
int MouseKeyboard(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie,int choice)
{
	int x0, y0, k=0;
	const int X0 = 4, Y0 = 3;
	cct_getxy(x0, y0);
	int X = X0, Y = Y0, x1 = *lie * 8 + X0, y1 = (*hang - 'A') * 4 + Y0,x2,y2, ret, maction, keycode1, keycode2, loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	
	while (loop)
	{
		
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*�ָ���ɫ*/
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
			TurnLightorDark(map, map2, (x1 - X0) / (3 + 5), (y1 - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ

		if (ret == CCT_MOUSE_EVENT)//������
		{
			cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//���ǵ�֮ǰ����ʾ
			cct_gotoxy(0, r * 4 + 3);
			/*��֤��С�����ڣ��Ҳ����߿�*/
			//cout << "X=" << X << " Y=" << Y << endl;
			if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)
			{
				cout << "[��ǰ���] " << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
				x1 = X;//��¼��ǰ���λ�ã��Ա��ж���һ���ƶ��Ƿ���ԭ���Ŀ�
				y1 = Y;
				TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
			}
			else
				cout << "[��ǰ���] λ�÷Ƿ�";
			switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK://���
					if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)//�ڿ�����
					{
						cct_gotoxy(0, r * 4 + 3);
						cout << "ѡ���� ";
						cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
						cout << endl;
						loop = 0;//ֹͣѭ��
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK://�Ҽ�
					k = 1;
					break;
			}//end of switch
		}//end of if
		else if (ret == CCT_KEYBOARD_EVENT)//����
		{
			cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//���ǵ�֮ǰ����ʾ
			cct_gotoxy(0, r * 4 + 3);
			cout << "[��ǰ����] : ";
			cct_getxy(x2, y2);
			switch (keycode1) {
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((Y - Y0) / (2 + 2) > 0)
								Y -= 4;
							else//�������˾ʹ���ȥ
								Y += 4*(r-1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout<< char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							break;
						case KB_ARROW_DOWN:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((Y - Y0) / (2 + 2) < r-1)
								Y += 4;
							else//�������˾ʹ���ȥ
								Y -= 4 * (r - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							break;
						case KB_ARROW_LEFT:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((X - X0) / (3 + 5) > 0)
								X -= 8;
							else//�������˾ʹ���ȥ
								X += 8 * (c - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;	
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							break;
						case KB_ARROW_RIGHT:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((X - X0) / (3 + 5) < c-1)
								X += 8;
							else//�������˾ʹ���ȥ
								X -= 8 * (c - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							cct_gotoxy(x2, y2);
							cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							break;
					}
					break;
				case 13://�س�
					cct_gotoxy(0, r * 4 + 3);
					cout << "ѡ���� ";
					cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
					cout << endl;
					loop = 0;
					break;

				case (int)'Q':
				case (int)'q':
					k = 1;
					break;
			}//end of switch
		}//end of else if

		if (k)//�Ҽ���q/Q����
			break;
	}
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	*hang = char((Y - Y0) / (2 + 2) + 'A');
	*lie = (X - X0) / (3 + 5);
	return k;//�������水���Ҽ�����q/Q
	
}
/*ѡ�е���ͬ���ڵ�ɫ��һ���ɫ*/
void MulLightorDark(int map[][CE + 2], char map2[][CE + 2], int r, int c,char hang,int lie, int loop)
{
	int i, j;
	for (i = 1; i < RE + 1; i++)
	{
		for (j = 1; j < CE + 1; j++)
		{
			if (map2[i][j] == '*' && !(hang - 'A' == i - 1 && lie == j - 1))//��*������ѡ�е�����
			{
				TurnLightorDark(map, map2, j - 1, i - 1,loop, r, c);
			}
		}
	}
}
/*��ȥ���*/
void MulBlank(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie)
{
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (map2[i][j] == '*' && !(hang - 'A' == i - 1 && lie == j - 1))//��*������ѡ�е�����85
			{
				TurnLightorDark(map, map2, j - 1, i - 1, 4, r, c);//��ɰ�ɫ
			}
		}
	}
}
/*����*/
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
/*����һ��*/
void Drop_Once(int map[][CE + 2], char map2[][CE + 2], int r, int c, int i, int j)
{
	const int X0 = 4, Y0 = 3, time = 10;
	//i,jΪ������±�
	int x= (j - 1) * 8 + X0, y= (i - 1) * 4 + Y0;//x,y�����ǿ�����Ͻ�����
	int k;
	cout << setiosflags(ios::left);

	for (k = 0; k < 4; k++)
	{
		cct_setcolor(15, 15);//����ɫ
		cct_gotoxy(x, y+k);//��ʼʱx��yΪÿ���������Ͻ�����
		cout << "  " << "  " << "  ";
		cct_gotoxy(x, y+k + 1);
		cout << "  " << "  " << "  ";
		cct_gotoxy(x, y+k + 2);
		cout << "  " << "  " << "  ";
		cct_setcolor();

		cct_setcolor(map[i+1][j],0);//��ɫ,ע��xy�������ʾ������
		cct_gotoxy(x, y+k + 1);//��ʼʱx��yΪÿ���������Ͻ�����
		cout << "��" << "��" << "��";
		cct_gotoxy(x, y+k + 2);
		cout << "��" << setw(2) << map[i+1][j] << "��";
		cct_gotoxy(x, y+k + 3);
		cout << "��" << "��" << "��";
		cct_setcolor();

		Sleep(time);
	}
	/*�ص��߽磬���´�ӡ*/
	y+=3;
	cct_gotoxy(x, y);
	cct_setcolor(15, 0);//�׵׺�ɫ
	cout << "������";
	cct_setcolor();

}
/*ɫ������*/
void Drop(int map[][CE + 2], char map2[][CE + 2], int r, int c)
{
	int i, j, k = 0;
	for (j = 1; j < CE + 1; j++)//��ÿһ�п�ʼ
		for (i = RE; i > 1; i--)//���ܵ�һ��
		{
			if (map2[i][j] == '*' && map2[i - 1][j] != '*')//������*
			{
				map[i][j] = map[i - 1][j];//���渳ֵ������
				map[i - 1][j] = 0;
				map2[i - 1][j] = '*';
				map2[i][j] = '0';
				Drop_Once(map, map2, r, c, i-1, j);//����������ƶ�һ��
			}
		}
	/*��黹û��û0��*���棬�������Χ��*/
	for (i = 1; i < r; i++)//���ü�����һ��
	{
		for (j = 1; j < CE; j++)
		{
			if (map[i][j] > 0 && map[i + 1][j] == 0)//0��*����Ͳ�����
			{
				k++;
				break;
			}
		}
	}
	if (k)
		Drop(map, map2, r, c);
}
/*�հ�λ�����ɫ��*/
void fill(int map[][CE + 2], char map2[][CE + 2], int r, int c)
{
	int i, j;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (map2[i][j] == '*' )//��*,��Ҫ���
			{
				TurnLightorDark(map, map2, j - 1, i - 1, 2, r, c);
			}
		}
	}
}