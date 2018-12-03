/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

inline double P(double x, int n)
{
	if (!n)
		return 1;
	if (n == 1) 
		return x;
	return ((2 * n - 1)*x*P(x, n - 1) - (n - 1)*P(x, n - 2)) / n;
}

int main()
{
	int n;
	double x;

	while (1)
	{
		printf("��ֱ����븡����x�ͽ���n������nΪ�Ǹ����� : ");
		cin >> x >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> x >> n;
			printf("\n");
		}

		if (n < 0)
		{
			printf("�������n����Ϊ����������������\n");
			continue;
		}
		break;
	}
	cout <<"P("<<x<<","<<n<<") = " << P(x, n) << endl;

	return 0;
}
