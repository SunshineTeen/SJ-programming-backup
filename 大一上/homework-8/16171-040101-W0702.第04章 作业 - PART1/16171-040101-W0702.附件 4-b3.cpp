/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/* 不允许对本函数做任何修改
   除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch(num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
		}
}

/* 可根据需要自定义其它函数 */


/* 根据需要完成main函数 */
int main()
{
	return 0;
}
