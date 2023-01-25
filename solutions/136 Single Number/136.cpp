/*
time complexity: O(n)
tags: Array, Bit Manipulation
note: 用到 Bitwise XOR ^: 0 ^ 0 = 0, A ^ A = 0, 0 ^ A = A, A ^ 0 = A
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }
};