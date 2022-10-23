/* 2151298 信11 杨滕超 */
/* 2152813 陆宇龙 2152497 赵勃维 2151404 陈鹏宇 2151779 王睿 2151515 邓兰可 2150238 袁泉*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#define N 80
#define ADD 9
#define M 32
using namespace std;
int main()
{
	char ifname[N] = { '\0' }, ofname[N] = { '\0' }, add[ADD] = { '\0' }, a[M + 1] = { '\0' }, ch;
	char b[M / 2 + 1] = { '\0' };
	int i, j, k, a0[M / 2] = { 0 }, sum1, sum2, sum = 0, sum0, loop = 0;
	clog << "文件名以下形式均可以:" << endl;
	clog << "    a.txt                    : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat          : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入要转换的hex格式文件名 : ";
	cin >> ifname;
	clog << "请输入转换后的文件名        : ";
	cin >> ofname;
	ifstream in;
	ofstream out;
	in.open(ifname, ios::in  | ios::binary);
	if (!in.is_open())
	{
		cout << "输入文件" << ifname << "打开失败!" << endl;
		return -1;
	}
	else
	{
		/*打开目标文件*/
		out.open(ofname, ios::out | ios::binary);
		while (1)
		{
			/*if (in.peek() == EOF)
				break;*/
			k = 0;
			sum1 = 0;
			sum2 = 0;
			for (i = 0; i < M; i++)//a数组恢复
				a[i] = '\0';
			for (i = 0; i < M / 2; i++)//b数组恢复
				b[i] = '\0';
			/*读取位置,会全部覆盖*/
			for (i = 0; i < ADD-1; i++)
			{
				if (in.peek() == EOF||in.peek()==' ')
					break;
				add[i] = in.get();
			}
			/*验证偏移量*/
			sum0 = 0;
			
			if (add[0] >= '0' && add[0] <= '9')
				sum0 += 16 * 16 * 16 * 16 * 16 * 16 * 16 * (add[0] - '0');
			else if (add[0] >= 'a' && add[0] <= 'f')
				sum0 += 16 * 16 * 16 * 16 * 16 * 16 * 16 * (add[0] - 87);
			if (add[1] >= '0' && add[1] <= '9')
				sum0 += 16 * 16 * 16 * 16 * 16 * 16 *  (add[1] - '0');
			else if (add[1] >= 'a' && add[1] <= 'f')
				sum0 += 16 * 16 * 16 * 16 * 16 * 16 *  (add[1] - 87);
			if (add[2] >= '0' && add[2] <= '9')
				sum0 += 16 * 16 * 16 * 16 * 16 *  (add[2] - '0');
			else if (add[2] >= 'a' && add[2] <= 'f')
				sum0 += 16 * 16 * 16 * 16 * 16 *  (add[2] - 87);
			if (add[3] >= '0' && add[3] <= '9')
				sum0 += 16 * 16 * 16 * 16 *  (add[3] - '0');
			else if (add[3] >= 'a' && add[3] <= 'f')
				sum0 += 16 * 16 * 16 * 16 *  (add[3] - 87);
			if (add[4] >= '0' && add[4] <= '9')
				sum0 += 16 * 16 * 16 *  (add[4] - '0');
			else if (add[4] >= 'a' && add[4] <= 'f')
				sum0 += 16 * 16 * 16 *  (add[4] - 87);
			if (add[5] >= '0' && add[5] <= '9')
				sum0 += 16 * 16 *  (add[5] - '0');
			else if (add[5] >= 'a' && add[5] <= 'f')
				sum0 += 16 * 16 * (add[5] - 87);
			if (add[6] >= '0' && add[6] <= '9')
				sum0 += 16 * (add[6] - '0');
			else if (add[6] >= 'a' && add[6] <= 'f')
				sum0 += 16 *  (add[6] - 87);
			if (add[7] >= '0' && add[7] <= '9')
				sum0 +=  (add[7] - '0');
			else if (add[7] >= 'a' && add[7] <= 'f')
				sum0 +=  (add[7] - 87);

			if (sum0 != sum)
			{
				cout<<"最左侧的偏移量0x"<<add<<"不是期望值0x"<<setw(7) << setfill('0') << hex << sum << "0 ";
				break;
			}
			/*跳过空格和-*/
			while (1)
			{
				if (in.peek() == EOF)
					break;
				ch = in.peek();
				if (ch == ' ' || ch == '-')
					ch = in.get();
				ch = in.peek();
				if (ch != ' ' && ch != '-')
					break;
			}
			/*读入对应十六进制 给a数组*/
			for (i = 0; i < M; i++)
			{
				if (in.peek() == EOF)
					break;
				sum1 = 0;//记录空格数量
				sum2 = 0;//记录-数量
				/*跳过空格和-*/
				while (1)
				{
					ch = in.peek();
					if (ch == ' ' || ch == '-')
					{
						ch = in.get();
						if (ch == ' ')
							sum1++;
						else
							sum2++;
					}
					ch = in.peek();
					if ((ch != ' ' && ch != '-') || sum1 >= 2 && sum2 == 0)
						break;
				}
				if (sum1 >= 2 && sum2 == 0)
					break;
				a[i] = in.get();
				k++;
			}
			k /= 2;
			/*跳过空格和-*/
			while (1)
			{
				if (in.peek() == EOF)
					break;
				ch = in.peek();
				if (ch == ' ' || ch == '-')
					ch = in.get();
				ch = in.peek();
				if (ch != ' ' && ch != '-')
					break;
			}
			/*读入对应字符 给b数组*/
			for (i = 0; i < M / 2; i++)
			{
				if (in.peek() == EOF)
					break;
				sum1 = 0;
				/*跳过空格和-*/
				while (1)
				{
					ch = in.peek();
					if (ch == ' ' || ch == '-')
					{
						ch = in.get();
						sum1++;
					}
					ch = in.peek();
					if ((ch != ' ' && ch != '-')||sum1>=2)
						break;
				}
				if (sum1 >= 2)
					break;
				b[i] = in.get();
			}

			/*a0数组存转为十进制的ascii码，初始化*/
			for (i = 0; i < M / 2; i++)
				a0[i] = 0;
			for (i = 0, j = 0; i < M && ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'a' && a[i] <= 'f')); i += 2, j++)
			{
				if (a[i] >= 'a' && a[i] <= 'f')//a97
					a0[j] += 16 * (a[i] - 87);
				else
					a0[j] += 16 * (a[i] - '0');

				if (a[i + 1] >= 'a' && a[i + 1] <= 'f')//a97
					a0[j] += (a[i + 1] - 87);
				else
					a0[j] += (a[i + 1] - '0');
			}
			
			
			for (i = 0; i < k; i++)
			{
				if (a0[i] > 127)//汉字处理
					a0[i] -= 256;
				//if(a0[i]!=13)不能这个
			    out<<(char)a0[i];
			}
			
			/*跳过空格和回车,不读入*/
			while (1)
			{
				ch = in.peek();
				if (ch == ' ' || ch == '\r'|| ch == '\n')
					ch = in.get();
				ch = in.peek();
				if (ch != ' ' && ch != '\r' && ch!='\n')
					break;
			}
			
			if (in.peek() == EOF)
				break;
			sum++;

		}//end of while
	}//end of else 
	out.close();//关闭文件
	in.close();//关闭文件
	return 0;
}