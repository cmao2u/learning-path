#include <iostream>
#include"point.h"
#include"circle.h"
#include "isInCircle.h"
#include <fstream>
#include <ctime>
#include <string>
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

/*4.2对象特性
构造函数和析构函数
class Person
{
public:
	Person()
	{
		cout << "这是构造函数" << endl;
	}
	~Person()
	{
		cout << " 这是析构函数" << endl;
	}

};
void test01()
{
	Person p;
}*/
/*4.2.2拷贝构造函数与调用
class person
{
public:
	person()
	{
		cout << "这是构造函数（无参)" << endl;
	}
	person(int a)		
	{
		 age = a;
		cout << "这是构造函数(有参)" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "这是拷贝构造函数" << endl;
	}
	~person()
	{
		cout << "这是析构函数" << endl;
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
		cout << "这是一个无参构造函数" << endl;
	}
	person(int a)
	{
		age = a;
		cout << "这是一个有参构造函数" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "这是一个拷贝构造函数" << endl;
	}
	~person()
	{
		cout << "这是一个析构函数" << endl;
	}
	
public:
	int age;
};
void test01()
{
	person p1(10);
	person p2(p1);
	cout << "p2的年龄是" << p2.age<<endl;

}
void test02(person p)
{

}
void test03()
{
	person p1;
	test02(p1);//运行拷贝构造函数person p(test02)=p1(test03)
}
person test04()
{
	person p2;
	cout << (int*)&p2 << endl;
	return person(p2);//去掉person触发NRVO
}
void test05()
{
	person p3 = test04();
	cout << (int*)&p3 << endl;
}
*/

/*4.2.5浅拷贝与深拷贝
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
	cout << "p1身高是" << *p1.height << endl;
	cout << "p2身高是" << *p2.height << endl;
}*/
/*4.2.6初始化列表
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
子类
class phone
{
public:
	string p_name;
	phone(string name)
	{
		p_name = name;
		cout << "Phone构造" << endl;
	}
	~phone()
	{
		cout << "phone析构" << endl;
	}
};
class person
{
public:
	string name;
	phone phone;
	person(string name, string p_name) :name(name), phone(p_name)
	{
		cout << "Person构造" << endl;
	}
	~person()
	{
		cout << "Person析构" << endl;
	}
};
void test01()
{
	person p("张三", "honor");
	cout << p.name << "用" << p.phone.p_name << endl;
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
/*4.3C++对象模型和this指针
* 4.3.1 成员变量和成员函数分开存储
class person
{public:
	int m_a;
};*/
/*this指针的用法
class person
{
public:
	int age;
	person(int age)
	{
		this->age = age;
	}
	person& personaddage(person p)
	{
		this->age += p.age;
		return *this;
	}
};
void test01()
{
	person p1(10);
	cout << p1.age << endl;
	person p2(10);
	p2.personaddage(p1).personaddage(p1).personaddage(p1);//链式编程
	cout << p2.age << endl;
}*/
/*4.3.3空指针访问成员函数
class person
{
public:
	int m_age;
	void func01()
	{
		cout << "nothing" << endl;
	}
	void func02()
	{
		if (this == NULL)
		{
			return ;
		}
		cout <<this->m_age << endl;
	}
};
void test01()
{
	person* p = NULL;
	p->func01();
	p->func02();
}*/
/*4.3.4 const修饰成员函数
class person
{
public:
	mutable int m_age;
	 int m_age2;


	void func01() const
	{
		m_age = 100;
	}
};
void test02()
{

}
void test01()
{
	const person p;
	p.m_age = 100;
	p.func01();
}
常函数：
成员函数后加const后我们称为这个函数为常函数
常函数内不可以修改成员属性
成员属性声明时加关键字mutable后，在常函数中依然可以修改
常对象：
声明对象前加const称该对象为常对象
常对象只能调用常函数*/
/*4.4友元
* 4.4.1 全局函数做友元
class building
{public:
	string m_bedroom;
	building()
	{
		m_bedroom = "卧室";
		m_livingroom = "客厅";
	}
private:
	string m_livingroom;
	friend void func01(building *b1)
	{
		 cout << "正在访问" << b1->m_bedroom<< endl;
		 cout << "正在访问" << b1->m_livingroom << endl;
	}
	
};
void test01()
{
	building b;
	func01(&b);
}*/
/*类做友元
class person;
class building
{
public:
	string m_livingroom;
	building();
	friend class person;
private:
	string m_bedroom;
	
};
building::building()
{
	m_bedroom = "卧室";
}
class person
{
public:
	void visit()
	{
		building* b1 = new building;
		cout << "正在访问" << b1->m_bedroom;
	}
};
void test01()
{
	person p;
	p.visit();
}*/
/*4.5.1 加号运算符重载
class person
{
public:
	int m_A;
	int m_B;
	person()
	{ }
person(int a,int b):m_A(a),m_B(b)
{ }
//person& operator+(const person& p1)
//{
//	person temp;
//	temp.m_A = this->m_A + p1.m_A;
//	temp.m_B = this->m_B + p1.m_B;
//	return temp;
//}

};
//person& operator+(person& p1, int val)
//{
//	person temp;
//	temp.m_A = p1.m_A + val;
//	temp.m_B = p1.m_A + val;
//	return temp;
//}
person& operator+(person& p1, person &p2)
{
	person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_A + p2.m_B ;
	return temp;
}
void test() {
	person p1(10, 10);
	person p2(20, 20);
	//成员函数方式
	person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
	//person p4 = p3 + 10; //相当于 operator+(p3,10)
	//cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}*/
/*4.5.2 左移运算符重载
class person
{
	friend ostream& operator<<(ostream& cout, person& p);
private:
	int m_A;
	int m_B;
public:
	person()
	{ }
	person(int a, int b) :m_A(a), m_B(b)
	{

	}
};
ostream& operator<<(ostream& cout, person& p)
{
	cout << "m_A:" << p.m_A << " m_B:" << p.m_B;
	return cout;
}
void test01()
{
	person p(10, 10);
	cout << p << " helloworld" << endl;

}*/
/*/递增运算符重载
class person
{
public:
	person()
	{ }
	person(int age) :m_A(age)
	{ }
	friend	ostream& operator<<(ostream& cout, person p);
	person& operator--()
	{
		m_A--;
		return *this;
	}
	person operator--(int)
	{
		person temp=*this;
		m_A--;
		return temp;
		
	}
private:
	int m_A;

};
ostream& operator<<(ostream& cout, person p)
{
	cout << "m_A:" << p.m_A << endl;
	return cout;
}

void test01()
{
	person p1(10);
	cout << --(--p1);
	cout << p1;
	person p2(10);
	cout << p2-- << endl;
	cout << p2 << endl;
}*/
/*4.5.4 赋值运算符重载
class person
{
public:
	friend ostream& operator<<(ostream& cout, person& p);
	person(int a)
	{
		m_A = new int(a);
	}
	person& operator=(person& p)
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
		m_A = new int(*p.m_A);
		return *this;
	}
	~person()
	{
		if (m_A != NULL)
		{
			delete m_A;
			m_A = NULL;
		}
	}

private:
	int *m_A;

};
ostream& operator<<(ostream& cout, person& p)
{
	cout << *p.m_A << endl;
	return cout;
}
void test01()
{
	person p1(10);
	person p2(19);
	person p3(29);
	cout << p1;
	cout << p2;
	cout << p3;
	p3=p2 = p1;
	cout << p2 << endl;
	cout << p3;
}*/
/*4.5.5 关系运算符重载
class person
{
public:
	person(int a, string name1) :m_A(a), name(name1)
	{

	}
	bool operator==(person& p)
	{
		if (name == p.name &&m_A==p.m_A)
			return true;
		else return false;
	}
private:
	int m_A;
	string name;
};
void test01()
{
	person p1(18, "张三");
	person p2(18,"tom");
	if (p1 == p2)
	{
		cout << "相同" << endl;
	}
	else cout << "不同" << endl;

}*/
/*继承方式
class base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;

};
class son1 :public base1
{
public:
	void func()
	{
		m_A = 10;
			m_B = 10;
			//m_C = 10;//错误
	}
};
class son2 :protected base1
{ 
public:
	void func()
	{
				m_A = 10;
		m_B = 10;
		//m_C = 10;//错误
	}
};
class son3 :private base1
{
	public:
	void func()
	{
		m_A = 10;
		m_B = 10;
		//m_C = 10;//错误
	}
};
void test01()
{
	son1 s1;
	s1.m_A = 10;
		s1.m_B = 10;
		s1.m_C = 10;
}
void test02()
{
	son2 s2;
	s2.m_A = 10;
	s2.m_B = 10;
	s2.m_C = 10;
}
void test03()
{
	son3 s3;
	s3.m_A = 10;
	s3.m_B = 10;
	s3.m_C = 10;
}*/
/*
class base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class son1 :public base1
{
public:
	int m_D;
	
};
void test01()
{
	cout << "sizeof Son = " << sizeof(son1) << endl;
}*/
/*4.6.7 多继承语法
class base1
{
public:
	int m_A;
	base1()
	{
		m_A = 10;
	}
};
class base2
{
public:
	int m_B;
	base2()
	{
		m_B = 20;
	}
};
class son :public base1, public base2
{
public:
	int m_C;
	int m_D;
	son()
	{
		m_C = 12;
		m_D = 32;
	}
};
void test01()
{
	son s;
	cout << s.m_A << endl;
	s.m_A = 98;
	cout << s.m_A << endl;
	cout << sizeof(s) << endl;
}*/ 
/*菱形继承和虚继承
class animal
{
public:
	int age;

};
class sheep : virtual public animal
{
};
class goldenfish : virtual public animal
{
	
};
class dog : public sheep, public goldenfish
{
public:
	dog()
	{
	}
	
};
void test01()
{
	dog d;
	d.sheep::age = 109;
	d.goldenfish::age = 98;
	cout << "sheep age:" << d.sheep::age << endl;
	cout << "goldenfish age:" <<d. goldenfish::age << endl;
	cout << "animal age:" << d.age << endl;
}*/
/*4.7.1 多态的基本概念
class animal
{
public:
	virtual void speak()//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	{
		cout << "动物在说话" << endl;
	}

};
class cat :public animal
{
public:
	void speak()
	{
		cout << "喵喵喵" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "汪汪汪" << endl;
	}
};
void dospeak(animal& animal)
{
	animal.speak();
}
void test01()
{
	cat cat;
	dospeak(cat);
	dog dog;
	dospeak(dog);

} //多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象*/
/*4.7.2 多态案例一-计算器类
class calculator
{
public:
	int m_Number1;
	int m_Number2;
	virtual int getresult()
	{
		return 0;
	}
};
class addcalculator:public calculator
{
public:
	int getresult()
	{
		return m_Number1 + m_Number2;
	}
};
class subcalculator:public calculator
{
public:
	int getresult()
	{
		return m_Number1 - m_Number2;
	}
};
class mulcalculator:public calculator
{
public:
	int getresult()
	{
		return m_Number1 * m_Number2;
	}
};
void test01()
{
	calculator* ptr = new addcalculator;
	ptr->m_Number1 = 100;
	ptr->m_Number2 = 100;
	cout << ptr->m_Number1 << "+" << ptr->m_Number2 << "="<<ptr->getresult() << endl;
	delete  ptr;
	


	ptr = new subcalculator;
	ptr->m_Number1 = 100;
	ptr->m_Number2 = 100;
	cout << ptr->m_Number1 << "-" << ptr->m_Number2 << "=" <<ptr->getresult() << endl;
	delete  ptr;
	ptr = new mulcalculator;
	ptr->m_Number1 = 100;
	ptr->m_Number2 = 100;
	cout << ptr->m_Number1 << "*" << ptr->m_Number2 <<"=" << ptr->getresult() << endl;
	delete  ptr;
	
}*/
/*4.7.3 纯虚函数和抽象类
class base
{
public:
	virtual void func() = 0;
};
class son :public base
{
public:
	void func()
	{
		cout << "重写" << endl;
	}
};
void test01()
{
	base* base = new son;
	base->func();
	delete base;
}*/
/*制作饮品
class abstractdrink
{
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddThings() = 0;
};
class coffee :public abstractdrink
{
public:
	void boil()
	{
		cout << "煮水" << endl;
	}
	void brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	void AddThings()
	{
		cout << "加糖和牛奶" << endl;
	}
};
class tea :public abstractdrink
{
	public:
	void boil()
	{
		cout << "煮水" << endl;
	}
	void brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	void AddThings()
	{
		cout << "加柠檬" << endl;
	}
};
void dowork(abstractdrink* drink)
{
	drink->boil();
	drink->brew();
	drink->PourInCup();
	drink->AddThings();
}
void test01()
{
	abstractdrink* drink = new coffee;
	dowork(drink);
	delete drink;
	cout << "-------------------" << endl;
	drink = new tea;
	dowork(drink);
	delete drink;
}*/
/*4.7.5 虚析构和纯虚析构
class animal
{
public:
	animal()
	{
		cout << "animal构造函数调用" << endl;
	}
	virtual void speak() = 0;
	virtual ~animal() = 0;
};
animal::~animal()
{
	cout << "animal析构函数调用" << endl;
}
class cat :public animal
{
public:
	cat(string name)
	{
		cout << "cat构造函数调用" << endl;
		m_Name = new  string (name);
	}
	void speak()
	{
		cout <<*m_Name <<"喵喵喵" << endl;
	}
	~cat()
	{
		cout << "cat析构函数调用" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	string *m_Name;
};
void test01()
{
	animal* animal = new cat("tom小猫");
	animal->speak();
	delete animal;
}*/
/*4.7.6 多态案例三-电脑组装
class CPU
{
public:
	virtual void  calculate() = 0;
};
class videoCard
{
	public:
	virtual void display() = 0;
};
class memory
{
	public:
	virtual void storage() = 0;
};
class computer
{
public:
	computer(CPU* cpu, videoCard* vc, memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	 ~computer()
	{
		 if(m_cpu!=NULL)
		 {
			 delete m_cpu;
			 m_cpu = NULL;
		 }
		 if (m_vc != NULL)
		 {
			 delete m_vc;
			 m_vc = NULL;
		 }
		 if (m_mem != NULL)
		 {
			 delete m_mem;
			 m_mem = NULL;
		 }
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
private:
	CPU* m_cpu;
	videoCard* m_vc;
	memory* m_mem;
};
class intelCPU :public CPU
{
	public:
	void calculate()
	{
		cout << "intel CPU计算中" << endl;
	}
};
class intelVideoCard :public videoCard
{
	public:
	void display()
	{
		cout << "intel 显卡显示中" << endl;
	}
};
class intelMemory :public memory
{
	public:
	void storage()
	{
		cout << "intel 内存储存中" << endl;
	}
};
class lenovoCPU :public CPU
{
	public:
	void calculate()
	{
		cout << "lenovo CPU计算中" << endl;
	}
};
class lenovoVideoCard :public videoCard
{
	public:
	void display()
	{
		cout << "lenovo 显卡显示中" << endl;
	}
};
class lenovoMemory :public memory
{
	public:
	void storage()
	{
		cout << "lenovo 内存储存中" << endl;
	}
};
void test01()
{
	CPU* cpu = new intelCPU;
	videoCard* vc = new intelVideoCard;
	memory* mem = new intelMemory;
	computer* computer1 = new computer(cpu, vc, mem);
	computer1->work();
	delete computer1;
	cpu = new lenovoCPU;
	vc = new lenovoVideoCard;
	mem = new lenovoMemory;
	computer* computer2 = new computer(cpu, vc, mem);
	computer2->work();
	delete computer2;
}*/
/*5.1.1写文件
void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "橙猫猫在学操作文件" << endl;
	ofs << "加油" << endl;
	ofs << "2025.10.27" << endl;
	ofs.close();
	cout << "文件写入成功" << endl;
}*/
/*
void test01()
{
		const int repeat = 1000;  // 循环次数（不宜过大，否则运行过久）
		clock_t start, end;
		ifstream ifs;
		string filename = "test.txt";  // 待读取的文件

		// 1. 方式一：使用 >> 运算符读取（按空白分隔）
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {  // 检查文件是否打开成功
			cout << "方式一：文件打开失败！" << endl;
			return;
		}
		start = clock();  // 开始计时
		for (int i = 0; i < repeat; i++) {
			char buf[10240] = { 0 };
			ifs.clear();  // 重置文件状态（清除eofbit等标志）
			ifs.seekg(0, ios::beg);  // 指针移回文件开头
			while (ifs >> buf) {  // 按空白（空格/换行）分隔读取
				// 注释掉控制台输出，避免拖慢测试（输出速度远慢于文件读取）
				// cout << buf << " ";
			}
			// cout << endl;  // 每行结束换行（仅作格式参考）
		}
		end = clock();  // 结束计时
		ifs.close();
		cout << "方式一（>> 运算符）用时："
			<< (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;


		// 2. 方式二：使用 ifstream::getline 读取（C风格字符数组）
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "方式二：文件打开失败！" << endl;
			return;
		}
		start = clock();
		for (int i = 0; i < repeat; i++) {
			char buf[10240] = { 0 };
			ifs.clear();
			ifs.seekg(0, ios::beg);
			while (ifs.getline(buf, sizeof(buf))) {  // 按行读取（C数组）
				// cout << buf << endl;
			}
		}
		end = clock();
		ifs.close();
		cout << "方式二（ifs.getline + 字符数组）用时："
			<< (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;


		// 3. 方式三：使用全局 getline 读取（C++ string）
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "方式三：文件打开失败！" << endl;
			return;
		}
		start = clock();
		for (int i = 0; i < repeat; i++) {
			string buf;
			ifs.clear();
			ifs.seekg(0, ios::beg);
			while (getline(ifs, buf)) {  // 按行读取（C++ string，更灵活）
				// cout << buf << endl;
			}
		}
		end = clock();
		ifs.close();
		cout << "方式三（全局getline + string）用时："
			<< (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;


		// 4. 方式四：使用 ifstream::get 读取（逐个字符）
		ifs.open(filename, ios::in);
		if (!ifs.is_open()) {
			cout << "方式四：文件打开失败！" << endl;
			return;
		}
		start = clock();
		for (int i = 0; i < repeat; i++) {
			char c;
			ifs.clear();
			ifs.seekg(0, ios::beg);
			while ((c = ifs.get()) != EOF) {  // 逐个字符读取
				// cout << c;
			}
			// cout << endl;
		}
		end = clock();
		ifs.close();
		cout << "方式四（ifs.get 逐个字符）用时："
			<< (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

}*/
/*最快
char buf[1024] = { 0 };
 while (ifs.getline(buf,sizeof(buf)))
 {
   cout << buf << endl;
}*//*
void test01() {


	ifstream ifs;
	ifs.open("test.txt", ios::in);
	char buf[10245] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;

	}

}*/
/*
class person
{
public:	
	string name;
	 int age;

};
void test01()
{
	ofstream ofs;
	ofs.open("test2.txt", ios::out | ios::binary);
	person p1 = { "张三",18 };
	ofs.write((const char *) &p1, sizeof(p1));
}*/
/*5.2.2 读文件
class person
{
public:
	string name;
	int age;

};
void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in | ios::binary);
	if(!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	person p1;
	ifs.read((char*)&p1, sizeof(p1));
	cout << p1.name << endl;
	cout << p1.age << endl;
	ifs.close();
}*/
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

	/*案例2
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
	拷贝构造函数与调用
	test01();
	test02();*/

	/*4.2.3拷贝函数的调用时机
	test01();
	test03();
	test05();*/

	//test01();


	//test01();
	//cout << person::age << endl;
	/*4.3.1成员变量和成员函数分开存储
	person p;
	cout << sizeof(p);*/

//test01();
//test01();
//test01();

   //test01();
 //test();
  //test01();
 //test01();
test01();

	return 0;

}
