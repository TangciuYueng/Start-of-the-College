#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> 
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	int a,b1,s1,g1,b2,s2,g2,b3,s3,g3,count=0;
	for (a = 123456789; a <= 598764321; a++)//b1最大只能是5，否则b1<b2<b3就超了//improve 2
	{
		b1 = a / 100000000;
		s1 = a % 100000000 / 10000000;
		if (s1 == b1 || s1 == 0)//分解后就判断，不对就跳出，减少判断次数//improve3
			continue;
		g1 = a % 10000000 / 1000000;
		if (g1 == s1 || g1 == b1 || g1 == 0)
			continue;
		b2 = a % 1000000 / 100000;
		if (b2 == g1 || b2 == s1 || b2 == b1 || b2 == 0)
			continue;
		s2 = a % 100000 / 10000;
		if (s2 == b2 || s2 == g1 || s2 == s1 || s2 == b1|| s2 == 0)
			continue;
		g2 = a % 10000     / 1000;
		if ( g2 == s2 || g2 == b2 || g2 == g1 || g2 == s1 || g2 == b1||g2==0)
			continue;
		b3 = a % 1000      / 100;
		if ( b3 == g2 || b3 == s2 || b3 == b2 || b3 == g1 || b3 == s1 || b3 == b1||b3==0)
			continue;
		s3 = a % 100       / 10;
		if ( s3 == b3 || s3 == g2 || s3 == s2 || s3 == b2 || s3 == g1 || s3 == s1 || s3 == b1||s3==0)
			continue;
		g3 = a % 10;
		if (g3 == s3 || g3 == b3 || g3 == g2 || g3 == s2 || g3 == b2 || g3 == g1 || g3 == s1 || g3 ==b1||g3==0)
			continue;
		if ((b1 * 100 + s1 * 10 + g1) + (b2 * 100 + s2 * 10 + g2) + (b3 * 100 + s3 * 10 + g3) == 1953 &&
			(b1 * 100 + s1 * 10 + g1) < (b2 * 100 + s2 * 10 + g2) &&
			(b2 * 100 + s2 * 10 + g2) < (b3 * 100 + s3 * 10 + g3))
		{
			cout << b1 << s1 << g1 << "+"
				<< b2 << s2 << g2 << "+"
				<< b3 << s3 << g3 << "=1953" << endl;
			count++;
		}
	}
	cout <<count<< endl;

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}