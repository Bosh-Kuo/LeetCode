/*
time complexity: O(n)
tags: Array, Dynamic Programming, Greedy
note: 直覺會想將 DP[i] 定義為前 i 天可獲得的最大利潤，但實際上前 i 天的最大利潤並不能幫助推導第 i+1 天的最大利潤。
但第 i 天擁有現金卻可以幫助推導第 i+1 天擁有的現金，前提是我們得先接受再持有股票狀態下現金可能為負的觀念
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][0] = 第 i 天持有股票情況下擁有的現金， DP[i][1] = 第 i 天不持有股票情況下擁有的現金
2. 推導遞迴式:
DP[i][0] = max(DP[i-1][0], DP[i-1][1] - price[i])
DP[i][1] = max(DP[i-1][1], DP[i-1][0] + price[i])
3. 初始化 DP array: DP[0][0] = -price[0], DP[0][1] = 0
4. 確認遍歷順序:  i = 0 ~ n，最後取 DP[n-1][1]
5. 舉例驗證 DP array: price = [7,1,5,3,6,4]
DP[0][0] = -7, DP[0][1] = 0
DP[1][0] = -1, DP[1][1] = 0
DP[2][0] = -1, DP[2][1] = 4
DP[3][0] = 1,  DP[3][1] = 4
DP[4][0] = 1,  DP[4][1] = 7
DP[5][0] = 3,  DP[4][1] = 7
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
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < n; i++)
        {
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i]);  // dp[1]: 今天
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);  // dp[0]: 昨天
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[1][1];
    }
};