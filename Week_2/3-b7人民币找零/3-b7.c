/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double s;
	double a, b, c, d, e, f, g, h, i, j, k, l, m;
	printf("����������ֵ��\n");
    scanf("%lf", &s);
	a = (int)(s / 50);
	b = (int)((s - a * 50) / 20);
	c = (int)((s - a * 50 - b * 20) / 10);
	d = (int)((s - a * 50 - b * 20 - c * 10) / 5);
	e = (int)((s - a * 50 - b * 20 - c * 10 - d * 5) / 1);
	f = s - a * 50 - b * 20 - c * 10 - d * 5 - e * 1;
	g = (int)(f * 100);
	h = (int)(g / 50);
	i = (int)((g - h * 50) / 10);
	j = (int)((g - h * 50 - i * 10) / 5);
	k = (int)((g - h * 50 - i * 10 - j * 5) / 2);
	l = (int)((g - h * 50 - i * 10 - j * 5 - k * 2) / 1);
	m = a + b + c + d + e + h + i + j + k + l;
	printf("��%.0lf�����㣬�������£�\n",m);
	if (a != 0)
		printf("50Ԫ ; %.0lf��\n", a);
	if (b != 0)
        printf("20Ԫ ; %.0lf��\n", b);
	if (c != 0)
        printf("10Ԫ ; %.0lf��\n", c);
	if (d != 0)
		printf("5Ԫ  ; %.0lf��\n", d);
	if (e != 0)
        printf("1Ԫ  ; %.0lf��\n", e);
	if (h != 0)
        printf("5��  ; %.0lf��\n", h);
	if (i != 0)
	    printf("1��  ; %.0lf��\n", i);
    if (j != 0)
        printf("5��  ; %.0lf��\n", j);
	if (k != 0)
	    printf("2��  ; %.0lf��\n", k);
    if (l != 0)
	    printf("1��  ; %.0lf��\n", l);
	
	return 0;
}