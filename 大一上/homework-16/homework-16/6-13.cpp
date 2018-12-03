/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#define For(i,l,r,k) for(double i=l;i<=r;i+=k)

using namespace std;

const int n = 10000000;
const double eps = 1e-12;

double fun_sin(const double l,const double r)
{
	double res = 0;
	const double delta = (r - l) / n;
	if (delta < eps)
		return 0;
	For(i, l, r, delta)
		res += delta*sin(i);
	return res;
}
double fun_cos(const double l, const double r)
{
	double res = 0;
	const double delta = (r - l) / n;
	if (delta < eps)
		return 0;
	For(i, l, r, delta)
		res += delta*cos(i);
	return res;
}
double fun_exp(const double l, const double r) 
{
	double res = 0;
	const double delta = (r - l) / n;
	if (delta < eps)
		return 0;
	For(i, l, r, delta)
		res += delta*exp(i);
	return res;
}
double definite_integration(double(*fun)(double,double),double l,double r)
{
	double res = fun(l, r);
	return res;
}
int main()
{
	double low, high, value;
	cin >> low >> high; //输入上下限
	value = definite_integration(fun_sin,low, high);
	cout << value << endl;
	cin >> low >> high; //输入上下限
	value = definite_integration(fun_cos, low, high);
	cout << value << endl;
	cin >> low >> high; //输入上下限
	value = definite_integration(fun_exp, low, high);
	cout << value << endl;
	return 0;
}
