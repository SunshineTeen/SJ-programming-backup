//ĞÕÃû£ºÍõÕÜÔ´ °à¼¶£º¼ÆËã»ú1°à Ñ§ºÅ£º1652228
#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	Teacher(string, int, char, string, string, string);
	void display();
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
	string title;
};
Teacher::Teacher(string _name, int _age, char _sex, string _addr, string _tel, string _title)
{
	name = _name;
	age = _age;
	sex = _sex;
	addr = _addr;
	tel = _tel;
	title = _title;
}
void Teacher::display()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "address: " << addr << endl;
	cout << "tel: " << tel << endl;
	cout << "title: " << title << endl;
}

class Cadre
{
public:
	Cadre(string, int, char, string, string, string);
	void display();
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
	string post;
};
Cadre::Cadre(string _name, int _age, char _sex, string _addr, string _tel, string _post)
{
	name = _name;
	age = _age;
	sex = _sex;
	addr = _addr;
	tel = _tel;
	post = _post;
}
void Cadre::display()
{
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "address: " << addr << endl;
	cout << "tel: " << tel << endl;
	cout << "post: " << post << endl;
}

class Teacher_Cadre :public Teacher, public Cadre
{
public:
	Teacher_Cadre(string, int, char s, string, string, string , string, double w);
	void show();
private:
	double wages;
};
Teacher_Cadre::Teacher_Cadre(string _name, int _age, char _sex, string _addr, string _tel, string _title, string _post, double _wages) :
	Teacher(_name, _age, _sex, _addr, _tel, _title), Cadre(_name, _age, _sex, _addr, _tel, _post)
{
	wages = _wages;
}
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "post: " << Cadre::post << endl;
	cout << "wages: " << wages << endl;
}

int main()
{
	Teacher_Cadre tc("Taihou", 17, 'f', "Japan", "12345678", "×°¼×¿ÕÄ¸", "ÆìÅ", 123.45);
	
	tc.Teacher::display();
	cout << endl;
	tc.Cadre::display();
	cout << endl;
	tc.show();

	return 0;
}
//Output:
//name: Taihou
//age: 17
//sex: f
//address: Japan
//tel: 12345678
//title: ×°¼×¿ÕÄ¸
//
//name: Taihou
//age: 17
//sex: f
//address: Japan
//tel: 12345678
//post: ÆìÅ
//
//name: Taihou
//age: 17
//sex: f
//address: Japan
//tel: 12345678
//title: ×°¼×¿ÕÄ¸
//post: ÆìÅ
//wages: 123.45
