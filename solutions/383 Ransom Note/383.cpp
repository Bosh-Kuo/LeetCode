/**
time complexity: O(n)
tags: Hash Table, String, Counting
note: 把 magazine 所有字母出現的數字用 hashtable 記起來，對照 ransomNote，若找不到或者對應的數值為 0 回傳 false
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> hashmap;
        for (char c : magazine)
        {
            if (hashmap.count(c))
                hashmap[c] += 1;
            else
                hashmap[c] = 1;
        }
        for (char c : ransomNote)
        {
            if (hashmap[c] > 0 && hashmap.count(c))
                hashmap[c] -= 1;
            else
                return false;
        }
        return true;
    }
};