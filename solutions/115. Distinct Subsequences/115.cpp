/*
time complexity: O(m*n)
tags: String, Dynamic Programming
note:
令 dp[i][j] =  numDistinct(s[:i], t[:j])，最終答案為 dp[m][n]
ex:
s = "babgbag", t = "bag"
dp[0][1] = numDistinct("", "b"), dp[1][0] = numDistinct("b", "")
dp[5][3] = numDistinct("babgb", "bag")

1. 定義 dp 初始值： dp[0][0] = 1, dp[i][0] = 1, dp[0][j] = 0
2. 定義 dp 遞迴關係式： dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + dp[i-1][j] : dp[i-1][j]

ex 1:  s = "babgbag", t = "bag"，求 dp[5][3]
因為 s[4] != t[2]，所以 dp[5][3] = dp[4][3]
"babgb" <-> "bag" 等同於  "babg" <-> "bag"

ex 2:  s = "babagag", t = "bag"，，求 dp[5][3]
因為 s[4] == t[2]，所以 dp[5][3] = dp[4][2] + dp[4][3]
dp[4][2]("baba" <-> "ba")
dp[4][3]("baba" <-> "bag")
*/

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        int ans = 0;

        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= n; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (s[i - 1] == t[j - 1])
                               ? dp[i - 1][j - 1] + dp[i - 1][j]
                               : dp[i - 1][j];
            }
        }
        return (int)dp[m][n];
    }
};