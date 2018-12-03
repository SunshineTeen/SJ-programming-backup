//姓名:王哲源 班级:计算机一班 学号:1652228

#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

using namespace std;

#define For(i,l,r) for(int i=l;i<=r;++i)

int main()
{
	const int Maxn=70;
	const int N=3;
	const int M=80;
	int cnt[Maxn]={0};
	// 0-9  0-9
	// 10 ' '
	// 11-36  A-Z
	// 37-62  a-z
	// 63 other

	printf("请输入一篇每行80个字符，共3行的文章\n");

	For(i,1,N)
	{
		For(j,1,M)
		{
			char ch=getchar();
			if(ch>='0' && ch<='9')
			{
				++cnt[ch-'0'];
				continue;
			}
			if(ch>='A' && ch<='Z')
			{
				++cnt[ch-'A'+11];
				continue;
			}
			if(ch>='a' && ch<='z')
			{
				++cnt[ch-'a'+37];
				continue;
			}
			if(ch==' ')
				++cnt[10];
			else
				++cnt[63];
		}
		getchar();
	}

	printf("该文章共含有大写字母:\n");
	For(i,11,36)
	{
		printf("%c :",i-11+'A');
		cout<<setw(3)<<cnt[i];
		printf("个\n");
	}

	printf("小写字母:\n");
	For(i,37,62)
	{
		printf("%c :",i-37+'a');
		cout<<setw(3)<<cnt[i];
		printf("个\n");
	}

	printf("数字:\n");
	For(i,0,9)
	{
		printf("%d :",i);
		cout<<setw(3)<<cnt[i];
		printf("个\n");
	}

	printf("空格:");
	cout<<setw(3)<<cnt[10];
	printf("个\n");

	printf("其他字符:");
	cout<<setw(3)<<cnt[63];
	printf("个\n");

	//system("pause");//////////////////////////
	return 0;
}