/* 2151298 信11 杨滕超 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> 
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, i=0;
	double i1, i2, i3, i4, i5, i6, i7, i8, i9, h;
	for (a = 100; a < 999; a++) {
		for (b = 100; b < 999; b++) {
			for (c = 100; c < 999; c++) {
				if (a + b + c == 1953 && a < b && b < c) {
					h = ((double)a * 1000000 + (double)b * 1000 + c);
					i1 = (int)(h / 100000000);
					i2 = (int)((h - i1 * 100000000) / 10000000);
					i3 = (int)((h - i1 * 100000000 - i2 * 10000000) / 1000000);
					i4 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000) / 100000);
					i5 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000 - i4 * 100000) / 10000);
					i6 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000 - i4 * 100000 - i5 * 10000) / 1000);
					i7 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000 - i4 * 100000 - i5 * 10000 - i6 * 1000) / 100);
					i8 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000 - i4 * 100000 - i5 * 10000 - i6 * 1000 - i7 * 100) / 10);
					i9 = (int)((h - i1 * 100000000 - i2 * 10000000 - i3 * 1000000 - i4 * 100000 - i5 * 10000 - i6 * 1000 - i7 * 100 - i8 * 10) / 1);
					if (i1 != 0 && i2 != 0 && i3 != 0 && i4 != 0 && i5 != 0 && i6 != 0 && i7 != 0 && i8 != 0 && i9 != 0)
						if (i1 != i2 && i1 != i3 && i1 != i4 && i1 != i5 && i1 != i6 && i1 != i7 && i1 != i8 && i1 != i9)
							if (i2 != i3 && i2 != i4 && i2 != i5 && i2 != i6 && i2 != i7 && i2 != i8 && i2 != i9)
								if (i3 != i4 && i3 != i5 && i3 != i6 && i3 != i7 && i3 != i8 && i3 != i9)
									if (i4 != i5 && i4 != i6 && i4 != i7 && i4 != i8 && i4 != i9)
										if (i5 != i6 && i5 != i7 && i5 != i8 && i5 != i9)
											if (i6 != i7 && i6 != i8 && i6 != i9)
												if (i7 != i8 && i7 != i9)
													if (i8 != i9) {
														i++;
														cout << "No.";
														if (i < 10)
															cout << "  " << i;
														else if (i >= 10 && i <= 99)
															cout << " " << i;
														else
															cout << i;
														cout << " : " << a << "+" << b << "+" << c << "=1953" << endl;

													}
			    }
		    }
		}
	}
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}/*
 一重循环：a=123456789；a<987654321；a++
 之后分解九个位数字
 之后判断各不相同，且不是零（如果有零或相等，就 continue)
 接着判断等于1953
 之后从小到大顺序输出，基本型60s左右（循环八亿多次挑出540）
 改进1：分解之后即刻判断,改进后25s
 改进2：a<598764321(1953使得第一个最大只能是5),15s左右
 改进3：不是++了是一次+10

 三重循环：基本30s（六亿多次挑出540个）
 改进1：内循环中分解后立刻判断15s左右
 改进2：在外层循环中不要都进到内循环，在中层外层判断，1s左右
 改进3：同上0.7s
 改进4：改变百位的初值和终止(123到598)，并保证a<b<c:b=a+1;b<=(1953-a)/2  c=1953-a-b  剩下c的判断要是>1000 就continue 0.35s

 九重循环（约四亿多次）
 改进1：里面八层立即判断
 改进2：改进百位的初值和终值
 改进3：改成六重（c=1953-前面两个百位数）

 奥数法、、、

 同一个程序，cmd窗口字体影响运行速度
 相同算法，cout和printf的差别，printf居然更快，但cout有安全输入检查更好
 相同算法，有无输出，发现拖慢速度的是输出
 不同编译器
 同一个编译器，不同编译配置
 */
