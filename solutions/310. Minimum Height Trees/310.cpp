/*
time complexity: O(n)
tags: Depth-First Search, Breadth-First Search, Graph, Topological Sort
note: 只有將只有一個 edge 的 node 視為 leaf 時的 tree 才有可能有最小的 tree height
使用 topological sort 的概念，把 leaf node 一層一層移除，
最後一層被移除的 nodes 就是 MHT 可能的 roots
*/

class Solution
{
public:
    // 當下只有一個 edge 的 node 作為 root 的時候， tree height 都不會最小化
    // 只有將它們視為 leaf 時的 tree 才有可能有最小的 tree height
    // 使用 topological sort 的概念，把 leaf node 一層一層移除，
    // 最後一層被移除的 nodes 就是 MHT 可能的 roots

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0); // 紀錄每個 node 連接的 edge 數
        vector<int> ans;

        // 若只有 1 or 2 個 node 直接回傳結果
        if (n == 1)
            return {0};
        else if (n == 2)
            return {0, 1};

        // 建立 graph
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        // 將 leaf nodes 放進 queue
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i), indegree[i]--; // add all the leaf nodes to the queue
        }

        // 一層一層移除 leaf nodes
        while (!q.empty())
        {
            int s = q.size();
            ans.clear(); // 只有最後一層被移除的 leaf nodes 才會是 MHT's roots
            for (int i = 0; i < s; i++)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto child : graph[curr])
                {
                    // 移除該 leaf node 後，可能會有新的 node 成為 leaf node
                    indegree[child]--;
                    if (indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        return ans;
    }
};