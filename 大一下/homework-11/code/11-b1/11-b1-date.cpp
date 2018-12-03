//姓名：王哲源 班级：计算机1班 学号：1652228

#include"11-b1-date.h"
#include<iomanip>

Date::Date(int _y, int _m, int _d)
{
	if ((_y > MaxYear || _y < MinYear) || (_m > MaxMonth || _m < MinMonth))
		_y = MinYear, _m = MinMonth, _d = 1;
	else
	{
		int daylimit = Days[_m] + (_m == 2 && Leapyear(_y));
		if(_d<1 || _d>daylimit)
			_y = MinYear, _m = MinMonth, _d = 1;
	}
	year = _y;
	month = _m;
	day = _d;
}
Date::Date(int _d)
{
	int y = 1900, m = 1, d = 1;
	if (_d >= 73049)
		y = 2099, m = 12, d = 31;
	else if (_d > 1)
		days2date(_d, y, m, d);
	year = y;
	month = m;
	day = d;
}
void Date::set(int _y, int _m, int _d)
{
	if ((_y > MaxYear || _y < MinYear) || (_m > MaxMonth || _m < MinMonth))
		_y = MinYear, _m = MinMonth, _d = 1;
	else
	{
		int daylimit = Days[_m] + (_m == 2 && Leapyear(_y));
		if (_d<1 || _d>daylimit)
			_y = MinYear, _m = MinMonth, _d = 1;
	}
	year = _y;
	month = _m;
	day = _d;
}

istream& operator >> (istream &it, Date &rhs)
{
	int y, m, d;
	it >> y >> m >> d;
	rhs.set(y, m, d);
	return it;
}
ostream& operator <<(ostream &it, const Date &rhs)
{
	it << rhs.year << '-';
	it << setw(2) << setiosflags(ios::right) << setfill('0') << rhs.month << '-';
	it << setw(2) << setiosflags(ios::right) << setfill('0') << rhs.day;
	return it;
}

Date Date::operator +(const int d)const
{
	Date res = *this;
	res.day += d;
	while (1)
	{
		if (res.month > MaxMonth)
			res.month = MinMonth, ++res.year;
		if (res.year > MaxYear)
			res.year = MinYear;
		int daylimit = Days[res.month] + (res.month == 2 && Leapyear(res.year));
		if (res.day <= daylimit)
			break;
		res.day -= daylimit;
		++res.month;
	}
	return res;
}
Date Date::operator -(const int d)const
{
	Date res = *this;
	res.day -= d;
	while (1)
	{
		if (res.day > 0)
			break;
		--res.month;
		if (res.month < MinMonth)
			res.month = MaxMonth, --res.year;
		if (res.year < MinYear)
			res.year = MaxYear;
		int daylimit = Days[res.month] + (res.month == 2 && Leapyear(res.year));
		res.day += daylimit;
	}
	return res;
}
int Date::operator -(Date rhs)const
{
	return date2days((*this).year, (*this).month, (*this).day) - date2days(rhs.year, rhs.month, rhs.day);
}
Date& Date::operator +=(const int d)
{
	day += d;
	while (1)
	{
		if (month > MaxMonth)
			month = MinMonth, ++year;
		if (year > MaxYear)
			year = MinYear;
		int daylimit = Days[month] + (month == 2 && Leapyear(year));
		if (day <= daylimit)
			break;
		day -= daylimit;
		++month;
	}
	return *this;
}
Date& Date::operator -=(const int d)
{
	day -= d;
	while (1)
	{
		if (day > 0)
			break;
		--month;
		if (month < MinMonth)
			month = MaxMonth, --year;
		if (year < MinYear)
			year = MaxYear;
		int daylimit = Days[month] + (month == 2 && Leapyear(year));
		day += daylimit;
	}
	return *this;
}

Date& Date::operator ++()
{
	++day;
	int daylimit = Days[month] + (month == 2 && Leapyear(year));
	if (day > daylimit)
	{
		day = 1,++month;
		if (month > MaxMonth)
		{
			month = MinMonth, ++year;
			if (year > MaxYear)
				year = MinYear;
		}
	}
	return *this;
}
Date Date::operator ++(int)
{
	Date old = *this;
	++day;
	int daylimit = Days[month] + (month == 2 && Leapyear(year));
	if (day > daylimit)
	{
		day = 1, ++month;
		if (month > MaxMonth)
		{
			month = MinMonth, ++year;
			if (year > MaxYear)
				year = MinYear;
		}
	}
	return old;
}
Date& Date::operator --()
{
	--day;
	if (day < 1)
	{
		--month;
		if (month < MinMonth)
		{
			month = MaxMonth;
			--year;
			if (year < MinYear)
				year = MaxYear;
		}
		day = Days[month] + (month == 2 && Leapyear(year));
	}
	return *this;
}
Date Date::operator --(int)
{
	Date old = *this;
	--day;
	if (day < 1)
	{
		--month;
		if (month < MinMonth)
		{
			month = MaxMonth;
			--year;
			if (year < MinYear)
				year = MaxYear;
		}
		day = Days[month] + (month == 2 && Leapyear(year));
	}
	return old;
}

bool Date::operator >(const Date &rhs)const
{
	if (year != rhs.year)
		return year > rhs.year;
	if (month != rhs.month)
		return month > rhs.month;
	return day > rhs.day;
}
bool Date::operator <(const Date &rhs)const
{
	if (year != rhs.year)
		return year < rhs.year;
	if (month != rhs.month)
		return month < rhs.month;
	return day < rhs.day;
}
bool Date::operator >=(const Date &rhs)const
{
	if (year != rhs.year)
		return year > rhs.year;
	if (month != rhs.month)
		return month > rhs.month;
	return day >= rhs.day;

}
bool Date::operator <=(const Date &rhs)const
{
	if (year != rhs.year)
		return year < rhs.year;
	if (month != rhs.month)
		return month < rhs.month;
	return day <= rhs.day;
}
bool Date::operator ==(const Date &rhs)const
{
	return year == rhs.year && month == rhs.month && day == rhs.day;
}
bool Date::operator !=(const Date &rhs)const
{
	return year != rhs.year || month != rhs.month || day != rhs.day;
}

Date Date::getDateClass()
{
	return *this;
}

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
int date2days(const int year, const int month, const int day)
{
	int res = 0;
	bool leapyear = Leapyear(year);
	for (int y = MinYear; y < year; ++y)
		res += Year + Leapyear(y);
	for (int m = MinMonth; m < month; ++m)
		res += Days[m] + (leapyear && m == 2);
	res += day;
	return res;
}
