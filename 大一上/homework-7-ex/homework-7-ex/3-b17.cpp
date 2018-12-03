/* 班级:计算机一班 学号:1652228 姓名:王哲源 */
#include <iostream>
using namespace std;
int main()
{
	int x;

	/*
	cin读入非数字报错原因:
	cin被置failbit。
	在每次读取数据前，cin会检测当前流的状态，
	failbit会导致operator<<直接退出，需读取的变量没变，所以造成死循环
	*/
	while (1) {
		cout << "请输入x的值(0-100)：";
		cin >> x;
		while (cin.fail())//若cin被置failbit则cin.fail()返回值为true
		{
			cin.clear();//清除fail状态
			cin.ignore(1024,'\n');//抛弃从输入流中提取的在\n前的最多1024个数据
			cout << "请输入x的值(0-100)：";
			cin >> x;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "x=" << x << endl;

	return 0;
}
/*
while(!scanf("%d",&x))
{
	puts("error");
	fflush(stdin);//刷新缓冲区 
}
*/

