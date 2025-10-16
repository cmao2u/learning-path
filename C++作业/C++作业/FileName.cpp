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
}



