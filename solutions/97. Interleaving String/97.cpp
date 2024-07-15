/*
time complexity: O(m*n)
tags: String, Dynamic Programming
note:
*/

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length();
        if (m + n < s3.length())
            return false;

        // 假設 n <= m
        if (m < n)
            return isInterleave(s2, s1, s3);

        // dp[j] 表示 s3 前(i+j)個字元組成的 substring 可以由 s1 的前 i 個字元與 s2 的前 j 個字元組成
        // 當 s1[i-1] == s3[i+j-1]，表示 s3 前(i+j-1)個字元組成的 substring 可能由 s1 的前 i-1 個字元與 s2 的前 j 個字元組成 => dp[j]
        // 當 s2[j-1] == s3[i+j-1]，表示 s3 前(i+j-1)個字元組成的 substring 可能由 s1 的前 i 個字元與 s2 的前 j-1 個字元組成 => dp[j-1]
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; ++j)
        {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; ++i)
        {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j)
            {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n];
    }
};
