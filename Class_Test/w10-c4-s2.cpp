/* 2151298 ��11 ������ */
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ���
   3��������������������
   4�������������������κ���ʽ��ѭ��
   ---------------------------------------------------------------------
*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ݹ鷨��a+aa+...+aaaaa
  ���������
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2�������������κ���ʽ��ѭ��
			3�������������һ���ľ�̬�ֲ�����
***************************************************************************/
int calc(int a, int n)
{
	if (n == 1)
		return a;
	else
		return a * n + calc(a, n - 1) * 10;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int a, n;

	cout << "������a��n��ֵ" << endl;
	cin >> a >> n;	//�������������
	cout << "S=" << calc(a, n) << endl;

	return 0;
}