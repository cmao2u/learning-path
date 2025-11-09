//这是cpp提高阶段
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*1.2 函数模板
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;

}*/
/*
1.2.3 函数模板案例
案例描述：
利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
排序规则从大到小，排序算法为选择排序
分别利用char数组和int数组进行测试
template<typename T>
void SelectSort( T List[], int n)
{
	int p = 0;
	for (int i = 0; i < n - 1; i++)
	{
		p = i;
		for (int j = i + 1;j<n; j++)
		{
			if (List[j] < List[p])
			{
				p = j;
			}
		}
			if (p != i)
			{
				int temp = List[i];
				List[i] = List[p];
				List[p] = temp;
			}
	}
}
template<typename T>
void PrintArray(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void test01()
{
	int arr[] = { 5,0,7,45,4,3,7,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	PrintArray(arr, n);
	cout << endl;
}
void test02()
{
	double arr[] = { 5.5,0.7,7.4,45.9,4.3,3.6,7.1,1.8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	PrintArray(arr, n);
	cout << endl;
}
void test03()
{
	char arr[] = { 'b','c','a','e','d' };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	PrintArray(arr, n);
	cout << endl;
}*/
/*1.2.4 普通函数与函数模板的区别
template<typename T>
T Add(T a, T b)
{
	return a + b;
}
double Add2(double a, double b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << Add<int>(a, c) << endl;
}
void test02()
{
	double a = 10.5;
	double b = 20.3;
	char c = 'c';
	cout << Add2(a, c) << endl;
}*/
/*1.3.1 类模板语法
template<class typeName,class typeage>
class Person
{
public:
	Person(typeName name, typeage age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->name << " 年龄：" << this->age << endl;
	}

	typeName name;
	typeage age;

};
	void test01()
	{
		Person<string, int> p("张三", 20);
		p.showPerson();
	}*/
/*1.3.4 类模板对象做函数参数
template<class T1,class T2>
class Person
{
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	
};
void printperson(Person<string, int>& p)
{
	cout << "姓名：" << p.name << " 年龄：" << p.age << endl;
}
void test01()
{
	Person<string, int > p("张三", 18);
	printperson(p);
}*/
/*1.3.5 类模板与继承
template <class T1>
class person
{
public:
	T1 m;

};
class son1 :public person <int>
{
};
void test01()
{
	son1 s1;
	s1.m = 10;
	cout << s1.m << endl;
}
template<class T1,class T2>
class son2 :public person<T2>
{
public:
	T1 obj;
	son2()
	{
		cout << "T1类型是" << typeid(T1).name();
		cout << "T2类型是" << typeid(T2).name();
	}
};
void test02()
{
	son2<string, int> s2;
	s2.obj = "你好"; s2.m = 18;
	cout << s2.obj << s2.m << endl;

}*/
/*
template <class T1,class T2>
class person
{
public:
	person(T1 name, T2 age);
	void showinfo();
	T1 m_name;
	T2 m_age;
};
template<class T1,class T2>
person<T1,T2>::person(T1 name, T2 age)
{
	this->m_name = name;
	this->m_age = age;
}
template<class T1,class T2>
void person<T1, T2>::showinfo()
{
	cout << "name:" << this->m_name << endl;
	cout << "age:" << this->m_age << endl;
}
void test01()
{
	person<string, int> p1("tom", 18);
	p1.showinfo();
}*/
/*1.3.8 类模板与友元
template <class T1, class T2> class person;//为了声明showinfo2，由于里面有person不认识所以先声明一下person
template <class T1, class T2>
void showinfo2(person<T1, T2>& p2);//可用1111111111111111111处替换
template <class T1,class T2>
class person
{
public:
	
	person(T1 name, T2 age)
	{
		this->m_age = age;
		this->m_name = name;
	}
private:
	friend void showinfo(person<T1,T2> &p1)
	{
		cout << p1.m_name << p1.m_age << endl;
	}
	friend void showinfo2<>(person<T1, T2>& p2);
private:
	T1 m_name;
	T2 m_age;
};
template<class T1, class T2>
void showinfo2(person<T1, T2>& p2)
{
	cout << p2.m_name << p2.m_age << endl;//11111111111111
}
void test01()
{
	person<string,int> p1("tom",3);
	showinfo(p1);
}
void test02()
{
	person<string, int> p2("jerry",2);
	showinfo2(p2);
}
*/
/*2.5.1 vector存放内置数据类型
void func1(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	/*vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	//for(vector<int>::iterator itBegin=v.begin();itBegin!=v.end();itBegin++)
	//{
	//	cout << *itBegin << endl;
	//}
	for_each(v.begin(), v.end(), func1);
}*/
/*2.5.2 Vector存放自定义数据类型
class person
{
public:
	person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test01()
{
	person p1("aaa", 111);
	person p2("bbb", 222);
	person p3("ccc", 333);
	person p4("ddd", 444);
	person p5("eee", 555);
	person p6("fff", 666);
	vector<person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	for (vector<person>::iterator itBegin=v.begin(); itBegin != v.end(); itBegin++)
	{
		cout << "姓名是:" << itBegin->name;
		cout << "年龄是:" << itBegin->age << endl;
	}
}
void test02()
{
	person p1("aaa", 111);
	person p2("bbb", 222);
	person p3("ccc", 333);
	person p4("ddd", 444);
	person p5("eee", 555);
	person p6("fff", 666);
	vector<person*> v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	v2.push_back(&p6);
	for (vector<person*>::iterator itBegin = v2.begin(); itBegin != v2.end(); itBegin++)
	{
		cout << "姓名是:" << (**itBegin).name << " " << "年龄是:" << (**itBegin).age << endl;
	}
}*/
void test01()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 1; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 4);
		v3.push_back(i + 8);
		v4.push_back(i + 12);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++)
	{
		for (vector<int>::iterator itBegin2 = (*itBegin).begin(); (itBegin2) != (*itBegin).end(); itBegin2++)
		{
			cout << *itBegin2<<'\t';
		}
		cout << endl;
	}

}







int main()
{
	/*1.2 函数模板
	double a = 19.2;
	double b = 30.2;
	myswap<double>(a, b);
	cout << "a是" << a << endl << "b是" << b << endl;*/
	/*test01();
	test02();
	test03();*/
	/*test01();
	test02();*/
	/*test01();*/
	/*test01();
	test02();*/
	/*test01();
	test02();*/
	test01();
	return 0;
}