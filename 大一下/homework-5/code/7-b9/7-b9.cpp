//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<fstream>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define FFLUSH while(getchar()!='\n')
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;

const int maxl = 8;

struct Student
{
	char *name;
	Student *nxt;
};
struct Seat
{
	int *column;
	Seat *nxt;
};

void Free(Student *&stu_head, Seat *&seat_head)
{
	while (stu_head != NULL)
	{
		Student *pre = stu_head;
		stu_head = stu_head->nxt;
		delete pre->name;
		delete pre;
	}
	while (seat_head != NULL)
	{
		Seat *pre = seat_head;
		seat_head = seat_head->nxt;
		delete pre->column;
		delete pre;
	}
}

char *get_Stu(int k, Student *p)
{
	while (k--)
		p = p->nxt;
	return p->name;
}
void output(const int n, int const* Id, Student *stu_head, Seat *seat_head, const int row, char const* out_file)
{
	ofstream outfile(out_file);

	int p = 0;
	Seat* cur = seat_head;

	while (cur != NULL)
	{
		outfile << "|    /   |";
		int x = *(cur->column);
		opFor(j, row - 1, 0)
		{
			if ((x >> j) & 1)
			{
				if (Id[p] == -1)
					outfile << "    /   |";
				else
				{
					outfile << setw(8) << setiosflags(ios::right) << get_Stu(Id[p],stu_head);
					outfile << "|";
				}
				++p;
				continue;
			}
			outfile << "    /   |";
		}
		outfile << "\n";
		cur = cur->nxt;
	}

	outfile.close();
}
void allocate(const int mode, const int n, const int m, bool *seat_f, bool *stu_f, int *Id)
{
	srand((unsigned)time(0));
	int last = n, j = -1;
	while (last)
	{
		int i = rand() % n;
		if (stu_f[i])
			continue;
		stu_f[i] = 1;

		if (mode == 1)
			++j;
		else
		{
			do
			{
				j = rand() % m;
			} while (seat_f[j]);
		}
		seat_f[j] = 1;

		Id[j] = i;
		--last;
	}
}
void init_mode(int &mode)
{
	printf("有以下两种分配方式[1/2]\n");
	printf("1.按座位顺序分配\n");
	printf("2.教室随机分配\n");
	printf("请选择分配方式:");
	while (1)
	{
		if (!scanf("%d", &mode))
			mode = 3;
		if (mode < 1 || mode>2)
		{
			printf("输入错误，请重新选择:");
			FFLUSH;
			continue;
		}
		return;
	}
}
int work(const int n, const int m, Student *stu_head, Seat *seat_head, const int row, char const* out_file)
{
	freopen("CON", "r", stdin);
	int mode;
	init_mode(mode);

	bool *seat_f = new(nothrow) bool[m] {0};
	bool *stu_f = new(nothrow) bool[n] {0};
	int *Id = new(nothrow) int[m];

	if (seat_f == NULL || stu_f == NULL || Id == NULL)
	{
		printf("No Free Memory\n");
		
		delete[]seat_f;
		delete[]stu_f;
		delete[]Id;
		return -1;
	}

	sFor(i, 0, m)
		Id[i] = -1;

	allocate(mode, n, m, seat_f, stu_f, Id);
	output(n, Id, stu_head, seat_head, row, out_file);

	delete[]seat_f;
	delete[]stu_f;
	delete[]Id;

	return 0;
}

int init_seat(int &m, Seat *&seat_head, int &row, char const* seat_file)
{
	ifstream seatfile;
	seatfile.open(seat_file, ios::in);
	if (!seatfile.is_open())
	{
		cout << "Seat File Open Error" << endl;
		return -1;
	}

	char tmp[500] = { "TaihouDaisuki" };
	Seat *p = seat_head;

	while (1)
	{
		seatfile >> tmp;
		row = strlen(tmp);
		int seat = 1;
		sFor(i, 0, row)
		{
			seat <<= 1;
			if (tmp[i] == 'N')
				continue;
			seat |= 1;
			++m;
		}
		seat -= (1 << row);
		if (!seat)
			break;

		Seat *tp = new(nothrow) Seat;
		if (tp == NULL)
		{
			delete tp;
			printf("No Free Memory\n");
			return -1;
		}
		if (seat_head == NULL)
			seat_head = tp;
		else
			p->nxt = tp;

		p = tp;
		p->column= new(nothrow) int(seat);
		if (p->column == NULL)
		{
			printf("No Free Memory\n");
			return -1;
		}
		p->nxt = NULL;
	}

	seatfile.close();
	return 0;
}
int init_stu(int &n, Student *&stu_head, char const* stu_file)
{
	ifstream stufile;
	stufile.open(stu_file, ios::in);
	if (!stufile.is_open())
	{
		cout << "Student File Open Error" << endl;
		return -1;
	}

	char tmp[500] = { "TaihouDaisuki" };
	Student *p = stu_head;

	while (1)
	{
		stufile.getline(tmp, 499);
		if (!strcmp(tmp, "NULL"))
			break;
		++n;
		int tl = Min(strlen(tmp),maxl);

		Student *tp = new(nothrow) Student;
		if (tp == NULL)
		{
			delete tp;
			printf("No Free Memory\n");
			return -1;
		}
		if (stu_head == NULL)
			stu_head = tp;
		else
			p->nxt = tp;

		p = tp;
		p->name = new(nothrow) char[tl + 1];
		if (p->name == NULL)
		{
			printf("No Free Memory\n");
			return -1;
		}
		p->nxt = NULL;
		strncpy(p->name, tmp, tl);
		p->name[tl] = '\0';
	}

	stufile.close();
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc <= 3)
	{
		cout << "请分别输入学生姓名、座位分布及输出文件的文件名\n";
		return -1;
	}

	int n = 0, m = 0, row=0;
	Student *stu_head = NULL;
	Seat *seat_head = NULL;
	if (init_stu(n, stu_head, argv[1]) == -1 || init_seat(m, seat_head, row, argv[2]) == -1)
	{
		Free(stu_head, seat_head);
		return -1;
	}

	if (n > m)
	{
		printf("座位不足\n");
		Free(stu_head, seat_head);
		return 0;
	}

	if (work(n, m, stu_head, seat_head, row, argv[3]) == -1)
	{
		Free(stu_head, seat_head);
		return -1;
	}

	return 0;
}
