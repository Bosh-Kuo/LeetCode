/*
time complexity: O(n^2)
tags: Depth-First Search, Breadth-First Search, Graph, Heap(Priority Queue), Shortest Path
note: 本題為最小路徑問題，可用 Dijkstra algorithm 解，找出從 k 出發到所有節點的最小路徑，回傳之中最大值
*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> distance(n + 1, INT_MAX);                         // 初始化 distance 向量，記錄從節點 k 到各節點的最短距離，初始值為 INT_MAX
        vector<vector<int>> edge(n + 1, vector<int>(n + 1, INT_MAX)); // 初始化 edge 矩陣，edge[i][j] 表示從節點 i 到節點 j 的距離，初始值為 INT_MAX
        unordered_set<int> visited;                                   // 初始化 visited 集合，用於記錄已經走訪過的節點
        for (auto time : times)
        {
            edge[time[0]][time[1]] = time[2];
        }

        // 設定起始節點 k 的距離為 0
        int source = k;
        distance[k] = 0;

        while (visited.size() < n)
        {
            // 更新從 source 出發可以到達的節點的最短距離
            for (int target = 1; target <= n; target++)
            {
                // 忽略 source 自己
                if (target == source)
                    continue;

                // 如果 source 到 target 有邊且 source 可以被到達，則更新距離
                if (edge[source][target] != INT_MAX && distance[source] != INT_MAX)
                    distance[target] = min(distance[target], distance[source] + edge[source][target]);
            }

            // 將 source 節點標記為已走訪
            visited.insert(source);

            // 找到下一個最近且未被走訪過的節點作為新的 source
            int tempDistance = INT_MAX;
            for (int i = 1; i <= n; i++)
            {
                if (visited.count(i) == 0 && distance[i] <= tempDistance)
                {
                    source = i;
                    tempDistance = distance[i];
                }
            }
        }

        // 找出從 k 出發到所有節點的最長距離(省略 distance[0])
        int ans = *max_element(distance.begin() + 1, distance.end());
        return ans == INT_MAX ? -1 : ans;
    }
};