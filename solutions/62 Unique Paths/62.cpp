/*
time complexity: O(m*n)
tags: Math, Dynamic Programming, Combinatorics
note: follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][j] = 到達 (i,j) 最多的可能路徑數
2. 推導遞迴式: DP[i][j] = DP[i][j-1] + DP[i-1][j]
3. 初始化 DP array: DP[0][0] ~ DP[0][n] = 1，DP[0][0] ~ DP[m][0] = 1
4. 確認遍歷順序: 從 i = 0 開始由左至右遍歷
5. 舉例驗證 DP array: m = 3, n = 2
DP[0][0] = 1, DP[0][1] = 1
DP[1][0] = 1, DP[1][1] = 2
DP[2][0] = 1, DP[2][1] = 3
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> row_i(n, 1);
        for(int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                row_i[j] = row_i[j-1] + row_i[j];
            }
        }
        return row_i[n-1];
    }
};

int main()
{
}