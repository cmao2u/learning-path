//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	cout << s.size() << '\n';
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++)
//	{
//		cout << s[i];
//	}
//	cout << '\n';
//	for (char c : s)
//	{
//		cout << c;
//	}
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	for (char c:s)
//	{
//		if (c == 'a')
//			cnt++;
//	}
//	cout << cnt;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	for (char c : s)
//	{
//		if(c>='a'&&c<='z')
//			cnt++;
//	}
//	cout << cnt;
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	for (char c : s)
//		cout << c;
//	cout << '\n';
//	for(int i=s.size()-1;i>=0;i--)
//		cout << s[i];
//	return 0;
//}题 1：输出字符串长度
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	cout << s.size() << '\n';
//	return 0;
//}
//输入一个字符串，输出它的长度。
//
//题 2：统计字符 a 的个数
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	for (int i=0; i < s.size(); i++)
//	{
//#include <iostream>
//using namespace std;
//		if (s[i] == 'a')
//			cnt++;
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//输入一个字符串，输出其中 'a' 出现了几次。
//
//题 3：统计数字字符个数
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if(s[i]>='0'&&s[i]<='9')
//			cnt++;
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//输入一个字符串，输出其中数字字符有几个。
//
//题 4：统计元音字母个数
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	for(int i=0;i<s.size();i++)
//	{
//		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
//			cnt++;
//	}
//	cout << cnt << '\n';
//	return 0;
//}
//输入一个字符串，统计 a e i o u 有多少个。
//
//题 5：判断回文串
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	bool judge = true;
//	for (int i = 0; i < s.size() / 2; i++)
//	{
//		if (s[i] != s[s.size() - 1 - i])
//		{
//			judge = false;
//			break;
//		}
//	}
//	if(judge)
//		cout << "yes\n";
//	else
//		cout << "no\n";
//	return 0;
//}
//输入一个字符串，判断是不是回文串，输出 yes 或 no。

//题 6：倒序输出字符串
//#include <iostream>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	for (int i = s.size() - 1; i >= 0; i--)
//		cout << s[i];
//	return 0;
//}
//输入一个字符串，把它反过来输出*/