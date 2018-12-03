#include <iostream>
#include <Windows.h>
using namespace std;

/* 返回值：0  ：有解
           -1 : 原始数据有0-9之外的非法值
           -2 ：原始值行/列/九宫有冲突
		   -3 ：无解
		   -4 : 其它错误（无内存等）
*/
int solving_sudoku(int sudoku[9][9])
{
	/* 本循环用于测试超时，实际使用时删除即可 */
	for (int i = 0; i < 1000; i++)
		Sleep(1000);

	return 0;
}
