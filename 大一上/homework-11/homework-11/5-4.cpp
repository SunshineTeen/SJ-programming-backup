/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

int main()
{
	int a[15] = { 0, 2,5,7,14,56,75,115,346,3563,9834 };
	int n;
	while (1)
	{
		printf("������һ��������");
		cin >> n;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ�������һ������ : ";
			cin >> n;
			printf("\n");
		}
		break;
	}

	int p = 0;
	For(i, 1, 10)
		if (a[i] > n)
		{
			p = i;
			break;
		}
	if (!p)
		a[11] = n;
	else
	{
		opFor(i, 10, p)
			a[i + 1] = a[i];
		a[p] = n;
	}
	For(i, 1, 10)
		printf("%d ", a[i]);
	printf("%d\n", a[11]);

	return 0;
}