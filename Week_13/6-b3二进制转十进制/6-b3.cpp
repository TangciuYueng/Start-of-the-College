/* 2151298 信11 杨滕超 */
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
const int N = 33;
const int scale = 2;
void change(char* p,int len)
{
	char* p0;
	unsigned int num = 0, i;
	p0 = p;
	for (i=len; *p != '\0'; p++)
	{
		num = (unsigned int)((*p - '0')*pow(scale, i-1) + num);
		i--;
	}
	cout << num << endl;
}
int main()
{
	char str[N] = { '\0' };
	int len; 
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    cin.getline(str,N,'\n');
    len = strlen(str);
	change(str,len);
	return 0;
}
