/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
using namespace std;
void weekputout1()
{
	cout << "            1��                             2��                             3��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}
void weekputout2()
{
	cout << "            4��                             5��                             6��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}
void weekputout3()
{
	cout << "            7��                             8��                             9��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}
void weekputout4()
{
	cout << "           10��                            11��                            12��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
}
int zeller(int y, int m, int d = 1)
{
	int w = 0, c = 0;
	if (m >= 3) {
		c = y / 100;
		y = y - c * 100;
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	}
	if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 12 + 1) / 5 + d - 1;
	}

	if (w >= 0)
		w = w % 7;
	else {
		while (w < 0) {
			w = w + 7;
		}
		w = w % 7;
	}
	return w;
}
void year_canlender(int y)
{
	int i, j, leap, k, t[4] = {0}, firstday, season1[6][23] = { 0 }, season2[6][23] = { 0 }, season3[6][23] = { 0 }, season4[6][23] = { 0 };
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)//�ж��Ƿ�����
		leap = 1;
	else
		leap = 0;
	int m[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 }, year[12][42] = { 0 };//�·��������,������·ݣ�1
	/*�·ݸ�ֵ*/
	for (i = 0; i < 12; i++)
	{
		for (k = 1, firstday = zeller(y, i + 1); k <= m[i]; k++,firstday++)//ÿ�µĸ�ֵ��zeller ��ÿ�µ�һ�����ڼ���ǰ����ż�����
		    year[i][firstday] = k;
	}
	/*���ȸ�ֵ*/
	for (i = 0; i < 6; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if(j!=7&&j!=15)
			    season1[i][j] = year[(j / 8)][i * 7 + j % 8];//��ѧ����ת��
		}
	}
	for (i = 0; i < 6; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (j != 7 && j != 15)
				season2[i][j] = year[(j / 8)+3][i * 7 + j % 8];
		}
	}
	for (i = 0; i < 6; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (j != 7 && j != 15)
				season3[i][j] = year[(j / 8)+6][i * 7 + j % 8];
		}
	}
	for (i = 0; i < 6; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (j != 7 && j != 15)
				season4[i][j] = year[(j / 8)+9][i * 7 + j % 8];
		}
	}
	/*ÿ���������һ�������ּ�¼*/
	for (i = 0; i < 23; i++)
	{
		if (season1[5][i] != 0)
			t[0]++;
		if (season2[5][i] != 0)
			t[1]++;
		if (season3[5][i] != 0)
			t[2]++;
		if (season4[5][i] != 0)
			t[3]++;
	}
	/*�ĸ����ȴ�ӡ*/
	weekputout1();
	for (i = 0; i < 5; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season1[i][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season1[i][j];
		}
		cout << endl ;
		
	}
	if (t[0])//�����ж����һ��
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season1[5][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season1[i][j];

		}
		cout << endl;
	}
		cout << endl;
	weekputout2();
	for (i = 0; i < 5; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season2[i][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season2[i][j];
			
		}
		cout << endl ;
	}
	if (t[1])//�����ж����һ��
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season2[5][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season2[i][j];

		}
		cout << endl;
	}
	cout << endl;
	weekputout3();
	for (i = 0; i < 5; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season3[i][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season3[i][j];
		}
		cout << endl;
	}
	if (t[2])//�����ж����һ��
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season3[5][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season3[i][j];

		}
		cout << endl;
	}
		cout << endl;
	weekputout4();
	for (i = 0; i < 5; i++)//i�Ǽ��ȵ�������
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season4[i][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season4[i][j];
		}
		cout << endl;
	}
	if (t[3])//�����ж����һ��
	{
		for (j = 0; j < 23; j++)//j�Ǽ��ȵ�������
		{
			if (season4[5][j] == 0)
				cout << "    ";
			else
				cout << setw(4) << setiosflags(ios::left) << season4[i][j];

		}
		cout << endl;
	}
		cout << endl;
}
int main()
{ 
	system("mode con cols=120 lines=45");
	int y;
	while (1)
	{
		cout << "���������[1900-2100]" << endl;
		cin >> y;
		if (cin.fail() || y < 1900 || y>2100)
		{
			cin.clear();
			cin.ignore(65536,'\n');
			continue;
		}
		if (y <= 2100 && y >= 1900)
			break;
	}
	cout << y << "�������:" << endl;
	cout << endl;
	year_canlender(y);
	cout << endl;
	return 0;
}