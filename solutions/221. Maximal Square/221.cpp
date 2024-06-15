/**
time complexity: O(n)
tags: Array, Dynamic Programming, Matrix
note: 由於從左上往右下遍歷，因此關注當前所在的位置的左、上、左上三個角落，判斷是否可以構成面積更大的正方形。
當這三個角落其中一者為 0，則該位置面積為 matrix 上標記的數字。若三個角落都大於 0，則可構成的最大正方形面積取決於
這三個角落分別能構成的正方形中的最小邊長。
*/

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int max = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 < 0 || j - 1 < 0)
                    dp[i][j] = matrix[i][j] - '0';
                else
                {
                    if (matrix[i][j] == '0')
                        dp[i][j] = 0;
                    else
                    {
                        int length = (int)(min({sqrt(dp[i - 1][j]), sqrt(dp[i][j - 1]), sqrt(dp[i - 1][j - 1])})) + 1;
                        dp[i][j] = length * length;
                    }
                }
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max;
    }
};