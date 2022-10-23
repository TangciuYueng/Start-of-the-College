/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double s;
	double a, b, c, d, e, f, g, h, i, j, k, l, m;
	printf("请输入找零值：\n");
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
	printf("共%.0lf张找零，具体如下：\n",m);
	if (a != 0)
		printf("50元 ; %.0lf张\n", a);
	if (b != 0)
        printf("20元 ; %.0lf张\n", b);
	if (c != 0)
        printf("10元 ; %.0lf张\n", c);
	if (d != 0)
		printf("5元  ; %.0lf张\n", d);
	if (e != 0)
        printf("1元  ; %.0lf张\n", e);
	if (h != 0)
        printf("5角  ; %.0lf张\n", h);
	if (i != 0)
	    printf("1角  ; %.0lf张\n", i);
    if (j != 0)
        printf("5分  ; %.0lf张\n", j);
	if (k != 0)
	    printf("2分  ; %.0lf张\n", k);
    if (l != 0)
	    printf("1分  ; %.0lf张\n", l);
	
	return 0;
}