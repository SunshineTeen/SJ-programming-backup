/* ѧ�� ���� �༶ */
#include <iostream>
using namespace std;

class student {
    private:
        int num;
        float score;
    public:
        void display();   //���ѧ�źͳɼ�
        /* ������Ҫ��������Ա�����Ķ��壬�������� */

};

/* �ڴ˸������Ա������ʵ�֣����ⷽʽ�� */

int main()
{
    student *p, s[5] = { student(1001, 78.5),
                         student(1002, 63.5),
                         student(1003, 87.5),
                         student(1004, 52.5),
                         student(1005, 34.5)};
    /* ������� 1001��1003��1005�����˵���Ϣ
      ��ע�⣺���������ٶ����κ����͵ı��� */


    return 0;
}
