/* 班级：计算机一班 学号：1652228 姓名：王哲源 */
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, sum = 0;
	for (i = 0; i<5; i++) {
		for (j = 0; j<5; j++) {
			for (k = 0; k<5; k++) {
				cout << "*";
				sum++;
				if (k == 3) 
					break;/************/
			}
			cout << ' ';
			/************/
		}
		cout << endl;
		/************/
	}
	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;
	return 0;
}