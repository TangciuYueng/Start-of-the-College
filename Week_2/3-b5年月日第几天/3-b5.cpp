/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "请输入年，月，日" << endl;
	cin >> a >> b >> c;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
		if (b >= 1 && b <= 12) {
			switch (b){
				case 1:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 2:
					if (c >= 1 && c <= 29)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 3:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 4:
					if (c >= 1 && c <= 30)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 +31+ c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 5:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" <<31+29+31+30+c<< "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 6:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + c<< "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 7:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31+30+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 8:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + 30 + 31+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 9:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 10:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + 30 + 31 +31+30+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 11:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 12:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30+c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
					
			}
		}
		else 
			cout << "输入错误-月份不正确" << endl;
	}
	else {
		if (b >= 1 && b <= 12) {
			switch (b) {
				case 1:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 2:
					if (c >= 1 && c <= 28)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 3:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 4:
					if (c >= 1 && c <= 30)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 5:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 6:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 7:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 8:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 9:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 10:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 11:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 12:
					if (c >= 1 && c <= 31)
						cout << a << "-" << b << "-" << c << "是" << a << "年的第" << 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c << "天" << endl;
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
			}
		}
		else
			cout<< "输入错误-月份不正确" << endl;
	}

	return 0;
}