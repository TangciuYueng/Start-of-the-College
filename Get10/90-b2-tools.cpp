/* 2151298 ��11 ������ */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;
const int N = 80, NUM_KONGGE = 4, RB = 5, CB = 5, TB = 5, TE = 20;
/*end����*/
void to_be_continued()//����������
{
	cout << "��С�������������End����...";
	char str[N];
	int i,x,y;
	cct_getxy(x, y);//ȡ�����Ժ���ָ����λ��
	while (1)
	{
		cin.ignore(65536, '\n');
		for (i = 0; i < N; i++)//ѭ����ʼ�����\0
			str[i] = '\0';
		cct_showch(x, y, ' ',COLOR_BLACK,COLOR_WHITE, NUM_KONGGE);
		cct_gotoxy(x, y);//�ָ����λ��
		cin.getline(str, N, '\n');
		for (i = 0; i < 4; i++)
	    {
			if (str[i] >= 'a' && str[i] <= 'z')//ת�ɴ�д
				str[i] -= 32;
		}
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == '\0')
			break;
		else
		{
			
			cout << "����������������룡������" << endl;
		}
	}

}
/*���뺯��*/
void input(int* rp, int* cp, int* tgtp ,int choice)
{
	while (1)
	{
		cout << "����������(5-8)��" << endl;
		cin >> *rp;
		if (*rp >= RB && *rp <= RE)
			break;
		
		cin.clear();//�����������建����
	    cin.ignore(65536, '\n');
		
	}
	while (1)
	{
		cout << "����������(5-10)��" << endl;
		cin >> *cp;
		if (*cp >= CB && *cp <= CE)
			break;
		cin.clear();//�����������建����
		cin.ignore(65536, '\n');
		
	}
	if (choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 'A' - '0' && choice != 'B' - '0')
	{
		while (1)
		{
			cout << "������ϳ�Ŀ��(5-20)��" << endl;
			cin >> *tgtp;
			if (*tgtp >= TB && *tgtp <= TE)
				break;
			cin.clear();//�����������建����
			cin.ignore(65536, '\n');

		}
	}
}
/*���뺯��3��ȷ�Ϻϲ�*/
char input3(char*hang,int*lie)
{
	int x, y;
	char ch;
	cct_getxy(x, y);//ȡ�����Ժ���ָ����λ��
	while (1)
	{
		cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���"<<*hang<<*lie<<"��(Y / N / Q)��";
		ch = _getche();
		if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N' || ch == 'q' || ch == 'Q')
			break;
		else
		{
			cin.ignore(65536, '\n');
			cct_gotoxy(x, y);//���벻�ԣ��ͻص�ԭ��λ��������һ��
		}
	}
	if (ch >= 'a' && ch <= 'z')//Сдת�ɴ�д
		ch -= 32;
	cout << endl;
	return ch;
}
/*���뺯��2��ѡ������*/
void input2(int* rp, int* cp,char* hang, int* lie)//rpָ��������cpָ������
{
	cout << "������ĸ+������ʽ[����c2]����������꣺";
	int x, y;
	cct_getxy(x, y);//ȡ�����Ժ���ָ����λ��
	while (1)
	{
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, NUM_KONGGE);
		cct_gotoxy(x, y);//�ָ����λ��
		cin >> *hang;
		cin >> *lie;
		if (*hang >= 'a' && *lie <= 'z')//Сдת�ɴ�д
			*hang -= 32;

		if ((*hang>= 'A' && *hang<='A' + *rp - 1) && (*lie>=0 && *lie<=*cp - 1))
			break;
		else if(!((*hang >= 'A' && *hang <= 'A' + *rp - 1) && (*lie >= 0 && *lie <= *cp - 1)))
		    cout << "�����������������.";
		cin.ignore(65536, '\n');
	}
}
/*���뺯��4�����س��������;���뺯��5�����س���ֵ���;���뺯��6���س�������һ�κϳ�;���뺯��7���س�����Ŀ��*/
void input456(int num)
{
	char ch;
	int x, y;
	cct_getxy(x,y);
	while (1)
	{
		cct_gotoxy(x, y);
		if (num == 4)
			cout << "���س����������������0����...";
		else if (num == 5)
			cout << "���س���������ֵ���...";
		else if (num == 6)
			cout << "���κϳɽ��������س���������һ�εĺϳ�...";
		else if (num == 7)
			cout << "���س������������Ŀ�����...";
		ch = _getch();
		if (ch == 13)
			break;
	}
}
/*��¼�÷ֲ����*/
void fen(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie,int*tgtp,int *zongfen)
{
	int fen, geshu = 0, i, j;
	for (i = 1; i < RE + 1; i++)//��¼*�ĸ���
		for (j = 1; j < CE + 1; j++)
			if (map2[i][j] == '*')
				geshu++;
	fen = geshu * map[*hang - 'A' + 1][*lie + 1] * 3;
	*zongfen += fen;
	cout << "���ε÷֣�" << fen << " �ܵ÷֣�" << *zongfen << " �ϳ�Ŀ�꣺" << *tgtp <<"     " << endl;
	cout << endl;
}
/*��������*/
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
/*�ҵ����ֵ*/
int find_max(int map[][CE + 2])
{
	int i, j, max=map[0][0];
	for (i = 1; i < RE+1; i++)
		for (j = 1; j < CE+1; j++)
			if (map[i][j] > max)
				max = map[i][j];
	return max;
}
/*�س��������ȷ��,����ͼ��*/
int MouseKeyboardAffirm(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie)//����ѡ�п�Ķ�Ӧ��������
{
	int  k = 0, m = 0, loop = 1;
	const int X0 = 4, Y0 = 3;
	//cct_getxy(x0, y0);
	/*ע���ʱx1��y1��ֵӦΪ��һ��ȷ�������Ŀ�*/
	int X = *lie * 8 + X0, Y = (*hang - 'A') * 4 + Y0, x1 = *lie*8+X0, y1 = (*hang-'A')*4 + Y0, x2=0, y2=0, ret, maction, keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	
	while (loop)
	{
		k = 0;//��¼�س�������ļ�����ÿ��ѭ���ָ�
		m = 0;//��¼������ļ�����ÿ��ѭ���ָ�
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		/*�ָ���ɫ*/
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
		{
			TurnLightorDark(map, map2, (x1 - X0) / (3 + 5), (y1 - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ

		}
		if (ret == CCT_MOUSE_EVENT)//������
		{
			if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
			{
				cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//���ǵ�֮ǰ����ʾ
				cct_gotoxy(0, r * 4 + 3);
			}

			if (((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2) && X >= X0 && Y >= Y0 && (X - X0) / 8 < c && (Y - Y0) / 4 < r)//�ڿ�����
			{
				if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
					cout << "[��ǰ���] " << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
				x1 = X;//��¼��ǰ���λ�ã��Ա��ж���һ���ƶ��Ƿ���ԭ���Ŀ�
				y1 = Y;
				TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
			}
			else
			{
				if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
				{
					cct_gotoxy(0, r * 4 + 3);
					cout << "[��ǰ���] λ�÷Ƿ�";
				}
			}
			
			switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK://���
					k++;//�ж�������ͻس����Ա�����жϽ���
					break;


			}//end of switch
		}//end of if
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
			{
				cct_showch(0, r * 4 + 3, ' ', 0, 7, 60);//���ǵ�֮ǰ����ʾ
cct_gotoxy(0, r * 4 + 3);
cout << "[��ǰ����] : ";
cct_getxy(x2, y2);
			}

			switch (keycode1) {
				case 224:
					switch (keycode2) {
						case KB_ARROW_UP:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((Y - Y0) / (2 + 2) > 0)
								Y -= 4;
							else//�������˾ʹ���ȥ
								Y += 4 * (r - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							}
							m++;
							break;
						case KB_ARROW_DOWN:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((Y - Y0) / (2 + 2) < r - 1)
								Y += 4;
							else//�������˾ʹ���ȥ
								Y -= 4 * (r - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							}
							m++;
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
							m++;
							break;
						case KB_ARROW_RIGHT:
							/*�ָ���ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 2, r, c);//�����������꣬���㿪ʼ
							if ((X - X0) / (3 + 5) < c - 1)
								X += 8;
							else//�������˾ʹ���ȥ
								X -= 8 * (c - 1);
							/*��ɫ*/
							TurnLightorDark(map, map2, (X - X0) / (3 + 5), (Y - Y0) / (2 + 2), 1, r, c);//�����������꣬���㿪ʼ
							x1 = X;
							y1 = Y;
							if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2))//��겻��ԭ���Ŀ�
							{
								cct_gotoxy(x2, y2);
								cout << char((Y - Y0) / (2 + 2) + 'A') << "��" << (X - X0) / (3 + 5) << "��   ";
							}
							m++;
							break;
					}
					break;
				case 13://�س�
					k++;//�ж�������ͻس����Ա�����жϽ���
					break;


			}//end of switch
		}//end of else if
		if ((x1 - X0) / (3 + 5) != (X - X0) / (3 + 5) || (y1 - Y0) / (2 + 2) != (Y - Y0) / (2 + 2) || k > 0 || m > 0
			|| !((X - X0) % 8 <= 5) && ((Y - Y0) % 4 <= 2))//��겻��ԭ���Ŀ���лس������
			loop = 0;

	}


	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	*hang = char((Y - Y0) / (2 + 2) + 'A');
	*lie = (X - X0) / (3 + 5);
	return k;//�����Ƿ��лس��������
}
/*�س������ȷ��*/
int confirm()
{
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	int x = 0, y = 0, k1 = 0, k2 = 0, ma = 0, ret = 0, k = 0;
	while (k==0)
	{
		k = 0;
		ret = cct_read_keyboard_and_mouse(x, y, ma, k1, k2);
		if (ret == CCT_MOUSE_EVENT)
		{
			if (ma == MOUSE_LEFT_BUTTON_CLICK)//���
				k++;
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if (k1 == 13 && k2 == 0)//�س�
				k++;
		}
	}
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return k;
}
/*��C�����ȷ��*/
int confirmC()
{
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	int x = 0, y = 0, k1 = 0, k2 = 0, ma = 0, ret = 0, k = 0;
	while (k == 0)
	{
		k = 0;
		ret = cct_read_keyboard_and_mouse(x, y, ma, k1, k2);
		if (ret == CCT_MOUSE_EVENT)
		{
			if (ma == MOUSE_LEFT_BUTTON_CLICK)//���
				k++;
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if ((k1 == (int)('C')||k1==(int)('c')) && k2 == 0)//��c
				k++;
		}
	}
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return k;
}