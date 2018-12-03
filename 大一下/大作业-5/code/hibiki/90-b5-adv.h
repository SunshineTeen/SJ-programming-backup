/*1652191 卓弋然 计算机1*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <io.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

struct Elem
{
	int data[200];
	int exp;  //exp * 200 + data下标 就得到该数字的位数 exp>=0
	Elem *prior;
	Elem *next;
};

class bigint
{
private:
	bool notation = 1;  //notation == 1为正
	int len = 0;  //用于记录位数
	Elem *head = NULL;  //带头结点的双向链表
	Elem *tail = NULL;
public:
	bigint();
	bigint(const int& pa);
	bigint(const bigint& a);

	~bigint();

	bigint& operator=(bigint &a);
	bigint& bigint::operator=(const int& p);
	friend istream& operator >> (istream &in, bigint &a);
	friend ostream& operator << (ostream &out, bigint &a);
	friend bigint operator+(const bigint &a, const bigint &b);
	friend bigint operator-(const bigint &a, const bigint &b);
	friend bigint operator*(const bigint &a, const bigint &b);
	friend bigint operator/(const bigint &a, const bigint &b);
	friend bigint operator%(const bigint &a, const bigint &b);
	friend bigint operator+=(bigint &a, const bigint &b);
	friend bigint operator-=(bigint &a, const bigint &b);
	friend bigint operator*=(bigint &a, const bigint &b);
	friend bigint operator/=(bigint &a, const bigint &b);
	friend bigint operator%=(bigint &a, const bigint &b);

	friend bigint abs_plus(Elem **a_head, Elem **a_tail, Elem **b_head, Elem **b_tail, int a_len, int b_len, int &len);
	friend bigint abs_minus_abs(Elem **a_head, Elem **a_tail, Elem **b_head, Elem **b_tail, int a_len, int b_len, int &len);
	friend bool abs_bigger_or_equal(Elem *a_head, Elem *a_tail, Elem *b_head, Elem *b_tail, int a_len, int b_len);
	friend void abs_minus_equal(Elem **a_head, Elem **a_tail, Elem *b_head, Elem *b_tail, int a_len, int b_len, int a_pos, int b_pos = 1, int mode = 1);

	friend bool operator==(const bigint &a, const bigint &b);
	friend bool operator!=(const bigint &a, const bigint &b);
	friend bool operator>=(const bigint &a, const bigint &b);
	friend bool operator<=(const bigint &a, const bigint &b);
	friend bool operator>(const bigint &a, const bigint &b);
	friend bool operator<(const bigint &a, const bigint &b);

	friend bigint operator+(bigint &a);
	friend bigint operator-(bigint &a);
	friend bigint& operator++(bigint &a);
	friend bigint& operator--(bigint &a);
	friend bigint operator++(bigint &a, int);
	friend bigint operator--(bigint &a, int);
	//friend void test_(bigint &a);
};
