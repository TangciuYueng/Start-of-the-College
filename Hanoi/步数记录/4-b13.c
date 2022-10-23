/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int f, ret1, ret2, ret3;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
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
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n",qishi,mubiao);
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(f, qishi, zhongjian, mubiao);
    return 0;

}