//����:����Դ �༶:�����һ�� ѧ��:1652228

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

	printf("������һƪÿ��80���ַ�����3�е�����\n");

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

	printf("�����¹����д�д��ĸ:\n");
	For(i,11,36)
	{
		printf("%c :",i-11+'A');
		cout<<setw(3)<<cnt[i];
		printf("��\n");
	}

	printf("Сд��ĸ:\n");
	For(i,37,62)
	{
		printf("%c :",i-37+'a');
		cout<<setw(3)<<cnt[i];
		printf("��\n");
	}

	printf("����:\n");
	For(i,0,9)
	{
		printf("%d :",i);
		cout<<setw(3)<<cnt[i];
		printf("��\n");
	}

	printf("�ո�:");
	cout<<setw(3)<<cnt[10];
	printf("��\n");

	printf("�����ַ�:");
	cout<<setw(3)<<cnt[63];
	printf("��\n");

	//system("pause");//////////////////////////
	return 0;
}