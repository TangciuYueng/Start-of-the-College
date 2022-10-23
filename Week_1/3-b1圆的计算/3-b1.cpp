/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double r, h;
	const double pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed);//为了设置小数点后的位数
	cout << "圆周长     : " << setprecision(2) << pi * 2 * r << endl;
	cout << "圆面积     : " << setprecision(2) << pi * r * r << endl;
	cout << "圆球表面积 : " << setprecision(2) << pi * 4 * r * r << endl;
	cout << "圆球体积   : " << setprecision(2) << pi * 4 * r * r * r / 3 << endl;
	cout << "圆柱体积   : " << setprecision(2) << pi * r * r * h << endl;
	return 0;
}
