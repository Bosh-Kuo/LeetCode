/*
time complexity: O(n)
tags: Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap(Priority Queue), Shortest Path
note: 使用 bfs 紀錄從 src 到每個可以到達的位置的最小花費。
由於每個節點與 src 之間可能不只有一條路徑，因此只紀錄 stops <= k 且從 src 走到該節點花費最小的金額
*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // 儲存從 src 到每個位置的最低花費
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // 儲存每個節點可以到的節點與花費 adj[i]= {{to_j, price_j}, {to_k, price_k}, ...}
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // 儲存 {從 src 走到 node 累計花費, {目前所在的 node, 從 src 走到 node 累計停戰次數}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;

            for (auto it : adj[node])
            {
                int adjNode = it.first; // 目前所在的 node 可以到達的節點
                int edWt = it.second;   // 目前所在的 node 到 adjNode 的花費

                if (stops <= k && cost + edWt < dist[adjNode])
                {
                    dist[adjNode] = cost + edWt;
                    q.push({cost + edWt, {adjNode, stops + 1}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};