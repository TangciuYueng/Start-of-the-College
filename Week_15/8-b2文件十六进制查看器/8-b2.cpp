/* 2151298 ��11 ������ */
#include <iostream>
#include <fstream>
#include <iomanip>
#define N 80
#define M 16
#define MID 7
using namespace std;
int main()
{
	char fname[N] = { '\0' }, a[M+1] = { '\0' },ch;
	int i = 0, j = 0, k;
	clog << "�ļ���������ʽ������:" << endl;
	clog << "    a.txt                    : ����·����ʽ" << endl;
	clog << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	clog << "�������ļ��� : ";
	cin >> fname;
	ifstream in;
	in.open(fname, ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "�����ļ�" << fname << "��ʧ�ܣ�" << endl;
		return -1;
	}
	else
	{
		while (1)
		{
			if (in.peek() == EOF)
				break;
			k = 0;//��¼�������k��ʼ��
			/*�����ʼ��*/
			for (i = 0; i < M; i++)
				a[i] = '\0';

			/*��������飬������eof�Ͳ����룬���涼��\*/
			for (i = 0; i < M; i++)
			{
				if (in.peek() == EOF)//һ��ʮ���������ļ�����ֹͣ����
					break;
				a[i] = in.get();
				k++;//��¼һ���ж��ٸ��ַ�
			}
			
			/*���λ��*/
			cout << setw(MID) << setfill('0') << hex << j << "0 ";
	
			/*��������k���ַ���ʮ������*/
			for (i = 0; i < k; i++)
			{
				if (a[i] < 0)//������
					a[i] += 256;
				cout << setfill(' ');//��ԭ�����0������ո�
				if ((int)(unsigned char)a[i] >= 16)//ʮ��������λ��
					cout << setw(3) << setiosflags(ios::right) << hex << (int)(unsigned char)a[i];
				else if ((int)(unsigned char)a[i] < 16)
					cout << setw(2) << setiosflags(ios::right) << '0' << hex << (int)(unsigned char)a[i];
				if (k >= M / 2 + 1 && i == M / 2 - 1)//�ɰ˸����ϵ������и�
					cout << " -";
			}
			/*�����λ*/
			for (i = k; i < M; i++)//����û������Ŀ�λ
			{
				cout << "   ";
			}
			if (k < M / 2 + 1)//��û������Ĵ��ڰ˸������Ŀ�λ���и�
				cout << "  ";

			cout << "     ";//����ո�
			for (i = 0; i < k; i++)
			{
				if ((int)a[i] >= 33 && (int)a[i] <= 126)
					cout << a[i];
				else
					cout << '.';
			}
			cout << endl;
			
			if (in.peek() == EOF)
				break;
				
			j++;
		}
	}
	in.close();
	return 0;
}