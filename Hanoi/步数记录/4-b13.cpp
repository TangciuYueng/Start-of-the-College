/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
using namespace std;/*!!!!!�Ľ��Ĵ��������C�ĸ�ʽ����5-b6-2*/

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int i = 0;
    if (n == 1)
    {
        if (1 + i < 10)
            cout << "    " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if(1 + i >= 10 && 1 + i < 100)
            cout << "   " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if (1 + i >= 100 && 1 + i < 1000)
            cout << "  " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else if (1 + i >= 1000 && 1 + i < 10000)
            cout << " " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        else 
            cout<< ++i << ":  " << n << "# " << src << "-->" << dst << endl;
    }

    else
    {
        hanoi(n - 1, src, dst, tmp);
        if (1 + i < 10)
        {
            if (n >= 10)
                cout << "    " << ++i << ": " << n << "# " << src << "-->" << dst << endl;

            else
                cout << "    " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;

        }
        else if (1 + i >= 10 && 1 + i < 100)
        {
            if (n >= 10)
                cout << "   " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << "   " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;

        }
        else if (1 + i >= 100 && 1 + i < 1000)
        {
            if (n >= 10)
                cout << "  " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << "  " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        }
        else if (1 + i >= 1000 && 1 + i < 10000)
        {
            if (n >= 10)
                cout << " " << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << " " << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        }
        else
        {
            if (n >= 10)
                cout << ++i << ": " << n << "# " << src << "-->" << dst << endl;
            else
                cout << ++i << ":  " << n << "# " << src << "-->" << dst << endl;
        }

        hanoi(n - 1, tmp, src, dst);
    }

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int f;
    char qishi, mubiao, zhongjian;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> f;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
            cin >> f;
        }
        if (f >= 1 && f <= 16)
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> qishi;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "��������ʼ��(A-C)" << endl;
            cin >> qishi;
        }
        if (qishi == 'a' || qishi == 'A' || qishi == 'b' || qishi == 'B' || qishi == 'c' || qishi == 'C')
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> mubiao;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            cout << "������Ŀ����(A-C)" << endl;
            cin >> mubiao;
        }
        while (mubiao == qishi)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            if (mubiao >= 97)
                mubiao = (char)(mubiao - 32);
            if (qishi >= 97)
                qishi = (char)(qishi - 32);
            cout << "Ŀ����(" << mubiao << ")��������ʼ��(" << qishi << ")��ͬ" << endl;
            cin >> mubiao;
        }
        if (mubiao == 'a' || mubiao == 'A' || mubiao == 'b' || mubiao == 'B' || mubiao == 'c' || mubiao == 'C')
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');

    cout << "�ƶ�����Ϊ:" << endl;

    if (mubiao >= 97)
        mubiao = (char)(mubiao - 32);
    if (qishi >= 97)
        qishi = (char)(qishi - 32);

    if (qishi != 'A' && mubiao != 'A')
        zhongjian = 'A';
    else if (qishi != 'B' && mubiao != 'B')
        zhongjian = 'B';
    else
        zhongjian = 'C';

    hanoi(f, qishi, zhongjian, mubiao);

    return 0;

}
