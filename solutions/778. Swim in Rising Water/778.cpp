/*
time complexity: O(n^2 * log(n))
tags: Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Heap(Priority Queue), Matrix
note: 本題可視為為最小路徑問題，用 Dijkstra algorithm 解。目標是從網格的左上角 (0,0) 移動到右下角 (n-1,n-1)，找到一條路徑，使得路徑上經過的最大高度值最小化。
*/

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // 初始化一個距離向量，表示從起點到每個節點的最短距離，初始為無窮大
        vector<int> distance(n * n, INT_MAX);
        // 定義四個方向的移動 (右, 左, 上, 下)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        // minHeap 用於選取下一個最小距離的節點，使前進路線沿著最小距離路徑走
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        distance[0] = grid[0][0];

        while (!pq.empty())
        {
            int source = pq.top();
            int dist = distance[source];
            pq.pop();

            // 計算當前節點在網格中的行列坐標
            int i = source / n;
            int j = source % n;

            // 如果已經到達終點，返回結果
            if (source == n * n - 1)
            {
                return dist;
            }

            // 遍歷當前節點的四個相鄰節點
            for (auto dir : directions)
            {
                int target_i = i + dir.first;
                int target_j = j + dir.second;
                int target = target_i * n + target_j;

                // 超越邊界者忽略
                if (target_i >= n || target_i < 0 || target_j >= n || target_j < 0)
                    continue;

                // 計算從當前節點到相鄰節點的距離，取最大值。因為我們關心的是經過的最大高度
                int newDist = max(dist, grid[target_i][target_j]);

                // 如果新計算的距離小於當前記錄的距離，更新距離，並加入 minHeap
                if (newDist < distance[target])
                {
                    distance[target] = newDist;
                    pq.push(target);
                }
            }
        }

        return distance[n * n - 1];
    }
};