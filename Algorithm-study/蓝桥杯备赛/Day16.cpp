//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Edge
//{
//	int u, v, w;
//};
//bool cmp(Edge a, Edge b)
//{
//	return a.w < b.w;
//}
//vector<int> parent;
//int find(int x)
//{
//	if (parent[x] == x) return x;
//	return parent[x] = find(parent[x]);
//}
//bool merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx == ry)return false;
//	parent[rx] = ry;
//	return true;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<Edge> edges(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//	}
//	sort(edges.begin(), edges.end(), cmp);
//	parent.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//	}
//	int total_weight = 0;
//	int edge_count = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int u = edges[i].u;
//		int v = edges[i].v;
//		int w = edges[i].w;
//		if (merge(u, v))
//		{
//			total_weight += w;
//			edge_count++;
//		}
//		if (edge_count == n - 1)break;
//	}
//	if (edge_count == n - 1)
//		cout << total_weight << '\n';
//	else
//		cout << -1 << '\n';
//	return 0;
//}
//题 1：输入边，按权值排序后输出
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Edge
//{
//	int u, v, w;
//};
//bool cmp(Edge a,Edge b)
//{
//	return a.w < b.w;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<Edge> edges(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//	}
//	sort(edges.begin(), edges.end(), cmp);
//	for (int i = 0; i < m; i++)
//	{
//		cout << i << ":" << edges[i].u << " " << edges[i].v << " " << edges[i].w << '\n';
//	}
//}
//先把边结构体和排序写熟。
//题 2：Kruskal 模板题
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<int> parent;
//struct Edge
//{
//	int u, v, w;
//};
//bool cmp(Edge a, Edge b)
//{
//	return a.w < b.w;
//}
//int find(int x)
//{
//	if (parent[x] == x) return x;
//	return parent[x] = find(parent[x]);
//}
//bool merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx == ry)return false;
//	parent[rx] = ry;
//	return true;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<Edge> edges(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//	}
//	sort(edges.begin(), edges.end(), cmp);
//	parent.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//	}
//	int total_weight = 0;
//	int count = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int u = edges[i].u;
//		int v = edges[i].v;
//		int w = edges[i].w;
//		if (merge(u, v))
//		{
//			total_weight += w;
//			count++;
//		}
//		if (count == n - 1)
//			break;
//	}
//	if (count == n - 1)
//		cout << total_weight << '\n';
//	else
//		cout << -1 << '\n';
//	return 0;
//}
//输出最小生成树总权值。
//题 3：判断图是否能生成最小生成树
//也就是图是否连通，不连通输出 - 1。
//题 4：输出选中了哪些边
//#include <iostream>
//#include<vector>
//#include <algorithm>
//using namespace std;
//vector<int> parent;
//struct Edge
//{
//	int u, v, w;
//};
//bool cmp(Edge a, Edge b)
//{
//	return a.w < b.w;
//}
//int find(int x)
//{
//	if (parent[x] == x)return x;
//	return parent[x] = find(parent[x]);
//}
//bool merge(int x, int y)
//{
//	int rx = find(x);
//	int ry = find(y);
//	if (rx == ry)return false;
//	parent[rx] = ry;
//	return true;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<pair<int, int>> edge_select(n - 1);
//	vector<Edge> edges(m);
//	for (int i = 0; i < m; i++)
//	{
//		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//	}
//	sort(edges.begin(), edges.end(), cmp);
//	parent.resize(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		parent[i] = i;
//	}
//
//	int total_weight = 0;
//	int edge_count = 0;
//	for (int i = 0; i < m; i++)
//	{
//		int u = edges[i].u;
//		int v = edges[i].v;
//		int w = edges[i].w;
//		if (merge(u, v))
//		{
//			edge_count++;
//			total_weight += w;
//			edge_select[edge_count].first = u;
//			edge_select[edge_count].second = v;
//		}
//		if (edge_count == n - 1)break;
//	}
//	if (edge_count == n - 1)
//	{
//		cout << total_weight << '\n';
//		for (int i = 0; i <n-1; i++)
//		{
//			cout << edge_select[i].first << "->";
//			cout << edge_select[i].second << '\n';
//		}
//	}
//	else
//		cout << -1 << '\n';
//	return 0;
//}
//不仅输出总权值，还输出 MST 里具体选了哪些边。
//4 5
//1 2 1
//1 3 4
//2 3 2
//2 4 5
//3 4 3