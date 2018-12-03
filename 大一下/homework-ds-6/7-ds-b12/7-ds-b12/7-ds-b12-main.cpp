//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<conio.h>
#include"7-ds-b12-linear_list_L.cpp"

using namespace std;

int main()
{
	const int N = 5; //student类为5，其余为10
	cout << "【当前测试类型：student】" << endl;
	cout << "输入数据要求：" << endl;
	cout << "int:整数" << endl;
	cout << "double1:实数" << endl;
	cout << "string:字符串" << endl;
	cout << "student:学号(int范围内整数) 姓名(长度不超过9的字符串) 性别(单字符) 成绩(至多5位小数) 地址(长度不超过29的字符串)" << endl;
	LinkList<student> L;
	student e1, e2;
	int i, pos;

	cout << "空表=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl << endl;

	cout << "请依次输入" << N << "个元素【注意按照要求输入】：" << endl;
	for (i = N; i > 0; --i) 
		cin >> e1,L.ListInsert(1, e1);

	cout << "当前表内情况：" << endl;
	L.ListTraverse();
	
	cout << "空表=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl << endl;

	for (i = 0; i < 5; ++i)
	{
		int pos;
		switch (i)
		{
		case 0:
			pos = 1;
			break;
		case 1:
			pos = L.ListLength();
			break;
		case 2:
			pos = -1;
			break;
		case 3:
			pos = L.ListLength() + 1;
			break;
		case 4:
			cout << "请输入要取元素的位序[1.." << L.ListLength() << "]：";
			cin >> pos;
			break;
		}

		if (L.GetElem(pos, e1) == OK) 
		{
			cout << "第" << pos << "个元素=" << e1 << endl;

			if (L.PriorElem(e1, e2) == OK)
				cout << "第" << pos << "个元素(" << e1 << ")的前驱=" << e2 << endl;
			else
				cout << "无法取得第" << pos << "个元素(" << e1 << ")的前驱" << endl;

			if (L.NextElem(e1, e2) == OK)
				cout << "第" << pos << "个元素(" << e1 << ")的后继=" << e2 << endl;
			else
				cout << "无法取得第" << pos << "个元素(" << e1 << ")的后继" << endl;
		}
		else
			cout << "无法取得第" << pos << "个元素" << endl;
	} 

	cout << endl << "请输入要查找的元素的值" << endl;
	cin >> e1;

	if ((pos = L.LocateElem(e1)) > 0) 
		cout << "元素" << e1 << "的位序=" << pos << endl;
	else
		cout << "找不到元素" << e1 << endl;

	cout << endl << "请输入要插入元素的值" << endl;
	cin >> e1;
	cout << endl << "请输入要插入元素的位序：" << endl;
	cin >> pos;

	if (L.ListInsert(pos, e1) == OK) 
	{
		cout << "在第" << pos << "个元素前插入元素=" << e1 << "成功" << endl;
		cout << "新表为：" << endl;
		L.ListTraverse();
	}
	else
		cout << "在第" << pos << "个元素前插入元素=" << e1 << "失败" << endl;

	cout << endl << "请输入要删除元素的位序：" << endl;
	cin >> pos;

	if (L.ListDelete(pos, e1) == OK) 
	{
		cout << "删除第" << pos << "个元素=" << e1 << "成功" << endl;
		cout << "新表为：" << endl;
		L.ListTraverse();
	}
	else
		cout << "删除第" << pos << "个元素失败" << endl;

	cout << endl << "清空表：" << endl;
	L.ClearList();
	cout << "空表=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "表长=" << L.ListLength() << endl << endl;

	cout << "测试结束，按回车退出...";
	while (_getch() != '\r');
	return 0;
}
