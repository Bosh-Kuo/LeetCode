/*
time complexity: O(n)
tags: Math, Bit Manipulation, Recursion
note: 用 Recursion 把 kthGrammar(N, K) 簡化成 kthGrammar(N-1, prevK) (+ 1 or -1) 要處理的 row 的長度就會越來越短
*/
#include <iostream>
using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int lastRow = kthGrammar(n - 1, (k + 1) / 2);

        // 0 1 1 "0"
        // 0 1 1 0 1 0 0 "1"
        if ((k + 1) % 2 != 0)
            return lastRow == 0 ? 1 : 0;
        else
            return lastRow;
    }
};

int main()
{
    Solution sol;
    cout << sol.kthGrammar(2, 2);
}