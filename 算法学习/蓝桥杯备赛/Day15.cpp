//#include <iostream>
//#include <vector>
//using namespace std;
//struct Edge
//{
//	int to, w;
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<Edge>> g(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	int s;
//	cin >> s;
//	const int INF = 1e10;
//	vector<int> dist(n + 1, INF);
//	vector<int> vis(n + 1, 0);
//	dist[s] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int u = -1;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!vis[j] && (u == -1 || dist[j] < dist[u]))
//			{
//				u = j;
//			}
//		}
//		if (u == -1 || dist[u] == INF)break;
//		vis[u] = 1;
//		for (Edge e : g[u])
//		{
//			int v = e.to;
//			int w = e.w;
//			if (dist[v] > dist[u] + w)
//			{
//				dist[v] = dist[u] + w;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (dist[i] == INF)cout << i << ":" << -1 << '\n';
//		else cout << i << ":" << dist[i] << '\n';
//	}
//	return 0;
//}
//题 1：建带权无向图并输出邻居
//#include <iostream>
//#include <vector>
//using namespace std;
//struct Edge
//{
//	int to, w;
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<Edge>> g;
//	g.resize(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (Edge e : g[i])
//			cout <<i<<" " << "to:" << e.to << " " << "w:" << e.w << '\n';
//	}
//	return 0;
//}
//输入 n, m 和 u v w，输出每个点连出去的(to, w)。
//题 2：Dijkstra 模板题
//#include <iostream>
//#include <vector>
//using namespace std;
//struct Edge
//{
//	int to, w;
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<Edge>> g(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	int s;
//	cin >> s;
//	const int INF = 1e7;
//	vector<int> dist(n + 1,INF);
//	vector<int> vis(n + 1,0);
//	dist[s] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int u = -1;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!vis[j] && (u == -1 || dist[j] < dist[u]))
//				u = j;
//		}
//		if (u == -1 || dist[u] == INF)break;
//		vis[u] = 1;
//		for (Edge e : g[u])
//		{
//			int v = e.to;
//			int weight = e.w;
//			if (dist[v] > dist[u] + weight)
//			{
//				dist[v] = dist[u] + weight;
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (dist[i] == INF)
//			cout << i << ":" << -1 << '\n';
//		else
//			cout << i << ":" << dist[i] << '\n';
//	}
//	return 0;
//}
//输入带权图和起点，输出起点到每个点的最短路。
//题 3：输出起点到终点的最短路长度
//#include <iostream>
//#include <vector>
//using namespace std;
//struct Edge
//{
//	int to, w;
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<vector<Edge>> g(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		g[u].push_back({ v,w });
//		g[v].push_back({ u,w });
//	}
//	const int INF = 100000000;
//	vector<int> dist(n + 1, INF);
//	vector<int> vis(n + 1, 0);
//	int start;
//	cin >> start;
//	dist[start] = 0;
//	int end;
//	cin >> end;
//
//	for (int i = 1; i <= n; i++)
//	{
//		int u = -1;
//		for (int j = 1; j <= n; j++)
//		{
//			if (!vis[j] && (u == -1 || dist[j] < dist[u]))
//				u = j;
//		}
//		if (u == -1 || dist[u] == INF)break;
//		vis[u] = 1;
//		for (Edge e : g[u])
//		{
//			int v = e.to;
//			int weight = e.w;
//			if (dist[v] > dist[u] + weight)
//				dist[v] = dist[u] + weight;
//		}
//	}
//	if (dist[end] == INF)
//		cout << "-1" << '\n';
//	else 
//		cout << dist[end] << '\n';
//	return 0;
//}
//只输出 dist[t]。
//题 4：判断某个点是否不可达
//如果不可达输出 - 1。
//5 6
//1 2 2
//1 3 5
//2 3 1
//2 4 2
//3 5 3
//4 5 1
//1