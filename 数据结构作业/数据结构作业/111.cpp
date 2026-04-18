//#include <iostream>
//using namespace std;
//
//const int MaxSize = 100;
//
//template <class T>
//struct SqList
//{
//    T elem[MaxSize];
//    int length;
//};
//
//template <class T>
//void InitList(SqList<T>& L)
//{
//    L.length = 0;
//}
//
//template <class T>
//bool LocateElem(const SqList<T>& L, const T& e)
//{
//    for (int i = 0; i < L.length; ++i)
//    {
//        if (L.elem[i] == e)
//            return true;
//    }
//    return false;
//}
//
//template <class T>
//bool AppendElem(SqList<T>& L, const T& e)
//{
//    if (L.length >= MaxSize)
//        return false;
//    L.elem[L.length++] = e;
//    return true;
//}
//
//void InputSet(SqList<char>& L, const string& name)
//{
//    InitList(L);
//    int n;
//    cout << "请输入集合 " << name << " 的原始元素个数：";
//    cin >> n;
//
//    cout << "请依次输入 " << n << " 个字符元素：" << endl;
//    for (int i = 0; i < n; ++i)
//    {
//        char ch;
//        cin >> ch;
//        if (!LocateElem(L, ch))
//            AppendElem(L, ch); // 自动去重
//    }
//}
//
//void PrintSet(const SqList<char>& L, const string& name)
//{
//    cout << name << " = ";
//    cout << "{";
//    for (int i = 0; i < L.length; ++i)
//    {
//        cout << L.elem[i];
//        if (i != L.length - 1)
//            cout << ", ";
//    }
//    cout << "}" << endl;
//}
//
//void InterSet(const SqList<char>& A, const SqList<char>& B, SqList<char>& C)
//{
//    InitList(C);
//    for (int i = 0; i < A.length; ++i)
//    {
//        if (LocateElem(B, A.elem[i]))
//            AppendElem(C, A.elem[i]);
//    }
//}
//
//void UnionSet(const SqList<char>& A, const SqList<char>& B, SqList<char>& C)
//{
//    InitList(C);
//    for (int i = 0; i < A.length; ++i)
//        AppendElem(C, A.elem[i]);
//
//    for (int i = 0; i < B.length; ++i)
//    {
//        if (!LocateElem(C, B.elem[i]))
//            AppendElem(C, B.elem[i]);
//    }
//}
//
//void SubSet(const SqList<char>& A, const SqList<char>& B, SqList<char>& C)
//{
//    InitList(C);
//    for (int i = 0; i < A.length; ++i)
//    {
//        if (!LocateElem(B, A.elem[i]))
//            AppendElem(C, A.elem[i]);
//    }
//}
//
//void ShowMenu()
//{
//    cout << "\n========== 集合运算 ==========" << endl;
//    cout << "1. 输入集合 A 和 B" << endl;
//    cout << "2. 显示当前集合" << endl;
//    cout << "3. 求交集 A∩B" << endl;
//    cout << "4. 求并集 A∪B" << endl;
//    cout << "5. 求差集 A-B" << endl;
//    cout << "0. 退出程序" << endl;
//    cout << "请选择操作：";
//}
//
//int main()
//{
//    SqList<char> A, B, C;
//    InitList(A);
//    InitList(B);
//    InitList(C);
//
//    int choice;
//    do
//    {
//        ShowMenu();
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            InputSet(A, "A");
//            InputSet(B, "B");
//            cout << "集合创建完成（已自动去重）。" << endl;
//            break;
//        case 2:
//            PrintSet(A, "A");
//            PrintSet(B, "B");
//            break;
//        case 3:
//            InterSet(A, B, C);
//            PrintSet(C, "A∩B");
//            break;
//        case 4:
//            UnionSet(A, B, C);
//            PrintSet(C, "A∪B");
//            break;
//        case 5:
//            SubSet(A, B, C);
//            PrintSet(C, "A-B");
//            break;
//        case 0:
//            cout << "程序结束。" << endl;
//            break;
//        default:
//            cout << "输入无效，请重新选择。" << endl;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
#include <iostream>
#include <vector>

struct LNode
{
    int data;
    LNode* next;
};
void InitList(LNode*& L)
{
    L = new LNode;
    L->next = nullptr;
}
bool InsertSortElem(LNode* L, int e)
{
    LNode* s = new LNode;
    if (s == nullptr)
    {
        return false;
    }

    s->data = e;
    LNode* p = L;
    LNode* q = p->next;

    while (q != nullptr && q->data <= e)
    {
        p = q;
        q = q->next;
    }

    s->next = q;
    p->next = s;
    return true;
}

void CreateOrderedList(LNode*& L, const std::vector<int>& nums)
{
    InitList(L);
    for (int x : nums)
    {
        InsertSortElem(L, x);
    }
}

void MergeOrderedList(LNode*& LA, LNode*& LB)
{
    LNode* pa = LA;
    LNode* qa = pa->next;
    LNode* pb = LB;
    LNode* qb = pb->next;

    while (qa != nullptr && qb != nullptr)
    {
        if (qa->data < qb->data)
        {
            pa = qa;
            qa = qa->next;
        }
        else
        {
            pa->next = qb;
            pb->next = qb->next;
            qb->next = qa;
            pa = qb;
            qb = pb->next;
        }
    }

    if (qb != nullptr)
    {
        pa->next = qb;
    }

    delete LB;
    LB = nullptr;
}

void PrintList(LNode* L)
{
    if (L == nullptr || L->next == nullptr)
    {
        std::cout << "空";
        return;
    }

    LNode* p = L->next;
    while (p != nullptr)
    {
        std::cout << p->data;
        if (p->next != nullptr)
        {
            std::cout << ",";
        }
        p = p->next;
    }
}

void DestroyList(LNode*& L)
{
    if (L == nullptr)
    {
        return;
    }

    LNode* p = L;
    while (p != nullptr)
    {
        LNode* q = p->next;
        delete p;
        p = q;
    }
    L = nullptr;
}

void RunCase(const std::vector<int>& a, const std::vector<int>& b)
{
    LNode* LA = nullptr;
    LNode* LB = nullptr;

    CreateOrderedList(LA, a);
    CreateOrderedList(LB, b);

    std::cout << "La: ";
    PrintList(LA);
    std::cout << "\nLb: ";
    PrintList(LB);

    MergeOrderedList(LA, LB);

    std::cout << "\n合并以后 La: ";
    PrintList(LA);
    std::cout << "\n\n";

    DestroyList(LA);
    DestroyList(LB);
}

int main()
{
    std::cout << "===== 有序表合并测试 =====\n\n";

    RunCase({ 11, 22, 33, 44 }, { 1, 13, 17, 39 });
    RunCase({ 11 }, { 1, 13, 17, 39 });
    RunCase({ 11, 22, 33, 44 }, { 1 });
    RunCase({ 11, 22, 33, 44 }, {});
    RunCase({}, { 1, 13, 17, 39 });
    RunCase({}, {});
    RunCase({ 55 }, { 1, 13, 17, 39 });

    return 0;
}