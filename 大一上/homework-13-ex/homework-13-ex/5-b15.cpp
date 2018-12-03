/* ѧ��:1652228 ����:����Դ �༶:�����һ�� */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

bool check(int N, char code[])
{
	int cnt[4] = { 0 };
	// 0 digit
	// 1 Big alpha
	// 2 Small alpha
	// 3 other

	For(i, 1, N)
	{
		char ch = code[i];
		if (ch >= '0' && ch <= '9')
		{
			++cnt[0];
			continue;
		}
		if (ch >= 'A' && ch <= 'Z')
		{
			++cnt[1];
			continue;
		}
		if (ch >= 'a' && ch <= 'z')
		{
			++cnt[2];
			continue;
		}
		++cnt[3];
	}
	if (cnt[0] >= 2 && cnt[1] >= 2 && cnt[2] >= 2 && cnt[3] >= 2)
		return 1;
	return 0;
}

int init()
{
	int res;
	while (1)
	{
		printf("���������볤��(12-16) :");
		cin >> res;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ����밴��׼���� : ";
			cin >> res;
			printf("\n");
		}

		if (res < 12 || res >16)
		{
			printf("��������볤��Ӧ����12-16֮�䣬����������\n");
			continue;
		}
		return res;
	}
}

int main()
{
	const int Maxn = 25;
	char code[Maxn] = { 0 };
	int n = init(), T = 10;

	srand((unsigned)time(0));
	while (T)
	{
		For(i, 1, n)
			code[i] = rand() % 94 + 33;
		if (!check(n, code))
			continue;
		printf("%s\n", code + 1);
		--T;
	}

	return 0;
}