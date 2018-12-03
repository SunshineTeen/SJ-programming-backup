//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
	private:
		int year;
		int month;
		int day;
	public:
	/* 根据需要定义所需的成员函数、友元函数等 */
		Date();
		Date(const int, const int, const int);

		void set(const int, const int = 1, const int = 1);
		void get(int &, int &, int &);
		void show()const;

		Date(int);
		operator int()const;

		friend Date operator +(const Date,const int);
		friend Date operator +(const int, const Date);
		friend Date operator -(const Date, const int);
		friend int operator -(const Date, const Date);

		friend Date& operator ++(Date &);
		friend Date operator ++(Date &, int);
		friend Date& operator --(Date &);
		friend Date operator --(Date &, int);

		friend istream& operator >>(istream&, Date&);
		friend ostream& operator <<(ostream&, Date&);

		bool operator ==(const Date&)const;
		bool operator !=(const Date&)const;
		friend bool operator <(const Date, const Date);
		friend bool operator <=(const Date, const Date);
		friend bool operator >(const Date, const Date);
		friend bool operator >=(const Date, const Date);
};

/* 如果有其它全局函数需要声明，写于此处 */
bool Leapyear(const int);
void days2date(int, int &, int &, int &);
void date2days(int &, const int, const int, const int);

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int Maxy = 2099;
const int Miny = 1900;
const int Maxm = 12;
const int Minm = 1;
const int Year = 365;
const int limitd = 73049;
const int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
