/*
time complexity: O(n)
tags: Array, Hash Table, Two Pointers, Binary Search, Sorting
note: 先用一個 Hash Table 存下比較短的 array 的 element 以及出現過的次數，這樣可以用比較少的記憶體。接著以比較長的 array 來跟 hash table 比對
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> hashTable;
        vector<int> &longOne = nums1.size() >= nums2.size() ? nums1 : nums2;
        vector<int> &shortOne = nums1.size() >= nums2.size() ? nums2 : nums1;
        for (int i = 0; i < shortOne.size(); i++)
        {
            if (hashTable.count(shortOne[i]))
                hashTable[shortOne[i]]++;
            else
                hashTable[shortOne[i]] = 1;
        }
        for (int i = 0; i < longOne.size(); i++)
        {
            if (hashTable[longOne[i]] > 0)
            {
                ans.push_back(longOne[i]);
                hashTable[longOne[i]]--;
            }
        }
        return ans;
    }
};