//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	printf("������һ��ʵ��\n");

	double x;
	scanf(" %lf", &x);

	printf("��Ӧ��yֵΪ:");
	if (x < 1)
		cout << x << endl;
	else if (x >= 1 && x < 10)
		cout << 2 * x - 1 << endl;
	else
		cout << 3 * x - 11 << endl;     //x>10
	
	return 0;
}