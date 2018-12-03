//姓名：王哲源 班级：计算机1班 学号：1652228

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const float pi = float(acos(-1.0));

class Shape
{
public:
	virtual float area() const = 0;
};

class Circle :public Shape
{
public:
	Circle(const float _r = 0) :r(_r)
	{
		if (r < 0)
			r = 0;
	}
	float area() const
	{
		return pi*r*r;
	}
private:
	float r;
};
class Square :public Shape
{
public:
	Square(const float _a = 0) :a(_a)
	{
		if (a < 0)
			a = 0;
	}
	float area() const
	{
		return a*a;
	}
private:
	float a;
};
class Rectangle :public Shape
{
public:
	Rectangle(const float _a = 0, const float _b = 0) :a(_a), b(_b)
	{
		if (a < 0)
			a = 0;
		if (b < 0)
			b = 0;
	}
	float area() const
	{
		return a*b;
	}
private:
	float a, b;
};
class Trapezoid :public Shape
{
public:
	Trapezoid(const float _a = 0, const float _b = 0, const float _h = 0) :a(_a), b(_b), h(_h)
	{
		if (a < 0)
			a = 0;
		if (b < 0)
			b = 0;
		if (h < 0)
			h = 0;
	}
	float area()const
	{
		return 0.5f*(a + b)*h;
	}
private:
	float a, b, h;
};
class Triangle :public Shape
{
public:
	Triangle(const float _a = 0, const float _b = 0, const float _c = 0) :a(_a), b(_b), c(_c)
	{
		if (a < 0)
			a = 0;
		if (b < 0)
			a = 0;
		if (c < 0)
			a = 0;
		if (a + b <= c || b + c <= a || c + a <= b)
			a = b = c = 0;
	}
	float area()const
	{
		float p = 0.5f*(a + b + c);
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
private:
	float a, b, c;
};

int main()
{
	Circle c(5.0f);
	Square s(5.0f);
	Rectangle r(3.0f, 4.0f);
	Trapezoid t1(1.0f, 2.0f, 3.0f);
	Triangle t2(3.0f, 4.0f, 5.0f);
	Shape *sh[5] = { &c,&s,&r,&t1,&t2 };

	int i;
	for (i = 0; i < 5; ++i)
		cout << sh[i]->area() << endl;

	return 0;
}
