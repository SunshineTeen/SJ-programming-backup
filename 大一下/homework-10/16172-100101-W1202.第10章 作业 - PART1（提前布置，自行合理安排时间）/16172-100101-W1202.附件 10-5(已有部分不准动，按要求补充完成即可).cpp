/* ѧ�� ���� �༶ */
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
    private:
        int value[2][3];
    public:
        matrix operator+(matrix &b);
        /* ----������Ҫ���������Ա�����Ķ���---- */

    };

/* ----�������Ա����������ʵ��---- */

/* ----main������׼��---- */
int main()
{
    matrix m1, m2, m3;

    cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m1;
    cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m2;
	
    cout << "��ʼ����m1��ֵ��" << endl;
    cout << m1 << endl;
    cout << "��ʼ����m2��ֵ��" << endl;
    cout << m2 << endl;
    cout << "��Ӻ����m3��ֵ��" << endl;
    cout << (m3=m1+m2) << endl;

    return 0;
}
