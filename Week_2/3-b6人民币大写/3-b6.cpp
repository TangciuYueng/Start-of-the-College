/* 2151298 ��11 ������ */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double number;
    double a,b,c,d,e,f,g,h,i,j,k,l,m;
	cout << "������[0-100��)֮�������:" << endl;
    cin >> number;
    a = int(number / 1000000000);
    b = int((number - a * 1000000000) / 100000000);
    c = int((number - a * 1000000000 - b * 100000000) / 10000000);
    d = int((number - a * 1000000000 - b * 100000000 - c * 10000000) / 1000000);
    e = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000) / 100000);
    f = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000) / 10000);
    g = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000) / 1000);
    h = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000) / 100);
    i = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100) / 10);
    j = int((number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100 - i * 10) / 1);
    k = number - a * 1000000000 - b * 100000000 - c * 10000000 - d * 1000000 - e * 100000 - f * 10000 - g * 1000 - h * 100 - i * 10 - j * 1;
    l = int(k * 100.001 / 10);
    m = int(k * 100.001 - l * 10);
    

    cout << "��д�����:" << endl;  
    if (!(a == 0 && b == 0)) {         //�ж��ڼ���
        if (a >= 1 && a <= 9) {        //ʮ��
            if (a == 1)
                cout << "Ҽ";
            else if (a == 2)
                cout << "��";
            else if (a == 3)
                cout << "��";
            else if (a == 4)
                cout << "��";
            else if (a == 5)
                cout << "��";
            else if (a == 6)
                cout << "½";
            else if (a == 7)
                cout << "��";
            else if (a == 8)
                cout << "��";
            else if (a == 9)
                cout << "��";
            cout << "ʰ";
        }
        if (b >= 1 && b <= 9) {       //��
            if (b == 1)
                cout << "Ҽ";
            else if (b == 2)
                cout << "��";
            else if (b == 3)
                cout << "��";
            else if (b == 4)
                cout << "��";
            else if (b == 5)
                cout << "��";
            else if (b == 6)
                cout << "½";
            else if (b == 7)
                cout << "��";
            else if (b == 8)
                cout << "��";
            else if (b == 9)
                cout << "��";
            
        }
        cout << "��";
    }
    
    if (!(c == 0 && d == 0 && e == 0 && f == 0)) {  //�򼶱�
        if (c == 0 && d == 0 && e == 0 && f != 0) {  //0001 case1 
            if (a != 0 || b != 0)
                cout << "��";
            if (f >= 1 && f <= 9) {
                if (f == 1)
                    cout << "Ҽ";
                else if (f == 2)
                    cout << "��";
                else if (f == 3)
                    cout << "��";
                else if (f == 4)
                    cout << "��";
                else if (f == 5)
                    cout << "��";
                else if (f == 6)
                    cout << "½";
                else if (f == 7)
                    cout << "��";
                else if (f == 8)
                    cout << "��";
                else if (f == 9)
                    cout << "��";
                cout << "��";
            }
        }
        if (c == 0 && d == 0 && e != 0 && f == 0) {  //0010 case2
            if (a != 0 || b != 0)
            cout << "��";
            if (e >= 1 && e <= 9) {
                if (e == 1)
                    cout << "Ҽ";
                else if (e == 2)
                    cout << "��";
                else if (e == 3)
                    cout << "��";
                else if (e == 4)
                    cout << "��";
                else if (e == 5)
                    cout << "��";
                else if (e == 6)
                    cout << "½";
                else if (e == 7)
                    cout << "��";
                else if (e == 8)
                    cout << "��";
                else if (e == 9)
                    cout << "��";
                cout << "ʰ��";
            }
        }
        if (c == 0 && d != 0 && e == 0 && f == 0) {  //0100 case3
            if (a != 0 || b != 0)
            cout << "��";
            if (d >= 1 && d <= 9) {
                if (d == 1)
                    cout << "Ҽ";
                else if (d == 2)
                    cout << "��";
                else if (d == 3)
                    cout << "��";
                else if (d == 4)
                    cout << "��";
                else if (d == 5)
                    cout << "��";
                else if (d == 6)
                    cout << "½";
                else if (d == 7)
                    cout << "��";
                else if (d == 8)
                    cout << "��";
                else if (d == 9)
                    cout << "��";
                cout << "����";
            }
        }
        if (c != 0 && d == 0 && e == 0 && f == 0) { //1000 case4
            if(c==1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ��";
        }
        if (c == 0 && d == 0 && e != 0 && f != 0) {  //0011 case5
            if (a != 0 || b != 0)
            cout << "��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ";

            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c == 0 && d != 0 && e == 0 && f != 0) { //0101 case6
            if (a != 0 || b != 0)
            cout << "��";     
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "����";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c != 0 && d == 0 && e == 0 && f != 0) {//1001 case7
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ��";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c == 0 && d != 0 && e != 0 && f == 0) {//0110 case8
            if (a != 0 || b != 0)
            cout << "��";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ��";
        }
        if (c != 0 && d == 0 && e != 0 && f == 0) {//1010 case9 
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ��";
        }
        if (c != 0 && d != 0 && e == 0 && f == 0) {//1100 case10
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "����";
        }
        if (c != 0 && d != 0 && e != 0 && f == 0) { //1110 case11
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ��";
        }
        if (c != 0 && d != 0 && e == 0 && f != 0) {//1101 case12
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "����";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c != 0 && d == 0 && e != 0 && f != 0) {//1011 case13
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c == 0 && d != 0 && e != 0 && f != 0) {//0111 case14
            if (a != 0 || b != 0)
            cout << "��";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
        if (c != 0 && d != 0 && e != 0 && f != 0) {//1111 case15
            if (c == 1)
                cout << "Ҽ";
            else if (c == 2)
                cout << "��";
            else if (c == 3)
                cout << "��";
            else if (c == 4)
                cout << "��";
            else if (c == 5)
                cout << "��";
            else if (c == 6)
                cout << "½";
            else if (c == 7)
                cout << "��";
            else if (c == 8)
                cout << "��";
            else if (c == 9)
                cout << "��";
            cout << "Ǫ";
            if (d == 1)
                cout << "Ҽ";
            else if (d == 2)
                cout << "��";
            else if (d == 3)
                cout << "��";
            else if (d == 4)
                cout << "��";
            else if (d == 5)
                cout << "��";
            else if (d == 6)
                cout << "½";
            else if (d == 7)
                cout << "��";
            else if (d == 8)
                cout << "��";
            else if (d == 9)
                cout << "��";
            cout << "��";
            if (e == 1)
                cout << "Ҽ";
            else if (e == 2)
                cout << "��";
            else if (e == 3)
                cout << "��";
            else if (e == 4)
                cout << "��";
            else if (e == 5)
                cout << "��";
            else if (e == 6)
                cout << "½";
            else if (e == 7)
                cout << "��";
            else if (e == 8)
                cout << "��";
            else if (e == 9)
                cout << "��";
            cout << "ʰ";
            if (f == 1)
                cout << "Ҽ";
            else if (f == 2)
                cout << "��";
            else if (f == 3)
                cout << "��";
            else if (f == 4)
                cout << "��";
            else if (f == 5)
                cout << "��";
            else if (f == 6)
                cout << "½";
            else if (f == 7)
                cout << "��";
            else if (f == 8)
                cout << "��";
            else if (f == 9)
                cout << "��";
            cout << "��";
        }
    }
    
    if (!(g == 0 && h == 0 && i == 0 && j == 0)) {  //Ԫ����
        if (g == 0 && h == 0 && i == 0 && j != 0) {//0001 case1
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (j >= 1 && j <= 9) {
                if (j == 1)
                    cout << "Ҽ";
                else if (j == 2)
                    cout << "��";
                else if (j == 3)
                    cout << "��";
                else if (j == 4)
                    cout << "��";
                else if (j == 5)
                    cout << "��";
                else if (j == 6)
                    cout << "½";
                else if (j == 7)
                    cout << "��";
                else if (j == 8)
                    cout << "��";
                else if (j == 9)
                    cout << "��";
                cout << "Բ";
            }
        }
        if (g == 0 && h == 0 && i != 0 && j == 0) {//0010 case2
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (i >= 1 && i <= 9) {
                if (i == 1)
                    cout << "Ҽ";
                else if (i == 2)
                    cout << "��";
                else if (i == 3)
                    cout << "��";
                else if (i == 4)
                    cout << "��";
                else if (i == 5)
                    cout << "��";
                else if (i == 6)
                    cout << "½";
                else if (i == 7)
                    cout << "��";
                else if (i == 8)
                    cout << "��";
                else if (i == 9)
                    cout << "��";
                cout << "ʰԲ";
            }
        }
        if (g == 0 && h != 0 && i == 0 && j == 0) {//0100 case3
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (h >= 1 && h <= 9) {
                if (h == 1)
                    cout << "Ҽ";
                else if (h == 2)
                    cout << "��";
                else if (h == 3)
                    cout << "��";
                else if (h == 4)
                    cout << "��";
                else if (h == 5)
                    cout << "��";
                else if (h == 6)
                    cout << "½";
                else if (h == 7)
                    cout << "��";
                else if (h == 8)
                    cout << "��";
                else if (h == 9)
                    cout << "��";
                cout << "��Բ";
            }
        }
        if (g != 0 && h == 0 && i == 0 && j == 0) {//1000 case4
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "ǪԲ";
        }
        if (g == 0 && h == 0 && i != 0 && j != 0) {   //0011 case5
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰ";

            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g == 0 && h != 0 && i == 0 && j != 0) {//0101 case6
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "����";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g != 0 && h == 0 && i == 0 && j != 0) {//1001 case7
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ��";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g == 0 && h != 0 && i != 0 && j == 0) {//0110 case8
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰԲ";
        }
        if (g != 0 && h == 0 && i != 0 && j == 0) {//1010 case9
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰԲ";
        }
        if (g != 0 && h != 0 && i == 0 && j == 0) {//1100 case10
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "��Բ";
        }
        if (g != 0 && h != 0 && i != 0 && j == 0) {//1110 case11
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰԲ";
        }
        if (g != 0 && h != 0 && i == 0 && j != 0) {//1101 case12
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "����";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g != 0 && h == 0 && i != 0 && j != 0) {//1011 case13
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰ";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g == 0 && h != 0 && i != 0 && j != 0) {//0111 case14
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "��";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰ";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
        if (g != 0 && h != 0 && i != 0 && j != 0) {//1111 case15
            if (g == 1)
                cout << "Ҽ";
            else if (g == 2)
                cout << "��";
            else if (g == 3)
                cout << "��";
            else if (g == 4)
                cout << "��";
            else if (g == 5)
                cout << "��";
            else if (g == 6)
                cout << "½";
            else if (g == 7)
                cout << "��";
            else if (g == 8)
                cout << "��";
            else if (g == 9)
                cout << "��";
            cout << "Ǫ";
            if (h == 1)
                cout << "Ҽ";
            else if (h == 2)
                cout << "��";
            else if (h == 3)
                cout << "��";
            else if (h == 4)
                cout << "��";
            else if (h == 5)
                cout << "��";
            else if (h == 6)
                cout << "½";
            else if (h == 7)
                cout << "��";
            else if (h == 8)
                cout << "��";
            else if (h == 9)
                cout << "��";
            cout << "��";
            if (i == 1)
                cout << "Ҽ";
            else if (i == 2)
                cout << "��";
            else if (i == 3)
                cout << "��";
            else if (i == 4)
                cout << "��";
            else if (i == 5)
                cout << "��";
            else if (i == 6)
                cout << "½";
            else if (i == 7)
                cout << "��";
            else if (i == 8)
                cout << "��";
            else if (i == 9)
                cout << "��";
            cout << "ʰ";
            if (j == 1)
                cout << "Ҽ";
            else if (j == 2)
                cout << "��";
            else if (j == 3)
                cout << "��";
            else if (j == 4)
                cout << "��";
            else if (j == 5)
                cout << "��";
            else if (j == 6)
                cout << "½";
            else if (j == 7)
                cout << "��";
            else if (j == 8)
                cout << "��";
            else if (j == 9)
                cout << "��";
            cout << "Բ";
        }
    }
    else if (a && b && c && d && e && f && g && h && i && j && k)
    cout << "Բ";
    


        if (l != 0 && m != 0) {
            if (l == 1)
                cout << "Ҽ";
            else if (l == 2)
                cout << "��";
            else if (l == 3)
                cout << "��";
            else if (l == 4)
                cout << "��";
            else if (l == 5)
                cout << "��";
            else if (l == 6)
                cout << "½";
            else if (l == 7)
                cout << "��";
            else if (l == 8)
                cout << "��";
            else if (l == 9)
                cout << "��";
            cout << "��";
            if (m == 1)
                cout << "Ҽ";
            else if (m == 2)
                cout << "��";
            else if (m == 3)
                cout << "��";
            else if (m == 4)
                cout << "��";
            else if (m == 5)
                cout << "��";
            else if (m == 6)
                cout << "½";
            else if (m == 7)
                cout << "��";
            else if (m == 8)
                cout << "��";
            else if (m == 9)
                cout << "��";
            cout << "��";
        }

        if (l == 0 && m != 0) {
            if (a || b || c || d || e || f || g || h || i || j )
            cout << "��" ;
            if (m == 1)
                cout << "Ҽ";
            else if (m == 2)
                cout << "��";
            else if (m == 3)
                cout << "��";
            else if (m == 4)
                cout << "��";
            else if (m == 5)
                cout << "��";
            else if (m == 6)
                cout << "½";
            else if (m == 7)
                cout << "��";
            else if (m == 8)
                cout << "��";
            else if (m == 9)
                cout << "��";
            cout << "��";
        }
        if (l != 0 && m == 0) {
            if (l == 1)
                cout << "Ҽ";
            else if (l == 2)
                cout << "��";
            else if (l == 3)
                cout << "��";
            else if (l == 4)
                cout << "��";
            else if (l == 5)
                cout << "��";
            else if (l == 6)
                cout << "½";
            else if (l == 7)
                cout << "��";
            else if (l == 8)
                cout << "��";
            else if (l == 9)
                cout << "��";
            cout << "��";
        }

    if (m == 0)
        cout << "��\n";
 
    return 0;
}
