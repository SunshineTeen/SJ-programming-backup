//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include <windows.h> //ȡϵͳʱ��

#define For(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int main()
{	
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&fc_begin);	//��ó�ʼӲ����ʱ������

										/* �˴�����ĳ���ʼ */
	const int STD = 1953;
	int cnt = 0;
	For(i, 100, 997)
	{
		int a = i / 100, b = i % 100 / 10, c=i % 10;
		if (!a || !b || !c || a == b || a == c || b == c)
			continue;
		For(j, i + 1, 998)
		{
			int d = j / 100, e = j % 100 / 10, f = j % 10;
			if (!d || !e || !f || d == e || d == f || e == f
				|| d == a || d == b || d == c
				|| e == a || e == b || e == c
				|| f == a || f == b || f == c)
				continue;
			For(k, j + 1, 998)
			{
				int x = k / 100, y = k % 100 / 10, z = k % 10;
				if (!x || !y || !z || x == y || x == z || y == z
					|| x == a || x == b || x == c || x == d || x == e || x == f
					|| y == a || y == b || y == c || y == d || y == e || y == f
					|| z == a || z == b || z == c || z == d || z == e || z == f)
					continue;
				if (i + k + j == STD)
				{
					++cnt;
					printf("No.");
					cout << setw(3) << cnt;
					printf(" : %d+%d+%d=1953\n", i, j, k);
				}
			}
		}
	}

	printf("total=%d\n", cnt);
										/* �˴�����ĳ������ */

	QueryPerformanceCounter(&fc_end);//�����ֹӲ����ʱ������
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "ʱ��Ƶ�ʣ�" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "ʱ�Ӽ�����" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "��" << endl;

	return 0;
}
