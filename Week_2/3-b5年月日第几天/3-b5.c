/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &a ,&b , &c);
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
		if (b >= 1 && b <= 12) {
			switch (b) {
				case 1:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 2:
					if (c >= 1 && c <= 29)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 3:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 29 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 4:
					if (c >= 1 && c <= 30)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 29 + 31 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 5:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 6:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 7:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 8:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 9:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 10:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 11:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;
				case 12:
					if (c >= 1 && c <= 31)
						printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c);
					else
						printf("�������-�����µĹ�ϵ�Ƿ�\n");
					break;

			}
		}
		else
			printf("�������-�·ݲ���ȷ\n");
	}
	else {
	if (b >= 1 && b <= 12) {
		switch (b) {
			case 1:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 2:
				if (c >= 1 && c <= 28)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 3:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 28 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 4:
				if (c >= 1 && c <= 30)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 28 + 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 5:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 28 + 31 + 30 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 6:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, 31 + 28 + 31 + 30 + 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 7:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 8:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 9:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 10:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 11:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
			case 12:
				if (c >= 1 && c <= 31)
					printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c,a, 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c);
				else
					printf("�������-�����µĹ�ϵ�Ƿ�\n");
				break;
		}
	}
	else
		printf("�������-�·ݲ���ȷ\n");
	}
	return 0;
}
