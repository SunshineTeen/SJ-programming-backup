//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>
#include"11-b1-date.h"
#include"11-b1-time.h"

using namespace std;

typedef long long LL;

class DateTime :private Date, private Time
{
public:
	DateTime(int, int, int, int, int, int);
	DateTime(LL = 0);
	void set(int, int, int, int, int, int);

	friend istream& operator >> (istream &it, DateTime &rhs);
	friend ostream& operator <<(ostream &it, DateTime &rhs);

	DateTime operator +(const LL)const;
	friend DateTime operator +(const LL, DateTime);
	DateTime operator -(const LL)const;
	friend LL operator -(DateTime, DateTime);

	DateTime& operator ++();
	DateTime operator ++(int);
	DateTime& operator --();
	DateTime operator --(int);
private:

};
