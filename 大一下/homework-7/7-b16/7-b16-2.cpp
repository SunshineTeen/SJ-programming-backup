//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<io.h>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;

const int Maxn = 20;
const int Maxm = 35;

char peek(FILE *fp)
{
	char res;
	fread(&res, 1, 1, fp);
	fseek(fp, -1, SEEK_CUR);
	return res;
}

void replace(char source[], char aim[])
{
	FILE *f2 = fopen(aim, "rb+");
	if (f2==NULL)
	{
		printf("No such substitution file\n");
		return;
	}

	FILE *f1 = fopen(source, "rb+");
	if (f1==NULL)
	{
		printf("Not submitted\n");
		return;
	}

	char tmp[1024 * 200] = " ";
	int n = 0;
	while (!feof(f1))
		fread(&tmp[n++], 1, 1, f1); //fread will take one more time for \0
	fclose(f1);
	char *p = strstr(tmp, "int main(");
	*p = '\0';
	n = strlen(tmp);
	while (!feof(f2))
		fread(&tmp[n++], 1, 1, f2);
	fclose(f2);

	FILE* f_new=fopen(source,"wb+");
	fwrite(tmp, strlen(tmp), 1, f_new);
	fclose(f_new);

	printf("Replace successfully\n");
}

bool get_info(FILE *cpp, char(*info)[100])
{
	while (peek(cpp) == ' ' || peek(cpp) == '\n')
		fseek(cpp, 1, SEEK_CUR);
	char tmp[3] = "";
	fread(tmp, 1, 2, cpp);
	if (strcmp(tmp, "//") && strcmp(tmp, "/*"))
	{
		printf("No information in first line\n");
		return 0;
	}

	int cnt = 0;
	while (1)
	{
		if (cnt > 2)
			break;
		while (peek(cpp) == ' ' || peek(cpp) == '\t')
			fseek(cpp, 1, SEEK_CUR);
		char tr = peek(cpp);
		if (tr == '*' || tr == '\n')
		{
			printf("Information is incomplete\n");
			return 0;
		}
		int p = 0;
		char tmp;
		while (1)
		{
			fread(&tmp, 1, 1, cpp);
			if (tmp == ' ' || tmp == '*' || tmp == '\n' || tmp == '\t')
				break;
			info[cnt][p++] = tmp;
		}
		info[cnt++][p] = '\0';
	}
	return 1;
}
void check(char route[], char Id[], char name[], char(*Class)[100])
{
	FILE *cpp = fopen(route, "r+");
	if (cpp == NULL)
	{
		printf("Not submitted\n");
		return;
	}
	while (1)
	{
		char ch=peek(cpp);
		if (ch != ' '&& ch != '\n' && ch != '\t')
			break;
		fseek(cpp, 1, SEEK_CUR);
	}

	char info[3][100] = { "" };
	int f = get_info(cpp, info);
	fclose(cpp);
	if (!f)
		return;

	bool res_1 = 0;
	For(i, 0, 2)
		res_1 |= (!strcmp(info[i], name));
	if (!res_1)
		printf("*Name Error* ");
	bool res_2 = 0;
	For(i, 0, 2)
		res_2 |= ((strstr(info[i], Class[0]) != NULL) | (strstr(info[i], Class[1]) != NULL));
	if (!res_2)
		printf("*Class Error* ");
	bool res_3 = 0;
	For(i, 0, 2)
		res_3 |= (!strcmp(info[i], Id));
	if (!res_3)
		printf("*Student ID Error* ");
	if (res_1 && res_2 && res_3)
		printf("*Pass*");
	printf("\n");
}
void check_all_file(char pre[], char Id[], char name[], char(*Class)[100])
{
	printf("\n");
	long fst_file;
	struct _finddata_t file_info;
	char catalog[100] = "";
	strcpy(catalog, pre);
	strcat(catalog, "*.*");
	if ((fst_file = _findfirst(catalog, &file_info)) == -1L)
	{
		cout << "No Files" << endl << endl;
		return;
	}
	do
	{
		if (strstr(file_info.name, ".cpp") == NULL
			&& strstr(file_info.name, ".c") == NULL
			&& strstr(file_info.name, ".h") == NULL)
			continue;
		char route[100] = "";
		strcpy(route, pre);
		cout << setw(35) << setiosflags(ios::left) << file_info.name;
		strcat(route, file_info.name);
		check(route, Id, name, Class);
	} while (!_findnext(fst_file, &file_info));
	_findclose(fst_file);
	printf("\n");
}

void work(const int mode, char *course, char *source, char *cpy = NULL)
{
	char file[Maxn] = ".\\source\\";
	strcat(file, course);
	strcat(file, ".dat");
	FILE *dat= fopen(file, "r+");
	if (dat == NULL)
	{
		printf("Courese Error\n");
		return;
	}
	char name[100] = "Taihou";
	char Class[2][100] = { "" };
	char Id[100] = "1652228";
	while (!feof(dat))
	{
		fscanf(dat, " %s %s %s %s", Id, name, Class[0], Class[1]);

		char route[100] = ".\\source\\";
		strcat(route, course);
		strcat(route, "-");
		strcat(route, Id);
		strcat(route, "\\");
		cout << setw(10) << setiosflags(ios::left) << Id;
		cout << setw(15) << setiosflags(ios::left) << name;
		if (cpy == NULL)
		{
			if (mode == 1)
			{
				cout << setw(35) << setiosflags(ios::left) << source;
				strcat(route, source);
				check(route, Id, name, Class);
			}
			else
				check_all_file(route, Id, name, Class);
		}
		else
		{
			strcat(route, source);
			char _route[100] = ".\\source\\";
			strcat(_route, cpy);
			replace(route, _route);
		}
	}
	fclose(dat);
}

bool init(int argc, char *argv[], int &mode, char *course, char *source, char *cpy)
{
	if (argc != 4 && argc != 5)
	{
		printf("Command Error\n");
		return 0;
	}
	if (argc == 4)
	{
		if (strcmp("-checktitle", argv[1]))
		{
			printf("Command Error\n");
			return 0;
		}
		mode = 1;
		strcpy(course, argv[2]);
		strcpy(source, argv[3]);
		if (!strcmp(source, "all"))
		{
			mode = 2;
			return 1;
		}
		int len = strlen(source);
		int i = 0;
		for (; i < len && source[i] != '.'; ++i);
		if (i == len || (strcmp(source + i, ".cpp") && strcmp(source + i, ".h") && strcmp(source + i, ".c")))
		{
			printf("Source not found\n");
			return 0;
		}
	}
	else
	{
		if (strcmp("-replace", argv[1]) || !strcmp(argv[3], "all") || !strcmp(argv[4], "all"))
		{
			printf("Command Error\n");
			return 0;
		}
		mode = 3;
		strcpy(course, argv[2]);
		strcpy(source, argv[3]);
		strcpy(cpy, argv[4]);

		int len = strlen(source);
		int i = 0;
		for (; i < len && source[i] != '.'; ++i);
		if (i == len || strcmp(source + i, ".cpp"))
		{
			printf("Source not found\n");
			return 0;
		}

		len = strlen(cpy);
		i = 0;
		for (; i < len && cpy[i] != '.'; ++i);
		if (i == len || strcmp(cpy + i, ".cpp"))
		{
			printf("Source not found\n");
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int mode;
	char course[Maxn] = "LoveTaihouForever";
	char source[Maxm] = "LoveTaihouForever";
	char cpy[Maxm] = "LoveTaihouForever";
	if (!init(argc, argv, mode, course, source, cpy))
		return -1;
	if (mode == 1 || mode == 2)
		work(mode, course, source);
	else
		work(mode, course, source, cpy);

	return 0;
}
