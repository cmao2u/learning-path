//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	srand(time(0));
//	vector<int> a(100);
//	for (int i = 0; i < 100; i++)
//	{
//		a[i] = rand() % 100;
//	}
//	int n = sizeof(a) / sizeof(a[0]);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			for (int k = j + 1; k < n; k++)
//			{
//				 if (a[i] + a[j] + a[k] == 100)
//					cout << a[i] << " " << a[j] <<" "<<a[k]<<endl;
//			}
//		}
//	}
//	return 0;
//}
//题 1：统计满足条件的数对个数
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	int cnt = 0;
//	for(int i=0;i<n;i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[i] + a[j] == 0&&i<j)
//				cnt++;
//		}
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//输入 n 和 n 个整数，统计有多少对(i, j) 满足 i < j 且 a[i] + a[j] == 0。
//
//	这题练双重循环。
//
//	题 2：找是否存在两数和为 m
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	bool found = false;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[i] + a[j] == m)
//			{
//				found = true;
//				break;
//			}
//		}
//	}
//	if(found)
//		cout << "yes";
//	else
//		cout << "no";
//}
//	输入 n、m 和 n 个整数，判断是否存在两个数和等于 m。
//	输出 yes 或 no。
//
//	这题也是双重循环，但比上一题更接近比赛题。
//
//	题 3：统计满足条件的三元组个数
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n; int cnt = 0;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			for (int k = j + 1; k < n; k++)
//			{
//				if ( a[i] + a[j] + a[k] == 0)
//					cnt++;
//			}
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}

//	输入 n 和 n 个整数，统计有多少个三元组(i, j, k) 满足 i < j < k 且三数之和为 0。
//
//	这题练三重循环和边界控制。
//
//	题 4：暴力枚举区间和
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int max_sum = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		for (int j = i; j < n; j++)
//		{
//			sum += a[j];
//			if(sum > max_sum)
//				max_sum = sum;
//		}
//	}
//	cout << max_sum;
//	return 0;
//}
//	输入 n 和 n 个整数，求所有连续子数组里，和最大的那个值。
//
//	今天先用暴力做，不用前缀和优化。
//	题 5：模拟时钟
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int h, m, x;
//	cin >> h >> m >> x;
//	int total_minutes = h * 60 + m + x;
//	int new_h = (total_minutes / 60) % 24;
//	int new_m = total_minutes % 60;
//	cout << new_h << " " << new_m;
//	return 0;
//}
//	输入一个时刻 h m 和一个整数 x，表示增加 x 分钟后，输出新的时刻。
//
//	比如输入 23 50 20，输出 0 10。
//
//	这题练规则模拟。
//
//	题 6：字符串规则模拟
//
//	输入一个字符串，把其中每个小写字母都变成下一个字母。
//	比如：
//
//	a->b
//
//	b->c
//
//	...
//
//	z->a
//
//	输出新字符串。
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	int n = s.size();
//	for (int i = 0; i < n; i++)
//	{
//		if(s[i] >= 'a' && s[i] <= 'z')
//		{
//			s[i] = (s[i] - 'a' + 1) % 26 + 'a';
//		}
//	}
//	cout << s;
//	return 0;
//}
//	这题练字符模拟。