/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;
int a, b, c, i=0;
int A[10], B[10], C[10];
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
    cout << endl;
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
void hanoi(int n, char src, char tmp, char dst)
{
    int m=0;
    cout << setiosflags(ios::right);
    if (n == 1)
    {
        cout << "第" << setw(4) << ++i << " " << "步(" << setw(2) << n << "): " << src << "-->" << dst ;
        change_putout(src, dst);
    }
        
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << ++i << " " << "步(" << setw(2) << n << "): " << src << "-->" << dst ;
        change_putout(src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int f,k,n;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10):" << endl;
        cin >> f;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');   
        }
        if (f >= 1 && f <= 10)
            break;
    }//清除缓冲区要放在循环里面
    
    while (1)
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "请输入起始柱(A-C):" << endl;
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
        cout << "请输入目标柱(A-C):" << endl;
        cin >> mubiao;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "请输入目标柱(A-C):" << endl;
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
            cout << "目标柱(" << mubiao << ")不能与起始柱(" << qishi << ")相同" << endl;
            cin >> mubiao;
        }
        if (mubiao == 'a' || mubiao == 'A' || mubiao == 'b' || mubiao == 'B' || mubiao == 'c' || mubiao == 'C')
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');

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
    cout << "初始:" << "               ";
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
 
    putout();
    hanoi(f, qishi, zhongjian, mubiao);

    return 0;
}