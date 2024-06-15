/*
time complexity: O(n)
tags: Array, Hash Table, String, Sorting
note: 用 unordered_map 實作 hash map，把 strs 中的每個字串經過 sort 後作為 key，而原本的值作為 value，value 可以存在一個 vector 裏。
這樣可以讓不同字串共用同一個 key，最後把 hash table 的 key value pairs 逐個拿出
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> Ans;
        unordered_map<string, vector<string>> hashmap;
        for (auto str: strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            hashmap[sortedStr].push_back(str);
        }
        for (auto map: hashmap)
            Ans.push_back(map.second);
        return Ans;
    }
};
