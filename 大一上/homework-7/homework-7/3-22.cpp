//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>

#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

int main()
{
	int sum = 1;
	opFor(i, 9, 1)
		sum = (sum + 1) * 2;
	printf("���ӵ�1�칲ժ��%d������\n", sum);

	return 0;
}