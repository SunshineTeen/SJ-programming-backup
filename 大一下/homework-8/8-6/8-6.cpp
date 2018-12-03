//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N = 3;

class cuboid
{
private:
	int length, width, height;
public:
	bool input();
	void output();
};

int main()
{
	For(i, 1, N)
	{
		cuboid A;
		printf("请输入第%d个长方体的长、宽、高:",i);
		while (!A.input())
		{
			printf("输入有误，请重新输入:");
			continue;
		}
		printf("第%d个长方体的体积为:",i);
		A.output();
	}
	return 0;
}

bool cuboid::input()
{
	cin >> length >> width >> height;
	if (cin.fail() || length <= 0 || width <= 0 || height <= 0)
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}
	return 1;
}
void cuboid::output()
{
	cout << length*width*height << endl;
}