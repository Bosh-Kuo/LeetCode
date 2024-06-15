/*
time complexity: O(n)
tags: Math
note: 最後要檢查是否超過 32-bit integer range
參考： https://leetcode.com/problems/reverse-integer/solutions/3099545/my-c-solution-beats-100-0ms-run-time/
*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long r = 0;
        while (x)
        {
            r = r * 10 + x % 10; // find reminder and add its to r
            x = x / 10;          // Update the value of x
        }
        if (r > INT_MAX || r < INT_MIN)
            return 0; // check 32 bit range
        return int(r);
    }
};