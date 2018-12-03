//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define WAIT while(_getch()!='\r')

using namespace std;

const char file_name[] = "KanColle.ini";
const int Maxm = 10 * 1024;

enum ITEM_TYPE { TYPE_INT, TYPE_DOUBLE, TYPE_STRING, TYPE_CHARACTER, TYPE_NULL };

int find_group(fstream &fp, const char *group_name);
int find_item(fstream &fp, const int st, const char *item_name, int *val_p = NULL);
void cpy_info(fstream &fp, const int l, const int r, char cpy[], int &cnt);
void re_output(fstream &fp, char st1[], const int n, char st2[], const int m, const void *item_value = NULL, const enum ITEM_TYPE item_type = TYPE_NULL, const bool add = 0);
void get_value(fstream &fp, const int pos, const void *item_value, const enum ITEM_TYPE item_type);

int group_add(fstream &fp, const char *group_name);
int group_del(fstream &fp, const char *group_name);
int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_del(fstream &fp, const char *group_name, const char *item_name);
int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_get_value(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
