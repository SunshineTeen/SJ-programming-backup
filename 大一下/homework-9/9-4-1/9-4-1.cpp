//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
using namespace std;

class student {
private:
	int num;
	float score;
public:
	void display();   //输出学号和成绩
					  /* 给出需要的其它成员函数的定义，数量不限 */
	student(int _num, float _score) :num(_num), score(_score)
	{
	}
};

/* 在此给出类成员函数的实现（体外方式） */
void student::display()
{
	cout << "学号：" << num << "  成绩：" << score << endl;
}

int main()
{
	student *p, s[5] = { student(1001, 78.5),
		student(1002, 63.5),
		student(1003, 87.5),
		student(1004, 52.5),
		student(1005, 34.5) };
	/* 下面输出 1001、1003、1005三个人的信息
	【注意：】不允许再定义任何类型的变量 */
	for (p = s; p < s + 5; p += 2)
		p->display();
	return 0;
}