/* ѧ�� ���� �༶ */
#include <iostream>
using namespace std;

class Days {
	private:
		int year;
		int month;
		int day;
		int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
	public:
		int calc_days();     //�����ǵ���ĵڼ���
		/* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
};

/* �˴��������Ա����������ʵ�� */




/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012,3,18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	if (1) {
		Days d1(2011,12,31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
		}
	
	if (1) {
		Days d1(2012,12,31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
		}
		
	if (1) {
		Days d1(2011,2,29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
		}

	return 0;
}
