//����������Դ �༶�������1�� ѧ�ţ�1652228
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double r = 1.5, h = 3;
	double pi = acos(-1.0);
	printf("Բ�ܳ�=%.2f\n", 2*pi*r);
	printf("Բ���=%.2f\n", pi*r*r);
	printf("Բ������=%.2f\n", 4*pi*r*r);
	printf("Բ�����=%.2f\n", 4.0/3*pi*r*r*r);
	printf("Բ�����=%.2f\n", pi*r*r*h);
	return 0;
}