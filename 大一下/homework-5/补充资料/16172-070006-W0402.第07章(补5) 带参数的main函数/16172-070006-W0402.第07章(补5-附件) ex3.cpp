#include <iostream>
using namespace std;

int main()
{
    char stu_no_1[1024], stu_no_2[1024];
    char filename[1024];
    int  matching_rate;

    cout << "������Ҫ����ѧ��(ȫ��������all)" << endl;
    cin >> stu_no_1;        //���ǵ�������ܳ���7λ��������鶨��Ϊ1024
    //��stu_no_1����ȷ�Լ��

    cout << "������Ҫƥ���ѧ��(ȫ��������all)" << endl;
    cin >> stu_no_2;        //���ǵ�������ܳ���7λ��������鶨��Ϊ1024
    //��stu_no_1����ȷ�Լ��

    cout << "������Ҫ�����ļ���" << endl;
    cin >> filename;        //���ǵ�������ܳ���32λ��������鶨��Ϊ1024

    cout << "������ƥ���(60-100)" << endl;
    cin >> matching_rate;
    //��matching_rate����ȷ�Լ��

    //��������...
    return 0;
}
