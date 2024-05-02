/*
time complexity: O(m*n)
tags: Array, Dynamic Programming, Breadth-First Search, Matrix
note: 參考 topological sort 的概念，逐層破解
1. 先處理等於 0 的 cells，並將四周等於 1 的 cells 一併計算好距離後加入 queue
2. 持續將 queue 中的 cells 拿出來，計算周圍等於 1 的 cells，並加入 queue
3. 直到 queue 為空時回傳 ans
*/

class Solution
{
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool inRange(int x, int y, int m, int n)
    {
        if (x >= 0 && x < m && y >= 0 && y < n)
            return true;
        else
            return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // 若一個 cell 為 1 且四周完全沒有 0，則必須依賴四周的 cell 來論自己的離
        // 0 的最短距離 先把 0 的 distance 都標記好，並把這批 0 周圍的 1 放進
        // queue 等待處理， 處理 queue 中的 cell 時，一邊標記周圍還沒處理過的
        // 1，一邊把這些 1 放進 queue 等待處理

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // 先標記好等於 0 的 cells
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    for (auto &dir : directions)
                    {
                        int x = i + dir.first;
                        int y = j + dir.second;
                        // 如果該等於 1 的 cell 已經被處理過，則跳過
                        if (inRange(x, y, m, n) && mat[x][y] == 1 &&
                            ans[x][y] < 0)
                        {
                            ans[x][y] = ans[i][j] + 1; // 處理該 cell
                            q.push({x, y});            // 將該 cell 座標加入 queue
                        }
                    }
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();
            for (auto &dir : directions)
            {
                int x = current.first + dir.first;
                int y = current.second + dir.second;
                // 如果該等於 1 的 cell 已經被處理過，則跳過
                if (inRange(x, y, m, n) && mat[x][y] == 1 && ans[x][y] < 0)
                {
                    ans[x][y] =
                        ans[current.first][current.second] + 1; // 處理該 cell
                    q.push({x, y});                             // 將該 cell 座標加入 queue
                }
            }
        }
        return ans;
    };
};