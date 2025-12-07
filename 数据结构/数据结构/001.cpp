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