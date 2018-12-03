//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix operator+(matrix &b);
	/* ----根据需要添加其它成员函数的定义---- */
	matrix()
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 3; ++j)
				value[i][j] = 0;
	}
	friend istream &operator >> (istream &, matrix &);
	friend ostream &operator << (ostream &, const matrix &);
};

/* ----给出类成员函数的体外实现---- */
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

/* ----main函数不准动---- */
int main()
{
	matrix m1, m2, m3;

	cout << "请输入矩阵m1的值(共2行3列，按先行后列的顺序输入)" << endl;
	cin >> m1;
	cout << "请输入矩阵m2的值(共2行3列，按先行后列的顺序输入)" << endl;
	cin >> m2;

	cout << "初始矩阵m1的值：" << endl;
	cout << m1 << endl;
	cout << "初始矩阵m2的值：" << endl;
	cout << m2 << endl;
	cout << "相加后矩阵m3的值：" << endl;
	cout << (m3 = m1 + m2) << endl;
	
	return 0;
}