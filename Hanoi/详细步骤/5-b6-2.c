/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int top[3],abc[3][10],i=0;
void putout()
{
    int k;
    printf(" A:");
    for (k = 0; k < 10; k++)
    {
        if (abc[0][k] == 0)
            printf("  ");
        else
            printf("%2d", abc[0][k]);
    }
    printf(" B:");
    for (k = 0; k < 10; k++)
    {
        if (abc[1][k] == 0)
            printf("  ");
        else
            printf("%2d", abc[1][k]);
    }
    printf(" C:");
    for (k = 0; k < 10; k++)
    {
        if (abc[2][k] == 0)
            printf("  ");
        else
            printf("%2d", abc[2][k]);
    }
    printf("\n");
}
void jilu()
{
    int k, m = 0;
    for (k = 0; k < 11; k++)
    {
        if (abc[0][k] == 0)
        {
            top[0] = k;
            break;
        }
    }
    for (k = 0; k < 11; k++)
    {
        if (abc[1][k] == 0)
        {
            top[1] = k;
            break;
        }
    }
    for (k = 0; k < 11; k++)
    {
        if (abc[2][k] == 0)
        {
            top[2] = k;
            break;
        }
    }
}
void change_putout(char x, char y)
{
    jilu();
    //注意此时的赋值操作可以更加优化：利用相对坐标！！
	//但是为什么不直接--top[]呢，因为我写的每次执行一边还要重新记录一遍top[] 
	abc[y-'A'][top[y-'A']++]=abc[x-'A'][top[x-'A']-1];
	abc[x-'A'][top[x-'A']-1] = 0;
	/*  
    if (x == 'A')
    {
        if (y == 'B')
        {
            abc[1][top[1]] = abc[0][top[0] - 1];
            abc[0][top[0] - 1] = 0;
        }
        else if (y == 'C')
        {
            abc[2][top[2]] = abc[0][top[0] - 1];
            abc[0][top[0] - 1] = 0;
        }
    }
    else if (x == 'B')
    {
        if (y == 'A')
        {
            abc[0][top[0]] = abc[1][top[1] - 1];
            abc[1][top[1] - 1] = 0;
        }
        else if (y == 'C')
        {
            abc[2][top[2]] = abc[1][top[1] - 1];
            abc[1][top[1] - 1] = 0;
        }
    }
    else if (x == 'C')
    {
        if (y == 'A')
        {
            abc[0][top[0]] = abc[2][top[2] - 1];
            abc[2][top[2] - 1] = 0;
        }
        else if (y == 'B')
        {
            abc[1][top[1]] = abc[2][top[2] - 1];
            abc[2][top[2] - 1] = 0;
        }
    }*/ 
    putout();
}
void hanoi(int n, char src, char tmp, char dst)
{
    int m = 0;
    if (n == 1)
    {
        printf("第%4d 步(%2d): %c-->%c",++i,n,src,dst);
        change_putout(src, dst);
    }

    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", ++i, n, src, dst);
        change_putout(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int f, k, n, ret1, ret2, ret3;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10):\n");
        ret1 = scanf("%d", &f);
        if (ret1 != 1 || f < 1 || f>10)
            while (getchar() != '\n');
        else
        {
            while (getchar() != '\n');
            break;
        }
    }

    while (1)
    {
        printf("请输入起始柱(A-C):\n");
        ret2 = scanf("%c", &qishi);
        while (getchar() != '\n');
        if (qishi == 'a' || qishi == 'A' || qishi == 'b' || qishi == 'B' || qishi == 'c' || qishi == 'C')
           break;
    }

    while (1)
    {
        printf("请输入目标柱(A-C):\n");
        ret3 = scanf("%c", &mubiao);
        while (getchar() != '\n');
        if (qishi == mubiao)
        {
            if (mubiao >= 97)
                mubiao = (char)(mubiao - 32);
            if (qishi >= 97)
                qishi = (char)(qishi - 32);
            printf("目标柱(%c)不能与起始柱(%c)相同\n", qishi, mubiao);
        }
        else if (mubiao == 'a' || mubiao == 'A' || mubiao == 'b' || mubiao == 'B' || mubiao == 'c' || mubiao == 'C')
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
    n = f;
    printf("初始:               ");
    if (qishi == 'A')
    {
        for (k = 0; k < f; k++)
        {
            abc[0][k] = n;
            n--;
        }
    }
    else if (qishi == 'B')
    {
        for (k = 0; k < f; k++)
        {
            abc[1][k] = n;
            n--;
        }
    }
    else
    {
        for (k = 0; k < f; k++)
        {
            abc[2][k] = n;
            n--;
        }
    }

    putout();
    hanoi(f, qishi, zhongjian, mubiao);

    return 0;
}
