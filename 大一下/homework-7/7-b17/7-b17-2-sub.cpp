//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<io.h>
#include<conio.h>
#include<experimental/filesystem>
#include "7-b17-2.h"

using namespace std;

char peek(FILE *fp)
{
	char res;
	fread(&res, 1, 1, fp);
	fseek(fp, -1, SEEK_CUR);
	return res;
}

int find_group(FILE *fp, const char *group_name)
{
	fseek(fp, 0, SEEK_SET);
	char tmp[Maxm] = "Taihou";
	while (!feof(fp))
	{
		int pos = int(ftell(fp));
		fgets(tmp, sizeof(tmp), fp);
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
int find_item(FILE *fp, const int st, const char *item_name, int *val_p)
{
	fseek(fp, st, SEEK_SET);
	char tmp[Maxm] = "Taihou";
	while (1)
	{
		int pos = int(ftell(fp));
		fgets(tmp, sizeof(tmp), fp);
		if (!strcmp(tmp, "\r\n"))
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
void cpy_info(FILE *fp, const int l, const int r, char cpy[], int &cnt)
{
	if (l == r)
		return;
	fseek(fp, l, SEEK_SET);
	For(i, l, r)
		cpy[cnt++] = fgetc(fp);
}
void re_output(FILE *fp, char st1[], const int n, char st2[], const int m, const void *item_value, const enum ITEM_TYPE item_type, const bool add)
{
	_chsize(_fileno(fp), 0);

	fseek(fp, 0, SEEK_SET);
	fwrite(st1, n, 1, fp);
	if (item_value != NULL)
	{
		if (item_type == TYPE_INT)
			fprintf(fp, "%d", *((int*)item_value));
		else if (item_type == TYPE_DOUBLE)
			fprintf(fp, "%lf", *((double*)item_value));
		else if (item_type == TYPE_STRING)
			fprintf(fp, "%s", (char*)item_value);
		else if (item_type == TYPE_CHARACTER)
			fprintf(fp, "%c", char(*((char*)item_value)));
	}
	if (add)
		fputc('\r', fp), fputc('\n', fp);
	fwrite(st2, m, 1, fp);
}
void get_value(FILE *fp, const int pos, const void *item_value, const enum ITEM_TYPE item_type)
{
	fseek(fp, pos, SEEK_SET);
	if (item_type == TYPE_NULL)
		return;

	char tmp[Maxm] = "Taihou";
	fgets(tmp, sizeof(tmp), fp);
	tmp[strlen(tmp) - 2] = '\0';
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

int group_add(FILE *fp, const char *group_name)
{
	if (find_group(fp, group_name) != -1)
		return 0;

	fseek(fp, 0, SEEK_END);
	fputc('[', fp);
	fwrite(group_name, strlen(group_name), 1, fp);
	fputc(']', fp);
	fputc('\r', fp);
	fputc('\n', fp);
	fputc('\r', fp);
	fputc('\n', fp);

	return 1;
}

int group_del(FILE *fp, const char *group_name)
{
	fseek(fp, 0, SEEK_END);
	int end = int(ftell(fp));

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

	fseek(fp, l + 1, SEEK_SET);
	while (1)
	{
		while (fgetc(fp) != '\n');
		if (peek(fp) == '\r')
			break;
	}
	fseek(fp, 2, SEEK_CUR);

	char *cpy2 = new(nothrow)char[end - ftell(fp)];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(ftell(fp)), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_add(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	fseek(fp, 0, SEEK_END);
	int end = int(ftell(fp));

	int l = find_group(fp, group_name);
	if (l == -1)
		return 0;
	l = find_item(fp, l, item_name);
	if (l != -1)
		return 0;

	fseek(fp, -3, SEEK_CUR);
	int len = strlen(item_name);
	char *cpy1 = new(nothrow) char[int(ftell(fp)) + len + 2];
	if (cpy1 == NULL)
	{
		printf("No Free Memory\n");
		return 0;
	}
	int cnt1 = 0;
	cpy_info(fp, 0, int(ftell(fp)), cpy1, cnt1);
	sFor(i, 0, len)
		cpy1[cnt1++] = item_name[i];
	cpy1[cnt1++] = '=';

	char *cpy2 = new(nothrow)char[end - int(ftell(fp))];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(ftell(fp)), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2, item_value, item_type, 1);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_del(FILE *fp, const char *group_name, const char *item_name)
{
	fseek(fp, 0, SEEK_END);
	int end = int(ftell(fp));

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

	while (fgetc(fp) != '\n');
	char *cpy2 = new(nothrow)char[end - int(ftell(fp))];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(ftell(fp)), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_update(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{
	fseek(fp, 0, SEEK_END);
	int end = int(ftell(fp));

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

	while (fgetc(fp) != '\n');
	char *cpy2 = new(nothrow)char[end - int(ftell(fp))];
	if (cpy2 == NULL)
	{
		printf("No Free Memory\n");
		delete[]cpy1;
		return 0;
	}
	int cnt2 = 0;
	cpy_info(fp, int(ftell(fp)), end - 1, cpy2, cnt2);

	re_output(fp, cpy1, cnt1, cpy2, cnt2, item_value, item_type, 1);
	delete[]cpy1;
	delete[]cpy2;
	return 1;
}

int item_get_value(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
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
