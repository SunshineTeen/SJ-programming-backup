/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int Maxn = 15;
const int Maxl = 10010;

int main()
{
	char num[Maxn][Maxl];
	char s[Maxl];
	int n = 0, cnt = 0;

	printf("������һ���ַ���\n");
	char tmp;
	while ((tmp = getchar()) != '\n')
		*(s + (++n)) = tmp;
	*(s + (++n)) = 0;

	For(i, 1, n)
	{
		if (*(s+i)<'0' || *(s + i)>'9')
			continue;
		int j = i, p = 0;
		++cnt;
		while (*(s + j) >= '0' && *(s + j) <= '9')
			*(*(num+cnt)+(++p))= *(s + (j++));
		*(*(num + cnt) + (++p)) = '\0';
		i = j;
	}

	if (!cnt)
		printf("���ַ����в���������\n");
	else
	{
		printf("һ����%d������,����\n", cnt);
		For(i, 1, cnt)
			printf("%s\n", *(num+i) + 1);
	}
	return 0;
}
