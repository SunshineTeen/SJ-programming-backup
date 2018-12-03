//����������Դ �༶�������1�� ѧ�ţ�1652228

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
		printf("��%d��ѧ�Ƶ�ƽ����Ϊ:%.2f\n", i + 1, tots[i] / N);
	For(j, 0, 2)
	{
		printf("----------------------------------\n");
		printf("��%d��ѧ����߷ֵ�ѧ����Ϣ����:\n", j + 1);
		For(i, 1, N)
			if (fabs(stu[i].score[j] - max_s[j]) < eps)
			{
				printf("ѧ��:%d ����:%s ", stu[i].no, stu[i].name);
				printf("��һ�ųɼ�:%.1f �ڶ��ųɼ�:%.1f �����ǳɼ�:%.1f ", stu[i].score[0], stu[i].score[1], stu[i].score[2]);
				printf("ƽ���ɼ�:%.2f\n", stu[i].ave);
			}
	}
}

void init_score(int i, float &score)
{
	printf("�������ѧ���ĵ�%d��ѧ�Ƴɼ�:", i + 1);
	while (1)
	{
		cin >> score;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			printf("��������ȷ�ĳɼ�:");
			cin >> score;
		}
		if (score < 0 || score>100)
		{
			printf("��������ȷ�ĳɼ�:");
			continue;
		}
		return;
	}
}
void init_name(char name[])
{
	printf("�������ѧ��������:");
	scanf(" %s", name);
}
void init_no(int i, int &no)
{
	printf("�������%d��ѧ����ѧ��:", i);
	cin >> no;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		printf("��������ȷ��ѧ��:");
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