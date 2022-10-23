/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;/*!!!!!改进的错误输入和C的格式化在5-b6-2*/

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
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
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        if (1 + i < 10)
            cout << "    " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if(1 + i >= 10 && 1 + i < 100)
            cout << "   " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if (1 + i >= 100 && 1 + i < 1000)
            cout << "  " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if (1 + i >= 1000 && 1 + i < 10000)
            cout << " " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else 
            cout<< ++i << ":  " << n << "# " << src << "-->" << dst << endl;
    }

    else
    {
        hanoi(n - 1, src, dst, tmp);
        if (1 + i < 10)
        {
            if (n >= 10)
                cout << "    " << ++i << ": " << n << "# " << src << "-->" << dst << endl;

            else
                cout << "    " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;

        }
        else if (1 + i >= 10 && 1 + i < 100)
        {
            if (n >= 10)
                cout << "   " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << "   " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;

        }
        else if (1 + i >= 100 && 1 + i < 1000)
        {
            if (n >= 10)
                cout << "  " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << "  " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        }
        else if (1 + i >= 1000 && 1 + i < 10000)
        {
            if (n >= 10)
                cout << " " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << " " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        }
        else
        {
            if (n >= 10)
                cout << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
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
    int f;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> f;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "请输入汉诺塔的层数(1-16)" << endl;
            cin >> f;
        }
        if (f >= 1 && f <= 16)
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> qishi;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "请输入起始柱(A-C)" << endl;
            cin >> qishi;
        }
        if (qishi == 'a' || qishi == 'A' || qishi == 'b' || qishi == 'B' || qishi == 'c' || qishi == 'C')
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> mubiao;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "请输入目标柱(A-C)" << endl;
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

    cout << "移动步骤为:" << endl;

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

    hanoi(f, qishi, zhongjian, mubiao);

    return 0;

}
