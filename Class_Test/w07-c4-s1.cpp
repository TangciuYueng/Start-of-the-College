/* 2151298 ��11 ������*/
#include <iostream>
using namespace std;


int main()
{
	int a, b, c, d;
	int x, y, z, w;
	cout << "�������ĸ�����" << endl;
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
		cout << "��С���������� : " << x << " " << y << " " << z << " " << w << endl;
	else if(w<x)
		cout<< "��С���������� : " << z << " " << w << " " << x << " " << y << endl;
	else if(x<z&&w<y)
		cout<< "��С���������� : " <<x << " " <<z << " " << w << " " << y << endl;
	else if(z<x&&y<w)
		cout<<"��С���������� : " << z << " " << x << " " << y << " " << z << endl;
	else if(x<z&&y<w)
		cout << "��С���������� : " << x << " " << z << " " << y << " " << w << endl;
	else if(z<x&&w<y)
		cout<< "��С���������� : " << z << " " << x << " " << w << " " << y << endl;
	return 0;

}