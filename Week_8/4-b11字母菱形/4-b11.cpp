/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
char denghao( char end_ch)
{
	/*������Ҫ=�ĸ������ٷ���һ����=��*/
	int geshu;
	geshu = 2 * (int)(end_ch - 64) - 1;
	cout << setfill('=') << setw(geshu);
	return '=';
}
void kong(int x, char end_ch)
{
	int geshu;
	geshu = x - end_ch + 1;
	cout << setfill(' ')<<setw(geshu);
	/*���ݹ̶��������ĸ�ͱ仯�������ĸ�жϴ�ӡ�ո������*/
}
void f1(int x, char end_ch)
{
	/*�����ӡ�仯�������ĸ��A*/
	int end = end_ch;
	cout << char(end);
	if (end > 65)
	{
		end--;
		f1(x, (char)(end));
	}
}
void f2(int x, char start_ch, char end_ch)
{
	/*�����ӡB���仯�������ĸ��ע����Ҫ�仯�����ĸend_ch��Ϊ���գ���ʱ�仯�����ʼ��ĸ*/
	x = end_ch;
	int start = (int)start_ch;
	if (start < x)
	{
		start++;
		cout << (char)(start);
		f2(x, (char)start, end_ch);
	}
	else
		cout << endl;
}
void f(int x, char start_ch, char end_ch)
{
	/*���ո��뵹�������ϣ���ӡһ���пɱ�������ĸ*/
	kong(x, end_ch);
	f1(x, end_ch);
	f2(x, start_ch, end_ch);
}
void xia(int x, char start_ch, char end_ch)
{
	int changelast = end_ch;
	if (changelast >= 'A')
	{
		f(x, start_ch, end_ch);
		changelast--;
		xia(x, start_ch, (char)changelast);
	}
}
void shang(int x, char start_ch, char end_ch)
{
	/* ��֤changefirstһֱ����*/
	static int changefirst = 65;
	if (changefirst < x)
	{
		f(x, start_ch, (char)changefirst);
		changefirst++;
		shang(x, start_ch, (char)changefirst);
	}
}
void print_diamond(char start_ch, char end_ch)
{
	const int x = end_ch;
	shang(x, start_ch, end_ch);
	xia(x, start_ch, end_ch);
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout << denghao(end_ch) << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << denghao(end_ch) << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}