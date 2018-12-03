#include <iostream>
using namespace std;

int main()
{
    char stu_no_1[1024], stu_no_2[1024];
    char filename[1024];
    int  matching_rate;

    cout << "请输入要检查的学号(全部则输入all)" << endl;
    cin >> stu_no_1;        //考虑到输入可能超过7位，因此数组定义为1024
    //加stu_no_1的正确性检查

    cout << "请输入要匹配的学号(全部则输入all)" << endl;
    cin >> stu_no_2;        //考虑到输入可能超过7位，因此数组定义为1024
    //加stu_no_1的正确性检查

    cout << "请输入要检查的文件名" << endl;
    cin >> filename;        //考虑到输入可能超过32位，因此数组定义为1024

    cout << "请输入匹配度(60-100)" << endl;
    cin >> matching_rate;
    //加matching_rate的正确性检查

    //后续部分...
    return 0;
}
