/* 2151298 信11 杨滕超 */
#include <iostream>
#include <limits> 
using namespace std;
int zeller(int y, int m, int d);

int zeller(int y, int m, int d)
{
	int w=0,c=0;
	if (m >= 3) {
		c = y/100;
	    y = y - c * 100;//y = y % 100也是可以的 
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	}
	if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;//y = y % 100也是可以的 
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m+12 + 1) / 5 + d - 1;
	}
	/*将上面两个东西合起来，正常情况中间加个
	if(m == 1 || m == 2) 
	{
	m += 12;
	y --;
    }
	*/ 
	if (w >= 0)
		w = w % 7;
	else {
		while (w < 0) {//若w算出来负数，则一直加7直到正数为止 
			w = w + 7;
		}
		w = w % 7;
	}
	/*也可以采用
	w=(w%7+7)%7      负数%7是-1到-6，再+7即可*/

	return w;
}
int main()
{
	int y, m, d,w;

	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日："<<endl;
			cin >> y >> m >>d;
		}//not int 
		
		if(y||m||d){
			while ( y < 1900 || y>2100 )
		    {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "年份不正确，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月、日："<<endl;
			cin >> y >> m >>d;
		    }//year wrong
		if (y >= 1900 && y <= 2100) {
			while ( m < 1 || m>12)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
				cout << "月份不正确，请重新输入" << endl;
				cout << "请输入年[1900-2100]、月、日："<<endl;
				cin >> y >> m >> d;
			}//month wrong

			if (m >= 1 && m <= 12) {
				if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
						while ( d < 1 || d>31)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 31)
							break;
					}

					if (m == 2) {
						while ( d < 1 || d>29)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 29)
							break;
					}

					if (m == 4 || m == 6 || m == 9 || m == 11) {
						while ( d < 1 || d>30)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 30)
							break;
					}
				}//big year

				if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) {
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
						while ( d < 1 || d>31)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 31)
							break;
					}

					if (m == 2) {
						while ( d < 1 || d>28)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 28)
							break;
					}

					if (m == 4 || m == 6 || m == 9 || m == 11) {
						while ( d < 1 || d>30)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "日不正确，请重新输入" << endl;
							cout << "请输入年[1900-2100]、月、日："<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 30)
							break;
					}
				}//small year
			}//month wrong
		}//year right
			
		}
	
			
	}//最大循环


	w=zeller(y, m, d);
	
	if (w == 0)
		cout << "星期日" << endl;
	if (w == 1)
		cout << "星期一" << endl;
	if (w == 2)
		cout << "星期二" << endl;
	if (w == 3)
		cout << "星期三" << endl;
	if (w == 4)
		cout << "星期四" << endl;
	if (w == 5)
		cout << "星期五" << endl;
	if (w == 6)
		cout << "星期六" << endl;
	return 0;
}
