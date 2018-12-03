/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')
#define Min(a,b) ((a)<(b)?(a):(b))

const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
const int Maxn = 11;
const int Maxm = 11;
const int Maxc = 7;
const int Maxx = Maxn*Maxm;
const int fx[4] = { 0,-1,0,1 };
const int fy[4] = { -1,0,1,0 };
const int gx[8] = { 0,0,-1,1,-1,1,-1,1 }; //check
const int gy[8] = { -1,1,0,0,-1,1,1,-1 }; //check
const int fgc[8] = { 7,4,3,1,2,7,0,5 }; //color of array

//prework_part
void reset(int(*map)[Maxm], const int n, const int m, int &last); //clear all data
void output_menu(); //menu

//input_part
void init(int &n, int &m);
bool init_mode(int &mode);
void init_st(int(*map)[Maxm], const int n, const int m, int &sx, int &sy);
void init_ed(int(*map)[Maxm], const int n, const int m, int &ex, int &ey);

//work_part
void work_1(int(*map)[Maxm], const int n, const int m, int &last);
void work_2(int(*map)[Maxm], const int n, const int m, int &last);
void work_3(int(*map)[Maxm], const int n, const int m, int &last);
void work_4(int(*map)[Maxm], const int n, const int m, int &last);
void work_5(int(*map)[Maxm], const int n, const int m, int &last);
void work_6(int(*map)[Maxm], const int n, const int m, int &last);
int work_7(const int mode, int(*map)[Maxm], const int n, const int m, int &last);

//tools_part
char alpha_upper(const char ch);
void End(); //press enter to continue
bool bfs(int(*map)[Maxm], const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm]);
void get_route(const int sx, const int sy, const int ex, const int ey, int(*frox)[Maxm], int(*froy)[Maxm], int(*tox)[Maxm], int(*toy)[Maxm]);

//array_working_part
void reset_map(int x, int(*map)[Maxm], const int n, const int m, int &last); //rand n balls
int rand_ball(int(*map)[Maxm], const int n, const int m, const int col, int &last);
int check(int(*map)[Maxm], const int x, const int y, int &last, int *sum_del);//checking for delet
int Calc(int(*map)[Maxm], int x, int y, const int col, const int fx, const int fy);//calc balls
void Delete(int(*map)[Maxm], int x, int y, const int col, const int fx, const int fy);//delete the balls

//array_output_part
void output_array(const int(*map)[Maxm], const int n, const int m, const int mode);
void output_route(int(*map)[Maxm], const int n, const int m, const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm]);
void output_route_array(const int n, const int m, const bool(*f)[Maxm]); // prework_for_array_and_route_output
void output_route_col(int(*map)[Maxm], const int n, const int m, const bool(*f)[Maxm]);

//cmd_output_part
void reset_pic_base(int(*map)[Maxm], const int n, const int m); //simple output
void reset_pic(const int mode, int(*map)[Maxm], const int n, const int m); //cmd final output
void reset_menu(const int tot, const int *col, const int(*map)[Maxm], const int n, const int m, const int *sum_del, bool*setting); //adding the calc menu

//mouse_work_part
int mouse_init(const int mode, int(*map)[Maxm], const int n, const int m, int *mouse, bool *setting);
int mouse_work(const int mode, int(*map)[Maxm], const int n, const int m, int &last, int &score, int *sum_del, bool *setting);
void ball_moving(int(*map)[Maxm], const int n, const int m, const int sx, const int sy, const int ex, const int ey, int(*tox)[Maxm], int(*toy)[Maxm], int col);

int read_mouse_and_key(const HANDLE hin,const int mode, int &X, int &Y, const int enable_read_mouse_moved = 1);
int Check_Double_Click(int pre_mouse_event, const int enable_read_mouse_moved = 1);
void work_8(int(*map)[Maxm], const int n, const int m, int &last);
void work_9(int(*map)[Maxm], const int n, const int m, int &last);
