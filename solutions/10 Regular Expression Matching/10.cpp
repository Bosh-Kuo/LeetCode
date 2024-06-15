/*
time complexity: O(n*m)
tags: String, Dynamic Programming, Recursion
note:
. 表示 match 任意 char
* 表示 match 0 或多個前面一個 char:
"a*" 可 match "a", "aa", "aaa", ....
".*" 可 match ".", "..", "...", ....
*/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        // dp[i][j] 表示字串 s 的前 i 個字符和模式 p 的前 j 個字符是否匹配。
        // 整個 dp 陣列的大小是 (m+1) x (n+1)，其中 m 是字串 s 的長度，n 是模式 p 的長度。
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // 初始化: dp[0][0] 為 true，表示空字串與空模式是匹配的。
        dp[0][0] = true;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 處理 '*' 字符: 如果模式的第 j 個字符 p[j - 1] 是 '*'，那麼有兩種情況可以使 dp[i][j] 為真：
                if (p[j - 1] == '*')
                {
                    // 1. 匹配零個前面的元素，忽略這個 '*' 和它前面的字符，這時 dp[i][j] = dp[i][j - 2]。
                    // ex: s = "aa", p = "aac*", 在 "*" 匹配零個 'c' 時，dp[2][4] = dp[2][2] = true。
                    bool condition1 = dp[i][j - 2];

                    // 2. '*' 匹配前面的字符時(模式第 j - 1 個字符 p[j - 2] 跟字串第 i 個字符 s[i - 1] 相同)，
                    // 這時 dp[i][j] = dp[i - 1][j] (即忽略剛剛匹配成功的字串第 i 個字符 s[i - 1]，繼續往前匹配字串第 i-1 個字符 s[i - 2])
                    // ex: s = "aaa", p = "a*", 在 "*" 匹配前個 'a' 時(s[3-1] == p[2 - 2])，dp[3][2] = dp[2][2] => 比對 s = "aa" 與 p = "a*"
                    bool condition2 = i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');

                    dp[i][j] = condition1 || condition2;
                }
                // 當模式的第 j 個字符 p[j - 1] 不是 '*'，是普通字符或 '.' 時：
                else
                {
                    // 檢查字串第 i 個字符 s[i - 1] 是否與模式的第 j 個字符  p[j - 1] 匹配
                    // 若是，則 dp[i][j] = dp[i-1][j-1]
                    // ex: s = "ca", p = "ba"，此時 dp[2][2] = dp[1][1] = true。
                    if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
