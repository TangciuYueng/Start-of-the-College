/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;
#define M 10
#define N 17
static const char other[] = "~!@#$%^&*()-_=+[],.?";
int main()
{
	int i, j, k, len, daxie, xiaoxie, shuzi, qita, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, have = 0;
	char key[M][N] = { '\0' }, firstline[100] = {'\0'},ch;
	cin.getline(firstline,100,'\n');//��ȡ��һ����98���ַ�

	//��ȡ���ȣ���д��Сд�����֣����� �������
	cin >>len>>daxie>>xiaoxie>>shuzi>>qita;

	cin.get(ch);//��qita����Ļس�����

	for (i = 0; i < M; i++)
		cin.getline(key[i], N, '\n');//��������ʮ�����ַ���β����س�
	/*����Ĳ����Ƿ���ȷ*/
	if (len < 12 || len>16 || daxie < 2 || daxie >= len || xiaoxie < 2 || xiaoxie >= len || shuzi < 2 || shuzi >= len || qita < 2 || qita >= len)
		sum++;
	/*�Ƚϳ���*/
	for(i=0;i<M;i++)
	{
		if (len != strlen(key[i]))
			sum++;
	}
	/*sum1��Ӧ��д��sum2��ӦСд��sum3��Ӧ���֣�sum4��Ӧ����
	�����Ƿ����㲻С�ڶ�Ӧ��Ҫ��*/
	for (i = 0; i < M; i++)
	{
		/*�ǵ�ÿһ������Ƚ���֮���Ӧ��sum��ԭ*/
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		sum4 = 0;
		have = 0;
		for (j = 0; j < len; j++)
		{
			if (key[i][j] >= 'A' && key[i][j] <= 'Z')
				sum1++;
			else if (key[i][j] >= 'a' && key[i][j] <= 'z')
				sum2++;
			else if (key[i][j] >= '0' && key[i][j] <= '9')
				sum3++;
			else//�����Ƿ��зǷ��ַ��������ַ���������other�еıȽϣ�������ͬ���ǷǷ���have=0�ͷǷ���
			{
				for (k = 0; k < 20; k++)
				{
					if (key[i][j] == other[k])
						have++;
				}
				if (have == 0 || key[i][j] < 0)//����ascii�ֽ����Ϊ����
					sum++;
			}
		}
		sum4 = strlen(key[i]) - sum1 - sum2 - sum3;
		if (sum1 < daxie || sum2 < xiaoxie || sum3 < shuzi || sum4 < qita)
			sum++;
	}

	if (sum)
		cout << "����" << endl;
	else
		cout << "��ȷ" << endl;
	return 0;
}