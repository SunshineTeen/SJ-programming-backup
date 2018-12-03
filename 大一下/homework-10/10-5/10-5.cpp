//����������Դ �༶�������1�� ѧ�ţ�1652228
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix operator+(matrix &b);
	/* ----������Ҫ���������Ա�����Ķ���---- */
	matrix()
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 3; ++j)
				value[i][j] = 0;
	}
	friend istream &operator >> (istream &, matrix &);
	friend ostream &operator << (ostream &, const matrix &);
};

/* ----�������Ա����������ʵ��---- */
matrix matrix::operator+(matrix &b)
{
	matrix c;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			c.value[i][j] = value[i][j] + b.value[i][j];
	return c;
}
istream &operator >> (istream &it, matrix &M)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			it >> M.value[i][j];
	return it;
}
ostream &operator << (ostream &it, const matrix &M)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
			it << setiosflags(ios::left) << setw(3) << M.value[i][j];
		printf("\n");
	}
		
	return it;
}

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
	cout << (m3 = m1 + m2) << endl;
	
	return 0;
}