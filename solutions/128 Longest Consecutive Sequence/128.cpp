/*
time complexity: O(n)
tags: Array, Hash Table, Union Find
note: 先將所有數字存進 hash set 裏面，接著再遍歷一遍，若該數的上下連續整數有出現在 hash set 裏，就將其從 hash set 中移除，
避免遍歷的過程中重複搜尋。
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 建立 hash set
        unordered_set<int> hashSet;
        for (int i = 0; i < nums.size(); i++)
            hashSet.insert(nums[i]);

        int count = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hashSet.count(nums[i]))
            {
                hashSet.erase(nums[i]);
                count = 1;
            }
            else
                continue;

            // 大於 nums[i] 的數字
            int plus = 1;
            while (hashSet.count(nums[i] + plus))
            {
                hashSet.erase(nums[i] + plus);
                count++;
                plus++;
            }

            // 小於 nums[i] 的數字
            int minus = 1;
            while (hashSet.count(nums[i] - minus))
            {
                hashSet.erase(nums[i] - minus);
                count++;
                minus++;
            }

            if (count > maxCount)
                maxCount = count;
        }
        return maxCount;
    }
};