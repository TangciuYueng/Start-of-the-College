/* 2151298 信11 杨滕超 */
#include <iostream>
#include <cmath>//Dev需要的头文件
#include <iomanip>
using namespace std;
int main()
{
	int a, b, c;
	const double pi = 3.14159;
	double s;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;
	s =(double) a * b * sin((double)c * 2 * pi / 360) / 2;
	cout << "三角形的面积为 : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
	return 0;
}