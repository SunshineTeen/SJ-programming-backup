/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Min(a,b) ((a)<(b)?(a):(b))
#define FFLUSH while(getchar()!='\n')

const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
const int N = 9;
const int menu_X = 67;
const int menu_Y = 4;
const int low_X = 4;
const int low_Y = 1;
const int high_X = 58;
const int high_Y = 28;
const bool zeros[3][N + 1] = { 0 };

struct File
{
	char *name;
	File *pre;
	File *nxt;
};
struct Point
{
	int x;
	int y;
};
struct Operation
{
	Point pos;
	int past;
	Operation *pre;
};

char alpha_upper(const char ch);
int rotate(const int x, const int y);
void clear_img(int line);
void End();

int get_file(File *&head, int &cnt);
void Free_file(File *&head);
void Free_Operation(Operation *p);

void pre_work(int(*map)[N + 1], bool(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9]);
int check(int(*map)[N + 1], bool(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9]);

int select_base(int(*map)[N + 1]);
void select_img(int(*map)[N + 1], File *head, const int lim);

void init(int &mode);
int input(Point &P, int &x, bool const(*fix)[N + 1], char *res);
int input_keyboard(Point &P, int &x, bool const(*fix)[N + 1], int const(*map)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9]);
int input_mouse(Point &P, int &x, bool const(*fix)[N + 1], int const(*map)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9]);
int read_mouse_and_key(const HANDLE hin, int &X, int &Y, const int enable_read_mouse_move = 1);

void output_menu();
void menu_output_base(File *f_head);
void menu_output_img(File *f_head, const int limit);
void output_base(int(*map)[N + 1], bool const(*fix)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9]);
void output_img(int(*map)[N + 1], bool const(*fix)[N + 1], bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9], Point P);
void output_ex(const int mode, Point &P, bool const(*fix)[N + 1], int const x, bool const(*f)[N + 1], int const(*fx)[9], int const(*fy)[9], int const(*fz)[9]);

int main();
void work(const int mode);
void game_base(int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9]);
void game_img(const int mode, int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9]);
void work_auto(int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9]);

bool dfs(int x, int y, int(*map)[N + 1], bool const(*fix)[N + 1], int(*fx)[9], int(*fy)[9], int(*fz)[9]);
