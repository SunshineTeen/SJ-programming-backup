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

char peek(FILE *fp);

int find_group(FILE *fp, const char *group_name);
int find_item(FILE *fp, const int st, const char *item_name, int *val_p = NULL);
void cpy_info(FILE *fp, const int l, const int r, char cpy[], int &cnt);
void re_output(FILE *fp, char st1[], const int n, char st2[], const int m, const void *item_value = NULL, const enum ITEM_TYPE item_type = TYPE_NULL, const bool add = 0);
void get_value(FILE *fp, const int pos, const void *item_value, const enum ITEM_TYPE item_type);

int group_add(FILE *fp, const char *group_name);
int group_del(FILE *fp, const char *group_name);
int item_add(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_del(FILE *fp, const char *group_name, const char *item_name);
int item_update(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_get_value(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
