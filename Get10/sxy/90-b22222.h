/* –≈11 …≥–¶“Ú 2153396 */
#pragma once

#define N 10
#define M 12

void shuru(char n);
char menu();
void shuzu(int x0, int y0, char n, int mb, bool bo = 1);
void zhaoshu1(char zb[], char sz[N][M], char ch, int x0, int y0, char n, int mb);
void shangsai(char zb[],char sz[N][M], char jl[N][M],char ch, int x0, int y0, char n,int mb, bool bo = 1);
void zhaoshu2(char zb[], char sz[N][M], char ch, int x0, int y0, int x, int y, char jl[N][M]);
void shuchuxh(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb);
void heyi(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb);
void shuru2(char zb[], char sz[N][M], int x0, int y0, char n, int mb, bool boo = 1);
void defen(char jl[N][M], char ch, char n, int mb, int x0, int y0);
void shangsai2(char zb[], char sz[N][M], char jl[N][M], char ch, int x0, int y0, char n, int mb, bool bo = 0);
void xialuo(char sz[N][M], char jl[N][M], int x0, int y0);
void tianchong(char sz[N][M], char jl[N][M], int mb, int x0, int y0, char n,char ch);
void huakuai(int x0, int y0);
void huakuai2(int x0, int y0,char n);
void shuzu2(char zb[], char sz[N][M], int x0, int y0, char n, int mb);
void xuan(char sz[N][M],int x0, int y0, char n, int a, int b);
void biansai(int X, int Y, char sz[N][M], int se);
