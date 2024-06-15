/*
time complexity: O(n)
tags: Array, Dynamic Programming, Breadth-First Search
note: 以範例 coins = [1,2,5], amount = 11 來舉例， 11 可透過 1+10, 2+9, 5+6 組成，那麼題目就變成了
找出 amount = 10/9/6 時所需硬幣最少者。
1. 定義 dp array: dp[i] = amount == i 時所需做少的 coins 數量，可為 -1 or 0
2. 定義 dp 方程式: dp[i] = min(1 + dp[i-coins[j]] )
3. 初始化 dp array: dp[0] == 0，
4. 推導邏輯：
- 當 coin[j] = 10, amount = 5 時，顯然幣值為 10 的硬幣不可能組成 5，可以直接跳過
- 檔 coins = [2] => dp[0] = 0, dp[1] = -1, dp[2] = 1, amount = 3 時， dp[3-2] = -1，因此 幣值為 2 的硬幣不可能用來組成3
*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        // 定義 dp array: dp[i] = amount == i 時所需做少的 coins 數量
        vector<int> dp(amount + 1);

        // 定義 dp 方程式: dp[i] = min(1 + dp[i-coins[j]] )
        for (int i = 1; i <= amount; i++)
        {
            int minDpValue = -1;
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] > i)
                    continue;
                int dpValue = dp[i - coins[j]];
                if (dpValue == -1)
                    continue; // 例如 coins = [2,3], i = 3, j = 0 => dp[3-2] = -1，也就是 coins[0] 不可能組成 3
                else
                {
                    if (minDpValue == -1)
                        minDpValue = dpValue + 1;
                    else
                        minDpValue = dpValue + 1 < minDpValue ? dpValue + 1 : minDpValue;
                }
            }
            dp[i] = minDpValue;
        }
        return dp[amount];
    }
};