/*
time complexity:
tags: Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union Find, Sorting
note: 用 unordered_map 紀錄每個 email 對應的 account index，並用 unionByRank 維護 Union Find
*/

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);       // 用來表示對應的樹的高度
        parent.resize(n + 1, 0);     // 用來存每個 account idx 的 parent idx
        for (int i = 0; i <= n; i++) // 一開始所有 account 的 parent idx 都指向本身
            parent[i] = i;
    }

    int findUPar(int u)
    {
        if (parent[u] == u)
            return u;
        else
        {
            parent[u] = findUPar(parent[u]);
            return parent[u];
        }
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return; // 若兩者的 root 相同，代表兩者屬於同個集合，不需合併
        if (rank[ulp_u] < rank[ulp_v])
        { // 若右者的 rank 較大，則左方所在的集合合併至右方所在的集合
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        { // 若左者的rank 較大，則右方所在的集合合併至左方所在的集合
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail] = i;
                else
                    ds.unionByRank(i, mapMailNode[mail]);
            }
        }
        vector<string> mergedMail[n];
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};