/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define number 10
#define xuehao 8
#define xingming 9
#define pass 60
void input(char num[][xuehao],char name[][xingming],int grade[])//注意二维列标要有东西
{
	int i;
    for (i = 0; i < number; i++)
    {
		/*scanf需要地址，数组名字代表地址，+i表示第几个元素的地址*/
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
	    scanf("%s", num+i);
	   	scanf("%s", name+i);
	    scanf("%d", grade+i);
	}
}
void ranknum(char num[][xuehao], char name[][xingming], int grade[])
{
	int i, j, k=0, m=0;
	char num1[1][xuehao];
	char name1[1][xingming];
	int grade1[1];
	
	for (i = 0; i < number - 1; i++)
	{
		for (j = 0; j < number - (i + 1); j++)
		{
			if (strlen(num[j]) < strlen(num[j + 1]))//先判断长度
			{
				strcpy(num1[0], num[j]);
					strcpy(num[j], num[j + 1]);
					strcpy(num[j + 1], num1[0]);

					strcpy(name1[0], name[j]);
					strcpy(name[j], name[j + 1]);
					strcpy(name[j + 1], name1[0]);

					grade1[0] = grade[j];
					grade[j] = grade[j + 1];
				grade[j + 1] = grade1[0];
			}
			else if (strcmp(num[j], num[j + 1]) < 0&&(strlen(num[j]) == strlen(num[j + 1])))//注意strcmp“真假”是正负，if的真假是非零和零
			{
				strcpy(num1[0], num[j]);
				strcpy(num[j], num[j+1]);
				strcpy(num[j+1], num1[0]);

				strcpy(name1[0], name[j]);
				strcpy(name[j], name[j+1]);
				strcpy(name[j+1], name1[0]);

				grade1[0] = grade[j];
				grade[j] = grade[j+1];
				grade[j+1] = grade1[0];

			}
		}
	}
}
void output(char num[][xuehao], char name[][xingming], int grade[])
{
	int i;
	printf("及格学生(学号降序)\n");
	for (i = 0; i < number; i++)
	{
		if (grade[i] >= pass)
			printf("%s %s %d\n", name[i], num[i], grade[i]);
	}
}
int main()
{
	int grade[number];
	char name[number][xingming], num[number][xuehao];
	input(num, name, grade);
	ranknum(num, name, grade);
	printf("\n");
	output(num, name, grade);
	return 0;
}