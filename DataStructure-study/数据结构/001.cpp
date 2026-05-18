//#include <iostream>
//#include <time.h>
//using namespace std;
///*
//void printN(int N)
//{
//	for(int i=1;i<N;i++)
//	{
//		cout << i << endl;
//	}
//}
//void printn(int N)
//{
//	if (N) {
//		printn(N - 1);
//			cout << N << endl;
//	}
//}*/
/*关于算法效率
clock_t start, finish;
double duration;
double function01(int n, double a[], double x)
{
	double p = a[0];
	for (int i = 1; i <= n; i++)
	{
		p += (a[i] * pow(x, i));
	}
	return p;
}
double function02(int n, double a[], double x)
{
	double p = a[n];
	for (int i = n; i > 0; i--)
	{
		p = (p * x + a[i - 1]);
	}
	return p;
}*/
/*关于算法效率
clock_t start,finish;
double duration;
double function01(int n, double a[], double x)
{
	double p = 1/a[0];
	for (int i = 1; i <= n; i++)
	{
		p += pow(x, i) / a[i];
	}
	return p;
}
double function02(int n, double a[], double x)
{
	double p = 1 / a[n];
	for (int i = n; i > 0; i--)
	{
		p = (p * x + (1 / a[i - 1]));
	}
	return p;
}*/

/*Maximum Subsequence Sum Problem
int func01(int A[], int n)
{
	
	int MaxSum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ThisSum = 0;
			for (int k = i; k < j; k++)
			{
				ThisSum += A[k];	
			}
			if (ThisSum > MaxSum)
			MaxSum = ThisSum;
			
		}
	}
	return MaxSum; 
}
int func02(int A[],int n)
{
	int MaxSum = 0;
	for (int i = 0; i < n; i++)
	{
		int ThisSum = 0;
		for (int j = i; j < n; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
				
			
	}
	return MaxSum;
}
int Max3(int a, int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}
int MaxSubseqSum(int List[], int  left, int right)
{
	int center, MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	center = (left + right) / 2;
	if (left == right)
	{
		return List[left] > 0 ? List[left] : 0;
	}
	MaxLeftSum = MaxSubseqSum(List, left, center);
	MaxRightSum = MaxSubseqSum(List, center + 1, right);
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	RightBorderSum = 0; MaxRightBorderSum = 0;
	for (int i = center + 1; i <= right; i++)
	{
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int func03(int List[],int n)
{
	return MaxSubseqSum(List, 0, n - 1);
}
int func04(int List[],int n)
{
	int ThisSum = 0; int MaxSum = 0;
		for (int i = 0;i <= n; i++)
		{
			ThisSum += List[i];
			if(ThisSum>MaxSum)
				MaxSum = ThisSum;
			else if (ThisSum < 0)
				ThisSum = 0;

		}
		return MaxSum;
}



void test01()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func01(A, n) << endl;
}
void test02()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func02(A, n) << endl;
}
void test03()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func03(A, n) << endl;
}
void test04()
{
	int A[] = { -2,11,-4,13,-5,-2 ,5,-8,4,8,-9};
	int n = sizeof(A) / sizeof(A[0]);
	cout << func04(A, n) << endl
{/*
	//printN(1000);
	printn(10000);
}*/
	/*关于算法效率
	多项式求值
	double a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };// 多项式系数
	int n = 20;  // 多项式最高次数（必须小于数组长度-1）
	double x = 10.0;  // 多项式自变量

	// 重复调用1000000次，放大时间差异
	const int repeat = 1000000;

	// 测试function01
	clock_t start = clock();
	for (int i = 0; i < repeat; i++) {
		function01(n, a, x);
	}
	clock_t finish = clock();
	double duration01 = double(finish - start) / CLOCKS_PER_SEC;  // 用CLOCKS_PER_SEC更标准
	cout << "function01 时间: " << duration01 << "s" << endl;
	cout << function01(n, a, x) << endl;

	// 测试function02
	start = clock();
	for (int i = 0; i < repeat; i++) {
		function02(n, a, x);
	}
	finish = clock();
	double duration02 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function02 时间: " << duration02 << "s" << endl;
	cout << function02(n, a, x) << endl;	*/

	/*
	double a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };// 多项式系数
	int n = 20;
	
	{
		function02(n, a, x);
	}
	 finish = clock();
	double duration02 = double(finish - start) / CLOCKS_PER_SEC;
	cout << "function02 时间: " << duration02 << "s" << endl;
	cout << function02(n, a, x) << endl;*/
	/*Maximum Subsequence Sum Problem
	/test01();
	test02();
	test03();
	test04();*/
//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//// 多项式项类
//class Polynomial {
//public:
//	int coef;  // 系数
//	int expon; // 指数
//	Polynomial(int c, int e) : coef(c), expon(e) {}
//};
//
//// 读取多项式（静默读取，按指数降序返回）
//vector<Polynomial> readPoly() {
//	int n;
//	cin >> n;
//	map<int, int> polyMap; // 用map自动按指数升序存储，合并同类项
//	for (int i = 0; i < n; i++) {
//		int c, e;
//		cin >> c >> e;
//		polyMap[e] += c; // 自动合并同类项（输入可能有重复指数，题目虽未说但需兼容）
//	} 
//	// 转换为vector，按指数降序排列
//	vector<Polynomial> poly;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) { // 系数不为0才加入
//			poly.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return poly;
//}
//
//// 多项式加法（用map实现，自动合并同类项）
//vector<Polynomial> addPoly(const vector<Polynomial>& p1, const vector<Polynomial>& p2) {
//	map<int, int> polyMap;
//	// 加入p1的项
//	for (const auto& term : p1) {
//		polyMap[term.expon] += term.coef;
//	}
//	// 加入p2的项，自动合并同类项    
//	for (const auto& term : p2) {
//		polyMap[term.expon] += term.coef;
//	}
//	// 转换为vector，按指数降序
//	vector<Polynomial> result;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) {
//			result.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return result;
//}
//
//// 多项式乘法（用map实现，自动合并同类项）
//vector<Polynomial> mulPoly(const vector<Polynomial>& p1, const vector<Polynomial>& p2) {
//	map<int, int> polyMap;
//	// 遍历p1和p2的所有项，计算乘积并存入map
//	for (const auto& term1 : p1) {
//		for (const auto& term2 : p2) {
//			int new_e = term1.expon + term2.expon; // 指数相加
//			int new_c = term1.coef * term2.coef;   // 系数相乘
//			polyMap[new_e] += new_c;               // 自动合并同类项
//		}
//	}
//	// 转换为vector，按指数降序
//	vector<Polynomial> result;
//	for (auto it = polyMap.rbegin(); it != polyMap.rend(); it++) {
//		if (it->second != 0) { // 系数不为0才加入
//			result.push_back(Polynomial(it->second, it->first));
//		}
//	}
//	return result;
//}
//
//// 打印多项式（严格按题目格式：无多余空格，零多项式输出0 0）
//void printPoly(const vector<Polynomial>& poly) {
//	if (poly.empty()) {
//		cout << "0 0";
//	}
//	else {
//		for (size_t i = 0; i < poly.size(); i++) {
//			if (i > 0) {
//				cout << " ";
//			}
//			cout << poly[i].coef << " " << poly[i].expon;
//		}
//	}
//	cout << endl;
//}
//
//int main() {
//	// 读取两个多项式（无交互式提示，兼容样例批量输入）
//	vector<Polynomial> p1 = readPoly();
//	vector<Polynomial> p2 = readPoly();
//
//	// 计算乘积和和
//	vector<Polynomial> product = mulPoly(p1, p2);
//	vector<Polynomial> sum_poly = addPoly(p1, p2);
//
//	// 输出结果（先乘积，后和，符合题目要求）
//	printPoly(product);
//	printPoly(sum_poly);
//
//	return 0;
//}
/*
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
class Polynomial
{
public:
	int coef;
	int expon;
	Polynomial(int a, int b) :coef(a), expon(b) {}
};
vector<Polynomial> readPoly(int coef = 0, int expon = 0)
{
	int n;
	cout << "请输入第一个多项式非零项的个数" << endl;
	cin >> n;
	map<int, int>m1;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入系数和指数" << endl;
		cin >> coef >> expon;
		m1[expon] += coef;
	}
	vector<Polynomial>v1;
	for (auto it = m1.rbegin(); it != m1.rend(); it++)
	{
		if (it->second != 0)
		{
			v1.push_back(Polynomial(it->second, it->first));
		}
	}
	return v1;
}
vector<Polynomial> AddPolynomial(vector<Polynomial>& p1, vector<Polynomial>& p2)
{
	map<int, int> m1;
	for (const auto& term : p1)
	{
		m1[term.expon] = term.coef;
	}
	for (const auto& term : p2)
	{
		m1[term.expon] += term.coef;
	}
	vector<int, int> result;
	for (auto it = m1.rbegin(); it != m1.rend(); it++)
	{
		if (it->second != 0)
		{

		}
	}
}

int main()
{
	vector<Polynomial> p1 = readPoly();
	vector<Polynomial> p2 = readPoly();

}*/
//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//typedef struct Node* Bintree;
//struct Node
//{
//	int data;
//	Bintree Left;
//	Bintree Right;
//
//};
//void PreOrderTravelsal(Bintree BT)
//{
//	if (BT)
//	{
//		cout << BT->data;
//		PreOrderTravelsal(BT->Left);
//		PreOrderTravelsal(BT->Right);
//	}
//}
//void InOrderTravelsal(Bintree BT)
//{
//	if (BT)
//	{
//		InOrderTravelsal(BT->Left);
//		cout << BT->data;
//		InOrderTravelsal(BT->Right);
//	}
//}
//void PostOrderTravelsal(Bintree BT)
//{
//	if (BT)
//	{
//		PostOrderTravelsal(BT->Left);
//		PostOrderTravelsal(BT->Right);
//		cout << BT->data;
//	}
//}
//void LevelOrderTravelsal(Bintree BT)
//{
//	queue<Bintree> q;
//	if (!BT)
//		return;
//	while (!q.empty())
//	{
//		cout << q.front();
//		q.pop();
//		if (BT->Left)
//			q.push(BT->Left);
//		if (BT->Right)
//			q.push(BT->Right);
//	}
////}
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <iterator>
//
//// 定义二叉树节点结构
//struct TreeNode {
//	char data;
//	int left;  // 左孩子的索引，-1表示空
//	int right; // 右孩子的索引，-1表示空
//};
//
//// 将树的构建逻辑封装在一个函数中
//// 读取输入并返回根节点的索引
//int buildTree(std::vector<TreeNode>& tree) {
//	int n;
//	std::cin >> n;
//
//	if (n == 0) {
//		return -1; // 空树
//	}
//
//	tree.resize(n);
//	std::vector<int> parent(n, -1); // 用于寻找根节点
//
//	for (int i = 0; i < n; ++i) {
//		char data;
//		std::string leftStr, rightStr;
//
//		// 直接从标准输入读取数据，不添加任何提示
//		std::cin >> data >> leftStr >> rightStr;
//
//		tree[i].data = data;
//		 
//		// 处理左孩子
//		tree[i].left = (leftStr == "-") ? -1 : std::stoi(leftStr);
//		// 处理右孩子
//		tree[i].right = (rightStr == "-") ? -1 : std::stoi(rightStr);
//
//		// 更新父节点信息
//		if (tree[i].left != -1) {
//			parent[tree[i].left] = i;
//		}
//		if (tree[i].right != -1) {
//			parent[tree[i].right] = i;
//		}
//	}
//
//	// 根节点是父节点为-1的节点
//	auto it = std::find(parent.begin(), parent.end(), -1);
//	if (it != parent.end()) {
//		return std::distance(parent.begin(), it);
//	}
//
//	return -1; // 理论上不会到达这里
//}
//
//// 递归判断两棵树是否同构
//bool isIsomorphic(const std::vector<TreeNode>& tree1, int root1,
//	const std::vector<TreeNode>& tree2, int root2) {
//	// 1. 如果两个节点都为空，它们是同构的
//	if (root1 == -1 && root2 == -1) {
//		return true;
//	}
//	// 2. 如果一个为空另一个不为空，它们不同构
//	if (root1 == -1 || root2 == -1) {
//		return false;
//	}
//	// 3. 如果节点的值不同，它们不同构
//	if (tree1[root1].data != tree2[root2].data) {
//		return false;  
//	}
//
//	// 4. 递归检查子树的两种可能情况
//	// 情况一：不交换左右子树
//	bool case1 = isIsomorphic(tree1, tree1[root1].left, tree2, tree2[root2].left) &&
//		isIsomorphic(tree1, tree1[root1].right, tree2, tree2[root2].right);
//
//	// 情况二：交换左右子树
//	bool case2 = isIsomorphic(tree1, tree1[root1].left, tree2, tree2[root2].right) &&
//		isIsomorphic(tree1, tree1[root1].right, tree2, tree2[root2].left);
//
//	return case1 || case2;
//}
//
//int main() {
//	// 关闭 cin 和 cout 的同步，可以加速IO，在数据量大时很有用
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(NULL);
//
//	std::vector<TreeNode> tree1, tree2;
//	int root1 = buildTree(tree1);
//	int root2 = buildTree(tree2);
//
//	// 调用同构判断函数
//	if (isIsomorphic(tree1, root1, tree2, root2)) {
//		std::cout << "Yes" << std::endl;
//	}
//	else {
//		std::cout << "No" << std::endl;
//	}
//
//	return 0;
//}
/*创造节点
建树：
利用vector存储每个节点 
找出根（-1的）
同构函数：
1.都为空true
2.一个为空一个有false
3.根值不同false
4.1不交换左右子树递归
4.2交换左右子树递归
主函数：
 调用建树函数建两棵树
 判断同构并输出结果
 */
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//struct TreeNode
//{
//	char data;
//	int left;
//	int right;
//};
//int BuildTree(vector<TreeNode> &Tree)
//{
//	int n;
//	cin >> n;
//	if (n == 0)
//		return -1;//空树
//	Tree.resize(n);
//	vector<int> parent(n, -1);
//	for (int i = 0; i < n; i++)
//	{
//		char data;
//		string leftStr;
//		string rightStr;
//		cin >> data >> leftStr >> rightStr;
//		Tree[i].data = data;
//		Tree[i].left = (leftStr == "-" ? -1 : stoi(leftStr));
//		Tree[i].right = (rightStr == "-" ? -1 : stoi(rightStr));
//		if (Tree[i].left != -1)
//			parent[Tree[i].left] = i;
//		if (Tree[i].right != -1)
//			parent[Tree[i].right] = i;
//	}
//	auto it = find(parent.begin(), parent.end(), -1);
//	if (it != parent.end())
//		return distance(parent.begin(), it);
//	else 
//		return -1;//理论上不会到达这里
//
//}
//bool isIsomorphic(const vector<TreeNode>& tree1, int root1,
//	const vector<TreeNode>& tree2, int root2)
//{
//	if (root1 == -1 && root2 == -1)
//		return true;
//	if (root1 == -1 && root2 != -1)
//		return false;
//	if (tree1[root1].data != tree2[root2].data)
//		return false;
//	bool case1 = isIsomorphic(tree1, tree1[root1].left, tree2, tree2[root2].left) &&
//		isIsomorphic(tree1, tree1[root1].right, tree2, tree2[root2].right);
//	bool case2 = isIsomorphic(tree1, tree1[root1].left, tree2, tree2[root2].right) &&
//		isIsomorphic(tree1, tree1[root1].right, tree2, tree2[root2].left);
//	return case1 || case2;
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	vector<TreeNode> tree1, tree2;
//	int root1 = BuildTree(tree1);
//	int root2 = BuildTree(tree2);
//	if(isIsomorphic(tree1, root1, tree2, root2))
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//}



/*List leaves
造树：
存储数据
层序遍历
没有左右孩子输出*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include< string>
//#include <algorithm>
//using namespace std;
//struct TreeNode
//{
//	int left;
//	int right;
//};
//int BuildTree(vector<TreeNode>& Tree)
//{
//	int n; cin >> n;
//	if (n == 0)
//		return -1;//空树
//	Tree.resize(n);
//	vector<int> parent(n, -1);
//	for (int i = 0; i < n; i++)
//	{
//		string leftStr;
//		string rightStr;
//		cin  >> leftStr >> rightStr;
//		Tree[i].left = (leftStr == "-" ? -1 : stoi(leftStr));
//		Tree[i].right = (rightStr == "-" ? -1 : stoi(rightStr));
//		if (Tree[i].left != -1)
//			parent[Tree[i].left] = i;
//		if (Tree[i].right != -1)
//			parent[Tree[i].right] = i;
//	}
//	auto it = find(parent.begin(), parent.end(), -1);
//	if (it != parent.end())
//		return distance(parent.begin(), it);
//	else
//		return -1;//理论上不会到达这里
//}
//void LevelOrderTravelsal(const vector<TreeNode>& Tree, int root)
//{
//	queue<int> q;
//	if (root == -1)
//		return;
//	q.push(root);
//	bool first = true; //声明布尔变量 first，用于 控制输出格式：标记是否是 “第一个要输出的叶子节点”（避免行尾多余空格）。
//	while (!q.empty())
//	{
//		int index = q.front();
//		q.pop();
//		if (Tree[index].left == -1 && Tree[index].right == -1)
//		{
//			if (first)
//			{
//				cout << index;
//				first = false;
//			}
//			else
//				cout << " " << index;
//		}
///		if (Tree[index].left != -1)
//			q.push(Tree[index].left);
//		if (Tree[index].right != -1)
//			q.push(Tree[index].right);
//	}
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	vector<TreeNode>tree;
//	int root = BuildTree(tree);
//	LevelOrderTravelsal(tree,root);
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//// BST节点结构体（C++风格，带构造函数）
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	// 构造函数：初始化节点值，左右子树为空
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//// 向BST中插入节点（递归实现）
//TreeNode* insert(TreeNode* root, int val) {
//	if (root == nullptr) {  // 空树/叶子节点，新建节点
//		return new TreeNode(val);
//	}
//	if (val < root->val) {  // 小于当前节点，插入左子树
//		root->left = insert(root->left, val);
//	}
//	else {  // 大于当前节点，插入右子树（题目无重复值，无需处理等于）
//		root->right = insert(root->right, val);
//	}
//	return root;
//}
//
//// 前序遍历BST，生成特征序列（存储到vector中）
//void preOrder(TreeNode* root, vector<int>& res) {
//	if (root == nullptr) return;
//	res.push_back(root->val);    // 根
//	preOrder(root->left, res);   // 左
//	preOrder(root->right, res);  // 右
//}
//
//// 释放BST所有节点内存（避免内存泄漏）
//void deleteTree(TreeNode* root) {
//	if (root == nullptr) return;
//	deleteTree(root->left);   // 递归释放左子树
//	deleteTree(root->right);  // 递归释放右子树
//	delete root;              // 释放当前节点
//}
//
//// 生成插入序列对应的BST前序序列
//vector<int> getPreSeq(const vector<int>& seq) {
//	TreeNode* root = nullptr;
//	// 插入所有元素构建BST
//	for (int val : seq) {
//		root = insert(root, val);
//	}
//	// 生成前序序列
//	vector<int> pre;
//	preOrder(root, pre);
//	// 释放内存
//	deleteTree(root);
//	return pre;
//}
//
//int main() {
//	int n, m;
//	// 循环读取测试用例，n=0时结束
//	while (cin >> n && n != 0) {
//		cin >> m;
//		// 读取初始插入序列
//		vector<int> initSeq(n);
//		for (int i = 0; i < n; ++i) {
//			cin >> initSeq[i];
//		}
//		// 生成初始序列的前序特征
//		vector<int> initPre = getPreSeq(initSeq);
//
//		// 检查m个待验证序列
//		for (int i = 0; i < m; ++i) {
//			vector<int> checkSeq(n);
//			for (int j = 0; j < n; ++j) {
//				cin >> checkSeq[j];
//			}
//			// 生成待验证序列的前序特征
//			vector<int> checkPre = getPreSeq(checkSeq);
//			// 对比特征序列
//			if (checkPre == initPre) {
//				cout << "Yes" << endl;
//			}
//			else {
//				cout << "No" << endl;
//			}
//		}
//	}
//	return 0;
//}
/*判断是否是同一颗BST
1.根据BST的特征——Inorder相同
只要判断先序是否相同即可
2.建树
3.记录完后删除遍历后数据
4.封装函数
5.循环调用*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
//};
//TreeNode* insert(TreeNode* root, int val)
//{
//	if (root == nullptr)
//	{
//		return new TreeNode(val);
//	}
//	if (val < root->val)
//		root->left = insert(root->left, val);
//	else
//		root -> right = insert(root->right, val);
//	return root;
//}
//void PreOrder(TreeNode* root, vector<int>& res)
//{
//	if (root == nullptr)
//		return;
//	res.push_back(root->val);
//	PreOrder(root->left, res);
//	PreOrder(root->right, res);
//}
//void deleteTree(TreeNode* root)
//{
//	if (root == nullptr)
//		return;
//	deleteTree(root->left);
//	deleteTree(root->right);
//	delete root;
//}
//vector<int> getPreSeq(const vector<int>& seq)
//{
//	TreeNode* root = nullptr;
//	for (int val : seq)
//	{
//		root = insert(root,val);
//	}
//	vector<int> pre;
//	PreOrder(root, pre);
//	deleteTree(root);
//	return pre;
//}
//int main()
//{
//	int m, n;
//	while (cin >> m && m != 0)
//	{
//		cin >> n;
//		vector<int> InitSeq(m);
//		for(int i=0; i < m; i++)
//		{
//			cin >> InitSeq[i];
//		}
//		InitSeq = getPreSeq(InitSeq);
//		for (int i = 0; i < n; i++)
//		{
//			vector<int> CheckSeq(m);
//			for (int j = 0; j < m; j++)
//			{
//				cin >> CheckSeq[j];
//			}
//			CheckSeq = getPreSeq(CheckSeq);
//			if(CheckSeq == InitSeq)
//				cout << "Yes" << endl;
//			else
//				cout << "No" << endl;
//		}
//	}
//	return 0;
//
//
//}

/*
#include <iostream>
#include <algorithm>
using namespace std;

// AVL树节点结构
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	int height; // 节点高度
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

// 获取节点高度（空节点高度为0）
int getHeight(TreeNode* node) {
	return node ? node->height : 0;
}

// 更新节点高度
void updateHeight(TreeNode* node) {
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// 计算平衡因子（左高-右高）
int getBalance(TreeNode* node) {
	return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// LL旋转（右旋）：处理左子树的左子树失衡
TreeNode* rightRotate(TreeNode* y) {
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;

	// 执行旋转
	x->right = y;
	y->left = T2;

	// 更新高度（先更新子节点，再更新父节点）
	updateHeight(y);
	updateHeight(x);

	return x; // 新根节点
}

// RR旋转（左旋）：处理右子树的右子树失衡
TreeNode* leftRotate(TreeNode* x) {
	TreeNode* y = x->right;
	TreeNode* T2 = y->left;

	// 执行旋转
	y->left = x;
	x->right = T2;

	// 更新高度
	updateHeight(x);
	updateHeight(y);

	return y; // 新根节点
}

// AVL树插入函数（递归实现，返回调整后的根）
TreeNode* insert(TreeNode* root, int val) {
	// 1. 按二叉搜索树规则插入节点
	if (root == nullptr) {
		return new TreeNode(val);
	}
	if (val < root->val) {
		root->left = insert(root->left, val);
	} else if (val > root->val) {
		root->right = insert(root->right, val);
	} else {
		return root; // 无重复值，直接返回
	}

	// 2. 更新当前节点高度
	updateHeight(root);

	// 3. 计算平衡因子，判断是否失衡
	int balance = getBalance(root);

	// 4. 失衡处理（四种情况）
	// 情况1：LL失衡（左左）
	if (balance > 1 && val < root->left->val) {
		return rightRotate(root);
	}
	// 情况2：RR失衡（右右）
	if (balance < -1 && val > root->right->val) {
		return leftRotate(root);
	}
	// 情况3：LR失衡（左右）
	if (balance > 1 && val > root->left->val) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// 情况4：RL失衡（右左）
	if (balance < -1 && val < root->right->val) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root; // 未失衡，返回原根
}

int main() {
	int N;
	while (cin >> N) {
		TreeNode* root = nullptr;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			root = insert(root, val);
		}
		cout << root->val << endl; // 输出最终根节点
	}
	return 0;
}*/
/*
最小堆路径
1.建m(Size)大小的堆 函数
2.插入最小堆数据函数
3.封装*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct Minheap
//{
//	vector<int> data;
//	int Size;
//	int Capacity;
//};
//void CreateMinheap(Minheap& H, int Capacity)
//{
//	H.Capacity = Capacity;
//	H.Size = 0;
//	H.data.resize(Capacity + 1);
//	H.data[0] = -100000;//哨兵
//}
//void Insert(Minheap& H, int val)
//{
//	
//	H.data[++H.Size] = val;
//	int i = H.Size;
//	for (; H.data[i / 2] > val&&i!=1; i /=2)
//	{
//		H.data[i] = H.data[i / 2];
//		H.data[i / 2] = val;
//	}
//}
//void Path(Minheap& H, int index)
//{
//	for(int i=index; i>0; i/=2)
//	{
//		cout << H.data[i];
//		if (i != 1)
//			cout << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int n, m;
//	cout << "请输入插入元素的个数以及需要打印的路径条数" << endl;
//	cin >> n >> m;
//	Minheap H;
//	CreateMinheap(H, n);
//	for(int i=0;i<n;i++)
//	{
//		int val;
//		cout << "请输入第" << i + 1 << "个元素的值" << endl;
//		cin >> val;
//		Insert(H, val);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int index;
//		cout << "请输入需要打印路径的节点索引" << endl;
//		cin >> index;
//		Path(H, index);
//	}
//	return 0;
//}
/*
优化版本:
#include <iostream>
#include <vector>
#include <climits>  // 提供INT_MIN
using namespace std;

// 结构体变量名改用小写（符合C++变量命名习惯）
struct Minheap {
    vector<int> data;  // 堆元素（索引1开始，0为哨兵）
    int size;          // 当前元素个数（原Size→size）
    int capacity;      // 最大容量（原Capacity→capacity）
};

// 初始化堆：明确哨兵作用，vector直接初始化
void CreateMinheap(Minheap& H, int capacity) {
    H.capacity = capacity;
    H.size = 0;
    // 直接初始化vector，避免后续resize可能的隐患
    H.data = vector<int>(capacity + 1, 0);  // 容量+1，初始值0
    H.data[0] = INT_MIN;  // 哨兵：确保比所有输入元素小，用于终止上滤
}

// 插入函数：增加注释，逻辑更清晰
void Insert(Minheap& H, int val) {
    if (H.size >= H.capacity) {  // 堆满保护（题目输入合法可省略，但保留更鲁棒）
        return;
    }
    int i = ++H.size;  // 新元素先放末尾
    // 上滤：父节点值 > 当前值时，父节点下移
    while (H.data[i/2] > val) {  // 用while比for更直观（逻辑不变）
        H.data[i] = H.data[i/2];  // 父节点下移
        i /= 2;  // 指针上移到父节点
    }
    H.data[i] = val;  // 找到正确位置，放入新元素
}

// 路径打印：增加索引合法性检查（防错）
void Path(Minheap& H, int index) {
    // 检查索引是否合法（1<=index<=size），避免越界访问
    if (index < 1 || index > H.size) {
        return;  // 非法索引直接返回（题目输入合法可省略，防错用）
    }
    for (int i = index; i > 0; i /= 2) {
        cout << H.data[i];
        if (i != 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Minheap H;
    CreateMinheap(H, n);  // 传入n作为容量
    
    // 插入n个元素
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Insert(H, val);
    }
    
    // 打印m条路径
    for (int i = 0; i < m; ++i) {
        int index;
        cin >> index;
        Path(H, index);
    }
    
    return 0;
}*/
//呃，有点忘了，重新学一遍吧
//#include <iostream>
//void PrintN(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		std::cout << i << " ";
//	}
//}
//#include<iostream>
//void PrintN(int n)
//{
//	if (n == 1)
//	{
//		std::cout << 1 << " ";
//	}
//	else
//	{
//		PrintN(n - 1);
//		std::cout << n << " ";
//	}
//}
//int main()
//{
//	int n;
//	std::cin >> n;
//	PrintN(n);
//}
//#include <iostream>
//double func(int n, int a[], double x)
//{
//	double p = a[0];
//	for (int i = 0; i <= n; i++)
//	{
//		p += a[i] * pow(x, i);
//	}
//}
//#include <iostream>
//#include <cmath>
//#include <ctime>
//double func1(double x, int n)
//{
//	double p = 1.0;
//	for (int i = 1; i <= n; i++)
//	{
//		p = p + pow(x, i) / i;
//	}
//	return p;
//}
//double func2(double x, int n)
//{
//	 double p = 1.0 / n;
//	for (int i=n-1; i >=1; i--)
//	{
//     p = p * x + 1.0/i;
//	}
//	return p*x+1.0;
//}
//int main()
//{
//	double x = 1.1;
//	const int n = 100;
//	volatile double ans = 0.0;
//	clock_t start, end;
//	start = clock();
//	for (int i = 0; i < 1e7; i++)
//		ans=func1(x, n);
//	end = clock();
//	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
//	std::cout << duration<<'\n';
//	start = clock();
//	for (int i = 0; i <= 1e7; i++)
//		ans=func2(x, n);
//	end = clock();
//	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
//	std::cout << duration<<'\n';
//}
//#include <iostream>
//
//using ElementType = int;
//using Position = int;   // Position: position，位置/下标
//
//class SeqList
//{
//public:
//	static constexpr int kMaxSize = 100;
//	static constexpr Position kError = -1;
//
//	SeqList() : last_(-1) {}  // 初始化空表，last_ = -1
//
//	bool isEmpty() const
//	{
//		return last_ == -1;
//	}
//
//	bool isFull() const
//	{
//		return last_ == kMaxSize - 1;
//	}
//
//	int size() const
//	{
//		return last_ + 1;
//	}
//
//	// 查找元素 X，找到返回下标，找不到返回 -1
//	Position find(ElementType x) const
//	{
//		Position i = 0;
//		while (i <= last_ && data_[i] != x)
//		{
//			++i;
//		}
//
//		if (i > last_)
//		{
//			return kError;
//		}
//		else
//		{
//			return i;
//		}
//	}
//
//	// 在下标 P 位置前插入元素 X
//	bool insert(ElementType x, Position p)
//	{
//		if (isFull())
//		{
//			std::cout << "表满，无法插入\n";
//			return false;
//		}
//
//		if (p < 0 || p > last_ + 1)
//		{
//			std::cout << "插入位置不合法\n";
//			return false;
//		}
//
//		for (Position i = last_; i >= p; --i)
//		{
//			data_[i + 1] = data_[i];
//		}
//
//		data_[p] = x;
//		++last_;
//		return true;
//	}
//
//	// 删除下标 P 处的元素
//	bool erase(Position p)
//	{
//		if (p < 0 || p > last_)
//		{
//			std::cout << "删除位置不合法\n";
//			return false;
//		}
//
//		for (Position i = p + 1; i <= last_; ++i)
//		{
//			data_[i - 1] = data_[i];
//		}
//
//		--last_;
//		return true;
//	}
//
//	void print() const
//	{
//		for (Position i = 0; i <= last_; ++i)
//		{
//			std::cout << data_[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//
//private:
//	ElementType data_[kMaxSize];  // data_: data，数据数组
//	Position last_;               // last_: last，最后一个有效元素的下标
//};
//
//int main()
//{
//	SeqList list;
//
//	list.insert(10, 0);
//	list.insert(20, 1);
//	list.insert(30, 2);
//	list.print();   // 10 20 30
//
//	list.insert(99, 1);
//	list.print();   // 10 99 20 30
//
//	std::cout << "20 的位置: " << list.find(20) << '\n';
//
//	list.erase(2);
//	list.print();   // 10 99 30
//
//	return 0;
//}
//
//#include <iostream>
//using ElementType = int;
//using Position = int;
//class Seqlist
//{
//public:
//	static constexpr int kMaxSize = 100;
//	static constexpr Position kError = -1;
//	Seqlist() :last_(-1) {}
//	bool isEmpty() const
//	{
//		return last_ == -1;
//	}
//	bool isFull() const
//	{
//		return last_ == kMaxSize - 1;
//	}
//	int size() const
//	{
//		return last_ + 1;
//	}
//	Position find(ElementType x)const
//	{
//		Position i = 0;
//		while (i <= last_ && data_[i] != x)
//		{
//			++i;
//		}
//		if (i > last_)
//			return kError;
//		else
//			return i;
//	}
//	bool insert(ElementType x, Position p)
//	{
//		if (isFull())
//		{
//			std::cout << "表满，无法插入\n";
//			return false;
//		}
//		if (p<0 || p>last_ + 1)
//		{
//			std::cout << "插入位置不合法\n";
//			return false;
//		}
//		for (Position i = last_; i >= p; --i)
//		{
//			data_[i + 1] = data_[i];
//		}
//		data_[p] = x;
//		++last_;
//		return true;
//	}
//	bool erase(Position p)
//	{
//		if (p<0 || p>last_)
//		{
//			std::cout << "删除位置不合法\n";
//			return false;
//		}
//		for (Position i = p + 1; i <= last_; i++)
//		{
//			data_[i - 1] = data_[i];
//		}
//		last_--;
//		return true;
//	}
//	void print() const
//	{
//		for (Position i = 0;i <= last_; i++)
//		{
//			std::cout << data_[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//private:
//	ElementType data_[kMaxSize];
//	Position last_;
//};
//int main()
//{
//	Seqlist list;
//	list.insert(10, 0);
//	list.insert(20, 1);
//	list.insert(30, 2);
//	list.print();
//	list.insert(99, 1);
//	list.print();
//	std::cout << "20的位置:" << list.find(20) << '\n';
//	list.erase(2);
//	list.print();
//	return 0;
//}
//写一个顺序表，能做到:
//查找元素 X，找到返回下标，找不到返回 - 1
//在下标 P 位置前插入元素 X
//删除下标 P 处的元素
//#include <iostream>
//class SeqList
//{
//	using ElementType = int;
//	using Position = int;
//
//public:
//	static constexpr int kMaxSize = 100;
//	static constexpr Position kError = -1;
//
//	SeqList() :last_(-1) {}
//
//	bool isFull() const
//	{
//		return last_ == kMaxSize - 1;
//	}
//
//	int size() const
//	{
//		return last_ + 1;
//	}
//
//	bool isEmpty() const
//	{
//		return last_ == -1;
//	}
//
//	bool insert(ElementType x,Position p)
//	{
//		if (isFull())
//		{
//			std::cout << "表满，无法插入"<<'\n';
//			return false;
//		}
//		if (p < 0 || p > last_+1)
//		{
//			std::cout << "插入目标位置不合法"<<'\n'; //输出格式要统一
//			return false;
//		}
//		for (Position i = last_ + 1; i > p; i--)
//		{
//			data_[i] = data_[i - 1];
//		}
//		data_[p] = x;
//		last_++;
//		return true;
//	}
//
//	void print() const
//	{
//		for (Position i = 0; i <= last_; i++)
//		{
//			std::cout << data_[i] << " ";
//		}
//		std::cout << '\n';
//	}
//	Position find(ElementType x) const
//	{
//		for (Position i = 0; i <= last_; i++)//保持类型一致性。
//		{
//			if (data_[i] == x)
//			{
//				return i;
//			}
//		}
//		return kError;
//	}
//
//	bool erase(Position p)
//	{
//		if (p < 0 || p > last_)
//		{
//			std::cout << "删除位置不合法" << '\n';
//			return false;
//		}
//		for (Position i = p; i < last_; i++)
//		{
//			data_[i] = data_[i + 1];
//		}
//		last_--;
//		return true;
//	}
//
//private:
//	ElementType data_[kMaxSize];
//	Position last_;
//};
//int main()
//{
//	SeqList list;
//	list.insert(10, 0);
//	list.insert(20, 1);
//	list.insert(30, 2);
//	list.print();
//	list.insert(99, 1);
//	list.print();
//	std::cout << "20的位置:" << list.find(20) << '\n';
//	list.erase(2);
//	list.print();
//	return 0;
//}
//#include <iostream>
//
//using ElementType = int;
//
//struct ListNode
//{
//	ElementType data;   // data: data，数据域
//	ListNode* next;     // next: next，下一个结点指针
//
//	ListNode(ElementType value = 0, ListNode* nextNode = nullptr)
//		: data(value), next(nextNode)
//	{
//	}
//};
//
//using Position = ListNode*;   // Position: position，位置，这里本质是结点指针
//
//class LinkedList
//{
//public:
//	static constexpr Position kError = nullptr;
//
//	LinkedList()
//	{
//		head_ = new ListNode();   // 头结点，不存有效数据
//	}
//
//	~LinkedList()
//	{
//		Position current = head_;
//		while (current != nullptr)
//		{
//			Position nextNode = current->next;
//			delete current;
//			current = nextNode;
//		}
//	}
//
//	// 查找元素 x，找到返回结点指针，找不到返回 nullptr
//	Position find(ElementType x) const
//	{
//		Position p = head_->next;   // p 指向第一个有效结点
//		while (p != nullptr && p->data != x)
//		{
//			p = p->next;
//		}
//		return p;
//	}
//
//	// 在结点 p 前插入新结点 x
//	bool insert(ElementType x, Position p)
//	{
//		Position pre = head_;   // pre: predecessor，前驱结点
//
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//
//		if (pre == nullptr)
//		{
//			std::cout << "插入位置参数错误\n";
//			return false;
//		}
//
//		Position tmp = new ListNode(x);  // tmp: temporary，临时新结点
//		tmp->next = p;
//		pre->next = tmp;
//		return true;
//	}
//
//	// 删除结点 p
//	bool erase(Position p)
//	{
//		if (p == nullptr)
//		{
//			std::cout << "删除位置参数错误\n";
//			return false;
//		}
//
//		Position pre = head_;
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//
//		if (pre == nullptr)
//		{
//			std::cout << "删除位置参数错误\n";
//			return false;
//		}
//
//		pre->next = p->next;
//		delete p;
//		return true;
//	}
//
//	// 尾插，方便测试
//	void pushBack(ElementType x)
//	{
//		Position tail = head_;
//		while (tail->next != nullptr)
//		{
//			tail = tail->next;
//		}
//		tail->next = new ListNode(x);
//	}
//
//	void print() const
//	{
//		Position p = head_->next;
//		while (p != nullptr)
//		{
//			std::cout << p->data << ' ';
//			p = p->next;
//		}
//		std::cout << '\n';
//	}
//
//	Position first() const
//	{
//		return head_->next;
//	}
//
//	Position head() const
//	{
//		return head_;
//	}
//
//private:
//	Position head_;   // head_: head，头结点
//};
//
//int main()
//{
//	LinkedList list;
//
//	list.pushBack(10);
//	list.pushBack(20);
//	list.pushBack(30);
//	list.print();   // 10 20 30
//
//	Position p = list.find(20);
//	list.insert(99, p);   // 在 20 前插入 99
//	list.print();         // 10 99 20 30
//
//	p = list.find(20);
//	list.erase(p);        // 删除 20
//	list.print();         // 10 99 30
//
//	return 0;
//}
//下面自行练习
//#include <iostream>
//
//using ElementType = int;
//
//struct ListNode
//{
//	ElementType data;
//	ListNode* next;
//
//	ListNode(ElementType value=0,ListNode* nextNode = nullptr) : data(value),next(nextNode) {}
//};
//
//using Position = ListNode*;
//
//class LinkedList
//{
//	
//
//public:
//	static constexpr Position kError = nullptr;
//
//	LinkedList()
//	{
//		head_ = new ListNode();
//	}
//
//	~LinkedList()
//	{
//		Position current = head_;
//		while (current != nullptr)
//		{
//			Position nextNode = current->next;
//			delete current;
//			current = nextNode;
//		}
//	}
//
//	Position find(ElementType x) const
//	{
//		Position p = head_->next;
//		while (p != nullptr && p->data != x)
//		{
//			p = p->next;
//		}
//		return p;
//	}
//
//	bool insert(ElementType x, Position p)
//	{
//		Position pre = head_;
//		
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//		if (pre == nullptr)
//		{
//			std::cout << "插入位置不合法\n";
//			return false;
//		}
//
//		Position tmp = new ListNode(x);
//		tmp->next = p;
//		pre->next = tmp;
//		return true;
//	}
//
//	bool erase(Position p)
//	{
//		if (p == nullptr)
//		{
//			std::cout << "插入位置不合法\n";
//			return false;
//		}
//		
//		Position pre = head_;
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//
//		if (pre == nullptr)
//		{
//			std::cout << "插入位置不合法\n";
//		}
//
//		pre->next = p->next;
//		delete p;
//		return true;
//	}
//
//	void pushBack(ElementType x)
//	{
//		Position tail = head_;
//		while (tail->next != nullptr)
//		{
//			tail = tail->next;
//		}
//		tail->next = new ListNode(x);
//	}
//	void print() const
//	{
//		Position p = head_->next;
//		while (p != nullptr)
//		{
//			std::cout << p->data << ' ';
//			p = p->next;
//		}
//		std::cout << '\n';
//	}
//
//	Position first() const
//	{
//		return head_->next;
//	}
//
//	Position head() const
//	{
//		return head_;
//	}
//
//private:
//	Position head_ = nullptr;
//};
//
//int main()
//{
//	LinkedList list;
//
//	list.pushBack(10);
//	list.pushBack(20);
//	list.pushBack(30);
//	list.print();
//
//	Position p = list.find(20);
//	list.insert(99, p);
//	list.print();
//
//	p = list.find(20);
//	list.erase(p);
//	list.print();
//
//	return 0;
//}
//#include <iostream>
//
//using ElementType = int;
//
//struct ListNode
//{
//	ElementType data;
//	ListNode* next;
//
//	ListNode(ElementType value = 0, ListNode* nextNode = nullptr) : data(value), next(nextNode) {};
//};
//
//using Position = ListNode*;
//
//class LinkedList
//{
//public:
//	LinkedList()
//	{
//		head_ = new ListNode();
//	}
//	~LinkedList()
//	{
//		Position current = head_;
//		while (current != nullptr)
//		{
//			Position temp = current->next;
//			delete current;
//			current = temp;
//		}
//	}
//
//	void pushBack(ElementType value)
//	{
//		Position tail = head_;
//		while (tail->next != nullptr)
//		{
//			tail = tail->next;
//		}
//		tail->next = new ListNode(value);
//	}
//	
//	void print() const
//	{
//		Position pre = head_->next;
//		while (pre != nullptr)
//		{
//			std::cout << pre->data << " ";
//			pre = pre->next;
//		}
//		std::cout << '\n';
//	}
//
//	Position find(ElementType value) const
//	{
//		Position pre = head_->next;
//		while (pre != nullptr && pre->data != value)
//		{
//			pre = pre->next;
//		}
//		return pre;
//	}
//
//	bool insert(ElementType value, Position p)
//	{
//		Position pre = head_;
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//		if (pre == nullptr)
//		{
//			std::cout << "插入位置不合法\n";
//			return false;
//		}
//		
//		Position temp = new ListNode(value);
//		temp->next = p;
//		pre->next = temp;
//		return true;
//	}
//
//	bool erase(Position p)
//	{
//		if (p == nullptr)
//		{
//			std::cout << "删除位置不合法\n";
//			return false;
//		}
//
//		Position pre = head_;
//
//		while (pre != nullptr && pre->next != p)
//		{
//			pre = pre->next;
//		}
//
//		if (pre == nullptr)
//		{
//			std::cout << "删除位置不合法\n";
//			return false;
//		}
//
//		pre->next = p->next;
//		delete p;
//		return true;
//	}
//
//	Position head() const
//	{
//		return head_;
//	}
//	
//	Position first() const
//	{
//		return head_->next;
//	}
//
//private:
//	Position head_;
//};
//
//int main()
//{
//	LinkedList list;
//
//	list.pushBack(10);
//	list.pushBack(20);
//	list.pushBack(30);
//	list.print();
//
//	Position p = list.find(20);
//	list.insert(99, p);
//	list.print();
//
//	p = list.find(20);
//	list.erase(p);
//	list.print();
//
//	return 0;
//
//}
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//using ElementType = int;
//using Position = int;
//
//class ArrayStack
//{
//public:
//	explicit ArrayStack(int maxSize)
//		: data_(maxSize), top_(-1), maxSize_(maxSize)
//	{
//	}
//
//	bool isEmpty() const
//	{
//		return top_ == -1;
//	}
//
//	bool isFull() const
//	{
//		return top_ == maxSize_ - 1;
//	}
//
//	bool push(ElementType x)
//	{
//		if (isFull())
//		{
//			std::cout << "堆栈满\n";
//			return false;
//		}
//
//		data_[++top_] = x;
//		return true;
//	}
//
//	ElementType pop()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，无法弹出元素");
//		}
//
//		return data_[top_--];
//	}
//
//	ElementType top() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，没有栈顶元素");
//		}
//
//		return data_[top_];
//	}
//
//	int size() const
//	{
//		return top_ + 1;
//	}
//
//	void print() const
//	{
//		for (Position i = 0; i <= top_; ++i)
//		{
//			std::cout << data_[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//
//private:
//	std::vector<ElementType> data_;  // data: 数据区，底层是连续空间
//	Position top_;                   // top: 栈顶元素下标
//	int maxSize_;                    // max size: 最大容量
//};
//
//int main()
//{
//	ArrayStack stack(5);
//
//	stack.push(10);
//	stack.push(20);
//	stack.push(30);
//
//	stack.print();  // 10 20 30
//
//	std::cout << "栈顶元素: " << stack.top() << '\n';
//
//	std::cout << "弹出: " << stack.pop() << '\n';
//	std::cout << "弹出: " << stack.pop() << '\n';
//
//	stack.print();  // 10
//
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//using ElementType = int;
//using Position = int;
//
//class ArrayStack
//{
//public:
//	explicit ArrayStack(int maxSize) : data_(maxSize), top_(-1), maxSize_(maxSize) {};
//
//	bool isEmpty() const
//	{
//		return top_ == -1;
//	}
//
//	bool isFull() const
//	{
//		return maxSize_ - 1 == top_;
//	}
//
//	bool push(ElementType x)
//	{
//		if (isFull())
//		{
//			std::cout << "堆栈满\n";
//			return false;
//		}
//
//		data_[++top_] = x;
//		return true;
//	}
//
//	ElementType pop()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，无法弹出元素");
//		}
//
//		return data_[top_--];
//	}
//
//	ElementType top() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，没有栈顶元素");
//		}
//		return data_[top_];
//	}
//
//	int size() const
//	{
//		return top_ + 1;
//	}
//
//	void print() const
//	{
//		for (Position i = 0; i <= top_; ++i)
//		{
//			std::cout << data_[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//
//private:
//	std::vector<ElementType> data_;
//	Position top_;
//	int maxSize_;
//};
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//class ArrayStack
//{
//	using ElementType = int;
//	using Position = int;
//public:
//	explicit ArrayStack(int maxSize) :data_(maxSize), top_(-1), maxSize_(maxSize) {};
//
//	bool isEmpty() const
//	{
//		return top_ == -1;
//	}
//	
//	bool isFull() const
//	{
//		return top_ == maxSize_ - 1;
//	}
//
//	bool push(ElementType x) 
//	{
//		if (isFull())
//		{
//			throw std::runtime_error("堆栈满，无法添加新元素");
//		}
//		data_[++top_] = x;
//		return true;
//	}
//
//	ElementType pop()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，无法弹出元素");
//		}
//		return data_[top_--];
//	}
//
//	ElementType top() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空");
//		}
//		return data_[top_];
//	}
//
//	int size() const
//	{
//		return top_ + 1;
//	}
//
//	void print() const
//	{
//		for (int i = 0; i <= top_; i++)
//		{
//			std::cout << data_[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//
//private:
//	std::vector<ElementType> data_;
//	Position top_;
//	int maxSize_;
//
//};
//
//int main()
//{
//	ArrayStack stack(5);
//
//	stack.push(10);
//	stack.push(20);
//	stack.push(30);
//
//	stack.print();
//
//	std::cout << "栈顶元素 :" << stack.top() << '\n';
//
//	std::cout << "弹出:" << stack.pop() << '\n';
//	std::cout << "弹出:" << stack.pop() << '\n';
//
//	stack.print();
//
//	return 0;
//}
//#include <iostream>
//#include <stdexcept>
//
//using ElementType = int;
//
//class LinkedStack
//{
//private:
//	struct Node
//	{
//		ElementType data;  // data: 数据域
//		Node* next;        // next: 下一个结点指针
//
//		Node(ElementType value = 0, Node* nextNode = nullptr)
//			: data(value), next(nextNode)
//		{
//		}
//	};
//
//public:
//	LinkedStack()
//		: head_(new Node())
//	{
//	}
//
//	~LinkedStack()
//	{
//		while (!isEmpty())
//		{
//			pop();
//		}
//
//		delete head_;
//	}
//
//	bool isEmpty() const
//	{
//		return head_->next == nullptr;
//	}
//
//	bool push(ElementType x)
//	{
//		Node* newNode = new Node(x, head_->next);
//		head_->next = newNode;
//		return true;
//	}
//
//	ElementType pop()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，无法弹出元素");
//		}
//
//		Node* firstNode = head_->next;
//		ElementType topElement = firstNode->data;
//
//		head_->next = firstNode->next;
//		delete firstNode;
//
//		return topElement;
//	}
//
//	ElementType top() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("堆栈空，没有栈顶元素");
//		}
//
//		return head_->next->data;
//	}
//
//	void print() const
//	{
//		Node* current = head_->next;
//
//		while (current != nullptr)
//		{
//			std::cout << current->data << ' ';
//			current = current->next;
//		}
//
//		std::cout << '\n';
//	}
//
//private:
//	Node* head_;  // head: 头结点，不存有效数据
//};

/*
构造
析构
空？
加节点
pop
top
print*/

//#include <iostream>
//#include <stdexcept>
//
//class LinkedStack
//{
//public:
//	using ElementType = int;
//	struct Node
//	{
//		ElementType data_;
//		Node* next_;
//
//		Node (ElementType value = 0, Node *nextNode = nullptr) : data_(value), next_(nextNode){}
//	};
//
//	LinkedStack() :head_(new Node)	{}
//
//	~LinkedStack()
//	{
//		while (!isEmpty())
//		{
//			pop();
//		}
//		delete head_; 
//	}
//
//	bool isEmpty() const
//	{
//		return head_->next_ == nullptr;
//	}
//
//	void push(ElementType x)
//	{
//		Node* newNode = new Node(x, head_->next_);
//		head_->next_ = newNode;
//
//	}
//
//	ElementType pop()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("栈空，无法弹出元素");
//		}
//
//		Node* firstNode = head_->next_;
//		head_->next_ = firstNode->next_;
//		ElementType topElement = firstNode->data_;
//		delete firstNode;
//		return topElement;
//	}
//
//	ElementType top() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("栈空");
//		}
//		return head_->next_->data_;
//	}
//
//	void print() const
//	{
//		for (Node* P = head_->next_; P != nullptr; P = P->next_)
//		{
//			std::cout << P->data_ << " ";
//		}
//		std::cout << "\n";
//	}
//
//private:
//	Node* head_;
//};
//
//
//int main()
//{
//	LinkedStack stack;
//
//	stack.push(10);
//	stack.push(20);
//	stack.push(30);
//
//	stack.print();  // 30 20 10
//
//	std::cout << "栈顶元素: " << stack.top() << '\n';
//
//	std::cout << "弹出: " << stack.pop() << '\n';
//	std::cout << "弹出: " << stack.pop() << '\n';
//
//	stack.print();  // 10
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//using ElementType = int;
//using Position = int;
//
//class CircularQueue
//{
//public:
//	explicit CircularQueue(int maxSize)
//		: data_(maxSize), front_(0), rear_(0), maxSize_(maxSize)
//	{
//		if (maxSize <= 1)
//		{
//			throw std::invalid_argument("队列容量必须大于 1");
//		}
//	}
//
//	bool isEmpty() const
//	{
//		return front_ == rear_;
//	}
//
//	bool isFull() const
//	{
//		return (rear_ + 1) % maxSize_ == front_;
//	}
//
//	bool enqueue(ElementType x)
//	{
//		if (isFull())
//		{
//			std::cout << "队列满，无法入队\n";
//			return false;
//		}
//
//		rear_ = (rear_ + 1) % maxSize_;
//		data_[rear_] = x;
//		return true;
//	}
//
//	ElementType dequeue()
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("队列空，无法出队");
//		}
//
//		front_ = (front_ + 1) % maxSize_;
//		return data_[front_];
//	}
//
//	ElementType front() const
//	{
//		if (isEmpty())
//		{
//			throw std::runtime_error("队列空，没有队头元素");
//		}
//
//		Position first = (front_ + 1) % maxSize_;
//		return data_[first];
//	}
//
//	int size() const
//	{
//		return (rear_ - front_ + maxSize_) % maxSize_;
//	}
//
//	void print() const
//	{
//		Position current = (front_ + 1) % maxSize_;
//
//		while (current != (rear_ + 1) % maxSize_)
//		{
//			std::cout << data_[current] << ' ';
//			current = (current + 1) % maxSize_;
//		}
//
//		std::cout << '\n';
//	}
//
//private:
//	std::vector<ElementType> data_;
//	Position front_;     // front: 队头前一个位置
//	Position rear_;      // rear: 队尾元素位置
//	int maxSize_;
//};

/*
* 空
* 满
* 入队
* 出队
* 队首元素
* 个数
* 打印
*/
#include <iostream>
#include <vector>
#include <stdexcept>

class CircularQueue
{
	using ElementType = int;
	using Position = int;
public:
	explicit CircularQueue(int maxSize): data_(maxSize), front_(0),rear_(0), maxSize_(maxSize)
	{
		if (maxSize <= 1)
			throw std::runtime_error("队列最大值不能小于1");
	}
	bool isEmpty() const
	{
		return rear_ == front_;
	}

	bool isFull() const
	{
		return (rear_ + 1)%maxSize_ == front_;
	}
	
	void enqueue(ElementType x)
	{
		if (isFull())
		{
			throw std::runtime_error("队列满，无法添加新元素");
		}
		rear_ = (rear_ + 1) % maxSize_;
		data_[rear_] = x;
	}

	ElementType dequeue()
	{
		if (isEmpty())
		{
			throw std::runtime_error("队列空，无法出元素");
		}
		front_ = (front_ + 1) % maxSize_;
		return data_[front_];
	}
	ElementType front() const
	{
		if (isEmpty())
		{
			throw std::runtime_error("队列空，没有第一个元素");
		}
		return data_[(front_ + 1) % maxSize_];
	}

	int size() const
	{
		return (rear_ - front_ + maxSize_) % maxSize_;
	}

	void print()
	{
		Position current = (front_ + 1) % maxSize_;
		while (current != (rear_+1) % maxSize_)
		{
			std::cout << data_[current] << " ";
			current = (current + 1) % maxSize_;
		}
		std::cout << "\n";
	}

private:
	std::vector<ElementType> data_;
	Position front_;
	Position rear_;
	int maxSize_;
};

int main()
{
	CircularQueue queue(5);

	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);

	queue.print();  // 10 20 30

	std::cout << "队头元素: " << queue.front() << '\n';

	std::cout << "出队: " << queue.dequeue() << '\n';
	std::cout << "出队: " << queue.dequeue() << '\n';

	queue.enqueue(40);
	queue.enqueue(50);
	queue.enqueue(60);

	queue.print();  // 30 40 50 60

	std::cout << "当前队列长度: " << queue.size() << '\n';

	return 0;
}