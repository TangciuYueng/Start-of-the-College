/* 2151298 信11 杨滕超*/
#include <iostream>
using namespace std;


int main()
{
	int a, b, c, d;
	int x, y, z, w;
	cout << "请输入四个整数" << endl;
	cin >> a >> b >> c >> d;
	if (a < b) {//x<y
		x = a;
		y = b;
	}
		
	else {
		x = b;
		y = a;

	}
	if (c < d) {//z<w
		z = c;
		w = d;
	}
	else {
		z = d;
		w = c;
	}
	if (y < z)
		cout << "从小到大依次是 : " << x << " " << y << " " << z << " " << w << endl;
	else if(w<x)
		cout<< "从小到大依次是 : " << z << " " << w << " " << x << " " << y << endl;
	else if(x<z&&w<y)
		cout<< "从小到大依次是 : " <<x << " " <<z << " " << w << " " << y << endl;
	else if(z<x&&y<w)
		cout<<"从小到大依次是 : " << z << " " << x << " " << y << " " << z << endl;
	else if(x<z&&y<w)
		cout << "从小到大依次是 : " << x << " " << z << " " << y << " " << w << endl;
	else if(z<x&&w<y)
		cout<< "从小到大依次是 : " << z << " " << x << " " << w << " " << y << endl;
	return 0;

}