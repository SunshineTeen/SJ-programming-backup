//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	char *ch = "Taihou";
	char *p= (char*)malloc(strlen(ch)*sizeof(char*));
	strcpy(p, ch);
	free(p);

	puts("Done");
	system("pause");

	return 0;
}
