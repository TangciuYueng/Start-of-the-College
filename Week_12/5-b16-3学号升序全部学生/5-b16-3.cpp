/* 2151298 ��11 ������ */
#include <iostream>
#include <string.h>
using namespace std;
#define number 10
void input(string num[], string name[], int grade[])//ע���ά�б�Ҫ�ж���
{
	int i;
	for (i = 0; i < number; i++)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		cin >> num[i];
		cin >> name[i];
		cin >> grade[i];
	}
}
void ranknum(string num[], string name[], int grade[])
{
	int i, j;
	string num1;
	string name1;
	int grade1[1];

	for (i = 0; i < number - 1; i++)
	{
		for (j = 0; j < number - (i + 1); j++)
		{
			if (num[j].length()>num[j+1].length()) 
			{
				num1 = num[j];
				num[j] = num[j + 1];
				num[j + 1] = num1;

				name1 = name[j];
				name[j] = name[j + 1];
				name[j + 1] = name1;

				grade1[0] = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = grade1[0];
			}
			else if (num[j]> num[j + 1]&&(num[j].length()==num[j+1].length()))
			{
				num1 = num[j];
				num[j] = num[j + 1];
				num[j + 1] = num1;

				name1 = name[j];
				name[j] = name[j + 1];
				name[j + 1] = name1;

				grade1[0] = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = grade1[0];
			}
		}
	}
}
void output(string num[], string name[], int grade[])
{
	int i;
	cout << "ȫ��ѧ��(ѧ������)" << endl;
	for (i = 0; i < number; i++)
	{
		cout << name[i] << " " << num[i] << " " << grade[i] << endl;
	}
}
int main()
{
	int grade[number];
	string name[number], num[number];
	input(num, name, grade);
	ranknum(num, name, grade);
	cout << endl;
	output(num, name, grade);
	return 0;
}
