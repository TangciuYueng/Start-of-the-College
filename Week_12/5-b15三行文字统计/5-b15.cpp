/* 2151298 信11 杨滕超 */
#include <iostream>
#include <conio.h>
using namespace std;
#define M 3
#define N 128
int main()
{
	int daxie=0, xiaoxie=0, shuzi=0, kongge=0, qita=0, i, j;
	char str[M][N];
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128, '\n');
	/*记录大写，小写，数字和空格*/
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
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << shuzi << endl;
	cout << "空格 : " << kongge << endl;
	cout << "其它 : " << qita << endl;

	return 0;
}