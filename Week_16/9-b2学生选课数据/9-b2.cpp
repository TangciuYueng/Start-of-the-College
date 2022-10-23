/* 2151298 ��11 ������ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�
class stu_list;//��ǰ����
#define MAX_NO_LEN        8
#define NUM               2
/*����ֵ��char��ָ��*/
char* tj_strcpy(char* s1, const char* s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	char* s10 = s1;
	if (s1 == NULL)
		return 0;
	else
	{
		if (s2 == NULL)//�Ÿ��յ��ڿ�ͷ
			*s1 = '\0';
		else
		{
			for (;; s2++, s1++)
			{
				*s1 = *s2;//��s1�ĵ�һ����ʼ��ֵ
				if (*s2 == '\0')
					break;
			}
		}
		s1 = s10;//s1��λ
		return s1;
	}
}

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no = 0;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	char no[MAX_NO_LEN];  //�ַ�ѧ��
	int turn[NUM] = { 0 };//�ִ�
	int z;//��¼��һ�����һ����λ��
	friend class stu_list;//��Ԫ
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	int i, j, sum = 0, k1;
	char ch;
	ifstream in;
	in.open(filename, ios::in);

	if (!in.is_open())//�򿪲��ɹ�
	{
		cout << "�ļ�[" << filename << "]��ʧ��" << endl;
		return -1;
	}
	else//�ļ��򿪳ɹ�
	{
		if (append == 0)//��һ��
		{
			for (i = 0; i < MAX_STU_NUM + 1; i++)
			{
				/*ѭ����ʼ�ַ�������β��*/
				for (j = 0; j < MAX_NO_LEN; j++)
				{
					stu[i].no[j] = '\0';
				}
				for (j = 0; j < MAX_NAME_LEN; j++)
				{
					stu[i].stu_name[j] = '\0';
				}
				/*����ѧ���ַ�*/
				for (j = 0; j < MAX_NO_LEN && in.peek() >= '0' && in.peek() <= '9'; j++)
				{
					stu[i].no[j] = in.get();
				}


				/*�����ո�س�*/
				while (1)
				{
					if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
						ch = in.get();
					else
						break;
				}

				//if (in.peek() == 13 || in.peek() == 10)//û��Ҫ��û�ж�������û�лس�
				//	continue;
				/*��ȡ����*/
				for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13&&in.peek()!=EOF; j++)
					stu[i].stu_name[j] = in.get();

				/*�����ո�س�*/
				while (1)
				{
					if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
						ch = in.get();
					else
						break;
				}
				/*ѧ���ַ�תΪint�ַ�*/
				stu[i].stu_no = 0;
				int k = 1000000;
				for (j = 0; stu[i].no[j] != '\0'; j++)
				{
					stu[i].stu_no += (stu[i].no[j] - '0') * k;
					k /= 10;
				}
				/*��ǵ�һ��*/
				stu[i].turn[0] = 1;
				stu[0].z = i;
				/*cout << stu[i].stu_no << " ";
				for (j = 0; j<MAX_NAME_LEN&&stu[i].stu_name[j] != '\0'; j++)
				{
					cout << stu[i].stu_name[j];
				}
				cout << endl;
				ch = _getch();*/
				/*�ļ�β����*/
				if (in.peek() == EOF)
					break;

			}//end of for i
		}//end of if append==1
		else//�ڶ���ѡ��
		{
			stu[0].z += 0;
			/*�ӵ�һ�ֵ����������Ŷ���*/
			for (i = stu[0].z+1; i < MAX_STU_NUM + 1; i++)
			{
				for (j = 0; j < MAX_NO_LEN; j++)
				{
					stu[i].no[j] = '\0';
				}
				for (j = 0; j < MAX_NAME_LEN; j++)
				{
					stu[i].stu_name[j] = '\0';
				}
				while (1)//ѭ������ѧ�ţ�ֱ����֮ǰ��ѧ�Ŷ���ͬ�˲�����
				{
					sum = 0;
					/*����ѧ���ַ�*/
					for (j = 0; j < MAX_NO_LEN && in.peek() >= '0' && in.peek() <= '9'; j++)
					{
						stu[i].no[j] = in.get();
					}
					/*ѧ���ַ�תΪint�ַ�*/
					stu[i].stu_no = 0;
					int k = 1000000;
					for (j = 0; stu[i].no[j] != '\0'; j++)
					{
						stu[i].stu_no += (stu[i].no[j] - '0') * k;
						k /= 10;
					}
					/*��ǰ���Ƿ�����ͬѧ�ŵ�*/
					for (k = 0; k <= stu[0].z; k++)
					{
						if (stu[k].stu_no == stu[i].stu_no)
						{
							k1 = k;//��¼������ѡ�ζ��е�ѧ��
							sum++;
						}
					}
					if (sum == 0)//��ǰ�涼��ͬ��
					{
						stu[i].turn[1] = 1;//�ڶ���ѡ���У�����ѭ����ȡ���������
						break;
					}
					else//����ͬ�ģ��Ѻ���Ķ�����֮���� ������ Ȼ������ѭ��������һ��
					{
						stu[k1].turn[1] = 1;//�ڶ���ѡ���У�ע����k1
						/*�����ո�س�*/
						while (1)
						{
							if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
								ch = in.get();
							else
								break;
						}
						/*��ȡ����*/
						for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13; j++)
							stu[i].stu_name[j] = in.get();
						/*�����ո�س�*/
						while (1)
						{
							if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
								ch = in.get();
							else
								break;
						}
						/*ѧ�ţ��������ָ�*/
						stu[i].stu_no = 0;
						for (j = 0; j < MAX_NO_LEN; j++)
						{
							stu[i].no[j] = '\0';
						}
						for (j = 0; j < MAX_NAME_LEN; j++)
						{
							stu[i].stu_name[j] = '\0';
						}
						if (in.peek() == EOF)
							break;
					}//end of else ����ֵͬ
					
				}//end of while 

				if (in.peek() == EOF)
					break;
				/*�����ո�س�*/
				while (1)
					{
						if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
							ch = in.get();
						else
							break;
					}
				/*��ȡ����*/
				for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13&&in.peek()!=EOF; j++)
					stu[i].stu_name[j] = in.get();
				/*�����ո�س�*/
				while (1)
					{
						if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
							ch = in.get();
						else
							break;
					}

				
				/*�ļ�β����*/
				if (in.peek() == EOF)
					break;
			}//end of for i
		}//end of else 

		in.close();
		return 0;
	}//end of else 
	
}
int stu_list::print(const char* prompt)
{
	int i = 0, j = 0, t = 0, k;
	char name[MAX_NAME_LEN] = { '\0' };
	int turn[NUM] = { 0 };
	for (i = 0; *(prompt + i) != '\0'; i++)
		cout << *(prompt + i);
	cout << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
	/*ѧ������*/
	for (i = 0; i < MAX_STU_NUM + 1; i++)
	{
		for (j = 0; j < MAX_STU_NUM - i && stu[j + 1].stu_no>0; j++)//ע�ⲻҪ�����õ�ǰ�棬�㶼�����/û��
		{
			if (stu[j].stu_no >stu[j + 1].stu_no)
			{
				t = stu[j].stu_no;
				stu[j].stu_no = stu[j + 1].stu_no;
				stu[j + 1].stu_no = t;

				tj_strcpy(name, stu[j].stu_name);
				tj_strcpy(stu[j].stu_name, stu[j +1].stu_name);
				tj_strcpy(stu[j +1].stu_name, name);

				for (k = 0; k < NUM; k++)
				{
					turn[k] = stu[j].turn[k];
					stu[j].turn[k] = stu[j +1].turn[k];
					stu[j + 1].turn[k] = turn[k];
				}

			}
		}
	}
	cout << setiosflags(ios::left);
	for (i = 0; i < MAX_STU_NUM + 1 && stu[i].stu_no != 0; i++)//ֻ���ѧ�Ų������
	{
		
		cout << setw(5) << i + 1;
		cout << setw(8) << stu[i].stu_no;
		cout << setw(33) << stu[i].stu_name;
		if (stu[i].turn[0] > 0 && stu[i].turn[1] > 0)
		{
			cout << setw(7) << 'Y';
			cout << 'Y';
		}
		else if (stu[i].turn[0] == 0 && stu[i].turn[1] > 0)
		{
			cout << setw(7) << "/";
			cout << "��ѡ";
		}
		else if (stu[i].turn[0] > 0 && stu[i].turn[1] == 0)
		{
			cout << setw(7) << 'Y';
			cout << "�˿�";
		}
		cout << endl;
		
	}
	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}