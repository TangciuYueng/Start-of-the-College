#include <iostream>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	/*��ƴ���������ֱ�ʶ*/
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
	cout << "ʮ��λ : " << shiyi << endl;
	cout << "��λ   : " << yi << endl;
	cout << "ǧ��λ : " << qianwan << endl;
	cout << "����λ : " << baiwan << endl;
	cout << "ʮ��λ : " << shiwan << endl;
	cout << "��λ   : " << wan << endl;
	cout << "ǧλ   : " << qian << endl;
	cout << "��λ   : " << bai << endl;
	cout << "ʮλ   : " << shi << endl;
	cout << "Ԫ     : " << yuan << endl;
	cout << "��     : " << jiao << endl;
	cout << "��     : " << fen << endl;//�ֽ⸡�������ǲ��ԡ�����
	/*ǰ��������һ��λ�����㡣���Һ�����Ϊ����Ϊ�㣬��Ȼ����㽻������һ����*/
	if (qianwan == 1)
		cout << "ҼǪ";
	else if (qianwan == 2)
		cout << "��Ǫ";
	else if (qianwan == 3)
		cout << "��Ǫ";
	else if (qianwan == 4)
		cout << "��Ǫ";
	else if (qianwan == 5)
		cout << "��Ǫ";
	else if (qianwan == 6)
		cout << "½Ǫ";
	else if (qianwan == 7)
		cout << "��Ǫ";
	else if (qianwan == 8)
		cout << "��Ǫ";
	else if (qianwan == 9)
		cout << "��Ǫ";
	else if (shiyi + yi > 0 && baiwan > 0)//��a+b>0�ķ�ʽ�ж��Ƿ�Ϊ�㣡�� 
	    cout << "��";
	
	if (baiwan == 1)
		cout << "Ҽ��";
	else if (baiwan == 2)
		cout << "����";
	else if (baiwan == 3)
		cout << "����";
	else if (baiwan == 4)
		cout << "����";
	else if (baiwan == 5)
		cout << "���";
	else if (baiwan == 6)
		cout << "½��";
	else if (baiwan == 7)
		cout << "���";
	else if (baiwan == 8)
		cout << "�ư�";
	else if (baiwan == 9)
		cout << "����";
	else if (shiyi + yi + qianwan> 0 && shiwan > 0)
		cout << "��";

	if (shiwan == 1)
		cout << "Ҽʰ";
	else if (shiwan == 2)
		cout << "��ʰ";
	else if (shiwan == 3)
		cout << "��ʰ";
	else if (shiwan == 4)
		cout << "��ʰ";
	else if (shiwan == 5)
		cout << "��ʰ";
	else if (shiwan == 6)
		cout << "½ʰ";
	else if (shiwan == 7)
		cout << "��ʰ";
	else if (shiwan == 8)
		cout << "��ʰ";
	else if (shiwan == 9)
		cout << "��ʰ";
	else if (shiyi + yi + qianwan+baiwan > 0 && wan > 0)
		cout << "��";

	if (wan == 1)
		cout << "Ҽ��";
	else if (wan == 2)
		cout << "����";
	else if (wan == 3)
		cout << "����";
	else if (wan == 4)
		cout << "����";
	else if (wan == 5)
		cout << "����";
	else if (wan == 6)
		cout << "½��";
	else if (wan == 7)
		cout << "����";
	else if (wan == 8)
		cout << "����";
	else if (wan == 9)
		cout << "����";
	else if (shiyi + yi + qianwan + baiwan +shiwan> 0 && qian > 0)
		cout << "��";
	return 0;
}
