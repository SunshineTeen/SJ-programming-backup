#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>	//strlen/strcpy
#include <cstdlib>	//atoi
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void usage(char *procname)
{
    cout << "Usage: " << procname << " Ҫ����ѧ��/ALL ƥ��ѧ��/ALL Դ������/ALL ���ƶȷ�ֵ(60-100)" << endl;
    cout << "               1659999          1659998      all          80" << endl;
    cout << "               1659999          all          3-b5.cpp     60" << endl;
    cout << "               all              all          3-b5.cpp     80" << endl;
    cout << "               all              all          all          80" << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char **argv)
{
    char stu_no_1[8], stu_no_2[8];
    char filename[32];
    int  matching_rate;
    int  i;

    /* �������������������ʾ */
    if (argc!=5) {
    	usage(argv[0]);
    	return 0;
	}

    /* ���ĵ�1��������Ҫ����ѧ�� */
    if (strcmp(argv[1], "all")==0)
    	strcpy(stu_no_1, argv[1]);
    else if (strlen(argv[1])==7) {
	for (i=0; i<7; i++)
	    if (argv[1][i]<'0' || argv[1][i]>'9')  //���� '0'-'9'֮����ַ�
	    	break;
	if (i<7) {
	    cout << "Ҫ����ѧ�Ų���7λ����" << endl;
	    return -1;
	    }
	strcpy(stu_no_1, argv[1]);
	}
    else {
    	cout << "Ҫ����ѧ�Ų���7λ" << endl;
	return -1;
	}

    /* ���ĵ�2��������Ҫƥ���ѧ�� */
    if (strcmp(argv[2], "all")==0)
    	strcpy(stu_no_2, argv[2]);
    else if (strlen(argv[2])==7) {
	for (i=0; i<7; i++)
	    if (argv[2][i]<'0' || argv[2][i]>'9')  //���� '0'-'9'֮����ַ�
	    	break;
	if (i<7) {
	    cout << "Ҫƥ���ѧ�Ų���7λ����" << endl;
	    return -1;
	    }
	strcpy(stu_no_2, argv[2]);
	}
    else {
    	cout << "Ҫƥ���ѧ�Ų���7λ" << endl;
	return -1;
	}

    /* ���ĵ�3���������ļ��� */
    if (strcmp(argv[3], "all")==0)
    	strcpy(filename, argv[3]);
    else if (strlen(argv[3])<32)
    	strcpy(filename, argv[3]);
    else {
    	cout << "�ļ���̫��" << endl;
	return -1;
	}

    /* ���ĵ�4�����������ƶ� */
    matching_rate = atoi(argv[4]);
    if (matching_rate<60 || matching_rate>100) {
    	cout << "ƥ��ȳ�������Χ" << endl;
	return -1;
	}

    cout << "�������ͨ��" << endl;
    cout << "���ѧ�ţ�" << stu_no_1 << endl;
    cout << "ƥ��ѧ�ţ�" << stu_no_2 << endl;
    cout << "�� �� ����" << filename << endl;
    cout << "ƥ �� �ȣ�" << matching_rate << endl;
    
    /* �����ʵ�ֹ���... */
    cout << "ִ����..." << endl;

    cout << "ִ�����" << endl;
    return 0;
}
