/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
int main()
{
	double s;
	double a,b,c,d,e,f,g,h,i,j,k,l,m;
	cout << "����������ֵ��" << endl;
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
	cout << "��" << m << "�����㣬�������£�" << endl;
	if(a!=0)
	cout << "50Ԫ ; " << a << "��" << endl;
	if(b!=0)
	cout << "20Ԫ ; " << b << "��" << endl;
	if(c!=0)
	cout << "10Ԫ ; " << c << "��" << endl;
	if(d!=0)
	cout << "5Ԫ  ; " << d << "��" << endl;
	if(e!=0)
	cout << "1Ԫ  ; " << e << "��" << endl;
	if(h!=0)
	cout << "5��  ; " << h << "��" << endl;
	if(i!=0)
	cout << "1��  ; " << i << "��" << endl;
	if(j!=0)
	cout << "5��  ; " << j << "��" << endl;
	if(k!=0)
	cout << "2��  ; " << k << "��" << endl;
	if(l!=0)
	cout << "1��  ; " << l << "��" << endl;
	return 0;
}