/*
time complexity: O(n)
tags: Math, Dynamic Programming, Recursion, Memorization
note: n 階的階梯可以透過從第 n-1 階再走一階或從第 n-2 階再走兩階達到，為了避免重複計算，把算過的 C(n-1), C(n-2) 存起來
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int C[45] = {0};
    int climbStairs(int n) {
        if (n==1)
        {
            C[n] = 1;
            return C[n];
        }
        else if (n==2)
        {
            C[n] = 2;
            return C[n];
        }                
        else
        {
            if (C[n-1] == 0)
                C[n-1] = climbStairs(n-1);
            if (C[n-2] == 0)
                C[n-2] = climbStairs(n-2);
            return C[n-1] + C[n-2];
        }            
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(45) << endl;
}