#include <iostream>
using namespace std;
int MaxSubseqSum01(int List[], int n)
{
    int ThisSum = 0; int MaxThisSum = 0;
    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= n-1; j++)
        {
            ThisSum = 0;
            for (int k = i; k <= j; k++)
            {
                ThisSum += List[k];
                if (ThisSum > MaxThisSum)
                    MaxThisSum = ThisSum;
                
            }
        }
    }
    return MaxThisSum;
}
int main()
{
    int K;
    cin >> K;
    int *List=new int[K];
    for (int i = 0; i < K; i++)
        cin >> List[i];
    cout << MaxSubseqSum01(List, K);
    return 0;
}