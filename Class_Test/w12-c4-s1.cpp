/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
int convert(int n,int digit)
{
	static int sum=0;
	if (n < 10 && n >0)
	{
		if (n == digit)
			sum++;
	}
	else if (n >= 10)
	{
		convert(n / 10,digit);
		if (n % 10 == digit)
			sum++;
	}
	return sum;
}
int main()
{
	int a[10000], i = 0, num, digit, sum=0;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> num;
	cout << "������" << num << "��������" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> a[i];
	}
	cout << "����������[0..9]" << endl;
	cin >> digit;
	for (i = 0; i < num; i++)
	{
		sum = convert(a[i], digit);
	}

	cout << num << "�����к���" << digit << "�ĸ��� : " << sum << endl;
	return 0;
}