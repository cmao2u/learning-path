//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	int x;
//	cin >> n;
//	cin >> x;
//	int ans = -1;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	int l = 0;
//	int r = n - 1;
//	while (l <= r)
//	{
//		int mid = (l + (r - 1)) / 2;
//		if (a[mid] <= x)
//		{
//			if (a[mid] == x)
//				ans = x;
//			l = mid + 1;
//		}
//		if (a[mid] > x)
//			r = mid - 1;
//	}
//	cout << ans;
//	return 0;
//}
//题 1：判断某个数是否存在
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	int x;
//	cin >> x;
//	int l = 0;
//	int r = n - 1;
//	while (l <= r)
//	{
//		int mid = (l + (r)) / 2;
//		if (a[mid] <= x)
//		{
//			if (a[mid] == x)
//			{
//				cout << "yes";
//				return 0;
//			}
//			l = mid + 1;
//		}
//		else
//		{
//			r = mid - 1;
//		}
//	}
//	cout << "no";
//	return 0;
//}
//输入一个升序数组和 x，输出 yes 或 no
//
//题 2：输出某个数的位置
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//  sort(a,begin(),a.end())
//	int ans = -1;
//	int l = 0;
//	int r = n - 1;
//	int x;
//	cin >> x;
//	while (l <= r)
//	{
//		int mid = (l + (r)) / 2;
//		if (a[mid] <= x)
//		{
//			if (a[mid] == x)
//			{
//				ans = mid;
//				cout << ans;
//				return 0;
//			}
//			l = mid + 1;
//		}
//		else
//			r = mid - 1;
//	}
//	cout << ans;
//	return 0;
//}
//如果存在，输出任意一个位置；不存在输出 - 1
//
//题 3：输出某个数第一次出现的位置
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	int l = 0, r = n - 1;
//	int x;
//	cin >> x;
//	int ans = -1;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (a[mid] >= x)
//		{
//			if (a[mid] == x)
//				ans = mid;
//			r = mid - 1;
//		}
//		else
//			l = mid + 1;
//	}
//	cout << ans;
//	return 0;
//
//}
//数组可能有重复元素
//
//题 4：输出某个数最后一次出现的位置
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	int l = 0, r = n - 1;
//	int x;
//	cin >> x;
//	int ans = -1;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (a[mid] <= x)
//		{
//			if (a[mid] == x)
//				ans = mid;
//			l = mid + 1;
//		}
//		else
//			r = mid - 1;
//	}
//	cout << ans;
//	return 0;
//
//}
//数组可能有重复元素
//
//题 5：输出第一个大于等于 x 的位置
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	sort(a.begin(), a.end());
//	int l = 0, r = n - 1;
//	int x;
//	cin >> x;
//	int ans = -1;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (a[mid] >= x)
//		{
//			ans = mid;
//			r = mid - 1;
//		}
//		else
//			l = mid + 1;
//	}
//	cout << ans;
//	return 0;
//}
//如果不存在输出 - 1
//
//题 6：先排序，再查询
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int x;
//	cin >> x;
//	sort(a.begin(), a.end());
//	int l = 0, r = n - 1;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (a[mid] <= x)
//		{
//			if (a[mid] == x)
//			{
//				cout << "yes";
//				return 0;
//			}
//			l = mid + 1;
//		}
//		else
//			r = mid - 1;
//	}
//	cout << "no";
//	return 0;
//}
//输入一个无序数组和 x，先排序，再判断 x 是否存在
//
//这题很重要，因为它把你前三天的 sort 和今天的二分连起来了。