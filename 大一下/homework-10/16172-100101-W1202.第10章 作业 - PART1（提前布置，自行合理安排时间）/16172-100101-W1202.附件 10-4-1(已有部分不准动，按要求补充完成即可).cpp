/* ѧ�� ���� �༶ */
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
    private:
        int value[2][3];
    public:
        matrix(int (*p)[3]);  //���캯�����������ʼ������
        void display();       //����þ���
        matrix operator+(matrix &b);
        /* ----������Ҫ���������Ա�����Ķ���---- */

    };

/* ----�������Ա����������ʵ��---- */

/* ----main������׼��---- */
int main()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    int b[2][3] = {{1,2,3},{4,5,6}};
    matrix m1(a), m2(b), m3;

    cout << "��ʼ����m1��ֵ��" << endl;
    m1.display();
    cout << "��ʼ����m2��ֵ��" << endl;
    m2.display();
    m3 = m1 + m2;
    cout << "��Ӻ����m3��ֵ��" << endl;
    m3.display();

    return 0;
}
