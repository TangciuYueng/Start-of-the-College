/* 2151298 信11 杨滕超 */
#include <iostream>
#include <string.h>
using namespace std;
#define number 10
#define pass 60
void input(string num[], string name[], int grade[])//注意二维列标要有东西
{
	int i;
	for (i = 0; i < number; i++)
	{
		/*scanf需要地址，数组名字代表地址，+i表示第几个元素的地址*/
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		cin >> num[i];
		cin >> name[i];
		cin >> grade[i];
	}
}
void rankgrade(string num[], string name[], int grade[])
{
	int i, j;
	string num1;
	string name1;
	int grade1[1];

	for (i = 0; i < number - 1; i++)
	{
		for (j = 0; j < number - (i + 1); j++)
		{
			if (grade[j] > grade[j + 1])//大于是升序
			{
				num1 = num[j];
				num[j] = num[j+1];
				num[j+1] = num1;

				name1 = name[j];
				name[j] = name[j+1];
				name[j+1] = name1;

				grade1[0] = grade[j];
				grade[j] = grade[j+1];
				grade[j+1] = grade1[0];

			}
		}
	}
}
void output(string num[], string name[], int grade[])
{
	int i;
	cout << "不及格学生(成绩升序)" << endl;
	for (i = 0; i < number; i++)
	{
		if (grade[i] < pass)
			cout << name[i] << " " << num[i] << " " << grade[i] << endl;
	}
}
int main()
{
	int grade[number];
	string name[number], num[number];
	input(num, name, grade);
	rankgrade(num, name, grade);
	cout << endl;
	output(num, name, grade);
	return 0;
}