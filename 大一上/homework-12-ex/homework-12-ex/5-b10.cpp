/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

int main()
{
	const int Maxn = 100;
	char s[Maxn];
	printf("������һ��������80���ַ���Ӣ����䣬�Կո���Ϊ���ʷָ��������Իس���β\n");
	gets_s(s);

	printf("���������Ϊ\n");
	int l = 0, r;
	while (1)
	{
		while (s[l] == ' ')
		{
			printf(" ");
			++l;
		}
		if (s[l] == '\0')
		{
			printf("\n");
			break;
		}

		r = l;
		while (s[r] != ' ') ++r;
		if (s[l] >= 'a' && s[l] <= 'z')
			printf("%c", s[l] - 32);
		else
			printf("%c", s[l]);
		For(i, l+1, r-1)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				printf("%c", s[i] + 32);
			else
				printf("%c", s[i]);
		}

		l = r;
	}

	//system("pause");/////////////////////////
	return 0;
}
//tHis IS a C 8*# pROGram 
