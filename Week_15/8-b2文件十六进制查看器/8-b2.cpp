/* 2151298 信11 杨滕超 */
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
	clog << "文件名以下形式均可以:" << endl;
	clog << "    a.txt                    : 不带路径形式" << endl;
	clog << "    ..\\data\\b.dat          : 相对路径形式" << endl;
	clog << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	clog << "请输入文件名 : ";
	cin >> fname;
	ifstream in;
	in.open(fname, ios::in | ios::binary);
	if (!in.is_open())
	{
		cout << "输入文件" << fname << "打开失败！" << endl;
		return -1;
	}
	else
	{
		while (1)
		{
			if (in.peek() == EOF)
				break;
			k = 0;//记录读入个数k初始化
			/*数组初始化*/
			for (i = 0; i < M; i++)
				a[i] = '\0';

			/*读入给数组，看到了eof就不读入，后面都是\*/
			for (i = 0; i < M; i++)
			{
				if (in.peek() == EOF)//一组十六个读到文件结束停止读入
					break;
				a[i] = in.get();
				k++;//记录一组有多少个字符
			}
			
			/*输出位置*/
			cout << setw(MID) << setfill('0') << hex << j << "0 ";
	
			/*输出读入的k个字符的十六进制*/
			for (i = 0; i < k; i++)
			{
				if (a[i] < 0)//处理汉字
					a[i] += 256;
				cout << setfill(' ');//由原来填充0变成填充空格
				if ((int)(unsigned char)a[i] >= 16)//十六进制两位数
					cout << setw(3) << setiosflags(ios::right) << hex << (int)(unsigned char)a[i];
				else if ((int)(unsigned char)a[i] < 16)
					cout << setw(2) << setiosflags(ios::right) << '0' << hex << (int)(unsigned char)a[i];
				if (k >= M / 2 + 1 && i == M / 2 - 1)//由八个以上的数才有杠
					cout << " -";
			}
			/*补充空位*/
			for (i = k; i < M; i++)//补充没有输出的空位
			{
				cout << "   ";
			}
			if (k < M / 2 + 1)//若没有输出的大于八个，补的空位还有杠
				cout << "  ";

			cout << "     ";//五个空格
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