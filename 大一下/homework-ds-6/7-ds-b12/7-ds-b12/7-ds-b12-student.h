//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

using namespace std;

class student
{
public:
	student& operator =(const student &);

	bool operator ==(const student&)const;
	bool operator !=(const student&)const;

	friend istream& operator >> (istream&, student&);
	friend ostream& operator << (ostream&, const student&);
protected:
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
};
