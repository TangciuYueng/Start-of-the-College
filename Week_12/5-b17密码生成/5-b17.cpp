/* 2151298 信11 杨滕超 */
#include <iostream>
#include <time.h>
using namespace std;
static const char other[] = "~!@#$%^&*()-_=+[],.?";
#define M 10
#define N 17
void mima(char key[][N], int len, int daxie, int xiaoxie, int shuzi, int qita)
{
	int i, j, k, suiji;
	srand((unsigned)time(NULL));
	for (i = 0; i < M; i++)
	{
		for (k = 0; k < daxie; k++)//先随机赋值指定个数的字符
			{
				j = rand() % len;//从0到len-1随机 每行密码的第几个元素
				if (key[i][j] != '\0')//如果不是\0就再来一次
					k--;
				else
					key[i][j] = 'A' + rand() % 26;
			}
		for (k = 0; k < xiaoxie; k++)
			{
				j = rand() % len;
				if (key[i][j] != '\0')
					k--;
				else
					key[i][j] = 'a' + rand() % 26;
			}
		for (k = 0; k < shuzi; k++)
			{
				j = rand() % len;
				if (key[i][j] != '\0')
					k--;
				else
					key[i][j] = '0' + rand() % 10;
			}
		for (k = 0; k < qita; k++)
			{
				j = rand() % len;
				if (key[i][j] != '\0')
					k--;
				else
					key[i][j] = other[rand() % 20];
			}

		if (len != daxie + xiaoxie + shuzi + qita)//后面数字之和还不满足长度
			{
				for (k = 0; k < len - daxie - xiaoxie - shuzi - qita; k++)
				{
					suiji = rand() % 4;
					if (suiji == 0)
					{
						j = rand() % len;
						if (key[i][j] != '\0')
							k--;
						else
							key[i][j] = 'A' + rand() % 26;
					}
					else if (suiji == 1)
					{
						j = rand() % len;
						if (key[i][j] != '\0')
							k--;
						else
							key[i][j] = 'a' + rand() % 26;
					}
					else if (suiji == 2)
					{
						j = rand() % len;
						if (key[i][j] != '\0')
							k--;
						else
							key[i][j] = '0' + rand() % 10;
					}
					else
					{
						j = rand() % len;
						if (key[i][j] != '\0')
							k--;
						else
							key[i][j] = other[rand() % 20];
					}

				}

			}
		key[i][len] = '\0';
	}
}
int main()
{
	char key[M][N] = { '\0' };
	int len = 0, daxie = 0, xiaoxie = 0, shuzi = 0,  qita = 0, i;
	int daxie1 = 0, xiaoxie1 = 0, shuzi1 = 0, qita1 = 0;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len;
	cin >> daxie;
	cin >> xiaoxie;
	cin >> shuzi;
	cin >> qita;
	if (cin.fail() || daxie < 2 || xiaoxie < 2 || shuzi < 2 || qita < 2)
		cout << "输入非法" << endl;
	else if (len > 16 || len < 12)
		cout << "密码长度[" << len << "]不正确" << endl;
	else if (daxie > len)
		cout << "大写字母个数[" << daxie << "]不正确" << endl;
	else if (xiaoxie > len)
		cout << "小写字母个数[" << xiaoxie << "]不正确" << endl;
	else if (shuzi > len)
		cout << "数字个数[" << shuzi << "]不正确" << endl;
	else if (qita > len)
		cout << "其它符号个数[" << qita << "]不正确" << endl;
	else if (daxie + xiaoxie + shuzi + qita > len)
		cout << "所有字符类型之和[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]大于总密码长度[" << len << "]" << endl;
	else
	{
		cout << len<<" " << daxie <<" " << xiaoxie<<" " << shuzi <<" " << qita << endl;
		mima(key, len, daxie, xiaoxie, shuzi, qita);
		
		for (i = 0; i < M; i++)
			cout << key[i] << endl;
	}
	return 0;
}