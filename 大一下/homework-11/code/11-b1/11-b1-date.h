//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

using namespace std;

#define MaxYear 2099
#define MinYear 1900
#define MaxMonth 12
#define MinMonth 1

const int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const int Year = 365;

class Date
{
public:
	Date(int, int, int);
	Date(int = 0);
	void set(int, int, int);

	friend istream& operator >> (istream &it, Date &rhs);
	friend ostream& operator <<(ostream &it, const Date &rhs);

	Date operator +(const int)const;
	Date operator -(const int)const;
	int operator -(Date)const;
	Date& operator +=(const int);
	Date& operator -=(const int);

	Date& operator ++();
	Date operator ++(int);
	Date& operator --();
	Date operator --(int);

	bool operator >(const Date &rhs)const;
	bool operator <(const Date &rhs)const;
	bool operator >=(const Date &rhs)const;
	bool operator <=(const Date &rhs)const;
	bool operator ==(const Date &rhs)const;
	bool operator !=(const Date &rhs)const;
protected:
	int year, month, day;
	Date getDateClass();
};

bool Leapyear(const int);
void days2date(int, int&, int&, int&);
int date2days(const int, const int, const int);
