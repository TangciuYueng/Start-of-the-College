/* 2151298 ��11 ������ */
#include <iostream>
#include <limits> 
using namespace std;
int zeller(int y, int m, int d);

int zeller(int y, int m, int d)
{
	int w=0,c=0;
	if (m >= 3) {
		c = y/100;
	    y = y - c * 100;//y = y % 100Ҳ�ǿ��Ե� 
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	}
	if (m == 1 || m == 2) {
		y = y - 1;
		c = y / 100;
		y = y - c * 100;//y = y % 100Ҳ�ǿ��Ե� 
		w = y + y / 4 + c / 4 - 2 * c + 13 * (m+12 + 1) / 5 + d - 1;
	}
	/*������������������������������м�Ӹ�
	if(m == 1 || m == 2) 
	{
	m += 12;
	y --;
    }
	*/ 
	if (w >= 0)
		w = w % 7;
	else {
		while (w < 0) {//��w�������������һֱ��7ֱ������Ϊֹ 
			w = w + 7;
		}
		w = w % 7;
	}
	/*Ҳ���Բ���
	w=(w%7+7)%7      ����%7��-1��-6����+7����*/

	return w;
}
int main()
{
	int y, m, d,w;

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "�����������������" << endl;
			cout << "��������[1900-2100]���¡��գ�"<<endl;
			cin >> y >> m >>d;
		}//not int 
		
		if(y||m||d){
			while ( y < 1900 || y>2100 )
		    {
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cout << "��ݲ���ȷ������������" << endl;
			cout << "��������[1900-2100]���¡��գ�"<<endl;
			cin >> y >> m >>d;
		    }//year wrong
		if (y >= 1900 && y <= 2100) {
			while ( m < 1 || m>12)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
				cout << "�·ݲ���ȷ������������" << endl;
				cout << "��������[1900-2100]���¡��գ�"<<endl;
				cin >> y >> m >> d;
			}//month wrong

			if (m >= 1 && m <= 12) {
				if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
						while ( d < 1 || d>31)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 31)
							break;
					}

					if (m == 2) {
						while ( d < 1 || d>29)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 29)
							break;
					}

					if (m == 4 || m == 6 || m == 9 || m == 11) {
						while ( d < 1 || d>30)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 30)
							break;
					}
				}//big year

				if (!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)) {
					if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
						while ( d < 1 || d>31)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 31)
							break;
					}

					if (m == 2) {
						while ( d < 1 || d>28)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 28)
							break;
					}

					if (m == 4 || m == 6 || m == 9 || m == 11) {
						while ( d < 1 || d>30)
						{
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');
							cout << "�ղ���ȷ������������" << endl;
							cout << "��������[1900-2100]���¡��գ�"<<endl;
							cin >> y >> m >> d;
						}//date wrong
						if (d >= 1 && d <= 30)
							break;
					}
				}//small year
			}//month wrong
		}//year right
			
		}
	
			
	}//���ѭ��


	w=zeller(y, m, d);
	
	if (w == 0)
		cout << "������" << endl;
	if (w == 1)
		cout << "����һ" << endl;
	if (w == 2)
		cout << "���ڶ�" << endl;
	if (w == 3)
		cout << "������" << endl;
	if (w == 4)
		cout << "������" << endl;
	if (w == 5)
		cout << "������" << endl;
	if (w == 6)
		cout << "������" << endl;
	return 0;
}
