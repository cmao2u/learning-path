//pre[i] 是 前 i 个数的和
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n), pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + a[i];
//	for (int i = 0; i < n + 1; i++)
//		cout << "pre[" << i << "]" << "=" << pre[i] << '\n';
//	return 0;
//}
//题 1：输出前缀和数组
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + a[i];
//	for (int i = 0; i < n + 1; i++)
//		cout << "pre[" << i << "]=" << pre[i] << '\n';
//	return 0;
//}
//输入 n 和 n 个整数，输出 pre[0] ~pre[n]
//
//这题是入门，必须会。
//
//题 2：单次区间和查询
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + a[i];
//	int l, r;
//	cin >> l >> r;
//	int sum = pre[r + 1] - pre[l];
//	cout << "区间[l, r] 的和="<< sum << endl;
//	return 0;
//}
//输入 n 和 n 个整数，再输入 l, r，输出区间[l, r] 的和。
//
//这题练公式。
//
//题 3：多次区间和查询
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + a[i];
//	int q;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
		//int l, r;
		//cin >> l >> r;
		//int sum = pre[r + 1] - pre[l];
//		cout << "第" << i + 1 << "个区间和是" << sum << '\n';   注意，调试的时候可以清晰，但是OJ可能会误判文字
//	}
//	return 0;
//}
//输入 n 和数组，再输入 q 次查询，每次给 l, r，输出每次区间和。
//
//这题是前缀和最标准的应用场景。
//
//题 4：统计区间内偶数个数
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> b(n);
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] % 2 == 0)
//			b[i] = 1;
//		else
//			b[i] = 0;
//	}
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + b[i];
//	int q;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		int cnt = pre[r + 1] - pre[l];
//		cout << cnt;
//	}
//	return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int q;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		int cnt = 0;
//		for (int j = l; j < r+1; j++)
//		{
//			if (a[j] % 2 == 0)
//				cnt++;
//		}
//		cout << cnt<<'\n';
//	}
//}
//输入数组后，再做多次查询，每次问[l, r] 中有多少个偶数。
//
//提示：
//
//先把数组转成 0 / 1
//
//偶数记成 1
//
//再做前缀和
//
//这个题很重要，因为它说明前缀和不只会算“和”，还会算“数量”。
//一个很直观的比喻

//你第二种写法像这样：
//
//每次有人问“第 20 页到第 80 页一共有多少个偶数”，
//你都重新翻一遍第 20 到 80 页。
//
//前缀和像这样：
//
//我先把“前 1 页有多少个偶数、前 2 页有多少个偶数、前 3 页有多少个偶数……”全记下来。
//以后别人一问，我直接查表相减。
//
//所以前缀和的本质是：
//
//空间换时间，预处理换快速查询。
//题 5：统计区间内正数个数
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> b(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > 0)
//			b[i] = 1;
//		else
//			b[i] = 0;
//	}
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//	{
//		pre[i + 1] = pre[i] + b[i];
//	}
//	int q;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		int cnt = pre[r + 1] - pre[l];
//		cout << cnt << '\n';
//	}
//	return 0;
//}
//和上一题一样，只是统计大于 0 的个数。
//
//题 6：用前缀和做“最大区间和”的暴力优化版
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	vector<int> pre(n + 1, 0);
//	for (int i = 0; i < n; i++)
//		pre[i + 1] = pre[i] + a[i];
//	int max_sum = a[0];
//	for (int l = 0; l < n + 1; l++)
//	{
//		for (int r = l; r < n; r++)
//		{
//			int sum = pre[r + 1] - pre[l];
//			if (sum > max_sum)
//				max_sum = sum;
//		}
//	}
//	cout << max_sum;
//	return 0;
//}
//昨天你是三层味道地去做区间和。
//今天你可以这样：
//
//枚举左端点 l
//
//枚举右端点 r
//
//用前缀和 O(1) 算[l, r] 的和
//
//这样虽然还是 O(n²)，但已经比原来“每次重新累加”强很多。