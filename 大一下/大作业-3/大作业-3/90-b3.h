/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Min(a,b) ((a)<(b)?(a):(b))
#define FFLUSH while(getchar()!='\n')

#define base_zone 8

#define CLOCK 0
#define ALARM 1

#define Mechanical 0
#define Mechanical_Y 120
#define Mechanical_zone_Y 100
#define Digital 1
#define Digital_Y 110
#define Digital_zone_Y 85

#define Normal 1
#define LED 2
#define Abnormal 3

#define Hour 14
#define Minute 24
#define Second 30

#define TLE -1

#define IntSize sizeof(int)

using namespace std;

const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
const double pi = acos(-1.0);
const double eps = 1e-6;
const int N = 300;

const char *const Dig[] =
{
	"０","１","２","３","４","５","６","７","８","９"
};
const char *const Zone[] =
{
	"Ｌｏｎｄｏｎ", "Ｐａｒｉｓ" ,"Ｋｙｉｖ","Ｍｏｓｃｏｗ","Ｋａｂｕｌ","Ｍｕｍｂａｉ",
	"Ｙａｎｇｏｎ","Ｖｉｅｎｔｉａｎｅ","Ｂｅｉｊｉｎｇ","Ｔｏｋｙｏ","Ｂｒｉｓｂａｎｅ","Ｓｙｄｎｅｙ",
	"Ａｎａｄｙｒ",	"Ｗｅｌｌｉｎｇｔｏｎ","Ｈｏｎｏｌｕｌｕ","Ａｎｃｈｒｏａｇｅ","Ｖａｎｃｏｕｖｅｒ","Ｐｈｏｅｎｉｘ",
	"Ｈｏｕｓｔｏｎ","Ｎｅｗ　Ｙｏｒｋ","Ｓａｎｔｉａｇｏ","Ｂｒａｓｉｌｉａ","ＵＴＣ－２","ＵＴＣ－１"
};
const char *const Mode[] =
{
	"仅一次","每周一","每周二","每周三","每周四","每周五","每周六","每周日",
	"每　日","工作日","休息日"
};
const char *const Week[] =
{
	"星期日","星期一","星期二","星期三","星期四","星期五","星期六"
};
const char *const iniFile = ".\\1652228\\alarm_setting.ini";

struct Point
{
	int x;
	int y;
};

struct Alarm
{
	int h;
	int m;
	int mode;
	Alarm *nxt;
	Alarm *pre;
};

void setfont();

void get_alarm_ini(Alarm *&head);
void refresh_ini(Alarm *head);

int get_key(const HANDLE hin, int time_limit = 500);

bool check_time(Alarm *const al, const int w, const int h, const int m);
void Alarm_Clock_Rang();
////////////////////////////////////////////////////////////////////////////
void output_str(const unsigned char *str, const  int mode);
void output_dig(int d, const int mode);
int output_ch(const unsigned char word[], const int mode);
////////////////////////////////////////////////////////////////////////////
void clock_work(Alarm *head, int &option, int &mode);

void output_mechanical_clock(const Point O, Point pre[3][N], const int time_zone, bool &day_change);
void Draw_Circle(const Point O);
void Draw_Hand(const Point O, Point last[3][N], double ang, int op);

void output_digital_clock(const int time_zone, bool &day_change);

void output_help(const int Y);
void output_time_zone(const int Y, const int zone);
void output_day_info(const int mode, const int time_zone, const int X, const int Y);

bool check_alarm(Alarm *head, const int time_zone);
/////////////////////////////////////////////////////////////////////////////
void alarm_work(Alarm *head, int &option);
bool alarm_set(Alarm *const head, Alarm *&cur);

void output_alarm(Alarm *cur, const Alarm *head);
void output_alarm(Alarm *cur, const int choose);
void output_alarm_menu();
void output_alarm_setting();
