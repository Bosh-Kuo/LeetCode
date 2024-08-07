/*
time complexity: O(|E|+|V|·log|V|)，其中|E|為邊的個數、|V|為節點個數。
tags: Array, Union Find, Graph, Minimum Spanning Tree
note: 本題為標準的 Minimum Spanning Tree，使用普林演算法（Prim’s algorithm）來解。
參考：https://medium.com/@ralph-tech/%E6%BC%94%E7%AE%97%E6%B3%95%E5%AD%B8%E7%BF%92%E7%AD%86%E8%A8%98-%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A8%B9-minimum-spanning-tree-mst-26c9482419a7
*/

typedef struct edge
{
    int weight;
    pair<int, int> endpoints;
} weightedEdge;

class Solution
{
public:
    // Prim’s algorithm
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        vector<vector<int>> weights(
            n, vector<int>(n, 0)); // 所有 edges weight 初始化為 0
        unordered_set<int> visitedNodes;

        // 1. 建立 weights
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || weights[i][j] != 0 || weights[j][i] != 0)
                    continue;
                int manhattanDistance = abs(points[i][0] - points[j][0]) +
                                        abs(points[i][1] - points[j][1]);
                weights[i][j] = manhattanDistance;
                weights[j][i] = manhattanDistance;
            }
        }

        // 定義一個比較結構，用於 minHeap
        struct MinHeapComparator
        {
            bool operator()(weightedEdge lhs, weightedEdge rhs)
            {
                return lhs.weight >
                       rhs.weight; // 較小的元素應排前面，所以當左元素小於右元素時返回
                                   // true
            }
        };
        // 用於儲存當前可走訪的 edge
        priority_queue<weightedEdge, vector<weightedEdge>, MinHeapComparator>
            minHeap;

        // 2. 從 node_0 出發，將 node_0 可走訪所有 edge 夾到 minHeap 中
        for (int i = 1; i < n; i++)
        {
            weightedEdge zero_i;
            zero_i.weight = weights[0][i];
            zero_i.endpoints = {0, i};
            minHeap.push(zero_i);
        }

        // 每次選擇 weight 最小且不會形成環的 edge，直到所有 nodes 都拜訪過
        visitedNodes.insert(0);
        while (visitedNodes.size() < n)
        {
            weightedEdge minEdge = minHeap.top();
            minHeap.pop();
            int source = minEdge.endpoints.first;
            int target = minEdge.endpoints.second;
            // 確保走向 target 不會形成環
            if (visitedNodes.count(target) == 0)
            {
                ans += minEdge.weight;
                visitedNodes.insert(target);
                for (int i = 0; i < n; i++)
                {
                    if (i == target || visitedNodes.count(i) > 0)
                        continue;
                    weightedEdge target_i;
                    target_i.weight = weights[target][i];
                    target_i.endpoints = {target, i};
                    minHeap.push(target_i);
                }
            }
        }
        return ans;
    }
};