/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c, i=0, j, sum;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
	
		while (scanf("%d %d", &a, &b)!=2 ||( a < 2000 || a>2030 || b < 1 || b>12) ){
			
			printf("����Ƿ�������������\n");
			printf("���������(2000-2030)���·�(1-12) : ");
			while (getchar() != '\n');
		}
		if (a >= 2000 && a <= 2030 && b <= 12 && b >= 1)
			    break;

	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", a, b);

		while (scanf("%d", &c) !=1 ||( c < 0 || c>6)) {
			printf("����Ƿ�������������\n");
			printf("���������(2000-2030)���·�(1-12) : ");
			while (getchar() != '\n');
		}
		if (c >= 0 && c <= 6)
			    break;

	}
	printf("\n");
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			i = 31;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 4 || b == 6 || b == 9 || b == 11)
			i = 30;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 2)
			i = 29;

	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			i = 31;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 4 || b == 6 || b == 9 || b == 11)
			i = 30;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 2)
			i = 28;
	j = 2;
	printf("%d��%d�µ�����Ϊ:\n", a, b);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	if (c == 0) {
		sum = 1;
		printf("   1");
	}
		
	else if (c == 1) {
		sum = 2;
		printf("           1");
	}
		
	else if (c == 2) {
		sum = 3;
		printf("                   1");
	}
	else if (c == 3) {
		sum = 4;
		printf("                           1");
	}
	else if (c == 4) {
		sum = 5;
		printf("                                   1");
	}
	else if (c == 5) {
		sum = 6;
		printf("                                           1");
	}
	else  {
		sum = 7;
		printf("                                                   1");
	}
	
	while (j <= i) {
		if (sum % 7 == 0) {
			printf("\n");
			
			printf("%4d", j);
		}
		else {
			printf("%8d", j);

		}
			
		sum = sum + 1;
		j++;
	}

	return 0;
}