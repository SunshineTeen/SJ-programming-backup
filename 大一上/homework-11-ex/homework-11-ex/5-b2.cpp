/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{
	const int N = 100;
	const int Maxn = N + 10;
	bool f[Maxn] = { 0 };

	For(i, 1, N)
	{
		for (int j = i; j <= N; j += i)
		{
			if (!f[j])
				f[j] = 1;
			else
				f[j] = 0;
		}
	}
	int cnt = 0;
	printf("���ŵĵƵı��Ϊ:\n");
	For(i, 1, N)
		if (f[i])
		{
			++cnt;
			if (cnt == 11)
			{
				printf("\n");
				cnt = 0;
			}
			cout << setw(4) << "#" << i;
		}
	printf("\n");

	return 0;
}