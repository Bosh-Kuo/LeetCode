/*
time complexity: O(n)
tags: Hash Table, Math, String
note:
*/

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanToNum = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int number = 0;
        for (int i = 0; i < s.size(); i++)
        {
            number += romanToNum[s[i]];
            if (i > 0 && romanToNum[s[i]] > romanToNum[s[i - 1]])
                number -= 2 * romanToNum[s[i - 1]];
        }
        return number;
    }
};