/* 班级:计算机一班 学号:1652228 姓名:王哲源 */
#include <iostream>
using namespace std;

/* 此处给出fun函数的实现 */
template < class T1 , class T2 >
inline void fun(T1 x, T2 y)
{
	int tmp1 = sizeof(x), tmp2 = sizeof(y);
	if (tmp1 < tmp2)
		printf("参数1所占空间 <  参数2所占空间\n");
	else if (tmp1 > tmp2)
		printf("参数1所占空间 >  参数2所占空间\n");
	else
		printf("参数1所占空间 == 参数2所占空间\n");
}

/* main函数不准修改 */
int main()
{
	short  s1 = 0, s2 = 0;
	int    i1 = 0, i2 = 0;
	long   l1 = 0, l2 = 0;
	float  f1 = 0, f2 = 0;
	double d1 = 0, d2 = 0;

	fun(s1, s2); //期望输出 参数1所占空间 == 参数2所占空间
	fun(i1, l2); //期望输出 参数1所占空间 == 参数2所占空间
	fun(f1, d2); //期望输出 参数1所占空间 <  参数2所占空间
	fun(d1, f2); //期望输出 参数1所占空间 >  参数2所占空间
	fun(d2, l1); //期望输出 参数1所占空间 >  参数2所占空间
	
	return 0;
}
