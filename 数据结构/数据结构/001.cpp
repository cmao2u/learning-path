//#include <iostream>
//#include <time.h>
//using namespace std;
///*
//void printN(int N)
//{
//	for(int i=1;i<N;i++)
//	{
//		cout << i << endl;
//	}
//}
//void printn(int N)
//{
//	if (N) {
//		printn(N - 1);
//			cout << N << endl;
//	}
//}*/
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

/*Maximum Subsequence Sum Problem
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
int func04(int List[],int n)
{
	int ThisSum = 0; int MaxSum = 0;
		for (int i = 0;i <= n; i++)
		{
			ThisSum += List[i];
			if(ThisSum>MaxSum)
				MaxSum = ThisSum;
			else if (ThisSum < 0)
				ThisSum = 0;

		}
		return MaxSum;
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
void test04()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func04(A, n) << endl
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
	
	{
		function02(n, a, x);
	}
	 finish = clock();
	double duration02 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function02 时间: " << duration02 << "s" << endl;
	cout << function02(n, a, x) << endl;*/
	/*Maximum Subsequence Sum Problem
	/test01();
	test02();
	test03();
	test04();*/
//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//// 多项式项类
//class Polynomial {
//public:
//	int coef;  // 系数
//	int expon; // 指数
//	Polynomial(int c, int e) : coef(c), expon(e) {}
//};
//
//// 读取多项式（静默读取，按指数降序返回）
//vector<Polynomial> readPoly() {
//	int n;
//	cin >> n;
//	map<int, int> polyMap; // 用map自动按指数升序存储，合并同类项
//	for (int i = 0; i < n; i++) {
//		int c, e;
//		cin >> c >> e;
//		polyMap[e] += c; // 自动合并同类项（输入可能有重复指数，题目虽未说但需兼容）
//	} 
//	// 转换为vector，按指数降序排列
//	vector<Polynomial> poly;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) { // 系数不为0才加入
//			poly.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return poly;
//}
//
//// 多项式加法（用map实现，自动合并同类项）
//vector<Polynomial> addPoly(const vector<Polynomial>& p1, const vector<Polynomial>& p2) {
//	map<int, int> polyMap;
//	// 加入p1的项
//	for (const auto& term : p1) {
//		polyMap[term.expon] += term.coef;
//	}
//	// 加入p2的项，自动合并同类项    
//	for (const auto& term : p2) {
//		polyMap[term.expon] += term.coef;
//	}
//	// 转换为vector，按指数降序
//	vector<Polynomial> result;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) {
//			result.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return result;
//}
//
//// 多项式乘法（用map实现，自动合并同类项）
//vector<Polynomial> mulPoly(const vector<Polynomial>& p1, const vector<Polynomial>& p2) {
//	map<int, int> polyMap;
//	// 遍历p1和p2的所有项，计算乘积并存入map
//	for (const auto& term1 : p1) {
//		for (const auto& term2 : p2) {
//			int new_e = term1.expon + term2.expon; // 指数相加
//			int new_c = term1.coef * term2.coef;   // 系数相乘
//			polyMap[new_e] += new_c;               // 自动合并同类项
//		}
//	}
//	// 转换为vector，按指数降序
//	vector<Polynomial> result;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) { // 系数不为0才加入
//			result.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return result;
//}
//
//// 打印多项式（严格按题目格式：无多余空格，零多项式输出0 0）
//void printPoly(const vector<Polynomial>& poly) {
//	if (poly.empty()) {
//		cout << "0 0";
//	}
//	else {
//		for (size_t i = 0; i < poly.size(); i++) {
//			if (i > 0) {
//				cout << " ";
//			}
//			cout << poly[i].coef << " " << poly[i].expon;
//		}
//	}
//	cout << endl;
//}
//
//int main() {
//	// 读取两个多项式（无交互式提示，兼容样例批量输入）
//	vector<Polynomial> p1 = readPoly();
//	vector<Polynomial> p2 = readPoly();
//
//	// 计算乘积和和
//	vector<Polynomial> product = mulPoly(p1, p2);
//	vector<Polynomial> sum_poly = addPoly(p1, p2);
//
//	// 输出结果（先乘积，后和，符合题目要求）
//	printPoly(product);
//	printPoly(sum_poly);
//
//	return 0;
//}
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
class Polynomial
{
public:
	int coef;
	int expon;
	Polynomial(int a, int b) :coef(a), expon(b) {}
};
vector<Polynomial> readPoly(int coef = 0, int expon = 0)
{
	int n;
	cout << "请输入第一个多项式非零项的个数" << endl;
	cin >> n;
	map<int, int>m1;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入系数和指数" << endl;
		cin >> coef >> expon;
		m1[expon] += coef;
	}
	vector<Polynomial>v1;
	for (auto it = m1.rbegin(); it != m1.rend(); it++)
	{
		if (it->second != 0)
		{
			v1.push_back(Polynomial(it->second, it->first));
		}
	}
	return v1;
}
vector<Polynomial> AddPolynomial(vector<Polynomial>& p1, vector<Polynomial>& p2)
{
	map<int, int> m1;
	for (const auto& term : p1)
	{
		m1[term.expon] = term.coef;
	}
	for (const auto& term : p2)
	{
		m1[term.expon] += term.coef;
	}
	vector<int, int> result;
	for (auto it = m1.rbegin(); it != m1.rend(); it++)
	{
		if (it->second != 0)
		{

		}
	}
}

int main()
{
	vector<Polynomial> p1 = readPoly();
	vector<Polynomial> p2 = readPoly();

}