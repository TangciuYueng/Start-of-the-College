/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double number;
    double a,b,c,d,e,f,g,h,i,j,k,l,m;
	cout << "请输入[0-100亿)之间的数字:" << endl;
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
    

    cout << "大写结果是:" << endl;  
    if (!(a == 0 && b == 0)) {         //判断亿级别
        if (a >= 1 && a <= 9) {        //十亿
            if (a == 1)
                cout << "壹";
            else if (a == 2)
                cout << "贰";
            else if (a == 3)
                cout << "叁";
            else if (a == 4)
                cout << "肆";
            else if (a == 5)
                cout << "伍";
            else if (a == 6)
                cout << "陆";
            else if (a == 7)
                cout << "柒";
            else if (a == 8)
                cout << "捌";
            else if (a == 9)
                cout << "玖";
            cout << "拾";
        }
        if (b >= 1 && b <= 9) {       //亿
            if (b == 1)
                cout << "壹";
            else if (b == 2)
                cout << "贰";
            else if (b == 3)
                cout << "叁";
            else if (b == 4)
                cout << "肆";
            else if (b == 5)
                cout << "伍";
            else if (b == 6)
                cout << "陆";
            else if (b == 7)
                cout << "柒";
            else if (b == 8)
                cout << "捌";
            else if (b == 9)
                cout << "玖";
            
        }
        cout << "亿";
    }
    
    if (!(c == 0 && d == 0 && e == 0 && f == 0)) {  //万级别
        if (c == 0 && d == 0 && e == 0 && f != 0) {  //0001 case1 
            if (a != 0 || b != 0)
                cout << "零";
            if (f >= 1 && f <= 9) {
                if (f == 1)
                    cout << "壹";
                else if (f == 2)
                    cout << "贰";
                else if (f == 3)
                    cout << "叁";
                else if (f == 4)
                    cout << "肆";
                else if (f == 5)
                    cout << "伍";
                else if (f == 6)
                    cout << "陆";
                else if (f == 7)
                    cout << "柒";
                else if (f == 8)
                    cout << "捌";
                else if (f == 9)
                    cout << "玖";
                cout << "万";
            }
        }
        if (c == 0 && d == 0 && e != 0 && f == 0) {  //0010 case2
            if (a != 0 || b != 0)
            cout << "零";
            if (e >= 1 && e <= 9) {
                if (e == 1)
                    cout << "壹";
                else if (e == 2)
                    cout << "贰";
                else if (e == 3)
                    cout << "叁";
                else if (e == 4)
                    cout << "肆";
                else if (e == 5)
                    cout << "伍";
                else if (e == 6)
                    cout << "陆";
                else if (e == 7)
                    cout << "柒";
                else if (e == 8)
                    cout << "捌";
                else if (e == 9)
                    cout << "玖";
                cout << "拾万";
            }
        }
        if (c == 0 && d != 0 && e == 0 && f == 0) {  //0100 case3
            if (a != 0 || b != 0)
            cout << "零";
            if (d >= 1 && d <= 9) {
                if (d == 1)
                    cout << "壹";
                else if (d == 2)
                    cout << "贰";
                else if (d == 3)
                    cout << "叁";
                else if (d == 4)
                    cout << "肆";
                else if (d == 5)
                    cout << "伍";
                else if (d == 6)
                    cout << "陆";
                else if (d == 7)
                    cout << "柒";
                else if (d == 8)
                    cout << "捌";
                else if (d == 9)
                    cout << "玖";
                cout << "佰万";
            }
        }
        if (c != 0 && d == 0 && e == 0 && f == 0) { //1000 case4
            if(c==1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟万";
        }
        if (c == 0 && d == 0 && e != 0 && f != 0) {  //0011 case5
            if (a != 0 || b != 0)
            cout << "零";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾";

            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c == 0 && d != 0 && e == 0 && f != 0) { //0101 case6
            if (a != 0 || b != 0)
            cout << "零";     
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰零";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c != 0 && d == 0 && e == 0 && f != 0) {//1001 case7
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟零";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c == 0 && d != 0 && e != 0 && f == 0) {//0110 case8
            if (a != 0 || b != 0)
            cout << "零";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾万";
        }
        if (c != 0 && d == 0 && e != 0 && f == 0) {//1010 case9 
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟零";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾万";
        }
        if (c != 0 && d != 0 && e == 0 && f == 0) {//1100 case10
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰万";
        }
        if (c != 0 && d != 0 && e != 0 && f == 0) { //1110 case11
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾万";
        }
        if (c != 0 && d != 0 && e == 0 && f != 0) {//1101 case12
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰零";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c != 0 && d == 0 && e != 0 && f != 0) {//1011 case13
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟零";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c == 0 && d != 0 && e != 0 && f != 0) {//0111 case14
            if (a != 0 || b != 0)
            cout << "零";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
        if (c != 0 && d != 0 && e != 0 && f != 0) {//1111 case15
            if (c == 1)
                cout << "壹";
            else if (c == 2)
                cout << "贰";
            else if (c == 3)
                cout << "叁";
            else if (c == 4)
                cout << "肆";
            else if (c == 5)
                cout << "伍";
            else if (c == 6)
                cout << "陆";
            else if (c == 7)
                cout << "柒";
            else if (c == 8)
                cout << "捌";
            else if (c == 9)
                cout << "玖";
            cout << "仟";
            if (d == 1)
                cout << "壹";
            else if (d == 2)
                cout << "贰";
            else if (d == 3)
                cout << "叁";
            else if (d == 4)
                cout << "肆";
            else if (d == 5)
                cout << "伍";
            else if (d == 6)
                cout << "陆";
            else if (d == 7)
                cout << "柒";
            else if (d == 8)
                cout << "捌";
            else if (d == 9)
                cout << "玖";
            cout << "佰";
            if (e == 1)
                cout << "壹";
            else if (e == 2)
                cout << "贰";
            else if (e == 3)
                cout << "叁";
            else if (e == 4)
                cout << "肆";
            else if (e == 5)
                cout << "伍";
            else if (e == 6)
                cout << "陆";
            else if (e == 7)
                cout << "柒";
            else if (e == 8)
                cout << "捌";
            else if (e == 9)
                cout << "玖";
            cout << "拾";
            if (f == 1)
                cout << "壹";
            else if (f == 2)
                cout << "贰";
            else if (f == 3)
                cout << "叁";
            else if (f == 4)
                cout << "肆";
            else if (f == 5)
                cout << "伍";
            else if (f == 6)
                cout << "陆";
            else if (f == 7)
                cout << "柒";
            else if (f == 8)
                cout << "捌";
            else if (f == 9)
                cout << "玖";
            cout << "万";
        }
    }
    
    if (!(g == 0 && h == 0 && i == 0 && j == 0)) {  //元级别
        if (g == 0 && h == 0 && i == 0 && j != 0) {//0001 case1
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (j >= 1 && j <= 9) {
                if (j == 1)
                    cout << "壹";
                else if (j == 2)
                    cout << "贰";
                else if (j == 3)
                    cout << "叁";
                else if (j == 4)
                    cout << "肆";
                else if (j == 5)
                    cout << "伍";
                else if (j == 6)
                    cout << "陆";
                else if (j == 7)
                    cout << "柒";
                else if (j == 8)
                    cout << "捌";
                else if (j == 9)
                    cout << "玖";
                cout << "圆";
            }
        }
        if (g == 0 && h == 0 && i != 0 && j == 0) {//0010 case2
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (i >= 1 && i <= 9) {
                if (i == 1)
                    cout << "壹";
                else if (i == 2)
                    cout << "贰";
                else if (i == 3)
                    cout << "叁";
                else if (i == 4)
                    cout << "肆";
                else if (i == 5)
                    cout << "伍";
                else if (i == 6)
                    cout << "陆";
                else if (i == 7)
                    cout << "柒";
                else if (i == 8)
                    cout << "捌";
                else if (i == 9)
                    cout << "玖";
                cout << "拾圆";
            }
        }
        if (g == 0 && h != 0 && i == 0 && j == 0) {//0100 case3
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (h >= 1 && h <= 9) {
                if (h == 1)
                    cout << "壹";
                else if (h == 2)
                    cout << "贰";
                else if (h == 3)
                    cout << "叁";
                else if (h == 4)
                    cout << "肆";
                else if (h == 5)
                    cout << "伍";
                else if (h == 6)
                    cout << "陆";
                else if (h == 7)
                    cout << "柒";
                else if (h == 8)
                    cout << "捌";
                else if (h == 9)
                    cout << "玖";
                cout << "佰圆";
            }
        }
        if (g != 0 && h == 0 && i == 0 && j == 0) {//1000 case4
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟圆";
        }
        if (g == 0 && h == 0 && i != 0 && j != 0) {   //0011 case5
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾";

            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g == 0 && h != 0 && i == 0 && j != 0) {//0101 case6
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰零";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g != 0 && h == 0 && i == 0 && j != 0) {//1001 case7
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟零";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g == 0 && h != 0 && i != 0 && j == 0) {//0110 case8
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾圆";
        }
        if (g != 0 && h == 0 && i != 0 && j == 0) {//1010 case9
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟零";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾圆";
        }
        if (g != 0 && h != 0 && i == 0 && j == 0) {//1100 case10
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰圆";
        }
        if (g != 0 && h != 0 && i != 0 && j == 0) {//1110 case11
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾圆";
        }
        if (g != 0 && h != 0 && i == 0 && j != 0) {//1101 case12
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰零";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g != 0 && h == 0 && i != 0 && j != 0) {//1011 case13
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟零";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g == 0 && h != 0 && i != 0 && j != 0) {//0111 case14
            if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0)
            cout << "零";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
        if (g != 0 && h != 0 && i != 0 && j != 0) {//1111 case15
            if (g == 1)
                cout << "壹";
            else if (g == 2)
                cout << "贰";
            else if (g == 3)
                cout << "叁";
            else if (g == 4)
                cout << "肆";
            else if (g == 5)
                cout << "伍";
            else if (g == 6)
                cout << "陆";
            else if (g == 7)
                cout << "柒";
            else if (g == 8)
                cout << "捌";
            else if (g == 9)
                cout << "玖";
            cout << "仟";
            if (h == 1)
                cout << "壹";
            else if (h == 2)
                cout << "贰";
            else if (h == 3)
                cout << "叁";
            else if (h == 4)
                cout << "肆";
            else if (h == 5)
                cout << "伍";
            else if (h == 6)
                cout << "陆";
            else if (h == 7)
                cout << "柒";
            else if (h == 8)
                cout << "捌";
            else if (h == 9)
                cout << "玖";
            cout << "佰";
            if (i == 1)
                cout << "壹";
            else if (i == 2)
                cout << "贰";
            else if (i == 3)
                cout << "叁";
            else if (i == 4)
                cout << "肆";
            else if (i == 5)
                cout << "伍";
            else if (i == 6)
                cout << "陆";
            else if (i == 7)
                cout << "柒";
            else if (i == 8)
                cout << "捌";
            else if (i == 9)
                cout << "玖";
            cout << "拾";
            if (j == 1)
                cout << "壹";
            else if (j == 2)
                cout << "贰";
            else if (j == 3)
                cout << "叁";
            else if (j == 4)
                cout << "肆";
            else if (j == 5)
                cout << "伍";
            else if (j == 6)
                cout << "陆";
            else if (j == 7)
                cout << "柒";
            else if (j == 8)
                cout << "捌";
            else if (j == 9)
                cout << "玖";
            cout << "圆";
        }
    }
    else if (a && b && c && d && e && f && g && h && i && j && k)
    cout << "圆";
    


        if (l != 0 && m != 0) {
            if (l == 1)
                cout << "壹";
            else if (l == 2)
                cout << "贰";
            else if (l == 3)
                cout << "叁";
            else if (l == 4)
                cout << "肆";
            else if (l == 5)
                cout << "伍";
            else if (l == 6)
                cout << "陆";
            else if (l == 7)
                cout << "柒";
            else if (l == 8)
                cout << "捌";
            else if (l == 9)
                cout << "玖";
            cout << "角";
            if (m == 1)
                cout << "壹";
            else if (m == 2)
                cout << "贰";
            else if (m == 3)
                cout << "叁";
            else if (m == 4)
                cout << "肆";
            else if (m == 5)
                cout << "伍";
            else if (m == 6)
                cout << "陆";
            else if (m == 7)
                cout << "柒";
            else if (m == 8)
                cout << "捌";
            else if (m == 9)
                cout << "玖";
            cout << "分";
        }

        if (l == 0 && m != 0) {
            if (a || b || c || d || e || f || g || h || i || j )
            cout << "零" ;
            if (m == 1)
                cout << "壹";
            else if (m == 2)
                cout << "贰";
            else if (m == 3)
                cout << "叁";
            else if (m == 4)
                cout << "肆";
            else if (m == 5)
                cout << "伍";
            else if (m == 6)
                cout << "陆";
            else if (m == 7)
                cout << "柒";
            else if (m == 8)
                cout << "捌";
            else if (m == 9)
                cout << "玖";
            cout << "分";
        }
        if (l != 0 && m == 0) {
            if (l == 1)
                cout << "壹";
            else if (l == 2)
                cout << "贰";
            else if (l == 3)
                cout << "叁";
            else if (l == 4)
                cout << "肆";
            else if (l == 5)
                cout << "伍";
            else if (l == 6)
                cout << "陆";
            else if (l == 7)
                cout << "柒";
            else if (l == 8)
                cout << "捌";
            else if (l == 9)
                cout << "玖";
            cout << "角";
        }

    if (m == 0)
        cout << "整\n";
 
    return 0;
}
