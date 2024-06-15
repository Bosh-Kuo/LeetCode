/*
time complexity : O(n)
tags: Array, Hash Table
note: 把出現過的數字用 Hash Table 存起來，當他出現第二次就 push 到 Ans
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // idx i 對到的元素表示 i 出現過幾次
        vector<int> hashTable(nums.size() + 1);
        vector<int> Ans;
        for(auto num: nums)
        {
            hashTable[num] += 1;
            if (hashTable[num] == 2)
                Ans.push_back(num);
        }
        return Ans;        
    }
};