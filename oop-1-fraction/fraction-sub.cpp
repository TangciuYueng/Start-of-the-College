#include <iostream>
#include <string>
#include "fraction.h"
using namespace std;
//���캯���������ӷ�ĸ
fraction::fraction(int a, int b) {
    if (a >= 0 && b >= 0)
    {
        up = a;
        down = b;
    }
    else if (a < 0 && b < 0)
    {
        up = -a;
        down = -b;
    }
    else if (a >= 0 && b < 0)
    {
        up = -a;
        down = -b;
    }
    else//(a < 0 && b >= 0)
    {
        up = a;
        down = b;
    }
}
//���캯��ֻ������
fraction::fraction(int a) :up(a), down(1) {

}
//ʲô������
fraction::fraction() :up(0), down(0) {

}
int fraction::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
inline int fraction::my_fabs(int a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}
void fraction::display()
{
    if (up == 0)
        cout << 0 << endl;
    else if (down == up)
        cout << 1 << endl;
    else if (down == 1)
        cout << up << endl;
    else if (down == 0)
        cout << "�������Ϊ��" << endl;
    else
        cout << up << '/' << down << endl;
}
//ȡ�෴����ȡ������stringתfraction��doubleתfraction
fraction fraction::operator-()
{
    up = -up;
    return *this;
}
void fraction::Reciprocal()
{
    if (down == 0)
        cout << "��ĸΪ�㣬����ȡ����" << endl;
    if (up != 0)
    {
        if (up < 0)
        {
            int temp = -up;
            up = -down;
            down = temp;
        }
        else
        {
            int temp = up;
            up = down;
            down = temp;
        }

    }
    else
        cout << "����Ϊ�㣬����ȡ����" << endl;
}
void fraction::Reduction() {
    if (down == 0)
    {
        cout << "��ĸΪ�㣬����Լ��" << endl;
        return;
    }
    int temp = gcd(my_fabs(up), my_fabs(down));
    up /= temp;
    down /= temp;
}
void fraction::StoF(const string& s) {
    int border = s.find('/');
    int u = 0, d = 0;
    bool flag = false;
    //����
    //����Ǹ���
    if (s.front() == '-')
        flag = true;

    //����з�ĸ
    if (border != string::npos)
    {
        for (int i = 0 + flag; i < border; ++i)
            u = u * 10 + (s[i] - '0');
        for (int i = border + 1; i < s.length(); ++i)
            d = d * 10 + (s[i] - '0');
    }
    //û�������ĸ
    else
    {
        for (int i = 0 + flag; i < s.length(); ++i)
            u = u * 10 + s[i] - '0';
        d = 1;
    }

    //���Ӹ���
    if (flag)
        up = -u;
    else
        up = u;
    down = d;
}
fraction fraction::DtoF(const double num)
{
    string temp = to_string(num);
    int border = temp.find('.');
    bool flag = false;
    //�Ǹ���
    if (temp.front() == '-')
        flag = true;
    //�������ֻȡ��λ
    int u = 0;
    int d = 1;
    bool pointAfter = false;
    for (int i = 0 + flag; i < temp.length() && i < 9 + flag; ++i)
    {
        if (i != border)
        {
            u = u * 10 + temp[i] - '0';
            if (pointAfter)
                d *= 10;
        }
        else
            pointAfter = true;
    }
    if (flag)
        up = -u;
    else
        up = u;
    down = d;
    this->Reduction();
    return *this;
}
//�Ӽ��˳�
fraction fraction::operator+(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    int uu = up * f.down + down * f.up;
    int dd = down * f.down;
    fraction t(uu, dd);
    t.Reduction();
    return t;
}
fraction fraction::operator-(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = f;
    t.operator-();
    return *this + t;
}
fraction fraction::operator*(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t1 = *this;
    fraction t2 = f;
    t1.Reduction();
    t2.Reduction();
    //����Լ��
    int x = gcd(my_fabs(t1.up), my_fabs(t2.down));
    t1.up /= x;
    t2.down /= x;
    x = gcd(my_fabs(t1.down), my_fabs(t2.up));
    t1.down /= x;
    t2.up /= x;
    //����t1
    t1.up *= t2.up;
    t1.down *= t2.down;
    t1.Reduction();
    return t1;
}
fraction fraction::operator/(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = f;
    t.Reciprocal();
    return (*this) * t;
}
fraction fraction::operator+(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t(num * down + up, down);
    return t;
}
fraction fraction::operator-(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t(up - num * down, down);
    return t;
}
fraction fraction::operator*(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t(up * num, down);
    t.Reduction();
    return t;
}
fraction fraction::operator/(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t(up, down * num);
    t.Reduction();
    return t;
}
fraction fraction::operator+(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = DtoF(num);
    return *this + t;
}
fraction fraction::operator-(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = DtoF(num);
    return *this - t;
}
fraction fraction::operator*(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = DtoF(num);
    return *this * t;
}
fraction fraction::operator/(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        fraction temp;
        return temp;
    }
    fraction t = DtoF(num);
    return *this / t;
}

void fraction::tongfen(fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return;
    }
    int a = gcd(my_fabs(down), my_fabs(f.down));
    int d1 = down / a;
    int d2 = f.down / a;
    //*this �ķ��ӷ�ĸҪ�� d2��f��d1
    up *= d2;
    down *= d2;
    f.up *= d1;
    f.down *= d1;
}
bool fraction::operator==(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    fraction t1 = *this;
    fraction t2 = f;
    t1.Reduction();
    t2.Reduction();
    return t2.up == t1.up && t1.down == t2.down;
}
bool fraction::operator!=(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return !((*this) == f);
}
bool fraction::operator<(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return (up * f.down - down * f.up) < 0;
}
bool fraction::operator>(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return (up * f.down - down * f.up) > 0;
}
bool fraction::operator<=(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return (up * f.down - down * f.up) <= 0;
}
bool fraction::operator>=(const fraction& f)
{
    if (down == 0 || f.down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return (up * f.down - down * f.up) >= 0;
}
bool fraction::operator==(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return fraction(num) == *this;
}
bool fraction::operator!=(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return !(fraction(num) == *this);
}
bool fraction::operator<(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this < fraction(num);
}
bool fraction::operator>(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this > fraction(num);
}
bool fraction::operator<=(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this <= fraction(num);
}
bool fraction::operator>=(const int num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this >= fraction(num);
}
bool fraction::operator==(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return DtoF(num) == *this;
}
bool fraction::operator!=(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return !(DtoF(num) == *this);
}
bool fraction::operator<(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this < DtoF(num);
}
bool fraction::operator>(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this > DtoF(num);
}
bool fraction::operator<=(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this <= DtoF(num);
}
bool fraction::operator>=(const double num)
{
    if (down == 0)
    {
        cout << "��ĸΪ�㣬�������㣬�����׼ȷ" << endl;
        return 0;
    }
    return *this >= DtoF(num);
}