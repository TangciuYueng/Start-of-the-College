/* 2151298 信11 杨滕超 */
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
	{'A', "香辣鸡腿堡",         18.5},
	{'B', "劲脆鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "劲爆鸡米花",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "藤椒无骨大鸡柳(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "香甜粟米棒",         9.0},
	{'U', "葡式蛋挞",           8.0},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
	//	{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
		{NULL, NULL, 0}
};
int main()
{
	while(1)
	{
		system("cls");
		system("mode con cols=120 lines=35");
		cout << "=============================================================" << endl;
		cout << "                      KFC 2021秋季菜单" << endl;
		cout << "=============================================================" << endl;
		int i, j, k = 0, q = 0, sum[NUM] = { 0 }, sum1[NUM] = { 0 };
		double  price = 0;
		char a[20];
		/*打印菜单*/
		for (i = 0; list[i].sym != '\0'; i++)
		{
			cout << setw(2) << setiosflags(ios::right) << list[i].sym << " ";
			cout << resetiosflags(ios::right);//解除右对齐
			cout << setiosflags(ios::left) << setw(20) << list[i].name;
			cout << setiosflags(ios::left) << setw(7) << list[i].money;
			cout << resetiosflags(ios::left);//解除左对齐

			if (i % 2 == 0)
				cout << "|  ";
			else
				cout << endl;
		}


		cout << endl << "【优惠信息】：" << endl;
		/*优惠信息输出部分*/
		for (i = 0; special[i].money != 0; i++)
		{
			for (j = 0; j < NUM; j++)
				sum[j] = 0;
			/*看有什么字母*/
			for (j = 0; special[i].zuhe[j] != '\0'; j++)
			{
				if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
				{
					sum[special[i].zuhe[j] - 'A']++;//对应二十六个字母位置有多少个数字母
					if (sum[special[i].zuhe[j] - 'A'] > 1)
						a[j] = '9';//表示重复的数字
					else
						a[j] = special[i].zuhe[j];//a数组记录组合里面有什么字母
				}
			}
			a[j] = '\0';

			cout << special[i].name << "=";
			/*字母对应的名字*/
			for (j = 0; ; j++)
			{
				if (a[j] >= 'A' && a[j] <= 'Z')
				{
					cout << list[a[j] - 'A'].name;
					if (sum[a[j] - 'A'] > 1)
						cout << "*" << sum[a[j] - 'A'];//通过a中的字母对应sum中对应字母的个数
					cout << "+";
				}
				else if (a[j] == '9')//表示与前面有过的字母重复
				{
					continue;
				}
				else
					break;
			}
			cout << '\b';//去掉最后一个+
			cout << "=" << special[i].money << endl;
		}

		cout << endl << "【输入规则说明】：" << endl;
		cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
		cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
		cout << endl << "请点单: ";
		char str[NUM] = { '\0' };


		price = 0;
		cin.getline(str,NUM,'\n');
		if (str[0] == '0' && str[1] == '\0')//结束
			break;
		else//不结束部分
		{
			/*小写转换成大写字母*/
			for (i = 0; i < NUM; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
			/*判断有无非字母字符*/
			for (i = 0; i < NUM && str[i] != '\0'; i++)
			{
				if (str[i] < 'A' || str[i]>'Z')
				{
					k++;
					break;
				}
			}
			if (k)//有非字母字符
			{
				cout << "输入错误，按任意键继续." << endl;
			}
			else//都是大写字母字符了
			{
				for (j = 0; j < NUM; j++)
					sum[j] = 0;
				/*记录对应字母有多少个*/
				for (j = 0; j < NUM; j++)
					if (str[j] >= 'A' && str[j] <= 'Z')
						sum[str[j] - 'A']++;
				/*点餐结果*/
				cout << "您的点餐=";
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
				cout << '\b' << " ";//去掉最后一个+
				cout << endl << "共计：";
				/*价钱计算*/
				for (i = 0; special[i].money != 0; )//循环优惠方案
				{
					/*sum1和q的初始化*/
					for (j = 0; j < NUM; j++)
						sum1[j] = 0;
					q = 0;

					for (j = 0; special[i].zuhe[j] != '\0'; j++)//循环优惠方案中的每个字母，由sum1数组记录
					{
						if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
						{
							sum1[special[i].zuhe[j] - 'A']++;//记录对应字母个数，记录完该字母即可判断
							if (sum[special[i].zuhe[j] - 'A'] < sum1[special[i].zuhe[j] - 'A'])//有一个字母没有就q非零，即不满足优惠
								q++;
						}
					}
					if (!q)//满足优惠！
					{
						price += special[i].money;
						for (j = 0; special[i].zuhe[j] != '\0'; j++)//循环优惠方案中的每个字母
						{
							if (special[i].zuhe[j] >= 'A' && special[i].zuhe[j] <= 'Z')
								sum[special[i].zuhe[j] - 'A']--;//减去套餐里面的东西
						}
					}
					else//不满足优惠，看下一个优惠满足否
						i++;
				}//end of for
				/*除去优惠剩余价钱的计算*/
				for (i = 0; list[i].sym != '\0'; i++)
				{
					if (list[i].sym >= 'A' && list[i].sym <= 'Z')
					{
						price += list[i].money * sum[list[i].sym - 'A'];
					}
				}
				cout << price;
				cout << "元" << endl;
				cout << "点单完成，按任意键继续." << endl;
				

			}//end of A-Z part else
			char ch;
			ch = _getch();
		}//end of big else
	
	}//end of while

	return 0;
}
