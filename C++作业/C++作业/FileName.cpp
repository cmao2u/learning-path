/*#include <iostream>
using namespace std;
int main() {
	int random1 = rand() % 90 + 10;
	int random2 = rand() % 21 - 10;
	cout << "random1��" << random1 << '\n' << "random2��" << random2 << endl;
	return 0;
}*/
/*#include <iostream>
using namespace std;
int main()
{
	int a, b, sum;
	cout << "����������뱻����\n";
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
	cout << "�����뻪���¶�:";
	cin >> f;
	c = 5 * (f - 32) / 9;
	cout << "�����¶�=" << c << endl;
	return 0;
}
#include <iostream>
using namespace std;
#define PI 3.14159
int main()
{
	double r;
	double area;
	cout << "������Բ�İ뾶:" << endl;
	cin >> r;
	area = PI * r * r;
	cout << "Բ�������" << area << endl;
	return 0;
}


#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "���������������߳�:";
	cin >> a >> b >> c;
	double s = a + b + c;
	double area = sqrt((s / 2) * (s / 2 - a) * (s / 2 - b) * (s / 2 - c));
	cout << "�����α߳���:" << s << endl;
	cout << "�����������:" << area << endl;
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
	cout << "������򵥵�����ʽ:\n";
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
		cout << "�������������!\n";
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
	cout << "������һԪ���η���ϵ��a,b,c��ֵ:" << endl;
	cin >> a >> b >> c;
	if ((b * b - 4 * a * c) < 0)
	{
		cout << "��ʵ����";
		return 1;
	}
	else
	{
		double  x1 = ((-b) + (sqrt(b * b - 4 * a * c))) / (2 * a);
		double  x2 = ((-b) - (sqrt(b * b - 4 * a * c))) / (2 * a);
		cout << "�÷��̵�����ʵ���ǣ�" << x1 << '\t' << x2 << endl;
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
	cout << "������򵥵�����ʽ:\n";
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
			cout << "��������Ϊ0" << endl;
			return 1;
		}
		else
		{
			result = a1 / a2;
			break;
		}
	default:
		cout << "�������������!\n";
		flag = 1;
	}
	if (flag == 0)
		cout << a1 << oper << a2 << "=" << result << endl;
	return 0;
}



