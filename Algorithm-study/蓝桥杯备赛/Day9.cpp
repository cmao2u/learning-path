//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Seg {
//	int l, r; 
//};
//bool cmp(Seg a, Seg b)
//{
//	return a.r < b.r;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Seg> seg(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> seg[i].l >> seg[i].r;
//	}
//	sort(seg.begin(), seg.end(), cmp);
//	int cnt = 0;
//	int last_end = -1e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (seg[i].l >= last_end)
//		{
//			cnt++;
//			last_end = seg[i].r;
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//题 1：给一组数，从小到大排序后，依次选取不重复元素输出
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
//	int last_val = -1e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > last_val)
//		{
//			cout << a[i]<<" ";
//			last_val = a[i];
//		}
//	}
//	return 0;
//}
//这题很简单，主要是热身，让你适应“排序后处理”。
//
//题 2：选择尽量多的不重叠区间
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Seg
//{
//	int l, r;
//};
//bool cmp(Seg a, Seg b)
//{
//	return a.r < b.r;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Seg> seg(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> seg[i].l >> seg[i].r;
//	}
//	sort(seg.begin(), seg.end(), cmp);
//	int cnt = 0;
//	int last_end = -1e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (seg[i].l >= last_end)
//		{
//			cnt++;
//			last_end = seg[i].r;
//		}
//	}
//	cout << cnt;
//	return 0;
//}
//这是今天最重要的一题。
//
//题3
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>need(n);
//	vector<int> res(m);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> need[i];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cin >> res[i];
//	}
//	sort(need.begin(), need.end());
//	sort(res.begin(), res.end());
//	int i = 0, j = 0, cnt = 0;
//	while (i < n && j < m)
//	{
//		if (need[i] <= res[j])
//		{
//			cnt++;
//			i++;
//			j++;
//		}
//		else
//		{
//			j++;
//		}
//
//	}
//	cout << cnt;
//	return 0;
//
//}
//也就是刚才“需求 / 资源匹配”这个模型。
//
//题 4：给若干数，求最少分组数，使每组和不超过某个值（基础版）
//
//这题有一点贪心味，但先做简单数据版。
//
//题 5：把若干任务按结束时间排序，问最多能完成多少个
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Seg
//{
//	int l, r;
//};
//bool cmp(Seg a,Seg b)
//{
//	return a.r < b.r;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Seg> seg(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> seg[i].l >> seg[i].r;
//	}
//	sort(seg.begin(), seg.end(), cmp);
//	int cnt = 0;
//	int last_end = -1e9;
//	for (int i = 0; i < n; i++)
//	{
//		if (seg[i].l >= last_end)
//		{
//			cnt++;
//			last_end = seg[i].r;
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//本质和区间贪心很像，是巩固题。