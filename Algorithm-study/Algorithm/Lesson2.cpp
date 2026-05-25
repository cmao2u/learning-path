//练习 1：统计偶数和奇数
//
//输入 n，再输入 n 个整数。
//
//输出偶数个数和奇数个数。
//#include <iostream>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	int odd = 0;
//	int even = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		std::cin >> x;
//		if (x % 2 == 0)
//		{
//			even++;
//		}
//		else
//		{
//			odd++;
//		}
//	}
//	std::cout << even <<" " << odd;
//	return 0;
//}
//O(n)
//要求：
//
//1. 不用数组
//2. 一边输入一边判断
//3. 输出格式：偶数个数 奇数个数
//4. 写出时间复杂度
//练习 2：数组元素翻倍
//
//输入 n，再输入 n 个整数。
//
//把每个元素乘以 2 后输出。
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	std::vector < int > a(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> a[i];
//		a[i] *= 2;
//	}
//
//	for (int i = 0; i < static_cast<int>(a.size()); i++)
//	{
//		std::cout << a[i]<<" ";
//	}
//	
//	std::cout << "\n";
//}
//O(n)
//要求：
//
//1. 使用 vector 存数组
//2. 修改数组元素
//3. 输出修改后的数组
//4. 写出时间复杂度
//练习 3：统计字符串中的小写字母个数
//
//输入一个不含空格的字符串 s。
//
//统计其中有多少个小写字母。
//
//小写字母范围：
//
//'a' 到 'z'
//#include <iostream>
//
//int main()
//{
//	int lower_cnt = 0;
//	std::string s;
//	std::cin >> s;
//
//	for (int i = 0; i < static_cast<int>(s.size()); i++)
//	{
//		if (s[i] >= 'a' && s[i] <= 'z')
//			lower_cnt++;
//	}
//	
//	std::cout << lower_cnt;
//}
//O(n)
//要求：
//
//1. 遍历字符串
//2. 判断字符是否在 'a' 到 'z' 之间
//3. 写出时间复杂度
//练习 4：字符串倒序输出
//
//输入一个不含空格的字符串 s。
//
//倒序输出这个字符串。
//#include<iostream>
//
//int main()
//{
//	std::string s;
//	std::cin >> s;
//	for (int i = static_cast<int>(s.size()-1); i >= 0; i--)
//	{
//		std::cout << s[i];
//	}
//}O(n)
//要求：
//
//1. 从最后一个字符开始输出
//2. 注意下标不要越界
//3. 写出时间复杂度
//练习 5：左右移动模拟
//
//输入 n，再输入 n 个字符，每个字符是 L 或 R。
//
//初始位置为 0。
//
//规则：
//
//L：向左移动 1
//R：向右移动 1
//
//输出最后的位置。
//#include <iostream>
//
//int main()
//{
//	int n;
//	std::cin >> n;
//	int locate = 0;
//	for (int i = 0; i < n; i++)
//	{
//		char s;
//		std::cin >> s;
//		if (s == 'L')
//		{
//			locate--;
//		}
//		else
//		{
//			locate++;
//		}
//
//	}
//
//	std::cout << locate;
//}
//O(n)
//要求：
//
//1. 不用数组
//2. 一边输入一边更新位置
//3. 写出时间复杂度