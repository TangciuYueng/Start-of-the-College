/* 2151298 ��11 ������ */
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
    /*str1��ֵ��str2*/
    for (p2=str2;*p1 != '\0'; p2++,p1++)
        *p2 = *p1;

    /*p1�׵�ַ*/
    p1 = p10;
    /*��ת�ַ���*/
    tj_strrev(p1);

    /*�ȽϷ�ת֮���ԭ���Ƿ�һ��,�ǵ��׵�ַ*/
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
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str1,N,stdin);
	/*�����ȥ�Ļس�,������һ���س���ֵΪ\0*/
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