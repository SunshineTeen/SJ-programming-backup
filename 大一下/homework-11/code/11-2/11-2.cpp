//姓名：王哲源 班级：计算机1班 学号：1652228
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << " num: " << num << endl;
		cout << " name: " << name << endl;
		cout << " sex: " << sex << endl;
	}
private:
	int num;
	string name;
	char sex;
};

class Student1 :private Student
{
public:
	void get_value_1()
	{
		get_value();
		cin >> age >> addr;
	}
	void display_1()
	{
		display();
		cout << " age: " << age << endl;
		cout << " address: " << addr << endl;
	}
private:
	int age;
	string addr;
};

int main()
{
	Student1 stud;
	stud.get_value_1();
	stud.display_1();
	return 0;
}
