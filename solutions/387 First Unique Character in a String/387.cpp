/*
time complexity: O(n)
tags: Hash Table, String, Queue, Counting
note: 用 hashtable 存下每個字母出現的次數
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> hashTable;
        for (int i = 0; i < s.length(); i++)
        {
            if (!hashTable.count(s[i]))
                hashTable[s[i]] = 1;
            else
                hashTable[s[i]] += 1;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (hashTable[s[i]] < 2)
                return i;
        }
        return -1;
    }
};