#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>	//strlen/strcpy
#include <cstdlib>	//atoi
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void usage(char *procname)
{
    cout << "Usage: " << procname << " 要检查的学号/ALL 匹配学号/ALL 源程序名/ALL 相似度阀值(60-100)" << endl;
    cout << "               1659999          1659998      all          80" << endl;
    cout << "               1659999          all          3-b5.cpp     60" << endl;
    cout << "               all              all          3-b5.cpp     80" << endl;
    cout << "               all              all          all          80" << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char **argv)
{
    char stu_no_1[8], stu_no_2[8];
    char filename[32];
    int  matching_rate;
    int  i;

    /* 参数数量不对则给出提示 */
    if (argc!=5) {
    	usage(argv[0]);
    	return 0;
	}

    /* 带的第1个参数：要检查的学号 */
    if (strcmp(argv[1], "all")==0)
    	strcpy(stu_no_1, argv[1]);
    else if (strlen(argv[1])==7) {
	for (i=0; i<7; i++)
	    if (argv[1][i]<'0' || argv[1][i]>'9')  //不是 '0'-'9'之间的字符
	    	break;
	if (i<7) {
	    cout << "要检查的学号不是7位数字" << endl;
	    return -1;
	    }
	strcpy(stu_no_1, argv[1]);
	}
    else {
    	cout << "要检查的学号不是7位" << endl;
	return -1;
	}

    /* 带的第2个参数：要匹配的学号 */
    if (strcmp(argv[2], "all")==0)
    	strcpy(stu_no_2, argv[2]);
    else if (strlen(argv[2])==7) {
	for (i=0; i<7; i++)
	    if (argv[2][i]<'0' || argv[2][i]>'9')  //不是 '0'-'9'之间的字符
	    	break;
	if (i<7) {
	    cout << "要匹配的学号不是7位数字" << endl;
	    return -1;
	    }
	strcpy(stu_no_2, argv[2]);
	}
    else {
    	cout << "要匹配的学号不是7位" << endl;
	return -1;
	}

    /* 带的第3个参数：文件名 */
    if (strcmp(argv[3], "all")==0)
    	strcpy(filename, argv[3]);
    else if (strlen(argv[3])<32)
    	strcpy(filename, argv[3]);
    else {
    	cout << "文件名太长" << endl;
	return -1;
	}

    /* 带的第4个参数：相似度 */
    matching_rate = atoi(argv[4]);
    if (matching_rate<60 || matching_rate>100) {
    	cout << "匹配度超出合理范围" << endl;
	return -1;
	}

    cout << "参数检查通过" << endl;
    cout << "检查学号：" << stu_no_1 << endl;
    cout << "匹配学号：" << stu_no_2 << endl;
    cout << "文 件 名：" << filename << endl;
    cout << "匹 配 度：" << matching_rate << endl;
    
    /* 具体的实现过程... */
    cout << "执行中..." << endl;

    cout << "执行完成" << endl;
    return 0;
}
