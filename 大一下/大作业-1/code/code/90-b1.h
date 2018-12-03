/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')
#define Min(a,b) ((a)<(b)?(a):(b))

const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
const int Maxn = 12;
const int Maxm = 12;
const int Maxx = Maxn*Maxm;
const int Maxc = 9;
const int col[10] = { 0,9,10,11,12,13,14,7,5,6 }; //color of array

struct Point
{
	int x, y;
};

void output_score(int &tot, const int n, const int m, bool(*flag)[Maxm]);
void output_cmd_change(int step, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
void output_cmd_alter(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
void output_cmd_reset(int(*map)[Maxm], const int n, const int m, const int mode);
void output_cmd_base(int(*map)[Maxm], const int n, const int m);
void output_array(const int step, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);

template <typename T>
void Swap(T &x, T &y);
bool try_swap(int(*map)[Maxm], int n, int m, int tc, const int X, const int Y);
bool check_swap(int(*map)[Maxm], int n, int m, Point A, Point B);
void exchange(int(*map)[Maxm], int n, int m, Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, bool(*flag)[Maxm]);
bool find(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
void fill_map(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
void alter_map(int(*map)[Maxm], const int n, const int m, bool(*del)[Maxm]);
bool check(int(*map)[Maxm], const int n, const int m, bool(*del)[Maxm]);
void reset_map(int(*map)[Maxm], const int n, const int m);

bool mouse_init(Point &mouse, int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
bool mouse_work(int(*map)[Maxm], const int n, const int m, bool(*flag)[Maxm]);
void work_game(int(*map)[Maxm], const int n, const int m);

void work_cmd(int(*map)[Maxm], const int n, const int m, const int mode);
void cmd_reset(int(*map)[Maxm], const int n, const int m, const int mode);
void work_array(int(*map)[Maxm], const int n, const int m, const int mode);

void reset(int(*map)[Maxm], const int n, const int m);
bool file_input(char *file_name, int(*map)[Maxm], int &n, int &m);
void output_file_ans(char *file_name, const int n, const int m);
bool init_mode(int &mode);
void init(int &n, int &m);

char alpha_upper(const char ch);
void End();
void output_menu();
