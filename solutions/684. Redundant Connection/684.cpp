/*
time complexity: O(n)
tags: Depth-First Search, Breadth-First Search, Union Find, Graph
note: 使用 Union Find 演算法判斷每個 edge 的兩端點 root 是否相同，當兩端點的 root 相同時，代表出現了 cycle，該 edge 可以刪除
*/

class Solution
{
public:
    vector<int> parent, size;
    int findRoot(int node)
    {
        // parent 指向自己直接回傳自己
        if (parent[node] == node)
            return node;
        // 否則將 parent 改指向 parent 的 root 並回傳(ex: 1->5->7, => 1->7, 5->7, 回傳 7)
        int root = findRoot(parent[node]);
        parent[node] = root;
        return root;
    }

    void unionBySize(int x, int y)
    {
        int rootX = findRoot(x), rootY = findRoot(y);
        // 若 x, y 的 root 相同，則不需要 union
        if (rootX == rootY)
            return;
        if (size[rootX] > size[rootY])
        {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else
        {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> ans;
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // 一開始每個節點的 parent 都指向自己
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        // 遍歷 edge，檢查 edge 中的兩個 node 的 parent 是否為指向相同的節點
        for (auto edge : edges)
        {
            // 若 edge 兩端的節點都指向相同的 parent，代表形成 circle，該 edge 可以刪除
            if (findRoot(edge[0]) == findRoot(edge[1]))
                ans.push_back(edge);
            // 若 edge 兩端的節點指向不同的 parent，則將兩個 parent 合併(ex: parent[2] = 1, parent[3] = 3 => parent[3] = 1)
            else
                unionBySize(edge[0], edge[1]);
        }
        return ans.back();
    }
};
