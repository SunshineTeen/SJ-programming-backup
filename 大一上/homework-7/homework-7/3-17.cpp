//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{
	printf("����������������a��n\n");

	int a, n;
	scanf(" %d %d", &a, &n);

	int s = 0;
	For(i, 1, n)
	{
		int tmp = 0;
		For(j, 1, i)
			tmp = tmp * 10 + a;
		s += tmp;
	}
	printf("�����������������Ӧ���������Ϊ%d\n", s);

	return 0;
}