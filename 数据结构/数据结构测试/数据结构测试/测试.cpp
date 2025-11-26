//#include <iostream>
//using namespace std;
//int MaxSubseqSum01(int List[], int n)
//{
//    int ThisSum = 0; int MaxThisSum = 0;
//    for (int i = 0; i <= n-1; i++)
//    {
//        for (int j = 0; j <= n-1; j++)
//        {
//            ThisSum = 0;
//            for (int k = i; k <= j; k++)
//            {
//                ThisSum += List[k];
//                if (ThisSum > MaxThisSum)
//                    MaxThisSum = ThisSum;
//                
//            }
//        }
//    }
//    return MaxThisSum;
//}
//int main()
//{
//    int K;
//    cin >> K;
//    int *List=new int[K];
//    for (int i = 0; i < K; i++)
//        cin >> List[i];
//    cout << MaxSubseqSum01(List, K);
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Polynomial
//{
//public:
//    int coef;
//    int expon;
//    Polynomial(int coef, int expon)
//    {
//        this->coef = coef;
//        this->expon = expon;
//
//    }
//};
//void AddPolynomial()
//{
//    int coef = 0;
//    int expon = 0;
//}
//void MulPolynomial()
//{
//}
//void test01()
//{
//    int num = 0;
//    cout << "请输入第一个多项式非零项的个数" << endl;
//    cin >> num;
//    vector<Polynomial> PolynomialVector01;
//    for (int i = 0; i < num; i++)
//    {
//        int coef = 0; int expon = 0;
//        cout << "请输入第" << i + 1 << "项的系数和指数" << endl;
//        cin >> coef >> expon;
//        PolynomialVector01.push_back(Polynomial(coef, expon));
//    }
//    cout << "请输入第二个多项式非零项的个数" << endl;
//    cin >> num;
//        vector<Polynomial> PolynomialVctor02;
//    for (int i = 0; i < num; i++)
//    {
//        int coef = 0; int expon = 0;
//        cout << "请输入第" << i + 1 << "项的系数和指数" << endl;
//        cin >> coef >> expon;
//        PolynomialVctor02.push_back(Polynomial(coef, expon));
//    }
//}
//int main()
//{
//    test01();
//    return 0;
//}
//
//#include <vector>
//#include <map>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//class Polynomial
//{
//public:
//	int coef;
//	int expon;
//	Polynomial(int a, int b) :coef(a), expon(b) {}
//};
//vector<Polynomial> readPoly(int coef = 0, int expon = 0)
//{
//	int n;
//	cout << "请输入第一个多项式非零项的个数" << endl;
//	cin >> n;
//	map<int, int>m1;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "请输入系数和指数" << endl;
//		cin >> coef >> expon;
//		m1[expon] += coef;
//	}
//	vector<Polynomial>v1;
//	for (auto it = m1.rbegin(); it != m1.rend(); it++)
//	{
//		if (it->second != 0)
//		{
//			v1.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return v1;
//}
//vector<Polynomial> AddPolynomial(vector<Polynomial>& p1, vector<Polynomial>& p2)
//{
//	map<int, int> m1;
//	for (const auto& term : p1)
//	{
//		m1[term.expon] = term.coef;
//	}
//	for (const auto& term : p2)
//	{
//		m1[term.expon] += term.coef;
//	}
//	vector<int, int> result;
//	for (auto it = m1.rbegin(); it != m1.rend(); it++)
//	{
//		if (it->second != 0)
//		{
//
//		}
//	}
//}
//
//int main()
//{
//	vector<Polynomial> p1 = readPoly();
//	vector<Polynomial> p2 = readPoly();
//
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int BinarySearch(int arr[], int n, int target)
//{
//	int left = 0; int right = n - 1;
//	int mid;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] == target)
//		{
//			return mid;
//		}
//		else if (target > arr[mid])
//			left = mid + 1;
//		else
//			right = mid - 1;
//	}
//	return -1;
//}
//void test01()
//{
//	int arr[] = { 3,43,5,1,7,4,8,9,2,23,4 };
//	int n = sizeof(arr) / sizeof(int);
//	sort(arr,arr+n);
//	int y = 0;
//	cout << "你要找几?" << endl;
//	cin >> y;
//	int res = BinarySearch(arr, n, y);
//	if (res == -1)
//		cout << "没找到" << endl;
//	else
//		cout << "找到了元素" <<y<< endl;
//}
//int main()
//{
//	test01();
//	return 0;
//	binary_search()
//}
typedef struct TNode* Position;
typedef Position BinTree;
/* 二叉树类型 */
struct TNode
{ /* 树结点定义 */int Data;
/* 结点数据 */BinTree Left;
/* 指向左子树 */BinTree Right;
/* 指向右子树 */
};
int main()
{
	return 0;

}