/*
time complexity : O(n)
tags: Array, Hash Table, Two Pointers, Binary Search, Sorting
note: 用 unordered_map 作為 hash table 存下個元素作為 key，由於 unordered_map 查詢的複雜度為 O(1)， 因此選用 unordered_map 而非 map
當前元素 * 2 or 當前元素 / 2 出現在 hash table 中就回傳 true
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, bool> hashTable;
        for (int i = 0; i < arr.size(); i++)
        {
            // 若前面有出現該元素乘 2 或除 2 的值就回傳 true
            if (hashTable.count(arr[i] * 2) || (arr[i] % 2 == 0 && hashTable.count(arr[i] / 2)))
                return true;

            hashTable[arr[i]] = true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10,2,3,3};
    cout << sol.checkIfExist(arr);
}