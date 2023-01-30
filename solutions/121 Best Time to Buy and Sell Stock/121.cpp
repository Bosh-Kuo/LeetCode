/*
time complexity: O(n)
tags: Array, Dynamic Programming
note:
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][0] = 第 i 天的最低股票成本，DP[i][1] = 第 i 天的最高的收益
2. 推導遞迴式: DP[i][0] = min(DP[i-1][0], price[i]), DP[i][1] = max(DP[i-1][1], price - DP[i][0])
3. 初始化 DP array: DP[0][0] = price[0], DP[0][1] = 0 (當天就賣掉)
4. 確認遍歷順序: i = 1 to i = n
5. 舉例驗證 DP array: price = [3,2,7,1,8]
DP[0][0] = 3, DP[0][1] = 0,
DP[1][0] = 2, DP[1][1] = 0,
DP[2][0] = 2, DP[2][1] = 5,
DP[3][0] = 1, DP[3][1] = 5,
DP[4][0] = 1, DP[4][1] = 7,
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minCost = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }
        return maxProfit;
    }
};