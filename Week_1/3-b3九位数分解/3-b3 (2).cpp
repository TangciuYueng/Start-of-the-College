/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "ʮ��λ : " << (long long)a / 1000000000 << endl;
	cout << "��λ   : " << (long long)a % 1000000000 / 100000000 << endl;
	cout << "ǧ��λ : " << (long long)a % 100000000 / 10000000 << endl;
	cout << "����λ : " << (long long)a % 10000000 / 1000000<< endl;
	cout << "ʮ��λ : " << (long long)a % 1000000 / 100000 << endl;
	cout << "��λ   : " << (long long)a % 100000 / 10000 << endl;
	cout << "ǧλ   : " << (long long)a % 10000 / 1000 << endl;
	cout << "��λ   : " << (long long)a % 1000 / 100 << endl;
	cout << "ʮλ   : " << (long long)a % 100 / 10 << endl;
	cout << "Ԫ     : " << (long long)a % 10 << endl;
	cout << "��     : " << int ((a - (long long)a) * 100.001) % 100 / 10 << endl;
	cout << "��     : " << int ((a - (long long)a) * 100.001) % 10 << endl;
	return 0; 
}
