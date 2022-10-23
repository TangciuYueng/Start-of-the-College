#pragma once
using namespace std;
//������
class fraction {
public:
    //���캯���������ӷ�ĸ
    fraction(int a, int b);
    //���캯��ֻ������
    fraction(int a);
    //ʲô������
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
    //����С��Լ���������Ϊ�Ǹ���
    int gcd(int a, int b);
    inline int my_fabs(int a);
};