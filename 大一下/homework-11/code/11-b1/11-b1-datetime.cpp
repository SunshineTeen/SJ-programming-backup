//姓名：王哲源 班级：计算机1班 学号：1652228

#include"11-b1-datetime.h"
#include<iomanip>

DateTime::DateTime(int _y, int _mo, int _d, int _h, int _mi, int _s) :Date(_y, _mo, _d), Time(_h, _mi, _s)
{
	bool wrong = 0;
	if ((_y > MaxYear || _y < MinYear) || (_mo > MaxMonth || _mo < MinMonth) ||
		(_h >= Maxh || _h < 0) || (_mi >= Max || _mi < 0) || (_s > Max || _s < 0))
		wrong = 1;
	else
	{
		int daylimit = Days[_mo] + (_mo == 2 && Leapyear(_y));
		if (_d<1 || _d>daylimit)
			wrong = 1;
	}

	if (wrong)
		(*this).Date::set(1900, 1, 1), (*this).Time::set(0, 0, 0);
}
DateTime::DateTime(LL _s)
{
	LL _d = _s / (24 * 3600) + 1;
	
	if (_d > 73049 || _s < 0)
		(*this).Date::Date(), (*this).Time::Time();
	else
		(*this).Date::Date(int(_d)),(*this).Time::Time(int(_s % (24 * 3600)));
}
void DateTime::set(int _y, int _mo, int _d, int _h, int _mi, int _s)
{
	bool wrong = 0;
	if ((_y > MaxYear || _y < MinYear) || (_mo > MaxMonth || _mo < MinMonth) ||
		(_h >= Maxh || _h < 0) || (_mi >= Max || _mi < 0) || (_s > Max || _s < 0))
		wrong = 1;
	else
	{
		int daylimit = Days[_mo] + (_mo == 2 && Leapyear(_y));
		if (_d<1 || _d>daylimit)
			wrong = 1;
	}

	(*this).Date::set(wrong ? MaxYear + 1 : _y, _mo, _d);
	(*this).Time::set(wrong ? Maxh : _h, _mi, _s);
}

istream& operator >> (istream &it, DateTime &rhs)
{
	int y, mo, d, h, mi, s;
	it >> y >> mo >> d >> h >> mi >> s;
	rhs.set(y, mo, d, h, mi, s);
	return it;
}
ostream& operator <<(ostream &it, DateTime &rhs)
{
	it << rhs.getDateClass() << ' ' << rhs.getTimeClass() << endl;
	return it;
}

DateTime DateTime::operator +(const LL ds)const
{
	DateTime rhs = *this;
	int ts = ds % (24 * 3600), s = ts;
	int d = int(ds / (24 * 3600));
	int h = s / 3600;
	int m = (s %= 3600) / 60;
	s %= 60;
	m += (rhs.second + s) >= 60;
	h += (rhs.minute + m) >= 60;
	d += (rhs.hour + h) >= 24;
	rhs.Time::operator+=(ts);
	rhs.Date::operator+=(d);
	return rhs;
}
DateTime operator +(const LL ds, DateTime rhs)
{
	int ts = ds % (24 * 3600), s = ts;
	int d = int(ds / (24 * 3600));
	int h = s / 3600;
	int m = (s %= 3600) / 60;
	s %= 60;
	m += (rhs.second + s) >= 60;
	h += (rhs.minute + m) >= 60;
	d += (rhs.hour + h) >= 24;
	rhs.Time::operator+=(ts);
	rhs.Date::operator+=(d);
	return rhs;
}
DateTime DateTime::operator -(const LL ds)const
{
	DateTime rhs = *this;
	int ts = ds % (24 * 3600), s = ts;
	int d = int(ds / (24 * 3600));
	int h = s / 3600;
	int m = (s %= 3600) / 60;
	s %= 60;
	m += (rhs.second - s) < 0;
	h += (rhs.minute - m) < 0;
	d += (rhs.hour - h) < 0;
	rhs.Time::operator-=(ts);
	rhs.Date::operator-=(d);
	return rhs;
}
LL operator -(DateTime d1, DateTime d2)
{
	int s1 = d1.Date::operator-(d2);
	int s2 = d1.Time::operator-(d2);
	return 3600LL * 24 * s1 + s2;
}

DateTime& DateTime::operator ++()
{
	if (hour == 23 && minute == 59 && second == 59)
		(*this).Date::operator++();
	(*this).Time::operator++();
	return *this;
}
DateTime DateTime::operator ++(int)
{
	DateTime old = *this;
	if (hour == 23 && minute == 59 && second == 59)
		(*this).Date::operator++();
	(*this).Time::operator++();
	return old;
}
DateTime& DateTime::operator --()
{
	if (!hour && !minute && !second)
		(*this).Date::operator--();
	(*this).Time::operator--();
	return *this;
}
DateTime DateTime::operator --(int)
{
	DateTime old = *this;
	if (!hour && !minute && !second)
		(*this).Date::operator--();
	(*this).Time::operator--();
	return old;
}
