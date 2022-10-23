/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		while (getchar() != '\n');//清除缓冲区回车之前的所有东西
		if (ret == 1 && (x >= 0 && x <= 100))
		break;
	}
	printf("x=%d\n", x);
	return 0;
}