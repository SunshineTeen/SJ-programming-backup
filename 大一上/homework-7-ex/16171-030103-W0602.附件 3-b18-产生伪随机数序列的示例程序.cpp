/* 班级 学号 姓名 */
#include <iostream>
#include <stdlib.h>	//srand/rand函数
#include <time.h>	//time函数
using namespace std;
int main()
{
	int i;

	/* time(0)函数用于用于取当前系统时间（当前时间与1970-1-1 00:00:00相差的秒数）
	   srand()函数的功能是生成伪随机数序列的种子，参数是一个unsigned int型数字
	   rand()函数用于生成[0-32767]之间的伪随机数（种子相同则伪随机数相同）
	   注：一次srand()后，可以多次rand()  */

	/* 请多次运行本测试程序，观察下面两个序列的差异!!! */

	/* 错误方法：用一个固定整数做种子，则多次运行产生的伪随机数序列是相同的 */
	srand(12345);
	cout << "固定伪随机数序列：" << endl;
	for (i = 0; i < 10; i++)
		cout << rand() << endl;

	/* 正确方法：用当前系统时间做种子，这样在不同时间运行则种子不同，
	   从而使多次运行的伪随机数序列不同 */
	srand((unsigned int)time(0));
	cout << endl << "伪随机数序列：" << endl;
	for (i = 0; i < 10; i++)
		cout << rand() << endl;		//rand()函数用于生成0-32767间的整数

	return 0;
}
