#include <iostream>
#include <string>
#include <conio.h>
#include "fraction.h"
using namespace std;

int main() {
    char ch;
    fraction f, ff;
    cout << "测试取负运算" << endl;
    cout << "原数据输入，如“42/8”" << endl;
    //{-3, 34},{7, 2 },{9, 0},{ 0, 1} ,{5, 1}
    //正数负数分母为1、分子分母相同、分子分母为零
    string s;
    cin >> s;
    f.StoF(s);
    cout << "输入的分数" << endl;
    f.display();
    cout << "取负运算"  << endl;
    ff = -f;
    ff.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout << "测试求倒数" << endl;
    cin >> s;
    f.StoF(s);
    cout <<  "输入的分数" <<endl;
    f.display();
    f.Reciprocal();
    cout <<  "取倒数" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout << "测试约分" << endl;
    cin >> s;
    f.StoF(s);
    cout << "输入的分数"  << endl;
    f.display();
    f.Reduction();
    cout <<  "取约分"  << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "测试double型转成分数" << endl;
    double num;
    cin >> num;
    f.DtoF(num);
    cout <<  "double型转成分数结果" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout << "测试字符串型转成分数" << endl;
    cin >> s;
    f.StoF(s);
    cout  << "字符串型转成分数结果" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    //双目运算
    fraction f1, f2, f3;
    string s1, s2;
    bool res;

    cout <<  "加法" <<  endl;
    cout << "输入两个数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 + f2;
    cout << "运算结果";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout << "减法" << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 - f2;
    cout << "运算结果";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout << "乘法" << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 * f2;
    cout << "运算结果";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "除法"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 / f2;
    cout << "运算结果";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "等于"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 == f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "不等于"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 != f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "大于" << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 > f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "小于"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 < f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "大于等于"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 >= f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout <<  "小于等于"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 <= f2;
    cout << "运算结果";
    if (res)
        cout << "真" << endl;
    else
        cout << "假" << endl;
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();

    cout  << "通分"  << endl;
    cout << "输入两个分数" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f1.tongfen(f2);
    cout << "运算结果" << endl;;
    f1.display();
    f2.display();
    cout << "------------------------------------" << endl;
    cout << "回车继续" << endl;
    ch = _getch();
    
    cout << "display()函数" << endl;
    cout << "输入分子和分母" << endl;
    int fz, fm;
    cin >> fz >> fm;
    fraction fff(fz, fm);
    cout << "运算结果" << endl;
    fff.display();
    cout << "------------------------------------" << endl;
    cout << "测试结束" << endl;
    ch = _getch();
    return 0;
}