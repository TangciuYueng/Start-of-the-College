/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include <string>
#include "90-b2.h"
int game_progress(mto10_net_tools& client, char mapchar[][CE + 2], int r, int c, int map[][CE + 2], char map2[][CE + 2],int choice)
{
	char svrpack[RECVBUF_LEN];	//存放从Server端收到的数据
	char row;
	int col;
	if (choice == 'B' - '0')
		cct_cls();
	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* 根据服务端发来的地图，返回一个解坐标（目前为手工输入形式，需要改为自动求最佳解坐标）
			  提示：可以将client.get_map()的返回值复制到字符数组中，再还原为你自己的二维数组后求解
		   */
		if(choice=='A'-'0')
		    client.print_map(); //本函数仅为示意，图形界面中不能调用，要自己写转换函数
		huifu(map2);//map2全部置0

		/* 游戏已结束则不再读键*/
		if (client.is_gameover())
			break;

		/*client.get_map()的返回值复制到字符数组中*/
		int i = 1, j = 1, k = 0;
		while ((*(client.get_map() + k) >= '1' && *(client.get_map() + k) <= '9') || (*(client.get_map() + k) >= 'A' && *(client.get_map() + k) <= 'F'))
		{

			mapchar[i][j] = *(client.get_map() + k);
			j++;
			k++;
			if (j > c)//若果超过了列数，就换行
			{
				i++;
				j = 1;//列标重新来
			}
		}
		/*字符数组赋值给int数组*/
		for (i = 1; i <= r; i++)
		{
			for (j = 1; j <= c; j++)
			{
				if (mapchar[i][j] >= 'A' && mapchar[i][j] <= 'F')
					map[i][j] = mapchar[i][j] - 87;
				else
					map[i][j] = mapchar[i][j] - '0';
			}
		}
		
		/*找出最优解的row与col*/
		find_best(map, map2, &row, &col, r, c);

		if (choice == 'A' - '0')
		{
			cout << "请输入行(A-" << (char)(r + 'A' - 1) << ")列(0 - " << c - 1 << ")坐标 : ";
			cout << row << col;
		}
		
		

		if (row >= 'a' && row <= 'j')
			row -= 32; //如果是小写则转为大写
		client.send_coordinate(row, col);
		/*现在选择了B*/
		if (choice == 'B' - '0')
		{
			choice56(map, map2, &r, &c, 9);//选项56479伪图形初始输出
			cct_gotoxy(0, 4 * row + 3);
			cout << "当前选择" << row << "行" << col << "列               ";
			huifu(map2);//map2全部置0
			search1(map, map2, &row, &col);//相邻相同置*
			MulLightorDark(map, map2, r, c, row, col, 3);//相同值变亮
			merge(map, map2, &row, &col);//非输入坐标的，变成零
			MulBlank(map, map2, r, c, row, col);//非输入坐标的,变空白
			shining(map, map2, r, c, row, col);//合并完成之后的闪动
			map2[row - 'A' + 1][col + 1] = '0';//输入坐标的色块不置*
			Drop(map, map2, r, c);//块下落
		}
		

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* 等待Server端的gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* 打印出 svrpack 的内容，自行处理，并向Server端继续反馈
		   根据 Content 的内容，解释如下：
			"InvalidCoordinate" : 非法坐标
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeFailed" : 选择的坐标周围无可合成项
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
			"MergeSucceeded" : 本次合成成功
				GameID		：本次游戏ID
				Step		：目前步数
				Score		：目前分数
				MaxValue	：目前合成的最大值
				OldMap		：消除选择坐标后的地图
				NewMap		：消除选择坐标后再次填充的地图
			"GameOver" : 地图上无消除项，游戏结束
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值
			"GameFinished" : 已合成到设置上限（16），游戏完成
				GameID			：本次游戏ID
				FinalStep		：最终步数
				FinalScore		：最终分数
				FinalMaxValue	：最终合成的最大值 */

		
				/* 打印收到的原始字符串 */
		if(choice=='A'-'0')
		    cout << "Server应答 : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}
int choiceAB(int map[][CE + 2], char map2[][CE + 2],int tgt,int choice)
{
	const char* my_no = "2151298";		//本人学号
	const char* my_pwd = "adbzzzzx1423~!";	//本人密码

	int wanted_row, wanted_col, wanted_id, wanted_delay;

	cct_cls();//清空界面
	char mapchar[RE + 2][CE + 2];
	/*初始化*/
	for (int i = 0; i < RE + 2; i++)
		for (int j = 0; j < CE + 2; j++)
			mapchar[i][j] = '0';

#if 0 //条件编译，此处改为 #if 0 则表示启用下面 #else 中的语句
	wanted_row = 5;			//此处按需修改为键盘输入等形式
	wanted_col = 5;			//此处按需修改为键盘输入等形式
	wanted_id = -1;		//id为本次请求的游戏序号，如果置-1，表示服务器随机产生，[0..2^31-1]则表示想固定序号（序号固定，则每次给出的初始矩阵及后续填充均相同，方便调试）
	wanted_delay = 60 * 1000;	//delay为请求的每步应答的最长时延，单位ms
#else
	wanted_row = -1;
	wanted_col = -1;
	wanted_id = -1;
	wanted_delay = 60 * 1000;
#endif
	/*键盘输入行列*/
	input(&wanted_row, &wanted_col, &tgt, choice);

	mto10_net_tools client;

	/* 打开client类对象中的debug开关（调试时可打开，到图形界面时需关闭） */
	bool open = true;
	if (choice == 'B' - '0')
		open = false;
	client.set_debug_switch(open);

	/* 连接服务器 */
	if (client.connect() < 0) {
		/* 连接失败信息，有没有debug_switch都打印 */
		cout << "连接服务器失败!" << endl;
		return -1;
	}

	/* 向Server端发送认证信息及参数 */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
		cout << "发送认证及参数信息失败!" << endl;
		return -1;
	}

	/* 等待Server端下发参数（游戏开始）*/
	if (client.wait_for_game_start() < 0) {
		cout << "等待GameStart失败!" << endl;
		return -1;
	}

	/* 打印从服务器收到的参数，本次游戏以此参数为准（例：发送6行6列，返回8行10列，则本次游戏以8行10列为准）
	   下面打印的信息，图形化界面可以自行去除 */
	if (choice == 'A' - '0')
	{
		cout << "服务器返回信息 : " << endl;
		cout << "  行数 : " << client.get_row() << endl;
		cout << "  列数 : " << client.get_col() << endl;
		cout << "  ID号 : " << client.get_gameid() << endl;
		cout << "  超时 : " << client.get_delay() / 1000.0 << "(秒)" << endl;
		cout << "  地图 : " << client.get_map() << endl;

	}
	/* 地图串中的值为1-9，A-F，分别表示1-15的值，
		   例如：
			 服务器返回行=3
			 服务器返回列=4
			 服务器返回地图=123A85CF2123
		   则表示当前地图为(本例仅仅是示例)
			 1 2 3  10
			 8 5 12 15
			 2 1 2  3
			游戏结束的条件为：合成到16或无任何可合成元素 */

			/* 进入游戏交互环节
			   1、收到Server的GameOver则返回0，游戏结束
			   2、其它错误均返回-1（报文信息不正确等错误），重连，再次重复	*/
	if (game_progress(client, mapchar, wanted_row, wanted_col, map, map2, choice) < 0) {
		client.close();
		return -1;
	}

	client.close();
	if (choice == 'B' - '0')
		cct_gotoxy(0, 4 * wanted_row + 3);
	cout << "游戏结束" << endl;
	to_be_continued();
}
