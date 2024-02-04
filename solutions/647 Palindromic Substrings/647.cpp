/*
time complexity: O(n^2)
tags: String, Dynamic Programming
note: 找出每種可能的 subString，判斷該 subString 是否為回文，是的話總數 += 1
遍歷所有可能的 subString 的時間複雜度為 O(n^2)
檢核一字串是否為回文的時間複雜度為 O(n) => 利用該字串中已經計算過的 subString 的結果來推論該字串是是否為回文可將時間複雜度降到 O(1)
判斷 s[i] to s[j]: 可利用 s[i+1] ~ s[j-1] 的判斷結果來推論
*/

class Solution
{
public:
    int countSubstrings(string s)
    {
        // table[i][j] = s[i] ~ s[j] 是否為回文，是的話為 1，不是的話為 0
        vector<vector<int>> table(s.size(), vector<int>(s.size()));
        int count = 0;
        // 檢查所有可能的 subString，若該 subString 為 palindromic， count += 1
        for (int right = 0; right < s.size(); right++)
        {
            for (int left = 0; left <= right; left++)
            {
                if (left == right)
                    table[left][right] = 1;
                else if (left == right - 1)
                    table[left][right] = s[left] == s[right] ? 1 : 0;
                else
                    table[left][right] = s[left] == s[right] ? table[left + 1][right - 1] : 0;
                count += table[left][right];
            }
        }
        return count;
    }
};