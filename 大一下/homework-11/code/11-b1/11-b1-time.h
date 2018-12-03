//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

using namespace std;

#define Maxh 24
#define Max 60

class Time
{
public:
	Time(int, int, int);
	Time(int = 0);
	void set(int, int, int);

	friend istream& operator >> (istream &it, Time &rhs);
	friend ostream& operator <<(ostream &it, const Time &rhs);

	Time operator +(const int)const;
	Time operator -(const int)const;
	int operator -(Time)const;
	Time& operator +=(const int);
	Time& operator -=(const int);

	Time& operator ++();
	Time operator ++(int);
	Time& operator --();
	Time operator --(int);

	bool operator >(const Time &rhs)const;
	bool operator <(const Time &rhs)const;
	bool operator >=(const Time &rhs)const;
	bool operator <=(const Time &rhs)const;
	bool operator ==(const Time &rhs)const;
	bool operator !=(const Time &rhs)const;
protected:
	int hour, minute, second;
	Time getTimeClass();
};
