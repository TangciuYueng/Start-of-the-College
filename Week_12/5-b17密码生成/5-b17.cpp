/* 2151298 ��11 ������ */
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
		for (k = 0; k < daxie; k++)//�������ֵָ���������ַ�
			{
				j = rand() % len;//��0��len-1��� ÿ������ĵڼ���Ԫ��
				if (key[i][j] != '\0')//�������\0������һ��
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

		if (len != daxie + xiaoxie + shuzi + qita)//��������֮�ͻ������㳤��
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
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len;
	cin >> daxie;
	cin >> xiaoxie;
	cin >> shuzi;
	cin >> qita;
	if (cin.fail() || daxie < 2 || xiaoxie < 2 || shuzi < 2 || qita < 2)
		cout << "����Ƿ�" << endl;
	else if (len > 16 || len < 12)
		cout << "���볤��[" << len << "]����ȷ" << endl;
	else if (daxie > len)
		cout << "��д��ĸ����[" << daxie << "]����ȷ" << endl;
	else if (xiaoxie > len)
		cout << "Сд��ĸ����[" << xiaoxie << "]����ȷ" << endl;
	else if (shuzi > len)
		cout << "���ָ���[" << shuzi << "]����ȷ" << endl;
	else if (qita > len)
		cout << "�������Ÿ���[" << qita << "]����ȷ" << endl;
	else if (daxie + xiaoxie + shuzi + qita > len)
		cout << "�����ַ�����֮��[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]���������볤��[" << len << "]" << endl;
	else
	{
		cout << len<<" " << daxie <<" " << xiaoxie<<" " << shuzi <<" " << qita << endl;
		mima(key, len, daxie, xiaoxie, shuzi, qita);
		
		for (i = 0; i < M; i++)
			cout << key[i] << endl;
	}
	return 0;
}