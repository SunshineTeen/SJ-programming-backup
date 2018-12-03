/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#include <iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	double a, b, c;

	printf("��˳������һԪ���η��̵�����ϵ�� : ");
	const double eps = 1e-6;
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

	void work_0(double b, double c);
	void work_1(double a, double b);
	void work_2(double a, double b, double delta);
	void work_3(double a, double b, double delta);

	if (fabs(a) < eps)
	{
		work_0(b, c);
		return 0;
	}

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < eps)
		work_1(a, b);
	else if (delta > 0)
		work_2(a, b, delta);
	else
		work_3(a, b, delta);

	return 0;
}