/* 2151298 ��11 ������  */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3��������������������
   ---------------------------------------------------------------------
*/

#define SN	10	//student_num
#define CN	3	//course_num

struct student {
	int   no;        //ѧ�ţ���Ȼ��int�����������˴������ǣ�
	char  name[9];   //���������4������
	float score[CN]; //�����CN�ſεĳɼ�
	float fen;             //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ����������Ҫ��ɾ������
};

struct course {
	float max;    //ĳ�ſγ̵���߳ɼ�
	float min;    //ĳ�ſγ̵���ͳɼ�
	float avg;    //ĳ�ſγ̵�ƽ���ɼ�
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����snum��ѧ���Ļ�����Ϣ��cnum�ſεĳɼ�
  ���������
  �� �� ֵ��
  ˵    �������������ֺ궨��SN��CN��10��3
 ***************************************************************************/
void input(struct student* stu, int snum, int cnum)
{
	/* �����������ͱ����⣬�������������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;
	for (i = 0; i < snum; i++)
	{
		cout << "�������" << setw(2) << setiosflags(ios::right) << i + 1 << "��ѧ������Ϣ : ";
		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < cnum; j++)
		{
			cin >> stu[i].score[j];
		}
	}
	cout << endl;
	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�ͳ��cnum�ſε���ߡ���͡�ƽ���ɼ���snum��ѧ����
  ���������
  �� �� ֵ��
  ˵    �������������ֺ궨��SN��CN��10��3
 ***************************************************************************/
void process(struct student* stu, int snum, struct course* cno, int cnum)
{
	/* �����������ͱ����⣬�������������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	int i, j;
	for (i = 0; i < cnum; i++)//��i�ſ�
	{
		cno[i].avg = 0;
		j = 0;
		cno[i].max = stu[j].score[i];
		cno[i].min = stu[j].score[i];
		for (j = 0; j < snum; j++)//��j��ѧ��
		{
			cno[i].avg += stu[j].score[i];//ÿ������������
			if (j > 0)//�ӵڶ�����ʼ
			{
				if(stu[j].score[i]> cno[i].max)//�б�max����ĸ�ֵ��max
					cno[i].max = stu[j].score[i];
				else if(stu[j].score[i] < cno[i].min)
					cno[i].min = stu[j].score[i];
			}
		}
		cno[i].avg /= snum;//��ƽ��
	}
	/* ������ʵ�ֲ��� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����snum��ѧ���Ļ�����Ϣ��ƽ���ɼ�
  ���������
  �� �� ֵ��
  ˵    �������������ֺ궨��SN��CN��10��3
 ***************************************************************************/
void output_student(struct student* stu, int snum, int cnum)
{
	/* ��������ָ������⣬�������������������κ���ʽ�ı���
		 ������ã�����ɾ�������������ӻ��滻Ϊ������ʽ�ı���
		����for(int i=0; )��ʽ���±�������ͬ����ֹ */
	struct student* p;
	float* s;
	cout << snum << "��ѧ���ĳɼ�Ϊ" << endl;
	cout << "��� ѧ��    ����     ���ſγɼ�     ƽ���ɼ�" << endl;
	cout << "=============================================" << endl;
	cout<<resetiosflags(ios::right);//���֮ǰ���Ҷ��룬�������������
	cout<<setiosflags(ios::left);
	for (p = stu; p - stu < snum; p++)
	{
		cout << setw(4) << p-stu+1<<" ";
		cout << setw(7) << p->no<<" ";
		cout << setw(8) << p->name<<" ";
		for (s = p->score; s - p->score<cnum; s++)
		{
			cout << setiosflags(ios::fixed) << setprecision(0);//�ȶ�Ū�ɲ���С����֮��
			if ((int)(*s * 10) % 10 != 0)//��С����֮���������ų�С����
				cout << setiosflags(ios::fixed) << setprecision(1);
			cout << setw(4) << *s<< " ";
		}
		s = p->score;
		p->fen = *s + *(s + 1) + *(s + 2);
		p->fen /= cnum;
		cout << setw(5) <<setiosflags(ios::fixed)<<setprecision(2)<< p->fen;
		cout << resetiosflags(ios::fixed);//���С��
		cout << endl;
	}
	cout << endl;
	/* ������ʵ�ֲ��֣��������κ���ʽ��[]���� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����cnum�ſε�ͳ����Ϣ
  ���������
  �� �� ֵ��
  ˵    �������������ֺ궨��SN��CN��10��3
 ***************************************************************************/
void output_course(struct course* cno, int cnum)
{
	int i;  //������ֻ��������һ���������������������κ���ʽ�ı���������for(int k=0; )����ʽ
	cout << "���ſγ̵�ͳ����Ϣ" << endl;
	cout << "��� ��߳ɼ� ��ͳɼ� ƽ���ɼ�" << endl;
	cout << "===============================" << endl;
	cout << setiosflags(ios::fixed) << setprecision(2);
	for (i = 0; i < cnum; i++)
	{
		cout << setw(4) << i + 1 << " ";
		cout << setw(8) << cno[i].max << " ";
		cout << setw(8) << cno[i].min << " ";
		cout << setw(8) << cno[i].avg << " ";
		cout << endl;
	}
	cout << endl;
	/* ������ʵ�ֲ��� */
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
	struct student stu[SN];
	struct course cno[CN];

	/* ���롢ƽ������߷ֱַ�������������ʵ�� */
	input(stu, SN, CN);
	process(stu, SN, cno, CN);
	output_student(stu, SN, CN);
	output_course(cno, CN);

	return 0;
}

/* �������ݣ����Ƶ�cmd���ɣ�����ʱ����������һ�飩

2153171 ������ 76.5 82 52
2154063 ����� 63 49 87
2151626 ������ 56 76 69
2153178 ϯ���� 44.5 83.5 87
2153482 ���� 91 63.5 56
2151931 ���� 79 85.5 62
2151282 ���� 86 63 77.5
2153047 �ż�ľ 49.5 86 93.5
2151405 ��ά�� 68 74.5 60
2152505 ��ѧ�� 73 62 85

*/