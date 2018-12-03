/*姓名：王哲源  班级：计算机一班 学号：1652228*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << "a+b=" << a + b;
	system("pause");
	return 0;
}
/*
错误原因：
1.缺少头文件#include<iostream>
2.缺少命名空间using namespace std;
3.变量c未定义类型
4.局部变量a,b未赋值（初始化）
5.cout中的<<打成了>>
6.缺少return 0
*/
