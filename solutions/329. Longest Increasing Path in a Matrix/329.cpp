/*
time complexity: O(m*n)
tags: Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Topological Sort, Memoization, Matrix
note: 每個位置的 LIP 可以由周遭元素的 LIP 推論。利用 Topological Sort 的概念，將 in degree 為 0 的元素逐個解決，最後一輪才處理的元素即為 LIP
1. 建立 vector<vector<int>>，紀錄每個位置的 inDegree
2. 建立 LIP vector<vector<int>>，紀錄每個位置的 longest increasing
3. 把 inDegree 為 0 的座標 push 入 queue
4. while(!queue.empty()): 將 queue 中的座標 pop 出，若該座標周圍元素比該座標大，且LIP <= 該座標的 LIP，令鄰近座標的 LIP = 該座標 LIP + 1
5. 找出LIP 最大者
*/

class Solution
{
public:
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        // 1. 建立 indegree vector<vector<int>>，紀錄每個位置的 indegree
        // 2. 建立 LIP vector<vector<int>>，紀錄每個位置的 longest increasing
        // path
        // 3. 把 indegree 為 0 的座標 push 入 queue
        // 4. while(!queue.empty()): 將 queue 中的座標 pop 出
        // 若該座標周圍元素比該座標大，且LIP <= 該座標的 LIP，令鄰近座標的 LIP =
        // 該座標 LIP + 1
        // 5. 找出LIP 最大者

        int m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        vector<vector<int>> inDegree(m, vector<int>(n, 0));
        vector<vector<int>> LIP(m, vector<int>(n, 1));
        queue<pair<int, int>> pendingQueue;

        // initialize inDegree
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (auto &dir : direction)
                {
                    int x = dir.first + i;
                    int y = dir.second + j;
                    if (x >= 0 && x < m && y >= 0 && y < n)
                        inDegree[i][j] += (matrix[x][y] < matrix[i][j] ? 1 : 0);
                }
                if (inDegree[i][j] == 0)
                    pendingQueue.push({i, j});
            }
        }

        while (!pendingQueue.empty())
        {
            pair<int, int> coord = pendingQueue.front();
            pendingQueue.pop();
            for (auto &dir : direction)
            {
                int x = coord.first, y = coord.second;
                int targetX = dir.first + x, targetY = dir.second + y;
                if (targetX >= 0 && targetX < m && targetY >= 0 &&
                    targetY < n)
                {
                    if (matrix[x][y] < matrix[targetX][targetY])
                    {
                        LIP[targetX][targetY] =
                            max(LIP[targetX][targetY], LIP[x][y] + 1);
                        inDegree[targetX][targetY]--;

                        if (inDegree[targetX][targetY] == 0)
                            pendingQueue.push({targetX, targetY});
                    }

                    ans = max(ans, LIP[targetX][targetY]);
                }
            }
        }
        return ans;
    }
};