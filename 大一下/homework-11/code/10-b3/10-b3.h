//姓名：王哲源 班级：计算机1班 学号：1652228
#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
	private:
		char *content;
		int   len;
	public:
	/* 根据需要定义所需的成员函数、友元函数等 */
		TString();
		~TString();
		TString(const char *const);
		TString(const TString&);

		friend istream& operator >> (istream&, TString&);
		friend ostream& operator <<(ostream&, TString&);

		TString& operator =(const TString&);
		
		friend TString operator +(const TString&, const TString&);
		friend TString operator +(const TString &, const char *const);
		friend TString operator +(const char *const, const TString &);

		friend bool operator >(const TString &, const TString &);
		friend bool operator <(const TString &, const TString &);
		friend bool operator >=(const TString &, const TString &);
		friend bool operator <=(const TString &, const TString &);
		friend bool operator ==(const TString &, const TString &);
		friend bool operator !=(const TString &, const TString &);

		int length()const;

		char& operator [](const int)const;
};

/* 如果有其它全局函数需要声明，写于此处 */
int TStringLen(const TString &);
void Realloc(char *&, int &);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int block_size = 1024;
