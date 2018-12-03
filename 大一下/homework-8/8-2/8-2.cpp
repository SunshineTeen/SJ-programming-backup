//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	void input()
	{
		cin >> hour >> minute >> sec;
	}
	void output()
	{
		cout << hour << ":" << minute << ":" << sec << endl;
	}
};
int main()
{
	Time t1;
	t1.input();
	t1.output();
	return 0;
}
