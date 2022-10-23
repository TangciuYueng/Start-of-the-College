/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//用getch，因此不需要支持Linux
#include <string.h>	//Dev/CB的strlen需要
using namespace std;

struct tj_time {
	int tj_year;	//表示年份
	int tj_month;	//表示月(1-12)
	int tj_day;	//表示日(1-28/29/30/31)
	int tj_hour;	//表示小时(0-23)
	int tj_minute;	//表示分(0-59)
	int tj_second;	//表示秒(0-59)
};

/* 可以在此定义其它需要的函数 */
const int YEAR = 365;
void day_month_year(int* d, int* m, int* y)
{
	int leap;
	if (*y % 4 == 0 && *y % 100 != 0 || *y % 400 == 0)//判断是否闰年
		leap = 1;
	else
		leap = 0;
	int M[13] = { 0,31,28 + leap,31,30,31,30,31,31,30,31,30,31 };//每个月有多少天
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
		*d -= (YEAR + leap);//总天数减去当年的天数
		(*y)++;//年份加一
		day_month_year(d, m, y);//递归再来一年
	}
	
}


/***************************************************************************
  函数名称：
  功    能：给出提示并等待回车键
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //思考一下，||的左右两个条件能否互换
		cout << endl << "按回车键继续";
	else
		cout << endl << prompt << "，按回车键继续";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：调用系统的转换函数将整型秒值转换为与本题相似的结构体并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t的本质是64位无符号整数
{
	struct tm* tt;	//struct tm 为系统定义的结构体

	tt = localtime(&input_time);	//localtime为系统函数

	/* tm_*** 为struct tm中的成员，和本题的struct tj_time具体的内容不完全符合，具体含义自己查找相关资料 */
	cout << setfill('0') << setw(4) << tt->tm_year + 1900 << '-'
		<< setw(2) << tt->tm_mon + 1 << '-'
		<< setw(2) << tt->tm_mday << ' '
		<< setw(2) << tt->tm_hour << ':'
		<< setw(2) << tt->tm_min << ':'
		<< setw(2) << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换结果输出函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* 实现自定义结构的输出，输出形式与system_time_output相同 */
	cout << setfill('0') << setw(4) << tp->tj_year << '-'
		<< setw(2) << tp->tj_month << '-'
		<< setw(2) << tp->tj_day << ' '
		<< setw(2) << tp->tj_hour << ':'
		<< setw(2) << tp->tj_minute << ':'
		<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  函数名称：
  功    能：自定义转换函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//定义静态局部变量，不准动
	const int S = 60, MIN = 60, H = 24, MON = 12;
	/* 实现过程开始，在下面添加相应的定义及执行语句即可 */
	/*初始值*/
	result.tj_year = 1970;
	result.tj_month = 1;
	result.tj_day = 1;
	result.tj_hour = 8;
	result.tj_minute = 0;
	result.tj_second = 0;
	int leap;
	if (result.tj_year % 4 == 0 && result.tj_year % 100 != 0 || result.tj_year % 400 == 0)//判断是否闰年
		leap = 1;
	else
		leap = 0;
	int M[13] = { 0,31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	
	result.tj_second = input_time;
	if (input_time >= S)//大于六十秒,minute开始变化
	{
		result.tj_minute += (result.tj_second / S);//60s进位为1min
		result.tj_second %= S;//剩下不到60s的second
		if (result.tj_minute >= MIN)//大于3600秒,hour开始变化
		{
			result.tj_hour += (result.tj_minute / MIN);
			result.tj_minute %= MIN;
			if (result.tj_hour >= H)//大于57600秒,day开始变化
			{
				result.tj_day += (result.tj_hour / H);
				result.tj_hour %= H;
			    day_month_year(&result.tj_day, &result.tj_month, &result.tj_year);
			}
		}
	}
	/* 实现过程结束 */

	return &result;	//注意，返回的是静态局部变量的地址，本语句不准动
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		cin >> read_time; //因为采用输入重定向，此处不加任何提示

		/* 输入错误或<0则退出循环 */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "秒数             : " << read_time << endl;
		cout << "系统转换的结果   : ";
		system_time_output(read_time);

		cout << "自定义转换的结果 : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//系统函数，取当前系统时间（从1970-01-01 00:00:00开始的秒数）

		cout << "当前系统时间     : " << t << endl;
		cout << "系统转换的结果   : ";
		system_time_output(t);

		cout << "自定义转换的结果 : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}