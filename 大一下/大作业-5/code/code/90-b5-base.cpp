// 班级:计算机一班 学号:1652228 姓名:王哲源

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include "90-b5-base.h"

using namespace std;

bigint::bigint()
{
	num = NULL;
	len = block = f = 0;
}
bigint::~bigint()
{
	delete[] num;
	num = NULL;
	len = block = f = 0;
}
bigint::bigint(const bigint &rhs)
{
	len = rhs.len;
	block = rhs.block;
	f = rhs.f;
	int size = block*Each_Block;
	if (len == 1 && rhs.num[0] == 0)
		f = 0;
	num = new(nothrow)LL[size];
	if (num == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	memcpy(num, rhs.num, size);
}
bigint::bigint(LL n)
{
	block = 1;
	f = n >= 0 ? 0 : 1;
	n = abs(n);
	num = new(nothrow)LL[Each_Block];
	if (num == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	if (!n)
		len = 1, num[0] = 0;
	else
	{
		while (n)
			num[len++] = n%Max, n /= Max;
	}
	sFor(i, len, Each_Block)
		num[i] = 0;
}

void bigint::reset()
{
	delete[] num;
	num = NULL;
	len = block = 0;
}
bigint& bigint::operator =(const bigint &rhs)
{
	(*this).reset();
	len = rhs.len;
	block = rhs.block;
	f = rhs.f;
	int size = block*Each_Block;
	num = new(nothrow)LL[size];
	if (num == NULL)
	{
		puts("No Free Memory");
		exit(-1);
	}
	memcpy(num, rhs.num, size);
	return *this;
}

istream& operator >>(istream &it, bigint &rhs)
{
	rhs.reset();
	char ch;
	string n = "";
	while (!isdigit(ch = it.get()))
		if (ch == '-')
			break;
	if (ch == '-')
		rhs.f = 1;
	else
		n += ch;
	while (isdigit(ch = it.get()))
		n += ch;
	rhs.len = n.length() / Maxn + !!(n.length() % Maxn);
	int size;
	while ((size = (rhs.block*Each_Block)) < rhs.len) //////////括号啊大哥。。
		++rhs.block;
	rhs.num = new(nothrow) LL[size];
	if (rhs.num == NULL)
	{
		puts("No Free Memory");
		exit(Error);
	}
	int p = 0;
	for (int i = n.length() - 1; i >= 0;)
	{
		LL v = 0, m = 1;
		int cnt = 0;
		for (; i >= 0 && cnt < Maxn; --i, ++cnt)
			v += (n[i] - 48)*m, m *= 10;
		rhs.num[p++] = v;
	}
	sFor(i, rhs.len, size)
		rhs.num[i] = 0;
	return it;
}
ostream& operator <<(ostream &it, bigint &rhs)
{
	if (rhs.f && !(rhs.len == 1 && rhs.num[0] == 0))
		it.put('-');
	it << rhs.num[rhs.len - 1];
	opFor(i, rhs.len - 2, 0)
		it << setw(Maxn) << setiosflags(ios::right) << setfill('0') << rhs.num[i];
	return it;
}

bigint bigint::operator -()const
{
	bigint c(*this);
	c.f ^= 1;
	return c;
}

void Upper(bigint &rhs)
{
	int p = 0;
	while (p<rhs.len)
	{
		if (rhs.num[p] >= Max)
		{
			if (p + 1 == rhs.len)
			{
				if (rhs.len == rhs.block*Each_Block)
					Realloc(rhs);
				++rhs.len;
			}
			LL tmp = rhs.num[p];
			rhs.num[p] = tmp%Max;
			rhs.num[p + 1] += tmp / Max;
		}
		++p;
	}
}
void Realloc(bigint &newbuffer)
{
	bigint oldbuffer(newbuffer);
	delete[] newbuffer.num;
	int size = (++newbuffer.block)*Each_Block;
	newbuffer.num = new(nothrow) LL[size];
	memcpy(newbuffer.num, oldbuffer.num, size - Each_Block);
	sFor(i, size - Each_Block, size)
		newbuffer.num[i] = 0;
}
void Freealloc(bigint &newbuffer)
{
	int res_block = 0, res_len = newbuffer.len;
	opFor(i, newbuffer.block - 1, 0)
	{
		int limit = i*Each_Block;
		for (; res_len >= limit; --res_len)
			if (newbuffer.num[i])
				break;
		if (res_len != limit - 1)
			res_block = i + 1;
	}
	
	if (!res_block)
		res_block = 1, newbuffer.len = 1;
	else
		newbuffer.len = res_len;
	if (res_block == newbuffer.block)
		return;
	bigint oldbuffer(newbuffer);
	delete[] newbuffer.num;
	int size = res_block*Each_Block;
	newbuffer.num = new(nothrow) LL[size];
	memcpy(newbuffer.num, oldbuffer.num, size);
}

bigint operator +(const bigint &a, const bigint &b)
{
	bigint c;
	if (a.f^b.f)
	{
		c = a.f ? b - (-a) : a - (-b);
		return c;
	}
	int len = Max(a.len, b.len);

	if (a.len > b.len)
	{
		c = a;
		opFor(i, b.len - 1, 0)
			c.num[i] += b.num[i];
	}
	else
	{
		c = b;
		opFor(i, a.len - 1, 0)
			c.num[i] += a.num[i];
	}
	Upper(c);
	return c;
}
bigint operator -(const bigint &a, const bigint &b)
{
	bigint c;
	if (a.f^b.f)
	{
		c = a.f ? -((-a) + b) : a + (-b);
		return c;
	}
	if ((!a.f && a > b) || (a.f && -a < -b))
	{
		c = a;
		c.f = 0;
		sFor(i, 0, b.len)
		{
			c.num[i] -= b.num[i];
			if (c.num[i] < 0)
				c.num[i] += Max, --c.num[i + 1];
		}
	}
	else
	{
		c = b;
		c.f = 1;
		sFor(i, 0, a.len)
		{
			c.num[i] -= a.num[i];
			if (c.num[i] < 0)
				c.num[i] += Max, --c.num[i + 1];
		}
	}
	Freealloc(c);
	return c;
}
bigint& bigint::operator +=(const bigint &rhs)
{
	return (*this = (*this) + rhs);
}
bigint& bigint::operator -=(const bigint &rhs)
{
	return (*this = (*this) - rhs);
}
bigint bigint::operator ++(int)
{
	bigint old(*this);
	if (f)
	{
		if (len == 1 && num[0] == 1)
			f ^= 1, num[0] = 0;
		else
		{
			--num[0];
			int p = 0;
			while (num[p] < 0)
				num[p] += Max, --num[++p];
			Freealloc(*this);
		}
	}
	else
	{
		++num[0];
		if (num[0] >= Max)
			Upper(*this);
	}
	return old;
}
bigint bigint::operator --(int)
{
	bigint old(*this);
	if (!f)
	{
		if (len == 1 && num[0] == 0)
			f ^= 1, num[0] = 1;
		else
		{
			--num[0];
			int p = 0;
			while (num[p] < 0)
				num[p] += Max, --num[++p];
			Freealloc(*this);
		}
	}
	else
	{
		++num[0];
		if (num[0] >= Max)
			Upper(*this);
	}
	return old;
}
bigint& bigint::operator ++()
{
	if (f)
	{
		if (len == 1 && num[0] == 1)
			f ^= 1, num[0] = 0;
		else
		{
			--num[0];
			int p = 0;
			while (num[p] < 0)
				num[p] += Max, --num[++p];
			Freealloc(*this);
		}
	}
	else
	{
		++num[0];
		if (num[0] >= Max)
			Upper(*this);
	}
	return *this;
}
bigint& bigint::operator --()
{
	if (!f)
	{
		if (len == 1 && num[0] == 0)
			f ^= 1, num[0] = 1;
		else
		{
			--num[0];
			int p = 0;
			while (num[p] < 0)
				num[p] += Max, --num[++p];
			Freealloc(*this);
		}
	}
	else
	{
		++num[0];
		if (num[0] >= Max)
			Upper(*this);
	}
	return *this;
}

bigint operator *(const bigint &a, const bigint &b)
{
	bigint c;
	c.f = a.f^b.f;
	int limit = Each_Block*b.block;
	c.block = b.block;
	c.num = new(nothrow) LL[limit];
	if (c.num == NULL)
	{
		puts("No Free Memory");
		exit(Error);
	}
	sFor(i, 0, limit)
		c.num[i] = 0;
	sFor(i, 0, a.len)
	{
		sFor(j, 0, b.len)
		{
			if (i + j >= limit)
				Realloc(c), limit += Each_Block;
			c.num[i + j] += a.num[i] * b.num[j];
		}
		if (c.len < b.len + i)
			c.len = b.len + i;
		Upper(c);
	}
	return c;
}
bigint operator /(const bigint &a, const bigint &b)
{
	if (b.len == 1 && b.num[0] == 0)
	{
		puts("The divisor cannot be 0");
		exit(Error);
	}
	if ((a.f && b.f && a > b) || (!a.f && !b.f && a < b) || (a.f && !b.f && -a < b) || (!a.f && b.f && a < b))
	{
		bigint c(0);
		return c;
	}
	bigint ta(a), tb(a), c(a);
	c.f = a.f^b.f;
	ta.f = tb.f = 0;
	opFor(i, a.len - 1, 0)
		c.num[i] = 0;
	int p = a.len - 1;
	sFor(i, 0, b.len)
		tb.num[p--] = b.num[b.len - i - 1];
	int base = p;
	opFor(i, p, 0)
		tb.num[i] = 0;
	opFor(i, a.len - b.len, 0)
	{
		while (ta >= tb)
			++c.num[i], ta -= tb;
		if (base < 0)
			break;
		--tb.len;
		sFor(j, base, tb.len)
			tb.num[j] = tb.num[j + 1];
		--base;
	}
	Freealloc(c);
	return c;
}
bigint operator %(const bigint &a, const bigint &b)
{
	if (b.len == 1 && b.num[0] == 0)
	{
		puts("The divisor cannot be 0");
		exit(Error);
	}
	if ((a.f && b.f && a > b) || (!a.f && !b.f && a < b) || (a.f && !b.f && -a < b) || (!a.f && b.f && a < b))
	{
		bigint c(a);
		return c;
	}
	bigint ta(a), tb(a), c(a);
	c.f = a.f^b.f;
	ta.f = tb.f = 0;
	opFor(i, a.len - 1, 0)
		c.num[i] = 0;
	int p = a.len - 1;
	sFor(i, 0, b.len)
		tb.num[p--] = b.num[b.len - i - 1];
	int base = p;
	opFor(i, p, 0)
		tb.num[i] = 0;
	opFor(i, a.len - b.len, 0)
	{
		while (ta >= tb)
			++c.num[i], ta -= tb;
		if (base < 0)
			break;
		--tb.len;
		sFor(j, base, tb.len)
			tb.num[j] = tb.num[j + 1];
		--base;
	}
	Freealloc(ta);
	ta.f = a.f;
	return ta;
}
bigint& bigint::operator *=(const bigint &rhs)
{
	return (*this = *this*rhs);
}
bigint& bigint::operator /=(const bigint &rhs)
{
	return (*this = *this/rhs);
}
bigint& bigint::operator %=(const bigint &rhs)
{
	return (*this = *this%rhs);
}

bool operator >(const bigint &a, const bigint &b)
{
	if (a.f || b.f)
	{
		if (a.f && b.f)
			return -a < -b;
		else
			return !a.f;
	}

	if (a.len != b.len)
		return a.len > b.len;
	opFor(i, a.len - 1, 0)
		if (a.num[i] != b.num[i])
			return a.num[i] > b.num[i];
	return 0;
}
bool operator <(const bigint &a, const bigint &b)
{
	if (a.f || b.f)
	{
		if (a.f && b.f)
			return -a > -b;
		else
			return a.f;
	}

	if (a.len != b.len)
		return a.len < b.len;
	opFor(i, a.len - 1, 0)
		if (a.num[i] != b.num[i])
			return a.num[i] < b.num[i];
	return 0;
}
bool operator >=(const bigint &a, const bigint &b)
{
	if (a.f || b.f)
	{
		if (a.f && b.f)
			return -a <= -b;
		else
			return !a.f;
	}

	if (a.len != b.len)
		return a.len > b.len;
	opFor(i, a.len - 1, 0)
		if (a.num[i] != b.num[i])
			return a.num[i] > b.num[i];
	return 1;
}
bool operator <=(const bigint &a, const bigint &b)
{
	if (a.f || b.f)
	{
		if (a.f && b.f)
			return -a >= -b;
		else
			return a.f;
	}

	if (a.len != b.len)
		return a.len < b.len;
	opFor(i, a.len - 1, 0)
		if (a.num[i] != b.num[i])
			return a.num[i] < b.num[i];
	return 1;
}
bool operator ==(const bigint &a, const bigint &b)
{
	if (a.f^b.f || a.len != b.len)
		return 0;
	sFor(i, 0, a.len)
		if (a.num[i] != b.num[i])
			return 0;
	return 1;
}
bool operator !=(const bigint &a, const bigint &b)
{
	if (a.f^b.f || a.len != b.len)
		return 1;
	sFor(i, 0, a.len)
		if (a.num[i] != b.num[i])
			return 1;
	return 0;
}
