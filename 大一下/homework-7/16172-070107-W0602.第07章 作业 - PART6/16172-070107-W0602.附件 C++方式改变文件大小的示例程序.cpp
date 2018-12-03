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
	cout << "�ļ�����" << file_length << "�ֽ�" << endl;

	// ʹ�ļ���ԭ����������10�ֽ�
	experimental::filesystem::resize_file(fname, file_length-10);

	file.seekg(0, ios::end);
	file_length = (int)file.tellp();
	cout << "�ļ��³���" << file_length << "�ֽ�" << endl;

	cout << "������һ���ַ���(11-50�ַ�֮��)" << endl;
	gets_s(buf);

	/* �������ַ��������ݽ��ļ���ǰ10�ֽ��滻�� */
	file.seekg(0, ios::beg);
	file.write(buf, 10);
//	file << buf;
	file.close();
	/* ִ�е��ˣ�������� */

	/* �ٴζ�ȡ�ļ����� */
	file.open(fname, ios::in | ios::out);
	file.seekg(0, ios::end);
	file_length = (int)file.tellp();
	cout << "�رպ��ٴ���֤���ļ�����" << file_length << "�ֽ�" << endl;
	file.close();

	return 0;
}
