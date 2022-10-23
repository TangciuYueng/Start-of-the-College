/* 2151298 信11 杨滕超 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度
class stu_list;//提前声明
#define MAX_NO_LEN        8
#define NUM               2
/*返回值是char型指针*/
char* tj_strcpy(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* s10 = s1;
	if (s1 == NULL)
		return 0;
	else
	{
		if (s2 == NULL)//放个空的在开头
			*s1 = '\0';
		else
		{
			for (;; s2++, s1++)
			{
				*s1 = *s2;//从s1的第一个开始赋值
				if (*s2 == '\0')
					break;
			}
		}
		s1 = s10;//s1复位
		return s1;
	}
}

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no = 0;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	char no[MAX_NO_LEN];  //字符学号
	int turn[NUM] = { 0 };//轮次
	int z;//记录第一轮最后一个的位置
	friend class stu_list;//友元
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	/* 允许按需加入private数据成员和成员函数 */

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append)
{
	int i, j, sum = 0, k1;
	char ch;
	ifstream in;
	in.open(filename, ios::in);

	if (!in.is_open())//打开不成功
	{
		cout << "文件[" << filename << "]打开失败" << endl;
		return -1;
	}
	else//文件打开成功
	{
		if (append == 0)//第一轮
		{
			for (i = 0; i < MAX_STU_NUM + 1; i++)
			{
				/*循环开始字符数组置尾零*/
				for (j = 0; j < MAX_NO_LEN; j++)
				{
					stu[i].no[j] = '\0';
				}
				for (j = 0; j < MAX_NAME_LEN; j++)
				{
					stu[i].stu_name[j] = '\0';
				}
				/*读入学号字符*/
				for (j = 0; j < MAX_NO_LEN && in.peek() >= '0' && in.peek() <= '9'; j++)
				{
					stu[i].no[j] = in.get();
				}


				/*跳过空格回车*/
				while (1)
				{
					if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
						ch = in.get();
					else
						break;
				}

				//if (in.peek() == 13 || in.peek() == 10)//没必要，没有读到名字没有回车
				//	continue;
				/*读取名字*/
				for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13&&in.peek()!=EOF; j++)
					stu[i].stu_name[j] = in.get();

				/*跳过空格回车*/
				while (1)
				{
					if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
						ch = in.get();
					else
						break;
				}
				/*学号字符转为int字符*/
				stu[i].stu_no = 0;
				int k = 1000000;
				for (j = 0; stu[i].no[j] != '\0'; j++)
				{
					stu[i].stu_no += (stu[i].no[j] - '0') * k;
					k /= 10;
				}
				/*标记第一轮*/
				stu[i].turn[0] = 1;
				stu[0].z = i;
				/*cout << stu[i].stu_no << " ";
				for (j = 0; j<MAX_NAME_LEN&&stu[i].stu_name[j] != '\0'; j++)
				{
					cout << stu[i].stu_name[j];
				}
				cout << endl;
				ch = _getch();*/
				/*文件尾结束*/
				if (in.peek() == EOF)
					break;

			}//end of for i
		}//end of if append==1
		else//第二轮选课
		{
			stu[0].z += 0;
			/*从第一轮的名单最后接着读入*/
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
				while (1)//循环读入学号，直到与之前的学号都不同了才跳出
				{
					sum = 0;
					/*读入学号字符*/
					for (j = 0; j < MAX_NO_LEN && in.peek() >= '0' && in.peek() <= '9'; j++)
					{
						stu[i].no[j] = in.get();
					}
					/*学号字符转为int字符*/
					stu[i].stu_no = 0;
					int k = 1000000;
					for (j = 0; stu[i].no[j] != '\0'; j++)
					{
						stu[i].stu_no += (stu[i].no[j] - '0') * k;
						k /= 10;
					}
					/*找前面是否有相同学号的*/
					for (k = 0; k <= stu[0].z; k++)
					{
						if (stu[k].stu_no == stu[i].stu_no)
						{
							k1 = k;//记录下两轮选课都有的学号
							sum++;
						}
					}
					if (sum == 0)//与前面都不同的
					{
						stu[i].turn[1] = 1;//第二轮选课有，跳出循环读取下面的名字
						break;
					}
					else//有相同的，把后面的都读完之后并且 都置零 然后重新循环读下面一个
					{
						stu[k1].turn[1] = 1;//第二轮选课有，注意是k1
						/*跳过空格回车*/
						while (1)
						{
							if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
								ch = in.get();
							else
								break;
						}
						/*读取名字*/
						for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13; j++)
							stu[i].stu_name[j] = in.get();
						/*跳过空格回车*/
						while (1)
						{
							if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
								ch = in.get();
							else
								break;
						}
						/*学号，姓名都恢复*/
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
					}//end of else 有相同值
					
				}//end of while 

				if (in.peek() == EOF)
					break;
				/*跳过空格回车*/
				while (1)
					{
						if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
							ch = in.get();
						else
							break;
					}
				/*读取名字*/
				for (j = 0; j < MAX_NAME_LEN && in.peek() != 10 && in.peek() != 13&&in.peek()!=EOF; j++)
					stu[i].stu_name[j] = in.get();
				/*跳过空格回车*/
				while (1)
					{
						if (in.peek() == ' ' || in.peek() == 10 || in.peek() == 13 || in.peek() == '\t')
							ch = in.get();
						else
							break;
					}

				
				/*文件尾结束*/
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
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;
	/*学号升序*/
	for (i = 0; i < MAX_STU_NUM + 1; i++)
	{
		for (j = 0; j < MAX_STU_NUM - i && stu[j + 1].stu_no>0; j++)//注意不要把零拿到前面，零都在最后/没有
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
	for (i = 0; i < MAX_STU_NUM + 1 && stu[i].stu_no != 0; i++)//只输出学号不是零的
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
			cout << "补选";
		}
		else if (stu[i].turn[0] > 0 && stu[i].turn[1] == 0)
		{
			cout << setw(7) << 'Y';
			cout << "退课";
		}
		cout << endl;
		
	}
	cout << "===========================================================" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}