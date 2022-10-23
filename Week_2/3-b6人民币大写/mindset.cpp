#include <iostream>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	/*用拼音易于区分辨识*/
	double shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	shiyi = (int)a / 1000000000;
	yi = (int)a / 100000000 % 10;
	qianwan = (int)a / 10000000 % 10;
	baiwan = (int)a / 1000000 % 10;
	shiwan = (int)a / 100000 % 10;
	wan = (int)a / 10000 % 10;
	qian = (int)a / 1000 % 10;
	bai = (int)a / 100 % 10;
	shi = (int)a / 10 % 10;
	yuan = (int)a % 10;
	jiao = (int)((a - (int)a) * 100.001 / 10);
	fen = (int)((a - (int)a) * 100.001) % 10;
	cout << "十亿位 : " << shiyi << endl;
	cout << "亿位   : " << yi << endl;
	cout << "千万位 : " << qianwan << endl;
	cout << "百万位 : " << baiwan << endl;
	cout << "十万位 : " << shiwan << endl;
	cout << "万位   : " << wan << endl;
	cout << "千位   : " << qian << endl;
	cout << "百位   : " << bai << endl;
	cout << "十位   : " << shi << endl;
	cout << "元     : " << yuan << endl;
	cout << "角     : " << jiao << endl;
	cout << "分     : " << fen << endl;//分解浮点数还是不对、、、
	/*前面至少有一个位数非零。并且后面以为不能为零，不然输出零交给后面一个零*/
	if (qianwan == 1)
		cout << "壹仟";
	else if (qianwan == 2)
		cout << "贰仟";
	else if (qianwan == 3)
		cout << "叁仟";
	else if (qianwan == 4)
		cout << "肆仟";
	else if (qianwan == 5)
		cout << "伍仟";
	else if (qianwan == 6)
		cout << "陆仟";
	else if (qianwan == 7)
		cout << "柒仟";
	else if (qianwan == 8)
		cout << "捌仟";
	else if (qianwan == 9)
		cout << "玖仟";
	else if (shiyi + yi > 0 && baiwan > 0)//用a+b>0的方式判断是否都为零！！ 
	    cout << "零";
	
	if (baiwan == 1)
		cout << "壹佰";
	else if (baiwan == 2)
		cout << "贰佰";
	else if (baiwan == 3)
		cout << "叁佰";
	else if (baiwan == 4)
		cout << "肆佰";
	else if (baiwan == 5)
		cout << "伍佰";
	else if (baiwan == 6)
		cout << "陆佰";
	else if (baiwan == 7)
		cout << "柒佰";
	else if (baiwan == 8)
		cout << "捌佰";
	else if (baiwan == 9)
		cout << "玖佰";
	else if (shiyi + yi + qianwan> 0 && shiwan > 0)
		cout << "零";

	if (shiwan == 1)
		cout << "壹拾";
	else if (shiwan == 2)
		cout << "贰拾";
	else if (shiwan == 3)
		cout << "叁拾";
	else if (shiwan == 4)
		cout << "肆拾";
	else if (shiwan == 5)
		cout << "伍拾";
	else if (shiwan == 6)
		cout << "陆拾";
	else if (shiwan == 7)
		cout << "柒拾";
	else if (shiwan == 8)
		cout << "捌拾";
	else if (shiwan == 9)
		cout << "玖拾";
	else if (shiyi + yi + qianwan+baiwan > 0 && wan > 0)
		cout << "零";

	if (wan == 1)
		cout << "壹万";
	else if (wan == 2)
		cout << "贰万";
	else if (wan == 3)
		cout << "叁万";
	else if (wan == 4)
		cout << "肆万";
	else if (wan == 5)
		cout << "伍万";
	else if (wan == 6)
		cout << "陆万";
	else if (wan == 7)
		cout << "柒万";
	else if (wan == 8)
		cout << "捌万";
	else if (wan == 9)
		cout << "玖万";
	else if (shiyi + yi + qianwan + baiwan +shiwan> 0 && qian > 0)
		cout << "零";
	return 0;
}
