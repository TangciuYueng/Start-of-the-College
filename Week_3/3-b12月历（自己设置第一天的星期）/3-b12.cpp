/* 2151298 ��11 ������ */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
int main()
{
	int a, b, c, i, j, sum;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> a>>b;   
		while (cin.fail() || a < 2000 || a>2030 || b < 1 || b>12)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			cout << "���������(2000-2030)���·�(1-12) : ";
			cin >> a >> b;
		}
		if (a >= 2000 && a <= 2030 && b <= 12 && b >= 1)
			break;
	}
	while (1) {
		cout << "������" << a << "��" << b << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> c;
		while (cin.fail() || c < 0 || c>6) {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			cout << "������" << a << "��" << b << "��" << c << "�յ�����(0-6��ʾ������-������) : ";
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
			i = 29;//�����
	
	
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
			i = 31;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 4 || b == 6 || b == 9 || b == 11)
			i = 30;
	if (!(a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
		if (b == 2)
			i = 28;//ƽ���
	j = 2;//���ڴ�2�ſ�ʼ

	cout << a << "��" << b << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	/*ѡ��ͬ���ڵĿո�*/
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
		if (sum % 7 == 0) {//ÿ�����һ������س�
			cout << endl;
			cout << setw(4) << j;//���˵�һ�п�ͷ�ǿ��Ϊ4
		}
		else
		    cout << setw(8) << j;//�����п��Ϊ8
		
		sum = sum + 1;
		j++;
	}
	return 0;
}