/* 2151298 ��11 ������ */
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
	printf("��������[1900-2100]���¡��գ�\n");
	while (1)
	{
		ret = scanf("%d %d %d", &y, &m, &d);
		if (ret != 3)/* �жϷ���ֵ�Ƿ�����*/
		{
			while (getchar() != '\n');
			printf("�����������������\n");
			printf("��������[1900-2100]���¡��գ�\n");
		}
		else/*Ƕ��������*/
		{
			if (y < 1900 || y>2100)
			{
				while (getchar() != '\n');
				printf("��ݲ���ȷ������������\n");
				printf("��������[1900-2100]���¡��գ�\n");
			}
			else
			{
				if (m < 1 || m>12)
				{
					while (getchar() != '\n');
					printf("�·ݲ���ȷ������������\n");
					printf("��������[1900-2100]���¡��գ�\n");
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
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
							}
							else
								break;
						}

						if (m == 2)
						{
							if (d < 1 || d>29)
							{
								while (getchar() != '\n');
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
							}
							else
								break;
						}

						if (m == 4 || m == 6 || m == 9 || m == 11)
						{
							if (d < 1 || d>30)
							{

								while (getchar() != '\n');
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
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
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
							}
							else
								break;
						}

						if (m == 2)
						{
							if (d < 1 || d>28)
							{
								while (getchar() != '\n');
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
							}
							else
								break;
						}

						if (m == 4 || m == 6 || m == 9 || m == 11)
						{
							if (d < 1 || d>30)
							{

								while (getchar() != '\n');
								printf("�ղ���ȷ������������\n");
								printf("��������[1900-2100]���¡��գ�\n");
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
		printf("������\n");
	if (w == 1)
		printf("����һ\n");
	if (w == 2)
		printf("���ڶ�\n");
	if (w == 3)
		printf("������\n");
	if (w == 4)
		printf("������\n");
	if (w == 5)
		printf("������\n");
	if (w == 6)
		printf("������\n");
	return 0;

}