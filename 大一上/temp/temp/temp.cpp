#include<iostream>
#include<cstdio>
#include<conio.h>

using namespace std;

int main()
{
	char *c[] = { "John learn C++ language",
		"Be well!","You","Not very" };
	char **p[] = { c + 3, c + 2, c + 1, c };
	char ***pp = p;
	cout << (**++pp); //You  *pp=p[1]
	cout << (*--*++pp + 4);//learn C++ language *pp=p[2]
	cout << (*pp[-2] + 3);// very
	cout << (pp[-1][-1] + 2);// well
	cout << endl;
	system("pause");
	return 0;
}
