/*
time complexity: O(n)
tags: Array, Hash Table, Prefix Sum
note:
1. 紀錄每個 index 0 & 1 個數差(#0 - #1)
2. 用 hashmap紀錄(#0 - #1)最早發生的 index
3. 當計算 index i 之(#0 - #1)有存在 hashmap， i - hashmap[(#0 - #1)] 即為一段滿足 contiguous array 定義的範圍
*/

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        // 紀錄每個 index 0 & 1 個數差(#0 - #1)
        int diff = 0;
        int ans = 0;
        // 紀錄(#0 - #1)最早發生的 index
        // index = 0 之前 (#0 - #1) 為 0
        unordered_map<int, int> seen{{0, -1}};
        for (int i = 0; i < nums.size(); i++)
        {
            diff += nums[i] == 0 ? 1 : -1;
            if (seen.count(diff))
                ans = max(ans, i - seen[diff]);
            else
                seen[diff] = i;
        }
        return ans;
    }
};