/*
time complexity : O(m*n)
tags: Array, Bread-First Search, Matrix
note:
1. 掃一次 grid，將 rotten oranges 存進 queue，並紀錄 fresh oranges 數量
2. 若一開始就沒 fresh orange，直接回傳 0
3. 以 bfs 每一分鐘處理 numRotten 個格子
*/

class Solution
{
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int minute = 0;
        int numFresh = 0, numRotten = 0;
        queue<pair<int, int>> q;

        // 掃一次 grid，將 rotten oranges 存進 queue，並紀錄 fresh oranges 數量
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    numFresh++;
                else if (grid[i][j] == 2)
                {
                    numRotten++;
                    q.push(make_pair(i, j));
                }
            }
        }

        // 若一開始就沒 fresh orange，直接回傳 0
        if (numFresh == 0)
            return 0;

        // 每一分鐘處理 numRotten 個格子
        while (numRotten > 0)
        {
            minute++;
            int newNumRotten = 0;
            for (int i = 0; i < numRotten; i++)
            {
                pair<int, int> coord = q.front();
                q.pop();
                for (auto direction : directions)
                {

                    int x = coord.first + direction.first;
                    int y = coord.second + direction.second;
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    else
                    {
                        if (grid[x][y] == 1)
                        {
                            numFresh--;
                            newNumRotten++;
                            grid[x][y] = 2;
                            q.push(make_pair(x, y));
                        }
                    }
                }
            }
            numRotten = newNumRotten;
        }

        if (numFresh != 0)
            return -1;
        else
            return minute - 1;
    }
};