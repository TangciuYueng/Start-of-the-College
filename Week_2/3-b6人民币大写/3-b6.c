/* 2151298 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double number;
	double a, b, c, d, e, f, g, h, i, j, k, l, m;
	printf("������[0-100��)֮�������:\n");
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

    printf("��д�����:\n");
    if (!(a == 0 && b == 0)) 
    {
        if (a == 1)
            printf("Ҽ");
        else if (a == 2)
            printf("��");
        else if (a == 3)
            printf("��");
        else if (a == 4)
            printf("��");
        else if (a == 5)
            printf("��");
        else if (a == 6)
            printf("½");
        else if (a == 7)
            printf("��");
        else if (a == 8)
            printf("��");
        else if (a == 9)
            printf("��");
        printf("ʰ");
        if (b == 1)
            printf("Ҽ");
        else if (b == 2)
            printf("��");
        else if (b == 3)
            printf("��");
        else if (b == 4)
            printf("��");
        else if (b == 5)
            printf("��");
        else if (b == 6)
            printf("½");
        else if (b == 7)
            printf("��");
        else if (b == 8)
            printf("��");
        else if (b == 9)
            printf("��");
        printf("��");

    }
    
    if (!(c == 0 && d == 0 && e == 0 && f == 0))
    {
        if (c == 0 && d == 0 && e == 0 && f != 0)
        {
            if (a != 0 || b != 0)
                printf("��");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c == 0 && d == 0 && e != 0 && f == 0) {
            if (a != 0 || b != 0)
                printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ��");
        }
        if (c == 0 && d != 0 && e == 0 && f == 0) {  
            if (a != 0 || b != 0)
                printf("��");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("����");
        }
        if (c != 0 && d == 0 && e == 0 && f == 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ��");
        }
        if (c == 0 && d == 0 && e != 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c == 0 && d != 0 && e == 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("��");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("����");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c != 0 && d == 0 && e == 0 && f != 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ��");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c == 0 && d != 0 && e != 0 && f == 0) {
            if (a != 0 || b != 0)
                printf("��");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ��");
            


        }
        if (c != 0 && d == 0 && e != 0 && f == 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ��");
        }
        if (c != 0 && d != 0 && e == 0 && f == 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("����");
        }
        if (c != 0 && d != 0 && e != 0 && f == 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ��");
        }
        if (c != 0 && d != 0 && e == 0 && f != 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("����");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c != 0 && d == 0 && e != 0 && f != 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c == 0 && d != 0 && e != 0 && f != 0) {
            if (a != 0 || b != 0)
                printf("��");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
        if (c != 0 && d != 0 && e != 0 && f != 0) {
            if (c == 1)
                printf("Ҽ");
            else if (c == 2)
                printf("��");
            else if (c == 3)
                printf("��");
            else if (c == 4)
                printf("��");
            else if (c == 5)
                printf("��");
            else if (c == 6)
                printf("½");
            else if (c == 7)
                printf("��");
            else if (c == 8)
                printf("��");
            else if (c == 9)
                printf("��");
            printf("Ǫ");
            if (d == 1)
                printf("Ҽ");
            else if (d == 2)
                printf("��");
            else if (d == 3)
                printf("��");
            else if (d == 4)
                printf("��");
            else if (d == 5)
                printf("��");
            else if (d == 6)
                printf("½");
            else if (d == 7)
                printf("��");
            else if (d == 8)
                printf("��");
            else if (d == 9)
                printf("��");
            printf("��");
            if (e == 1)
                printf("Ҽ");
            else if (e == 2)
                printf("��");
            else if (e == 3)
                printf("��");
            else if (e == 4)
                printf("��");
            else if (e == 5)
                printf("��");
            else if (e == 6)
                printf("½");
            else if (e == 7)
                printf("��");
            else if (e == 8)
                printf("��");
            else if (e == 9)
                printf("��");
            printf("ʰ");
            if (f == 1)
                printf("Ҽ");
            else if (f == 2)
                printf("��");
            else if (f == 3)
                printf("��");
            else if (f == 4)
                printf("��");
            else if (f == 5)
                printf("��");
            else if (f == 6)
                printf("½");
            else if (f == 7)
                printf("��");
            else if (f == 8)
                printf("��");
            else if (f == 9)
                printf("��");
            printf("��");
        }
            
    }

    if (!(g == 0 && h == 0 && i == 0 && j == 0)) {
        if (g == 0 && h == 0 && i == 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g == 0 && h == 0 && i != 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰԲ");
        }
        if (g == 0 && h != 0 && i == 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��Բ");
        }
        if (g != 0 && h == 0 && i == 0 && j == 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("ǪԲ");
        }
        if (g == 0 && h == 0 && i != 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰ");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g == 0 && h != 0 && i == 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("����");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g != 0 && h == 0 && i == 0 && j != 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ��");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g == 0 && h != 0 && i != 0 && j == 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰԲ");
        }
        if (g != 0 && h == 0 && i != 0 && j == 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰԲ");
        }
        if (g != 0 && h != 0 && i == 0 && j == 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��Բ");

        }
        if (g != 0 && h != 0 && i != 0 && j == 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰԲ");
        }
        if (g != 0 && h != 0 && i == 0 && j != 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("����");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g != 0 && h == 0 && i != 0 && j != 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰ");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g == 0 && h != 0 && i != 0 && j != 0) {
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
                printf("��");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰ");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }
        if (g != 0 && h != 0 && i != 0 && j != 0) {
            if (g == 1)
                printf("Ҽ");
            else if (g == 2)
                printf("��");
            else if (g == 3)
                printf("��");
            else if (g == 4)
                printf("��");
            else if (g == 5)
                printf("��");
            else if (g == 6)
                printf("½");
            else if (g == 7)
                printf("��");
            else if (g == 8)
                printf("��");
            else if (g == 9)
                printf("��");
            printf("Ǫ");
            if (h == 1)
                printf("Ҽ");
            else if (h == 2)
                printf("��");
            else if (h == 3)
                printf("��");
            else if (h == 4)
                printf("��");
            else if (h == 5)
                printf("��");
            else if (h == 6)
                printf("½");
            else if (h == 7)
                printf("��");
            else if (h == 8)
                printf("��");
            else if (h == 9)
                printf("��");
            printf("��");
            if (i == 1)
                printf("Ҽ");
            else if (i == 2)
                printf("��");
            else if (i == 3)
                printf("��");
            else if (i == 4)
                printf("��");
            else if (i == 5)
                printf("��");
            else if (i == 6)
                printf("½");
            else if (i == 7)
                printf("��");
            else if (i == 8)
                printf("��");
            else if (i == 9)
                printf("��");
            printf("ʰ");
            if (j == 1)
                printf("Ҽ");
            else if (j == 2)
                printf("��");
            else if (j == 3)
                printf("��");
            else if (j == 4)
                printf("��");
            else if (j == 5)
                printf("��");
            else if (j == 6)
                printf("½");
            else if (j == 7)
                printf("��");
            else if (j == 8)
                printf("��");
            else if (j == 9)
                printf("��");
            printf("Բ");
        }


    }
    else if(a && b && c && d && e && f && g && h && i && j && k)
    printf("Բ");

    if (l != 0 && m != 0) {
        if (l == 1)
            printf("Ҽ");
        else if (l == 2)
            printf("��");
        else if (l == 3)
            printf("��");
        else if (l == 4)
            printf("��");
        else if (l == 5)
            printf("��");
        else if (l == 6)
            printf("½");
        else if (l == 7)
            printf("��");
        else if (l == 8)
            printf("��");
        else if (l == 9)
            printf("��");
        printf("��");
        if (m == 1)
            printf("Ҽ");
        else if (m == 2)
            printf("��");
        else if (m == 3)
            printf("��");
        else if (m == 4)
            printf("��");
        else if (m == 5)
            printf("��");
        else if (m == 6)
            printf("½");
        else if (m == 7)
            printf("��");
        else if (m == 8)
            printf("��");
        else if (m == 9)
            printf("��");
        printf("��");
    }
    if (l == 0 && m != 0) {
        if (a || b || c || d || e || f || g || h || i || j)
            printf("��");
        if (m == 1)
            printf("Ҽ");
        else if (m == 2)
            printf("��");
        else if (m == 3)
            printf("��");
        else if (m == 4)
            printf("��");
        else if (m == 5)
            printf("��");
        else if (m == 6)
            printf("½");
        else if (m == 7)
            printf("��");
        else if (m == 8)
            printf("��");
        else if (m == 9)
            printf("��");
        printf("��");
    }
    if (l != 0 && m == 0) {
        if (l == 1)
            printf("Ҽ");
        else if (l == 2)
            printf("��");
        else if (l == 3)
            printf("��");
        else if (l == 4)
            printf("��");
        else if (l == 5)
            printf("��");
        else if (l == 6)
            printf("½");
        else if (l == 7)
            printf("��");
        else if (l == 8)
            printf("��");
        else if (l == 9)
            printf("��");
        printf("��");
    }
    
    if (m == 0) {
        printf("��\n");
}

    return 0;
}
