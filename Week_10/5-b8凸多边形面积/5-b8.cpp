/* 2151298 信11 杨滕超 */
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
		/*两层循环！第一层确定相邻点与直线，第二层依次比对除了上述两点的点是否在线上*/
	    sum1 = 0;
		sum2 = 0;//记得每次循环后，sum1，sum2 恢复零
		for (i3 = 0; i3 < num; i3++)
		{		
			if ((i3 == i1) || (i3 == i1+1))//跳过构成直线的点
				continue;		
			/*避免用斜率的方式，会出现除数为零的情况*/
			t = xy[i3][0]*(xy[i1+1][1] - xy[i1][1])+xy[i3][1]*(xy[i1][0]-xy[i1+1][0])-xy[i1][0]*xy[i1+1][1]+xy[i1+1][0]*xy[i1][1];
			/*此处应有判断fabs小于1e-6（第一个if） 判断为共线直接推出，和一个大于零（或小于零）计数，下面判断是否都在要么是零，要么是num-2*/
			if (t > 0)//在直线上方
        		sum1++;
			else if(t<0)//在直线下方
				sum2++;	
		}	
		if (sum1 == num - 2 || sum2 == num - 2)//除了构成直线的两个点之外的点都在线上记一次
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
	/*分解成n-2个三角形，以（0，0）为每个三角形的公共顶点*/
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
		cout << "请输入多边形的顶点数量(4-7)" << endl;
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
	cout << "请按顺时针/逆时针方向输入"<<num<<"个顶点的x,y坐标：" << endl;
	while (1)
	{
		cout << "请输入第1个顶点的坐标：" << endl;
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
		cout << "请输入第2个顶点的坐标：" << endl;
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
		cout << "请输入第3个顶点的坐标：" << endl;
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
		cout << "请输入第4个顶点的坐标：" << endl;
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
			cout << "请输入第5个顶点的坐标：" << endl;
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
			cout << "请输入第5个顶点的坐标：" << endl;
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
			cout << "请输入第6个顶点的坐标：" << endl;
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
			cout << "请输入第5个顶点的坐标：" << endl;
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
			cout << "请输入第6个顶点的坐标：" << endl;
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
			cout << "请输入第7个顶点的坐标：" << endl;
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
		cout << "凸" << num << "边形的面积=" << area(xy, num) << endl;
	else 
		cout << "不是凸" << num << "边形" << endl;


	return 0;
}