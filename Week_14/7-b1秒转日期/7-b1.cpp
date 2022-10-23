/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */
const int YEAR = 365;
void day_month_year(int* d, int* m, int* y)
{
	int leap;
	if (*y % 4 == 0 && *y % 100 != 0 || *y % 400 == 0)//�ж��Ƿ�����
		leap = 1;
	else
		leap = 0;
	int M[13] = { 0,31,28 + leap,31,30,31,30,31,31,30,31,30,31 };//ÿ�����ж�����
	if (*d <= M[1])
	{
		;
	}
	else if (*d > M[1] && *d <= M[1] + M[2])
	{
		*d -= (M[1]);
		*m += 1;
	}
	else if (*d > M[1] + M[2] && *d <= M[1] + M[2] + M[3])
	{
		*d -= (M[1] + M[2]);
		*m += 2;
	}
	else if (*d > M[1] + M[2] + M[3] && *d <= M[1] + M[2] + M[3] + M[4])
	{
		*d -= (M[1] + M[2] + M[3]);
		*m += 3;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] && *d <= M[1] + M[2] + M[3] + M[4] + M[5])
	{
		*d -= (M[1] + M[2] + M[3] + M[4]);
		*m += 4;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5]);
		*m += 5;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6]);
		*m += 6;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7]);
		*m += 7;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8]);
		*m += 8;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9]);
		*m += 9;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10] && *d <= M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10] + M[11])
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10]);
		*m += 10;
	}
	else if (*d > M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10] + M[11] && *d <= YEAR + leap)
	{
		*d -= (M[1] + M[2] + M[3] + M[4] + M[5] + M[6] + M[7] + M[8] + M[9] + M[10] + M[11]);
		*m += 11;
	}
	else
	{
		*d -= (YEAR + leap);//��������ȥ���������
		(*y)++;//��ݼ�һ
		day_month_year(d, m, y);//�ݹ�����һ��
	}
	
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	cout << setfill('0') << setw(4) << tt->tm_year + 1900 << '-'
		<< setw(2) << tt->tm_mon + 1 << '-'
		<< setw(2) << tt->tm_mday << ' '
		<< setw(2) << tt->tm_hour << ':'
		<< setw(2) << tt->tm_min << ':'
		<< setw(2) << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	cout << setfill('0') << setw(4) << tp->tj_year << '-'
		<< setw(2) << tp->tj_month << '-'
		<< setw(2) << tp->tj_day << ' '
		<< setw(2) << tp->tj_hour << ':'
		<< setw(2) << tp->tj_minute << ':'
		<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��
	const int S = 60, MIN = 60, H = 24, MON = 12;
	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	/*��ʼֵ*/
	result.tj_year = 1970;
	result.tj_month = 1;
	result.tj_day = 1;
	result.tj_hour = 8;
	result.tj_minute = 0;
	result.tj_second = 0;
	int leap;
	if (result.tj_year % 4 == 0 && result.tj_year % 100 != 0 || result.tj_year % 400 == 0)//�ж��Ƿ�����
		leap = 1;
	else
		leap = 0;
	int M[13] = { 0,31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	
	result.tj_second = input_time;
	if (input_time >= S)//������ʮ��,minute��ʼ�仯
	{
		result.tj_minute += (result.tj_second / S);//60s��λΪ1min
		result.tj_second %= S;//ʣ�²���60s��second
		if (result.tj_minute >= MIN)//����3600��,hour��ʼ�仯
		{
			result.tj_hour += (result.tj_minute / MIN);
			result.tj_minute %= MIN;
			if (result.tj_hour >= H)//����57600��,day��ʼ�仯
			{
				result.tj_day += (result.tj_hour / H);
				result.tj_hour %= H;
			    day_month_year(&result.tj_day, &result.tj_month, &result.tj_year);
			}
		}
	}
	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		cin >> read_time; //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "����             : " << read_time << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(read_time);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��     : " << t << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(t);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}