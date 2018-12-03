// 班级:计算机一班 学号:1652228 姓名:王哲源

#include<iostream>

#define Error -1
#define sFor(i,l,r) for(int i=l;i<r;++i)
#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;

typedef long long LL;

const int Each_Block = 1024;
const int Maxn = 9;
const LL Max = 1000000LL * 1000;

class bigint
{
public:
	bigint();
	~bigint();
	bigint(const bigint&);
	bigint(LL);

	void reset();
	bigint& operator =(const bigint&);

	friend istream& operator >>(istream&, bigint&);
	friend ostream& operator <<(ostream&, bigint&);

	friend void Upper(bigint&);
	friend void Realloc(bigint&);
	friend void Freealloc(bigint&);

	bigint operator -()const;

	friend bigint operator +(const bigint&, const bigint&);
	friend bigint operator -(const bigint&, const bigint&);
	bigint& operator +=(const bigint &rhs);
	bigint& operator -=(const bigint &rhs);
	bigint operator ++(int);
	bigint operator --(int);
	bigint& operator ++();
	bigint& operator --();

	friend bigint operator *(const bigint&, const bigint&);
	friend bigint operator /(const bigint&, const bigint&);
	friend bigint operator %(const bigint&, const bigint&);
	bigint &operator *=(const bigint &rhs);
	bigint &operator /=(const bigint &rhs);
	bigint &operator %=(const bigint &rhs);

	friend bool operator >(const bigint&, const bigint&);
	friend bool operator <(const bigint&, const bigint&);
	friend bool operator >=(const bigint&, const bigint&);
	friend bool operator <=(const bigint&, const bigint&);
	friend bool operator ==(const bigint&, const bigint&);
	friend bool operator !=(const bigint&, const bigint&);
private:
	LL *num;
	int len, block;
	bool f;
};
