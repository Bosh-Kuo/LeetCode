/*
time complexity: O(n)
tags: Array, Dynamic Programming
note: follow DP 問題 5 步驟：
1. 定義 DP array: DP[i] = 到達第 i 層所花費最少的體力
2. 推導遞迴式: DP[i] = min(DP[i-1] + cost[i-1], DP[i-2] + cost[i-2])
3. 初始化 DP array: 因題目敘述可以從第 0 階或是第 1 階開始，表示到達第 0 OR 1 階是不用花力氣的，所以 DP[0] = 0, DP[1] = 0
4. 確認遍歷順序: 因 DP[i] 由 DP[i-1] and DP[i-2] 推導出，因此從 0 遍歷到 n
5. 舉例驗證 DP array: ex:
cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1],
DP =   [0,   0, 1, 2, 2,   3, 3, 4,   4, 5, 6]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int ans = 0, dp_0 = 0, dp_1 = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            int dp_i = min(dp_0 + cost[i - 2], dp_1 + cost[i - 1]);
            dp_0 = dp_1;
            dp_1 = dp_i;
        }
        return dp_1;
    }
};