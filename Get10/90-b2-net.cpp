/* 2151298 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include <string>
#include "90-b2.h"
int game_progress(mto10_net_tools& client, char mapchar[][CE + 2], int r, int c, int map[][CE + 2], char map2[][CE + 2],int choice)
{
	char svrpack[RECVBUF_LEN];	//��Ŵ�Server���յ�������
	char row;
	int col;
	if (choice == 'B' - '0')
		cct_cls();
	while (1) {
		/* -------------------
			Client=>Server
		   ------------------- */
		   /* ���ݷ���˷����ĵ�ͼ������һ�������꣨ĿǰΪ�ֹ�������ʽ����Ҫ��Ϊ�Զ�����ѽ����꣩
			  ��ʾ�����Խ�client.get_map()�ķ���ֵ���Ƶ��ַ������У��ٻ�ԭΪ���Լ��Ķ�ά��������
		   */
		if(choice=='A'-'0')
		    client.print_map(); //��������Ϊʾ�⣬ͼ�ν����в��ܵ��ã�Ҫ�Լ�дת������
		huifu(map2);//map2ȫ����0

		/* ��Ϸ�ѽ������ٶ���*/
		if (client.is_gameover())
			break;

		/*client.get_map()�ķ���ֵ���Ƶ��ַ�������*/
		int i = 1, j = 1, k = 0;
		while ((*(client.get_map() + k) >= '1' && *(client.get_map() + k) <= '9') || (*(client.get_map() + k) >= 'A' && *(client.get_map() + k) <= 'F'))
		{

			mapchar[i][j] = *(client.get_map() + k);
			j++;
			k++;
			if (j > c)//�����������������ͻ���
			{
				i++;
				j = 1;//�б�������
			}
		}
		/*�ַ����鸳ֵ��int����*/
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
		
		/*�ҳ����Ž��row��col*/
		find_best(map, map2, &row, &col, r, c);

		if (choice == 'A' - '0')
		{
			cout << "��������(A-" << (char)(r + 'A' - 1) << ")��(0 - " << c - 1 << ")���� : ";
			cout << row << col;
		}
		
		

		if (row >= 'a' && row <= 'j')
			row -= 32; //�����Сд��תΪ��д
		client.send_coordinate(row, col);
		/*����ѡ����B*/
		if (choice == 'B' - '0')
		{
			choice56(map, map2, &r, &c, 9);//ѡ��56479αͼ�γ�ʼ���
			cct_gotoxy(0, 4 * row + 3);
			cout << "��ǰѡ��" << row << "��" << col << "��               ";
			huifu(map2);//map2ȫ����0
			search1(map, map2, &row, &col);//������ͬ��*
			MulLightorDark(map, map2, r, c, row, col, 3);//��ֵͬ����
			merge(map, map2, &row, &col);//����������ģ������
			MulBlank(map, map2, r, c, row, col);//�����������,��հ�
			shining(map, map2, r, c, row, col);//�ϲ����֮�������
			map2[row - 'A' + 1][col + 1] = '0';//���������ɫ�鲻��*
			Drop(map, map2, r, c);//������
		}
		

		/* -------------------
			Server=>Client
		   ------------------- */
		   /* �ȴ�Server�˵�gameprogress */
		if (client.get_gameprogress_string(svrpack) < 0) {
			return -1;
		}

		/* ��ӡ�� svrpack �����ݣ����д�������Server�˼�������
		   ���� Content �����ݣ��������£�
			"InvalidCoordinate" : �Ƿ�����
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeFailed" : ѡ���������Χ�޿ɺϳ���
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
			"MergeSucceeded" : ���κϳɳɹ�
				GameID		��������ϷID
				Step		��Ŀǰ����
				Score		��Ŀǰ����
				MaxValue	��Ŀǰ�ϳɵ����ֵ
				OldMap		������ѡ�������ĵ�ͼ
				NewMap		������ѡ��������ٴ����ĵ�ͼ
			"GameOver" : ��ͼ�����������Ϸ����
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ
			"GameFinished" : �Ѻϳɵ��������ޣ�16������Ϸ���
				GameID			��������ϷID
				FinalStep		�����ղ���
				FinalScore		�����շ���
				FinalMaxValue	�����պϳɵ����ֵ */

		
				/* ��ӡ�յ���ԭʼ�ַ��� */
		if(choice=='A'-'0')
		    cout << "ServerӦ�� : " << endl << svrpack << endl;
	}//end of while(1)

	return 0;
}
int choiceAB(int map[][CE + 2], char map2[][CE + 2],int tgt,int choice)
{
	const char* my_no = "2151298";		//����ѧ��
	const char* my_pwd = "adbzzzzx1423~!";	//��������

	int wanted_row, wanted_col, wanted_id, wanted_delay;

	cct_cls();//��ս���
	char mapchar[RE + 2][CE + 2];
	/*��ʼ��*/
	for (int i = 0; i < RE + 2; i++)
		for (int j = 0; j < CE + 2; j++)
			mapchar[i][j] = '0';

#if 0 //�������룬�˴���Ϊ #if 0 ���ʾ�������� #else �е����
	wanted_row = 5;			//�˴������޸�Ϊ�����������ʽ
	wanted_col = 5;			//�˴������޸�Ϊ�����������ʽ
	wanted_id = -1;		//idΪ�����������Ϸ��ţ������-1����ʾ���������������[0..2^31-1]���ʾ��̶���ţ���Ź̶�����ÿ�θ����ĳ�ʼ���󼰺���������ͬ��������ԣ�
	wanted_delay = 60 * 1000;	//delayΪ�����ÿ��Ӧ����ʱ�ӣ���λms
#else
	wanted_row = -1;
	wanted_col = -1;
	wanted_id = -1;
	wanted_delay = 60 * 1000;
#endif
	/*������������*/
	input(&wanted_row, &wanted_col, &tgt, choice);

	mto10_net_tools client;

	/* ��client������е�debug���أ�����ʱ�ɴ򿪣���ͼ�ν���ʱ��رգ� */
	bool open = true;
	if (choice == 'B' - '0')
		open = false;
	client.set_debug_switch(open);

	/* ���ӷ����� */
	if (client.connect() < 0) {
		/* ����ʧ����Ϣ����û��debug_switch����ӡ */
		cout << "���ӷ�����ʧ��!" << endl;
		return -1;
	}

	/* ��Server�˷�����֤��Ϣ������ */
	if (client.send_parameter(my_no, '*', my_pwd, wanted_row, wanted_col, wanted_id, wanted_delay) < 0) {
		cout << "������֤��������Ϣʧ��!" << endl;
		return -1;
	}

	/* �ȴ�Server���·���������Ϸ��ʼ��*/
	if (client.wait_for_game_start() < 0) {
		cout << "�ȴ�GameStartʧ��!" << endl;
		return -1;
	}

	/* ��ӡ�ӷ������յ��Ĳ�����������Ϸ�Դ˲���Ϊ׼����������6��6�У�����8��10�У��򱾴���Ϸ��8��10��Ϊ׼��
	   �����ӡ����Ϣ��ͼ�λ������������ȥ�� */
	if (choice == 'A' - '0')
	{
		cout << "������������Ϣ : " << endl;
		cout << "  ���� : " << client.get_row() << endl;
		cout << "  ���� : " << client.get_col() << endl;
		cout << "  ID�� : " << client.get_gameid() << endl;
		cout << "  ��ʱ : " << client.get_delay() / 1000.0 << "(��)" << endl;
		cout << "  ��ͼ : " << client.get_map() << endl;

	}
	/* ��ͼ���е�ֵΪ1-9��A-F���ֱ��ʾ1-15��ֵ��
		   ���磺
			 ������������=3
			 ������������=4
			 ���������ص�ͼ=123A85CF2123
		   ���ʾ��ǰ��ͼΪ(����������ʾ��)
			 1 2 3  10
			 8 5 12 15
			 2 1 2  3
			��Ϸ����������Ϊ���ϳɵ�16�����κοɺϳ�Ԫ�� */

			/* ������Ϸ��������
			   1���յ�Server��GameOver�򷵻�0����Ϸ����
			   2���������������-1��������Ϣ����ȷ�ȴ��󣩣��������ٴ��ظ�	*/
	if (game_progress(client, mapchar, wanted_row, wanted_col, map, map2, choice) < 0) {
		client.close();
		return -1;
	}

	client.close();
	if (choice == 'B' - '0')
		cct_gotoxy(0, 4 * wanted_row + 3);
	cout << "��Ϸ����" << endl;
	to_be_continued();
}
