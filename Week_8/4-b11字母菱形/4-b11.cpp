/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */
   /***************************************************************************
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
char denghao( char end_ch)
{
	/*计算需要=的个数，再返回一个‘=’*/
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
	/*根据固定的最后字母和变化的最后字母判断打印空格的数量*/
}
void f1(int x, char end_ch)
{
	/*倒序打印变化的最大字母到A*/
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
	/*正序打印B到变化的最大字母，注意需要变化最大字母end_ch作为参照，此时变化的是最开始字母*/
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
	/*将空格与倒序正序结合，打印一行有可变的最大字母*/
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
	/* 保证changefirst一直都在*/
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout << denghao(end_ch) << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << denghao(end_ch) << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}