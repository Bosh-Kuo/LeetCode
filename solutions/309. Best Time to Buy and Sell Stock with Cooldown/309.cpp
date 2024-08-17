/*
time complexity: O(n)
tags: Array, Dynamic Programming
note: 每個時間點有 3 種狀態：持有/空手/賣出，每個狀態在當下時間的最大值關係式如下：
1. dp_hold[i] = max(dp_cool[i-1] - prices[i-1], dp_hold[i-1]);  // 在 i 時間持有
2. dp_cool[i] = max(dp_cool[i-1], dp_sell[i-1]); // 在 i 時間空手
3. dp_sell[i] = dp_hold[i-1] + prices[i-1]; // 在 i 時間賣出
由於 dp 以 i = 1 起算，因此將 prices 向前平移一單位
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int ans = 0;
        vector<int> dp_hold(n + 1);
        vector<int> dp_cool(n + 1);
        vector<int> dp_sell(n + 1);
        dp_hold[0] = INT_MIN;
        dp_cool[0] = 0;
        dp_sell[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp_hold[i] = max(dp_cool[i - 1] - prices[i - 1], dp_hold[i - 1]); // 在 i 時間持有
            dp_cool[i] = max(dp_cool[i - 1], dp_sell[i - 1]);                 // 在 i 時間空手
            dp_sell[i] = dp_hold[i - 1] + prices[i - 1];                      // 在 i 時間賣出
        }

        return max(dp_cool[n], dp_sell[n]);
    }
};
