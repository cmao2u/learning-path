//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> w(n + 1), v(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i] >> v[i];
//	}
//	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= w[i])
//			{
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
//			}
//		}
//	}
//	cout << dp[n][m] << '\n';
//	return 0;
//}
//题 1：标准 0 / 1 背包
//输入 n, m，再输入每个物品的重量和价值，输出最大总价值。
//
//题 2：背包恰好装到某个容量的最大价值（基础版）
//
//和标准背包差不多，但会让你更注意初始化。
//
//题 3：输出整张 dp 表
//
//不是只输出答案，而是把 dp 表打出来，看看状态是怎么一步步推出来的。
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> w(n + 1), v(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> w[i] >> v[i];
//	}
//	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			if (j >= w[i])
//			{
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
//			}
//		}
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			cout << dp[i][j] << '\t';
//		}
//		cout << '\n';
//	}
//	cout << "the answer :" << dp[n][m] << '\n';
//	return 0;
//}
//这题很适合你现在这个阶段。