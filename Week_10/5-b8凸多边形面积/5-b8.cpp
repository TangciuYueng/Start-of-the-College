/* 2151298 ��11 ������ */
#include <iostream>
#include <cmath>
using namespace std;
#define M 7
#define N 2
int judge(double xy[M][N],int num)
{
	int i1, i3=0,sum1=0,sum2=0,sum3=0;
	double t;
	for (i1 = 0; i1 < num-1; i1++)
	{
		/*����ѭ������һ��ȷ�����ڵ���ֱ�ߣ��ڶ������αȶԳ�����������ĵ��Ƿ�������*/
	    sum1 = 0;
		sum2 = 0;//�ǵ�ÿ��ѭ����sum1��sum2 �ָ���
		for (i3 = 0; i3 < num; i3++)
		{		
			if ((i3 == i1) || (i3 == i1+1))//��������ֱ�ߵĵ�
				continue;		
			/*������б�ʵķ�ʽ������ֳ���Ϊ������*/
			t = xy[i3][0]*(xy[i1+1][1] - xy[i1][1])+xy[i3][1]*(xy[i1][0]-xy[i1+1][0])-xy[i1][0]*xy[i1+1][1]+xy[i1+1][0]*xy[i1][1];
			/*�˴�Ӧ���ж�fabsС��1e-6����һ��if�� �ж�Ϊ����ֱ���Ƴ�����һ�������㣨��С���㣩�����������ж��Ƿ���Ҫô���㣬Ҫô��num-2*/
			if (t > 0)//��ֱ���Ϸ�
        		sum1++;
			else if(t<0)//��ֱ���·�
				sum2++;	
		}	
		if (sum1 == num - 2 || sum2 == num - 2)//���˹���ֱ�ߵ�������֮��ĵ㶼�����ϼ�һ��
			sum3++;
	}

	if (sum3==num-1)
		return 1;
	else
		return 0;
}
double area(double xy[M][N], int num)
{
	int i;
	double ds,S=0;
	/*�ֽ��n-2�������Σ��ԣ�0��0��Ϊÿ�������εĹ�������*/
	for (i = 1; i < num - 1; i++)
	{
		ds = fabs(xy[i][0] * xy[i + 1][1] + xy[i + 1][0] * xy[0][1] + xy[0][0] * xy[i][1] - xy[i][0] * xy[0][1] - xy[i + 1][0] * xy[i][1] - xy[0][0] * xy[i + 1][1]) / 2;
		S += ds;
	}
	return S;
}
int main()
{
	int num;
	double xy[M][N];
	while (1)
	{
		cout << "���������εĶ�������(4-7)" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (num >= 4 && num <= 7)
			break;
	}
	cout << "�밴˳ʱ��/��ʱ�뷽������"<<num<<"�������x,y���꣺" << endl;
	while (1)
	{
		cout << "�������1����������꣺" << endl;
		cin >> xy[0][0] >> xy[0][1];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	while (1)
	{
		cout << "�������2����������꣺" << endl;
		cin >> xy[1][0] >> xy[1][1];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	while (1)
	{
		cout << "�������3����������꣺" << endl;
		cin >> xy[2][0] >> xy[2][1];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	while (1)
	{
		cout << "�������4����������꣺" << endl;
		cin >> xy[3][0] >> xy[3][1];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	if (num == 5)
	{
		while (1)
		{
			cout << "�������5����������꣺" << endl;
			cin >> xy[4][0] >> xy[4][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
	}
	else if (num == 6)
	{
		while (1)
		{
			cout << "�������5����������꣺" << endl;
			cin >> xy[4][0] >> xy[4][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
		while (1)
		{
			cout << "�������6����������꣺" << endl;
			cin >> xy[5][0] >> xy[5][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
	}
	else if(num==7)
	{
		while (1)
		{
			cout << "�������5����������꣺" << endl;
			cin >> xy[4][0] >> xy[4][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
		while (1)
		{
			cout << "�������6����������꣺" << endl;
			cin >> xy[5][0] >> xy[5][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
		while (1)
		{
			cout << "�������7����������꣺" << endl;
			cin >> xy[6][0] >> xy[6][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else
				break;
		}
	}

	if (judge(xy, num))
		cout << "͹" << num << "���ε����=" << area(xy, num) << endl;
	else 
		cout << "����͹" << num << "����" << endl;


	return 0;
}