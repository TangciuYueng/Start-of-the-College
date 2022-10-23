#pragma once
/* 2151298 ÐÅ11 Ñîëø³¬ */
#define CE 10
#define RE 8
void to_be_continued();
void input(int* rp, int* cp, int* tgtp,int choice);
void input2(int* rp, int* cp,char* hang, int* lie);
char input3(char* hang, int* lie);
void input456(int num);
int count(char map2[][CE + 2]);
void output(int map[][CE + 2], char map2[][CE + 2], int r, int c, int select = 0);
void rand_num(int map[][CE+2], int r, int c);
int search1(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie);
void search2(int map[][CE + 2], char map2[][CE + 2], int i, int j, int same);
void merge(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie);
void fen(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie, int* tgtp, int* zongfen);
void drop(int map[][CE + 2], char map2[][CE + 2],int hang);
void myrandom(int map[][CE + 2], char map2[][CE + 2], int max);
int find_max(int map[][CE + 2]);
void choice56(int map[][CE + 2], char map2[][CE + 2], int* r, int* c,int choice);
void output56(int map[][CE + 2], char map2[][CE + 2], int r, int c,int choice);
int MouseKeyboard(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie, int choice);
void TurnLightorDark(int map[][CE + 2], char map2[][CE + 2], int x, int y, int loop, int r, int c);
int MouseKeyboardAffirm(int map[][CE + 2], char map2[][CE + 2], int r, int c, char* hang, int* lie);
void MulLightorDark(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie, int loop);
void MulBlank(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie);
void shining(int map[][CE + 2], char map2[][CE + 2], int r, int c, char hang, int lie);
int confirm();
int confirmC();
void Drop_Once(int map[][CE + 2], char map2[][CE + 2], int r, int c, int i, int j);
void Drop(int map[][CE + 2], char map2[][CE + 2], int r, int c);
void fill(int map[][CE + 2], char map2[][CE + 2], int r, int c);
int gameend(int map[][CE + 2], char map2[][CE + 2], int r, int c);
void outputtt(int map[][CE + 2], char map2[][CE + 2]);
void huifu(char map2[][CE + 2]);
void find_best(int map[][CE + 2], char map2[][CE + 2], char* hang, int* lie, int r, int c);
int choiceAB(int map[][CE + 2], char map2[][CE + 2], int tgt, int choice);
//int game_progress(mto10_net_tools& client, char mapchar[][CE + 2], int r, int c, int map[][CE + 2], char map2[][CE + 2]);