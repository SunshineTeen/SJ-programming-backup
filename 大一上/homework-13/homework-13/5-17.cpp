/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

void init(int score[], int i)
{
	cin >> score[i];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "������Ҵ��ַ��ˡ����밴��׼����ɼ� : ";
		cin >> score[i];
	}
}

int main()
{
	const int n = 10;
	const int Maxl = 100;
	char Name[n + 5][Maxl], Id[n + 5][Maxl];
	int score[n + 5];
	int cnt = 0;

	printf("����������10��ѧ����������ѧ�źͳɼ�\n");
	For(i, 1, n)
	{
		cin >> Name[i] >> Id[i];
		init(score, i);
		if (score[i] < 60) ++cnt;
	}

	if (!cnt)
		printf("û�в��������\n");
	else
	{
		printf("���������Ϊ\n");
		For(i, 1, n)
			if (score[i] < 60)
				printf("������%s      ѧ�ţ�%s\n", Name[i], Id[i]);
	}

	//system("pause");/////////////////////////
	return 0;
}
