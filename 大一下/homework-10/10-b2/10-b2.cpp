//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
#include "10-b2.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date()
{
	year = 2000;
	month = day = 1;
}
Date::Date(const int _y, const int _m, const int _d)
{
	year = _y;
	month = _m;
	day = _d;

	if (year > Maxy || year < Miny)
		year = 2000;
	if (month > Maxm || month < Minm)
		month = 1;
	const int Maxd = Days[month] + (Leapyear(year) && month == 2);
	if (day > Maxd || day < 1)
		day = 1;
}

void Date::set(const int y, const int m, const int d)
{
	if(y)
		year = y;
	if(m)
		month = m;
	if(d)
		day = d;
	
	if (year > Maxy || year < Miny)
		year = 2000;
	if (month > Maxm || month < Minm)
		month = 1;
	const int Maxd = Days[month] + (Leapyear(year) && month == 2);
	if (day > Maxd || day < 1)
		day = 1;
}
void Date::get(int &y, int &m, int &d)
{
	y = year;
	m = month;
	d = day;
}
void Date::show()const
{
	cout << year << "." << month << "." << day << "." << endl;
}

Date::Date(int _d)
{
	int y = 1900, m = 1, d = 1;
	if (_d >= limitd)
		y = 2099, m = 12, d = 31;
	else if (_d > 1)
		days2date(_d, y, m, d);
	year = y;
	month = m;
	day = d;
}
Date::operator int()const
{
	int res_d = 0;
	date2days(res_d, year, month, day);
	return res_d;
}

Date operator +(const Date rhs, const int _d)
{
	return (Date)((int)rhs + _d);
}
Date operator +(const int _d, const Date rhs)
{
	return (Date)((int)rhs + _d);
}
Date operator -(const Date rhs, const int _d)
{
	return (Date)((int)rhs - _d);
}
int operator -(const Date d1, const Date d2)
{
	return ((int)d1 - (int)d2);
}

Date& operator ++(Date &rhs)
{
	return rhs = rhs + 1;
}
Date operator ++(Date &rhs, int)
{
	Date tmp(rhs);
	rhs = rhs + 1;
	return tmp;
}
Date& operator --(Date &rhs)
{
	return rhs = rhs - 1;
}
Date operator --(Date &rhs, int)
{
	Date tmp(rhs);
	rhs = rhs - 1;
	return tmp;
}

istream& operator >>(istream &it, Date &rhs)
{
	int y, m, d;
	it >> y >> m >> d;
	rhs.set(y, m, d);
	return it;
}
ostream& operator <<(ostream &it, Date &rhs)
{
	it << rhs.year << "." << rhs.month << "." << rhs.day << "." << endl;
	return it;
}

bool Date::operator ==(const Date &rhs)const
{
	return year == rhs.year && month == rhs.month && day == rhs.day;
}
bool Date::operator !=(const Date &rhs)const
{
	return year != rhs.year || month != rhs.month || day != rhs.day;
}
bool operator <(const Date d1, const Date d2)
{
	return ((int)d1 - (int)d2) < 0;
}
bool operator <=(const Date d1, const Date d2)
{
	return ((int)d1 - (int)d2) <= 0;
}
bool operator >(const Date d1, const Date d2)
{
	return ((int)d1 - (int)d2) > 0;
}
bool operator >=(const Date d1, const Date d2)
{
	return ((int)d1 - (int)d2) >= 0;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
bool Leapyear(const int y)
{
	return (!(y % 4) && (y % 100)) || !(y % 400);
}
void days2date(int days, int &y, int &m, int &d)
{
	while (1)
	{
		bool leapyear = Leapyear(y);
		int totdays = Year + leapyear;
		if (totdays < days)
		{
			++y;
			days -= totdays;
			continue;
		}
		while ((totdays = Days[m] + (leapyear && m == 2)) < days)
			++m, days -= totdays;
		d = days;
		break;
	}
}
void date2days(int &days, const int year, const int month, const int day)
{
	bool leapyear = Leapyear(year);
	for (int y = Miny; y < year; ++y)
		days += Year + Leapyear(y);
	for (int m = Minm; m < month; ++m)
		days += Days[m] + (leapyear && m == 2);
	days += day;
}
