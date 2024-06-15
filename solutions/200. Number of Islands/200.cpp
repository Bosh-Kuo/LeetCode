/*
time complexity: O(m*n)
tags: Array, Depth-First Search, Union Find, Matrix
note: 本題用 BFS 來解。
1. 建立一個與 grid 形狀相同的 2d boolean array 用來記錄已經標記過的位置
2. 遍歷 grid 上的每一個位置，若該位置尚未被標記，則 island 總數加一，並且開始標記周圍屬於同一 island 的 lands
    - 使用 BFS 標記與當前所在 land("1")四面相鄰的所有land("1")，直到該 island 上所有 land 都被標記為止
*/

class Solution
{
public:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, pair<int, int> &coordinate)
    {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        // 待訪問的座標
        queue<pair<int, int>> visitingQueue;
        visitingQueue.push(coordinate);
        visited[coordinate.first][coordinate.second] = true;
        // 逐一標記屬於同一 island 的座標
        while (!visitingQueue.empty())
        {
            pair<int, int> currentCoordinate = visitingQueue.front();
            visitingQueue.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextX = currentCoordinate.first + directions[i].first;
                int nextY = currentCoordinate.second + directions[i].second;
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                    continue;
                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1')
                {
                    visitingQueue.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int answer = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    answer += 1;
                    pair<int, int> coordinate = {i, j};
                    bfs(grid, visited, coordinate);
                }
            }
        }
        return answer;
    }
};