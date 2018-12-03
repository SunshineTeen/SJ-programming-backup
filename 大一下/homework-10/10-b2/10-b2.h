//����������Դ �༶�������1�� ѧ�ţ�1652228
#include <iostream>
using namespace std;

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
	private:
		int year;
		int month;
		int day;
	public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
		Date();
		Date(const int, const int, const int);

		void set(const int, const int = 1, const int = 1);
		void get(int &, int &, int &);
		void show()const;

		Date(int);
		operator int()const;

		friend Date operator +(const Date,const int);
		friend Date operator +(const int, const Date);
		friend Date operator -(const Date, const int);
		friend int operator -(const Date, const Date);

		friend Date& operator ++(Date &);
		friend Date operator ++(Date &, int);
		friend Date& operator --(Date &);
		friend Date operator --(Date &, int);

		friend istream& operator >>(istream&, Date&);
		friend ostream& operator <<(ostream&, Date&);

		bool operator ==(const Date&)const;
		bool operator !=(const Date&)const;
		friend bool operator <(const Date, const Date);
		friend bool operator <=(const Date, const Date);
		friend bool operator >(const Date, const Date);
		friend bool operator >=(const Date, const Date);
};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
bool Leapyear(const int);
void days2date(int, int &, int &, int &);
void date2days(int &, const int, const int, const int);

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
const int Maxy = 2099;
const int Miny = 1900;
const int Maxm = 12;
const int Minm = 1;
const int Year = 365;
const int limitd = 73049;
const int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
