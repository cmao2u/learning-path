#include <iostream>
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





	return 0;

}
