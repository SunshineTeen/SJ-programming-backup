//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<io.h>
#include<conio.h>
#include<experimental/filesystem>
#include "7-b17-2.h"

using namespace std;

int main()
{
	cout << "**********************************************" << endl;
	cout << "*        �����������г����ܲ��Բ���        *" << endl;
	cout << "*��ȷ���ڳ���ͬ��Ŀ¼�´��ڿ��ļ�KanColle.ini*" << endl;
	cout << "*       ÿ�������ͨ���û��س����Լ���       *" << endl;
	cout << "*       ִ����;�ɴ�ini�ļ����м��        *" << endl;
	cout << "*            ��ע�ⲻҪ�޸��ļ���            *" << endl;
	cout << "*              ����س��Լ���                *" << endl;
	cout << "**********************************************" << endl;
	WAIT;

	FILE *ini=fopen(file_name,"rb+");
	if (ini == NULL)
	{
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}

	//--------------------------------------group_add----------------------------------------------------
	if (1)
	{
		cout << "group_add���Բ��֣��밴�س�����" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Harukaze\")��"
			<< "Ԥ�ƽ�������ļ�ĩβ�����ֿհ׵�[Harukaze]��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_add(ini, "Harukaze") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Taihou\")��"
			<< "Ԥ�ƽ�������ļ�ĩβ�����ֿհ׵�[Taihou]��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_add(ini, "Taihou") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Taihou\")��"
			<< "Ԥ�ƽ�����ļ��ޱ仯" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << group_add(ini, "Taihou") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Akizuki\")��"
			<< "Ԥ�ƽ�������ļ�ĩβ�����ֿհ׵�[Akizuki]��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_add(ini, "Akizuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Teruzuki\")��"
			<< "Ԥ�ƽ�������ļ�ĩβ�����ֿհ׵�[Teruzuki]��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_add(ini, "Teruzuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_add(ini,\"Hatsuzuki\")��"
			<< "Ԥ�ƽ�������ļ�ĩβ�����ֿհ׵�[Hatsuzuki]��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_add(ini, "Hatsuzuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "group_add���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_add-----------------------------------------------------
	if (1)
	{
		cout << "item_add���Բ��֣��밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"����\",&i,TYPE_INT)(int i=80)��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� ����=80 ����" << endl;
		int i = 86;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Taihou", "����", &i, TYPE_INT) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"����\",&i,TYPE_INT)(int i=80)��"
			<< "Ԥ�ƽ��Ϊ���ļ��ޱ仯" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << item_add(ini, "Taihou", "����", &i, TYPE_INT) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"�ر�\",&d,TYPE_DOUBLE)(double d=59.123)��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� �ر�=59.123 ����" << endl;
		double d = 59.123;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Taihou", "�ر�", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"NULL\",&d,TYPE_NULL)(double d=59.123)��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� NULL= ����" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Taihou", "NULL", &d, TYPE_NULL) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"״̬\",&c,TYPE_CHARACTER)(char c='n')��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� ״̬=n ����" << endl;
		char c = 'n';
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Taihou", "״̬", &c, TYPE_CHARACTER) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Taihou\",\"����\",s,TYPE_STRING)(char s[]=\"CV\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� ����=CV ����" << endl;
		char s[] = "CV";
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Taihou", "����", s, TYPE_STRING) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Akizuki\",\"����\",_s,TYPE_STRING)(char _s[]=\"DD\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Akizuki]���¶�� ����=DD ����" << endl;
		char _s[] = "DD";
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Akizuki", "����", _s, TYPE_STRING) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_add(ini,\"Hatsuzuki\",\"����\",_s,TYPE_STRING)(char _s[]=\"DD\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Hatsuzuki]���¶�� ����=DD ����" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_add(ini, "Hatsuzuki", "����", _s, TYPE_STRING) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "item_add���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_update--------------------------------------------------
	if (1)
	{
		cout << "item_update���Բ��֣��밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_update(ini,\"Taihou\",\"����\",&i,TYPE_INT)(int i=86)��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���´��������Ϊ ����=86" << endl;
		int i = 86;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_update(ini, "Taihou", "����", &i, TYPE_INT) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_update(ini,\"Taihou\",\"�ر�\",&d,TYPE_DOUBLE)(double d=69.123)��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���»ر������Ϊ �ر�=69.123" << endl;
		double d = 69.123;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_update(ini, "Taihou", "�ر�", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_update(ini,\"Taihou\",\"״̬\",c,TYPE_STRING)(char c[]='krkr')��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]��������״̬��Ϊ ״̬=krkr" << endl;
		char c[] = "krkr";
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_update(ini, "Taihou", "״̬", c, TYPE_STRING) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_update(ini,\"Taihou\",\"����\",s,TYPE_STRING)(char s[]=\"CVB\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]��������ֱ�Ϊ ����=CVB" << endl;
		char s[] = "CVB";
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_update(ini, "Taihou", "����", s, TYPE_STRING) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_update(ini,\"Taihou\",\"��\",&_c,TYPE_CHARACTER)(char _c='Y')��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���¶�� ��=Y ����" << endl;
		char _c = 'Y';
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_update(ini, "Taihou", "��", &_c, TYPE_CHARACTER) << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "item_update���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_del-----------------------------------------------------	
	if (1)
	{
		cout << "item_del���Բ��֣��밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_del(ini,\"Hatsuzuki\",\"����\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Hatsuzuki]���µ� ���� ���ɾ��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_del(ini, "Hatsuzuki", "����") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_del(ini,\"Hatsuzuki\",\"����\")��"
			<< "Ԥ�ƽ��Ϊ���ļ��ޱ仯" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << item_del(ini, "Hatsuzuki", "����") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_del(ini,\"Shimakaze\",\"����\")��"
			<< "Ԥ�ƽ��Ϊ���ļ��ޱ仯" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << item_del(ini, "Shimakaze", "����") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_del(ini,\"Taihou\",\"״̬\")��"
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Taihou]���µ� ״̬ ���ɾ��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_del(ini, "Taihou", "״̬") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "item_del���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------group_del----------------------------------------------------
	if (1)
	{
		cout << "group_del���Բ��֣��밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_del(ini,\"Teruzuki\")��" 
			<< "Ԥ�ƽ��Ϊ�����ļ��е�[Teruzuki]�ɾ��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_del(ini, "Teruzuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_del(ini,\"Teruzuki\")���Բ��֣�" 
			<< "Ԥ�ƽ��Ϊ���ļ��ޱ仯" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << group_del(ini, "Teruzuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������group_del(ini,\"Akizuki\")��"
			<< "Ԥ�ƽ�������ļ��е�[Taihou]������������ɾ��" << endl;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << group_del(ini, "Akizuki") << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "group_del���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	//--------------------------------------item_get_value-----------------------------------------------
	if (1)
	{
		cout << "item_get_value���Բ��֣��밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Taihou\", \"����\", &i, TYPE_INT)" << endl;
		int i;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_get_value(ini, "Taihou", "����", &i, TYPE_INT) << '*' << endl;
		cout << "Ԥ�ƻ��ֵ86*��ʵ��Ϊ��" << i << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Taihou\", \"����\", &d, TYPE_DOUBLE)" << endl;
		double d;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_get_value(ini, "Taihou", "�ر�", &d, TYPE_DOUBLE) << '*' << endl;
		cout << "Ԥ�ƻ��ֵ69.123*��ʵ��Ϊ��" << d << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Taihou\", \"NULL\", Null, TYPE_NULL)(char Null[] = \"���ɸı��ֵ\";)" << endl;
		char Null[] = "���ɸı��ֵ";
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_get_value(ini, "Taihou", "NULL", Null, TYPE_NULL) << '*' << endl;
		cout << "Ԥ�ƻ��ֵ ���ɸı��ֵ*��ʵ��Ϊ��" << Null << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Teruzuki\", \"����\", Null, TYPE_INT)(char Null[] = \"���ɸı��ֵ\";)" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << item_get_value(ini, "Teruzuki", "����", Null, TYPE_INT) << '*' << endl;
		cout << "Ԥ�ƻ��ֵ ���ɸı��ֵ*��ʵ��Ϊ��" << Null << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Hatsuzuki\", \"����\", Null, TYPE_DOUBLE)(char Null[] = \"���ɸı��ֵ\";)" << endl;
		cout << "����ֵԤ��Ϊ0��ʵ��Ϊ��" << item_get_value(ini, "Hatsuzuki", "����", Null, TYPE_DOUBLE) << '*' << endl;
		cout << "Ԥ�ƻ��ֵ ���ɸı��ֵ*��ʵ��Ϊ��" << Null << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Taihou\", \"��\", &c, TYPE_CHARACTER)" << endl;
		char ch;
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_get_value(ini, "Taihou", "��", &ch, TYPE_CHARACTER) << '*' << endl;
		cout << "Ԥ�ƻ��ֵY*��ʵ��Ϊ��" << ch << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "������item_get_value(ini, \"Taihou\", \"����\", &s, TYPE_STRING)" << endl;
		char s[1000];
		cout << "����ֵԤ��Ϊ1��ʵ��Ϊ��" << item_get_value(ini, "Taihou", "����", s, TYPE_STRING) << '*' << endl;
		cout << "Ԥ�ƻ��ֵCVB*��ʵ��Ϊ��" << s << '*' << endl;
		cout << "�ò����������밴�س�������" << endl << endl;
		WAIT;

		cout << "item_get_value���Խ��������س�������" << endl << endl << endl;
		WAIT;
	}
	
	fclose(ini);

	cout << "**********************************************" << endl;
	cout << "*               ������Ŀ���Խ���             *" << endl;
	cout << "*�ļ�KanColle.ini�����ս�����£�            *" << endl;
	cout << "*[Harukaze]                                  *" << endl;
	cout << "*                                            *" << endl;
	cout << "*[Taihou]                                    *" << endl;
	cout << "*���� = 86                                   *" << endl;
	cout << "*�ر�=69.123000                              *" << endl;
	cout << "*NULL =                                      *" << endl;
	cout << "*���� = CVB                                  *" << endl;
	cout << "*�� = Y                                      *" << endl;
	cout << "*                                            *" << endl;
	cout << "*[Hatsuzuki]                                 *" << endl;
	cout << "*                                            *" << endl;
	cout << "*������Ϊ�ļ�ĩβ�У�                        *" << endl;
	cout << "*�����ļ����бȶԣ����س����˳�              *" << endl;
	cout << "**********************************************" << endl;
	WAIT;

	return 0;
}
