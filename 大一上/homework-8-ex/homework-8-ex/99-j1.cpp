/* ѧ��:1652228 ����:����Դ �༶:�����һ�� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

						/* ������ƶ���ָ��λ�� */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* ��ָ��λ�ô���ӡһ��ָ�����ַ� */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int    i;

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand(unsigned int(time(0)));

	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	ע�⣺������bug���������ѭ�����ɵ�XY����ǡ����ȫ��ͬ������ĸ�����᲻��20������˵��������Ҫ�����bug�� */
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	/* �ڴ˴������Ҫ�Ĵ���-begin */
	//_getch();
	gotoxy(hout, 35, 9);
	int x = 35, y = 9;
	while (1)
	{
		char op = _getch();
		if (op == 'q' || op == 'Q')
			break;
		if (op == -32)//�������Ҿ�Ϊ���ܼ�����������ֵ���ҵ�һ����Ϊ-32����ֹascii��HPKM��ͻ
		{
			op = _getch();
			if (op == 72)//Up
			{
				if (y == 1)
					continue;
				gotoxy(hout, x, --y);
			}
			if (op == 75)//Left
			{
				if (x == 1)
					continue;
				gotoxy(hout, --x, y);
			}
			if (op == 80)//Down
			{
				if (y == MAX_Y)
					continue;
				gotoxy(hout, x, ++y);
			}
			if (op == 77)//Right
			{
				if (x == MAX_X)
					continue;
				gotoxy(hout, ++x, y);
			}
		}
		if (op == 32)
			cout << " \b";
	}

	/* �ڴ˴������Ҫ�Ĵ���-end */

	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س����˳�." << endl;
	getchar();
	return 0;
}