/* 班级:计算机一班 学号:1652228 姓名:王哲源 */ 

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include<cstdio> 
#include<cmath> 

using namespace std; 

inline void trans(int x, bool f) 
{ 
	int tmp = x / 10, dig = x % 10; 

	if (!tmp) 
	{ 
		if (!f) printf("- "); 
		printf("%c", dig+'0'); 
		return; 
	} 
	trans(tmp, f);

	if (tmp)
		printf(" ");
	printf("%c", dig+'0');
} 

int main() 
{ 
	int n; 

	while (1) 
	{ 
		printf("请输入一个整数n : "); 
		cin >> n; printf("\n"); 
		while (cin.fail()) 
		{ 
			cin.clear(); 
			cin.ignore(1024, '\n'); 
			cout << "求你别乱打字符了。。请按标准输入 : "; 
			cin >> n; printf("\n"); 
		} 
		break; 
	} 

	if (n == 0) printf("0\n"); 
	else 
	{
		bool f = n > 0 ? 1 : 0; 
		n = abs(n); 
		trans(n, f); 
		printf("\n"); 
	} 

	return 0; 
}
