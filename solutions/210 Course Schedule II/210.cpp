/**
time complexity: O(V+E)
tags: Depth-First Search, Breadth-First Search, Graph, Topological Sort
note: 建立 graph, degree => 找出 degree 為 0 的 course，加進 zeroDegree =>
將 zeroDegree 裡的數加入 order，並更新該數的 target 的 degree，並檢查 degree 是否為 0 => 若為零則將 target 加入 zeroDegree
*/

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        vector<int> order;
        queue<int> zeroDegree; // 代表可以直接完成的課

        // 建立 graph, degree
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int source = prerequisites[i][1];
            int target = prerequisites[i][0];
            graph[source].push_back(target);
            degree[target]++;
        }

        // 找出 degree 為 0 的 course，加進 zeroDegree
        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0)
                zeroDegree.push(i);
        }

        // 將 zeroDegree 裡的數加入 order，並更新該數的 target 的 degree，並檢查 degree 是否為 0
        while (!zeroDegree.empty())
        {

            int source = zeroDegree.front();
            order.push_back(source);
            zeroDegree.pop();
            for (auto target : graph[source])
            {
                degree[target]--;
                if (degree[target] == 0)
                    zeroDegree.push(target);
            }
        }

        // 若 order 長度不滿 numCourses 無法完成所有課程
        if (order.size() != numCourses)
            return {};
        else
            return order;
    }
};
