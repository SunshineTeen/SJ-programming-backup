//姓名：王哲源 班级：计算机1班 学号：1652228

#include<cmath>
#include"7-ds-b12-double1.h"

double1& double1::operator =(const double1 &rhs)
{
	x = rhs.x;
	return *this;
}

bool double1::operator ==(const double1 &rhs)const
{
	return fabs(x - rhs.x) < 1e-6;
}
bool double1::operator !=(const double1 &rhs)const
{
	return fabs(x - rhs.x) >= 1e-6;
}

istream& operator >> (istream &it, double1 &rhs)
{
	it >> rhs.x;
	return it;
}
ostream& operator <<(ostream &it, const double1 &rhs)
{
	it << rhs.x;
	return it;
}
