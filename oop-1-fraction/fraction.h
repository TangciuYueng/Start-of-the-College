#pragma once
using namespace std;
//分数类
class fraction {
public:
    //构造函数给出分子分母
    fraction(int a, int b);
    //构造函数只给分子
    fraction(int a);
    //什么都不给
    fraction();

    fraction operator-();
    void Reciprocal();
    void Reduction();
    void StoF(const string& s);
    fraction DtoF(const double num);
    void display();

    fraction operator+(const fraction& f);
    fraction operator+(const int num);
    fraction operator+(const double num);
    fraction operator-(const fraction& f);
    fraction operator-(const int num);
    fraction operator-(const double num);
    fraction operator*(const fraction& f);
    fraction operator*(const int num);
    fraction operator*(const double num);
    fraction operator/(const fraction& f);
    fraction operator/(const int num);
    fraction operator/(const double num);
    void tongfen(fraction& f);

    bool operator==(const fraction& f);
    bool operator!=(const fraction& f);
    bool operator<(const fraction& f);
    bool operator>(const fraction& f);
    bool operator<=(const fraction& f);
    bool operator>=(const fraction& f);
    bool operator==(const int num);
    bool operator!=(const int num);
    bool operator<(const int num);
    bool operator>(const int num);
    bool operator<=(const int num);
    bool operator>=(const int num);
    bool operator==(const double num);
    bool operator!=(const double num);
    bool operator<(const double num);
    bool operator>(const double num);
    bool operator<=(const double num);
    bool operator>=(const double num);
private:
    int up;
    int down;
    //求最小公约数，进入的为非负数
    int gcd(int a, int b);
    inline int my_fabs(int a);
};