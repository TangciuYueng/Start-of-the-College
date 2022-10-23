/* 2151298 信11 杨滕超 */
#include <iostream>
using namespace std;
int main()
{
	double s;
	double a,b,c,d,e,f,g,h,i,j,k,l,m;
	cout << "请输入找零值：" << endl;
	cin >> s;
	a = (int)(s / 50);
	b = (int)((s - a * 50) / 20);
	c = (int)((s - a * 50 - b * 20) / 10);
	d = (int)((s - a * 50 - b * 20 - c * 10) / 5);
	e = (int)((s - a * 50 - b * 20 - c * 10 - d * 5) / 1);
	f = s - a * 50 - b * 20 - c * 10 - d * 5 - e * 1;
	g = (int)(f * 100);
	h = (int)(g / 50);
	i = (int)((g - h * 50) / 10);
	j = (int)((g - h * 50 - i * 10) / 5);
	k = (int)((g - h * 50 - i * 10 - j * 5) / 2);
	l = (int)((g - h * 50 - i * 10 - j * 5 - k*2 ) / 1);
	m = a + b + c + d + e + h + i + j + k + l;
	cout << "共" << m << "张找零，具体如下：" << endl;
	if(a!=0)
	cout << "50元 ; " << a << "张" << endl;
	if(b!=0)
	cout << "20元 ; " << b << "张" << endl;
	if(c!=0)
	cout << "10元 ; " << c << "张" << endl;
	if(d!=0)
	cout << "5元  ; " << d << "张" << endl;
	if(e!=0)
	cout << "1元  ; " << e << "张" << endl;
	if(h!=0)
	cout << "5角  ; " << h << "张" << endl;
	if(i!=0)
	cout << "1角  ; " << i << "张" << endl;
	if(j!=0)
	cout << "5分  ; " << j << "张" << endl;
	if(k!=0)
	cout << "2分  ; " << k << "张" << endl;
	if(l!=0)
	cout << "1分  ; " << l << "张" << endl;
	return 0;
}