#include <iostream>
#include <string>
#include <conio.h>
#include "fraction.h"
using namespace std;

int main() {
    char ch;
    fraction f, ff;
    cout << "����ȡ������" << endl;
    cout << "ԭ�������룬�硰42/8��" << endl;
    //{-3, 34},{7, 2 },{9, 0},{ 0, 1} ,{5, 1}
    //����������ĸΪ1�����ӷ�ĸ��ͬ�����ӷ�ĸΪ��
    string s;
    cin >> s;
    f.StoF(s);
    cout << "����ķ���" << endl;
    f.display();
    cout << "ȡ������"  << endl;
    ff = -f;
    ff.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout << "��������" << endl;
    cin >> s;
    f.StoF(s);
    cout <<  "����ķ���" <<endl;
    f.display();
    f.Reciprocal();
    cout <<  "ȡ����" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout << "����Լ��" << endl;
    cin >> s;
    f.StoF(s);
    cout << "����ķ���"  << endl;
    f.display();
    f.Reduction();
    cout <<  "ȡԼ��"  << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "����double��ת�ɷ���" << endl;
    double num;
    cin >> num;
    f.DtoF(num);
    cout <<  "double��ת�ɷ������" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout << "�����ַ�����ת�ɷ���" << endl;
    cin >> s;
    f.StoF(s);
    cout  << "�ַ�����ת�ɷ������" << endl;
    f.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    //˫Ŀ����
    fraction f1, f2, f3;
    string s1, s2;
    bool res;

    cout <<  "�ӷ�" <<  endl;
    cout << "����������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 + f2;
    cout << "������";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout << "����" << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 - f2;
    cout << "������";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout << "�˷�" << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 * f2;
    cout << "������";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "����"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f3 = f1 / f2;
    cout << "������";
    f3.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "����"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 == f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "������"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 != f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "����" << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 > f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "С��"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 < f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "���ڵ���"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 >= f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout <<  "С�ڵ���"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    res = f1 <= f2;
    cout << "������";
    if (res)
        cout << "��" << endl;
    else
        cout << "��" << endl;
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();

    cout  << "ͨ��"  << endl;
    cout << "������������" << endl;
    cin >> s1 >> s2;
    f1.StoF(s1);
    f2.StoF(s2);
    f1.tongfen(f2);
    cout << "������" << endl;;
    f1.display();
    f2.display();
    cout << "------------------------------------" << endl;
    cout << "�س�����" << endl;
    ch = _getch();
    
    cout << "display()����" << endl;
    cout << "������Ӻͷ�ĸ" << endl;
    int fz, fm;
    cin >> fz >> fm;
    fraction fff(fz, fm);
    cout << "������" << endl;
    fff.display();
    cout << "------------------------------------" << endl;
    cout << "���Խ���" << endl;
    ch = _getch();
    return 0;
}