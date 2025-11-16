//这是cpp提高阶段
#include<iostream>
#include<vector>
#include<algorithm>
#include <deque>
#include <stack>
#include <queue>
#include<list>
#include <set>
#include <map>
#include <functional>
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
/*
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

}*/
/*string容器
void test01()
{
	/*string s1;
	const char* str = "hello，world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(10, 'd');
	cout << "s3=" << s3;*/
	/*
	string str1;
	str1.assign("hello,world");
	cout << str1 << endl;
	string str2;
	str2.assign("hello,c++", 5);
	cout << str2 << endl;
	string str3;
	str3.assign(str2);
	cout << str3;*/
	/*string str1;
	str1 = "I";
	cout << str1 << endl;
	string str2;
	str2 = " love";
	str1 += str2;
	cout << str1 << endl;
	string str3;
	str3 = " coding";
	str1.append(str3);
	cout << str1 << endl;
	string str4 = "啦啦啦啾咪";
	str1.append(str4, 6, 4);
	cout << str1 << endl;*/
	/*string str1;
	str1 = "abcdefgh";
	int res=str1.find("gh");
	cout << res << endl;
	str1.replace(1, 3, "22222");
	cout << str1 << endl;*/
	/*string str1 = "abcde";
	string str2 = "abced";
	int res = str1.compare(str2);
	if (res > 0)
		cout << "相同" << endl;
	if (res < 0)
		cout << "不同" << endl;*/
	/*string str1 = "hello,c++";
	for (int i = 0; i < str1.size(); i++)
		cout << str1.at(i);
	cout << endl;*/
	//string str1 = "soife";
	//str1.insert(1, "222");
	//str1.erase(4, 1);
	//cout << str1 << endl;
	//string str1 = "abedfggg";
	//string str2 = str1.substr(1, 4);
	//cout << str2 << endl;
	/*string str1 = "ggbond@gmail.com";
	int pos = str1.find("@");
	string str2 = str1.substr(0, pos);
	cout << "username:" << str2 << endl;*/
//}
/*3.2.2 vector构造函数
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator itBegin = v.begin(); itBegin < v.end(); itBegin++)
	{
		cout << *itBegin << " ";
	}
	cout << '\n';
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);//默认构造
	vector<int> v2(v1.begin(), v1.end());
	PrintVector(v2);//区间构造
	vector<int> v3(10, 100);
	PrintVector(v3);//n elem构造
	vector<int> v4(v3);
	PrintVector(v4);//拷贝构造
}*/
/*3.2.3 vector赋值操作
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator ItBegin = v.begin(); ItBegin < v.end(); ItBegin++)
	{
		cout << *ItBegin << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	vector<int> v2;
	v2 = v1;//operator=赋值
	PrintVector(v2);
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());//assign区间赋值
	PrintVector(v3);
	vector<int> v4;
	v4.assign(10, 100);//assign——n elem赋值
	PrintVector(v4);
}*/
/*
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator ItBegin = v.begin(); ItBegin < v.end(); ItBegin++)
	{
		cout << *ItBegin << " ";
	}
	cout << endl;
}*/
/*3.2.4 vector容量和大小
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << v1.empty() << endl;;
	cout << "v1的容量是" << v1.capacity() << endl;
	cout << "v1的大小是" << v1.size() << endl;
	v1.resize(18, 8888);
	PrintVector(v1);
}*/
/*3.2.5 vector插入和删除
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	v1.pop_back();
	PrintVector(v1);
	v1.insert(v1.begin(), 100);
	PrintVector(v1);
	v1.insert(v1.begin(), 2, 100);
	PrintVector(v1);
	v1.erase(v1.begin());
	PrintVector(v1);
	v1.clear();
	PrintVector(v1);

}*/
/*3.2.6 vector数据存取
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i);
	}
	cout << '\n';
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}*/
//void test01()
//{
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	vector<int>v2;
//	for (int i = 9; i >= 0; i--)
//	{
//		v2.push_back(i);
//	}
//	PrintVector(v1);
//	PrintVector(v2);
//	v1.swap(v2);
//	PrintVector(v1);
//	PrintVector(v2);
//}
/*3.2.7 vector互换容器
void test01()
{
	vector<int> v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1的容量是" << v1.capacity() << endl;
	cout << "v1的大小是" << v1.size() << endl;
	v1.resize(3);
	cout << "v1的容量是" << v1.capacity() << endl;
	cout << "v1的大小是" << v1.size() << endl;
	vector<int>(v1).swap(v1);
	cout << "v1的容量是" << v1.capacity() << endl;
	cout << "v1的大小是" << v1.size() << endl;
}*///可以用来回收空间
/*3.2.8 vector预留空间
void test01()
{
	int* p = NULL;
	int num = 0;
	vector<int> v1;
	v1.reserve(10000000);
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
		if (p != &v1[0])
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num;
}*/
void PrintDeque(deque<int> &d)
{
	for (deque<int>::iterator ItBegin = d.begin(); ItBegin < d.end(); ItBegin++)
	{
		cout << *ItBegin << " ";
	}
	cout << endl;
}/*
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);
	deque<int> d2;
	d2.assign(5, 100);
	PrintDeque(d2);
	deque<int> d3(d1.begin(), d1.end());
	PrintDeque(d3);
	deque<int> d4(d3);
	PrintDeque(d4);
}*/
/*
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);
	if (d1.empty())
	{
		cout << "容器空" << endl;
	}
	else
		cout << "容器不空" << endl;
	cout << "容器大小为" << d1.size() << endl;
	d1.resize(3);
	PrintDeque(d1);
	cout << "容器大小为 " << d1.size() << endl;
}*/
/*
void test01()
{
	deque<int> d1;
	d1.push_back(10);
	PrintDeque;
	d1.push_front(3);
	PrintDeque(d1);
	d1.pop_front();
	PrintDeque(d1);
	deque<int> d2;
	d2.insert(d2.begin(), d1.begin(), d1.end());
	PrintDeque(d2);

}*/
/*
void test01()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(12);
	d1.push_back(1);
	d1.push_back(43);
	d1.push_back(2);
	PrintDeque(d1);
	sort(d1.begin(), d1.end());
		PrintDeque(d1);
}*/
/*
void test01()
{
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	while (!s1.empty())
	{
		cout << "栈顶是" << s1.top() << endl;
		s1.pop();
	}
	cout << "stack中个数是" << s1.size();
}*/
/*
void test01()
{
	class person
	{
	public:
		string name;
		int age;
		person(string name,int age)
		{
			this->name = name;
			this->age = age;
		}
	};
	person p1("唐僧", 30);
	person p2("孙悟空", 1000);
	person p3("猪八戒", 900);
	person p4("沙僧", 800);
	queue<person> q1;
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	q1.push(p4);
	while (!q1.empty())
	{
		cout << "队头是" << q1.front().name << ",年龄是" << q1.front().age << endl;
		cout << "队尾是" << q1.back().name << ",年龄是" << q1.back().age << endl;
		q1.pop();
	}
}*/
void PrintList(const list<int>& l)
{
	for (list<int>::const_iterator ItBegin = l.begin(); ItBegin != l.end(); ItBegin++)
		cout << *ItBegin << " ";
	cout << endl;
}
/*list构造
void test01()
{
	list<int> l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	PrintList(l1);
	list<int> l2(l1.begin(), l1.end());
	list<int> l3(l2);
	list<int> l4(7, 100);
	PrintList(l2);
	PrintList(l3);
	PrintList(l4);
}*/
/*
void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	PrintList(L1);
	list<int> L2;
	L2.assign(L1.begin(), L1.end());
	L2.pop_back();
	PrintList(L2);
	L2.swap(L1);
	PrintList(L1);
	PrintList(L2);
}*/
/*
void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	while (1)
	{
		if (!L1.empty())
		{
			cout << "L1不为空" << endl;;
			PrintList(L1);
			L1.resize(0);
		}
		else
		{
			cout << "L1为空" << endl;;
			break;
		}
	}
}*/
/*
void test01()
{
	list<int> L1;
	L1.push_back(100);
	L1.push_front(13);
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 123,2);
	PrintList(L1);
	L1.remove(2);
	PrintList(L1);

}*/
/*
void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	cout << "front:" << L1.front() << " back:" << L1.back();
}*/
/*
bool MyCompare(int a, int b)
{
	return a > b;
}
void test01()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(24560);
	L1.push_back(3024);
	L1.push_back(420);
	L1.push_back(50);
	PrintList(L1);
	L1.sort();
	PrintList(L1);
	L1.reverse();
	PrintList(L1);
	L1.sort(MyCompare);
	PrintList(L1);
}*/
void PrintSet(set<int> s)
{
	for (set<int>::iterator ItBegin = s.begin(); ItBegin != s.end(); ItBegin++)
	{
		cout << *ItBegin << " ";
	}
	cout << endl;
}
/*set构造
void test01()
{
	set<int> s;
	s.insert(10);
	s.insert(132);
	s.insert(12);
	s.insert(15);
	s.insert(11);
	PrintSet(s);
	s.insert(11);
	PrintSet(s);
}*/
/*
void test01()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(12);
	s1.insert(13);
	s1.insert(14);
	s1.insert(15);
	s1.insert(15);
	s1.insert(16);
	PrintSet(s1);
	set<int>::iterator pos = s1.find(25);
	if (pos !=s1.end())
	{
		cout << "找到了"<< *pos << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	cout << s1.count(15) << endl;
}*/
/*
void test01()
{
	set<int> s1;
	pair<set<int>::iterator, bool> res = s1.insert(10);
	if (res.second == 1)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
	res = s1.insert(10);
	if (res.second == 1)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}
}*/
/*pair用法
void test01()
{
	pair<string, int > p("Tom", 3);
	cout << "姓名是" << p.first << " 年龄是" << p.second << endl;
}*/


/*
class MyCompare
{
public:
	bool operator()(int a,int b)const
	{
		return a > b;
	}
};
void test01()
{
	set<int,MyCompare> s1;
	s1.insert(10);
	s1.insert(11);
	s1.insert(12);
	s1.insert(13);
	s1.insert(14);
	s1.insert(15);
	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it;
	}
}*/
/*set装其它类
class person
{
public:
	string m_name;
	int m_age;
	person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};
person p1("刘备", 28);
person p2("张飞", 25);
person p3("关羽", 27);
class MyCompare
{
public:
	bool operator()(const person &p1, const person&p2) const
	{
		return p1.m_age > p2.m_age;
	}
};
void test01()
{
	set<person,MyCompare> s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	for (set<person, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名" << it->m_name << "年龄" << it->m_age << endl;
	}
}*/

void PrintMap(const map<int, int> & m)
{ 
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << "   value:" << it->second << endl;;
	}
	cout << endl;
}
/*
void test01()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 12));
	m.insert(pair<int, int>(3, 18));
	m.insert(pair<int, int>(2, 16));
	m.insert(pair<int, int>(4, 10));
	PrintMap(m);
	map<int, int>m3(m);
	PrintMap(m3);
}*/
/*
void test01()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1[2] = 15;
	PrintMap(m1);
	m1[3] = 23;
	m1.insert(pair<int, int>(5, 20));
	PrintMap(m1);
	m1.erase(m1.begin());
	m1.erase(5);
	PrintMap(m1);
	m1.clear();
	PrintMap(m1);
}*/
/*
void test01()
{
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 19));
	m1.insert(pair<int, int>(2, 13));
	m1.insert(pair<int, int>(3, 18));
	m1.insert(pair<int, int>(4, 15));
	m1.insert(pair<int, int>(5, 16));
	PrintMap(m1);
	map<int, int>::iterator res = m1.find(3);
	cout <<"找到了元素,key=" << res->first << "value=" << res->second << endl;
	cout << "出现" << m1.count(3);//////注：：：都是对key进行操作的
}*/
/*
class MyCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void test01()
{
	map<int, int,MyCompare> m1;
	m1.insert(pair<int, int>(1, 15));
	m1.insert(pair<int, int>(2, 16));
	m1.insert(pair<int, int>(3, 10));
	m1.insert(pair<int, int>(4, 11));
	m1.insert(pair<int, int>(5, 17));
	m1.insert(pair<int, int>(6, 18));
	for (map<int, int>::iterator itq = m1.begin(); itq != m1.end(); itq++)
	{
		cout << itq->first <<"   " << itq->second<<"   "<<endl;
	}
}*/
/*
void test01()
{
	negate<int> n;
	cout << n(10) << endl;
	plus<double> p;
	cout << p(24.1, 10.7) << endl;
}*/
/*template<class T> bool equal_to<T> //等于
template<class T> bool not_equal_to<T> //不等于
template<class T> bool greater<T> //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T> //小于
template<class T> bool less_equal<T> //小于等于*/

void PrintVector(const vector<bool>& v)
{
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	PrintVector(v);
	sort(v.begin(), v.end(),greater<int>());
	PrintVector(v);
	
}*/
void test01()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	vector<bool> v2;
	v2.resize(v1.size());
	PrintVector(v1);
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	PrintVector(v2);
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