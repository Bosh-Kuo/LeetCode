/*
time complexity: O(m*n)
tags: String, Dynamic Programming
note: follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][j] = lcs of text1[0 ... i-1] & text2[0 ... j-1] (取 text1, text2 前 i, j 個 char)
2. 推導遞迴式: DP[i] = DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise
3. 初始化 DP array: DP[0][0] = DP[1][0] = DP[0][1] = 0
4. 從 i = 1, j = 1 開始 -> i = m, j = n，DP[m][n] 即為答案
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // dpArray[i] represents the longest common subsequence of text1[0 ... i] & text2[0 ... j].
        // DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dpArray(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dpArray[i][j] = dpArray[i - 1][j - 1] += 1;
                else
                    dpArray[i][j] = max(dpArray[i - 1][j], dpArray[i][j - 1]);
            }
        }
        return dpArray[m][n];
    }
};