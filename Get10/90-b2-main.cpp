/* 2151298 ��11 ������ */
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
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������(֧�����)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "A.�����н��棨�����Զ���-�����棩" << endl;
	cout << "B.αͼ�ν��棨�����Զ���-�����棩" << endl;
	//cout << "C.�����н��棨�����Զ���-�����棩" << endl;
	cout << "---------------------------------------" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "[��ѡ��:] ";
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
		zongfen = 0;//�ָֻܷ�
		for (i = 0; i < RE + 1; i++)//ÿ��ѭ��map��map2�Ļָ�
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
			cin.ignore(65536, '\n');//�����ڻ���������Ķ���
			rand_num(map, r, c);//�����������
			output(map,map2,r, c);//�����ǰ����
			while (1)
			{
				input2(&r, &c, &hang, &lie);
				search1(map, map2, &hang, &lie);
				if (search1(map, map2, &hang, &lie)>1)
					break;
				else
				{
					cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
					cin.ignore(65536, '\n');
				}
			}
			output(map, map2, r, c, 1);//�����ĸ����*��0
			output(map, map2, r, c, 2);//�������ɫ��ʶ������
			to_be_continued();
			
		}
		else if (choice == 2)
		{
			cct_cls();
			input(&r, &c, &tgt,choice);
			cin.ignore(65536, '\n');//�����ڻ���������Ķ���
			rand_num(map, r, c);//�����������
			output(map, map2, r, c);//�����ǰ����
			while (1)
			{
				input2(&r, &c, &hang, &lie);
				map2[hang - 'A' + 1][lie + 1] = '*';//�ȸ�����������*��֮�����ݹ麯��
				search2(map, map2, hang - 'A' + 1, lie + 1, map[hang - 'A' + 1][lie + 1 ]);
				if (count(map2) > 1)
					break;
				else
				{
					cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
					cin.ignore(65536, '\n');
				}
			}
			output(map, map2, r, c, 1);//�����ĸ����*��0
			output(map, map2, r, c, 2);//�������ɫ��ʶ������
			to_be_continued();
		}
		else if (choice == 3)
		{
			cct_cls();
			input(&r, &c, &tgt, choice);
			cin.ignore(65536, '\n');//�����ڻ���������Ķ���
			rand_num(map, r, c);//�����������
			output(map, map2, r, c,0);//�����ǰ����
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
						cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
						cin.ignore(65536, '\n');
					}
				}
				output(map, map2, r, c, 1);//�����ĸ����*��0
				output(map, map2, r, c, 2);//�������ɫ��ʶ������

				ch = input3(&hang, &lie);
				if (ch == 'Y'||ch == 'Q')
					break;
			}
			if (ch == 'Y')
			{
				merge(map, map2, &hang, &lie);//����������ģ������
				output(map, map2, r, c, 3);//����ϲ�������
				fen(map, map2, &hang, &lie, &tgt, &zongfen);
				input456(4);//�س�����
				map2[hang - 'A' + 1][lie + 1] = '0';
				drop(map, map2,r);
				output(map, map2, r, c, 4);
				input456(5);//�س���ֵ���
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
			cin.ignore(65536, '\n');//�����ڻ���������Ķ���
			rand_num(map, r, c);//�����������
			output(map, map2, r, c, 0);//�����ǰ����
			while (1)
			{
				
				while (1)
				{
					while (1)
					{
						input2(&r, &c, &hang, &lie);
						cout << "����Ϊ"<<hang<<"��"<<lie<<"��" << endl;
						search1(map, map2, &hang, &lie);
						if (search1(map, map2, &hang, &lie) > 1)
							break;
						else
						{
							cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
							cin.ignore(65536, '\n');
						}
					}
					output(map, map2, r, c, 1);//�����ĸ����*��0
					output(map, map2, r, c, 2);//�������ɫ��ʶ������

					ch = input3(&hang, &lie);
					if (ch == 'Y' || ch == 'Q')
						break;
				}
				if (ch == 'Q')//���������ѭ��
				{
					to_be_continued();
					break;
				}
				if (ch == 'Y')
				{
					merge(map, map2, &hang, &lie);//����������ģ������
					output(map, map2, r, c, 3);//����ϲ�������
					fen(map, map2, &hang, &lie, &tgt,&zongfen);//��¼����
					input456(4);//�س�����
					map2[hang - 'A' + 1][lie + 1] = '0';
					drop(map, map2, r);
					output(map, map2, r, c, 4);
					input456(5);//�س���ֵ���
					myrandom(map, map2, find_max(map));//�����ֵ
					output(map, map2, r, c, 5);
				}
				input456(6);
				cout << endl;
				if (find_max(map) == tgt && sum == tgt-tgt0)
				{
					cct_setcolor(14, 4);
					cout << "�Ѿ��ϳɵ�" << tgt << endl;
					cct_setcolor();
					sum++;//ע����������ȵģ��ϳ�Ŀ���ٱ仯
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
			input(&r, &c, &tgt,choice);//��������������
			rand_num(map, r, c);//�����������
			choice56(map, map2, &r, &c,choice);//ѡ��56479
			if (choice == 7)
			{
				cct_gotoxy(0, r * 4 + 3);
				cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���";
				MouseKeyboard(map, map2, r, c, &hang, &lie,choice);
			}	
			else if (choice == 8)
			{
				hang = 'A';
				lie = 0;
				cct_gotoxy(0, r * 4 + 3);
				cout << "��ͷ��/����ƶ����س���/�������ѡ��,Q/�����Ҽ�����";
				while (1)
				{
					ret1=MouseKeyboard(map, map2, r, c, &hang, &lie,choice);
					if (ret1)//�Ҽ���q����
					{
						break;
					}
					search1(map, map2, &hang, &lie);//������ͬ��*
					cct_gotoxy(0, 4 * r + 4);
					MulLightorDark(map, map2, r, c, hang, lie, 3);//��ֵͬ����
					if (search1(map, map2, &hang, &lie) > 1)//��Χ����ͬ��ֵ
					{
						ret2 = MouseKeyboardAffirm(map, map2, r, c, &hang, &lie);//��¼�Ƿ��������س�
						if (ret2>0)//
						{
							cct_gotoxy(0, 4 * r + 3);
							cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
							break;
						}
						else
						{
							MulLightorDark(map, map2, r, c, hang, lie, 2);//��ֵͬ�䰵
						}
					}
					else//��Χû����ֵͬ��MouseKeyboard
					{
						cct_gotoxy(0, 4 * r + 3);
						cct_setcolor(0, 14);
						cout << "��Χ����ֵͬ";
						cct_setcolor();
						cout << "��ͷ��/����ƶ����س���/�������ѡ��";
					}
					if (ret1)
						break;
				}//end of while

				merge(map, map2, &hang, &lie);//����������ģ������
				cct_gotoxy(0, 0);
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//��һ������÷�
				MulBlank(map, map2, r, c, hang, lie);//�����������,��հ�
				shining(map, map2, r, c, hang, lie);//�ϲ����֮�������
				cct_gotoxy(0, 4 * r + 3);
				cct_setcursor(CURSOR_INVISIBLE);//�ر������ʾ
				cout << "�ϳ���ɣ��س���/�����������0                         ";
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//�ָ������ʾ
				confirm();//�س������ȷ��
				map2[hang - 'A' + 1][lie + 1] = '0';//���������ɫ�鲻��*
				Drop(map, map2, r, c);//������
				cct_gotoxy(0, 4 * r + 3);
				cct_setcursor(CURSOR_INVISIBLE);//�ر������ʾ
				cout << "����0��ɣ��س���/������������ֵ                        ";
				cct_setcursor(CURSOR_VISIBLE_NORMAL);//�ָ������ʾ
				confirm();//�س������ȷ��
				myrandom(map, map2, find_max(map));//������ֵ
				fill(map, map2, r, c);
				cct_gotoxy(0, 4 * r + 3);
				cct_setcolor(0, 14);
				cct_setcursor(CURSOR_INVISIBLE);//�ر������ʾ
				cout << "���κϳɽ�������C/�������������һ�εĺϳ�       ";
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
			input(&r, &c, &tgt, choice);//��������������
			tgt0 = tgt;
			rand_num(map, r, c);//�����������
			choice56(map, map2, &r, &c, choice);//ѡ��56479
			while(1)
			{
				ret9 = gameend(map, map2, r, c);
				if ( ret9== 0)
					break;
				hang = 'A';
				lie = 0;
				cct_gotoxy(0, r * 4 + 3);
				cout << "��ͷ��/����ƶ����س���/�������ѡ��,Q/�����Ҽ�����";
				while (1)
				{
					ret1 = MouseKeyboard(map, map2, r, c, &hang, &lie, choice);
					if (ret1)//�Ҽ���q����
						break;
					search1(map, map2, &hang, &lie);//������ͬ��*
					cct_gotoxy(0, 4 * r + 4);
					MulLightorDark(map, map2, r, c, hang, lie, 3);//��ֵͬ����
					if (search1(map, map2, &hang, &lie) > 1)//��Χ����ͬ��ֵ
					{
						ret2 = MouseKeyboardAffirm(map, map2, r, c, &hang, &lie);//��¼�Ƿ��������س�
						if (ret2 > 0)//�лس������
						{
							cct_gotoxy(0, 4 * r + 3);
							cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�";
							break;
						}
						else
						{
							MulLightorDark(map, map2, r, c, hang, lie, 2);//��ֵͬ�䰵
						}
					}
					else//��Χû����ֵͬ��MouseKeyboard
					{
						cct_gotoxy(0, 4 * r + 3);
						cct_setcolor(0, 14);
						cout << "��Χ����ֵͬ";
						cct_setcolor();
						cout << "��ͷ��/����ƶ����س���/�������ѡ��";
					}
					if (ret1)
						break;
				}//end of while
				if (ret1)//�Ҽ�����q/Q������С��
					break;
				merge(map, map2, &hang, &lie);//����������ģ������
				cct_gotoxy(0, 0);
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//��һ������÷�
				MulBlank(map, map2, r, c, hang, lie);//�����������,��հ�
				shining(map, map2, r, c, hang, lie);//�ϲ����֮�������
				cct_gotoxy(0, 4 * r + 3);
				
				map2[hang - 'A' + 1][lie + 1] = '0';//���������ɫ�鲻��*
				Drop(map, map2, r, c);//������
				
				myrandom(map, map2, find_max(map));//������ֵ
				fill(map, map2, r, c);
				
				if (find_max(map) == tgt && sum == tgt - tgt0)
				{
					cct_gotoxy(0, 4 * r + 3);
					cct_setcolor(0, 14);
					cout << "�Ѿ��ϳɵ�" << tgt;
					cct_setcolor();
					sum++;//ע����������ȵģ��ϳ�Ŀ���ٱ仯
					tgt++;
					cout << "�����س���/����������������Ŀ�����";
					confirm();
				}
				cct_gotoxy(0, 0);//���ϳ�Ŀ��ı䣬��Ҫ�������
				fen(map, map2, &hang, &lie, &tgt, &zongfen);//��һ������÷�
				
			}//end of while
			if (ret9 == 0)
			{
				cct_gotoxy(0, 4 * r + 3);
				cout << "��Ϸ����                                    ";
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