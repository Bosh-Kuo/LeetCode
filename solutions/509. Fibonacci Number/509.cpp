/*
time complexity: O(n)
tags: Math, Dynamic Programming, Recursion, Memorization
note: f(n) = f(n-1) + f(n-2)，為了避免重複計算，把算過的 f(n-1), f(n-2) 存起來
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int F[30] = {0};
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        else
        {
            if (F[n - 1] == 0)
                F[n - 1] = fib(n - 1);
            if (F[n - 2] == 0)
                F[n - 2] = fib(n - 2);
        }
        return F[n - 1] + F[n - 2];
    }
};

int main()
{
    Solution sol;
    cout << sol.fib(3) << endl;
}