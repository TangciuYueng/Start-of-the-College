/* 2151298 ÐÅ11 Ñîëø³¬*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double number;
	double a, b, c, d, e, f, g, h, i, j, k, l, m;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	scanf("%lf", &number);
	a = (int)(number / 1000000000);
    b = (int)((number - a * 1000000000) / 100000000);
    c = (int)((number - a * 1000000000 - b * 100000000) / 10000000);
    d = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000) / 1000000);
    e = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000) / 100000);
    f = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000) / 10000);
    g = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000) / 1000);
    h = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000) / 100);
    i = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100) / 10);
    j = (int)((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100 - i * 10) / 1);
    k = number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100 - i * 10 - j * 1;
    l = (int)(k * 100.001 / 10);
    m = (int)(k * 100.001 - l * 10);

    printf("´óÐ´½á¹ûÊÇ:\n");
    if (!(a == 0 && b == 0)) 
    {
        if (a == 1)
            printf("Ò¼");
        else if (a == 2)
            printf("·¡");
        else if (a == 3)
            printf("Èþ");
        else if (a == 4)
            printf("ËÁ");
        else if (a == 5)
            printf("Îé");
        else if (a == 6)
            printf("Â½");
        else if (a == 7)
            printf("Æâ");
        else if (a == 8)
            printf("°Æ");
        else if (a == 9)
            printf("¾Á");
        printf("Ê°");
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("ÒÚ");

    }
    
    if (!(c == 0 && d == 0 && e == 0 && f == 0))
    {
        if (c == 0 && d == 0 && e == 0 && f != 0)
        {
            if (a != 0 || b != 0)
                printf("Áã");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c == 0 && d == 0 && e != 0 && f == 0) {
            if (a != 0 || b != 0)
                printf("Áã");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°Íò");
        }
        if (c == 0 && d != 0 && e == 0 && f == 0) {  
            if (a != 0 || b != 0)
                printf("Áã");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°ÛÍò");
        }
        if (c != 0 && d == 0 && e == 0 && f == 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("ÇªÍò");
        }
        if (c == 0 && d == 0 && e != 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("Áã");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c == 0 && d != 0 && e == 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("Áã");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°ÛÁã");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c != 0 && d == 0 && e == 0 && f != 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c == 0 && d != 0 && e != 0 && f == 0) {
            if (a != 0 || b != 0)
                printf("Áã");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°Û");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°Íò");
            


        }
        if (c != 0 && d == 0 && e != 0 && f == 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°Íò");
        }
        if (c != 0 && d != 0 && e == 0 && f == 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("Çª");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°ÛÍò");
        }
        if (c != 0 && d != 0 && e != 0 && f == 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("Çª");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°Û");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°Íò");
        }
        if (c != 0 && d != 0 && e == 0 && f != 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("Çª");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°ÛÁã");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c != 0 && d == 0 && e != 0 && f != 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c == 0 && d != 0 && e != 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("Áã");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°Û");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
        if (c != 0 && d != 0 && e != 0 && f != 0) {
            if (c == 1)
                printf("Ò¼");
            else if (c == 2)
                printf("·¡");
            else if (c == 3)
                printf("Èþ");
            else if (c == 4)
                printf("ËÁ");
            else if (c == 5)
                printf("Îé");
            else if (c == 6)
                printf("Â½");
            else if (c == 7)
                printf("Æâ");
            else if (c == 8)
                printf("°Æ");
            else if (c == 9)
                printf("¾Á");
            printf("Çª");
            if (d == 1)
                printf("Ò¼");
            else if (d == 2)
                printf("·¡");
            else if (d == 3)
                printf("Èþ");
            else if (d == 4)
                printf("ËÁ");
            else if (d == 5)
                printf("Îé");
            else if (d == 6)
                printf("Â½");
            else if (d == 7)
                printf("Æâ");
            else if (d == 8)
                printf("°Æ");
            else if (d == 9)
                printf("¾Á");
            printf("°Û");
            if (e == 1)
                printf("Ò¼");
            else if (e == 2)
                printf("·¡");
            else if (e == 3)
                printf("Èþ");
            else if (e == 4)
                printf("ËÁ");
            else if (e == 5)
                printf("Îé");
            else if (e == 6)
                printf("Â½");
            else if (e == 7)
                printf("Æâ");
            else if (e == 8)
                printf("°Æ");
            else if (e == 9)
                printf("¾Á");
            printf("Ê°");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("Íò");
        }
            
    }

    if (!(g == 0 && h == 0 && i == 0 && j == 0)) {
        if (g == 0 && h == 0 && i == 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g == 0 && h == 0 && i != 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°Ô²");
        }
        if (g == 0 && h != 0 && i == 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°ÛÔ²");
        }
        if (g != 0 && h == 0 && i == 0 && j == 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("ÇªÔ²");
        }
        if (g == 0 && h == 0 && i != 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g == 0 && h != 0 && i == 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°ÛÁã");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g != 0 && h == 0 && i == 0 && j != 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g == 0 && h != 0 && i != 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°Û");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°Ô²");
        }
        if (g != 0 && h == 0 && i != 0 && j == 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°Ô²");
        }
        if (g != 0 && h != 0 && i == 0 && j == 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("Çª");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°ÛÔ²");

        }
        if (g != 0 && h != 0 && i != 0 && j == 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("Çª");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°Û");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°Ô²");
        }
        if (g != 0 && h != 0 && i == 0 && j != 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("Çª");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°ÛÁã");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g != 0 && h == 0 && i != 0 && j != 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("ÇªÁã");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g == 0 && h != 0 && i != 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("Áã");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°Û");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }
        if (g != 0 && h != 0 && i != 0 && j != 0) {
            if (g == 1)
                printf("Ò¼");
            else if (g == 2)
                printf("·¡");
            else if (g == 3)
                printf("Èþ");
            else if (g == 4)
                printf("ËÁ");
            else if (g == 5)
                printf("Îé");
            else if (g == 6)
                printf("Â½");
            else if (g == 7)
                printf("Æâ");
            else if (g == 8)
                printf("°Æ");
            else if (g == 9)
                printf("¾Á");
            printf("Çª");
            if (h == 1)
                printf("Ò¼");
            else if (h == 2)
                printf("·¡");
            else if (h == 3)
                printf("Èþ");
            else if (h == 4)
                printf("ËÁ");
            else if (h == 5)
                printf("Îé");
            else if (h == 6)
                printf("Â½");
            else if (h == 7)
                printf("Æâ");
            else if (h == 8)
                printf("°Æ");
            else if (h == 9)
                printf("¾Á");
            printf("°Û");
            if (i == 1)
                printf("Ò¼");
            else if (i == 2)
                printf("·¡");
            else if (i == 3)
                printf("Èþ");
            else if (i == 4)
                printf("ËÁ");
            else if (i == 5)
                printf("Îé");
            else if (i == 6)
                printf("Â½");
            else if (i == 7)
                printf("Æâ");
            else if (i == 8)
                printf("°Æ");
            else if (i == 9)
                printf("¾Á");
            printf("Ê°");
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("Ô²");
        }


    }
    else if(a && b && c && d && e && f && g && h && i && j && k)
    printf("Ô²");

    if (l != 0 && m != 0) {
        if (l == 1)
            printf("Ò¼");
        else if (l == 2)
            printf("·¡");
        else if (l == 3)
            printf("Èþ");
        else if (l == 4)
            printf("ËÁ");
        else if (l == 5)
            printf("Îé");
        else if (l == 6)
            printf("Â½");
        else if (l == 7)
            printf("Æâ");
        else if (l == 8)
            printf("°Æ");
        else if (l == 9)
            printf("¾Á");
        printf("½Ç");
        if (m == 1)
            printf("Ò¼");
        else if (m == 2)
            printf("·¡");
        else if (m == 3)
            printf("Èþ");
        else if (m == 4)
            printf("ËÁ");
        else if (m == 5)
            printf("Îé");
        else if (m == 6)
            printf("Â½");
        else if (m == 7)
            printf("Æâ");
        else if (m == 8)
            printf("°Æ");
        else if (m == 9)
            printf("¾Á");
        printf("·Ö");
    }
    if (l == 0 && m != 0) {
        if (a || b || c || d || e || f || g || h || i || j)
            printf("Áã");
        if (m == 1)
            printf("Ò¼");
        else if (m == 2)
            printf("·¡");
        else if (m == 3)
            printf("Èþ");
        else if (m == 4)
            printf("ËÁ");
        else if (m == 5)
            printf("Îé");
        else if (m == 6)
            printf("Â½");
        else if (m == 7)
            printf("Æâ");
        else if (m == 8)
            printf("°Æ");
        else if (m == 9)
            printf("¾Á");
        printf("·Ö");
    }
    if (l != 0 && m == 0) {
        if (l == 1)
            printf("Ò¼");
        else if (l == 2)
            printf("·¡");
        else if (l == 3)
            printf("Èþ");
        else if (l == 4)
            printf("ËÁ");
        else if (l == 5)
            printf("Îé");
        else if (l == 6)
            printf("Â½");
        else if (l == 7)
            printf("Æâ");
        else if (l == 8)
            printf("°Æ");
        else if (l == 9)
            printf("¾Á");
        printf("½Ç");
    }
    
    if (m == 0) {
        printf("Õû\n");
}

    return 0;
}
