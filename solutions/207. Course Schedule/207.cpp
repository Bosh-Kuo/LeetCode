/*
time complexity: O(n)
tags: Depth-First Search, Breadth-First Search, Graph, Topological Sort
note: 本題用 Kahn’s algorithm 做 Topological Sort。
用 graph 紀錄 graph[先修課程b] = [需要先修完課程b才能修的課程a]
用 indegree 紀錄課程 a 還有多少先修課程得修完才能修
從 indegree 為零的課程開始累計可以修的課數，並將 indegree[graph[剛修完的課]] 減一
直到沒有 indegree 為零的課程結束
*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 用 graph 紀錄 graph[先修課程b] = [需要先修完課程b才能修的課程a]
        // 用 indegree 紀錄課程 a 還有多少先修課程得修完才能修
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> canFinishedCourses;
        int finishedCoursesNum = 0;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]); // graph[i] 表示需要等課程 i 修完才能修的所有課程編號
            indegree[prerequisites[i][0]]++;                           // indegree[i] 表示課程 i 需要等多少門先修課程修完才能修
        }

        for (int i = 0; i < numCourses; i++)
        {
            // indegree[i] 為零表示 i 沒有先修課程
            if (indegree[i] == 0)
            {
                canFinishedCourses.push(i);
                finishedCoursesNum++;
            }
        }

        while (!canFinishedCourses.empty())
        {
            int finishedCourse = canFinishedCourses.front();
            canFinishedCourses.pop();
            for (int i = 0; i < graph[finishedCourse].size(); i++)
            {
                int pendingCourse = graph[finishedCourse][i];
                indegree[pendingCourse]--;
                if (indegree[pendingCourse] == 0)
                {
                    canFinishedCourses.push(pendingCourse);
                    finishedCoursesNum++;
                }
            }
        }
        return finishedCoursesNum == numCourses;
    }
};
Ｆ