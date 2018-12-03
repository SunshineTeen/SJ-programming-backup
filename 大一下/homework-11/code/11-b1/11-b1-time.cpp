//姓名：王哲源 班级：计算机1班 学号：1652228

#include"11-b1-time.h"
#include<iomanip>

Time::Time(int _h, int _m, int _s)
{
	if ((_h >= Maxh || _h < 0) || (_m >= Max || _m < 0) || (_s > Max || _s < 0))
		_h = _m = _s = 0;
	hour = _h;
	minute = _m;
	second = _s;
}
Time::Time(int _s)
{
	if (_s <= 0)
		hour = second = minute = 0;
	else
	{
		hour = (_s / 3600) % 24;
		_s %= 3600;
		minute = _s / 60;
		second = _s % 60;
	}
	
}
void Time::set(int _h, int _m, int _s)
{
	if (_h >= Maxh || _m >= Max || _s > Max)
		_h = _m = _s = 0;
	hour = _h;
	minute = _m;
	second = _s;
}

istream& operator >> (istream &it, Time &rhs)
{
	int h,m,s;
	it >> h >> m >> s;
	rhs.set(h,m,s);
	return it;
}
ostream& operator <<(ostream &it, const Time &rhs)
{
	it << setw(2) << setiosflags(ios::right) << setfill('0') << rhs.hour << ':';
	it << setw(2) << setiosflags(ios::right) << setfill('0') << rhs.minute << ':';
	it << setw(2) << setiosflags(ios::right) << setfill('0') << rhs.second;
	return it;
}

Time Time::operator +(const int s)const
{
	Time res = *this;
	res.second += s;
	res.minute += res.second / Max;
	res.second %= Max;
	res.hour += res.minute / Max;
	res.minute %= Max;
	res.hour %= Maxh;
	return res;
}
Time Time::operator -(const int s)const
{
	Time res = *this;
	res.second -= s;
	while (res.second < 0)
	{
		res.second += Max;
		--res.minute;
		if (res.minute < 0)
		{
			res.minute += Max, --res.hour;
			if (res.hour < 0)
				res.hour += Maxh;
		}
	}
	return res;
}
int Time::operator -(Time rhs)const
{
	return 3600 * ((*this).hour - rhs.hour) + 60 * ((*this).minute - rhs.minute) + (*this).second - rhs.second;
}
Time& Time::operator +=(const int s)
{
	second += s;
	minute += second / Max;
	second %= Max;
	hour += minute / Max;
	minute %= Max;
	hour %= Maxh;
	return *this;
}
Time& Time::operator -=(const int s)
{
	second -= s;
	while (second < 0)
	{
		second += Max;
		--minute;
		if (minute < 0)
		{
			minute += Max, --hour;
			if (hour < 0)
				hour += Maxh;
		}
	}
	return *this;
}


Time& Time::operator ++()
{
	++second;
	if (second == Max)
	{
		second -= Max;
		++minute;
		if (minute == Max)
		{
			minute -= Max;
			++hour;
			if (hour == Maxh)
				hour -= Maxh;
		}
	}
	return *this;
}
Time Time::operator ++(int)
{
	Time old = *this;
	++second;
	if (second == Max)
	{
		second -= Max;
		++minute;
		if (minute == Max)
		{
			minute -= Max;
			++hour;
			if (hour == Maxh)
				hour -= Maxh;
		}
	}
	return old;
}
Time& Time::operator --()
{
	--second;
	if (second<0)
	{
		second += Max;
		--minute;
		if (minute < 0)
		{
			minute += Max;
			--hour;
			if (hour < 0)
				hour += Maxh;
		}
	}
	return *this;
}
Time Time::operator --(int)
{
	Time old = *this;
	--second;
	if (second<0)
	{
		second += Max;
		--minute;
		if (minute < 0)
		{
			minute += Max;
			--hour;
			if (hour < 0)
				hour += Maxh;
		}
	}
	return old;
}

bool Time::operator >(const Time &rhs)const
{
	if (hour != rhs.hour)
		return hour > rhs.hour;
	if (minute != rhs.minute)
		return minute > rhs.minute;
	return second > rhs.second;
}
bool Time::operator <(const Time &rhs)const
{
	if (hour != rhs.hour)
		return hour < rhs.hour;
	if (minute != rhs.minute)
		return minute < rhs.minute;
	return second < rhs.second;
}
bool Time::operator >=(const Time &rhs)const
{
	if (hour != rhs.hour)
		return hour > rhs.hour;
	if (minute != rhs.minute)
		return minute > rhs.minute;
	return second >= rhs.second;
}
bool Time::operator <=(const Time &rhs)const
{
	if (hour != rhs.hour)
		return hour < rhs.hour;
	if (minute != rhs.minute)
		return minute < rhs.minute;
	return second <= rhs.second;
}
bool Time::operator ==(const Time &rhs)const
{
	return hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}
bool Time::operator !=(const Time &rhs)const
{
	return hour != rhs.hour || minute != rhs.minute || second != rhs.second;
}

Time Time::getTimeClass()
{
	return *this;
}
