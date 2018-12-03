//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<experimental/filesystem>
#include "7-b17-1.h"

using namespace std;

int find_group(fstream &fp, const char *group_name)
{
	fp.clear();
	fp.seekg(0, ios::beg);
	char tmp[Maxm] = "Taihou";
	while (!fp.eof())
	{
		int pos = int(fp.tellg());
		fp.getline(tmp, sizeof(tmp), '\n');
		if (tmp[0] != '[')
			continue;
		char tmp_name[Maxm] = "Taihou";
		int p = 1;
		while (tmp[p] != ']')
			tmp_name[p - 1] = tmp[p++];
		tmp_name[--p] = '\0';
		if (!strcmp(tmp_name, group_name))
			return pos;
	}
	return -1;
}
int find_item(fstream &fp, const int st, const char *item_name, int *val_p)
{
	fp.clear();
	fp.seekg(st, ios::beg);
	char tmp[Maxm] = "Taihou";
	while (1)
	{
		int pos = int(fp.tellg());
		fp.getline(tmp, sizeof(tmp), '\n');
		if (!strcmp(tmp, "\r"))
			break;
		int p = 0;
		int len = strlen(item_name);
		for (; p < len; ++p)
			if (tmp[p] != item_name[p])
				break;
		if (p != len)
			continue;
		if (val_p != NULL)
			*val_p = pos + p + 1;
		return pos;
	}
	return -1;
}
void cpy_info(fstream &fp, const int l, const int r, char cpy[], int &cnt)
{
	if (l == r)
		return;
	fp.clear();
	fp.seekg(l, ios::beg);
	For(i, l, r)
		cpy[cnt++] = fp.get();
}
void re_output(fstream &fp, char st1[], const int n, char st2[], const int m, const void *item_value, const enum ITEM_TYPE item_type, const bool add)
{
	experimental::filesystem::resize_file(file_name, 0);

	fp.clear();
	fp.seekp(0, ios::beg);
	fp.write(st1, n);
	if (item_value != NULL)
	{
		if (item_type == TYPE_INT)
			fp << *((int*)item_value);
		else if (item_type == TYPE_DOUBLE)
			fp << *((double*)item_value);
		else if (item_type == TYPE_STRING)
			fp << (char*)item_value;
		else if (item_type == TYPE_CHARACTER)
			fp << char(*((char*)item_value));
	}
	if (add)
		fp.put('\r').put('\n');
	fp.write(st2, m);
}
void get_value(fstream &fp, const int pos, const void *item_value, const enum ITEM_TYPE item_type)
{
	fp.clear();
	fp.seekg(pos, ios::beg);
	if (item_type == TYPE_NULL)
		return;

	char tmp[Maxm] = "Taihou";
	fp.getline(tmp, sizeof(tmp), '\r');
	int p = 0;
	if (item_type == TYPE_INT)
	{
		bool f = 1;
		int v = 0;
		if (tmp[p] == '-')
			f = 0, p++;
		while (tmp[p] >= '0' && tmp[p] <= '9')
			v = v * 10 + tmp[p] - 48, ++p;
		*((int*)item_value) = f ? v : -v;
	}
	else if (item_type == TYPE_DOUBLE)
	{
		bool f = 1;
		double v = 0;
		if (tmp[p] == '-')
			f = 0, p++;
		while (tmp[p] >= '0' && tmp[p] <= '9')
			v = v * 10 + tmp[p] - 48, ++p;
		if (tmp[p] == '.')
		{
			double doc = 0.1;
			++p;
			while (tmp[p] >= '0' && tmp[p] <= '9')
				v += (tmp[p] - 48)*doc, doc *= 0.1, ++p;
		}
		*((double*)item_value) = f ? v : -v;
	}
	else if (item_type == TYPE_STRING)
		strcpy((char*)item_value, tmp);
	else if (item_type == TYPE_CHARACTER)
		*((char*)item_value) = tmp[0];
}

int group_add(fstream &fp, const char *group_name)
{
	if (find_group(fp, group_name) != -1)
		return 0;

	fp.clear();
	fp.seekp(0, ios::end);
	fp.put('[');
	fp.write(group_name, strlen(group_name));
	fp.put(']').put('\r').put('\n').put('\r').put('\n');

	return 1;
}

int group_del(fstream &fp, const char *group_name)
{
	fp.clear();
	fp.seekg(0, ios::end);
	int end = int(fp.tellg());

	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;

	char *cpy1 = new(nothrow) char[l];
	if (cpy1 == NULL)
	{
		printf("No Free Memory\n");
		return 0;
	}
	int cnt1 = 0;
	cpy_info(fp, 0, l - 1, cpy1, cnt1);

	fp.clear();
	fp.seekg(l + 1, ios::beg);
	while (1)
	{
		while (fp.get() != '\n');
		if (fp.peek() == '\r')
			break;
	}
	fp.seekg(2, ios::cur);

	char *cpy2 = new(nothrow)char[end - int(fp.tellg())];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(fp.tellg()), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	fp.clear();
	fp.seekg(0, ios::end);
	int end = int(fp.tellg());

	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;
	l = find_item(fp, l, item_name);
	if (l != -1)
		return 0;

	fp.seekg(-3, ios::cur);
	int len = strlen(item_name);
	char *cpy1 = new(nothrow) char[int(fp.tellg()) + len + 2];
	if (cpy1 == NULL)
	{
		printf("No Free Memory\n");
		return 0;
	}
	int cnt1 = 0;
	cpy_info(fp, 0, int(fp.tellg()), cpy1, cnt1);
	sFor(i, 0, len)
		cpy1[cnt1++] = item_name[i];
	cpy1[cnt1++] = '=';

	char *cpy2 = new(nothrow)char[end - int(fp.tellg())];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(fp.tellg()), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2, item_value, item_type, 1);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_del(fstream &fp, const char *group_name, const char *item_name)
{
	fp.clear();
	fp.seekg(0, ios::end);
	int end = int(fp.tellg());

	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;
	l = find_item(fp, l, item_name);
	if (l == -1)
		return 0;

	char *cpy1 = new(nothrow) char[l];
	if (cpy1 == NULL)
	{
		printf("No Free Memory\n");
		return 0;
	}
	int cnt1 = 0;
	cpy_info(fp, 0, l - 1, cpy1, cnt1);

	while (fp.get() != '\n');
	char *cpy2 = new(nothrow)char[end - int(fp.tellg())];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(fp.tellg()), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	fp.clear();
	fp.seekg(0, ios::end);
	int end = int(fp.tellg());

	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;
	int pos;
	l = find_item(fp, l, item_name, &pos);
	if (l == -1)
	{
		item_add(fp, group_name, item_name, item_value, item_type);
		return 1;
	}

	char *cpy1 = new(nothrow) char[pos];
	if (cpy1 == NULL)
	{
		printf("No Free Memory\n");
		return 0;
	}
	int cnt1 = 0;
	cpy_info(fp, 0, pos - 1, cpy1, cnt1);

	while (fp.get() != '\n');
	char *cpy2 = new(nothrow)char[end - int(fp.tellg())];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(fp.tellg()), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2, item_value, item_type, 1);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_get_value(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;
	int pos;
	l = find_item(fp, l, item_name, &pos);
	if (l == -1)
		return 0;

	get_value(fp, pos, item_value, item_type);
	return 1;
}
