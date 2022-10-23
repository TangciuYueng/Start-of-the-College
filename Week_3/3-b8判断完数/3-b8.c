/* 2151298 信11 杨滕超 */
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, sum=0;
	for (i = 2; i <= 1000; i++) {
		for (j = 1; j<i; j++) {  //找因数和
			if (i % j == 0) {
				sum = sum + j;
			}
        }
		
		if(sum==i)  //判断是否为完数
			printf("%d,its factors are 1",i);
		for (j = 2; j < i; j++) {  //输出因数
			
			if (i % j == 0&&sum==i) {
				
				printf(",%d", j);
				
			}

		}
		if (i == sum)
			printf("\n");
		sum = 0;
	}
	/*反正1肯定是有的 之后就是逗号+数字的重复*/
	return 0;
}