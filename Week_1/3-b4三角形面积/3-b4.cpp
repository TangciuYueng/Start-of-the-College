/* 2151298 ��11 ������ */
#include <iostream>
#include <cmath>//Dev��Ҫ��ͷ�ļ�
#include <iomanip>
using namespace std;
int main()
{
	int a, b, c;
	const double pi = 3.14159;
	double s;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;
	s =(double) a * b * sin((double)c * 2 * pi / 360) / 2;
	cout << "�����ε����Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
	return 0;
}