#include <iostream>
#include"point.h"
#include"circle.h"
#include "isInCircle.h"
using namespace std;
/*3.2����ռλ
void func(int a,int)
{
	cout<< "this is func";
}*/

/*3.3��������
void func(int a, double b)
{
	cout << "����func01";
}
void func(double a, int b)
{
	cout << "����func02";
}
void func(int& a)
{
	cout << "����func&" << endl;
}
void func(const int& a)
{
	cout << "����func const" << endl;
}*/
/*��--��Ͷ���
4.1.1��װ--���Ժ���ΪΪ����
const double PI = 3.14159;
class circle
{
public://����Ȩ��
	double r;//����
	double perimeter()//��Ϊ
	{
		return PI * 2 * r;
	}
};*/
/*��װ����
class student
{
public:
	string  s_name;
	string  s_number;
	void in_name(string name)
	{
		s_name = name;
	}
	void in_number(string number)
	{
		s_number = number;
}
	void showinfo()
	{
		cout << "������" << s_name << '\t' << "ѧ����" <<s_number << endl;
	}
};*/
/*����Ȩ��
class Person
{
public:
	string name;
protected:
	string car;
private:
	string password;
public:
	void func()
	{
		name = "����";
		car = "�ʽ�";
		password = "154862";
	}
};*/
/*struct��class��������ǰ�߷���Ȩ��Ĭ��Ϊ��public������Ĭ����private
class c1
{
	int a;
};
struct c2
{
	int a;
};*/
/*��Ա��������Ϊ˽��
class Person
{

private:
	string name;
	int age=19;
	string idol;
public:
	void setname(string name02) {
		name = name02;
	} 
	string getname()
	{
		return name;
	}
	int getage()
	{
		return age;
	}
	void setidol(string idol02)
	{
		idol = idol02;
	}
	void setage(int age02)
	{
		if (age02 > 150 || age < 0)
		{
			cout << "��������" << endl;
			return;
		}
		else {
			age = age02;
		}
	}
};*/ 
/*��ư���һ
��������
class cube
{
private:
	double m_L;
	double m_W;
	double m_H;	
public:
	void setL(double L)
	{
		m_L = L;
	}
	void setW(double W)
	{
		m_W = W;
	}
	void setH(double H)
	{
		m_H = H;
	}
	double getL()
	{
		return m_L;
	}	
	double getW()
	{
		return m_W;
	}	
	double getH()
	{
		return m_H;
	}
	double volume()
	{
		return m_L * m_W * m_H;
	}
	double area()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	bool issamebyclass(cube& c)
	{
		if (m_L == c.m_L && m_W == c.m_W && m_H == c.m_H)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};
bool issame(cube& c1, cube& c2)
{
	if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW())
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

/*4.2��������
���캯������������
class Person
{
public:
	Person()
	{
		cout << "���ǹ��캯��" << endl;
	}
	~Person()
	{
		cout << " ������������" << endl;
	}

};
void test01()
{
	Person p;
}*/
/*4.2.2�������캯�������
class person
{
public:
	person()
	{
		cout << "���ǹ��캯�����޲�)" << endl;
	}
	person(int a)		
	{
		 age = a;
		cout << "���ǹ��캯��(�в�)" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "���ǿ������캯��" << endl;
	}
	~person()
	{
		cout << "������������" << endl;
	}
private: 
	int age;
};
void test01()
{
	person p1;
}
void test02()
{
	person p2(10);
}*/
/*
class person
{
public:

	person()
	{
		cout << "����һ���޲ι��캯��" << endl;
	}
	person(int a)
	{
		age = a;
		cout << "����һ���вι��캯��" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "����һ���������캯��" << endl;
	}
	~person()
	{
		cout << "����һ����������" << endl;
	}
	
public:
	int age;
};
void test01()
{
	person p1(10);
	person p2(p1);
	cout << "p2��������" << p2.age<<endl;

}
void test02(person p)
{

}
void test03()
{
	person p1;
	test02(p1);//���п������캯��person p(test02)=p1(test03)
}
person test04()
{
	person p2;
	cout << (int*)&p2 << endl;
	return person(p2);//ȥ��person����NRVO
}
void test05()
{
	person p3 = test04();
	cout << (int*)&p3 << endl;
}
*/

/*4.2.5ǳ���������
class person
{
public:
	int *height;
	person(int a)
	{
		height = new int(a);
	}
	person(const person& p)
	{
		height=new int(*p.height);
	}
	~person()
	{
		if (height != NULL)
		{
			delete height;
			height = NULL;

		}
	}
	
	
};
void test01()
{
	person p1(173);
	person p2(p1);
	cout << "p1�����" << *p1.height << endl;
	cout << "p2�����" << *p2.height << endl;
}*/
/*4.2.6��ʼ���б�
class person
{
public:
	person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
	{ }
	int m_a;
	int m_b;
	int m_c;

};*/
/*4.2.7
����
class phone
{
public:
	string p_name;
	phone(string name)
	{
		p_name = name;
		cout << "Phone����" << endl;
	}
	~phone()
	{
		cout << "phone����" << endl;
	}
};
class person
{
public:
	string name;
	phone phone;
	person(string name, string p_name) :name(name), phone(p_name)
	{
		cout << "Person����" << endl;
	}
	~person()
	{
		cout << "Person����" << endl;
	}
};
void test01()
{
	person p("����", "honor");
	cout << p.name << "��" << p.phone.p_name << endl;
};*/
/*4.27
static
class person
{
public:
	static int age;

};
int person::age = 18; 
*/
int main()
{
	/*func(1, 3.12);
	func(3.12, 1);
	int a = 10;
	func(a);
	func(10);*/
	/*4.1.1��Ͷ���
	circle c1;//����һ������
	c1.r = 4;
	cout << "Բ���ܳ���" << c1.perimeter() << endl;*/
	/*4.1��װ����
	student s1;
	s1.in_name("����");
	s1.in_number("15090");
	s1.showinfo();*/
	/*4.1����Ȩ��
	Person p1;
	p1.name = "����";
	p1.car = "����";//protect�����������
	p1.password = "15246";//private�����������*/
	/*����
	c1 c1;
	c1.a = 10;//����
	c2 c2;
	c2.a = 10;*/
	/*4.1��Ա��������Ϊ˽��
	Person p1;
	p1.setname("����");
	cout<<p1.getname();
	cout<<p1.getage();*/

	/*��ư���һ
	��������
	cube c1;
	cube c2;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	c2.setH(20);
	c2.setL(20);	
	c2.setW(20);	
	cout << "������������" << c1.volume() << endl;	
	cout << "������ı������" << c1.area() << endl;	
	int ret = issame(c1, c2);
	if (ret == 1)
	{
		cout << "��������������ȵ�" << endl;
	}
	else
		{
		cout << "�����������ǲ���ȵ�" << endl;
	}
	int ret2 = c1.issamebyclass(c2);
	if (ret2 == 1)
	{
		cout << "��������������ȵ�" << endl;
	}
	else
	{
		cout << "�����������ǲ���ȵ�" << endl;
	}
*/

	/*����2
	point p1;
	p1.setX(10);
	p1.setY(10);
	circle c1;
	c1.setR(10);
	point center;
	center.setX(10);
	center.setY(0);
	c1.setcenter(center);
	isInCircle(c1, p1);*/

	//test01();
	//Person p;


	/*person p1;
	person p2(10);
	person p3(p2);*/
	/*4.2.2
	�������캯�������
	test01();
	test02();*/

	/*4.2.3���������ĵ���ʱ��
	test01();
	test03();
	test05();*/

	//test01();


	//test01();
	//cout << person::age << endl;


	return 0;

}
