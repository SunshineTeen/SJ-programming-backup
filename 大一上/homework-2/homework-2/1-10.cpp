/*姓名：王哲源  班级：计算机一班 学号：1652228*/
#include <iostream>
using namespace std;
int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
}
void sort(int x, int y, int z)
{
	int temp;
	if (x>y) { temp = x; x = y; y = temp; }  //{}内的3个语句的作用是将x和y的值互换
	if (z<x) cout << z << ',' << x << ',' << y << endl;
	else if (z<y)  cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}
//功能： 将以空格隔开输入的三个数从小到大于同一行输出，每两个数之间用逗号隔开 
