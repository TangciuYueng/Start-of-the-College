/*2151299 信16班 苏家铭*/
#include<iostream>
using namespace std;
int main()
{
	double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;

	cout << "请输入[0..100 亿)之间的数字:" << endl;
	cin >> a;
	b = a;
	c = int(b / 1000000000);
	d = int((b - c * 1000000000) / 100000000);
	e = int((b - c * 1000000000 - d * 100000000) / 10000000);
	f = int((b - c * 1000000000 - d * 100000000 - e * 10000000) / 1000000);
	g = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000) / 100000);
	i = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000) / 10000);
	j = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000 - i * 10000) / 1000);
	k = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000 - i * 10000 - j * 1000) / 100);
	l = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000 - i * 10000 - j * 1000 - k * 100) / 10);
	m = int((b - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000 - i * 10000 - j * 1000 - k * 100 - l * 10) / 1);
	h = a - c * 1000000000 - d * 100000000 - e * 10000000 - f * 1000000 - g * 100000 - i * 10000 - j * 1000 - k * 100 - l * 10-m*1;
	o = h * 100.001;
	n = int(o / 10);
	p = o - n * 10;

	cout << "十亿位 ： " << int(c) << endl;
	cout << "亿位   ： " << int(d) << endl;
	cout << "千万位 ： " << int(e) << endl;
	cout << "百万位 ： " << int(f) << endl;
	cout << "十万位 ： " << int(g) << endl;
	cout << "万位   ： " << int(i) << endl;
	cout << "千位   ： " << int(j) << endl;
	cout << "百位   ： " << int(k) << endl;
	cout << "十位   ： " << int(l) << endl;
	cout << "圆     ： " << int(m) << endl;
	cout << "角     ： " << int(n) << endl;
	cout << "分     ： " << int(p) << endl;

	return 0;
}