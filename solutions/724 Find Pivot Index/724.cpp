/*
time complexity: O(n)
tags: Array, Prefix Sum
note: 紀錄每個位置的 Prefix Sum，若 Sum - Prefix Sum - 該元素 （右半邊）等於 Prefix Sum （左半邊）就回傳該元素 index
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, prefixSum = 0;
        for (auto num: nums)
            sum += num;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum - prefixSum - nums[i] == prefixSum)
                return i;
            
            prefixSum += nums[i];
        }
        return -1;
    }
};