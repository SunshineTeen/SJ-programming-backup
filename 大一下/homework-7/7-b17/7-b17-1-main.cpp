//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<experimental/filesystem>
#include "7-b17-1.h"

using namespace std;

int main()
{
	cout << "**********************************************" << endl;
	cout << "*        接下来将进行程序功能测试部分        *" << endl;
	cout << "*请确认在程序同名目录下存在空文件KanColle.ini*" << endl;
	cout << "*       每组操作间通过敲击回车键以继续       *" << endl;
	cout << "*       执行中途可打开ini文件进行检查        *" << endl;
	cout << "*            （注意不要修改文件）            *" << endl;
	cout << "*              输入回车以继续                *" << endl;
	cout << "**********************************************" << endl;
	WAIT;

	fstream ini;
	ini.open(file_name, ios::in | ios::out | ios::binary);
	if (!ini.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}

	//--------------------------------------group_add----------------------------------------------------
	if (1)
	{
		cout << "group_add测试部分，请按回车继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Harukaze\")："
			<< "预计结果：在文件末尾处出现空白的[Harukaze]项" << endl;
		cout << "返回值预计为1，实际为：" << group_add(ini, "Harukaze") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Taihou\")："
			<< "预计结果：在文件末尾处出现空白的[Taihou]项" << endl;
		cout << "返回值预计为1，实际为：" << group_add(ini, "Taihou") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Taihou\")："
			<< "预计结果：文件无变化" << endl;
		cout << "返回值预计为0，实际为：" << group_add(ini, "Taihou") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Akizuki\")："
			<< "预计结果：在文件末尾处出现空白的[Akizuki]项" << endl;
		cout << "返回值预计为1，实际为：" << group_add(ini, "Akizuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Teruzuki\")："
			<< "预计结果：在文件末尾处出现空白的[Teruzuki]项" << endl;
		cout << "返回值预计为1，实际为：" << group_add(ini, "Teruzuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_add(ini,\"Hatsuzuki\")："
			<< "预计结果：在文件末尾处出现空白的[Hatsuzuki]项" << endl;
		cout << "返回值预计为1，实际为：" << group_add(ini, "Hatsuzuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "group_add测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_add-----------------------------------------------------
	if (1)
	{
		cout << "item_add测试部分，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"搭载\",&i,TYPE_INT)(int i=80)："
			<< "预计结果为：在文件中的[Taihou]项下多出 搭载=80 子项" << endl;
		int i = 86;
		cout << "返回值预计为1，实际为：" << item_add(ini, "Taihou", "搭载", &i, TYPE_INT) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"搭载\",&i,TYPE_INT)(int i=80)："
			<< "预计结果为：文件无变化" << endl;
		cout << "返回值预计为0，实际为：" << item_add(ini, "Taihou", "搭载", &i, TYPE_INT) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"回避\",&d,TYPE_DOUBLE)(double d=59.123)："
			<< "预计结果为：在文件中的[Taihou]项下多出 回避=59.123 子项" << endl;
		double d = 59.123;
		cout << "返回值预计为1，实际为：" << item_add(ini, "Taihou", "回避", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"NULL\",&d,TYPE_NULL)(double d=59.123)："
			<< "预计结果为：在文件中的[Taihou]项下多出 NULL= 子项" << endl;
		cout << "返回值预计为1，实际为：" << item_add(ini, "Taihou", "NULL", &d, TYPE_NULL) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"状态\",&c,TYPE_CHARACTER)(char c='n')："
			<< "预计结果为：在文件中的[Taihou]项下多出 状态=n 子项" << endl;
		char c = 'n';
		cout << "返回值预计为1，实际为：" << item_add(ini, "Taihou", "状态", &c, TYPE_CHARACTER) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Taihou\",\"舰种\",s,TYPE_STRING)(char s[]=\"CV\")："
			<< "预计结果为：在文件中的[Taihou]项下多出 舰种=CV 子项" << endl;
		char s[] = "CV";
		cout << "返回值预计为1，实际为：" << item_add(ini, "Taihou", "舰种", s, TYPE_STRING) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Akizuki\",\"舰种\",_s,TYPE_STRING)(char _s[]=\"DD\")："
			<< "预计结果为：在文件中的[Akizuki]项下多出 舰种=DD 子项" << endl;
		char _s[] = "DD";
		cout << "返回值预计为1，实际为：" << item_add(ini, "Akizuki", "舰种", _s, TYPE_STRING) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_add(ini,\"Hatsuzuki\",\"舰种\",_s,TYPE_STRING)(char _s[]=\"DD\")："
			<< "预计结果为：在文件中的[Hatsuzuki]项下多出 舰种=DD 子项" << endl;
		cout << "返回值预计为1，实际为：" << item_add(ini, "Hatsuzuki", "舰种", _s, TYPE_STRING) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "item_add测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_update--------------------------------------------------
	if (1)
	{
		cout << "item_update测试部分，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_update(ini,\"Taihou\",\"搭载\",&i,TYPE_INT)(int i=86)："
			<< "预计结果为：在文件中的[Taihou]项下搭载子项变为 搭载=86" << endl;
		int i = 86;
		cout << "返回值预计为1，实际为：" << item_update(ini, "Taihou", "搭载", &i, TYPE_INT) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_update(ini,\"Taihou\",\"回避\",&d,TYPE_DOUBLE)(double d=69.123)："
			<< "预计结果为：在文件中的[Taihou]项下回避子项变为 回避=69.123" << endl;
		double d = 69.123;
		cout << "返回值预计为1，实际为：" << item_update(ini, "Taihou", "回避", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_update(ini,\"Taihou\",\"状态\",c,TYPE_STRING)(char c[]='krkr')："
			<< "预计结果为：在文件中的[Taihou]项下子项状态变为 状态=krkr" << endl;
		char c[] = "krkr";
		cout << "返回值预计为1，实际为：" << item_update(ini, "Taihou", "状态", c, TYPE_STRING) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_update(ini,\"Taihou\",\"舰种\",s,TYPE_STRING)(char s[]=\"CVB\")："
			<< "预计结果为：在文件中的[Taihou]项下子项舰种变为 舰种=CVB" << endl;
		char s[] = "CVB";
		cout << "返回值预计为1，实际为：" << item_update(ini, "Taihou", "舰种", s, TYPE_STRING) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_update(ini,\"Taihou\",\"婚\",&_c,TYPE_CHARACTER)(char _c='Y')："
			<< "预计结果为：在文件中的[Taihou]项下多出 婚=Y 子项" << endl;
		char _c = 'Y';
		cout << "返回值预计为1，实际为：" << item_update(ini, "Taihou", "婚", &_c, TYPE_CHARACTER) << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "item_update测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_del-----------------------------------------------------	
	if (1)
	{
		cout << "item_del测试部分，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_del(ini,\"Hatsuzuki\",\"舰种\")："
			<< "预计结果为：在文件中的[Hatsuzuki]项下的 舰种 子项被删除" << endl;
		cout << "返回值预计为1，实际为：" << item_del(ini, "Hatsuzuki", "舰种") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_del(ini,\"Hatsuzuki\",\"舰种\")："
			<< "预计结果为：文件无变化" << endl;
		cout << "返回值预计为0，实际为：" << item_del(ini, "Hatsuzuki", "舰种") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_del(ini,\"Shimakaze\",\"舰种\")："
			<< "预计结果为：文件无变化" << endl;
		cout << "返回值预计为0，实际为：" << item_del(ini, "Shimakaze", "舰种") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_del(ini,\"Taihou\",\"状态\")："
			<< "预计结果为：在文件中的[Taihou]项下的 状态 子项被删除" << endl;
		cout << "返回值预计为1，实际为：" << item_del(ini, "Taihou", "状态") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "item_del测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------group_del----------------------------------------------------
	if (1)
	{
		cout << "group_del测试部分，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_del(ini,\"Teruzuki\")："
			<< "预计结果为：在文件中的[Teruzuki]项被删除" << endl;
		cout << "返回值预计为1，实际为：" << group_del(ini, "Teruzuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_del(ini,\"Teruzuki\")测试部分："
			<< "预计结果为：文件无变化" << endl;
		cout << "返回值预计为0，实际为：" << group_del(ini, "Teruzuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：group_del(ini,\"Akizuki\")："
			<< "预计结果：在文件中的[Taihou]项及其下所有子项被删除" << endl;
		cout << "返回值预计为1，实际为：" << group_del(ini, "Akizuki") << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "group_del测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_get_value-----------------------------------------------
	if (1)
	{
		cout << "item_get_value测试部分，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Taihou\", \"搭载\", &i, TYPE_INT)" << endl;
		int i;
		cout << "返回值预计为1，实际为：" << item_get_value(ini, "Taihou", "搭载", &i, TYPE_INT) << '*' << endl;
		cout << "预计获得值86*，实际为：" << i << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Taihou\", \"搭载\", &d, TYPE_DOUBLE)" << endl;
		double d;
		cout << "返回值预计为1，实际为：" << item_get_value(ini, "Taihou", "回避", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "预计获得值69.123*，实际为：" << d << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Taihou\", \"NULL\", Null, TYPE_NULL)(char Null[] = \"不可改变的值\";)" << endl;
		char Null[] = "不可改变的值";
		cout << "返回值预计为1，实际为：" << item_get_value(ini, "Taihou", "NULL", Null, TYPE_NULL) << '*' << endl;
		cout << "预计获得值 不可改变的值*，实际为：" << Null << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Teruzuki\", \"舰种\", Null, TYPE_INT)(char Null[] = \"不可改变的值\";)" << endl;
		cout << "返回值预计为0，实际为：" << item_get_value(ini, "Teruzuki", "舰种", Null, TYPE_INT) << '*' << endl;
		cout << "预计获得值 不可改变的值*，实际为：" << Null << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Hatsuzuki\", \"舰种\", Null, TYPE_DOUBLE)(char Null[] = \"不可改变的值\";)" << endl;
		cout << "返回值预计为0，实际为：" << item_get_value(ini, "Hatsuzuki", "舰种", Null, TYPE_DOUBLE) << '*' << endl;
		cout << "预计获得值 不可改变的值*，实际为：" << Null << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Taihou\", \"婚\", &c, TYPE_CHARACTER)" << endl;
		char ch;
		cout << "返回值预计为1，实际为：" << item_get_value(ini, "Taihou", "婚", &ch, TYPE_CHARACTER) << '*' << endl;
		cout << "预计获得值Y*，实际为：" << ch << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "操作：item_get_value(ini, \"Taihou\", \"舰种\", &s, TYPE_STRING)" << endl;
		char s[1000];
		cout << "返回值预计为1，实际为：" << item_get_value(ini, "Taihou", "舰种", s, TYPE_STRING) << '*' << endl;
		cout << "预计获得值CVB*，实际为：" << s << '*' << endl;
		cout << "该操作结束，请按回车键继续" << endl << endl;
		WAIT;

		cout << "item_get_value测试结束，按回车键继续" << endl << endl << endl;
		WAIT;
	}

	ini.close();

	cout << "**********************************************" << endl;
	cout << "*               所有项目测试结束             *" << endl;
	cout << "*文件KanColle.ini的最终结果如下：            *" << endl;
	cout << "*[Harukaze]                                  *" << endl;
	cout << "*                                            *" << endl;
	cout << "*[Taihou]                                    *" << endl;
	cout << "*搭载 = 86                                   *" << endl;
	cout << "*回避=69.123000                              *" << endl;
	cout << "*NULL =                                      *" << endl;
	cout << "*舰种 = CVB                                  *" << endl;
	cout << "*婚 = Y                                      *" << endl;
	cout << "*                                            *" << endl;
	cout << "*[Hatsuzuki]                                 *" << endl;
	cout << "*                                            *" << endl;
	cout << "*（此行为文件末尾行）                        *" << endl;
	cout << "*请与文件进行比对，按回车键退出              *" << endl;
	cout << "**********************************************" << endl;
	WAIT;

	return 0;
}
