/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#define NUM 26
using namespace std;
struct KFC {
	char sym;
	char name[30];
	double money;
};
struct SPECIAL {
	const char zuhe[20];
	const char name[21];
	double money;
};
const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
	//	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};
int main()
{
	while(1)
	{
		system("cls");
		system("mode con cols=120 lines=35");
		cout << "=============================================================" << endl;
		cout << "                      KFC 2021�＾�˵�" << endl;
		cout << "=============================================================" << endl;
		int i, j, k = 0, q = 0, sum[NUM] = { 0 }, sum1[NUM] = { 0 };
		double  price = 0;
		char a[20];
		/*��ӡ�˵�*/
		for (i = 0; list[i].sym != '\0'; i++)
		{
			cout << setw(2) << setiosflags(ios::right) << list[i].sym << " ";
			cout << resetiosflags(ios::right);//����Ҷ���
			cout << setiosflags(ios::left) << setw(20) << list[i].name;
			cout << setiosflags(ios::left) << setw(7) << list[i].money;
			cout << resetiosflags(ios::left);//��������

			if (i % 2 == 0)
				cout << "|  ";
			else
				cout << endl;
		}


		cout << endl << "���Ż���Ϣ����" << endl;
		/*�Ż���Ϣ�������*/
		for (i = 0; special[i].money != 0; i++)
		{
			for (j = 0; j < NUM; j++)
				sum[j] = 0;
			/*����ʲô��ĸ*/
			for (j = 0; special[i].zuhe[j] != '\0'; j++)
			{
				if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
				{
					sum[special[i].zuhe[j] - 'A']++;//��Ӧ��ʮ������ĸλ���ж��ٸ�����ĸ
					if (sum[special[i].zuhe[j] - 'A'] > 1)
						a[j] = '9';//��ʾ�ظ�������
					else
						a[j] = special[i].zuhe[j];//a�����¼���������ʲô��ĸ
				}
			}
			a[j] = '\0';

			cout << special[i].name << "=";
			/*��ĸ��Ӧ������*/
			for (j = 0; ; j++)
			{
				if (a[j] >= 'A' && a[j] <= 'Z')
				{
					cout << list[a[j] - 'A'].name;
					if (sum[a[j] - 'A'] > 1)
						cout << "*" << sum[a[j] - 'A'];//ͨ��a�е���ĸ��Ӧsum�ж�Ӧ��ĸ�ĸ���
					cout << "+";
				}
				else if (a[j] == '9')//��ʾ��ǰ���й�����ĸ�ظ�
				{
					continue;
				}
				else
					break;
			}
			cout << '\b';//ȥ�����һ��+
			cout << "=" << special[i].money << endl;
		}

		cout << endl << "���������˵������" << endl;
		cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
		cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
		cout << endl << "��㵥: ";
		char str[NUM] = { '\0' };


		price = 0;
		cin.getline(str,NUM,'\n');
		if (str[0] == '0' && str[1] == '\0')//����
			break;
		else//����������
		{
			/*Сдת���ɴ�д��ĸ*/
			for (i = 0; i < NUM; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
			/*�ж����޷���ĸ�ַ�*/
			for (i = 0; i < NUM && str[i] != '\0'; i++)
			{
				if (str[i] < 'A' || str[i]>'Z')
				{
					k++;
					break;
				}
			}
			if (k)//�з���ĸ�ַ�
			{
				cout << "������󣬰����������." << endl;
			}
			else//���Ǵ�д��ĸ�ַ���
			{
				for (j = 0; j < NUM; j++)
					sum[j] = 0;
				/*��¼��Ӧ��ĸ�ж��ٸ�*/
				for (j = 0; j < NUM; j++)
					if (str[j] >= 'A' && str[j] <= 'Z')
						sum[str[j] - 'A']++;
				/*��ͽ��*/
				cout << "���ĵ��=";
				for (i = 0; list[i].money != 0; i++)
				{
					if (sum[i] != 0)
					{
						cout << list[i].name;
						if (sum[i] > 1)
							cout << "*" << sum[i];
						cout << "+";
					}
				}
				cout << '\b' << " ";//ȥ�����һ��+
				cout << endl << "���ƣ�";
				/*��Ǯ����*/
				for (i = 0; special[i].money != 0; )//ѭ���Żݷ���
				{
					/*sum1��q�ĳ�ʼ��*/
					for (j = 0; j < NUM; j++)
						sum1[j] = 0;
					q = 0;

					for (j = 0; special[i].zuhe[j] != '\0'; j++)//ѭ���Żݷ����е�ÿ����ĸ����sum1�����¼
					{
						if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
						{
							sum1[special[i].zuhe[j] - 'A']++;//��¼��Ӧ��ĸ��������¼�����ĸ�����ж�
							if (sum[special[i].zuhe[j] - 'A'] < sum1[special[i].zuhe[j] - 'A'])//��һ����ĸû�о�q���㣬���������Ż�
								q++;
						}
					}
					if (!q)//�����Żݣ�
					{
						price += special[i].money;
						for (j = 0; special[i].zuhe[j] != '\0'; j++)//ѭ���Żݷ����е�ÿ����ĸ
						{
							if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
								sum[special[i].zuhe[j] - 'A']--;//��ȥ�ײ�����Ķ���
						}
					}
					else//�������Żݣ�����һ���Ż������
						i++;
				}//end of for
				/*��ȥ�Ż�ʣ���Ǯ�ļ���*/
				for (i = 0; list[i].sym != '\0'; i++)
				{
					if (list[i].sym >= 'A' && list[i].sym <= 'Z')
					{
						price += list[i].money * sum[list[i].sym - 'A'];
					}
				}
				cout << price;
				cout << "Ԫ" << endl;
				cout << "�㵥��ɣ������������." << endl;
				

			}//end of A-Z part else
			char ch;
			ch = _getch();
		}//end of big else
	
	}//end of while

	return 0;
}
