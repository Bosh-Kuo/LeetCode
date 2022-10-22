/*
time complexity: O(log(n))
tags: Math, Recursion
note: 把問題轉換成 myPow(x*x, n/2) 可以把 recursive call 的次數降低到 log(n)，否則會 stack overflow
*/

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n < 0)
        {
            n = abs(n);
            x = 1/x;
        }
        if (n % 2 == 0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x*x, n/2);
    }
};


int main()
{
    Solution sol;
    cout << sol.myPow(5, -3);
}