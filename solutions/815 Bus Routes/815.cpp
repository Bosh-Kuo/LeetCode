/*
time complexity: O(log(n*k)), n = Number of Buses routes, k = Total number of stops
tags: Array, Hash Table, Breadth-First Search
note: 用 hash map 紀錄每個 stop 可以到達的 route，用 set 紀錄走訪過的 stops，用 queue 暫存即將走訪的 stop 與已經走訪過的 routes 數量
1. 建立每個 stop 可以到達的 route 的 hash map
2. 從 source stop 開始，逐一走訪 stop 可以走訪的 route，
3. 若該 route 包含了 target，直接回傳目前換過的 bus 數量；否則將該 route 上可到達的 stop 暫存近 queue 裡等待下一個 level 的 BFS 查詢
4. 完整走完一個 route 後清除該 route，避免後續 queue 裡的 stop 走回該 route 重複搜尋
*/

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        unordered_map<int, unordered_set<int>> stopToRoutes; // 紀錄每個 stop 可以到達的 route
        unordered_set<int> visitedStops;                     // 紀錄走訪過的 stops
        queue<pair<int, int>> q;                             // 暫存即將走訪的 stop 與已經走訪過的 routes 數量

        // 建立 stopToRoutes
        for (int i = 0; i < routes.size(); ++i)
        {
            for (int stop : routes[i])
            {
                stopToRoutes[stop].insert(i);
            }
        }

        q.push({source, 0});
        visitedStops.insert(source);

        // BFS 搜尋
        while (!q.empty())
        {
            int size = q.size();
            // 一次只計算一個 level
            for (int i = 0; i < size; ++i)
            {
                int currentStop = q.front().first;
                int busChanges = q.front().second;
                q.pop();

                for (int route : stopToRoutes[currentStop])
                {
                    for (int nextStop : routes[route])
                    {
                        // 只專注於還沒走訪過的 stop
                        if (!visitedStops.count(nextStop))
                        {
                            if (nextStop == target)
                                return busChanges + 1;

                            visitedStops.insert(nextStop);
                            q.push({nextStop, busChanges + 1});
                        }
                    }
                    // 該 route 的 stop 都走訪過就將該 route 清除，避免其他 route 上的 stop 走回該 route 重複搜尋
                    routes[route].clear();
                }
            }
        }
        return -1;
    }
};