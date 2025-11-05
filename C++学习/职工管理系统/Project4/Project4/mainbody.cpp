//这是cpp提高阶段
#include<iostream>
using namespace std;
/*1.2 函数模板
template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;

}*/

void SelectSort(int List[],int n)
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

int main()
{
	/*1.2 函数模板
	double a = 19.2;
	double b = 30.2;
	myswap<double>(a, b);
	cout << "a是" << a << endl << "b是" << b << endl;*/
	int A[] = { 1,5,3,8,5,9,3 };
	int n = sizeof(A) / sizeof(A[0]);
	SelectSort(A,n);
	for (int i = 0; i < n; i++)
		cout << A[i];

	return 0;
}
int n = sizeof(List) / sizeof(List[0]);