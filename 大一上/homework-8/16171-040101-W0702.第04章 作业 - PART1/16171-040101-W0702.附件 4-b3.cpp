/* ѧ�� ���� �༶ */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/* ������Ա��������κ��޸�
   ���������⣬�������κκ�����������㡱-������!!!!!! */
void daxie(int num, int flag_of_zero)
{
	switch(num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
		}
}

/* �ɸ�����Ҫ�Զ����������� */


/* ������Ҫ���main���� */
int main()
{
	return 0;
}
