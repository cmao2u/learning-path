/*#include <iostream>
using namespace std;
int main() {
	int random1 = rand() % 90 + 10;
	int random2 = rand() % 21 - 10;
	cout << "random1是" << random1 << '\n' << "random2是" << random2 << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main()
{
	int a, b, sum;
	cout << "请输入加数与被加数\n";
	cin >> a >> b;
	sum = a + b;
	cout << "sum=" << sum << endl;

	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	double f, c;
	cout << "请输入华氏温度:";
	cin >> f;
	c = 5 * (f - 32) / 9;
	cout << "摄氏温度=" << c << endl;
	return 0;
}
#include <iostream>
using namespace std;
#define PI 3.14159
int main()
{
	double r;
	double area;
	cout << "请输入圆的半径:" << endl;
	cin >> r;
	area = PI * r * r;
	cout << "圆的面积是" << area << endl;
	return 0;
}


#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "请输入三角形三边长:";
	cin >> a >> b >> c;
	double s = a + b + c;
	double area = sqrt((s / 2) * (s / 2 - a) * (s / 2 - b) * (s / 2 - c));
	cout << "三角形边长是:" << s << endl;
	cout << "三角形面积是:" << area << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	float a, b, c;
	cout << "input a    b   c\n";
	cin >> a >> b >> c;
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		cout << "Not Triangle\n";
	else
		cout << "Trianle\n";
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int year;
	cout << "Input year:";
	cin >> year;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		cout << year << "is a leap year" << endl;
	else
		cout << year << " isn't a leap year" << endl;
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	float a1, a2;
	char oper;
	float result;
	int flag = 0;
	cout << "请输入简单的运算式:\n";
	cin >> a1 >> oper >> a2;
	switch (oper)
	{
	case '+':
		result = a1 + a2;
		break;
	case '-':
		result = a1 - a2;
		break;
	case'*':
		result = a1 * a2;
		break;
	default:
		cout << "输入错误的运算符!\n";
		flag = 1;
	}
	if (flag == 0)
		cout << a1 << oper << a2 << "=" << result << endl;
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "请输入一元二次方程系数a,b,c的值:" << endl;
	cin >> a >> b >> c;
	if ((b * b - 4 * a * c) < 0)
	{
		cout << "无实根！";
		return 1;
	}
	else
	{
		double  x1 = ((-b) + (sqrt(b * b - 4 * a * c))) / (2 * a);
		double  x2 = ((-b) - (sqrt(b * b - 4 * a * c))) / (2 * a);
		cout << "该方程的两个实根是：" << x1 << '\t' << x2 << endl;
	}
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	float a1, a2;
	char oper;
	float result;
	int flag = 0;
	cout << "请输入简单的运算式:\n";
	cin >> a1 >> oper >> a2;
	switch (oper)
	{
	case '+':
		result = a1 + a2;
		break;
	case '-':
		result = a1 - a2;
		break;
	case'*':
		result = a1 * a2;
		break;
	case'/':
		if (a2 == 0)
		{
			cout << "除数不能为0" << endl;
			return 1;
		}
		else
		{
			result = a1 / a2;
			break;
		}
	default:
		cout << "输入错误的运算符!\n";
		flag = 1;
	}
	if (flag == 0)
		cout << a1 << oper << a2 << "=" << result << endl;
	return 0;
}*/
/*
#include <iostream>
using namespace std;
int main()
{
	double x, y;
	cout << "请输入x的值" << endl;
	cin >> x;
	if (x >= -5 && x <= 5)
	{
		y = x - 1;
	}
	else if (x > 5 && x <= 10)
	{
		y = x + 1;
	}
	else
	{
		y = 15.6;
	}
	cout << "y的值是" << y << endl;
	return 0;

}*/
/*
#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	double a, x1, x2;
	cout << "请输入a的值" << endl;
	cin >> a;
	x2 = a / 2;
	do {
		x1 = x2;
		x2 = 0.5 * (x1 + a / x1);
	} while (fabs(x2 - x1) >=1e-5);
	cout << "近似值是" << x2 << endl;
	return 0;
	
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	double salary,tax;
	cout << "请输入收入" << endl;
	cin >> salary;
	if (salary < 0)
	{
		cout << "错误" << endl;
	}
	else if (salary <= 800)
		cout << "您无需交税" << endl;
	else if (salary > 800 && salary <= 1200)
	{
		tax = (salary - 800) * 0.05;
	}
	else if (salary > 1200 && salary <= 2000)
	{
		tax = (1200 - 800) * 0.05 + (salary - 1200) * 0.08;
	}
	else 
	{
		tax = (1200 - 800) * 0.05 + (200 - 1200) * 0.08 + (salary - 2000) * 0.2;
	}
	cout << "您要交税" << tax << "元" << endl;
	return 0;

}
*//*
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入一行字符" << endl;
	char ch;
	int digital=0, letter=0, other=0;
	while ((ch = cin.get()) != '\n')
	{
		if (int(ch) >= 48 && int(ch) <= 57)
		{
			digital++;
		}
		else if ((int(ch) >= 65 && int(ch) <= 90) || (int(ch) >= 97 && int(ch) <= 122))
			letter++;
		else
			other++;
	}
	cout << "数字个数为" << digital<< endl;
	cout << "字母个数为" << letter<< endl;
	cout << "其它个数为" << other<< endl;
	return 0;

}
*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x, y;
//	for (x = 1; x < 30; x++)
//		for (y = 1; y < 30; y++)
//			if (2 * x + 4 * y == 90 && x + y == 30)
//			{
//				cout << "鸡有:" << x << '\t' << "兔有:" << y << endl;
//			}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a0, a1, a2;
//	int b;
//	for (a2 = 1; a2 <= 9; a2++)
//		for (a1 = 0; a1 <= 9; a1++)
//			for (a0 = 0; a0 <= 9; a0++)
//			{
//				b = a2 * 100 + a1 * 10 + a0;
//				if (b == a0 * a0 * a0 + a1 * a1 * a1 + a2 * a2 * a2)
//					cout << b << endl;
//			}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a0, a1, a2;
//	int b;
//	for (b = 100; b <= 999; b++)
//	{
//		a2 = b / 100;
//		a1 = b / 10 % 10;
//		a0 = b % 10;
//		if (b == a0 * a0 * a0 + a1 * a1 * a1 + a2 * a2 * a2)
//			cout << b << '\t';
//	}
//	cout << endl;
//	return 0;

//#include <iostream>
//using namespace std;
//int main()
//{
//	for (int i = 1; i < 600; i++)
//		if (i % 3 == 0 && (i % 10 == 5 || i / 10 % 10 == 5 || i / 100 == 5))
//		{
//			cout << i << '\t';
//		}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	int b;
//	int sum = 0;
//	cout << "请输入一个整数" << endl;
//	cin >> a;
//	while (a)
//	{
//		b = a % 10;
//		sum += b;
//		a = a / 10;
//	}
//	cout << "该整数的各位数字之和是" << sum << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b;
//	int t, x;
//	cout << "请输入两个正整数";
//	cin >> a >> b;
//	x = a * b;
//	if (a < b)
//	{
//		t = a, a = b, b = t;
//	}
//	if (t = a % b)
//	{
//		a = b;
//		b = t;
//	}
//	cout << "最大公约数为" << b << endl;
//	cout << "最小公倍数为" << x / b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c, i;
//	cout << "Input three number;";
//	cin >> a >> b >> c;
//	for (i = a; i <= a; i--)
//		if (a % i == 0 && b % i == 0 && c % i == 0)
//			break;
//	cout << i << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, i;
//	cout << "请输入一个正整数:";
//	cin >> a;
//	for (i = 2; i <= a / 2; i++)
//	{
//		if (a % i == 0)
//		{
//			cout << a << "不是素数" << endl;
//			break;
//		}
//		if (i == a / 2)
//			cout << a << "是素数" << endl;
//	}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int IsPrime(int a)
//{
//	for (int i = 2; i <= a / 2; i++)
//	{
//		if (a % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (IsPrime(i))
//			cout << i << '\t';
//	}
//	return 0;
////}
//#include <iostream>
//using namespace std;
//int IsNumber(int a)
//{
//	int sum = 0;
//	for (int i = 1; i < a; i++)
//	{
//		if (a % i == 0)
//			sum += i;
//	}
//	if (sum == a)
//		return 1;
//	return 0;
//}
//int main()
//{
//	for (int i = 1; i <= 1000; i++)
//	{
//		if (IsNumber(i))
//			cout << i << '\t';
//	}
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//int area(int a,int b,int c)
//{
//	int s = (a + b + c) / 2;
//	return sqrt(s * (s - a) * (s - b) * (s - c));
//}
//int main()
//{
//	int a = 0; int b = 0; int c = 0;
//	cout << "请输入三角形三边长" << endl;
//	cin >> a >> b >> c;
//	cout << "三角形面积是" << area(a, b, c) << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int symm(long n)
//{
//	int s = 0;
//	int temp = n;
//	while (n)
//	{
//		s = s * 10 + n % 10;
//		n /= 10;
//	}
//	if (s == temp)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	for (int m = 11; m< 1000; m++)
//	{
//		if (symm(m) && symm(m * m) && symm(m * m * m))
//			cout << m << '\t';
//	}
//}
/*#include <iostream>
using namespace std;
int Fibonnaci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n > 2)
	{
		return Fibonnaci(n - 1) + Fibonnaci(n - 2);
	}
	
}
int main()
{
	int n = 0;
	cout << "请输入要输出的项数" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		
		cout << Fibonnaci(i) << '\t';
		if (i % 5 == 0)
			cout << endl;
	}
	return 0;
}*///复习
/*
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "请输入三个整数" << endl;
	cin >> a >> b >> c;
	cout << "最大值是" << MAX(MAX(a, b), c) << endl;
	cout << "最小值是" << MIN(MIN(a, b), c) << endl;
	return 0;
}*/
/*
#include <iostream>
using namespace std;
int main()
{
	int t = 2;
	int s = 0;
	for (int i = 1; i <= 7; i++)
	{
		s += t;
		t = t * 10 + 2;
	}
	cout << "2+22+222+...+2222222=" << s << endl;
	return 0;
}*/
/*
#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	double x;
	cout << "请输入x的值" << endl;
	cin >> x;
	double y, y2;
	y = x;
	do {
		y2 = y;
		y = 2 * y / 3 + x / (3 * y * y);
	} while (fabs(y2 - y) >= 1e-5);
	cout << "x的立方根是" << y << endl;

	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	cout << "Input n,x:" << endl;
	double n, x, y;
	cin >> n >> x;
	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		double temp = 1;
		y = 1;
		for (int j = 1; j <= 2 * i - 1; j++)
		{

			y *= x;
			temp *= j;
		}
		y /= temp;
		if (i % 2 == 1)
		{
			sum += y;
		}
		else
		{
			sum -= y;
		}
	}
	cout << "值是" << sum << endl;
	return 0;
}*/

/*
#include <iostream>	
using namespace std;
int main()
{
	float y = 1, t = 1;
	int n;
	cout << "Input n:" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		t = t * i;
		y = y + t;
	}
	cout << "1+1!+2!+...+" << n << "!=" << y << endl;
	return 0;

}*/
//#include <iostream>
//using namespace std;
//float fun(float x)
//{
//	float y;
//	y = 2 * x * x + 5 * x + 3;
//	return y;
//}
//int main()
//{
//	float y1, y2;
//	y1 = fun(1.0);
//	y2 = fun(1.2);
//	cout << "y1=" << y1 << endl;
//	cout << "y2=" << y2 << endl;
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//double f(double x)
//{
//	float y;
//	y = x * x + 3 * x - 4;
//	return y;
//}
//double df(double x)
//{
//	float y;
//	y = 2 * x + 3;
//	return y;
//}
//int main()
//{
//	float x1, x0;
//	x1 = 0;
//	do
//	{
//		x0 = x1;
//		x1 = x0 - f(x0) / df(x0);
//	} while (f(x1) > 1e-5);
//	cout << "x=" << x1 << endl;
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//float f(float x)
//{
//	return x * x + 3 * x - 4;
//}
//int main()
//{
//	float x1, x2, x0;
//	do
//	{
//		cout << "请输入初值x1和x2:" << endl;
//		cin >> x1 >> x2;
//	} while ((f(x1) * f(x2)) > 0);
//	do {
//		x0 = (x1 + x2) / 2;
//		if ((f(x0) * f(x1)) > 0)
//			x1 = x0;
//		else
//			x2 = x0;
//	} while (fabs(f(x0)) > 1e-5);
//	cout << "x0=" << x0 << endl;
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//double f(double x)
//{
//	return x * x + 3 * x - 4;
//}
//double dx(double x)
//{
//	return 2 * x + 3;
//}
//void recursion(double x0)
//{
//	if (fabs(f(x0)) < 1e-5)
//	{
//		cout << "x0=" << x0 << endl;
//		return;
//	}
//	double x1 = x0 - f(x0) / dx(x0);
//	recursion(x1);
//}
//int main()
//{
//	double x0 = 2;
//	recursion(x0);
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//double f(double x)
//{
//	return x * x + 3 * x - 4;
//}
//double dx(double x)
//{
//	return 2 * x + 3;
//}
//void recursion(double x0)
//{
//	if (fabs(f(x0)) < 1e-5)
//	{
//		cout << "x0=" << x0 << endl;
//		return;
//	}
//	double x1 = x0 - f(x0) / dx(x0);
//	recursion(x1);
//}
//int main()
//{
//	double x0 = 2;
//	recursion(x0);
//	return 0;
////}
//#include <iostream>
//using namespace std;
//int prime(int x)
//{
//	for (int i = 2; i < x; i++)
//		if (x & i == 0)
//			return 0;
//	return 1;
//}
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (prime(i) == 1)
//			cout << i << '\t';
//	}
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//int IsPrime(int num)
//{
//	for (int i = 2; i < num; i++)
//		if (num % i == 0)
//			return 0;
//	return 1;
//}
//int main()
//{
//	int n;
//	cout << "请输入一个整数:" << endl;
//	cin >> n;
//	for (int i = 2; i <= n / 2; i++)
//	{
//		if (n % i == 0 && IsPrime(i))
//			cout << i << '\t';
//	}
//	cout << endl;
//	return 0;
//}
//+
#include <iostream>
using namespace std;
int fun(int num)
{
	int mul = 1;
	while (num)
	{
		mul *= num % 10;
		num /= 10;
	}
	return mul;
}
int main()
{
	int n, mul;
	cout << "请输入一个整数(输入0结束):" << endl;
	cin >> n;
	while (n)
	{
		mul = fun(n);
		cout << n << "各位数之积为" << mul << endl;
		cout << "请输入一个整数(输入0结束)";
		cin >> n;
	}
	return 0;
}
