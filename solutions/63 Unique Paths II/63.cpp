/*
time complexity: O(m*n)
tags: Array, Dynamic Programming, Matrix
note: follow DP 問題 5 步驟：
1. 定義 DP array: DP[i][j] = 到達 (i, j) 位置的可能路徑數
2. 推導遞迴式:
DP[i][j] = DP[i-1][j] + DP[i][j-1] (if obstacleGrid[i][j] != 1)，
DP[i][j] = 0 (if obstacleGrid[i][j] == 1)
3. 初始化 DP array: DP[0][0] ~ DP[0][n] = 1, DP[0][0] ~ DP[m][0] = 1 (if obstacleGrid[i][j] != 1)
4. 確認遍歷順序: 從 i = 0 to m，由左至右遍歷
5. 舉例驗證 DP array: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
DP[0][0] = 1, DP[0][1] = 1, DP[0][2] = 1
DP[1][0] = 1, DP[1][1] = 0, DP[1][2] = 1
DP[1][0] = 1, DP[1][1] = 1, DP[1][2] = 2
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<int> row_i;
        // initialize(i = 0)
        for (int j = 0; j < obstacleGrid[0].size(); j++)
        {
            if (obstacleGrid[0][j] == 1 || (j > 0 && row_i[j - 1] == 0))
                row_i.push_back(0);
            else
                row_i.push_back(1);
        }

        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                    row_i[j] = 0;
                else
                {

                    if ((j > 0 && obstacleGrid[i][j - 1] == 1) || (j == 0 && row_i[j] != 0))
                        row_i[j] = row_i[j];
                    else
                    {
                        if (j > 0)
                            row_i[j] = row_i[j] + row_i[j - 1];
                        else
                            row_i[j] = 0;
                    }
                }
            }
        }
        return row_i[obstacleGrid[0].size() - 1];
    }
};

int main()
{
}