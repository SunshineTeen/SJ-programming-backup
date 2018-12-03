//姓名：王哲源 班级：计算机1班 学号：1652228
#include<iostream>
using namespace std;
int main()
{
	printf("请输入一个华氏温度\n");
	double F;
	cin >> F;
	double c = 5.0 / 9 * (F - 32);
	printf("对应的摄氏温度为:%.2f\n", c);
	return 0;
}
