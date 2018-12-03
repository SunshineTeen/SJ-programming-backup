//����������Դ �༶�������1�� ѧ�ţ�1652228
#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
public:
	int calc_days();     //�����ǵ���ĵڼ���
						 /* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
	Days(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};

/* �˴��������Ա����������ʵ�� */
const int NDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int Days::is_leap_year()
{
	return (!(year % 4) && (year % 100)) || !(year % 400);
}
int Days::calc_days()
{
	int leapyear = is_leap_year();
	if (month < 1 || month >12)
		return -1;
	if (day < 1 || day >(NDays[month] + (month == 2 && leapyear)))
		return -1;
	int days = 0;
	for (int i = 1; i < month; ++i)
		days += NDays[i] + (i == 2 && leapyear);
	days += day;

	return days;
}


/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}
	
	return 0;
}