/* 2151298 ��11 ������ */
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, sum=0;
	for (i = 2; i <= 1000; i++) {
		for (j = 1; j<i; j++) {  //��������
			if (i % j == 0) {
				sum = sum + j;
			}
        }
		
		if(sum==i)  //�ж��Ƿ�Ϊ����
			printf("%d,its factors are 1",i);
		for (j = 2; j < i; j++) {  //�������
			
			if (i % j == 0&&sum==i) {
				
				printf(",%d", j);
				
			}

		}
		if (i == sum)
			printf("\n");
		sum = 0;
	}
	/*����1�϶����е� ֮����Ƕ���+���ֵ��ظ�*/
	return 0;
}