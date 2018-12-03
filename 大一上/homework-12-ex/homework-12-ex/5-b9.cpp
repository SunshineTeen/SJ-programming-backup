/* 班级:计算机一班 学号:1652228 姓名:王哲源 */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<fstream>

#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

inline void clear(bool f[])
{
	For(i, 0,9)
		f[i] = 0;
}

int main()
{
	ifstream file;
	file.open("shudu.txt", ios::in);
	if (!file.is_open())
	{
		printf("打开文件失败\n");
		return -1;
	}

	const int N = 9;
	const int Maxn = N + 5;
	int map[Maxn][Maxn];
	For(i, 1, N)
		For(j, 1, N)
			file >> map[i][j];

	bool f[Maxn];
	For(i, 1, N)
	{
		clear(f);
		For(j, 1, N)
		{
			if (f[map[i][j]])
			{
				printf("不满足数独的解\n");
				//system("pause");/////////////////////////
				file.close();
				return 0;
			}
			f[map[i][j]] = 1;
		}
	}

	For(j, 1, N)
	{
		clear(f);
		For(i, 1, N)
		{
			if (f[map[i][j]])
			{
				printf("不满足数独的解\n");
				//system("pause");/////////////////////////
				file.close();
				return 0;
			}
			f[map[i][j]] = 1;
		}
	}

	For(x, 0, 2)
		For(y, 0, 2)
		{
			clear(f);
			For(i,3*x+1,3*x+3)
				For(j, 3 * y + 1, 3 * y + 3)
				{
					if (f[map[i][j]])
					{
						printf("不满足数独的解\n");
						//system("pause");/////////////////////////
						file.close();
						return 0;
					}
					f[map[i][j]] = 1;
				}
		}

	printf("满足数组的解\n");
	//system("pause");/////////////////////////
	file.close();
	return 0;
}
