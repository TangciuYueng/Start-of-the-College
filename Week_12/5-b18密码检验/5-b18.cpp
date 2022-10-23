/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
#define M 10
#define N 17
static const char other[] = "~!@#$%^&*()-_=+[],.?";
int main()
{
	int i, j, k, len, daxie, xiaoxie, shuzi, qita, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, have = 0;
	char key[M][N] = { '\0' }, firstline[100] = {'\0'},ch;
	cin.getline(firstline,100,'\n');//读取第一行有98个字符

	//读取长度，大写，小写，数字，其他 五个数字
	cin >>len>>daxie>>xiaoxie>>shuzi>>qita;

	cin.get(ch);//把qita后面的回车拿走

	for (i = 0; i < M; i++)
		cin.getline(key[i], N, '\n');//包括最多的十六个字符和尾零与回车
	/*输入的参数是否正确*/
	if (len < 12 || len>16 || daxie < 2 || daxie >= len || xiaoxie < 2 || xiaoxie >= len || shuzi < 2 || shuzi >= len || qita < 2 || qita >= len)
		sum++;
	/*比较长度*/
	for(i=0;i<M;i++)
	{
		if (len != strlen(key[i]))
			sum++;
	}
	/*sum1对应大写，sum2对应小写，sum3对应数字，sum4对应其它
	检验是否满足不小于对应的要求*/
	for (i = 0; i < M; i++)
	{
		/*记得每一个密码比较完之后对应的sum复原*/
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		sum4 = 0;
		have = 0;
		for (j = 0; j < len; j++)
		{
			if (key[i][j] >= 'A' && key[i][j] <= 'Z')
				sum1++;
			else if (key[i][j] >= 'a' && key[i][j] <= 'z')
				sum2++;
			else if (key[i][j] >= '0' && key[i][j] <= '9')
				sum3++;
			else//检验是否有非法字符，其他字符中依次与other中的比较，若有相同则不是非法，have=0就非法了
			{
				for (k = 0; k < 20; k++)
				{
					if (key[i][j] == other[k])
						have++;
				}
				if (have == 0 || key[i][j] < 0)//汉字ascii分解出来为负数
					sum++;
			}
		}
		sum4 = strlen(key[i]) - sum1 - sum2 - sum3;
		if (sum1 < daxie || sum2 < xiaoxie || sum3 < shuzi || sum4 < qita)
			sum++;
	}

	if (sum)
		cout << "错误" << endl;
	else
		cout << "正确" << endl;
	return 0;
}