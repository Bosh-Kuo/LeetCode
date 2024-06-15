/*
time complexity: O(n)
tags: Array, Hash Table
note: 用 unordered set 作為 hash table 紀錄已經看過的數，再從 1 掃到 n，若沒有出現在 hash table 就加入 Ans
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> Ans;
        unordered_set<int> taken;
        for (auto num: nums)        
            taken.insert(num);
        for (int i = 1; i <= nums.size(); i++)
        {
            if(taken.count(i) == 0)
                Ans.push_back(i);
        }
        return Ans;
    }
};