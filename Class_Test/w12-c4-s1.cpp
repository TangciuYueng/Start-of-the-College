/* 2151298 信11 杨滕超 */
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
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> num;
	cout << "请输入" << num << "个正整数" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> a[i];
	}
	cout << "请输入数码[0..9]" << endl;
	cin >> digit;
	for (i = 0; i < num; i++)
	{
		sum = convert(a[i], digit);
	}

	cout << num << "个数中含有" << digit << "的个数 : " << sum << endl;
	return 0;
}