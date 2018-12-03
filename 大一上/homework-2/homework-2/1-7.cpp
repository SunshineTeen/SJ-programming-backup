/*姓名：王哲源  班级：计算机一班 学号：1652228*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	return 0;
}
int f(int x, int y, int z)
{
	int m;
	if (x<y) m = x;
	else m = y;
	if (z<m) m = z;
	return m;
}
//功能：从输入的三个数中得出其中最小的数并且以单行形式输出 
