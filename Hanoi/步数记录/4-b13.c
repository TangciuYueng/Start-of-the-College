/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
int i=0;
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        if (1 + i < 10)
            printf("    %d:  %d# %c-->%c\n", ++i, n, src, dst);
        else if (1 + i >= 10 && 1 + i < 100)
            printf("   %d:  %d# %c-->%c\n", ++i, n, src, dst);
        else if (1 + i >= 100 && 1 + i < 1000)
            printf("  %d:  %d# %c-->%c\n", ++i, n, src, dst);
        else if (1 + i >= 1000 && 1 + i < 10000)
            printf(" %d:  %d# %c-->%c\n", ++i, n, src, dst);
        else
            printf("%d:  %d# %c-->%c\n", ++i, n, src, dst);
    }

    else
    {
        hanoi(n - 1, src, dst, tmp);
        if (1 + i < 10)
        {
            if (n >= 10)
                printf("    %d: %d# %c-->%c\n", ++i, n, src, dst);
            else
                printf("    %d:  %d# %c-->%c\n", ++i, n, src, dst);
        }
        else if (1 + i >= 10 && 1 + i < 100)
        {
            if (n >= 10)
                printf("   %d: %d# %c-->%c\n", ++i, n, src, dst);
            else
                printf("   %d:  %d# %c-->%c\n", ++i, n, src, dst);
        }
        else if (1 + i >= 100 && 1 + i < 1000)
        {
            if (n >= 10)
                printf("  %d: %d# %c-->%c\n", ++i, n, src, dst);
            else
                printf("  %d:  %d# %c-->%c\n", ++i, n, src, dst);
        }
        else if (1 + i >= 1000 && 1 + i < 10000)
        {
            if (n >= 10)
                printf(" %d: %d# %c-->%c\n", ++i, n, src, dst);
            else
                printf(" %d:  %d# %c-->%c\n", ++i, n, src, dst);
        }
        else
        {
            if (n >= 10)
                printf("%d: %d# %c-->%c\n", ++i, n, src, dst);
            else
                printf("%d:  %d# %c-->%c\n", ++i, n, src, dst);
        }
        
        hanoi(n - 1, tmp, src, dst);
    }

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int f, ret1, ret2, ret3;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret1 = scanf("%d", &f);
        if (ret1 != 1 || f < 1 || f>16)
            while (getchar() != '\n');
        else
        {
            while (getchar() != '\n');
            break;
        }
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret2 = scanf("%c", &qishi);
        if (ret2 != 1)
            while (getchar() != '\n');
        else if (qishi == 'a' || qishi == 'A' || qishi == 'b' || qishi == 'B' || qishi == 'c' || qishi == 'C')
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
            continue;
        }
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret3 = scanf("%c", &mubiao);
        if (ret3 != 1)
            while (getchar() != '\n');
        else if (qishi == mubiao)
        {
            while (getchar() != '\n');
            if (mubiao >= 97)
                mubiao = (char)(mubiao - 32);
            if (qishi >= 97)
                qishi = (char)(qishi - 32);
            printf("目标柱(%c)不能与起始柱(%c)相同\n",qishi,mubiao);
        }
        else if (mubiao == 'a' || mubiao == 'A' || mubiao == 'b' || mubiao == 'B' || mubiao == 'c' || mubiao == 'C')
        {
            while (getchar() != '\n');
            break;
        }
        else
        {
            while (getchar() != '\n');
            continue;
        }
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
    printf("移动步骤为:\n");
    hanoi(f, qishi, zhongjian, mubiao);
    return 0;

}