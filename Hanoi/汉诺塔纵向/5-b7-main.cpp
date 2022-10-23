/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "5-b7.h"
using namespace std;
int a, b, c, i = 0;
int A[10], B[10], C[10];
void verticle_putout();
void change_verticle_putout(char x,char y);
void putout()
{
    int k;
    cout << " A:";
    for (k = 0; k < 10; k++)
    {
        if (A[k] == 0)
            cout << "  ";
        else
            cout << setw(2) << A[k];
    }
    cout << " B:";
    for (k = 0; k < 10; k++)
    {
        if (B[k] == 0)
            cout << "  ";
        else
            cout << setw(2) << B[k];
    }
    cout << " C:";
    for (k = 0; k < 10; k++)
    {
        if (C[k] == 0)
            cout << "  ";
        else
            cout << setw(2) << C[k];
    }
}
void jilu()
{
    int k, m = 0;
    for (k = 0; k < 11; k++)
    {
        if (A[k] == 0)
        {
            a = k;
            break;
        }
    }
    for (k = 0; k < 11; k++)
    {
        if (B[k] == 0)
        {
            b = k;
            break;
        }
    }
    for (k = 0; k < 11; k++)
    {
        if (C[k] == 0)
        {
            c = k;
            break;
        }
    }
}
void change_putout(char x, char y)
{
    jilu();
    if (x == 'A')
    {
        if (y == 'B')
        {
            B[b] = A[a - 1];
            A[a - 1] = 0;
        }
        else if (y == 'C')
        {
            C[c] = A[a - 1];
            A[a - 1] = 0;
        }
    }
    else if (x == 'B')
    {
        if (y == 'A')
        {
            A[a] = B[b - 1];
            B[b - 1] = 0;
        }
        else if (y == 'C')
        {
            C[c] = B[b - 1];
            B[b - 1] = 0;
        }
    }
    else if (x == 'C')
    {
        if (y == 'A')
        {
            A[a] = C[c - 1];
            C[c - 1] = 0;
        }
        else if (y == 'B')
        {
            B[b] = C[c - 1];
            C[c - 1] = 0;
        }
    }
    putout();
}
void hanoi(int n, char src, char tmp, char dst,int xianshi)
{
    int m = 0;
    char ch;
    cout << setiosflags(ios::right);
    if (n == 1)
    {
        if (xianshi == 0)
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ")";
            change_verticle_putout(src, dst);
              
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                    break;
            }
        }
        else
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ") ";
            change_putout(src, dst);
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                {
                    verticle_putout();
                    while (1)
                    {
                        ch = _getch();
                        if (ch == 13)
                            break;
                    }
                    break;
                }
            }
            
        }
    }

    else
    {
        hanoi(n - 1, src, dst, tmp, xianshi);
        if (xianshi == 0)
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ")";
             change_verticle_putout(src, dst);
                
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                    break;
            }
        }
        else
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ") ";
            change_putout(src, dst);
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                {
                    verticle_putout();
                    while (1)
                    {
                        ch = _getch();
                        if (ch == 13)
                            break;
                    }
                    break;
                }
            }
            
        }
        hanoi(n - 1, tmp, src, dst, xianshi);
        
        
    }
}
void hanoi1 (int n, char src, char tmp, char dst, int xianshi, int speed)
{
    int m = 0;
    cout << setiosflags(ios::right);
    if (n == 1)
    {
        if (xianshi == 0)
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ")";
            change_verticle_putout(src, dst);

            Sleep(500/speed);
        }
        else
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ") ";
            change_putout(src, dst);
            Sleep(500/speed);
            verticle_putout();
            Sleep(500/speed);
        }
    }

    else
    {
        hanoi1 (n - 1, src, dst, tmp, xianshi, speed);
        if (xianshi == 0)
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ")";
            change_verticle_putout(src, dst);
            Sleep(500/speed);
            
        }
        else
        {
            cct_gotoxy(0, 17);
            cout << "��" << setw(4) << ++i << "��(" << n << "#: " << src << "-->" << dst << ") ";
            change_putout(src, dst);
            Sleep(500/speed);
            verticle_putout();
            Sleep(500/speed);
        }
        hanoi1 (n - 1, tmp, src, dst, xianshi, speed);


    }
}
void kuangjia()
{
    cct_gotoxy(9, 12);
    cout << "=========================";
    cct_gotoxy(9, 13);
    cout << "  A         B         C";
}
void verticle_putout()
{
    kuangjia();
    const int XA = 11, XB = 21, XC = 31, Y = 11;
    int x, y, k = 0;
    x = XA;
    y = Y;
    cct_gotoxy(x, y);
    for (k = 0; k < 10; k++)
    {
        if (A[k] == 0)
            cout << "  ";
        else
        {
            if (A[k] == 10)
                cout << A[k];
            else
            {
                cct_gotoxy(x - 1, y);
                cout << " " << A[k];
            }
        }
        y--;
        cct_gotoxy(x-1, y);
    }
    x = XB;
    y = Y;
    cct_gotoxy(x, y);
    for (k = 0; k < 10; k++)
    {
        if (B[k] == 0)
            cout << "  ";
        else
        {
            if (B[k] == 10)
                cout << B[k];
            else
            {
                cct_gotoxy(x - 1, y);
                cout << " " << B[k];
            }
        }
        y--;
        cct_gotoxy(x - 1, y);
    }
    x = XC;
    y = Y;
    cct_gotoxy(x, y);
    for (k = 0; k < 10; k++)
    {
        if (C[k] == 0)
            cout << "  ";
        else
        {
            if (C[k] == 10)
                cout << C[k];
            else
            {
                cct_gotoxy(x - 1, y);
                cout << " " << C[k];
            }
        }
        y--;
        cct_gotoxy(x - 1, y);
    }
}
void change_verticle_putout(char x, char y)
{
    jilu();
    if (x == 'A')
    {
        if (y == 'B')
        {
            B[b] = A[a - 1];
            A[a - 1] = 0;
        }
        else if (y == 'C')
        {
            C[c] = A[a - 1];
            A[a - 1] = 0;
        }
    }
    else if (x == 'B')
    {
        if (y == 'A')
        {
            A[a] = B[b - 1];
            B[b - 1] = 0;
        }
        else if (y == 'C')
        {
            C[c] = B[b - 1];
            B[b - 1] = 0;
        }
    }
    else if (x == 'C')
    {
        if (y == 'A')
        {
            A[a] = C[c - 1];
            C[c - 1] = 0;
        }
        else if (y == 'B')
        {
            B[b] = C[c - 1];
            C[c - 1] = 0;
        }
    }
    verticle_putout();
}
int main()
{
    int f, k, n, speed, xianshi;
    char qishi, mubiao, zhongjian, ch;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10):" << endl;
        cin >> f;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        if (f >= 1 && f <= 10)
            break;
    }//���������Ҫ����ѭ������

    while (1)
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "��������ʼ��(A-C):" << endl;
        cin >> qishi;
        if (qishi == 'a' || qishi == 'A' || qishi == 'b' || qishi == 'B' || qishi == 'c' || qishi == 'C')
            break;
        else
            continue;
    }

    while (1)
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "������Ŀ����(A-C):" << endl;
        cin >> mubiao;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "������Ŀ����(A-C):" << endl;
            cin >> mubiao;
        }
        while (mubiao == qishi)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            if (mubiao >= 97)
                mubiao = (char)(mubiao - 32);
            if (qishi >= 97)
                qishi = (char)(qishi - 32);
            cout << "Ŀ����(" << mubiao << ")��������ʼ��(" << qishi << ")��ͬ" << endl;
            cin >> mubiao;
        }
        if (mubiao == 'a' || mubiao == 'A' || mubiao == 'b' || mubiao == 'B' || mubiao == 'c' || mubiao == 'C')
            break;
    }


    if (mubiao >= 97)
        mubiao = (char)(mubiao - 32);
    if (qishi >= 97)
        qishi = (char)(qishi - 32);

    if (qishi != 'A' && mubiao != 'A')
        zhongjian = 'A';
    else if (qishi != 'B' && mubiao != 'B')
        zhongjian = 'B';
    else
        zhongjian = 'C';
    while (1)
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
        if ((speed == 1 || speed == 2 || speed == 3 || speed == 4 || speed == 5 || speed == 0)&&cin.good())
            break;
    }
    while (1)
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> xianshi;
        if ((xianshi == 1 || xianshi == 0)&&cin.good())
            break;
    }
    n = f;
    
    cct_cls();
    if(xianshi==1)
        cout << "�� " << qishi << " �ƶ��� " << mubiao << "���� " << f << " �㣬��ʱ����Ϊ " << speed << "����ʾ�ڲ�����ֵ" << endl;
    else
        cout << "�� " << qishi << " �ƶ��� " << mubiao << "���� " << f << " �㣬��ʱ����Ϊ " << speed << "������ʾ�ڲ�����ֵ" << endl;
    /*�����ʼ��ֵ*/ 
    if (qishi == 'A')
    {
        for (k = 0; k < f; k++)
        {
            A[k] = n;
            n--;
        }
    }
    else if (qishi == 'B')
    {
        for (k = 0; k < f; k++)
        {
            B[k] = n;
            n--;
        }
    }
    else
    {
        for (k = 0; k < f; k++)
        {
            C[k] = n;
            n--;
        }
    }
    cct_gotoxy(0, 17);
    /*��ʼ*/
    if (speed == 0)
    {
        if (xianshi == 0)
        {
            verticle_putout();
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                {
                    hanoi(f, qishi, zhongjian, mubiao, xianshi);
                    cct_gotoxy(0, 27);
                    break;
                }

            }
        }
        else
        {
            cout << "��ʼ:" << "               ";
            putout();
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                {
                    verticle_putout();
                    while (1)
                    {
                        ch = _getch();
                        if (ch == 13)
                        {
                            hanoi(f, qishi, zhongjian, mubiao, xianshi);
                            cct_gotoxy(0, 27);
                            break;
                        }
                    }
                    break;
                }
            }

        }
    }
    else
    {
        if (xianshi == 0)
        {
            verticle_putout();
            Sleep(500/speed);
            hanoi1 (f, qishi, zhongjian, mubiao, xianshi, speed);
            Sleep(500/speed);
            cct_gotoxy(0, 27);
        }
        else
        {
            cout << "��ʼ:" << "               ";
            putout();
            Sleep(500/speed);
            verticle_putout();
            Sleep(500/speed);
            hanoi1 (f, qishi, zhongjian, mubiao, xianshi, speed);
            cct_gotoxy(0, 27);
        }
    }
    return 0;
}