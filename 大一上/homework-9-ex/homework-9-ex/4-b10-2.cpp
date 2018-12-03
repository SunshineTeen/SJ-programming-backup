/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */
#include <iostream>
using namespace std;

/* �˴�����fun������ʵ�� */
template <class T>
#define For(i,l,r) for(T i=l;i<=r;++i)
inline T fun(T n)
{
	T ans = 0;
	For(i, 1, n)
		ans += i;
	return ans;
}

/* main������׼�޸� */
int main()
{
	short          s1 = 255, s2 = s1 + 1;
	unsigned short us1 = 255, us2 = us1 + 1;
	int            i1 = 65535, i2 = i1 + 1;
	unsigned int   ui1 = 65535, ui2 = ui1 + 1;

	cout << fun(s1) << endl; //������� 32640
	cout << fun(s2) << endl; //������� -32640
	cout << fun(us1) << endl; //������� 32640
	cout << fun(us2) << endl; //������� 32896
	cout << fun(i1) << endl; //������� 2147450880
	cout << fun(i2) << endl; //������� -2147450880
	cout << fun(ui1) << endl; //������� 2147450880
	cout << fun(ui2) << endl; //������� 2147516416
	
	return 0;
}
