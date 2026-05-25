/*
之前学过一些
但是好像忘了
索性重新开始


第一课
时间复杂度
*/
//练习 1：求数组元素和
//
//输入 n，再输入 n 个整数，输出它们的和。
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> a(n);
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a[i];
//		sum += a[i];
//	}
//	std::cout << sum;
//}
//O(n)=n
//要求：
//
//写出代码
//说出时间复杂度
//练习 2：求最大值和最小值
//
//输入 n，再输入 n 个整数，输出最大值和最小值。
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector<int> a(n);
//	int firstvalue;
//	std::cin >> firstvalue;
//	int max = firstvalue;
//	int min = firstvalue;
//	for (int i = 1; i < n; i++)
//	{
//		std::cin >> a[i];
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//		if (a[i] < min)
//		{
//			min = a[i];
//		}
//	};
//	std::cout << max << " " << min;
//}
//O(n) = n
//要求：
//
//只遍历一遍数组
//说出时间复杂度
//练习 3：判断是否存在目标值
//
//输入 n 和 target，再输入 n 个整数。
//
//如果数组中存在 target，输出 YES，否则输出 NO。
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	int target;
//	std::cin >> target;
//	std::vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a[i];
//		if (a[i] == target)
//		{
//			std::cout << "YES";
//			return 0;
//		}
//	}
//	std::cout << "NO";
//}
//要求：
//
//用 O(n) 做法
//找到后可以提前结束
//练习 4：两数之和暴力版
//
//输入 n 和 x，再输入 n 个整数。
//
//判断是否存在两个不同位置的数，使它们的和等于 x。
//#include <iostream>
//#include<vector>
//
//int main()
//{
//	int n, x;
//	std::cin >> n >> x;
//	std::vector<int> a(n);
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[i] + a[j] == x)
//			{
//				std::cout << "YES";
//				return;
//			}
//		}
//	}
//	std::cout << "NO";
//}
//
//O(n) = n * n
//要求：
//
//先用两层循环暴力做
//输出 YES 或 NO
//说出时间复杂度
//练习 5：判断复杂度
//
//不用写代码，直接回答下面这些代码的复杂度：
//
//1
//for (int i = 0; i < n; i++) {
//    std::cout << i << '\n';
//}
//2
//for (int i = 0; i < n; i++) {
//    for (int j = 0; j < n; j++) {
//        std::cout << i << ' ' << j << '\n';
//    }
//}
//3
//for (int i = 1; i <= n; i *= 2) {
//    std::cout << i << '\n';
//}
//4
//std::sort(a.begin(), a.end());
//5
//for (int i = 0; i < n; i++) {
//    std::cout << a[i] << '\n';
//}
//
//for (int j = 0; j < n; j++) {
//    std::cout << a[j] << '\n';
//}
//1.O(n) = n;
//2.O(n) = n * n
//3.O(n) = log2n
//4.O(n) = nlogn
//5.O(n) = n
//#include <iostream>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	int number_Positive = 0;
//	int number_Negative = 0;
//	int number_Zero = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		std::cin >> x;
//		if (x > 0)
//		{
//			number_Positive++;
//		}
//		else if (x < 0)
//		{
//			number_Negative++;
//		}
//		else if (x == 0)
//		{
//			number_Zero++;
//		}
//		else
//		{
//			std::cout << "错误!";
//			break;
//		}
//	}
//	std::cout << number_Positive <<" " << number_Negative <<" " << number_Zero<<" ";
//	return 0;
//}