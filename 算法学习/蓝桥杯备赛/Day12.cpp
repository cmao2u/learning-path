//题 1：0 / 1 背包一维优化
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
//		cin >> w[i] >> v[i];
//	vector<int> dp(m + 1,0);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = m; j >= w[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//	cout << dp[m] << '\n';
//	return 0;
//	
//}
//把昨天二维版改写成一维版。
//题 2：完全背包基础版
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
//	vector<int> dp(m + 1, 0);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = w[i]; j <= m; j++)
//		{
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//	cout << dp[m] << '\n';
//	return 0;
//}
//每个物品可无限次选，求最大价值。
//题 3：对比同一组数据下，0 / 1 背包和完全背包结果
//感受“可重复选”和“不可重复选”的差别。
//题 4：硬币凑值（基础版）
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> coin(n + 1);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> coin[i];
//	}
//	vector<int> dp(m + 1, 0);
//	dp[0] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = coin[i]; j <= m; j++)
//		{
//			dp[j] = dp[j] || dp[j - coin[i]];
//		}
//	}
//	if (dp[m])
//		cout << "yes" << '\n';
//	else
//		cout << "no" << '\n';
//	return 0;
//}
//每种硬币无限个，问恰好凑到某个值能不能做到，或者最少硬币数。
//今天只摸最基础版本。