//�༶:�����һ�� ����:����Դ ѧ��:1652228
#include <iostream>
using namespace std;
int main()
{
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i + j++;
	n = (++i) + (++j) + m;
	cout << i << '\t' << m << '\t' << n << endl;
	return 0;
}
/*
���:
10		19		41

*/