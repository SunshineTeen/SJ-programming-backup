//����������Դ �༶�������1�� ѧ�ţ�1652228

#include<iostream>

using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	void input();
	void output();
	
};
int main()
{
	Time t1;
	t1.input();
	t1.output();
	return 0;
}

void Time::input()
{
	cin >> hour >> minute >> sec;
}
void Time::output()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}
