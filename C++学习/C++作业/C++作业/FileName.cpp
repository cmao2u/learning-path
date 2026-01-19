//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class Point
//{
//public:
//    int x;
//    int y;
//    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
//};
//
//class Line
//{
//public:
//    Point p1;
//    Point p2;
//    Line(const Point& a, const Point& b) : p1(a), p2(b) {}
//    double Length() const
//    {
//        return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
//    }
//};
//
//int main()
//{
//    Point p1(1, 2);
//    Point p2(4, 6);
//    Line l(p1, p2);
//    double len = l.Length();
//    cout << "线段的长度为:" << len << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	char s[10];
//	int i = 2;
//	cout << *(s + i);
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//class Tri
//{
//	double a, b, c;
//public:
//	Tri(double x, double y, double z)
//	{
//		a = x; b = y; c = z;
//	}
//	double Peri()
//	{
//		return(a + b + c);
//	}
//	double Area()
//	{
//		double p = Peri() / 2;
//		return(sqrt(p * (p - a) * (p - b) * (p - c)));
//	}
//	void show()
//	{
//		cout << "三边长为:" << a << "," << b << "," << c << endl;
//		cout << "周长为:" << Peri() << endl;
//		cout << "面积为:" << Area() << endl;
//	}
//};
//int main()
//{
//	Tri tri1(3, 4, 5), tri2(5, 6, 7);
//	tri1.show();
//	tri2.show();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class NUM {
//private:
//	int n;
//	int* p;
//public:
//	NUM(int n1)
//	{
//		n = n1;
//		p = new int[n];      //A
//	}
//	int yes(int x)
//	{
//		for (int i = 2; i <= x / 2; i++)
//			if (x % i == 0)
//				return 1;
//		return 0;
//	}
//	void fun()
//	{
//		int j;
//		for (int i = 3; 1; i++)
//		{
//			j = 0;
//			while (yes(i) == 0 && j < n)//B
//			{
//				p[j] = i;
//				j++;
//				i++;
//			}
//			if (j == n)
//				break;
//		}
//	}
//	void print()
//	{
//		for (int i = 0; i < n; i++)
//			cout << p[i] << " ";
//		cout << endl;
//	}
//	~NUM()
//	{
//		if (p)delete[] p;
//	}
//};
//int main()
//{
//	NUM num(10);
//	num.fun();//C
//	num.print();//D
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class STR
//{
//private:
//	char *s1;
//	char *s2;
//public:
//	STR(char* str)
//	{
//      int len = strlen(str);
//	  s1 = new char[len + 1];
//	  strcpy_s(s1, len + 1, str);
//	  s2 = nullptr; 
//	}
//	void delsame()
//	{
//		bool IsExist[256] = { false };
//		char result[1000] = { 0 };
//		int index = 0;
//		for (int i = 0; i < strlen(s1); i++)
//		{
//			if (IsExist[s1[i] - '\0'] != true)
//			{
//				IsExist[s1[i] - '\0'] = true;
//				result[index++] = s1[i];
//			}
//		}
//		result[index] = '\0';
//		s2 = new char[strlen(result) + 1];
//		strcpy_s(s2, strlen(result) + 1, result);
//	}
//	void show()
//	{
//		cout << "原字符串为:" << s1 << endl;
//		cout << "去重后的字符串为:" << s2 << endl;
//	}
//	~STR()
//	{
//		delete []s1;
//		delete []s2;
//	}
//};
//int main()
//{
//	char str1[100];
//	cout << "请输入字符串" << endl;
//	cin.getline(str1, 100);
//	STR s1(str1);
//	s1.delsame();
//	s1.show();
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//class WORD
//{
//	char* p;
//	char a[100][20];
//	int n;
//	char maxword[20];
//public:
//	WORD(char* str)
//	{
//		p = new char[strlen(str) + 1];
//		strcpy_s(p, strlen(str) + 1, str);
//	}
//	int alph(char c)
//	{
//				if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//			return 1;
//		else
//					return 0;
//	}
//	void fun()
//	{
//		int i, j, k, maxlength = 0;
//		j = 0;
//		for (i = 0; *(p + i) != '\0'; i++)
//		{
//			for(k=0;alph(*(p+i));k++,i++)
//				a[j][k] = *(p + i);
//			if (k > 0)
//			{
//				a[j][k] = '\0';
//				if (k > maxlength)
//				{
//					strcpy_s(maxword, strlen(a[j]) + 1, a[j]);
//					maxlength = k;
//				}
//				j++;
//				i--;
//			}
//		}
//		n = j;
//	}
//	void print()
//	{
//		cout << "测试字符串" << p << endl;
//		cout << "输出各个单词" << endl;
//		for (int i = 0; i < n; i++)
//			cout << a[i] << endl;
//		cout << "最长的单词是:" << maxword << '\t' << "长度是" << strlen(maxword) << endl;
//
//	}
//	~WORD()
//	{
//		if(p)
//		delete[] p;
//	}
//};
//int main()
//{
//	char str1[100];
//	cout << "请输入字符串" << endl;
//	cin.getline(str1, 100);
//	WORD w1(str1);
//	w1.fun();
//	w1.print();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class NUM
//{
//	int n, count;
//	int* p;
//public:
//	NUM(int num)
//	{
//		n = num;
//		p = new int[n + 1];
//		for (int i = 1; i <= n; i++)
//			*(p + i) = 0;
//		count = n;
//	}
//	int d(int num)
//	{
//		int t = num;
//		while (num)
//		{
//			t = t + num % 10;
//			num /= 10;
//		}
//		return t;
//	}
//	void fun()
//	{
//		int t;
//		for (int i = 1; i <= n; i++)
//		{
//			t = d(i);
//			if (t <= n && p[t] == 0)
//			{
//				p[t] = 1;
//				count = count - 1;
//			}
//		}
//	}
//	void print()
//	{
//		cout << "不大于" << n << "的自身数有" << count << "个:'\n'";
//		for (int i = 1; i <= n; i++)
//		{
//			if (p[i] == 0)
//			{
//				cout << i << '\t';
//			}
//		}
//	}
//	~NUM()
//	{
//		if (p) delete[] p;
//	}
//};
//int main()
//{
//	int x;
//	cout << "请输入一个正整数:";
//	cin >> x;
//	NUM num(x);
//	num.fun();
//	num.print();
//	return 0;
//}
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	GCD(b, a % b);        //递归实现
}
int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}
//int main()
//{
//	cout << "请输入两个正整数:" << endl;
//	int a, b;
//	cin >> a >> b;
//	cout << "最大公约数为:" << GCD(a, b) << endl;
//	cout << "最小公倍数为:" << LCM(a, b) << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int factorialSum(int n)
//{
//	int Sum = 0;
//	int fact = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		fact = fact * i;
//		Sum = Sum + fact;
//	}
//	return Sum;
//}
//int main()
//{
//	int n;
//	cout << "请输入一个正整数:" << endl;
//	cin >> n;
//	cout << n << "的阶乘和为:" << factorialSum(n) << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//bool IsPrime(int n)
//{
//	for (int i = 2; i < n / 2; i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int num = 0;
//	for (int i = 100; i <= 200; i++)
//	{
//		if (IsPrime(i))
//		{
//			cout << i << " ";
//			num++;
//			if (num % 5 == 0)
//				cout << endl;
//		}
//	}
//	return 0;
//}
//#include <iostream>
//#include <ctime>
//using namespace std;
//void SelectSort(int arr[], int n)
//{
//	for (int i = 0; i < n-1; i++)
//	{
//		int minIndex = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if(arr[j]<arr[minIndex])
//				minIndex = j;
//		}
//		if (minIndex != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[minIndex];
//			arr[minIndex] = temp;
//		}
//	}
//}
//int main()
//{
//	srand(time(0));
//	int arr[20];
//	for(int i=0;i<20;i++)
//	{
//		arr[i] = rand() % 90 + 10;
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl << "排序后:";
//	SelectSort(arr, 20);
//	for (int i = 0; i < 20; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//void BubbleSort(int arr[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//		for (int j = 0; j < size - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = temp;
//			}
//		}
//}
//int main()
//{
//	cout << "请输入10个整数" << endl;
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> arr[i];
//	}
//	int size = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, size);
//	cout << "排序后的整数是" << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int fun(char str[])
//{
//	int result = 0;
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		result = result * 10 + (str[i] - '0');
//	}
//	return result;
//}
//int main()
//{
//	char str[100];
//	cout << "请输入一个数字字符串:" << endl;
//	cin >> str;
//	int num = fun(str);
//	cout << "转换后的整数为:" << num << endl;
//	return 0;
//}
//#include <iostream>
//int sum1(int n)
//{
//	int current_sum = 0;
//	int current_val = 2;
//	for (int i = 0; i < n; i++)
//	{
//		current_sum += current_val;
//		current_val = current_val * 10 + 2;
//	}
//	return current_sum;
//}
//int main()
//{
//	int n;
//	std::cout << "请输入项数n:" << std::endl;
//	std::cin >> n;
//	int result = sum1(n);
//	std::cout << "前" << n << "项和为:" << result << std::endl;
//	return 0;
//}
//#include <iostream>
//void judge(char* str)
//{
//	int length = strlen(str);
//	char* p = str + length-1;
//	for (int i = 0; i < length / 2; i++)
//	{
//		if (*(str + i) != *(p - i))
//		{
//			std::cout << "NO" << std::endl;
//			return;
//		}
//	}
//	std::cout << "YES" << std::endl;
//	return;
//}
//int main()
//{
//	char str[100];
//	std::cout << "请输入一个字符串:" << std::endl;
//	std::cin.getline(str, 1000);
//	judge(str);
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//double fun(double x)
//{
//    double y = 0;
//    double term = x; 
//    int sign = 1;     
//    int n = 1;         
//
//    while (fabs(term) > 1e-5)
//    {
//        y += sign * term;
//        term = term * x * x / ((n + 1) * (n + 2));
//        sign = -sign;
//        n += 2;
//    }
//    return y;
//}
//int main()
//{
//	double x;
//	cout << "请输入一个实数:" << endl;
//	cin >> x;
//	double result = fun(x);
//	cout << "计算结果为:" << result << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int fun1(int m)
//{
//	if(m==2)
//		return 1;
//	for (int i = 2; i < m / 2; i++)
//		if (m % i == 0)
//			return 0;
//	return 1;
//}
//void fun2(int n)
//{
//	for (int i = 2; i <= n / 2; i++)
//	{
//		if(fun1(i)&&fun1(n-i))
//			cout << n << "=" << i << "+" << n - i << endl;
//	}
//}
//int main()
//{
//	int n;
//	cout << "请输入一个不小于6的偶数:" << endl;
//	cin >> n;
//	fun2(n);
//	return 0;
//}
//#include <iostream>
//#include <cmath>
//using namespace std;
//class Ctriangle
//{
//    double m_a;
//    double m_b;
//    double m_c;
//public:
//    Ctriangle(double a, double b, double c)
//    {
//        m_a = a;
//        m_b = b;
//        m_c = c;
//    }
//    double GetPerimeter()
//    {
//        return m_a + m_b + m_c;
//    }
//    double GetArea()
//    {
//        double p = (m_a + m_b + m_c) / 2;
//        return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
//    }
//    void display()
//    {
//        cout << "三角形的三边长为:" << m_a << " " << m_b << " " << m_c << endl;
//        cout << "三角形的周长是" << GetPerimeter() << endl;
//        cout << "三角形面积是" << GetArea() << endl;
//    }
//};
//int main()
//{
//    double a, b, c;
//    cout << "请输入三边长" << endl;
//    cin >> a >> b >> c;
//    Ctriangle Tri(a, b, c);
//    Tri.display();
//    return 0;
//}
//#include <iostream>
//using namespace std;
//class cycle
//{
//	double m_radius;
//public:
//	cycle(double r)
//	{
//		this->m_radius = r;
//	}
//	double area()
//	{
//		return 3.14 * m_radius * m_radius;
//	}
//	void show()
//	{
//		cout << "半径为:" << m_radius << "\t面积为:" << area() << endl;
//	}
//};
//int main()
//{
//	double r;
//	cout << "请输入圆的半径:" << endl;
//	cin >> r;
//	cycle c(r);
//	c.show();
//	returmn 0;1.////
//#include <iostream>
//int main()
//{
//	unsigned char c =256;
//	std::cout << c << std::endl;
//	return 0;
//}
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)//外层循环控制趟数
	{
		for (int j = 0; j < size - i - 1; j++)//内层循环控制每一趟比较的次数
		{
			if (arr[j] < arr[j + 1])//比较相邻的两个元素
			{
				int temp = arr[j + 1];//交换
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void SelectSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int MaxIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if(arr[j]>arr[MaxIndex])
				MaxIndex = j;
		}
		if (MaxIndex != i)
		{
			std::swap(arr[MaxIndex], arr[i]);
		}
	}
}
int IsPrime(int x)
{
	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
			return 0;
	}
		return 1;
	
}
void func(int n)
{
	int s2 = 0;
	int s1 = 1;
	int a[100];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			
			s1 *= j;
		}
			a[i] = s1;
			s1 = 1;
		
	}
	for (int i = 1; i <=n; i++)
	{
		s2 += a[i];
	}
	cout << s2;
}

int func2(int n)
{
	if (n == 1)
		return 1;
	return n * func2(n - 1);
}
void test01()
{
	int n;
	int sum = 0;
	cout << "请输入一个正整数:" << endl;
	cin >> n;
	for (int i = n; i >=1; i--)
	{
		sum += func2(i);
	}
	cout <<"n的阶乘和是"<< sum << endl;
}
void func3(char *s,int arr[])
{
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		arr[i] = s[i] - '0';
	}
}
void juege(char* s)//把指针和数组结合起来，尤其是数组的首地址
{
	int length = strlen(s);
	for (int i = 0; i < length / 2; i++)
	{
		if (s[i] != s[length - 1 - i])
		{
			cout << "NO";
			return ;
		}
	}
	cout << "YES" << endl;
}
void judge2(int n)
{
	int temp = n;
	int s=0;
	while (n)
	{
		s = s *10 +n % 10;
		n = n / 10;
	}
	if (s == temp)
		cout << "是回文数";
	else
		cout << "不是" << endl;
}
void fun2(int n)
{
	
	for (int i = 2; i <= n / 2; i++)
	{
		if ((IsPrime(i)) && (IsPrime(n - i)))
			cout << i << "+" << n - i << "=" << n << endl;

	}
}
int main()
{    
	int n;
	cout << "请输入一个不小于6的偶数" << endl;
	cin >> n;
	fun2(n);
	//char str[100];
	//cout << "请输入一个字符串" << endl;
	//cin.getline(str, 100);
	judge2(12321);
	/*juege(str);*/
	//func3(str, arr);
	//for (int i = 0; str[i] != '\0'; i++)
	//{
	//	cout << arr[i];
	//}

	/*int arr[10] = { 0 };
	std::cout << "请输入10个整数" << std::endl;
	for(int i=0;i<10;i++)
	{
		std::cin >> arr[i];
	}
	SelectSort(arr, 10);
	std::cout << "排序后的整数是" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
	*/
	/*func(5);
	test01();*/
	//srand(time(0));
	//int a = rand() % 90 - 100;
	//cout << a;

}