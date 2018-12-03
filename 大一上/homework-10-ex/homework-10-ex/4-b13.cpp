/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const double eps = 1e-6;

double a, b, c,delta;

void work_3()
{
	double common = -b / (2 * a);
	double tmp = sqrt(fabs(delta)) / (2 * a);

	printf("������������������\n");
	if (fabs(common) < eps)
	{
		cout << "x1 = " << tmp << 'i' << endl;
		cout << "x2 = " << "-" << tmp << 'i' << endl;
	}
	else
	{
		cout << "x1 = " << common << "+" << tmp << 'i' << " , ";
		cout << "x2 = " << common << "-" << tmp << 'i' << endl;
	}
}

void work_2()
{
	double x1 = (-b + sqrt(delta)) / (2 * a);
	double x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < eps)
		x1 = 0;
	if (fabs(x2) < eps)
		x2 = 0;

	printf("���������������ʵ��\n");
	cout << "x1 = " << x1 << " , " << "x2 = " << x2 << endl;
}

void work_1()
{
	double tmp = -b / (2 * a);
	if (fabs(tmp) < eps)
		tmp = 0;

	printf("�������������ʵ��\n");
	cout << "x1 = x2 = " << tmp << endl;
}

void work_0()
{
	printf("�÷��̵ĸ�Ϊ : x=");
	cout << (-c / b) << endl;
}

int main()
{
	printf("��˳������һԪ���η��̵�����ϵ�� : ");
	while (1)
	{
		cin >> a >> b >> c;
		printf("\n");
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ҵ��ַ��ˡ���������ʵ�� : ";
			cin >> a >> b >> c;
			printf("\n");
		}
		if (fabs(a) < eps && fabs(b) < eps)
		{
			printf("��������޷����ɷ��̣����������� : ");
			continue;
		}
		break;
	}

	if (fabs(a) < eps)
	{
		work_0();
		return 0;
	}

	delta = b * b - 4 * a * c;
	if (fabs(delta) < eps)
		work_1();
	else if (delta > 0)
		work_2();
	else
		work_3();

	return 0;
}