/*
time complexity : O(n)
tags: Array
note: 檢查每個元素的位數
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num: nums)
        {
            if ((int)log10(num) % 2 != 0)
                count ++;
        }
        return count;
    }
};