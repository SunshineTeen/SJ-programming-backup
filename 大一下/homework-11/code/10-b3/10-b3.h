//����������Դ �༶�������1�� ѧ�ţ�1652228
#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
	private:
		char *content;
		int   len;
	public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
int TStringLen(const TString &);
void Realloc(char *&, int &);
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
const int block_size = 1024;
