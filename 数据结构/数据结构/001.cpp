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
/*关于算法效率
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
}*/


int func01(int A[], int n)
{
	
	int MaxSum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ThisSum = 0;
			for (int k = i; k < j; k++)
			{
				ThisSum += A[k];	
			}
			if (ThisSum > MaxSum)
			MaxSum = ThisSum;
			
		}
	}
	return MaxSum; 
}
int func02(int A[],int n)
{
	int MaxSum = 0;
	for (int i = 0; i < n; i++)
	{
		int ThisSum = 0;
		for (int j = i; j < n; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
				
			
	}
	return MaxSum;
}
int Max3(int a, int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}
int MaxSubseqSum(int List[], int  left, int right)
{
	int center, MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	center = (left + right) / 2;
	if (left == right)
	{
		return List[left] > 0 ? List[left] : 0;
	}
	MaxLeftSum = MaxSubseqSum(List, left, center);
	MaxRightSum = MaxSubseqSum(List, center + 1, right);
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	RightBorderSum = 0; MaxRightBorderSum = 0;
	for (int i = center + 1; i <= right; i++)
	{
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int func03(int List[],int n)
{
	return MaxSubseqSum(List, 0, n - 1);
}


void test01()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func01(A, n) << endl;
}
void test02()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func02(A, n) << endl;
}
void test03()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func03(A, n) << endl;
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

	/*
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
	cout << function02(n, a, x) << endl;*/
	test01();
	test02();
	test03();


return 0;
}