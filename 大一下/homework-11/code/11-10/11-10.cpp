//姓名：王哲源 班级：计算机1班 学号：1652228
#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	Teacher(int _num, string _name, char _sex)
	{
		num = _num;
		name = _name;
		sex = _sex;
	}
	void output()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
private:
	int num;
	string name;
	char sex;
};

class BirthDate
{
public:
	void set(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	void output()
	{
		cout << "year:" << year << endl;
		cout << "month:" << month << endl;
		cout << "day:" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

class Professor :public Teacher
{
public:
	Professor(int _num, string _name, char _sex, int _year, int _month, int _day) :Teacher(_num, _name, _sex)
	{
		birthday.set(_year, _month, _day);
	}
	void change(int _year, int _month, int _day)
	{
		birthday.set(_year, _month, _day);
	}
	void output()
	{
		Teacher::output();
		birthday.output();
	}
private:
	BirthDate birthday;
};

int main()
{
	Professor prof1(153,"Taihou",'f',1941,7,10);
	prof1.change(1944, 3, 7);
	prof1.output();

	return 0;
}
//Data:
//153 Taihou f 1941 7 10
//Output:
//num:153
//name:Taihou
//sex:f
//year:1944
//month:3
//day:7