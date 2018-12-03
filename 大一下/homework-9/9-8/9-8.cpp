//姓名：王哲源 班级：计算机1班 学号：1652228

#include <iostream>

using namespace std;

class Student
{
public:
	Student(int n, float s) :num(n), score(s)
	{
	}
	void change(int n, float s)
	{
		num = n;
		score = s;
	}
	void display()
	{
		cout << num << " " << score << endl;
	}
private:
	int num;
	float score;
};
void fun(Student &stud)
{
	stud.change(101, 78.5);
	stud.display();
	stud.change(101, 80.5);
	stud.display();
}
int main()
{
	Student stud(0, 0);
	fun(stud);
	return 0;
}