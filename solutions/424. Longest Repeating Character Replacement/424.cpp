/*
time complexity: O(n)
tags: String, Hash Table, Sliding Window
note: 參考 https://leetcode.com/problems/longest-repeating-character-replacement/solutions/4200234/o-n-c-step-by-step-explanation/?envType=list&envId=ox36ed4d
使用 sliding window 界定當下可轉換成相同 char 的最長 substring，並記錄在 sliding window 中最常出現的 char 的出現次數 maxf
當 sliding window 長度 - maxf > k 時表示 sliding window 以無法容納更多 char，長度無法繼續擴增，因此將左邊界右移，
直到滿足 sliding window 長度 - maxf <= k 的條件 sliding window 的長度才可以繼續增長
*/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0;
        int ans = 0;
        int maxf = 0; // 表示在 sliding window 內最常出現的 char 的出現次數
        unordered_map<char, int> charFreqTable;

        for (right; right < s.size(); right++)
        {
            charFreqTable[s[right]] += 1;
            maxf = max(maxf, charFreqTable[s[right]]);
            int windowLength = right - left + 1;
            if (windowLength - maxf > k) // 表示 sliding window 能容納的非連續 char 已超過 k 個
            {
                // 左邊界向右移
                charFreqTable[s[left]] -= 1;
                left += 1;
            }
            else
            {
                ans = max(ans, windowLength);
            }
        }
        return ans;
    }
};