/*����������Դ  �༶�������һ�� ѧ�ţ�1652228*/
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int add(int x,int y);
	int c = add(a, b);
	cout << "a+b=" << c << endl;
	return 0;
}
int add(int x, int y)
{
	int z = x + y;
	return(z);
}
/*
����
1.����cδ��������
2.�ֲ�����a,bδ��ֵ����ʼ����
3.c=add(a,b)��ȱ�ٷֺ�
4.�������е�����δ�������Զ��庯��add()
5.int add(int x,int y)�����һ���ֺ�
6.�Զ��庯��add()�б���zδ��������
7.�Զ��庯��add()��returnƴд����
*/
