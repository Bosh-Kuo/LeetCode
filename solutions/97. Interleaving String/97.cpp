/*
time complexity: O(m*n)
tags: String, Dynamic Programming
note: 同註解
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

        // dp[i][j] 表示 s3 前(i+j)個字元組成的 substring 可以由 s1 的前 i 個字元與 s2 的前 j 個字元組成
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // 假設 s2 貢獻 0 個字元
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // 假設 s1 貢獻 0 個字元
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // 當 s1[i-1] == s3[i+j-1]，表示 s3 前(i+j-1)個字元組成的 substring 可能由 s1 的前 i-1 個字元與 s2 的前 j 個字元組成 => dp[i-1][j]
        // 當 s2[j-1] == s3[i+j-1]，表示 s3 前(i+j-1)個字元組成的 substring 可能由 s1 的前 i 個字元與 s2 的前 j-1 個字元組成 => dp[i][j-1]
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m][n];
    }
};
