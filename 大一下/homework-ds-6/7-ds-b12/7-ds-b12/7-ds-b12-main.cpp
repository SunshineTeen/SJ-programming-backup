//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<conio.h>
#include"7-ds-b12-linear_list_L.cpp"

using namespace std;

int main()
{
	const int N = 5; //student��Ϊ5������Ϊ10
	cout << "����ǰ�������ͣ�student��" << endl;
	cout << "��������Ҫ��" << endl;
	cout << "int:����" << endl;
	cout << "double1:ʵ��" << endl;
	cout << "string:�ַ���" << endl;
	cout << "student:ѧ��(int��Χ������) ����(���Ȳ�����9���ַ���) �Ա�(���ַ�) �ɼ�(����5λС��) ��ַ(���Ȳ�����29���ַ���)" << endl;
	LinkList<student> L;
	student e1, e2;
	int i, pos;

	cout << "�ձ�=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "��=" << L.ListLength() << endl << endl;

	cout << "����������" << N << "��Ԫ�ء�ע�ⰴ��Ҫ�����롿��" << endl;
	for (i = N; i > 0; --i) 
		cin >> e1,L.ListInsert(1, e1);

	cout << "��ǰ���������" << endl;
	L.ListTraverse();
	
	cout << "�ձ�=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "��=" << L.ListLength() << endl << endl;

	for (i = 0; i < 5; ++i)
	{
		int pos;
		switch (i)
		{
		case 0:
			pos = 1;
			break;
		case 1:
			pos = L.ListLength();
			break;
		case 2:
			pos = -1;
			break;
		case 3:
			pos = L.ListLength() + 1;
			break;
		case 4:
			cout << "������ҪȡԪ�ص�λ��[1.." << L.ListLength() << "]��";
			cin >> pos;
			break;
		}

		if (L.GetElem(pos, e1) == OK) 
		{
			cout << "��" << pos << "��Ԫ��=" << e1 << endl;

			if (L.PriorElem(e1, e2) == OK)
				cout << "��" << pos << "��Ԫ��(" << e1 << ")��ǰ��=" << e2 << endl;
			else
				cout << "�޷�ȡ�õ�" << pos << "��Ԫ��(" << e1 << ")��ǰ��" << endl;

			if (L.NextElem(e1, e2) == OK)
				cout << "��" << pos << "��Ԫ��(" << e1 << ")�ĺ��=" << e2 << endl;
			else
				cout << "�޷�ȡ�õ�" << pos << "��Ԫ��(" << e1 << ")�ĺ��" << endl;
		}
		else
			cout << "�޷�ȡ�õ�" << pos << "��Ԫ��" << endl;
	} 

	cout << endl << "������Ҫ���ҵ�Ԫ�ص�ֵ" << endl;
	cin >> e1;

	if ((pos = L.LocateElem(e1)) > 0) 
		cout << "Ԫ��" << e1 << "��λ��=" << pos << endl;
	else
		cout << "�Ҳ���Ԫ��" << e1 << endl;

	cout << endl << "������Ҫ����Ԫ�ص�ֵ" << endl;
	cin >> e1;
	cout << endl << "������Ҫ����Ԫ�ص�λ��" << endl;
	cin >> pos;

	if (L.ListInsert(pos, e1) == OK) 
	{
		cout << "�ڵ�" << pos << "��Ԫ��ǰ����Ԫ��=" << e1 << "�ɹ�" << endl;
		cout << "�±�Ϊ��" << endl;
		L.ListTraverse();
	}
	else
		cout << "�ڵ�" << pos << "��Ԫ��ǰ����Ԫ��=" << e1 << "ʧ��" << endl;

	cout << endl << "������Ҫɾ��Ԫ�ص�λ��" << endl;
	cin >> pos;

	if (L.ListDelete(pos, e1) == OK) 
	{
		cout << "ɾ����" << pos << "��Ԫ��=" << e1 << "�ɹ�" << endl;
		cout << "�±�Ϊ��" << endl;
		L.ListTraverse();
	}
	else
		cout << "ɾ����" << pos << "��Ԫ��ʧ��" << endl;

	cout << endl << "��ձ�" << endl;
	L.ClearList();
	cout << "�ձ�=" << (L.ListEmpty() == TRUE ? "TRUE" : "FALSE") << endl;
	cout << "��=" << L.ListLength() << endl << endl;

	cout << "���Խ��������س��˳�...";
	while (_getch() != '\r');
	return 0;
}
