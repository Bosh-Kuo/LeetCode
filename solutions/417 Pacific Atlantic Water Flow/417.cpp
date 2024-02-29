/*
time complexity: O(m*n)
tags: Array, Depth-First Search, Breadth-First Search, Matrix
note: 本題用 DFS 來解。
從 Pacific Ocean 邊界逆流往上走，經過的 cell 都可以通向 Pacific Ocean，Atlantic Ocean 同理
最終統計可同時通往 Pacific Ocean 與 Atlantic Ocean 的所有 cell
*/

class Solution
{
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int currentX, int currentY)
    {
        visited[currentX][currentY] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextX = currentX + directions[i].first;
            int nextY = currentY + directions[i].second;
            if (nextX < 0 || nextX >= visited.size() || nextY < 0 || nextY >= visited[0].size())
                continue;
            if (!visited[nextX][nextY] && heights[nextX][nextY] >= heights[currentX][currentY])
                dfs(heights, visited, nextX, nextY);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        // 從 Pacific Ocean 邊界逆流往上走，經過的 cell 都可以通向 Pacific Ocean，Atlantic Ocean 同理
        // 最終統計可同時通往 Pacific Ocean 與 Atlantic Ocean 的所有 cell
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> answer;

        // 遍歷最上 row & 最下 row
        for (int i = 0; i < heights[0].size(); i++)
        {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, heights.size() - 1, i);
        }

        // 遍歷最左 col & 最右 col
        for (int i = 0; i < heights.size(); i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size() - 1);
        }

        // 統計可通往 pacific, atlantic 的 cell
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    answer.push_back({i, j});
            }
        }
        return answer;
    }
};