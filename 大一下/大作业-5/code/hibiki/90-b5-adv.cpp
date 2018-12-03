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
#include "90-b5-adv.h"
using namespace std;

int destroy_list(Elem **head)
{
	Elem *p = (*head), *q;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}

	return 1;
}
int create_list(Elem **head, Elem **tail, int len)    //只负责链表创建，没有设置notation/len功能
{
	destroy_list(head);
	(*head) = (*tail) = new(nothrow) Elem;
	if ((*head) == NULL)
		return -1;
	int i = 0;
	(*head)->prior = (*head)->next = NULL;
	for (int i = 0; i < len / 1000 + 1; i++) {
		Elem *p = (*tail);
		*tail = new(nothrow) Elem;
		if ((*tail) == NULL)
			return -1;
		memset((*tail), -1, sizeof(Elem));
		p->next = (*tail);
		(*tail)->prior = p;
		(*tail)->next = NULL;
		p->exp = i;
		i++;
	}

	return 1;
}
int get_data(Elem **head, Elem **tail, int pos)  //pos >= 1，从最低位开始计数，注意pos和len的区别，pos是每五位为1
{
	pos--;
	int elem_no = pos / 200, subscript = pos % 200;
	//if (pos == 200)
	//	int asdfwegwew = 1;
	Elem *p = (*head)->next;
	for (int i = 0; i < elem_no; i++, p = p->next) {
		if (p == NULL) {
			Elem *q = new(nothrow) Elem;
			if (q == NULL)
				return -1;
			memset(q, -1, sizeof(Elem));
			(*tail)->next = q;
			q->prior = (*tail);
			q->next = NULL;
			p = (*tail) = q;
		}
	}
	if (p == NULL) {
		Elem *q = new(nothrow) Elem;
		if (q == NULL)
			return -1;
		memset(q, -1, sizeof(Elem));
		(*tail)->next = q;
		q->prior = (*tail);
		q->next = NULL;
		p = (*tail) = q;
	}

	if (p->data[subscript] == -1)
		return 0;
	return p->data[subscript];
}
int change_data(Elem **head, Elem **tail, int pos, int num)//pos >= 1，从最低位开始计数，注意pos和len的区别，pos是每五位为1
{
	pos--;
	int elem_no = pos / 200, subscript = pos % 200;
	//if (pos == 200)
	//	int sdfwerwer = 0;
	bool flag = 0;  //用于记录是否申请了新空间
	Elem *p = (*head)->next;
	for (int i = 0; i < elem_no; i++, p = p->next) {
		if (p == NULL) {
			Elem *q = new(nothrow) Elem;
			if (q == NULL)
				return -1;
			memset(q, -1, sizeof(Elem));
			(*tail)->next = q;
			q->prior = (*tail);
			q->next = NULL;
			p = (*tail) = q;
			flag = 1;
		}
	};
	if (p == NULL) {
		Elem *q = new(nothrow) Elem;
		if (q == NULL)
			return -1;
		memset(q, -1, sizeof(Elem));
		(*tail)->next = q;
		q->prior = (*tail);
		q->next = NULL;
		p = (*tail) = q;
		flag = 1;
	}

	p->data[subscript] = num;

	if (flag)
		return 2;
	return 1;
}
void correct_data(Elem **tail)
{
	Elem *p = (*tail);
	int i = 199;
	for (; p->data[i] == -1 && i >= 0; i--);

	if (!(p->prior->prior == NULL && i == 0))
		for (; p->data[i] == 0 && i >= 0; i--)
			p->data[i] = -1;

}
void correct_data_v2(Elem **head, Elem **tail)
{
	Elem *p = (*tail);
	int i = 199;
	for (; p != (*head)->next; ) {
		if (p != (*head)->next && p->data[0] == -1 || p->data[0] == 0) {
			Elem *q = p->prior;
			p->prior->next = p->next;
			if (p->next != NULL)
				p->next->prior = p->prior;
			delete p;
			p = q;
			(*tail) = p;
		}
		else
			break;
	}
	for (; p->data[i] == -1 && i >= 0; i--);

	for (; p->data[i] == 0 && i >= 0; i--)
		p->data[i] = -1;
}
int count_len(Elem* head, Elem* tail)
{
	Elem *p = head->next;
	int len = 0;
	for (; p != tail; p = p->next)
		len += 1000;
	//运行到此时 p 为 tail
	int i = 0;
	for (; p->data[i] != -1 && i != 200; i++)
		len += 5;
	i--;
	if (p->data[i] / 10 == 0)
		len -= 4;
	else if (p->data[i] / 100 == 0)
		len -= 3;
	else if (p->data[i] / 1000 == 0)
		len -= 2;
	else if (p->data[i] / 10000 == 0)
		len -= 1;

	return len;
}
bigint abs_plus(Elem **a_head, Elem **a_tail, Elem **b_head, Elem **b_tail, int a_len, int b_len, int &len)  //注意：这里的head、tail只是要运算部分的head、tail，并不一定是bigint的头、尾
{
	bigint c;
	int max_len, min_len;
	Elem *max_head, *min_head, *max_tail, *min_tail;
	if (a_len >= b_len) {
		max_len = a_len, min_len = b_len;
		max_head = *a_head, max_tail = *a_tail, min_head = *b_head, min_tail = *b_tail;
	}
	else {
		max_len = b_len, min_len = a_len;
		max_head = *b_head, max_tail = *b_tail, min_head = *a_head, min_tail = *a_tail;
	}
	len = max_len;

	int carry = 0, c_carry = 0;  //carry 记录x + y的进位，c_carry用来记录自身进位
	int i = 1;
	for (; i <= ((min_len - 1) / 5 + 1); i++) {
		int mid = get_data(&max_head, &max_tail, i) + get_data(&min_head, &min_tail, i);
		int c_i = mid % 100000;
		c_i += carry;
		c_i += c_carry;
		carry = mid / 100000;
		c_carry = c_i / 100000;
		change_data(&c.head, &c.tail, i, c_i % 100000);
	}

	for (; i <= ((max_len - 1) / 5 + 1); i++) {
		int mid = get_data(&max_head, &max_tail, i);
		int c_i = mid % 100000;
		c_i += carry;
		c_i += c_carry;
		carry = mid / 100000;
		c_carry = c_i / 100000;
		change_data(&c.head, &c.tail, i, c_i % 100000);
	}

	if (carry > 0 || c_carry > 0) {
		change_data(&c.head, &c.tail, i, 1);
		len++;
	}

	return c;
}
bigint abs_minus_abs(Elem **a_head, Elem **a_tail, Elem **b_head, Elem **b_tail, int a_len, int b_len, int &len) //绝对值的差的绝对值
{
	bigint c;
	int max_len, min_len;
	Elem *max_head, *min_head, *max_tail, *min_tail;
	if (a_len >= b_len) {
		max_len = a_len, min_len = b_len;
		max_head = *a_head, max_tail = *a_tail, min_head = *b_head, min_tail = *b_tail;
		c.notation = 1;
	}
	else {
		max_len = b_len, min_len = a_len;
		max_head = *b_head, max_tail = *b_tail, min_head = *a_head, min_tail = *a_tail;
		c.notation = 0;
	}

	len = max_len;

	int carry = 0;  //carry 进位
	int i = 1;
	for (; i <= ((min_len - 1) / 5 + 1); i++) {
		int x = get_data(&max_head, &max_tail, i);
		int y = get_data(&min_head, &min_tail, i);
		x += carry;
		if (x - y < 0)
			carry = -1;
		else
			carry = 0;
		int mid = (100000 + x - y) % 100000;
		change_data(&c.head, &c.tail, i, mid);
	}

	for (; i <= ((max_len - 1) / 5 + 1); i++) {
		int x = get_data(&max_head, &max_tail, i);
		x += carry;
		if (x < 0)
			carry = -1;
		else
			carry = 0;
		int mid = (100000 + x) % 100000;
		change_data(&c.head, &c.tail, i, mid);
	}

	int check = get_data(&max_head, &max_tail, i - 1);
	if (check == 0) {
		change_data(&c.head, &c.tail, i - 1, -1);
		len--;
	}

	return c;
}
void abs_plus_equal(Elem **a_head, Elem **a_tail, long long int b, int a_len, int a_pos = 1)
{
	int i = a_pos;
	long long int mid = (long long int)get_data(a_head, a_tail, i) + b;
	int carry = 0, c_carry = 0;
	int c_i = int(mid % 100000);
	c_i += carry;
	c_i += c_carry;
	carry = int(mid / 100000);
	c_carry = c_i / 100000;
	change_data(a_head, a_tail, i, c_i % 100000);
	a_len = count_len(*a_head, *a_tail);
	//correct_data(a_tail);

	for (i++; i <= ((a_len - 2) / 5 + 1); i++) {
		long long int mid = get_data(a_head, a_tail, i);
		int c_i = int(mid % 100000);
		if (carry == 0 && c_carry == 0)
			break;
		c_i += carry;
		c_i += c_carry;
		carry = int(mid / 100000);
		c_carry = c_i / 100000;
		change_data(a_head, a_tail, i, c_i % 100000);
		a_len = count_len(*a_head, *a_tail);
	}

	if (c_carry != 0 || carry != 0) {
		change_data(a_head, a_tail, i, carry + c_carry);
		a_len = count_len(*a_head, *a_tail);
	}
	correct_data(a_tail);

}
void abs_minus_equal(Elem **a_head, Elem **a_tail, Elem *b_head, Elem *b_tail, int a_len, int b_len, int a_pos, int b_pos, int mode)
{
	int carry = 0;  //carry 进位
	int i = a_pos;
	if (mode == 1)
		b_pos = a_pos;
	int j = b_pos;
	for (int k = 1; k <= ((b_len - 1) / 5 + 1); k++, j++, i++) {
		int x = get_data(a_head, a_tail, i);
		int y = get_data(&b_head, &b_tail, j);
		x += carry;
		if (x - y < 0)
			carry = -1;
		else
			carry = 0;
		int mid = (100000 + x - y) % 100000;
		change_data(a_head, a_tail, i, mid);
	}

	for (; i <= ((a_len - 1) / 5 + 1); i++) {
		int x = get_data(a_head, a_tail, i);
		if (carry == 0)
			break;
		x += carry;
		if (x < 0)
			carry = -1;
		else
			carry = 0;
		int mid = (100000 + x) % 100000;
		change_data(a_head, a_tail, i, mid);
	}

	correct_data(a_tail);

}
void abs_part_value(Elem **a_head, Elem **a_tail, Elem *b_head, Elem *b_tail, int b_len, int a_pos, int b_pos)
{
	int i = a_pos, j = b_pos;
	for (; j <= (b_len - 1) / 5 + 1; i++, j++) {
		int mid = get_data(&b_head, &b_tail, j);
		change_data(a_head, a_tail, i, mid);
	}
}

bool abs_bigger_or_equal(Elem *a_head, Elem *a_tail, Elem *b_head, Elem *b_tail, int a_len, int b_len)
{
	if (a_len > b_len)
		return 1;
	if (a_len < b_len)
		return 0;

	int len = a_len;
	for (int i = (len - 1) / 5 + 1; i >= 1; i--) {
		int a_num = get_data(&a_head, &a_tail, i), b_num = get_data(&b_head, &b_tail, i);
		if (a_num > b_num)
			return 1;
		if (a_num < b_num)
			return 0;
	}

	return 1;
}


bigint::bigint()
{
	head = new(nothrow) Elem;
	tail = new(nothrow) Elem;
	//if (tail == NULL || head == NULL)  /////////
	//	return;
	memset(tail, -1, sizeof(Elem));
	head->prior = NULL;
	head->next = tail;
	tail->prior = head;
	tail->next = NULL;
	tail->data[0] = 0;
	len = 1;
	tail->exp = 0;

}
bigint::bigint(const int& pa)
{
	long long int p = pa;
	head = new(nothrow) Elem;
	tail = new(nothrow) Elem;
	//if (tail == NULL || head == NULL)  ///////
	//	return;
	memset(tail, -1, sizeof(Elem));
	head->prior = NULL;
	head->next = tail;
	tail->prior = head;
	tail->next = NULL;
	tail->exp = 0;

	len = 1;
	if (p < 0) {  //如果是负数
		notation = 0;
		p = -1 * p;
	}
	long long int q = p;
	while (1) {
		q /= 10;
		if (q == 0)
			break;
		len++;
	}
	q = p;
	int num[8] = { -1, -1, -1, -1,-1, -1, -1 ,-1 };
	for (int i = 0; i < 8; i++) {
		num[i] = q % 100000;
		q /= 100000;
		if (q == 0)
			break;
	}
	for (int i = 0; i < 8; i++) {
		if (num[i] == -1)
			break;
		tail->data[i] = num[i];
	}
}
bigint::bigint(const bigint &a)
{
	head = tail = new(nothrow) Elem;
	//if (tail == NULL || head == NULL)   //////
	//	return;
	//tail = new(nothrow) Elem;
	head->prior = NULL;
	//head->next = tail;
	//tail->prior = head;
	tail->next = NULL;
	Elem* p = a.head->next;  //从首元素开始
	for (; p != NULL; p = p->next) {
		Elem *q = tail;
		tail = new(nothrow) Elem;
		memcpy(tail, p, sizeof(Elem));
		q->next = tail;
		tail->prior = q;
		tail->next = NULL;
	}
	len = a.len;
	notation = a.notation;
}

bigint::~bigint()
{
	destroy_list(&head);
	len = 0;
	notation = 1;
}

bigint& bigint::operator=(bigint &a)
{
	destroy_list(&head);
	head = tail = new(nothrow) Elem;
	//if (tail == NULL || head == NULL)   //////
	//	return;
	//tail = new(nothrow) Elem;
	head->prior = NULL;
	//head->next = tail;
	//tail->prior = head;
	tail->next = NULL;
	Elem* p = a.head->next;  //从首元素开始
	for (; p != NULL; p = p->next) {
		Elem *q = tail;
		tail = new(nothrow) Elem;
		//	if (tail == NULL)   //////
		//		return;
		memcpy(tail, p, sizeof(Elem));
		q->next = tail;
		tail->prior = q;
		tail->next = NULL;
	}
	len = a.len;
	notation = a.notation;

	return a;
}
bigint& bigint::operator=(const int& p)
{
	destroy_list(&head);
	head = new(nothrow) Elem;
	tail = new(nothrow) Elem;
	memset(tail, -1, sizeof(Elem));
	head->prior = NULL;
	head->next = tail;
	tail->prior = head;
	tail->next = NULL;

	int pa = p;
	if (p < 0) {  //如果是负数
		notation = 0;
		pa = -1 * p;
	}
	long long int q = pa;
	while (1) {
		q /= 10;
		if (q == 0)
			break;
		len++;
	}
	q = pa;
	int i = int(pow(10, len - 1));
	int num[8] = { -1, -1, -1, -1,-1, -1, -1 ,-1 };
	for (int i = 0; i < 8; i++) {
		num[i] = q % 100000;
		q /= 100000;
		if (q == 0)
			break;
	}
	for (int i = 0; i < 8; i++) {
		if (num[i] == -1)
			break;
		tail->data[i] = num[i];
	}

	return (*this);
}

istream& operator >> (istream &in, bigint &a)
{
	if (a.head != NULL)
		destroy_list(&a.head);
	a.head = a.tail = new(nothrow) Elem;
	//if (a.head == NULL || )   //////
	//	return;
	a.head->prior = NULL;
	a.tail->next = NULL;
	a.len = 0;
	a.notation = 1;

	char ch;
	string data = "";
	while (1) {
		ch = in.peek();
		if (ch == '-' || (ch >= '0' && ch <= '9'))
			break;
		else
			ch = in.get();
	}

	bool minus_flag = 0;  //等于1代表输入的是负数
	int num = 0, two_hundred = 1, exp_ = 0;  //two_hundred用于记录有多少个int[200]
	Elem *p = a.tail;
	ch = in.peek();      //如果是负数
	if (ch == '-') {
		a.notation = 0;
		minus_flag = 1;
		ch = in.get();
	}

	while (1) {
		ch = in.get();
		if (ch >= '0' && ch <= '9')
			data += ch;
		else
			break;
	}

	a.len = data.length();   ////////////////////////////////////////////////////////////注意string类的length()可能有误
	int length = a.len - 1, kp = 1;

	while (length > 4) {
		for (int i = 0; i < 5; i++) {
			ch = data[length - 4 + i];
			num = num * 10 + ch - '0';
		}
		length -= 5;

		//每读取五位数就将这五位数输入bigint中
		if (a.head == a.tail) {     //当head==tail是要先申请
			a.tail = new(nothrow) Elem;
			memset(a.tail, -1, sizeof(Elem));
			a.head->next = a.tail;
			a.tail->prior = a.head;
			a.tail->next = NULL;
			p = a.tail;
			p->exp = exp_;
			exp_++;
		}
		change_data(&a.head, &a.tail, kp, num);

		kp++;
		num = 0;
		if (length < 5)
			break;
	}


	num = 0;
	for (int i = 0; i <= length; i++) {
		ch = data[i];
		num = num * 10 + ch - '0';
	}

	change_data(&a.head, &a.tail, kp, num);

	return in;
}
ostream& operator << (ostream &out, bigint &a)
{
	Elem *p = a.tail;
	if (a.notation == 0)
		out << '-';

	int i = (a.len - 1) / 5 + 1;
	int x = get_data(&a.head, &a.tail, i);
	if (x != 0)
		out << get_data(&a.head, &a.tail, i);

	for (int i = (a.len - 1) / 5; i >= 1; i--)  //注意这里是i >= 1
		out << setw(5) << setfill('0') << get_data(&a.head, &a.tail, i);

	if (a.head->next->data[0] == 0 && a.head->next->data[1] == -1)
		out << '0';

	return out;
}
bigint operator+(const bigint &a, const bigint &b)
{
	bigint c;
	if (a.notation == 1 && b.notation == 0) {
		bigint d = b;
		d.notation = 0;
		c = a - d;
		return c;
	}
	if (a.notation == 0 && b.notation == 1) {
		bigint d = a;
		d.notation = 0;
		c = b - d;
		return c;
	}
	if (a.notation == 0 && b.notation == 0)
		c.notation = 0;
	if (a.notation == 1 && b.notation == 1)
		c.notation = 1;

	int len;
	Elem *a_head = a.head, *a_tail = a.tail, *b_head = b.head, *b_tail = b.tail;

	c = abs_plus(&a_head, &a_tail, &b_head, &b_tail, a.len, b.len, len);
	c.len = len;
	return c;
}
bigint operator-(const bigint &a, const bigint &b)
{
	bigint c;
	Elem *a_head = a.head, *a_tail = a.tail, *b_head = b.head, *b_tail = b.tail;
	if (a.notation == 1 && b.notation == 0) {
		int len;
		c = abs_plus(&a_head, &a_tail, &b_head, &b_tail, a.len, b.len, len);
		c.notation = 1;
		return c;
	}
	if (a.notation == 0 && b.notation == 1) {
		int len;
		c = abs_plus(&a_head, &a_tail, &b_head, &b_tail, a.len, b.len, len);
		c.notation = 0;
		return c;
	}
	bool flag = abs_bigger_or_equal(a.head, a.tail, b.head, b.tail, a.len, b.len);
	if (a.notation == 0 && b.notation == 0) {
		if (flag) {
			int len;
			c = abs_minus_abs(&a_head, &a_tail, &b_head, &b_tail, a.len, b.len, len);
			c.notation = 0;
			c.len = len;
			return c;
		}
		else {
			int len;
			c = abs_minus_abs(&b_head, &b_tail, &a_head, &a_tail, b.len, a.len, len);
			c.notation = 1;
			c.len = len;
			return c;
		}
	}

	if (flag) {
		int len;
		c = abs_minus_abs(&a_head, &a_tail, &b_head, &b_tail, a.len, b.len, len);
		c.notation = 1;
		c.len = len;
		return c;
	}
	else {
		int len;
		c = abs_minus_abs(&b_head, &b_tail, &a_head, &a_tail, b.len, a.len, len);
		c.notation = 0;
		c.len = len;
		return c;
	}
	return c;
}
bigint operator*(const bigint &a, const bigint &b)
{
	bigint c;
	if ((a.notation == 1 && b.notation == 1) || (a.notation == 0 && b.notation == 0))
		c.notation = 1;
	if ((a.notation == 1 && b.notation == 0) || (a.notation == 0 && b.notation == 1))
		c.notation = 0;
	//((min_len - 1) / 5 + 1)
	int max_len, min_len;
	Elem *max_head, *min_head, *max_tail, *min_tail;
	if (a.len >= b.len) {
		max_len = a.len, min_len = b.len;
		max_head = a.head, max_tail = a.tail, min_head = b.head, min_tail = b.tail;
	}
	else {
		max_len = b.len, min_len = a.len;
		max_head = b.head, max_tail = b.tail, min_head = a.head, min_tail = a.tail;
	}

	for (int i = 1; i <= ((max_len - 1) / 5 + 1); i++)
		for (int j = 1; j <= ((min_len - 1) / 5 + 1); j++) {
			int x = get_data(&max_head, &max_tail, i), y = get_data(&min_head, &min_tail, j);
			long long int mid = (long long int)x*y;
			//int carry = int(mid / 100000);
			// mid %= 100000;
			abs_plus_equal(&c.head, &c.tail, mid, a.len, (i - 1) + (j - 1) + 1);
			//abs_plus_equal(&c.head, &c.tail, carry, c.len, (i - 1) + (j - 1) + 2);
		}

	correct_data(&c.tail);
	c.len = count_len(c.head, c.tail);
	return c;
}
bigint operator/(const bigint &a, const bigint &b)
{
	if (b == (const bigint)0) {
		bigint d = -10086;
		cout << "error" << endl;
		return d;
	}

	int max_pos, min_pos;
	Elem *max_head, *min_head, *max_tail, *min_tail;
	bigint c;
	if ((a.notation == 1 && b.notation == 1) || (a.notation == 0 && b.notation == 0))
		c.notation = 1;
	if ((a.notation == 1 && b.notation == 0) || (a.notation == 0 && b.notation == 1))
		c.notation = 0;
	if (abs_bigger_or_equal(a.head, a.tail, b.head, b.tail, a.len, b.len)) {
		max_pos = (a.len - 1) / 5 + 1, min_pos = (b.len - 1) / 5 + 1;
		max_head = a.head, max_tail = a.tail, min_head = b.head, min_tail = b.tail;
	}
	else {
		c = bigint(0);
		c.len = 1;
		return c;
	}

	bigint e = a;
	for (int i = max_pos - min_pos + 1; i >= 1; i--) {
		int num = 0;
		bigint d;
		abs_part_value(&d.head, &d.tail, e.head, e.tail, e.len, 1, i);
		d.len = count_len(d.head, d.tail);
		while (abs_bigger_or_equal(d.head, d.tail, b.head, b.tail, d.len, b.len)) {
			abs_minus_equal(&d.head, &d.tail, b.head, b.tail, d.len, b.len, 1, 1, 2);
			d.len = count_len(d.head, d.tail);
			abs_minus_equal(&e.head, &e.tail, b.head, b.tail, e.len, b.len, i, 1, 2);
			e.len = count_len(e.head, e.tail);
			num++;
		}
		change_data(&c.head, &c.tail, i, num);
		//cout << i << endl;
	}


	correct_data(&c.tail);
	c.len = count_len(c.head, c.tail);
	return c;
}
bigint operator%(const bigint &a, const bigint &b)
{
	if (b == (const bigint)0) {
		bigint d = -10086;
		cout << "error" << endl;
		return d;
	}
	int max_pos, min_pos;
	Elem *max_head, *min_head, *max_tail, *min_tail;
	bigint c;
	if ((a.notation == 1 && b.notation == 1) || (a.notation == 0 && b.notation == 0))
		c.notation = 1;
	if ((a.notation == 1 && b.notation == 0) || (a.notation == 0 && b.notation == 1))
		c.notation = 0;
	if (abs_bigger_or_equal(a.head, a.tail, b.head, b.tail, a.len, b.len)) {
		max_pos = (a.len - 1) / 5 + 1, min_pos = (b.len - 1) / 5 + 1;
		max_head = a.head, max_tail = a.tail, min_head = b.head, min_tail = b.tail;
	}
	else {
		c = bigint(a);
		c.len = 1;
		return c;
	}

	bigint e = a;
	for (int i = max_pos - min_pos + 1; i >= 1; i--) {
		int num = 0;
		bigint d;
		abs_part_value(&d.head, &d.tail, e.head, e.tail, e.len, 1, i);
		d.len = count_len(d.head, d.tail);
		while (abs_bigger_or_equal(d.head, d.tail, b.head, b.tail, d.len, b.len)) {
			abs_minus_equal(&d.head, &d.tail, b.head, b.tail, d.len, b.len, 1, 1, 2);
			d.len = count_len(d.head, d.tail);
			abs_minus_equal(&e.head, &e.tail, b.head, b.tail, e.len, b.len, i, 1, 2);
			e.len = count_len(e.head, e.tail);
			num++;
		}
		//cout << i << endl;
	}

	correct_data_v2(&e.head, &e.tail);
	e.len = count_len(e.head, e.tail);
	c = e;

	//correct_data(&c.tail);
	//c.len = count_len(c.head, c.tail);
	return c;
}
bigint operator+=(bigint &a, const bigint &b)
{
	a = a + b;
	return a;
}
bigint operator-=(bigint &a, const bigint &b)
{
	a = a - b;
	return a;
}
bigint operator*=(bigint &a, const bigint &b)
{
	a = a*b;
	return a;
}
bigint operator/=(bigint &a, const bigint &b)
{
	if (b == (const bigint)0) {
		bigint d = -10086;
		cout << "error" << endl;
		return d;
	}
	a = a / b;
	return a;
}
bigint operator%=(bigint &a, const bigint &b)
{
	if (b == (const bigint)0) {
		bigint d = -10086;
		cout << "error" << endl;
		return d;
	}
	a = a%b;
	return a;
}

bool operator==(const bigint &a, const bigint &b)
{
	if (a.len != b.len)
		return 0;
	Elem *p = a.head->next, *q = b.head->next;

	for (; p != NULL && q != NULL; p = p->next, q = q->next) {
		for (int i = 0; i < 200; i++) {
			if (p->data[i] != q->data[i])
				return 0;
		}
	}

	return 1;
}
bool operator!=(const bigint &a, const bigint &b)
{
	if (a.len != b.len)
		return 1;
	Elem *p = a.head->next, *q = b.head->next;

	for (; p != NULL && q != NULL; p = p->next, q = q->next) {
		for (int i = 0; i < 200; i++) {
			if (p->data[i] != q->data[i])
				return 1;
		}
	}

	return 0;
}
bool operator>=(const bigint &a, const bigint &b)
{
	if (a.notation > b.notation)
		return 1;
	if (a.notation < b.notation)
		return 0;
	if (a.len > b.len) {
		if (a.notation == 1)
			return 1;
		else
			return 0;
	}
	if (a.len < b.len) {
		if (a.notation == 1)
			return 0;
		else
			return 1;
	}

	int len = a.len;
	bigint pa = a, pb = b;
	for (int i = (len - 1) / 5 + 1; i >= 1; i--) {
		int a_num = get_data(&pa.head, &pa.tail, i), b_num = get_data(&pb.head, &pb.tail, i);
		if (a_num > b_num) {
			if (a.notation == 1)
				return 1;
			else
				return 0;
		}
		if (a_num < b_num) {
			if (a.notation == 1)
				return 0;
			else
				return 1;
		}
	}

	return 1;
}
bool operator<=(const bigint &a, const bigint &b)
{
	if (a.notation > b.notation)
		return 0;
	if (a.notation < b.notation)
		return 1;
	if (a.len > b.len) {
		if (a.notation == 1)
			return 0;
		else
			return 1;
	}
	if (a.len < b.len) {
		if (a.notation == 1)
			return 1;
		else
			return 0;
	}

	int len = a.len;
	bigint pa = a, pb = b;
	for (int i = (len - 1) / 5 + 1; i >= 1; i--) {
		int a_num = get_data(&pa.head, &pa.tail, i), b_num = get_data(&pb.head, &pb.tail, i);
		if (a_num > b_num) {
			if (a.notation == 1)
				return 0;
			else
				return 1;
		}
		if (a_num < b_num) {
			if (a.notation == 1)
				return 1;
			else
				return 0;
		}
	}

	return 1;
}
bool operator>(const bigint &a, const bigint &b)
{
	if (a.notation > b.notation)
		return 1;
	if (a.notation < b.notation)
		return 0;
	if (a.len > b.len) {
		if (a.notation == 1)
			return 1;
		else
			return 0;
	}
	if (a.len < b.len) {
		if (a.notation == 1)
			return 0;
		else
			return 1;
	}

	int len = a.len;
	bigint pa = a, pb = b;
	for (int i = (len - 1) / 5 + 1; i >= 1; i--) {
		int a_num = get_data(&pa.head, &pa.tail, i), b_num = get_data(&pb.head, &pb.tail, i);
		if (a_num > b_num) {
			if (a.notation == 1)
				return 1;
			else
				return 0;
		}
		if (a_num < b_num) {
			if (a.notation == 1)
				return 0;
			else
				return 1;
		}
	}

	return 0;
}
bool operator<(const bigint &a, const bigint &b)
{
	if (a.notation > b.notation)
		return 0;
	if (a.notation < b.notation)
		return 1;
	if (a.len > b.len) {
		if (a.notation == 1)
			return 0;
		else
			return 1;
	}
	if (a.len < b.len) {
		if (a.notation == 1)
			return 1;
		else
			return 0;
	}

	int len = a.len;
	bigint pa = a, pb = b;
	for (int i = (len - 1) / 5 + 1; i >= 1; i--) {
		int a_num = get_data(&pa.head, &pa.tail, i), b_num = get_data(&pb.head, &pb.tail, i);
		if (a_num > b_num) {
			if (a.notation == 1)
				return 0;
			else
				return 1;
		}
		if (a_num < b_num) {
			if (a.notation == 1)
				return 1;
			else
				return 0;
		}
	}

	return 0;
}

bigint operator-(bigint &a)
{
	bigint d = a;
	d.notation = d.notation * -1;
	return d;
}
bigint operator+(bigint &a)
{
	return a;
}

bigint& operator++(bigint &a)
{
	a = a + bigint(1);
	return a;
}
bigint& operator--(bigint &a)
{
	a = a - bigint(1);
	return a;
}
bigint operator++(bigint &a, int)
{
	bigint b(a);
	a = a + bigint(1);
	return b;
}
bigint operator--(bigint &a, int)
{
	bigint b(a);
	a = a - bigint(1);
	return b;
}


bigint test(bigint a)
{
	return a;
}

void array_prt(bigint a[])
{
	for (int i = 0; i < 5; i++)
		cout << "test(b[" << i << "])值为：" << a[i] << endl;

}