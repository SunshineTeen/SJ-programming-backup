//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::~TString()
{
	delete[] content;
	len = 0;
}
TString::TString(const char *const ch)
{
	if (ch == NULL)
	{
		len = 0;
		content = NULL;
		return;
	}
	len = strlen(ch);
	content = new(nothrow) char[len + 1];
	if (content == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	for (int i = 0; i <= len; ++i)
		content[i] = ch[i];
}
TString::TString(const TString &rhs)
{
	len = rhs.len;
	if (!len)
	{
		content = NULL;
		return;
	}
	content = new(nothrow) char[len + 1];
	if (content == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	for (int i = 0; i <= len; ++i)
		content[i] = rhs.content[i];
}

istream& operator >>(istream &it, TString &rhs)
{
	char *buff = NULL;
	int block = 0, p = 0;
	char ch;
	while (1)
	{
		ch = it.get();
		if (ch == ' ' || ch == '\n')
			ch = '\0';
		if (!(p % block_size))
			Realloc(buff,block);
		buff[p++] = ch;
		if (ch == '\0')
			break;
	}
	rhs = buff;
	return it;
}
ostream& operator <<(ostream &it, TString &rhs)
{
	if (!rhs.len)
		it << "<NULL>" << endl;
	else
	{
		for (int i = 0; i < rhs.len; ++i)
			it << rhs.content[i];
		cout << endl;
	}
	return it;
}

TString& TString::operator =(const TString &rhs)
{
	delete[] content;
	len = rhs.len;
	if (rhs.content == NULL)
		content = NULL;
	else
	{
		content = new(nothrow) char[len + 1];
		if (content == NULL)
		{
			puts("No Free Memory");
			exit(-1);
		}
		for (int i = 0; i <= len; ++i)
			content[i] = rhs.content[i];
	}
	return *this;
}

TString operator +(const TString &s1, const TString &s2)
{
	TString s;
	bool dNULL = s1.content != NULL && s2.content != NULL;
	s.len = s1.len + s2.len;
	s.content = new(nothrow) char[s.len + dNULL];
	for (int i = 0; i < s1.len; ++i)
		s.content[i] = s1.content[i];
	for (int i = 0; i < s2.len; ++i)
		s.content[s1.len + i] = s2.content[i];
	if(dNULL)
		s.content[s.len] = '\0';
	return s;
}
TString operator +(const TString &s1, const char *const s2)
{
	TString s;
	bool dNULL = s1.content != NULL && s2 != NULL;
	int len2 = s2 == NULL ? 0 : strlen(s2);
	s.len = s1.len + len2;
	s.content = new(nothrow) char[s.len + dNULL];
	if(s1.content!=NULL)
		memcpy(s.content, s1.content, s1.len);
	if (s2 != NULL)
		memcpy(s.content + s1.len, s2, len2);
	if (dNULL)
		s.content[s.len] = '\0';
	return s;
}
TString operator +(const char *const s1, const TString &s2)
{
	TString s;
	bool dNULL = s1 != NULL && s2.content != NULL;
	int len1 = s1 == NULL ? 0 : strlen(s1);
	s.len = len1 + s2.len;
	s.content = new(nothrow) char[s.len + dNULL];
	if (s1 != NULL)
		memcpy(s.content, s1, len1);
	if (s2.content != NULL)
		memcpy(s.content + len1, s2.content, s2.len);
	if (dNULL)
		s.content[s.len] = '\0';
	return s;
}

bool operator >(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return s1.len > s2.len;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] > s2.content[i];
	return 0;
}
bool operator <(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return s1.len < s2.len;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] < s2.content[i];
	return 0;
}
bool operator >=(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return s1.len >= s2.len;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] >= s2.content[i];
	return 1;
}
bool operator <=(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return s1.len <= s2.len;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] <= s2.content[i];
	return 1;
}
bool operator ==(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return 0;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return 0;
	return 1;
}
bool operator !=(const TString &s1, const TString &s2)
{
	if (s1.len != s2.len)
		return 1;
	for (int i = 0; i < s1.len; ++i)
		if (s1.content[i] != s2.content[i])
			return 1;
	return 0;
}

int TString::length()const
{
	return len;
}

char& TString::operator [](const int i)const
{
	return content[i];
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
int TStringLen(const TString &rhs)
{
	return rhs.length();
}
void Realloc(char *&newbuff, int &block)
{
	char *oldbuff = new(nothrow)char[block*block_size];
	if (oldbuff == NULL)
	{
		delete[] newbuff;
		puts("No Free Memory");
		exit(-1);
	}
	memcpy(oldbuff, newbuff, block*block_size);
	delete[] newbuff;
	newbuff = new(nothrow)char[(++block)*block_size];
	if (newbuff == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	memcpy(newbuff, oldbuff, (block - 1)*block_size);
	delete[] oldbuff;
}


