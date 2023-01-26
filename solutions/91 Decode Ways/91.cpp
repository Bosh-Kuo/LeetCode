/*
time complexity:
tags: String, Dynamic Programming
note: 前一個字符是否是與其他數字組成十位數，會影響當前字符解碼的可能性
follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][0] = 第 i 個 char 為單獨一個位數時的所有組合數， DP[i][1] = 第 i 個 char 為一個十位數字的個位數時的所有組合數
2. 推導遞迴式:
if s[i] != '0': DP[i][0] = DP[i-1][0] + DP[i-1][1]
if s[i] == '0': DP[i][0] = 0
if (s[i-1] == '1') or (s[i-1] == '2' and s[i] in ['0', '6']): DP[i][1] = DP[i-1][0] else DP[i-1] = 0
3. 初始化 DP array: DP[0][0] = 1 if s[0] != '0', DP[0][1] = 0
4. 確認遍歷順序:  i = 0 ~ n，最後取 DP[n][0] + DP[n][1]
5. 舉例驗證 DP array: s = "226"
DP[0][0] = 1, DP[0][1] = 0
DP[1][0] = 1, DP[1][1] = 1
DP[2][0] = 2, DP[2][1] = 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = s[0] != '0' ? 1 : 0;
        dp[0][1] = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (dp[0][0] + dp[0][1] == 0)
                return 0;

            // 處理 dp[1][0]
            if (s[i] != '0')
                dp[1][0] = dp[0][0] + dp[0][1];
            else
                dp[1][0] = 0;

            // 處理 dp[1][1]
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
                dp[1][1] = dp[0][0];
            else
                dp[1][1] = 0;

            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[0][0] + dp[0][1];
    }
};