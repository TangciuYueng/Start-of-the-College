/* 2151298 ��11 ������ */
#include <iostream>
#include <conio.h>
using namespace std;
#define M 3
#define N 128
int main()
{
	int daxie=0, xiaoxie=0, shuzi=0, kongge=0, qita=0, i, j;
	char str[M][N];
	cout << "�������1��" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "�������2��" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "�������3��" << endl;
	cin.getline(str[2], 128, '\n');
	/*��¼��д��Сд�����ֺͿո�*/
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				daxie++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				xiaoxie++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				shuzi++;
			else if (str[i][j] == ' ')
				kongge++;
		}
	}
	qita = strlen(str[0]) + strlen(str[1]) + strlen(str[2]) - daxie - xiaoxie - shuzi - kongge;
	cout << "��д : " << daxie << endl;
	cout << "Сд : " << xiaoxie << endl;
	cout << "���� : " << shuzi << endl;
	cout << "�ո� : " << kongge << endl;
	cout << "���� : " << qita << endl;

	return 0;
}