/* 2151298 信11 杨滕超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
				strncat(result,&chnstr[num*2],2);//注意汉字一般两个字节，&取第一个的地址，拼接两个字节
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			strncat(result, &chnstr[num*2],2);
			break;
		default:
			printf( "error");
			break;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double number;
	int a, b, c, d, e, f, g, h, i, j, l, m;
	double k;//注意k是小数部分，需要浮点型 
	int flag = 0;
	const char shi[] = "拾";
	const char bai[] = "佰";
	const char qian[] = "仟";
	const char wan[] = "万";
	const char yi[] = "亿";
	const char yuan[] = "圆";
	const char jiao[] = "角";
	const char fen[] = "分";
	const char zheng[] = "整";
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf",&number);
	a = (int)(number / 1000000000);
	b = (int)((number - (double)a * 1000000000) / 100000000);
	c = (int)((number - (double)a * 1000000000 - (double)b * 100000000) / 10000000);
	d = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000) / 1000000);
	e = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000) / 100000);
	f = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000) / 10000);
	g = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000) / 1000);
	h = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000) / 100);
	i = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100) / 10);
	j = (int)((number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100 - (double)i * 10) / 1);
	k = (number - (double)a * 1000000000 - (double)b * 100000000 - (double)c * 10000000 - (double)d * 1000000 - (double)e * 100000 - (double)f * 10000 - (double)g * 1000 - (double)h * 100 - (double)i * 10 - (double)j * 1);
	l = (int)(k * 100.001 / 10);
	m = (int)(k * 100.001 - (double)l * 10);
	daxie(a, 0);//亿级别
	if (a != 0)
		strcat(result, shi);
	daxie(b, 0);
	if (b || a)
		strcat(result, yi);

	//万级别
	if ((b || a) && (d || e || f))
		flag = 1;
	else
		flag = 0;
	daxie(c, flag);
	if (c != 0)
		strcat(result, qian);


	if (c && (e || f) && flag == 0)//前面至少有一个不是零且后面有一个不是零
		flag = 1;
	else
		flag = 0;
	daxie(d, flag);
	if (d != 0)
		strcat(result, bai);

	if ((c || d) && f && flag == 0)
		flag = 1;
	else
		flag = 0;
	daxie(e, flag);
	if (e != 0)
		strcat(result, shi);


	daxie(f, 0);
	if (f || e || d || c)
		strcat(result, wan);

	flag = 0;
	//圆级别
	if ((b || a || c || d || e || f) && (h || i || j))
		flag = 1;
	else
		flag = 0;
	daxie(g, flag);
	if (g != 0)
		strcat(result, qian);

	if (g && (i || j) && flag == 0)//前面至少有一个不是零且后面有一个不是零
		flag = 1;
	else
		flag = 0;
	daxie(h, flag);
	if (h != 0)
		strcat(result,bai);

	if ((g || h) && j && flag == 0)
		flag = 1;
	else
		flag = 0;
	daxie(i, flag);

	if (i != 0)
		strcat(result, shi);

	if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !l && !m)
		flag = 1;

	daxie(j, flag);
	//判断圆的输出：全部都是零or整数位有东西
	if (a || b || c || d || e || f || g || h || i || j)
		strcat(result, yuan);

	else if (!a && !b && !c && !d && !e && !f && !g && !h && !i && !j && !l && !m)
		strcat(result, yuan);

	//小数级别
	flag = 0;
	if (m && (a || b || c || d || e || f || g || h || i || j))//前面有东西，后面必有一东西
		flag = 1;
	daxie(l, flag);
	if (l != 0)
		strcat(result, jiao);


	daxie(m, 0);//分的这个零都不用输出的 
	if (m != 0)
		strcat(result, fen);


	if (m == 0)
		strcat(result, zheng);
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}