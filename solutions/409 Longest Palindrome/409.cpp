/*
time complexity:
tags: Hash Table, String, Greedy
note: 若一 char 出現次數為奇數 n ，只會出現在 longest palindrome 中 n - 1 次
此外，整個 longest palindrome 允許一個 char 出現奇數次
*/

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        int odd = 0;
        unordered_map<char, int> charMap;
        for (auto c : s)
        {
            if (charMap.count(c))
                charMap[c] += 1;
            else
                charMap[c] = 1;
        }

        for (const auto &pair : charMap)
        {
            if (pair.second % 2 == 0)
                ans += pair.second;
            else
            {
                odd = 1;
                ans += pair.second - 1;
            }
        }
        return ans + odd;
    }
};