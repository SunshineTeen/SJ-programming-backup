/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

void Swap(char A[], char B[])
{
	const int Maxl = 50;
	char tmp[Maxl];

	strcpy(tmp,A);
	strcpy(A,B);
	strcpy(B,tmp);
}

int main()
{
	const int n = 3;
	const int Maxl = 50;

	char s[n + 2][Maxl];
	printf("�������������Ȳ�����29���ַ���\n");
	For(i, 1, n)
		scanf(" %s", s[i] + 1);

	if (strcmp(s[1], s[2]) > 0)
		Swap(s[1], s[2]);
	if (strcmp(s[1], s[3]) > 0)
		Swap(s[1], s[3]);
	if (strcmp(s[2], s[3]) > 0)
		Swap(s[2], s[3]);

	printf("�����ַ�����С�����˳��Ϊ\n");
	For(i, 1, n)
		printf("%s\n", s[i] + 1);

	return 0;
}
