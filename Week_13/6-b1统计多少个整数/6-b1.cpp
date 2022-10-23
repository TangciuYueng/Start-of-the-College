/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s(str);
	pa = a;
	is_num = 0;
	for (p = str; *p != '\0'; p++)
	{
		if (pa - a == 10 )
			break;
		/*判断本次是否是数字*/
		if (*p >= '0' && *p <= '9')
		{
			*pa = *pa * 10 + *p - '0';
			is_num = 1;
			/*本次是数字，接着判断下一个是否是数字，不是则下一个空间*/
			p++;
			if (*p < '0' || *p>'9')
				pa++;
			p--;//减回来
		}
		else 
			is_num = 0;
	}

	pnum = pa;

	cout << "共有" <<pa-a<< "个整数" << endl;

	for (pa = a; pnum-pa > 0; pa++)
		cout << *pa << " ";
	cout << endl;

	return 0;
}