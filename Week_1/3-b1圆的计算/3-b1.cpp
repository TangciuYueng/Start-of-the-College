/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double r, h;
	const double pi = 3.14159;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed);//Ϊ������С������λ��
	cout << "Բ�ܳ�     : " << setprecision(2) << pi * 2 * r << endl;
	cout << "Բ���     : " << setprecision(2) << pi * r * r << endl;
	cout << "Բ������ : " << setprecision(2) << pi * 4 * r * r << endl;
	cout << "Բ�����   : " << setprecision(2) << pi * 4 * r * r * r / 3 << endl;
	cout << "Բ�����   : " << setprecision(2) << pi * r * r * h << endl;
	return 0;
}
