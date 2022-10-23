/* 2151298 信11 杨滕超 */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
int main()
{
	int a, b, c, i, j, sum;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> a>>b;   
		while (cin.fail() || a < 2000 || a>2030 || b < 1 || b>12)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入年份(2000-2030)和月份(1-12) : ";
			cin >> a >> b;
		}
		if (a >= 2000 && a <= 2030 && b <= 12 && b >= 1)
			break;
	}
	while (1) {
		cout << "请输入" << a << "年" << b << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> c;
		while (cin.fail() || c < 0 || c>6) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入" << a << "年" << b << "月" << c << "日的星期(0-6表示星期日-星期六) : ";
			cin >> c;
		}
		if (c >= 0 && c <= 6)
			break;
	}
	cout << endl;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			i = 31;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 4 || b == 6 || b == 9 || b == 11)
			i = 30;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		if (b == 2)
			i = 29;//闰年的
	
	
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			i = 31;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 4 || b == 6 || b == 9 || b == 11)
			i = 30;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 2)
			i = 28;//平年的
	j = 2;//日期从2号开始

	cout << a << "年" << b << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	/*选择不同星期的空格*/
	if (c == 0) {
        cout << setw(4) <<"1";
		sum = 1;
	}  
	else if (c == 1) {
        cout << setw(12) << "1";
		sum = 2;
	}	
	else if (c == 2) {
		cout << setw(20) << "1";
		sum = 3;
	}
	else if (c == 3) {
		cout << setw(28) << "1";
		sum = 4;
	}
	else if (c == 4) {
		cout << setw(36) << "1";
		sum = 5;
	}
	else if (c == 5) {
		cout << setw(44) << "1";
		sum = 6;
	}
	else {
		cout << setw(52) << "1";
		sum = 7;
	}

	while (j <= i) {
		if (sum % 7 == 0) {//每行最后一个输出回车
			cout << endl;
			cout << setw(4) << j;//到了第一列开头是宽度为4
		}
		else
		    cout << setw(8) << j;//其余列宽度为8
		
		sum = sum + 1;
		j++;
	}
	return 0;
}