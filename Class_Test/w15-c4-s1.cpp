/* 2151298 信11 杨滕超  */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define SN	10	//student_num
#define CN	3	//course_num

struct student {
	int   no;        //学号（虽然用int不够合理，此处不考虑）
	char  name[9];   //假设姓名最长4个汉字
	float score[CN]; //数组放CN门课的成绩
	float fen;             //可增加其它你认为需要增加的结构体成员（限一个），不需要则删除本行
};

struct course {
	float max;    //某门课程的最高成绩
	float min;    //某门课程的最低成绩
	float avg;    //某门课程的平均成绩
};

/***************************************************************************
  函数名称：
  功    能：输入snum个学生的基本信息及cnum门课的成绩
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义SN、CN、10、3
 ***************************************************************************/
void input(struct student* stu, int snum, int cnum)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	int i, j;
	for (i = 0; i < snum; i++)
	{
		cout << "请输入第" << setw(2) << setiosflags(ios::right) << i + 1 << "个学生的信息 : ";
		cin >> stu[i].no;
		cin >> stu[i].name;
		for (j = 0; j < cnum; j++)
		{
			cin >> stu[i].score[j];
		}
	}
	cout << endl;
	/* 函数的实现部分 */
}

/***************************************************************************
  函数名称：
  功    能：统计cnum门课的最高、最低、平均成绩（snum个学生）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义SN、CN、10、3
 ***************************************************************************/
void process(struct student* stu, int snum, struct course* cno, int cnum)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	int i, j;
	for (i = 0; i < cnum; i++)//第i门课
	{
		cno[i].avg = 0;
		j = 0;
		cno[i].max = stu[j].score[i];
		cno[i].min = stu[j].score[i];
		for (j = 0; j < snum; j++)//第j个学生
		{
			cno[i].avg += stu[j].score[i];//每个分数加起来
			if (j > 0)//从第二个开始
			{
				if(stu[j].score[i]> cno[i].max)//有比max还大的赋值给max
					cno[i].max = stu[j].score[i];
				else if(stu[j].score[i] < cno[i].min)
					cno[i].min = stu[j].score[i];
			}
		}
		cno[i].avg /= snum;//求平均
	}
	/* 函数的实现部分 */
}

/***************************************************************************
  函数名称：
  功    能：输出snum个学生的基本信息及平均成绩
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义SN、CN、10、3
 ***************************************************************************/
void output_student(struct student* stu, int snum, int cnum)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* p;
	float* s;
	cout << snum << "个学生的成绩为" << endl;
	cout << "序号 学号    姓名     三门课成绩     平均成绩" << endl;
	cout << "=============================================" << endl;
	cout<<resetiosflags(ios::right);//解除之前的右对齐，才能设置左对齐
	cout<<setiosflags(ios::left);
	for (p = stu; p - stu < snum; p++)
	{
		cout << setw(4) << p-stu+1<<" ";
		cout << setw(7) << p->no<<" ";
		cout << setw(8) << p->name<<" ";
		for (s = p->score; s - p->score<cnum; s++)
		{
			cout << setiosflags(ios::fixed) << setprecision(0);//先都弄成不出小数点之后
			if ((int)(*s * 10) % 10 != 0)//若小数点之后有数，才出小数点
				cout << setiosflags(ios::fixed) << setprecision(1);
			cout << setw(4) << *s<< " ";
		}
		s = p->score;
		p->fen = *s + *(s + 1) + *(s + 2);
		p->fen /= cnum;
		cout << setw(5) <<setiosflags(ios::fixed)<<setprecision(2)<< p->fen;
		cout << resetiosflags(ios::fixed);//解除小数
		cout << endl;
	}
	cout << endl;
	/* 函数的实现部分，不允许任何形式的[]出现 */
}

/***************************************************************************
  函数名称：
  功    能：输出cnum门课的统计信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义SN、CN、10、3
 ***************************************************************************/
void output_course(struct course* cno, int cnum)
{
	int i;  //本函数只定义了这一个变量，不再允许定义任何形式的变量，包括for(int k=0; )等形式
	cout << "三门课程的统计信息" << endl;
	cout << "序号 最高成绩 最低成绩 平均成绩" << endl;
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
	/* 函数的实现部分 */
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
	struct student stu[SN];
	struct course cno[CN];

	/* 输入、平均、最高分分别由三个函数来实现 */
	input(stu, SN, CN);
	process(stu, SN, cno, CN);
	output_student(stu, SN, CN);
	output_course(cno, CN);

	return 0;
}

/* 测试数据，复制到cmd即可（测试时，不限于这一组）

2153171 曾明宇 76.5 82 52
2154063 刘佳昊 63 49 87
2151626 杜镇宇 56 76 69
2153178 席昌林 44.5 83.5 87
2153482 张羽 91 63.5 56
2151931 徐雄 79 85.5 62
2151282 梁阳 86 63 77.5
2153047 张佳木 49.5 86 93.5
2151405 孟维清 68 74.5 60
2152505 栾学禹 73 62 85

*/