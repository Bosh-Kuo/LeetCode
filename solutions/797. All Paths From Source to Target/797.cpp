/*
time complexity:
tags: Backtracking, Depth-First Search, Breadth-First Search, Graph
note: DFS 直接解
*/

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> answer;
    void dfs(vector<vector<int>> &graph, int currentIdx)
    {
        // 終止條件
        if (currentIdx == graph.size() - 1)
        {
            answer.push_back(path);
            return;
        }

        for (int i = 0; i < graph[currentIdx].size(); i++)
        {
            // 將節點 加入 path
            path.push_back(graph[currentIdx][i]);
            // DFS
            dfs(graph, graph[currentIdx][i]);
            // 回溯
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0); // 0 一定會是第一步
        dfs(graph, 0);
        return answer;
    }
};