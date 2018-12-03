/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

void Sort(char Name[][15], char Id[][15], int low, int high)
{
	if (low >= high)
		return;

	const int Maxl = 15;
	char tmp[Maxl], _tmp[Maxl];
	int l = low, r = high;

	strcpy(tmp, Name[l]);
	strcpy(_tmp, Id[l]);
	while (l < r)
	{
		while (l < r && strcmp(tmp, Name[r]) < 0)
			--r;
		if (l < r)
		{
			strcpy(Name[l], Name[r]);
			strcpy(Id[l], Id[r]);
		}
		while (l < r && strcmp(tmp, Name[l])>0)
			++l;
		if (l < r)
		{
			strcpy(Name[r], Name[l]);
			strcpy(Id[r], Id[l]);
		}
	}
	strcpy(Name[l], tmp);
	strcpy(Id[l], _tmp);
	Sort(Name, Id, low, l - 1);
	Sort(Name, Id, r + 1, high);
}

int init()
{
	int res;
	while (1)
	{
		cin >> res;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˣ�����������  :";
			cin >> res;
		}
		if (res <= 0)
		{
			printf("����Ӧ��Ϊ������������������\n");
			continue;
		}
		return res;
	}
}

int main()
{
	const int Maxn = 200;
	const int Maxl = 15;

	int n;
	char Name[Maxn][Maxl], Id[Maxn][Maxl];
	char aim[Maxl];

	printf("������ѧ������ :");
	n = init();

	For(i, 1, n)
	{
		printf("�������%d��ѧ����������ѧ�� : ",i);
		scanf(" %s %s", Name[i] + 1, Id[i] + 1);
	}
	Sort(Name, Id, 1, n);

	printf("������Ҫ���ҵ�ѧ������ : ");
	scanf(" %s", aim + 1);
	int p = 1;
	while (p <= n)
	{
		int cmp = strcmp(aim, Name[p]);
		if (cmp < 0)
		{
			p = n + 1;
			break;
		}
		if (!cmp)
			break;
		++p;
	}
	if (p == n + 1)
		printf("δ���ҵ���ͬѧ\n");
	else
		printf("���ҵ���ͬѧ����ѧ��Ϊ%s\n", Id[p]+1);

	return 0;
}
