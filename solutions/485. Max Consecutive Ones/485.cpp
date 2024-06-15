/*
time complexity : O(n)
tags: Array
note: 若看到 0 就中止連續累積
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        for (auto num: nums)
        {
            if (num == 0)
                count = 0;
            else
                count += 1;
            if (count > max)
                max = count;
        }
        return max;
    }
};