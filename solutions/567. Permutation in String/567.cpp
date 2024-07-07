/*
time complexity : O(n)
tags: Hash Table, Two Pointers, String, Sliding Window
note: 以 s1.size() 為 window(in s2) size，紀錄 window 中每個 char 出現次數是否跟 s1 相同
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        if (n > m)
            return false;

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // Count frequency of each character in s1
        for (int i = 0; i < n; ++i)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Check if the initial window matches
        if (s1Count == s2Count)
            return true;

        // Use sliding window to check remaining substrings
        for (int i = n; i < m; ++i)
        {
            s2Count[s2[i] - 'a']++;
            s2Count[s2[i - n] - 'a']--;

            if (s1Count == s2Count)
                return true;
        }

        return false;
    }
};