#include <iostream>
using namespace std;	
#include <string>
#include<ctime>
#include "swap1.h"
#include "swap2.h"
#include"BubbleSort.h"	
#include "PrintArray.h"	
void test01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void test02(int* a, int* b)
{
	int temp = *a;
	* a = *b;
	*b = temp;
}
void test03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*堆区
int* func()
{
	int* p = new int(10);
	return p;
}*/
/*栈区
int * func()
{
	int a = 10;
	return &a;
}*/
/*全局区
int a = 10;
int b = 20;
const int g = 20;
const int h = 20;*/
/*
struct Hero {
	string name;
	int age ;
	string sex;
};

void bubblesort(Hero arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j].age > arr[j + 1].age) {
				Hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printInfo(Hero arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "姓名是" << arr[i].name << "\t年龄是" << arr[i].age << "\t性别是" <<arr[i].sex<< endl;
	}
}*/


/*成绩生成
struct Student {
	string name;
	int score;
};
struct Teacher {
	string name;
	struct Student Sarray[5];
};

void allocatespace(Teacher Tarray[], int len) {
	string nameSeed = "ABCDE";
	
	for (int i = 0; i < len; i++) {
		Tarray[i].name = "Teacher_";
		Tarray[i].name += nameSeed[i];
		for (int j = 0; j < 5; j++) {
			int random = rand() % 61 + 40;
			Tarray[i].Sarray[j].name = "Student_";
			Tarray[i].Sarray[j].name += nameSeed[j];
			Tarray[i].Sarray[j].score = random;
		}
	}
}
void printInfo(Teacher Tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "老师的姓名是:" << Tarray[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t学生的姓名是:" << Tarray[i].Sarray[j].name << "  成绩是:" << Tarray[i].Sarray[j].score << endl;
		}
	}
}

*/



		


/*嵌套结构体与结构体指针	与const
struct student {
	string name;
	int age;
	int score;
};




struct Student {
	string name;
	int age;
	int score;
};

struct Teacher {
	int number;
	int age;
	string name;
	struct Student stu1;
	struct Student stu2;	
};


void printstudent1(struct Student stu) {
	stu.age = 28;
	cout << "子函数中 姓名是" << stu.name << "\t年龄是" << stu.age << "\t成绩是" << stu.score << endl;
}
void printstudent2(struct Student* stu) {
	stu->age = 30;
	cout << "子函数中 姓名是" << stu->name << "\t年龄是" << stu->age << "\t成绩是" << stu->score << endl;
}

void stuinfor(const struct student *stu) {	
	cout << "姓名是" << stu->name << "\t年龄是" << stu->age << "\t成绩是" << stu->score << endl;	
}*/

//#define day 7 宏常量定义
	int main(){
	/*1.1变量
	int a = 18;

		cout<< "橙猫猫今年的年龄是" << a << endl;
		*/
		/*1.2常量
		*constint day = 7; //const定义常量
		//int day = 16; //错误，常量不能被修改
		cout << "一周有" << day << "天" << endl;

		*/
		/*二.数据类型
		2.1整型
		short num1 = 10;
		int num2 = 10;
		long num3 = 10;
		long long num4 = 10;
		cout << "num1是" << num1 << endl;
		cout << "num2是" << num2 << endl;
		cout << "num3是" << num3 << endl;
		cout << "num4是" << num4 << endl;
		*/
		/* 2.2sizeof关键字
	用于看内存大小
	short num1 = 10;
	cout << "num1所占的内存空间是" << sizeof(num1) << endl;
	long long num2 = 29;
	cout << "num2所占的空间是" << sizeof(num2) << endl;*/
	/*2.3实型
	float money1 = 80.29f;
	double money2 = 98.62;
	double sum = money1 + money2;
	cout << "还剩" << sum << "块" << endl;
	cout << "float所占的内存是" << sizeof(money1) << endl;
	cout << "double所占的内存是" << sizeof(money2) << endl;*/
	/*2.3.2科学计数法
	float num1 = 3e3;//3*10^3
	cout << "num1等于" << num1 << endl;
	float num2 = 3e-4;
	cout << "num等于" << num2 << endl;*/
	/*2.4字符型
	char ch1 = 'a';
	cout << ch1 << endl;
	cout << sizeof(char) << endl;
	查询ASCII码
	cout << int(ch1) << endl;*/
	/*2.5转义字符
	cout << "书名：《C++入门》\n作者：张三\n价格：59.9元\n备注：推荐阅读章节：\"第一章\",\"第三章\""<<endl;
	cout << "学号\t姓名\t成绩" << endl;
	cout << "001\t小明\t92" << endl;
	cout << "002\t小红\t98" << endl;*/
	/*2.6字符串型
	string str1 = "hello world";
	cout << str1 << endl;
	char str2[] = "hello world";
	cout << str2 << endl;*/

	/*2.7bool型
	bool flag = true;
	cout << flag << endl;
	flag = false;
	cout << flag << endl;
	cout << sizeof(flag) << endl;*/

	/*2.8数据输入
	cout << "请输入a的值" << endl;
	int a = 0;
	cin >> a;//<<插入运算符>>提取运算符
	cout << "a的值为" << a << endl;

	char f[] = " hello world";
	cin >> f;
	cout << "橙猫猫想对你说" << f << endl;*/

	/*3.1运算符
	float a1 = 1.2f;
	float a2 = 0.6f;
	cout << a1 / a2 << endl;*/

	/*取模
	int b1 = 10;
	int b2 = 20;
	cout << b1 % b2 << endl;//小数不能取模运算*/

	/*3.2自增自减
	int a = 10;
	int b = a++ * 10;
	cout << b << endl;
	cout << b<< endl;

	int c = 10;
	int d = 10;
	cout << c++ * d << endl;//先用后加，此时c=11
	cout << ++c * d << endl;//先加后用*/

	/*3.3逻辑运算符
	int a = 3; int b = 4;
	cout << a == b << endl///<<的运算符优先级高于==，解析为（cout<<a)==b<<endl;

	cout << (3 != 4) << endl;
	cout << (3 <= 2) << endl;*/
	/*
	int a = 10; int c = 0;
	int b = 10;
	cout << !a << endl;     //非——取反
	cout << (a && b )<< endl;     //与——同时为真才为真
	cout << (a || c) << endl;   */  //或——只需有一个为真就为真

	/*程序流程结构
	* 4.1顺序结构
	int score = 85;
	cout << "请输入您的成绩:" << endl;
	cin >> score;
	if (score > 90) {
		cout << "你做的非常棒" << endl;
	}
	else if (score > 80 && score < 90) {
		cout << "你做的还不错" << endl;
	}
	else if (score > 70 && score < 80) {
		cout << "你需要加油" << endl;
	}
	else {
		cout << "你需要努力学习哦" << endl;}*/

		/*嵌套if语句
		cout << "请输入一个整数" << endl;
		int num = 0;
		cin >> num;
		if (num >= 100 && num <= 999) {
			cout << "你输入的是一个三位数" << endl;
			if ((num % 10) == (num / 10 % 10)) {
				cout << "并且这个三位数的个位和十位相等" << endl;
			}
		}
			else {
				cout << "这不是一个三位数" << endl;
			}*/
			/*小猪比体重
				int a = 0;
				int b = 0;
				int c = 0;
				cout << "请输入小猪a的体重:" << endl;
				cin >> a;
				cout << "请输入小猪b的体重:" << endl;
				cin >> b;
				cout << "请输入小猪c的体重:" << endl;
				cin >> c;
				if (a > b && b > c) {
					cout << "小猪a最重" << endl;
				}
				if (a > c && c > b) {
					cout << "小猪a最重" << endl;
				}
				if (b > a && a > c) {
					cout << "小猪b最重" << endl;
				}
				if (b > c && c > a) {
					cout << "小猪b最重" << endl;
				}
				if (c > a && a > b) {
					cout << "小猪b最重" << endl;
				}
				if (c > b && b > a) {
					cout << "小猪b最重" << endl;
				}*/

				/*
				int a = 0;
				int b = 0;
				int c = 0;
				cout << "请输入小猪a的体重:" << endl;
				cin >> a;
				cout << "请输入小猪b的体重:" << endl;
				cin >> b;
				cout << "请输入小猪c的体重:" << endl;
				cin >> c;
				if (a > b) {
					if (a > c) { cout << "小猪a最重"<<endl; }
					else { cout << "小猪c最重" << endl; }
				}
				else {
					if (b > c) { cout << "小猪b最重" << endl; }
					else { cout << "小猪c最重"<< endl; }
				}
				*/

				/*4.1.2三目运算符
				int a = 10;
				int b = 93;
				int c;
				c = (a > b ? a : b);
				cout << "c是" << c << endl;

				//用于赋值
				(a > b ? a : b) = 5;
				cout << "a是" << a << endl << "b是" << b << endl << "c是" << c << endl;*/

				/*4.1分支结构
				int month;
				cout << "请输入月份:" << endl;
				cin >> month;
				switch (month) {
				case 3:
				case 4:
				case 5:
					cout << "春天到了呢" << endl;
					break;
				case 6:
				case 7:
				case 8:
					cout << "夏天来了" << endl;
					break;
				case 9:
				case 10:
				case 11:
					cout << "秋天来了" << endl;
					break;
				case 12:
				case 1:
				case 2:
					cout << "冬天到了" << endl;
					break;
				default:
					cout << "错误！请输入1-12月份中任意一个！" << endl;
						break;
				}*/


				/*4.2while循环
				int num = 0;
				while (num < 10) {
					cout << num << endl;
					num++;
				}*/


				/*猜数字
				srand(time(0));//设置随机数种子
				int num = rand() % 100;
				cout << "请猜一个数字" << endl;
				int val=0;
				while (val != num) {
				cin >> val;
					if (val < num) { cout << "你猜的有点小了"<<endl;}
					if (val > num) { cout << "你猜的有点大了" << endl; }
				}
				cout << "恭喜你猜对了" << endl;*/

				/*do while语句
				int num = 0;
				do {
					cout << num << endl;
					num++;
				} while (num < 10);*/

				/*失败
				int num = 100;
				do {
				int a = num / 100;
				int b = num / 10 % 10;
				int c = num % 10;
				int sum = a * a * a + b * b * b + c * c * c;
				num++;
				} while (num<1000);
				if (num ==sum) { cout << "下一个水仙花数是" << num << endl; };
				num++;*/

				/*水仙花数
				int num = 100;
				do{
					int a = num / 100;
					int b = num / 10 % 10;
					int c = num % 10;
					int sum = a * a * a + b * b * b + c * c * c;
					if (sum == num) { cout << "下一个水仙花数是" << num << endl; };
					num++;
				} while (num < 1000);*/
				/*4.3for循环敲桌子小游戏
				for (int i = 1; i <= 100; i++) {
					if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7) {
						cout << "过" << endl;
					}
					else {
						cout << i << endl;
					}
				}*/
				/*4.4嵌套循环
			for (int i = 1; i < 10; i++){
				for (int j = 1; j < 10; j++){
					cout << "*" << "\t";

				}
				cout << endl;
			}
			*/
			/*乘法表
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= i; j++) {
					cout << j << "*" << i << "=" << i * j << "\t";
				}
				cout << endl;
			}	*/

			/*
			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= i; j++) {
					cout << j << "*" << i << "=" << i * j << "\t";
				}
				cout << endl;
			}*/

			/*break语句
			int num = 1;
			int sum=0;
			while (sum < 50) {
				sum += num;
				num++;
					if (sum > 50) {
						cout << "最后一次是" << num-1 << endl;
						cout << "sum是" << sum << endl;

					}

			}*/

			/*continue语句（已经过逻辑优化）
			int num = 1;
			while (num <= 20) {
				if (num % 4 == 0) { num++; continue; }
				if (num % 3 == 0) {
					cout << "3的倍数" << num << endl;
					num++;
				}
				else {
					cout << num << endl;
					num++;
				}



			}*/

			/*goto 语句
				int num = 1;
			FLAG:
				cout << "请输入密码" << endl;
				string password;
				cin >> password;
				if (num < 3) {
				if (password == "123456") {
					cout << "密码正确，欢迎使用本系统" << endl;
					return 0;
				}

				else {
					cout << "密码错误，请重新输入" << endl;
					num++;
					goto FLAG;

				}
			}
				else{
					cout << "密码错误次数过多，账号已锁定，请联系管理员" << endl;
				}

				*/



				/*五.数组
				5.1一维数组的定义
				int sum = 0;
				int arr1[] = { 5,2,9,1,7,3 };
				int minVal = arr1[0];
				for (int i = 0; i < 6; i++) {
					cout << arr1[i] << endl;
					sum += arr1[i];
					if (arr1[i] < minVal) {
						minVal = arr1[i];
					}
						}
					cout << "sum是" << sum << endl;
					cout << "数组中的最小值是" << minVal << endl;	*/

					/*5.2数组名
					int arr1[] = { 1,3,6,8,0,3 };
					cout << "arr1的地址是" << int(arr1)<< endl;
					cout << "arr1[0]的地址是" << int( & arr1[0]) << endl;
					cout << "arr1[1]的地址是" <<int( & arr1[1]) << endl;
					cout << "arr1的内存是" << sizeof(arr1) << endl;
					cout << "arr1的元素个数是" << sizeof(arr1) / sizeof(arr1)[0] << endl;*/

					/*小猪称体重
					int arr1[5] = { 300,350,200,400,250 };
					int maxVal = arr1[0];
					for (int i = 0; i < 5; i++) {
						if (arr1[i] > maxVal) {
							maxVal = arr1[i];
						}
					}
					cout << "最重的小猪体重是" << maxVal << endl;	*/

					/*数组倒序算法
					int arr1[5] = { 1,5,2,8,4 };
					for (int I = 0; I < 5; I++) {
						cout << "数组arr1的元素是" << arr1[I] << "\t";
					}

					int start = 0;
					int end = sizeof(arr1) / sizeof(arr1[0]) - 1;
					long temp = 0;
					while (start < end) {
						temp = arr1[start];
						arr1 [start]= arr1[end];
						arr1[end] = temp;
							start++;
							end--;


					}
					for(int j=0;j<5;j++){
						cout << "数组arr1的元素是" <<arr1[j] << "\t";
					}*/

					/***********冒泡序列
						int arr1[] = { 0,3,8,2,9,5,4,7,6 ,1 };
						int temp;
						for (int i = 0; i < 9; i++) {
							for (int j = 0; j < 10 - i - 1; j++) {
								if (arr1[j] > arr1[j + 1]) {
									temp = arr1[j];
									arr1[j] = arr1[j + 1];
									arr1[j + 1] = temp;
								}
							}
						}
						cout << "排序后的数组是" << endl;
						for (int k = 0; k < 10; k++) {
							cout << arr1[k] << "\t";
						}
					*/



/*二维数组
int arr[2][3] = { { 1,2,3 },{ 4, 5, 6 } };
for (int i = 0; i < 2; i++) {//遍历每一行
	for (int j = 0; j < 3; j++) {//遍历每一列
		cout << arr[i][j] << " ";//“ ”增强可读性
	}cout << endl;//每行进行换行
}*/


/*成绩统计
string names[] = { "张三","李四","王五" };
int arr1[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
	
for (int i = 0; i < 3; i++) {
	int sum = 0;
	for (int j = 0; j < 3; j++) {
		sum += arr1[i][j];
	}cout << names[i]<<"的成绩是" << sum << endl;
}*/

/*函数的定义与调用
int a = 100;
int b = 102;
int c = add(a, b);
cout << c << endl;*/

/*6.5值传递
int a = 10;
int b = 20;
swap(a, b);
cout << a <<" " <<b << endl;*/

/*6.6函数的声明
int c=uiu(a, b);
  cout << "c是" << c << endl;
int a = 12l;
int b = 983;
int c = max(a, b); 
cout << "最大值是" << c << endl;*/

/*7.1指针的定义
int a = 10;
int* p = &a;
cout << "*p是" << *p << endl;	
cout << p << endl;
cout << &a << endl;*/


/*7.2指针的内存大小
int a = 10;
int* p;
p = &a;
cout << "指针所占内存是" << sizeof(int*) << endl;*/

/*7.3空指针
int* p = NULL;*/

/*7.4野指针
int* p = (int*)0x1100;
cout << *p << endl;*/

/*指针和数组
int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
int* p = arr;
cout << "arr第一个元素是" << *p << endl;
cout << "arr中的元素有" << endl;
for (int i = 0; i < 10; i++) {
	cout << *p << endl;
	p++;
}*/

/*函数与指针
int a = 10;
int b = 20;
cout << "开始时a,b,的值分别是" << a << "\t" << b << endl;
swap1(a, b);
cout << "值传递后a,b,的值分别是" << a << "\t" << b << endl;
swap2(&a, &b);
cout << "地址传递后a,b,的值分别是" << a << "\t" << b << endl;*/

/*指针函数与数组
int arr[] = { 6,3,7,0,1,8,2,9,5,4 };
int n = sizeof(arr) / sizeof(arr[1]);
BubbleSort(arr, n);
PrintArray(arr, n);*/


/*8.1结构体
struct Student {
	string name;
	int age;
	int score;
};

struct Student s1 = { "张三",18,97 };
struct Student s2;
s2.name = "李四";
s2.age = 21;
s2.score = 99;
struct Student s3 = { "王五",22,93 };
cout << "姓名是" << s1.name << "年龄是" << s1.age << "分数是" << s1.score << endl;
cout << "姓名是" << s2.name << "年龄是" << s2.age << "分数是" << s2.score << endl;
cout << "姓名是" << s3.name << "年龄是" << s3.age << "分数是" << s3.score << endl;*/


/*结构体数组
struct Student stuarray[] = {
	{"张三",18,100},
{ "李四", 87, 65 },{"王五",54,54} };

for (int i = 0; i < 3; i++) {
	cout << "姓名" << stuarray[i].name << "\t年龄" << stuarray[i].age << "\t分数" << stuarray[i].score << endl;
}*/

/*结构体指针
struct Student s = { "张三",18,198 };
Student* p1 = &s;
p1->score=80;
cout << "姓名" <<p1->name << "\t年龄" << p1->age << "\t分数" << p1->score << endl;*/

/*结构体嵌套结构体
struct Teacher t1;
t1.number = 1000;
t1.age = 43;
t1.name = "李老师";
t1.stu1.age = 18;
t1.stu1.name = "张三";
t1.stu1.score = 99;
t1.stu2.age = 19;
t1.stu2.name = "李四";
t1.stu2.score = 98;
cout << "工号是" << t1.number << "\t姓名是" << t1.name << "\t年龄是" << t1.age << endl;	
cout << "学生1的姓名是" << t1.stu1.name << "\t年龄是" << t1.stu1.age << "\t成绩是" << t1.stu1.score << endl;	
cout << "学生2的姓名是" << t1.stu2.name << "\t年龄是" << t1.stu2.age << "\t成绩是" << t1.stu2.score << endl;	*/


/*结构体的值传递与地址传递
struct Student s1 = { "张三",18,97 };
printstudent1(s1);
cout << "主函数中 姓名是" << s1.name << "\t年龄是" << s1.age << "\t成绩是" << s1.score << endl;	
printstudent2(&s1);	
cout << "主函数中 姓名是" << s1.name << "\t年龄是" << s1.age << "\t成绩是" << s1.score << endl;	*/


/*
student stu = { "张三",18,95 };
stuinfor(&stu);	*/


/*成绩生成系统
srand(time(0));
struct Teacher Tarray[3];	
int len = sizeof(Tarray) / sizeof(Tarray[0]);
allocatespace(Tarray, len);
printInfo(Tarray, len);*/



/*英雄打印
struct Hero arr[5]{
	{"刘备",23,"男" },
	{ "关羽",22,"男" },
	{ "张飞",20,"男" },
	{ "赵云",21,"男" },
	{ "貂蝉",19,"女" } };
printInfo(arr, 5); cout<<endl;
int len = sizeof(arr) / sizeof(arr[0]);	
bubblesort(arr, len);
printInfo(arr, len);*/

/*全局区
int c = 10;
int d = 10;
static int e = 10;
static int f = 10;
const int i = 10;
const int j = 10;
cout << "全局变量a的地址是" << int( & a) << endl;
cout << "全局变量b的地址是" << int( & b) << endl;
cout << "局部变量c的地址是" << int( & c) << endl;
cout << "局部变量d的地址是" << int( & d) << endl;
cout << "静态变量e的地址是" <<int( & e) << endl;
cout << "静态变量f的地址是" << int( & f ) << endl;
cout << "const常量g的地址是" << int( & g) << endl;
cout << "const常量h的地址是" << int( & h) << endl;
cout << "const常量局部i的地址是" << int( & i) << endl;
cout << "const常量局部j的地址是" << int( & j) << endl;
cout << "字符串常量的地址是" << int( & "hello world") << endl;*/

/*1.1栈区
int* p = func();
cout << *p << endl;//悬空指针	
cout << *p << endl;*/


/*
int* p = func();
cout <<* p << endl;
cout << p << endl;
delete p;
cout << *p << endl;
*/


/*new运算符
int* arr = new int[10];
for (int i = 0; i < 10; i++)
{
	arr[i] = i + 100;
}
for (int i = 0; i < 10; i++)
{
	cout << arr[i] << endl;
}
delete[] arr;*/

/*2.1引用的基本使用
int a = 10;
int& b = a; 
cout << "a是" <<a<< endl;
cout << "b是" <<b<< endl;
b = 20;
cout << "a是" <<a<< endl;
cout << "b是" <<b<< endl;*/


/*2.2引用的注意事项
int a = 10;
int& b = a;
int c = 20;
b = c;
cout << a << b << c << endl;*/
/*2.3引用传递
int a = 10;
int b = 20;
test01(a, b);
cout << "test01中a和b为" << a << '\t' << b << endl;
test02(&a, &b);
cout << "test01中a和b为" << a << '\t' << b << endl;
test03(a, b);
cout << "test01中a和b为" << a << '\t' << b << endl;*/












	return 0;

}
