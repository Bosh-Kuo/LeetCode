/*
time complexity: O(n*m), n = coins.size(), m = amount
tags: Array,  Dynamic Programming
note: 當我們在第 i 個硬幣位置時，我們有兩個選擇：取 or 不取
1. 定義 dp[i][j]: 表示用前 i 個硬幣湊出金額 j 的方案數，若金額為 0，則方案數為 1（不取任何硬幣）。。
2.1 不取當前硬幣的情況：dp[i][j] = dp[i-1][j]，即用前 i-1 個硬幣湊出金額 j 的方案數。
2.2 取當前硬幣的情況：若 j >= coins[i-1]，則 dp[i][j] = dp[i][j - coins[i-1]]，
即用當前硬幣湊出金額 j-coins[i-1] 的方案數。
3. 返回結果：dp[n][amount] 即為使用所有硬幣湊出金額 amount 的方案數。
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // 初始化 DP 表格
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // 若金額為 0，則只有一種方案（不取任何硬幣）
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 1;
        }

        // 填充 DP 表格
        // 填充 DP 表格
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                // 不取當前硬幣的情況
                int notTake = dp[i - 1][j];
                // 取當前硬幣的情況
                int take = j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0;
                dp[i][j] = notTake + take;
            }
        }

        return dp[n][amount];
    }
};
