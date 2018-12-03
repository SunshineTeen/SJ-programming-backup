/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
	public:
		int calc_days();     //计算是当年的第几天
		/* 下面可以补充其它需要的类成员函数的定义，数量不限 */
};

/* 此处给出类成员函数的体外实现 */




/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
		}

	return 0;
}
