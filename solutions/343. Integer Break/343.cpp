/*
time complexity: O(n^2)
tags: Math, Dynamic Programming
note: follow DP 問題 5 步驟：
1. 定義 DP array: DP[i] = 拆分數字 i 可以得到的最大乘積
2. 推導遞迴式: i = (i-j) + (j)
DP[i] = max(DP[i-j] * j (其中一項是經拆解過的最大乘積), j * (i-j) (兩項都不經拆解)
3. 初始化 DP array: DP[0], DP[1]無法定義，從 DP[2] = 1 開始
4. 確認遍歷順序: i from 2 to n, j from 1 to i/2
5. 舉例驗證 DP array: n = 10
DP[2] = 1, DP[3] = 2, DP[4] = 4, DP[5] = 6, DP[7] = 12
DP[8] = 18, DP[9] = 24, DP[10] = 36
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> DP(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                DP[i] = max({DP[i], DP[i - j] * j, (i - j) * j});
            }
        }
        return DP[n];
    }
};