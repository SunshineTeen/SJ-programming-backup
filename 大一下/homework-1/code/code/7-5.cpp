//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N = 10;
const float eps = 1e-3f;

struct student
{
	int no;
	char name[9];
	float score[3];
	float ave;
};

void work(student stu[])
{
	float max_s[3], tots[3];
	const float inf = -1;
	For(j, 0, 2)
	{
		max_s[j] = inf;
		tots[j] = 0;
		For(i, 1, N)
		{
			tots[j] += stu[i].score[j];
			if (stu[i].score[j] > max_s[j])
				max_s[j] = stu[i].score[j];
		}
	}

	For(i, 0, 2)
		printf("第%d门学科的平均分为:%.2f\n", i + 1, tots[i] / N);
	For(j, 0, 2)
	{
		printf("----------------------------------\n");
		printf("第%d门学科最高分的学生信息如下:\n", j + 1);
		For(i, 1, N)
			if (fabs(stu[i].score[j] - max_s[j]) < eps)
			{
				printf("学号:%d 姓名:%s ", stu[i].no, stu[i].name);
				printf("第一门成绩:%.1f 第二门成绩:%.1f 第三们成绩:%.1f ", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				printf("平均成绩:%.2f\n", stu[i].ave);
			}
	}
}

void init_score(int i, float &score)
{
	printf("请输入该学生的第%d门学科成绩:", i + 1);
	while (1)
	{
		cin >> score;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			printf("请输入正确的成绩:");
			cin >> score;
		}
		if (score < 0 || score>100)
		{
			printf("请输入正确的成绩:");
			continue;
		}
		return;
	}
}
void init_name(char name[])
{
	printf("请输入该学生的姓名:");
	scanf(" %s", name);
}
void init_no(int i, int &no)
{
	printf("请输入第%d个学生的学号:", i);
	cin >> no;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		printf("请输入正确的学号:");
		cin >> no;
	}
}
void init(int i, student &stu)
{
	init_no(i, stu.no);
	init_name(stu.name);
	init_score(0, stu.score[0]);
	init_score(1, stu.score[1]);
	init_score(2, stu.score[2]);
	printf("----------------------------------\n");
	stu.ave = (stu.score[0] + stu.score[1] + stu.score[2]) / 3;
}

int main()
{
	student stu[N + 5];
	For(i, 1, N)
		init(i, stu[i]);
	work(stu);

	return 0;
}