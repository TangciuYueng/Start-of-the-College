#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> 
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	int a, b1, s1, g1, b2, s2, g2, b3, s3, g3, count = 0;
	for (b1 = 1; b1 <= 5; b1++) {//����ѭ����һ��ѭ����ö࣬�жϴ����ٵöࡣ��λ����಻��5
		for (s1 = 1; s1 <= 9; s1++) {
			if (s1 == b1 || s1 == 0)//�ֽ����жϣ����Ծ������������жϴ���//improve3
				continue;
			for (g1 = 1; g1 <= 9; g1++) {
				if (g1 == s1 || g1 == b1 || g1 == 0)
					continue;
				for (b2 = b1 + 1; b2 <= 8; b2++) {//b2Ҫ��b1�󣡣���ע������9�ù��ˣ���
					if (b2 == g1 || b2 == s1 || b2 == b1 || b2 == 0)
						continue;
					for (s2 = 1; s2 <= 9; s2++) {
						if (s2 == b2 || s2 == g1 || s2 == s1 || s2 == b1 || s2 == 0)
							continue;
						for (g2 = 1; g2 <= 9; g2++) {
							if (g2 == s2 || g2 == b2 || g2 == g1 || g2 == s1 || g2 == b1 || g2 == 0)
								continue;
							a = 1953 - b1 * 100 - s1 * 10 - g1 - b2 * 100 - s2 * 10 - g2;//�������ѭ������
							b3 = a / 100;
							s3 = a % 100 / 10;
							g3 = a % 10;
							if (b3 == g2 || b3 == s2 || b3 == b2 || b3 == g1 || b3 == s1 || b3 == b1 || b3 == 0 ||
								s3 == b3 || s3 == g2 || s3 == s2 || s3 == b2 || s3 == g1 || s3 == s1 || s3 == b1 || s3 == 0 ||
								g3 == s3 || g3 == b3 || g3 == g2 || g3 == s2 || g3 == b2 || g3 == g1 || g3 == s1 || g3 == b1 || g3 == 0)
								continue;
							if ((b1 * 100 + s1 * 10 + g1) < (b2 * 100 + s2 * 10 + g2) &&
								(b2 * 100 + s2 * 10 + g2) < a&&
								a>123&&a<999)
							{
								cout << b1 << s1 << g1 << "+"
									<< b2 << s2 << g2 << "+"
									<<a<< "=1953" << endl;
								count++;
							}
								

						}
					}
				}
			}
		}
	}

	cout << count++ << endl;


	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}