
//int main() 
//{
//	int n;
//	cin >> n;
//	cout << n << endl;
//	return 0;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << a + b << endl;
//	return 0;
//}
//int main()
//{
//	int x;
//	cin >> x;
//	if (x % 2 == 0)
//		cout << "even" << endl;
//	else
//		cout << "odd" << endl;
//	return 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	long long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	cout << sum << endl;
//	return 0;
//}
//#include <vector>
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	long long sum = 0;
//	for (int i = 0;i<n; i++)
//	{
//		cin >> a[i];
//		sum += a[i];
//	}
//	cout << sum << endl;
//	return 0;
//}
//题 4：数组求最大值
//
//输入 n，再输入 n 个整数，输出最大值
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int max_value = a[0];
//	for (int x=1; x<n; x++)
//	{
//		if (a[x] > max_value)
//			max_value = a[x];
//	}
//	cout << max_value << endl;
//}
//题 5：统计正数个数
//
//输入 n，再输入 n 个整数，输出大于 0 的数有几个
//题 6：求所有偶数的和
//
//输入 n，再输入 n 个整数，输出所有偶数的和
//题 7：求最小值
//
//输入 n 和 n 个整数，输出最小值
//题 8：统计偶数个数
//
//输入 n 和 n 个整数，输出偶数有几个
//题 1：数组最小值
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for(int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	int min_value = a[0];
//	for(int i=1;i<n;i++)
//	{
//		if(a[i] < min_value)
//			min_value = a[i];
//	}
//	cout << min_value << endl;
//	return 0;
//}
//输入 n 和 n 个整数，输出最小值。
//
//题 2：统计负数个数
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	int cnt = 0;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if(a[i] < 0)
//			cnt++;
//	}
//	cout << cnt << endl;
//	return 0;
//}
////输入 n 和 n 个整数，输出小于 0 的数有几个。
////
////题 3：统计偶数个数
////
////输入 n 和 n 个整数，输出偶数有几个。
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	int cnt = 0;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] %2== 0)
//			cnt++;
//	}
//	cout << cnt << endl;
//	return 0;
//}
////题 4：求奇数和
////
////输入 n 和 n 个整数，输出所有奇数的和。
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	int sum = 0;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] % 2 == 1)
//			sum+=a[i];
//	}
//	cout << sum << endl;
//	return 0;
//}
////题 5：求数组平均值
////#include<iostream>
////#include<vector>
////using namespace std;
////int main()
////{
////	int n;
////	double sum = 0;
////	double avg = 0;
////	cin >> n;
////	vector<int> a(n);
////	for (int i = 0; i < n; i++)
////	{
////		cin >> a[i];
////	}
////	for (int i = 0; i < n; i++)
////	{
////			sum += a[i];
////	}
////	avg = sum / n;
////	cout << avg << endl;
////	return 0;
////}
////输入 n 和 n 个整数，输出它们的和，再自己想想平均值该怎么表示。
////先不用纠结格式，先把“总和”写对。
////
////题 6：找第一个大于 0 的数
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > 0)
//		{
//			cout << a[i] << endl;
//			return 0;
//		}
//	}
//	cout << -1 << endl;
//	return 0;
//}
//输入 n 和 n 个整数，输出第一个大于 0 的数。
//如果一个都没有，输出 - 1。
