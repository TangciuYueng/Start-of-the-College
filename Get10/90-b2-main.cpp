/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
#define RE 8
#define CE 10
using namespace std;
int menu()
{
	cout << "---------------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版(支持鼠标)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "A.命令行界面（网络自动解-基本版）" << endl;
	cout << "B.伪图形界面（网络自动解-基本版）" << endl;
	//cout << "C.命令行界面（网络自动解-竞赛版）" << endl;
	cout << "---------------------------------------" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[请选择:] ";
	char ch;
	while (1)
	{
		ch = _getch();

		if (ch >= '0' && ch <= '9')
		{
			cout << ch - '0' << endl;
			break;
		}
		else if ((ch >= 'A' && ch <= 'C') || ch >= 'a' && ch <= 'c')
		{
			if (ch >= 'a' && ch <= 'c')
				ch -= 32;
			cout << ch << endl;
			break;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	return ch - '0';
}
int main()
{
	int r, c, tgt = 5, tgt0 = 5, lie, map[RE + 2][CE + 2] = { 0 }, i, j, sum = 0, zongfen = 0;
	int  ret1, ret2 = 0, ret9;
	char hang, map2[RE + 2][CE + 2], ch;
	while (1)
	{
		zongfen = 0;//总分恢复
		for (i = 0; i < RE + 1; i++)//每次循环map和map2的恢复
			for (j = 0; j < CE + 1; j++)
			{
				map[i][j] = 0;
				map2[i][j] = '0';
			}
			
		cct_cls();
		int choice = menu();
		if (choice == 0)
		{
			cout << endl << endl << endl << endl << endl;
			break;
		}
		else if(choice==1)
		{
			cct_cls();
			input(&r, &c, &tgt,choice);
			cin.ignore(65536, '\n');//跳过在缓冲区里面的东西
			rand_num(map, r, c);//随机生成数字
			output(map,map2,r, c);//输出当前数组
			while (1)
			{
				input2(&r, &c, &hang, &lie);
				search1(map, map2, &hang, &lie);
				if (search1(map, map2, &hang, &lie)>1)
					break;
				else
				{
					cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
					cin.ignore(65536, '\n');
				}
			}
			output(map, map2, r, c, 1);//输出字母数组*、0
			output(map, map2, r, c, 2);//输出有颜色标识的数组
			to_be_continued();
			
		}
		else if (choice == 2)
		{
			cct_cls();
			input(&r, &c, &tgt,choice);
			cin.ignore(65536, '\n');//跳过在缓冲区里面的东西
			rand_num(map, r, c);//随机生成数字
			output(map, map2, r, c);//输出当前数组
			while (1)
			{
				input2(&r, &c, &hang, &lie);
				map2[hang - 'A' + 1][lie + 1] = '*';//先给输入坐标置*，之后进入递归函数
				search2(map, map2, hang - 'A' + 1, lie + 1, map[hang - 'A' + 1][lie + 1 ]);
				if (count(map2) > 1)
					break;
				else
				{
					cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
					cin.ignore(65536, '\n');
				}
			}
			output(map, map2, r, c, 1);//输出字母数组*、0
			output(map, map2, r, c, 2);//输出有颜色标识的数组
			to_be_continued();
		}
		else if (choice == 3)
		{
			cct_cls();
			input(&r, &c, &tgt, choice);
			cin.ignore(65536, '\n');//跳过在缓冲区里面的东西
			rand_num(map, r, c);//随机生成数字
			output(map, map2, r, c,0);//输出当前数组
			while (1)
			{
				while (1)
				{
					input2(&r, &c, &hang, &lie);
					search1(map, map2, &hang, &lie);
					if (search1(map, map2, &hang, &lie) > 1)
						break;
					else
					{
						cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
						cin.ignore(65536, '\n');
					}
				}
				output(map, map2, r, c, 1);//输出字母数组*、0
				output(map, map2, r, c, 2);//输出有颜色标识的数组

				ch = input3(&hang, &lie);
				if (ch == 'Y'||ch == 'Q')
					break;
			}
			if (ch == 'Y')
			{
				merge(map, map2, &hang, &lie);//非输入坐标的，变成零
				output(map, map2, r, c, 3);//输出合并的数组
				fen(map, map2, &hang, &lie, &tgt, &zongfen);
				input456(4);//回车继续
				map2[hang - 'A' + 1][lie + 1] = '0';
				drop(map, map2,r);
				output(map, map2, r, c, 4);
				input456(5);//回车新值填充
				myrandom(map, map2, find_max(map));
				output(map, map2, r, c, 5);

			}
			to_be_continued();
		}//end of choice3
		else if (choice == 4)
		{
			cct_cls();
			input(&r, &c, &tgt, choice);
			tgt0 = tgt;
			cin.ignore(65536, '\n');//跳过在缓冲区里面的东西
			rand_num(map, r, c);//随机生成数字
			output(map, map2, r, c, 0);//输出当前数组
			while (1)
			{
				
				while (1)
				{
					while (1)
					{
						input2(&r, &c, &hang, &lie);
						cout << "输入为"<<hang<<"行"<<lie<<"列" << endl;
						search1(map, map2, &hang, &lie);
						if (search1(map, map2, &hang, &lie) > 1)
							break;
						else
						{
							cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
							cin.ignore(65536, '\n');
						}
					}
					output(map, map2, r, c, 1);//输出字母数组*、0
					output(map, map2, r, c, 2);//输出有颜色标识的数组

					ch = input3(&hang, &lie);
					if (ch == 'Y' || ch == 'Q')
						break;
				}
				if (ch == 'Q')//跳出最外层循环
				{
					to_be_continued();
					break;
				}
				if (ch == 'Y')
				{
					merge(map, map2, &hang, &lie);//非输入坐标的，变成零
					output(map, map2, r, c, 3);//输出合并的数组
					fen(map, map2, &hang, &lie, &tgt,&zongfen);//记录分数
					input456(4);//回车继续
					map2[hang - 'A' + 1][lie + 1] = '0';
					drop(map, map2, r);
					output(map, map2, r, c, 4);
					input456(5);//回车新值填充
					myrandom(map, map2, find_max(map));//填充新值
					output(map, map2, r, c, 5);
				}
				input456(6);
				cout << endl;
				if (find_max(map) == tgt && sum == tgt-tgt0)
				{
					cct_setcolor(14, 4);
					cout << "已经合成到" << tgt << endl;
					cct_setcolor();
					sum++;//注意先输出当先的，合成目标再变化
					tgt++;
					input456(7);
					cout << endl;
					output(map, map2, r, c, 0);
				}
				else
					cout << endl;
			}
		}//end of choice 4
		if (choice == 5 || choice==6||choice==7||choice==8)
		{
			cct_cls();
			input(&r, &c, &tgt,choice);//输入行数和列数
			rand_num(map, r, c);//随机生成数字
			choice56(map, map2, &r, &c,choice);//选项56479
			if (choice == 7)
			{
				cct_gotoxy(0, r * 4 + 3);
				cout << "箭头键/鼠标移动，回车键/单击左键选择并结束";
				MouseKeyboard(map, map2, r, c, &hang, &lie,choice);
			}	
			else if (choice == 8)
			{
				hang = 'A';
				lie = 0;
				cct_gotoxy(0, r * 4 + 3);
				cout << "箭头键/鼠标移动，回车键/单击左键选择,Q/单击右键结束";
				while (1)
				{
					ret1=MouseKeyboard(map, map2, r, c, &hang, &lie,choice);
					if (ret1)//右键或q结束
					{
						break;
					}
					search1(map, map2, &hang, &lie);//相邻相同置*
					cct_gotoxy(0, 4 * r + 4);
					MulLightorDark(map, map2, r, c, hang, lie, 3);//相同值变亮
					if (search1(map, map2, &hang, &lie) > 1)//周围有相同的值
					{
						ret2 = MouseKeyboardAffirm(map, map2, r, c, &hang, &lie);//记录是否有左键或回车
						if (ret2>0)//
						{
							cct_gotoxy(0, 4 * r + 3);
							cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
							break;
						}
						else
						{
							MulLightorDark(map, map2, r, c, hang, lie, 2);//相同值变暗
						}
					}
					else//周围没有相同值，MouseKeyboard
					{
						cct_gotoxy(0, 4 * r + 3);
						cct_setcolor(0, 14);
						cout << "周围无相同值";
						cct_setcolor();
						cout << "箭头键/鼠标移动，回车键/单击左键选择";
					}
					if (ret1)
						break;
				}//end of while

				merge(map, map2, &hang, &lie);//非输入坐标的，变成零
				cct_gotoxy(0, 0);
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//第一行输出得分
				MulBlank(map, map2, r, c, hang, lie);//非输入坐标的,变空白
				shining(map, map2, r, c, hang, lie);//合并完成之后的闪动
				cct_gotoxy(0, 4 * r + 3);
				cct_setcursor(CURSOR_INVISIBLE);//关闭鼠标显示
				cout << "合成完成，回车键/单击左键下落0                         ";
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//恢复鼠标显示
				confirm();//回车或左键确认
				map2[hang - 'A' + 1][lie + 1] = '0';//输入坐标的色块不置*
				Drop(map, map2, r, c);//块下落
				cct_gotoxy(0, 4 * r + 3);
				cct_setcursor(CURSOR_INVISIBLE);//关闭鼠标显示
				cout << "下落0完成，回车键/单击左键填充新值                        ";
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//恢复鼠标显示
				confirm();//回车或左键确认
				myrandom(map, map2, find_max(map));//填充随机值
				fill(map, map2, r, c);
				cct_gotoxy(0, 4 * r + 3);
				cct_setcolor(0, 14);
				cct_setcursor(CURSOR_INVISIBLE);//关闭鼠标显示
				cout << "本次合成结束，按C/单击左键继续新一次的合成       ";
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//
				cct_setcolor();
				confirmC();
			}//end of choice 8
			cct_gotoxy(0, 4 * r + 4);
			to_be_continued();
		}//end of chioce 5678
		else if (choice == 9)
		{
			cct_cls();
			input(&r, &c, &tgt, choice);//输入行数和列数
			tgt0 = tgt;
			rand_num(map, r, c);//随机生成数字
			choice56(map, map2, &r, &c, choice);//选项56479
			while(1)
			{
				ret9 = gameend(map, map2, r, c);
				if ( ret9== 0)
					break;
				hang = 'A';
				lie = 0;
				cct_gotoxy(0, r * 4 + 3);
				cout << "箭头键/鼠标移动，回车键/单击左键选择,Q/单击右键结束";
				while (1)
				{
					ret1 = MouseKeyboard(map, map2, r, c, &hang, &lie, choice);
					if (ret1)//右键或q结束
						break;
					search1(map, map2, &hang, &lie);//相邻相同置*
					cct_gotoxy(0, 4 * r + 4);
					MulLightorDark(map, map2, r, c, hang, lie, 3);//相同值变亮
					if (search1(map, map2, &hang, &lie) > 1)//周围有相同的值
					{
						ret2 = MouseKeyboardAffirm(map, map2, r, c, &hang, &lie);//记录是否有左键或回车
						if (ret2 > 0)//有回车或左键
						{
							cct_gotoxy(0, 4 * r + 3);
							cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成";
							break;
						}
						else
						{
							MulLightorDark(map, map2, r, c, hang, lie, 2);//相同值变暗
						}
					}
					else//周围没有相同值，MouseKeyboard
					{
						cct_gotoxy(0, 4 * r + 3);
						cct_setcolor(0, 14);
						cout << "周围无相同值";
						cct_setcolor();
						cout << "箭头键/鼠标移动，回车键/单击左键选择";
					}
					if (ret1)
						break;
				}//end of while
				if (ret1)//右键或者q/Q结束本小题
					break;
				merge(map, map2, &hang, &lie);//非输入坐标的，变成零
				cct_gotoxy(0, 0);
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//第一行输出得分
				MulBlank(map, map2, r, c, hang, lie);//非输入坐标的,变空白
				shining(map, map2, r, c, hang, lie);//合并完成之后的闪动
				cct_gotoxy(0, 4 * r + 3);
				
				map2[hang - 'A' + 1][lie + 1] = '0';//输入坐标的色块不置*
				Drop(map, map2, r, c);//块下落
				
				myrandom(map, map2, find_max(map));//填充随机值
				fill(map, map2, r, c);
				
				if (find_max(map) == tgt && sum == tgt - tgt0)
				{
					cct_gotoxy(0, 4 * r + 3);
					cct_setcolor(0, 14);
					cout << "已经合成到" << tgt;
					cct_setcolor();
					sum++;//注意先输出当先的，合成目标再变化
					tgt++;
					cout << "，按回车键/单击左键继续向更高目标进发";
					confirm();
				}
				cct_gotoxy(0, 0);//若合成目标改变，需要重新输出
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//第一行输出得分
				
			}//end of while
			if (ret9 == 0)
			{
				cct_gotoxy(0, 4 * r + 3);
				cout << "游戏结束                                    ";
				cct_gotoxy(0, 4 * r + 4);
				to_be_continued();
			}
			else
			{
				cct_gotoxy(0, 4 * r + 4);
				to_be_continued();
			}
			
		}//end of choice 9
		if (choice == 'A' - '0' || choice == 'B' - '0')
		{
			choiceAB(map, map2, tgt, choice);
		}//end of choice A
		
	}
	return 0;
}