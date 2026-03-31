//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> dist;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void bfs(int sx, int sy)
//{
//	queue<pair<int, int>>q;
//	q.push({ sx,sy });
//	dist[sx][sy] = 0;
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front();
//		q.pop();
//		int x = cur.first;
//		int y = cur.second;
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//			if (g[nx][ny] == '#')continue;
//			if (dist[nx][ny] != -1)continue;
//			dist[nx][ny] = dist[x][y] + 1;
//			q.push({ nx,ny });
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	dist.assign(n, vector<int>(m, -1));
//	int sx, sy, ex, ey;
//	cin >> sx >> sy >> ex >> ey;
//	if (g[sx][sy] == '.' && g[ex][ey] == '.')
//		bfs(sx, sy);
//	cout << dist[ex][ey] << '\n';
//	return 0;
//}
//题 1：迷宫最少步数
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> dist;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void bfs(int sx, int sy)
//{
//	queue<pair<int, int>> q;
//	q.push({ sx,sy });
//	dist[sx][sy] = 0;
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front();
//		q.pop();
//		int x = cur.first;
//		int y = cur.second;
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//			if (g[nx][ny] == '#')continue;
//			if (dist[nx][ny] != -1)continue;
//			dist[nx][ny] = dist[x][y] + 1;
//			q.push({ nx,ny });
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	dist.assign(n, vector<int>(m, -1));
//	int sx, sy, ex, ey;
//	cin >> sx>> sy>> ex>> ey;
//	if (g[sx][sy] == '.' && g[ex][ey] == '.')
//		bfs(sx, sy);
//	cout << dist[ex][ey] << '\n';
//	return 0;
//}
//就是刚才这题，必须会。
//
//题 2：从起点出发，到每个点的最少步数
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> dist;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void bfs(int sx, int sy)
//{
//	queue<pair<int, int>> q;
//	q.push({ sx,sy });
//	dist[sx][sy] = 0;
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front();
//		q.pop();
//		int x = cur.first;
//		int y = cur.second;
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//			if (g[nx][ny] == '#')continue;
//			if (dist[nx][ny] != -1)continue;
//			dist[nx][ny] = dist[x][y] + 1;
//			q.push({ nx,ny });
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	g.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> g[i];
//	dist.assign(n, vector<int>(m, -1));
//	int sx, sy;
//	cin >> sx >> sy;
//	if (g[sx][sy] == '.')
//		bfs(sx, sy);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << dist[i][j] << '\t';
//		}
//		cout << '\n';
//	}
//	return 0;
//}
//输出整张 dist 表。
//
//题 3：多源 BFS 入门
//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//using namespace std;
//int n, m;
//vector<string> g;
//vector<vector<int>> dist;
//int dx[4] = { -1,1,0,0 };
//int dy[4] = { 0,0,-1,1 };
//void bfs(const vector<pair<int, int>>& st)
//{
//	queue<pair<int, int>> q;
//	for (int i = 0; i < st.size(); i++)
//	{
//		int x = st[i].first;
//		int y = st[i].second;
//		if (x < 0 || x >= n || y < 0 || y >= m)continue;
//		if (g[x][y] == '#')continue;
//		if (dist[x][y] != -1)continue;
//		dist[x][y] = 0;
//		q.push({ x,y });
//	}
//	while (!q.empty())
//	{
//		pair<int, int> cur = q.front();
//		q.pop();
//		int x = cur.first;
//		int y = cur.second;
//		for (int dir = 0; dir < 4; dir++)
//		{
//			int nx = x + dx[dir];
//			int ny = y + dy[dir];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
//			if (g[nx][ny] == '#')continue;
//			if (dist[nx][ny] != -1)continue;
//			dist[nx][ny] = dist[x][y] + 1;
//			q.push({ nx,ny });
//		}
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
//	dist.assign(n, vector<int>(m, -1));
//	int number;
//	cin >> number;
//	vector<pair<int, int>> st(number);
//	for (int i = 0; i < number; i++)
//	{
//		cin >> st[i].first >> st[i].second;
//	}
//	bfs(st);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << dist[i][j] << '\t';
//		}
//		cout << '\n';
//	}
//	return 0;
//}
//给多个起点，同时往外扩散。
//坑 1：坐标和地图字符别混
//st[i].first、st[i].second 是坐标
//g[x][y] 才是格子内容
//坑 2：多源 BFS 不是多次调用单源 BFS
//正确做法：多个起点一次性入队
//不是一个个跑
//题 4：网格扩散题
//
//比如若干个火源 / 感染点同时扩散，求最早到达时间