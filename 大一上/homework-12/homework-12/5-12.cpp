//����:����Դ �༶:�����һ�� ѧ��:1652228

#define _CRT_NO_SECURE_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<ctime>

using namespace std;

#define For(i,l,r) for(int i=l;i<=r;++i)

int main()
{
	const int N=80;
	const int Maxn=N+10;
	char code[Maxn],source[Maxn];

	srand(unsigned(time(0)));
	For(i,1,N)
		code[i]=32+rand()%91;

	For(i,1,N)
	{
		if(code[i]>='A' && code[i]<='Z')
		{
			source[i]='A'+(26-(code[i]-'A'+1));
			continue;
		}
		if(code[i]>='a' && code[i]<='z')
		{
			source[i]='a'+(26-(code[i]-'a'+1));
			continue;
		}
		source[i]=code[i];
	}

	printf("����Ϊ:\n");
	For(i,1,N)
		printf("%c",code[i]);
	printf("\n");

	printf("ԭ��Ϊ:\n");
	For(i,1,N)
		printf("%c",source[i]);
	printf("\n");


	//system("pause");//////////////////////////
	return 0;
}