/*
time complexity: O(n^2)
tags: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
note: 本題用 DFS 來解。
第一遍遍歷時把所有 island 上的格子標上編號，(為了避免混亂編號從2開始)並且用 map 記錄每個島嶼的面積
若遍歷過程沒有編號為 0 的格子，則回傳 grid 面積
第二遍遍歷所有編號為 0 的格子，計算當該格子變成 1 的話周遭的島嶼面積的總和
*/

class Solution
{
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(vector<vector<int>> &grid, pair<int, int> coord, int &area, int islandNum)
    {
        int currentX = coord.first;
        int currentY = coord.second;
        grid[currentX][currentY] = islandNum; // 標記上島嶼編號
        area++;
        for (int i = 0; i < 4; i++)
        {
            int nextX = currentX + directions[i].first;
            int nextY = currentY + directions[i].second;
            pair<int, int> nextCoord = {nextX, nextY};
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                continue;
            if (grid[nextX][nextY] == 1)
                dfs(grid, nextCoord, area, islandNum);
        }
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int answer = 0;
        int islandNum = 2; // 從編號 2 開始編
        bool isAllLand = true;
        unordered_map<int, int> islandAreaMap;

        // 第一遍遍歷時把所有 island 上的格子標上編號，(為了避免混亂編號從2開始)並且用 map 記錄每個島嶼的面積
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                    isAllLand = false;
                else if (grid[i][j] == 1)
                {
                    // DFS 標記該島嶼上所有格子，並計算島嶼面積
                    int area = 0;
                    pair<int, int> coord = {i, j};
                    dfs(grid, coord, area, islandNum);

                    islandAreaMap[islandNum] = area;
                    islandNum++;
                }
            }
        }

        // 若遍歷過程沒有編號為 0 的格子，則回傳 grid 面積
        if (isAllLand)
            return grid.size() * grid[0].size();

        // 第二遍遍歷所有編號為 0 的格子，計算當該格子變成 1 的話周遭的島嶼面積的總和
        unordered_set<int> visitedIsland;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    int combinedArea = 1;  // grid[i][j] 本身
                    visitedIsland.clear(); // 清空拜訪紀錄
                    for (int k = 0; k < 4; k++)
                    {
                        int nextX = i + directions[k].first;
                        int nextY = j + directions[k].second;
                        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
                            continue;
                        int visitingIslandNum = grid[nextX][nextY];
                        if (visitedIsland.count(visitingIslandNum) == 0)
                        {
                            combinedArea += islandAreaMap[visitingIslandNum];
                            visitedIsland.insert(visitingIslandNum);
                        }
                    }
                    answer = max(combinedArea, answer);
                }
            }
        }
        return answer;
    }
};