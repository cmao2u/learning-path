//题 1：从小到大排序输出
//#include <iostream>
//#include <algorithm>
//#include <vector>
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
//	sort(a.begin(), a.end());
//	for (int i : a)
//		cout << i<<" ";
//	return 0;
//}
//输入 n 和 n 个整数，从小到大输出。
//
//题 2：从大到小排序输出
//#include <iostream>
//#include <algorithm>
//#include <vector>
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
//	sort(a.begin(), a.end(),greater<int>());
//	for (int i : a)
//		cout << i << " ";
//	return 0;
//}
//输入 n 和 n 个整数，从大到小输出。
//
//题 3：排序后输出最小值和最大值
//#include <iostream>
//#include <algorithm>
//#include <vector>
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
//	sort(a.begin(), a.end());
//	cout << a[0] << " " << a[n - 1];
//	return 0;
//}
//输入 n 和 n 个整数，排序后输出最小值和最大值。
//
//题 4：输出第 k 小的数
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	cout << a[k - 1];
//	return 0;
//}
//输入 n、k 和 n 个整数，输出第 k 小的数。
//
//题 5：输出中位数
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	cout << a[n / 2];
//	return 0;
//}
//输入 n 和 n 个整数，假设 n 为奇数，输出排序后的中位数。
//
//题 6：把字符串按字典序排序后输出
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	sort(s.begin(), s.end());
//	cout << s;
//	return 0;
//}
//输入一个字符串，把其中字符排序后输出。
//比如输入 dbca，输出 abcd。