#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   ---------------------------------------------------------------------
*/

/***************************************************************************
  函数名称：
  功    能：递归法求a+aa+...+aaaaa
  输入参数：
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、不允许出现任何形式的循环
			3、允许定义最多一个的静态局部变量
***************************************************************************/
int calc(int a, int n)
{
	int sum;
	if (n == 1)
		return a;
	else
	{
		sum = pow(10, n) * a / 9 - a / 9;
		return sum + calc(a, n - 1);
	}
	    
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int a, n;

	cout << "请输入a和n的值" << endl;
	cin >> a >> n;	//不考虑输入错误
	cout << "S=" << calc(a, n) << endl;

	return 0;
}