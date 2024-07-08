/*
time complexity : O(mn)
tags: String, Dynamic Programming
note: 定義 dp[i][j] 為 substring word1[0...i-1] 轉換成 substring word2[0,...j-1] 所需最少的操作次數
1. 定義 dp 關係式:
1.1 若 word1[i-1] == word2[j-1] 則 dp[i][j] = dp[i-1][j-1],
ex: "abc" -> "xyzc" 所需的操作數與 "ab" -> "xyz" 相同
1.2 若 word1[i-1] != word2[j-1]，則 dp[i][j] 為以下三者中最小者
1.2.1 將 word1[i-1] 換成 word2[j-1]。所需操作數相當於 dp[i-1][j-1] + 1
ex: "abc" -> "defg" 相當於 "ab" -> "def" 的操作次數 + 1("c"->"g")
1.2.2 將 word1[i-1] 刪除。所需操作數相當於 dp[i-1][j] + 1
ex: "abc" -> "fedcb" 相當於 "ab" -> "fedcb" 的操作次數 + 1(刪除"c")
1.2.3 在 word1[i] 插入 word2[j-1]。所需操作數相當於 dp[i][j-1] + 1
ex: "abc" -> "fedcx" 相當於 "abc" -> "fedc" 的操作次數 + 1(插入"x")

2. base cases:
2.1 dp[i][0] = i, 將 word1[0...i-1] 轉為空字串需要做 i 次的刪除動作
2.2 dp[0][j] = j, 將空字串轉成 word2[0...j-1] 需要做 j 次的插入動作
*/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // base cases
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        // find min dp[i][j]
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};