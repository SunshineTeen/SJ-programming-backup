// 姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<fstream>

#define sFor(i,l,r) for(int i=l;i<r;++i)

using namespace std;

inline bool Isdigit(const char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool IP_work(char *IP)
{
	const int low = 0;
	const int high = 255;

	int len = strlen(IP);
	int cnt = 0;
	int l = 0, r;
	int IP_adr[4] = { -1,-1,-1,-1};
	while (l < len)
	{
		int num = 0;
		r = l;
		while (Isdigit(IP[r]) && r < len)
			num = num * 10 + IP[r++] - '0';
		if (r - l > 3 || (++cnt)>4 || (r!=len && IP[r]!='.'))
			return 0;
		if (num<low || num>high)
			return 0;
		IP_adr[cnt - 1] = num;
		l = r + 1;
	}
	return (cnt == 4 && IP_adr[3] != -1);
}
bool op_work(int &op, char *com, char *para = NULL,int l=0,int r=0)
{
	if (com[1] == 't')
	{
		op = 1;
		return 1;
	}
	if (para == NULL || IP_work(para) || 
		!strcmp(para,"-n") || !strcmp(para,"-t") || !strcmp(para,"-l"))
	{
		cout << com << " Missing Parameter" << endl;
		return 0;
	}

	int num = 0;
	int len = strlen(para);
	if (len > 5)
		return 1;
	/*sFor(i, 0, len)
	{
		if (!Isdigit(para[i]))
			return 1;
		num = num * 10 + para[i] - '0';
	}*/
	num = atoi(para);
	if (num<l || num>r)
		return 1;
	op = num;
	return 1;
}

int main(int argc, char *argv[])
{
	//cout << "Grammar ping [-l size] [-n count] [-t] IP_address" << endl;
	const int ll = 64;
	const int rl = 64000;
	const int ln = 1;
	const int rn = 10000;

	int p = 0;
	int l = 100, n = 128, t = 0;
	bool IP_input = 0;

	while ((++p) < argc)
	{
		if (argv[p][0] == '-')
		{
			if (argv[p][2] != '\0')
			{
				cout << "Command Error\n" << endl;
				break;
			}
			char op = argv[p][1];
			bool flag = 1;
			if (op == 'l')
				flag = op_work(l, argv[p], argv[p + 1], ll, rl), ++p;
			else if (op == 'n')
				flag = op_work(n, argv[p], argv[p + 1], ln, rn), ++p;
			else if (op == 't')
				flag = op_work(t, argv[p]);
			else
			{
				cout << "Command Error\n" << endl;
				break;
			}
			if (flag)
				continue;

			p = 0;
			break;
		}
		if (!(IP_input = IP_work(argv[p])))
		{
			cout << "IP Error" << endl;
			break;
		}
	}

	if (p != argc)
		return -1;

	if (!IP_input)
	{
		cout << "Require a IP address" << endl;
		return -1;
	}

	cout << "the value of l is " << l << endl;
	cout << "the value of n is " << n << endl;
	cout << "the value of t is " << t << endl;

	return 0;
}
