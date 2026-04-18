//题 1：模板题
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> parent;
//int find(int x)
//{
//	if (parent[x] == x)return x;
//	return parent[x] = find(parent[x]);
//}
//void merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx != ry)
//		parent[rx] = ry;
//}
//bool same(int x, int y)
//{
//	return find(x) == find(y);
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	parent.resize(n+1);
//	for (int i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		merge(x, y);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cout << find(i) << " ";
//	}
//	return 0;
//}
//输入 n, m 和 m 条边，把所有边合并后，输出每个点的根节点。
//
//题 2：判断两点是否连通
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> parent;
//int find(int x)
//{
//	if (parent[x] == x)return x;
//	return parent[x] = find(parent[x]);
//}
//void merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx != ry)
//		parent[rx] = ry;
//}
//bool same(int x, int y)
//{
//	return(find(x) == find(y));
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	parent.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//		parent[i] = i;
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		merge(x, y);
//	}
//	int search_n;
//	cin >> search_n;
//	for (int i = 0; i < search_n; i++)
//	{
//		int x; int y;
//		cin >> x >> y;
//		if (same(x, y))cout << "yes" << '\n';
//		else cout << "no" << '\n';
//	}
//	return 0;
//}
//输入若干边，再输入若干查询(x, y)，输出它们是否连通。
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> parent;
//int find(int x)
//{
//	if (parent[x] == x)return x;
//	return parent[x] = find(parent[x]);
//}
//void merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx != ry)
//		parent[rx] = ry;
//}
//bool same(int x, int y)
//{
//	return find(x) == find(y);
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	parent.resize(n + 1);
//	int cnt = n;
//	for (int i = 1; i <= n; i++)
//		parent[i] = i;
//	for (int i = 0; i < m; i++)
//	{
//		int x; int y;
//		cin >> x >> y;
//		if (!same(x, y))
//		{
//			merge(x, y);
//			cnt--;
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//题 3：统计连通块个数
//
//输入无向图的边，输出最终连通块数。
//
//题 4：判断加边是否形成环
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> parent;
//int find(int x)
//{
//	if (parent[x] == x)return x;
//	return parent[x] = find(parent[x]);
//}
//void merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx != ry)
//		parent[rx] = ry;
//}
//bool same(int x, int y)
//{
//	return (find(x) == find(y));
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	parent.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//		parent[i] = i;
//	for (int i = 0; i < m; i++)
//	{
//		int x; int y;
//		cin >> x >> y;
//		if (same(x,y))
//		{
//			cout << "yes" << '\n';
//			merge(x, y);
//		}
//		else
//		{
//			cout << "no" << '\n';
//			merge(x, y);
//		}
//	}
//	return 0;
//}

//如果一条边的两个端点本来就在同一集合，那么加这条边就形成环。
//
//这题非常经典。