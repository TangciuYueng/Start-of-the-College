/* 2151298 ��11 ������ */
#include <iostream>
#include <cstring>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */


/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
				result = result + chnstr[num * 2] + chnstr[num * 2 + 1];//����һ�������ֽ�
			/*����result = chnstr[num * 2] + chnstr[num * 2 + 1] �����ȼ����ǣ���ִ�е�������ASCII��ӣ�֮���ٸ�ֵ���Ͳ�����*/
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
			break;
		default:
			cout<<"error"<<endl;
			break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	double number;
	int a, b, c, d, e, f, g, h, i, j, l, m;
	double k;//ע��k��С�����֣���Ҫ������ 
	int flag = 0;
	const char shi[] = "ʰ";
	const char bai[] = "��";
	const char qian[] = "Ǫ";
	const char wan[] = "��";
	const char yi[] = "��";
	const char yuan[] = "Բ";
	const char jiao[] = "��";
	const char fen[] = "��";
	const char zheng[] = "��";
	cout << "������[0-100��)֮�������:" << endl;
	cin >> number;
	a = (int)(number / 1000000000);
	b = (int)((number - (double)a * 1000000000) / 100000000);
	c = (int)((number - (double)a * 1000000000 - (double)b * 100000000) / 10000000);
	d = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000) / 1000000);
	e = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000) / 100000);
	f = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000) / 10000);
	g = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000) / 1000);
	h = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000) / 100);
	i = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100) / 10);
	j = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100 - (double)i * 10) / 1);
	k = (number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100 - (double)i * 10 - (double)j * 1);
	l = (int)(k * 100.001 / 10);
	m = (int)(k * 100.001 - (double)l * 10);
	daxie(a, 0);//�ڼ���
	if (a != 0)
		result += shi;
	daxie(b, 0);
	if (b || a)
		result += yi;

	//�򼶱�
	if ((b || a) && (d || e || f))
		flag = 1;
	else
		flag = 0;
	daxie(c, flag);
	if (c != 0)
		result += qian;


	if (c && (e || f) && flag == 0)//ǰ��������һ���������Һ�����һ��������
		flag = 1;
	else
		flag = 0;
	daxie(d, flag);
	if (d != 0)
		result += bai;

	if ((c || d) && f && flag == 0)
		flag = 1;
	else
		flag = 0;
	daxie(e, flag);
	if (e != 0)
		result += shi;


	daxie(f, 0);
	if (f || e || d || c)
		result += wan;

	flag = 0;
	//Բ����
	if ((b || a || c || d || e || f) && (h || i || j))
		flag = 1;
	else
		flag = 0;
	daxie(g, flag);
	if (g != 0)
		result += qian;

	if (g && (i || j) && flag == 0)//ǰ��������һ���������Һ�����һ��������
		flag = 1;
	else
		flag = 0;
	daxie(h, flag);
	if (h != 0)
		result += bai;

	if ((g || h) && j && flag == 0)
		flag = 1;
	else
		flag = 0;
	daxie(i, flag);

	if (i != 0)
		result += shi;

	if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !l && !m)
		flag = 1;

	daxie(j, flag);
	//�ж�Բ�������ȫ��������or����λ�ж���
	if (a || b || c || d || e || f || g || h || i || j)
		result += yuan;

	else if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !l && !m)
		result += yuan;
	//С������
	flag = 0;
	if (m && (a || b || c || d || e || f || g || h || i || j))//ǰ���ж������������һ����
		flag = 1;
	daxie(l, flag);
	if (l != 0)
		result += jiao;


	daxie(m, 0);//�ֵ�����㶼��������� 
	if (m != 0)
		result += fen;


	if (m == 0)
		result += zheng;
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}