//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("�����뵱������\n");

	int i;
	scanf(" %d", &i);

	double sum = 0;
	if (i <= 100000)
		sum = i*0.1;
	else if (i <= 200000)
		sum = 10000 + (i - 100000)*0.075;
	else if (i <= 400000)
		sum = 10000 + 15000 + (i - 200000)*0.05;
	else if (i <= 600000)
		sum = 10000 + 15000 + 10000 + (i - 400000)*0.03;
	else if (i <= 1000000)
		sum = 10000 + 15000 + 10000 + 6000 + (i - 600000)*0.015;
	else
		sum = 10000 + 15000 + 10000 + 6000 + 6000 + (i - 1000000)*0.01;
	printf("Ӧ������%.2lfԪ\n", sum);

	return 0;
}