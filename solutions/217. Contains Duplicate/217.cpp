/*
time complexity: O(n)
tags: Array, Hash Table, Sorting
note: 用 unorder_set 作為 hash table 儲存已存在的數字
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> hashTable;
        for(int i = 0; i < nums.size(); i ++)        
            hashTable.insert(nums[i]);
        return hashTable.size() < nums.size();                
    }
};