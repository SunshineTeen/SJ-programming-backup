/* 学号 姓名 班级 */
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
    private:
        int value[2][3];
    public:
        matrix operator+(matrix &b);
        /* ----根据需要添加其它成员函数的定义---- */

    };

/* ----给出类成员函数的体外实现---- */

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
    cout << (m3=m1+m2) << endl;

    return 0;
}
