/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, i = 0;
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
														printf( "No.");
														if (i < 10)
															printf( "  %d",i);
														else if (i >= 10 && i <= 99)
															printf(" %d",i);
														else
															printf("%d",i);
														printf(" : %d+%d+%d=1953\n",a,b,c);

													}
				}
			}
		}
	}
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
