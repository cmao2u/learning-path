#include <iostream>
using namespace std;

/*3.2函数占位
void func(int a,int)
{
	cout<< "this is func";
}*/

/*3.3函数重载
void func(int a, double b)
{
	cout << "这是func01";
}
void func(double a, int b)
{
	cout << "这是func02";
}
void func(int& a)
{
	cout << "这是func&" << endl;
}
void func(const int& a)
{
	cout << "这是func const" << endl;
}*/
/*四--类和对象
4.1.1封装--属性和行为为主体
const double PI = 3.14159;
class circle
{
public://访问权限
	double r;//属性
	double perimeter()//行为
	{
		return PI * 2 * r;
	}
};*/
/*封装案例
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
		cout << "名字是" << s_name << '\t' << "学号是" <<s_number << endl;
	}
};*/
/*访问权限
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
		name = "张三";
		car = "问界";
		password = "154862";
	}
};*/
/*struct和class的区别是前者访问权限默认为是public而后者默认是private
class c1
{
	int a;
};
struct c2
{
	int a;
};*/
/*成员属性设置为私有
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
			cout << "输入有误" << endl;
			return;
		}
		else {
			age = age02;
		}
	}
};*/ 
/*设计案例一
立方体类
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
	/*4.1.1类和对象
	circle c1;//创建一个对象
	c1.r = 4;
	cout << "圆的周长是" << c1.perimeter() << endl;*/
	/*4.1封装案例
	student s1;
	s1.in_name("张三");
	s1.in_number("15090");
	s1.showinfo();*/
	/*4.1访问权限
	Person p1;
	p1.name = "李四";
	p1.car = "红旗";//protect不可类外访问
	p1.password = "15246";//private不可类外访问*/
	/*区别
	c1 c1;
	c1.a = 10;//错误
	c2 c2;
	c2.a = 10;*/
	/*4.1成员属性设置为私有
	Person p1;
	p1.setname("张三");
	cout<<p1.getname();
	cout<<p1.getage();*/

	/*设计案例一
	立方体类
	cube c1;
	cube c2;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	c2.setH(20);
	c2.setL(20);	
	c2.setW(20);	
	cout << "长方体的体积是" << c1.volume() << endl;	
	cout << "长方体的表面积是" << c1.area() << endl;	
	int ret = issame(c1, c2);
	if (ret == 1)
	{
		cout << "两个立方体是相等的" << endl;
	}
	else
		{
		cout << "两个立方体是不相等的" << endl;
	}
	int ret2 = c1.issamebyclass(c2);
	if (ret2 == 1)
	{
		cout << "两个立方体是相等的" << endl;
	}
	else
	{
		cout << "两个立方体是不相等的" << endl;
	}
*/





	return 0;

}
