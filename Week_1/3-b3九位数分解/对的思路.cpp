#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	int b = (int)(a / 10);
	double sanweishu;
	int liangweishu;
	/*用拼音易于辨识*/
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
	cout << "十亿位 : " << shiyi << endl;
	cout << "亿位   : " << yi<< endl;
	cout << "千万位 : " << qianwan<< endl;
	cout << "百万位 : " << baiwan << endl;
	cout << "十万位 : " << shiwan << endl;
	cout << "万位   : " << wan<< endl;
	cout << "千位   : " << qian<< endl;
	cout << "百位   : " << bai << endl;
	cout << "十位   : " << shi << endl;
	cout << "元     : " << yuan << endl;
	cout << "角     : " << jiao << endl;
	cout << "分     : " << fen << endl;
	return 0;
}