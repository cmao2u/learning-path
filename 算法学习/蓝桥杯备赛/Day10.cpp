//题 1：爬楼梯
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> dp(n + 1, 0);
//	if (n >= 1)dp[1] = 1;
//	if (n >= 2)dp[2] = 2;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//	cout << dp[n];
//	return 0;
//}
//必须会，入门模板。
//
//题 2：斐波那契数列
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> dp(n + 1, 0);
//	if (n >= 1)dp[1] = 1;
//	if (n >= 2)dp[2] = 1;
//	for (int i = 3; i <= n; i++)
//	{
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//	cout << dp[n];
//	return 0;
//}
//和爬楼梯几乎同模型，当热身。
//
//题 3：最大连续子数组和（DP 版）
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	vector<int> dp(n);
//	dp[0] = a[0];
//	int ans = dp[0];
//	for (int i = 1; i < n; i++)
//	{
//		dp[i] = max(dp[i - 1] + a[i], a[i]);
//		ans = max(ans, dp[i]);
//	}
//	cout << ans;
//	return 0;
//}
//这个很有比赛价值。
//
//题 4：不选相邻数的最大和
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	if (n == 1)cout << a[0];
//	vector<int> dp(n);
//	dp[0] = a[0];
//	dp[1] = max(a[0], a[1]);
//	
//	for (int i = 2; i < n; i++)
//	{
//		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
//	}
//	cout << dp[n - 1];
//	return 0;
//}
//这个很经典，也很锻炼“状态定义”。