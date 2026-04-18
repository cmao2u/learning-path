//#include <iostream>
//#include <vector>
//using namespace std;
//void dfs(int x, int y)
//{
//	vis[x][y] = 1;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];;
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (vis[nx][ny])continue;
//		if (g[nx][ny] != '1')continue;
//		dfs(nx, ny);
//	}
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> vis;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void dfs(int x, int y)
//{
//	vis[x][y] = 1;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (vis[nx][ny]) continue;
//		if (g[nx][ny] != '1')continue;
//		dfs(nx, ny);
//
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> g[i];
//	}
//	vis.assign(n, vector<int>(m, 0));
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> vis;
//int dx[4] = {-1,1,0,0};
//int dy[4] = { 0,0,-1,1 };
//void dfs(int x, int y)
//{
//	vis[x][y] = 1;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (vis[nx][ny] == 1)continue;
//		if (g[nx][ny] != '1')continue;
//		dfs(nx, ny);
//
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	vis.assign(n, vector<int>(m, 0));
//	int sx,sy;
//	cin >> sx>>sy;
//	if (g[sx][sy] == '1')
//	{
//		dfs(sx, sy);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << vis[i][j] << ' ';
//		} 
//		cout << '\n';
//	}
//	return 0;
//}
//题 2：统计连通块个数
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> vis;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void dfs(int x, int y)
//{
//	vis[x][y] = 1;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (g[nx][ny] != '1')continue;
//		if (vis[nx][ny])continue;
//		dfs(nx, ny);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	vis.assign(n, vector<int>(m, 0));
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (g[i][j] == '1' && (vis[i][j] ==0))/*以后看到 if (...)，脑子里自动检查一遍：	我这里是在比较，还是在赋值？*/
//			{
//				dfs(i, j);
//				cnt++;
//			}
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}

//输入 0 / 1 网格，统计一共有多少块 1 区域。
//题 3：迷宫是否可达
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> vis;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void dfs(int x, int y)
//{
//	vis[x][y] = 1;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (vis[nx][ny])continue;
//		if (g[nx][ny] != '.')continue;
//		dfs(nx, ny);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	vis.assign(n, vector<int>(m, 0));
//	int sx, sy, ex, ey;
//	cin >> sx >> sy >> ex >> ey;
//	if (g[sx][sy] == '.' && g[ex][ey] == '.')
//	{
//		dfs(sx, sy);
//	}
//	if (vis[ex][ey])
//		cout << "yes";
//	else
//		cout << "no";
//	return 0;
//}
//输入一个网格，'.' 表示能走，'#' 表示障碍，再给起点和终点，判断能否走到终点。
//
//这题练“可达性”。
//
//题 4：统计某个点所在连通块的大小
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int n, m;
// int cnt=0;
//vector<string> g;
//vector<vector<int>> vis;
//int dx[4] = {-1,1,0,0};
//int dy[4] = {0,0,-1,1};
//void dfs(int x, int y)
//{
//
//	vis[x][y] = 1;
//	cnt++;
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//		if (g[nx][ny] != '1')continue;
//		if (vis[nx][ny])continue;
//		dfs(nx, ny);
//		
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	vis.assign(n, vector<int>(m, 0));
//	int sx, sy;
//	cin >> sx >> sy;
//	if (g[sx][sy] == '1')
//	{
//		dfs(sx, sy);
//	}
//	cout << cnt;
//	return 0;
//}
//输入 0 / 1 网格和一个起点(sx, sy)，输出它所在那块区域有多少个格子。
//
//这题会让你开始理解：DFS 不只是能“走”，还能顺手“统计”。
//
//题 5：把网格中所有连通块大小都算出来，输出最大值
//
//输入 0 / 1 网格，输出最大连通块的大小。
//
//这题是题 2 和题 4 的组合升级。