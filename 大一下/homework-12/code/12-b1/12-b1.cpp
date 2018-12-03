//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N = 1000000;

class integral
{
public:
	virtual double value()const = 0;
};

class integral_sin :public integral
{
public:
	integral_sin(const double _l = 0, const double _r = 0) :l(_l), r(_r)
	{
		if (l > r)
			swap(l, r);
	}
	friend istream& operator >> (istream&, integral_sin&);
	double value()const;
private:
	double l, r;
};
class integral_cos :public integral
{
public:
	integral_cos(const double _l = 0, const double _r = 0) :l(_l), r(_r)
	{
		if (l > r)
			swap(l, r);
	}
	friend istream& operator >> (istream&, integral_cos&);
	double value()const;
private:
	double l, r;
};
class integral_exp :public integral
{
public:
	integral_exp(const double _l = 0, const double _r = 0) :l(_l), r(_r)
	{
		if (l > r)
			swap(l, r);
	}
	friend istream& operator >> (istream&, integral_exp&);
	double value()const;
private:
	double l, r;
};

istream& operator >> (istream &it, integral_sin &rhs)
{
	it >> rhs.l >> rhs.r;
	if (rhs.l > rhs.r)
		swap(rhs.l, rhs.r);
	return it;
}
istream& operator >> (istream &it, integral_cos &rhs)
{
	it >> rhs.l >> rhs.r;
	if (rhs.l > rhs.r)
		swap(rhs.l, rhs.r);
	return it;
}
istream& operator >> (istream &it, integral_exp &rhs)
{
	it >> rhs.l >> rhs.r;
	if (rhs.l > rhs.r)
		swap(rhs.l, rhs.r);
	return it;
}
double integral_sin::value()const
{
	double delta = (r - l) / N;
	double cur = l;
	double res = 0;
	For(i, 1, N)
		res += delta*sin(cur), cur += delta;
	return res;
}
double integral_cos::value()const
{
	double delta = (r - l) / N;
	double cur = l;
	double res = 0;
	For(i, 1, N)
		res += delta*cos(cur), cur += delta;
	return res;
}
double integral_exp::value()const
{
	double delta = (r - l) / N;
	double cur = l;
	double res = 0;
	For(i, 1, N)
		res += delta*exp(cur), cur += delta;
	return res;
}


int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral     *p;

	cin >> s1;
	p = &s1;
	cout << p->value() << endl;
	cin >> s2;
	p = &s2;
	cout << p->value() << endl;
	cin >> s3;
	p = &s3;
	cout << p->value() << endl;

	return 0;
}
