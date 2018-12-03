/*姓名：王哲源  班级：计算机一班 学号：1652228*/
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int add(int x,int y);
	int c = add(a, b);
	cout << "a+b=" << c << endl;
	return 0;
}
int add(int x, int y)
{
	int z = x + y;
	return(z);
}
/*
错误：
1.变量c未定义类型
2.局部变量a,b未赋值（初始化）
3.c=add(a,b)后缺少分号
4.主函数中调用了未声明的自定义函数add()
5.int add(int x,int y)后多了一个分号
6.自定义函数add()中变量z未定义类型
7.自定义函数add()中return拼写错误
*/
