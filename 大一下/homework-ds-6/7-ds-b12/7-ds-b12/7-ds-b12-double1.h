//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

using namespace std;

class double1
{
public:
	double1& operator =(const double1 &rhs);

	bool operator ==(const double1&)const;
	bool operator !=(const double1&)const;

	friend istream& operator >> (istream&, double1&);
	friend ostream& operator << (ostream&, const double1&);
protected:
	double x;
};
