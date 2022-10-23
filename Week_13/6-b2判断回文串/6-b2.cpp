/* 2151298 信11 杨滕超 */
#include <iostream>
#include <cstring>
#include <string.h>
#define N 82
using namespace std;
char* tj_strrev(char* str)
{
    char* str1 = str, t, * str0 = str;
    str1 += strlen(str);
    str1--;
    int i;
    if (str == NULL)
        return 0;
    else
    {
        for (i = 0; (unsigned int)i <= (strlen(str) / 2) && *str != '\0'; i++, str++, str1--)
        {
            t = *str;
            *str = *str1;
            *str1 = t;
        }
        str = str0;
        return str;
    }
}
int tj_strrevcmp(char *p1,int len)
{
    char  str2[N] = { '\0' }, * p2, * p10;
    p10 = p1;
    /*str1赋值给str2*/
    for (p2=str2;*p1 != '\0'; p2++,p1++)
        *p2 = *p1;

    /*p1首地址*/
    p1 = p10;
    /*反转字符串*/
    tj_strrev(p1);

    /*比较反转之后和原来是否一样,记得首地址*/
    p1 = p10;
    p2 = str2;
    if (strcmp(p1,p2) == 0)
        return 1;
    else
        return 0;
    
}
int main()
{
    char str1[N] = { '\0' }, * p1 = str1;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str1,N,stdin);
	/*处理进去的回车,碰到第一个回车赋值为\0*/
    for (;; p1++)
    {
        if (*p1 == 10)
        {
            *p1 = '\0';
            break;
        }
    }
    if (tj_strrevcmp(str1, strlen(str1)) == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

	return 0;
}