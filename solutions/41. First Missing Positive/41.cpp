/*
time complexity: O(n)
tags: Array, Hash Table
note: 用 unordered set 作為 hash table 紀錄已經看過的數，若 smallestMissing 出現在 hash table 裡面 smallestMissing 就加一，直到 smallestMissing 不在 hash table 裡面
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> taken;
        int smallestMissing = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            taken.insert(nums[i]);
            while(taken.count(smallestMissing) == 1)
                smallestMissing ++;
        }
        return smallestMissing;
    }
};