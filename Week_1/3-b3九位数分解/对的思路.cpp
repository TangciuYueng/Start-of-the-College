#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	int b = (int)(a / 10);
	double sanweishu;
	int liangweishu;
	/*��ƴ�����ڱ�ʶ*/
	double shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	shiyi = (int)(a / 1000000000);
	yi = (int)(b) % 100000000 / 10000000;
	qianwan= (int)(b) % 10000000 / 1000000;
	baiwan= (int)(b) % 1000000 / 100000;
	shiwan= (int)(b) % 100000 / 10000;
	wan= (int)(b) % 10000 / 1000;
	qian= (int)(b) % 1000 / 100;
	bai= (int)(b) % 100 / 10;
	shi= (int)(b) % 10 / 1;
	sanweishu = a - shiyi * 1000000000 - yi * 100000000 - qianwan * 10000000 - baiwan * 1000000 - shiwan * 100000 - wan * 10000 - qian * 1000 - bai * 100 - shi * 10;
	yuan =(int)(sanweishu);
	liangweishu =(int)( (sanweishu - (int)(sanweishu)) * 100.001);
	jiao = (int)(liangweishu/10);
	fen = (int)(liangweishu % 10);
	cout << "ʮ��λ : " << shiyi << endl;
	cout << "��λ   : " << yi<< endl;
	cout << "ǧ��λ : " << qianwan<< endl;
	cout << "����λ : " << baiwan << endl;
	cout << "ʮ��λ : " << shiwan << endl;
	cout << "��λ   : " << wan<< endl;
	cout << "ǧλ   : " << qian<< endl;
	cout << "��λ   : " << bai << endl;
	cout << "ʮλ   : " << shi << endl;
	cout << "Ԫ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;
	return 0;
}