/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

int cnt;

inline void output(int num, char from, char to)
{
	++cnt;
	cout << setw(5) << cnt << ":";
	cout << setw(2) << num;
	printf("# %c---->%c\n",from, to);
}
inline void move(int num, char from, char to, char tmp)
{
	if (!num)
		return;
	move(num - 1, from, tmp, to);
	output(num, from, to);
	move(num - 1, tmp, to, from);
}

int main()
{
	int n;

	while (1)
	{
		printf("���������ӵĸ���n (1-16) : ");
		cin >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> n;
			printf("\n");
		}

		if (n <= 0 || n >= 17)
		{
			printf("���ӵĸ���Ӧ������1-16֮�䣬����������\n");
			continue;
		}
		break;
	}

	move(n, 'A', 'C', 'B');

	return 0;
}