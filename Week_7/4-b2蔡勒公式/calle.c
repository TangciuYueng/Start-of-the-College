/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int zeller(int y, int m, int d);

int zeller(int y, int m, int d)
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
int main()
{
	int y, m, d, w;
	int ret;
	printf("请输入年[1900-2100]、月、日：\n");
	while (1)
	{
		ret = scanf("%d %d %d", &y, &m, &d);
		if (ret != 3)/* 判断返回值是否是三*/
		{
			while (getchar() != '\n');
			printf("输入错误，请重新输入\n");
			printf("请输入年[1900-2100]、月、日：\n");
		}
		else/*嵌套年月日*/
		{
			if (y < 1900 || y>2100)
			{
				while (getchar() != '\n');
				printf("年份不正确，请重新输入\n");
				printf("请输入年[1900-2100]、月、日：\n");
			}
			else
			{
				if (m < 1 || m>12)
				{
					while (getchar() != '\n');
					printf("月份不正确，请重新输入\n");
					printf("请输入年[1900-2100]、月、日：\n");
				}
				else
				{
					if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
					{
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							if (d < 1 || d>31)
							{
								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}

						if (m == 2)
						{
							if (d < 1 || d>29)
							{
								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}

						if (m == 4 || m == 6 || m == 9 || m == 11)
						{
							if (d < 1 || d>30)
							{

								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}

					}

					if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
					{
						if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
						{
							if (d < 1 || d>31)
							{
								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}

						if (m == 2)
						{
							if (d < 1 || d>28)
							{
								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}

						if (m == 4 || m == 6 || m == 9 || m == 11)
						{
							if (d < 1 || d>30)
							{

								while (getchar() != '\n');
								printf("日不正确，请重新输入\n");
								printf("请输入年[1900-2100]、月、日：\n");
							}
							else
								break;
						}
					}
				}
			}
		}
	}
	w = zeller(y, m, d);

	if (w == 0)
		printf("星期日\n");
	if (w == 1)
		printf("星期一\n");
	if (w == 2)
		printf("星期二\n");
	if (w == 3)
		printf("星期三\n");
	if (w == 4)
		printf("星期四\n");
	if (w == 5)
		printf("星期五\n");
	if (w == 6)
		printf("星期六\n");
	return 0;

}