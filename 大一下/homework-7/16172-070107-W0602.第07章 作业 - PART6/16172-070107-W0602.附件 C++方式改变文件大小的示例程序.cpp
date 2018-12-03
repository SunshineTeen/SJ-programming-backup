#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <experimental/filesystem>
using namespace std;

int main()
{
	const char *fname = "test.txt";
	fstream file(fname, ios::in | ios::out | ios::binary);
	int file_length;
	char buf[80];

	if (!file.is_open()) {
		cout << "open failed!" << endl;
		return -1;
	}

	file.seekg(0, ios::end);
	file_length = (int)file.tellp();
	cout << "文件长度" << file_length << "字节" << endl;

	// 使文件在原基础上缩减10字节
	experimental::filesystem::resize_file(fname, file_length-10);

	file.seekg(0, ios::end);
	file_length = (int)file.tellp();
	cout << "文件新长度" << file_length << "字节" << endl;

	cout << "请输入一个字符串(11-50字符之间)" << endl;
	gets_s(buf);

	/* 用输入字符串的内容将文件的前10字节替换掉 */
	file.seekg(0, ios::beg);
	file.write(buf, 10);
//	file << buf;
	file.close();
	/* 执行到此，测试完成 */

	/* 再次读取文件长度 */
	file.open(fname, ios::in | ios::out);
	file.seekg(0, ios::end);
	file_length = (int)file.tellp();
	cout << "关闭后再次验证新文件长度" << file_length << "字节" << endl;
	file.close();

	return 0;
}
