/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */
#include <iostream>
using namespace std;
int main()
{
	int x;

	/*
	cin��������ֱ���ԭ��:
	cin����failbit��
	��ÿ�ζ�ȡ����ǰ��cin���⵱ǰ����״̬��
	failbit�ᵼ��operator<<ֱ���˳������ȡ�ı���û�䣬���������ѭ��
	*/
	while (1) {
		cout << "������x��ֵ(0-100)��";
		cin >> x;
		while (cin.fail())//��cin����failbit��cin.fail()����ֵΪtrue
		{
			cin.clear();//���fail״̬
			cin.ignore(1024,'\n');//����������������ȡ����\nǰ�����1024������
			cout << "������x��ֵ(0-100)��";
			cin >> x;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "x=" << x << endl;

	return 0;
}
/*
while(!scanf("%d",&x))
{
	puts("error");
	fflush(stdin);//ˢ�»����� 
}
*/

