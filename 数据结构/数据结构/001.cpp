#include <iostream>
#include <time.h>
using namespace std;
/*
void printN(int N)
{
	for(int i=1;i<N;i++)
	{
		cout << i << endl;
	}
}
void printn(int N)
{
	if (N) {
		printn(N - 1);
			cout << N << endl;
	}
}*/
/*关于算法效率
clock_t start, finish;
double duration;
double function01(int n, double a[], double x)
{
	double p = a[0];
	for (int i = 1; i <= n; i++)
	{
		p += (a[i] * pow(x, i));
	}
	return p;
}
double function02(int n, double a[], double x)
{
	double p = a[n];
	for (int i = n; i > 0; i--)
	{
		p = (p * x + a[i - 1]);
	}
	return p;
}*/
clock_t start,finish;
double duration;
double function01(int n, double a[], double x)
{
	double p = 1/a[0];
	for (int i = 1; i <= n; i++)
	{
		p += pow(x, i) / a[i];
	}
	return p;
}
double function02(int n, double a[], double x)
{
	double p = 1 / a[n];
	for (int i = n; i > 0; i--)
	{
		p = (p * x + (1 / a[i - 1]));
	}
	return p;
}
int main()
{/*
	//printN(1000);
	printn(10000);
}*/
	/*关于算法效率
	多项式求值
	double a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };// 多项式系数
	int n = 20;  // 多项式最高次数（必须小于数组长度-1）
	double x = 10.0;  // 多项式自变量

	// 重复调用1000000次，放大时间差异
	const int repeat = 1000000;

	// 测试function01
	clock_t start = clock();
	for (int i = 0; i < repeat; i++) {
		function01(n, a, x);
	}
	clock_t finish = clock();
	double duration01 = double(finish - start) / CLOCKS_PER_SEC;  // 用CLOCKS_PER_SEC更标准
	cout << "function01 时间: " << duration01 << "s" << endl;
	cout << function01(n, a, x) << endl;

	// 测试function02
	start = clock();
	for (int i = 0; i < repeat; i++) {
		function02(n, a, x);
	}
	finish = clock();
	double duration02 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function02 时间: " << duration02 << "s" << endl;
	cout << function02(n, a, x) << endl;	*/

	double a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };// 多项式系数
	int n = 20;
	double x = 10.0;
	const int repeat = 1000000;
	clock_t start = clock();
	for (int i = 0; i < repeat; i++)
	{
		function01(n,a,x);
	}
	clock_t finish = clock();
	double duration01 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function01 时间: " << duration01 << "s" << endl;
	cout << function01(n, a, x) << endl;
	 start = clock();
	for (int i = 0; i < repeat; i++)
	{
		function02(n, a, x);
	}
	 finish = clock();
	double duration02 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function02 时间: " << duration02 << "s" << endl;
	cout << function02(n, a, x) << endl;


return 0;
}