/* 2151298 ��11 ������ */
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int x;
	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		while (cin.fail())//Ҳ�����ã�cin������ʱ����false��)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(),'\n');
			cout << "������x��ֵ[0-100] : ";
			cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //�˾䲻׼��������Ҫ�����ʱgoodΪ1
	return 0;
}
