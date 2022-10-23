/* 2151298 ĞÅ11 Ñîëø³¬ */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double number;
    double a,b,c,d,e,f,g,h,i,j,k,l,m;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
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
    

    cout << "´óĞ´½á¹ûÊÇ:" << endl;  
    if (!(a == 0 && b == 0)) {         //ÅĞ¶ÏÒÚ¼¶±ğ
        if (a >= 1 && a <= 9) {        //Ê®ÒÚ
            if (a == 1)
                cout << "Ò¼";
            else if (a == 2)
                cout << "·¡";
            else if (a == 3)
                cout << "Èş";
            else if (a == 4)
                cout << "ËÁ";
            else if (a == 5)
                cout << "Îé";
            else if (a == 6)
                cout << "Â½";
            else if (a == 7)
                cout << "Æâ";
            else if (a == 8)
                cout << "°Æ";
            else if (a == 9)
                cout << "¾Á";
            cout << "Ê°";
        }
        if (b >= 1 && b <= 9) {       //ÒÚ
            if (b == 1)
                cout << "Ò¼";
            else if (b == 2)
                cout << "·¡";
            else if (b == 3)
                cout << "Èş";
            else if (b == 4)
                cout << "ËÁ";
            else if (b == 5)
                cout << "Îé";
            else if (b == 6)
                cout << "Â½";
            else if (b == 7)
                cout << "Æâ";
            else if (b == 8)
                cout << "°Æ";
            else if (b == 9)
                cout << "¾Á";
            
        }
        cout << "ÒÚ";
    }
    
    if (!(c == 0 && d == 0 && e == 0 && f == 0)) {  //Íò¼¶±ğ
        if (c == 0 && d == 0 && e == 0 && f != 0) {  //0001 case1 
            if (a != 0 || b != 0)
                cout << "Áã";
            if (f >= 1 && f <= 9) {
                if (f == 1)
                    cout << "Ò¼";
                else if (f == 2)
                    cout << "·¡";
                else if (f == 3)
                    cout << "Èş";
                else if (f == 4)
                    cout << "ËÁ";
                else if (f == 5)
                    cout << "Îé";
                else if (f == 6)
                    cout << "Â½";
                else if (f == 7)
                    cout << "Æâ";
                else if (f == 8)
                    cout << "°Æ";
                else if (f == 9)
                    cout << "¾Á";
                cout << "Íò";
            }
        }
        if (c == 0 && d == 0 && e != 0 && f == 0) {  //0010 case2
            if (a != 0 || b != 0)
            cout << "Áã";
            if (e >= 1 && e <= 9) {
                if (e == 1)
                    cout << "Ò¼";
                else if (e == 2)
                    cout << "·¡";
                else if (e == 3)
                    cout << "Èş";
                else if (e == 4)
                    cout << "ËÁ";
                else if (e == 5)
                    cout << "Îé";
                else if (e == 6)
                    cout << "Â½";
                else if (e == 7)
                    cout << "Æâ";
                else if (e == 8)
                    cout << "°Æ";
                else if (e == 9)
                    cout << "¾Á";
                cout << "Ê°Íò";
            }
        }
        if (c == 0 && d != 0 && e == 0 && f == 0) {  //0100 case3
            if (a != 0 || b != 0)
            cout << "Áã";
            if (d >= 1 && d <= 9) {
                if (d == 1)
                    cout << "Ò¼";
                else if (d == 2)
                    cout << "·¡";
                else if (d == 3)
                    cout << "Èş";
                else if (d == 4)
                    cout << "ËÁ";
                else if (d == 5)
                    cout << "Îé";
                else if (d == 6)
                    cout << "Â½";
                else if (d == 7)
                    cout << "Æâ";
                else if (d == 8)
                    cout << "°Æ";
                else if (d == 9)
                    cout << "¾Á";
                cout << "°ÛÍò";
            }
        }
        if (c != 0 && d == 0 && e == 0 && f == 0) { //1000 case4
            if(c==1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "ÇªÍò";
        }
        if (c == 0 && d == 0 && e != 0 && f != 0) {  //0011 case5
            if (a != 0 || b != 0)
            cout << "Áã";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°";

            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c == 0 && d != 0 && e == 0 && f != 0) { //0101 case6
            if (a != 0 || b != 0)
            cout << "Áã";     
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°ÛÁã";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c != 0 && d == 0 && e == 0 && f != 0) {//1001 case7
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c == 0 && d != 0 && e != 0 && f == 0) {//0110 case8
            if (a != 0 || b != 0)
            cout << "Áã";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°Û";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°Íò";
        }
        if (c != 0 && d == 0 && e != 0 && f == 0) {//1010 case9 
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°Íò";
        }
        if (c != 0 && d != 0 && e == 0 && f == 0) {//1100 case10
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "Çª";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°ÛÍò";
        }
        if (c != 0 && d != 0 && e != 0 && f == 0) { //1110 case11
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "Çª";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°Û";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°Íò";
        }
        if (c != 0 && d != 0 && e == 0 && f != 0) {//1101 case12
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "Çª";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°ÛÁã";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c != 0 && d == 0 && e != 0 && f != 0) {//1011 case13
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c == 0 && d != 0 && e != 0 && f != 0) {//0111 case14
            if (a != 0 || b != 0)
            cout << "Áã";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°Û";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
        if (c != 0 && d != 0 && e != 0 && f != 0) {//1111 case15
            if (c == 1)
                cout << "Ò¼";
            else if (c == 2)
                cout << "·¡";
            else if (c == 3)
                cout << "Èş";
            else if (c == 4)
                cout << "ËÁ";
            else if (c == 5)
                cout << "Îé";
            else if (c == 6)
                cout << "Â½";
            else if (c == 7)
                cout << "Æâ";
            else if (c == 8)
                cout << "°Æ";
            else if (c == 9)
                cout << "¾Á";
            cout << "Çª";
            if (d == 1)
                cout << "Ò¼";
            else if (d == 2)
                cout << "·¡";
            else if (d == 3)
                cout << "Èş";
            else if (d == 4)
                cout << "ËÁ";
            else if (d == 5)
                cout << "Îé";
            else if (d == 6)
                cout << "Â½";
            else if (d == 7)
                cout << "Æâ";
            else if (d == 8)
                cout << "°Æ";
            else if (d == 9)
                cout << "¾Á";
            cout << "°Û";
            if (e == 1)
                cout << "Ò¼";
            else if (e == 2)
                cout << "·¡";
            else if (e == 3)
                cout << "Èş";
            else if (e == 4)
                cout << "ËÁ";
            else if (e == 5)
                cout << "Îé";
            else if (e == 6)
                cout << "Â½";
            else if (e == 7)
                cout << "Æâ";
            else if (e == 8)
                cout << "°Æ";
            else if (e == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "Íò";
        }
    }
    
    if (!(g == 0 && h == 0 && i == 0 && j == 0)) {  //Ôª¼¶±ğ
        if (g == 0 && h == 0 && i == 0 && j != 0) {//0001 case1
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (j >= 1 && j <= 9) {
                if (j == 1)
                    cout << "Ò¼";
                else if (j == 2)
                    cout << "·¡";
                else if (j == 3)
                    cout << "Èş";
                else if (j == 4)
                    cout << "ËÁ";
                else if (j == 5)
                    cout << "Îé";
                else if (j == 6)
                    cout << "Â½";
                else if (j == 7)
                    cout << "Æâ";
                else if (j == 8)
                    cout << "°Æ";
                else if (j == 9)
                    cout << "¾Á";
                cout << "Ô²";
            }
        }
        if (g == 0 && h == 0 && i != 0 && j == 0) {//0010 case2
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (i >= 1 && i <= 9) {
                if (i == 1)
                    cout << "Ò¼";
                else if (i == 2)
                    cout << "·¡";
                else if (i == 3)
                    cout << "Èş";
                else if (i == 4)
                    cout << "ËÁ";
                else if (i == 5)
                    cout << "Îé";
                else if (i == 6)
                    cout << "Â½";
                else if (i == 7)
                    cout << "Æâ";
                else if (i == 8)
                    cout << "°Æ";
                else if (i == 9)
                    cout << "¾Á";
                cout << "Ê°Ô²";
            }
        }
        if (g == 0 && h != 0 && i == 0 && j == 0) {//0100 case3
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (h >= 1 && h <= 9) {
                if (h == 1)
                    cout << "Ò¼";
                else if (h == 2)
                    cout << "·¡";
                else if (h == 3)
                    cout << "Èş";
                else if (h == 4)
                    cout << "ËÁ";
                else if (h == 5)
                    cout << "Îé";
                else if (h == 6)
                    cout << "Â½";
                else if (h == 7)
                    cout << "Æâ";
                else if (h == 8)
                    cout << "°Æ";
                else if (h == 9)
                    cout << "¾Á";
                cout << "°ÛÔ²";
            }
        }
        if (g != 0 && h == 0 && i == 0 && j == 0) {//1000 case4
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "ÇªÔ²";
        }
        if (g == 0 && h == 0 && i != 0 && j != 0) {   //0011 case5
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°";

            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g == 0 && h != 0 && i == 0 && j != 0) {//0101 case6
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°ÛÁã";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g != 0 && h == 0 && i == 0 && j != 0) {//1001 case7
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g == 0 && h != 0 && i != 0 && j == 0) {//0110 case8
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°Û";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°Ô²";
        }
        if (g != 0 && h == 0 && i != 0 && j == 0) {//1010 case9
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°Ô²";
        }
        if (g != 0 && h != 0 && i == 0 && j == 0) {//1100 case10
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "Çª";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°ÛÔ²";
        }
        if (g != 0 && h != 0 && i != 0 && j == 0) {//1110 case11
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "Çª";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°Û";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°Ô²";
        }
        if (g != 0 && h != 0 && i == 0 && j != 0) {//1101 case12
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "Çª";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°ÛÁã";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g != 0 && h == 0 && i != 0 && j != 0) {//1011 case13
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "ÇªÁã";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g == 0 && h != 0 && i != 0 && j != 0) {//0111 case14
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "Áã";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°Û";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
        if (g != 0 && h != 0 && i != 0 && j != 0) {//1111 case15
            if (g == 1)
                cout << "Ò¼";
            else if (g == 2)
                cout << "·¡";
            else if (g == 3)
                cout << "Èş";
            else if (g == 4)
                cout << "ËÁ";
            else if (g == 5)
                cout << "Îé";
            else if (g == 6)
                cout << "Â½";
            else if (g == 7)
                cout << "Æâ";
            else if (g == 8)
                cout << "°Æ";
            else if (g == 9)
                cout << "¾Á";
            cout << "Çª";
            if (h == 1)
                cout << "Ò¼";
            else if (h == 2)
                cout << "·¡";
            else if (h == 3)
                cout << "Èş";
            else if (h == 4)
                cout << "ËÁ";
            else if (h == 5)
                cout << "Îé";
            else if (h == 6)
                cout << "Â½";
            else if (h == 7)
                cout << "Æâ";
            else if (h == 8)
                cout << "°Æ";
            else if (h == 9)
                cout << "¾Á";
            cout << "°Û";
            if (i == 1)
                cout << "Ò¼";
            else if (i == 2)
                cout << "·¡";
            else if (i == 3)
                cout << "Èş";
            else if (i == 4)
                cout << "ËÁ";
            else if (i == 5)
                cout << "Îé";
            else if (i == 6)
                cout << "Â½";
            else if (i == 7)
                cout << "Æâ";
            else if (i == 8)
                cout << "°Æ";
            else if (i == 9)
                cout << "¾Á";
            cout << "Ê°";
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "Ô²";
        }
    }
    else if (a && b && c && d && e && f && g && h && i && j && k)
    cout << "Ô²";
    


        if (l != 0 && m != 0) {
            if (l == 1)
                cout << "Ò¼";
            else if (l == 2)
                cout << "·¡";
            else if (l == 3)
                cout << "Èş";
            else if (l == 4)
                cout << "ËÁ";
            else if (l == 5)
                cout << "Îé";
            else if (l == 6)
                cout << "Â½";
            else if (l == 7)
                cout << "Æâ";
            else if (l == 8)
                cout << "°Æ";
            else if (l == 9)
                cout << "¾Á";
            cout << "½Ç";
            if (m == 1)
                cout << "Ò¼";
            else if (m == 2)
                cout << "·¡";
            else if (m == 3)
                cout << "Èş";
            else if (m == 4)
                cout << "ËÁ";
            else if (m == 5)
                cout << "Îé";
            else if (m == 6)
                cout << "Â½";
            else if (m == 7)
                cout << "Æâ";
            else if (m == 8)
                cout << "°Æ";
            else if (m == 9)
                cout << "¾Á";
            cout << "·Ö";
        }

        if (l == 0 && m != 0) {
            if (a || b || c || d || e || f || g || h || i || j )
            cout << "Áã" ;
            if (m == 1)
                cout << "Ò¼";
            else if (m == 2)
                cout << "·¡";
            else if (m == 3)
                cout << "Èş";
            else if (m == 4)
                cout << "ËÁ";
            else if (m == 5)
                cout << "Îé";
            else if (m == 6)
                cout << "Â½";
            else if (m == 7)
                cout << "Æâ";
            else if (m == 8)
                cout << "°Æ";
            else if (m == 9)
                cout << "¾Á";
            cout << "·Ö";
        }
        if (l != 0 && m == 0) {
            if (l == 1)
                cout << "Ò¼";
            else if (l == 2)
                cout << "·¡";
            else if (l == 3)
                cout << "Èş";
            else if (l == 4)
                cout << "ËÁ";
            else if (l == 5)
                cout << "Îé";
            else if (l == 6)
                cout << "Â½";
            else if (l == 7)
                cout << "Æâ";
            else if (l == 8)
                cout << "°Æ";
            else if (l == 9)
                cout << "¾Á";
            cout << "½Ç";
        }

    if (m == 0)
        cout << "Õû\n";
 
    return 0;
}
