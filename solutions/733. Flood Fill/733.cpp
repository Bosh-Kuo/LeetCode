/*
time complexity: O(n)
tags: Array, Depth-First Search, Breadth-First Search, Matrix
note: 用 bfs 實作 BFS：先塗色在加入 queue，最後才改 image[sr][sc]，避免將重複的{x, y} 加入 queue
*/

class Solution
{
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;

        // 先將四周的 pixel 更改顏色在加入 queue
        if (image[sr][sc] != color)
        {
            for (auto &direction : directions)
            {
                int x = sr + direction.first;
                int y = sc + direction.second;
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == image[sr][sc])
                {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }

        while (!q.empty())
        {
            int currentX = q.front().first;
            int currentY = q.front().second;
            q.pop();
            for (auto &direction : directions)
            {
                int nextX = currentX + direction.first;
                int nextY = currentY + direction.second;

                if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && image[nextX][nextY] == image[sr][sc] && !(nextX == sr && nextY == sc))
                {
                    cout << nextX << ", " << nextY << endl;
                    image[nextX][nextY] = color;
                    q.push({nextX, nextY});
                }
            }
        }
        image[sr][sc] = color;
        return image;
    }
};