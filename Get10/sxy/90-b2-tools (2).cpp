/* ��11 ɳЦ�� 2153396 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;
#define N 10
#define M 12

void zhaoshu1(char zb[], char sz[N][M], char ch, int x0, int y0,char n,int mb)//���Ա���û��һ����
{
	int i, j, x = 0, y = 0, q = 0, w = 0;
	char jl[N][M];
	for (i = 0; i < N; i++) {//��ʼ��
		for (j = 0; j < M; j++)
			jl[i][j] = '0';
	}
	if (zb[0] > 64 && zb[1] > 47) {//��������
		x = (int)zb[0] - 64;//xΪѡ��ĺ�����+1
		y = (int)zb[1] - 47;//yΪѡ���������+1
	}

	jl[x][y] = '*';
	for (q = 0; q < 10; q++) {
		for (i = 1; i < N - 1; i++) {//����ch����Χ���Ǻŵ���
			for (j = 1; j < M - 1; j++) {
				if (sz[i][j] == ch && (jl[i][j + 1] == '*' || jl[i][j - 1] == '*' || jl[i + 1][j] == '*' || jl[i - 1][j] == '*'))
					jl[i][j] = '*';
				else
					jl[i][j] = '0';
			}
		}
	}
	shuchuxh(zb,sz, jl,ch, x0, y0,n,mb);
}

void shuchuxh(char zb[],char sz[N][M],char jl[N][M],char ch, int x0, int y0,char n,int mb) {//������Ǻŵ�����
	int i, j;
	cout << "���ҽ�����飺" << endl;
	cout << "  |";
	for (i = 0; i < y0; i++) //�����һ��
		cout << "  " << i;
	cout << endl << "--+-";//����ָ���
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//�������
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++)
			cout << setw(3) << jl[j + 1][i + 1];
		cout << endl;
	}
	cout << endl << endl;

	shangsai(zb, sz, jl, ch, x0, y0, n, mb);
}

void zhaoshu2(char zb[], char sz[N][M], char ch, int x0, int y0, int x, int y, char jl[N][M])//�ݹ�
{
	jl[x][y] = '*';

	if (x - 1 > 0 && sz[x - 1][y] == ch && jl[x - 1][y] != '*') {
		jl[x - 1][y] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x - 1, y, jl);
	}
	if (y - 1 > 0 && sz[x][y - 1] == ch && jl[x][y - 1] != '*') {
		jl[x][y - 1] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x, y - 1, jl);
	}
	if (y + 1 < y0 + 1 && sz[x][y + 1] == ch && jl[x][y + 1] != '*') {
		jl[x][y + 1] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x, y + 1, jl);
	}
	if (x + 1 < x0 + 1 && sz[x + 1][y] == ch && jl[x + 1][y] != '*') {
		jl[x + 1][y] = '*';
		zhaoshu2(zb, sz, ch, x0, y0, x + 1, y, jl);
	}
}

void shangsai(char zb[],char sz[N][M], char jl[N][M],char ch, int x0, int y0,char n,int mb,bool bo)//��ɫ
{
	int i, j, a, b;
	char qr;
	if (bo)
		cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	cout << "  |";
	for (i = 0; i < y0; i++) //�����һ��
		cout << "  " << i;
	cout << endl << "--+-";//����ָ���
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//�������
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			cout << "  ";
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(14, 0);
			cout << sz[j + 1][i + 1];
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(0, 7);
		}
		cct_setcolor(0, 7);
		cout << endl;
	}
	cout << endl;

	if (n == '3') {
		while (1) {
			cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << (char)zb[0] << zb[1] << "��(Y/N/Q)��";
			while (1) {//����
				qr = _getche();
				cct_getxy(a, b);
				if (qr == 'Y' || qr == 'y' || qr == 'n' || qr == 'N' || qr == 'q' || qr == 'Q')
					break;
				else if (n == 13)
					cct_gotoxy(10, b);
				else {
					cct_showch(a - 1, b, ' ');
					cct_gotoxy(a - 1, b);
				}
			}
			cout << endl << endl;
			if (qr == 'Y' || qr == 'y') {
				heyi(zb, sz, jl, ch, x0, y0, n, mb);
				break;
			}
			else if (qr == 'n' || qr == 'N')
				shuru2(zb, sz, x0, y0, n, mb, 0);
			else
				return;
		}
	}
}

void shuzu(int x0, int y0, char n,int mb)
{
	srand((unsigned)time(0));
	int  i, j, s = 0;
	char zb[80] = { '\0' }, sz[N][M];
	for (i = 0; i < N; i++) {//��ʼ��
		for (j = 0; j < M; j++)
			sz[i][j] = '0';
	}

	cout << endl << "��ǰ���飺" << endl;//��ӡ����
	cout << "  |";
	for (i = 0; i < y0; i++) //�����һ��
		cout << "  " << i;
	cout << endl << "--+-";//����ָ���
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//�������
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			s = (rand() % 3) + 1;
			cout << "  " << s;
			sz[j + 1][i + 1] = s + '0';//+1Ϊ�˰�8��10����10��12
		}
		cout << endl;
	}
	cout << endl;

	shuru2(zb, sz, x0, y0, n, mb);
}

void shuru2(char zb[], char sz[N][M], int x0, int y0, char n, int mb, bool boo)
{
	int x2, y2, x1, y1, x = 0, y = 0, i, j;
	bool bo = 1;
	char jl[N][M], ch;
	if (boo)
		cin.ignore(65535, '\n');
	else {
		cout << endl << "��ǰ���飺" << endl;//��ӡ����
		cout << "  |";
		for (i = 0; i < y0; i++) //�����һ��
			cout << "  " << i;
		cout << endl << "--+-";//����ָ���
		for (i = 0; i < y0; i++)
			cout << "---";
		cout << endl;

		for (j = 0; j < x0; j++) {//�������
			cout << (char)(j + 65) << " |";
			for (i = 0; i < y0; i++)
				cout << "  " << sz[j + 1][i + 1];
			cout << endl;
		}
		cout << endl;
	}

	cct_getxy(x2, y2);//��ʾ�������λ��
	while (1) {
		if (bo)
			cct_gotoxy(0, y2);
		cout << "������ĸ+������ʽ[����c2]����������꣺";
		cin.getline(zb, 50, '\n');

		if ((int)zb[0] <= 123 && (int)zb[0] >= 97)//��СдתΪ��д
			zb[0] = zb[0] - 32;

		if (((int)zb[0] < 65 + x0 && (int)zb[0] >= 65) && ((int)zb[1] < y0 + 48 && (int)zb[1] >= 48))
			cout << "����Ϊ" << (char)zb[0] << "��" << zb[1] << "��";
		else {
			bo = 1;
			cout << "�����������������.";
			cct_getxy(x1, y1);//�������֮����λ��
			cct_showch(39, y1 - 1, ' ', 0, 7, 50);
			cct_gotoxy(39, y1 - 1);
			continue;
		}

		if (zb[0] > 64 && zb[1] > 47) {//��������
			x = (int)zb[0] - 64;//xΪѡ��ĺ�����+1
			y = (int)zb[1] - 47;//yΪѡ���������+1
		}
		ch = sz[x][y];//chΪָ�����괦������

		if (y >= 1 && x >= 1) {
			if (sz[x][y + 1] != ch && sz[x][y - 1] != ch && sz[x + 1][y] != ch && sz[x - 1][y] != ch) {//�����Ƿ�����Ǻ�
				cout << endl << "����ľ�������λ�ô���������ֵͬ������������" << endl;
				bo = 0;
				cct_getxy(x2, y2);//��ʾ�������λ��
				continue;
			}
			else
				break;
		}
	}
	cout << endl << endl;

	if (n == '1')
		zhaoshu1(zb, sz, ch, x0, y0, n, mb);
	else if (n == '2' || n == '3') {
		for (i = 0; i < N; i++) {//��ʼ��
			for (j = 0; j < M; j++)
				jl[i][j] = '0';
		}
		zhaoshu2(zb, sz, ch, x0, y0, x, y, jl);
		shuchuxh(zb, sz, jl, ch, x0, y0, n, mb);
	}
}

void shuru(char n)
{
	int x = 0, y = 0, mb = 5;
	char zb[3] = { '\0' };
	cct_cls();
	while (1) {
		cout << "����������(5-8)��" << endl;
		cin >> x;
		if (x <= 8 && x >= 5)
			break;
	}
	while (1) {
		cout << "����������(5-10)��" << endl;
		cin >> y;
		if (y <= 10 && y >= 5)
			break;
	}
	if (n == '3')
		while (1) {
			cout << "������ϳ�Ŀ��(5-20)��" << endl;
			cin >> mb;
			if (mb <= 20 && mb >= 5)
				break;
		}

	shuzu(x, y, n, mb);
}

void heyi(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb)
{
	int i, j, x = 0, y = 0, a, b;
	char hc;
	cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
	if (zb[0] > 64 && zb[1] > 47) {//��������
		x = (int)zb[0] - 64;//xΪѡ��ĺ�����+1
		y = (int)zb[1] - 47;//yΪѡ���������+1
	}
	jl[x][y] = '1';
	sz[x][y] = (char)(ch + 1);
	/*�鲢����������������������������������������������������������������������������������������������������*/
	for (i = 0; i <= x0; i++) {
		for (j = 0; j <= y0; j++) {
			if (jl[i][j] == '*')
				sz[i][j] = '0';

		}
	}
	

	shangsai2(zb, sz, jl, ch, x0, y0, n, mb, 0);
	defen(jl, ch, n, mb, x0, y0);
	cout << "���س����������������0����..." << endl;
	while (1) {
		hc = _getche();
		cct_getxy(a, b);
		if (hc == 13)
			break;
		else if (hc == '\b')
			cct_gotoxy(30, b);
		else {
			cct_showch(a - 1, b, ' ');
			cct_gotoxy(a - 1, b);
		}
	}
	xialuo(sz, jl, x0, y0);
	cout << "��0�������(��ͬɫ��ʶ)��" << endl;
	/*for (i = 0; i<N; i++)
		for (j = 0; j < M; j++)	{
			if (jl[i][j] == '*' && !(i == x && j == y))
				sz[i][j] = '0';

		}
		*/
	shangsai2(zb, sz, jl, ch, x0, y0, n, mb, 0);
	cout << "���س���������ֵ���..." << endl;
	while (1) {
		hc = _getche();
		cct_getxy(a, b);
		if (hc == 13)
			break;
		else if (hc == '\b')
			cct_gotoxy(30, b);
		else {
			cct_showch(a - 1, b, ' ');
			cct_gotoxy(a - 1, b);
		}
	}
	cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	tianchong(sz, jl, mb, x0, y0, n, ch);
	shangsai2(zb, sz, jl, ch, x0, y0, n, mb, 0);

	/*for (i = 0; i <= x0; i++) {
		for (j = 0; j <= y0; j++) {
			cout << sz[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (i = 0; i <= x0; i++) {
		for (j = 0; j <= y0; j++) {
			cout << jl[i][j] << " ";

		}
		cout << endl;
	}
	*/
}

void xialuo(char sz[N][M], char jl[N][M], int x0, int y0)
{
	int i, j;
	for (j = 1; j <= y0; j++) {
		for (i = x0; i > 1; i--) {//���ܵ�һ�У���������������������������������������������������11
			if (jl[i][j] == '*' && jl[i - 1][j] != '*') {
				if (jl[i - 1][j] != '\0'&& jl[i][j] != '\0') {
					sz[i][j] = sz[i - 1][j];
					sz[i - 1][j] = '0';
					jl[i][j] = '0';
					jl[i - 1][j] = '*';
				}
			}
		}
	}

	for (j = 1; j <= y0; j++) {
		for (i = x0; i > 0; i--) {
			if (sz[i - 1][j] != '0' && sz[i][j] == '0')
				break;
		}
		if (i != 0)
			break;
	}
	if (j != y0 + 1)
		xialuo(sz, jl, x0, y0);
}

void defen(char jl[N][M],char ch,char n,int mb,int x0,int y0)
{
	int i, j, q = 0, f = 0;
	for (i = 0; i < x0; i++) {
		for (j = 0; j < y0; j++) {
			if (jl[i + 1][j + 1] == '*')
				q++;
		}
	}
	f = (q + 1) * (ch - '0') * 3;
	cout << "���ε÷֣�" << f << " �ܵ÷֣�" << f << " �ϳ�Ŀ�꣺" << mb << endl << endl;
}

void shangsai2(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb, bool bo)//��ɫ2
{
	int i, j;
	if (bo)
		cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	cout << "  |";
	for (i = 0; i < y0; i++) //�����һ��
		cout << "  " << i;
	cout << endl << "--+-";//����ָ���
	for (i = 0; i < y0; i++)
		cout << "---";
	cout << endl;

	for (j = 0; j < x0; j++) {//�������
		cout << (char)(j + 65) << " |";
		for (i = 0; i < y0; i++) {
			cout << "  ";
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(14, 0);
			cout << sz[j + 1][i + 1];
			if (jl[j + 1][i + 1] == '*' || jl[j + 1][i + 1] == '1')
				cct_setcolor(0, 7);
		}
		cct_setcolor(0, 7);
		cout << endl;
	}
	cout << endl;
}

void tianchong(char sz[N][M], char jl[N][M], int mb, int x0, int y0, char n, char ch)
{
	srand((unsigned)time(0));
	int s, i, j;
	if (n == '3') {
		if (ch != '3')
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 3) + 1;
					if (sz[i + 1][j + 1] == '0')
						sz[i + 1][j + 1] = s + '0';
				}
			}
		else//���������
			for (i = 0; i < x0; i++) {
				for (j = 0; j < y0; j++) {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 10) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 4 + '0';
					}
					else if (s > 10 && s <= 40) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 3 + '0';
					}
					else if (s > 40 && s <= 70) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 2 + '0';
					}
					else if (s > 70 && s <= 100) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 1 + '0';
					}
				}
			}
	}
	else if (n!= '3'){//456789ѡ��
		for(i=0;i<x0;i++)
			for (j = 0; j < y0; j++) {
				if (ch == '4') {//���ֵΪ5
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 25) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 1 + '0';
					}
					else if (s > 25 && s <= 25 + 25) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 2 + '0';
					}
					else if (s > 25 + 25 && s <= 25 * 3) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 3 + '0';
					}
					else if (s > 25 * 3 && s <= 25 * 3 + 15) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 4 + '0';
					}
					else if (s > 90 && s <= 100) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 5 + '0';
					}
				}
				else if (ch == '5') {//�ϲ������ֵ��6
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 20) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 1 + '0';
					}
					else if (s > 20 && s <= 20 * 2) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 2 + '0';
					}
					else if (s > 20 * 2 && s <= 20 * 3) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 3 + '0';
					}
					else if (s > 20 * 3 && s <= 20 * 4) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 4 + '0';
					}
					else if (s > 80 && s <= 95) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 5 + '0';
					}
					else if (s > 950 && s <= 100) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = 6 + '0';
					}
				}
				else if (ch >= '6') {
					s = (rand() % 100) + 1;
					if (s > 0 && s <= 5) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = ch + '0';
					}
					else if (s > 5 && s <= 10) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = ch - 1 + '0';
					}
					else if (s > 10 && s <= 20) {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = ch - 2 + '0';
					}
					else {
						if (sz[i + 1][j + 1] == '0')
							sz[i + 1][j + 1] = rand() % (ch - '0' - 3) + 1;
					}
				}
			}
	}

}