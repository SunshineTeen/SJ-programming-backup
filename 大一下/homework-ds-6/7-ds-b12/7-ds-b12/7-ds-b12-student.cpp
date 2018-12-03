//姓名：王哲源 班级：计算机1班 学号：1652228

#include<cstring>
#include<cmath>
#include"7-ds-b12-student.h"

student& student::operator =(const student &rhs)
{
	num = rhs.num;
	memcpy(name, rhs.name, 10 * sizeof(char));
	sex = rhs.sex;
	score = rhs.score;
	memcpy(addr, rhs.addr, 30 * sizeof(char));
	return *this;
}

bool student::operator ==(const student &rhs)const
{
	return num == rhs.num;
}
bool student::operator !=(const student &rhs)const
{
	return num != rhs.num;
}

istream& operator >> (istream &it, student &rhs)
{
	it >> rhs.num >> rhs.name >> rhs.sex >> rhs.score >> rhs.addr;
	return it;
}
ostream& operator <<(ostream &it, const student &rhs)
{
	it << rhs.num << " " << rhs.name << " " << rhs.sex << " " << rhs.score << " " << rhs.addr;
	return it;
}
