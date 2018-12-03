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

void output(ifstream &file)
{
	int pos = 0;
	while (1)
	{
		char ch[17] = { "" };
		For(i, 1, 16)
		{
			char tmp = file.get();
			if (tmp == EOF)
				break;
			ch[i] = tmp;
		}
		cout << setw(8) << setiosflags(ios::right) << setfill('0') << hex << setiosflags(ios::uppercase) << pos;
		cout << ": ";
		For(i, 1, 16)
		{
			short Hex = short(ch[i]) & 0xff;
			if (!Hex)
				cout << "   ";
			else
				cout << setw(2) << setiosflags(ios::right) << setfill('0') << hex << setiosflags(ios::uppercase) << Hex << ' ';
			if (i == 8)
				cout << "- ";
		}
		cout << "; ";
		For(i, 1, 16)
		{
			if (!ch[i])
			{
				cout << endl;
				return;
			}
			cout << ((ch[i] >= 33 && ch[i] <= 126) ? ch[i] : '.');
		}
		cout << endl;
		++pos;
	}
}

int main(int argc, char *argv[])
{
	char file_name[100] = { "LoveTaihouForever" };
	if (argc != 1)
		strcpy(file_name, argv[1]);
	else
	{
		cout << "文件名以一下形式均可以：" << endl;
		cout << "    a.txt：不带路径形式" << endl;
		cout << "    ..\\data\\b.dat：相对路径形式" << endl;
		cout << "    C:\\Windows\\System32\\c,dat：绝对路径形式" << endl;
		cout << "请输入文件名：";
		cin >> file_name;
	}

	ifstream infile;
	infile.open(file_name, ios::in | ios::binary);
	if (!infile.is_open())
	{
		cout << "File Open Error" << endl;
		return -1;
	}
	output(infile);
	infile.close();

	return 0;
}
