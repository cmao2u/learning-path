//题 1：建图并输出每个点的邻居
	/*#include <iostream>
	#include <vector>
	using namespace std;
	int main()
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n+1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << ":";
			for (int v:g[i])
			{
				cout << v << " ";
			}
			cout << "\n";
		}
		return 0;
	}*/
//这是最基础的题。
//
//你需要做到：
//
//会开 g
//会读入边
//会输出 g[1] ~g[n]
//题 2：图上的 DFS 遍历
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> vis;
//vector<vector<int>> g;
//void dfs(int s)
//{
//	vis[s] = 1;
//	for (int v : g[s])
//	{
//		if (!vis[v])
//			dfs(v);
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	g.resize(n + 1);
//	vis.resize(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v;
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int s;
//	cin >> s;
//	dfs(s);
//	for (int i = 1; i <= n; i++)
//	{
//		if (vis[i])
//		{
//			cout << i;
//		}
//	}
//	return 0;
//}
//给你一个起点 s，输出所有从 s 能到达的点。
//
//这题练：
//#include <vector>
//#include <iostream>
//using namespace std;
//vector<int> vis;
//vector<vector<int>> g;
//void dfs(int s)
//{
//	vis[s] = 1;
//	for (int v : g[s])
//	{
//		if (!vis[v])
//			dfs(v);
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	g.resize(n + 1);
//	vis.resize(n + 1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v;
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!vis[i])
//		{
//			dfs(i);
//			cnt++;
//		}
//	}
//	cout << cnt;
//	return 0;
//}
//图上 DFS 基础骨架
//题 3：图的连通块个数
//
//这题和你之前“网格连通块计数”本质一样。
//
//做法：
//
//扫所有点
//每发现一个没访问过的点，就 dfs(i)，并且 cnt++
//题 4：图上的 BFS 最短步数
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//vector<vector<int>> g;
//vector<int> dist;
//void bfs(int s)
//{
//	queue<int> q;
//	q.push(s);
//	dist[s] = 0;
//	while (!q.empty())
//	{
//		int cur = q.front();
//		q.pop();
//		for (int v : g[cur])
//		{
//			if (dist[v] == -1)
//			{
//				dist[v] = dist[cur] + 1;
//				q.push(v);
//			}
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	g.resize(n + 1);
//	dist.assign(n+1,-1);
//	for (int i = 0; i < m; i++)
//	{
//		int u, v;
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int s;
//	cin >> s;
//	bfs(s);
//	for (int i = 1; i <= n; i++)
//	{
//		if (dist[i] != -1)
//			cout << i << ":" << dist[i] << '\n';
//	}
//	return 0;
//}
//给起点 s，求它到所有点的最少边数。
//
//这题练：
//
//图上 BFS 基础骨架